import re
import shutil
from pathlib import Path

Import("env")

FRAMEWORK_PACKAGE = "framework-arduinoteensy"
platform = env.PioPlatform()
framework_dir = Path(platform.get_package_dir(FRAMEWORK_PACKAGE) or "")

if not framework_dir.is_dir():
    env.Exit(
        f"Cannot find Teensy framework package at {framework_dir}."
        " Is it installed?"
    )

framework_version = platform.get_package_version(FRAMEWORK_PACKAGE)
build_dir = Path(env.subst("$BUILD_DIR"))
patched_framework_dir = build_dir / "patched-framework-arduinoteensy"
version_marker = patched_framework_dir / ".framework_version"

SECTION_RE = re.compile(
    r"(?P<header>#elif defined\(USB_MIDI16_AUDIO_SERIAL\)\n)"
    r"(?P<body>.*?)(?=\n#elif |\n#endif)",
    re.S,
)

REPLACEMENTS = {
    "MANUFACTURER_NAME": "  #define MANUFACTURER_NAME\t{'m','i','n','i','c','h','o','r','d'}",
    "MANUFACTURER_NAME_LEN": "  #define MANUFACTURER_NAME_LEN\t9",
    "PRODUCT_NAME": "  #define PRODUCT_NAME\t\t{'m','i','n','i','c','h','o','r','d'}",
    "PRODUCT_NAME_LEN": "  #define PRODUCT_NAME_LEN\t9",
    "MIDI_NUM_CABLES": "  #define MIDI_NUM_CABLES       2",
}


def ensure_framework_copy():
    stored_version = version_marker.read_text().strip() if version_marker.exists() else ""
    if patched_framework_dir.is_dir() and stored_version == framework_version:
        return

    if patched_framework_dir.exists():
        shutil.rmtree(patched_framework_dir)

    patched_framework_dir.mkdir(parents=True, exist_ok=True)
    shutil.copytree(framework_dir, patched_framework_dir, dirs_exist_ok=True)
    version_marker.write_text(framework_version)


def patch_usb_desc(path: Path):
    content = path.read_text()
    match = SECTION_RE.search(content)
    if not match:
        env.Exit("USB_MIDI16_AUDIO_SERIAL section not found in usb_desc.h")

    body = match.group("body")
    patched_body = body
    missing = []

    for macro, replacement in REPLACEMENTS.items():
        patched_body, count = re.subn(
            rf"(?m)^[ \t]*#define[ \t]+{macro}[ \t]+.*$",
            replacement,
            patched_body,
        )
        if count == 0:
            missing.append(macro)

    if missing:
        env.Exit(
            "Failed to patch usb_desc.h for macros: %s"
            % ", ".join(sorted(missing))
        )

    patched_content = (
        content[: match.start("body")] + patched_body + content[match.end("body") :]
    )
    if patched_content != content:
        path.write_text(patched_content)


ensure_framework_copy()

usb_desc_path = patched_framework_dir / "cores" / "teensy4" / "usb_desc.h"
if not usb_desc_path.exists():
    env.Exit(f"Patched usb_desc.h not found at {usb_desc_path}")

patch_usb_desc(usb_desc_path)

# Keep a standalone copy for quick inspection alongside build outputs.
shutil.copyfile(usb_desc_path, build_dir / "usb_desc_patched.h")

original_get_package_dir = platform.get_package_dir


def get_package_dir_override(name):
    if name == FRAMEWORK_PACKAGE:
        return str(patched_framework_dir)
    return original_get_package_dir(name)


platform.get_package_dir = get_package_dir_override
