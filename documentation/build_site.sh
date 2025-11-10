#! /usr/bin/env bash
source venv/bin/activate
python3 -m mkdocs build
cp docs/index.html site/
cp docs/mk25.html site/
cp -R ../firmware/minicontrol site/