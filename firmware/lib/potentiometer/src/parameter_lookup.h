#ifndef PARAMETER_LOOKUP_H
#define PARAMETER_LOOKUP_H

struct ParameterInfo {
    uint8_t sysex_adress;
    bool is_integer;
    int16_t min_value;
    int16_t max_value;
};

static const ParameterInfo parameter_lookup[] = {
    { 20, 1, 0, 360 }, // bank color
    { 32, 0, 0, 1 }, // led attenuation
    { 21, 1, 0, 1 }, // retrigger chords
    { 22, 1, 0, 1 }, // change held strings
    { 23, 1, 0, 2 }, // slash level
    { 30, 1, 0, 12 }, // transpose
    { 31, 1, 0, 1 }, // sharp function
    { 33, 1, 0, 1 }, // barry harris mode
    { 34, 1, 0, 6 }, // chord frame shift
    { 35, 1, 0, 11 }, // chord key signature
    { 24, 0, 0, 8 }, // reverb size
    { 25, 0, 0, 1 }, // reverb high damping
    { 26, 0, 0, 1 }, // reverb low damping
    { 27, 0, 0, 1 }, // reverb low pass
    { 28, 0, 0, 1 }, // reverb diffusion
    { 29, 0, 0, 1 }, // pan
    { 10, 1, 21, 219 }, // chord alternate control
    { 11, 1, 0, 100 }, // chord alternate range
    { 12, 1, 21, 219 }, // harp alternate control
    { 13, 1, 0, 100 }, // harp alternate percent range
    { 14, 1, 21, 219 }, // mod main control
    { 15, 1, 0, 100 }, // mod main percent range
    { 16, 1, 21, 219 }, // mod alternate control
    { 17, 1, 0, 100 }, // mod alternate percent range 
    { 4, 1, 0, 1024 }, // chord alternate value
    { 5, 1, 0, 1024 }, // harp alternate value
    { 6, 1, 0, 1024 }, // mod alternate value
    { 7, 0, 0, 10 }, // firmware revision
    { 2, 0, 0, 1 }, // global gain
    { 99, 1, 0, 4 }, // octave change
    { 40, 1, 0, 6 }, // harp shuffling
    { 98, 1, 0, 1 }, // chromatic mode
    { 41, 0, 0, 1 }, // amplitude
    { 42, 1, 0, 11 }, // waveform
    { 43, 1, 0, 5000 }, // attack
    { 44, 1, 0, 5000 }, // hold
    { 45, 1, 0, 5000 }, // decay
    { 46, 0, 0, 1 }, // sustain
    { 47, 1, 0, 5000 }, // release
    { 48, 1, 0, 10 }, // retrigger release
    { 49, 1, 0, 2000 }, // base frequency
    { 50, 0, 0, 3 }, // keytrack value
    { 51, 0, 0.7, 5 }, // resonance
    { 52, 1, 0, 5000 }, // attack
    { 53, 1, 0, 5000 }, // hold
    { 54, 1, 0, 5000 }, // decay
    { 55, 0, 0, 1 }, // sustain
    { 56, 1, 0, 5000 }, // release
    { 57, 1, 0, 100 }, // retrigger release
    { 58, 0, 0, 5 }, // filter sensitivity
    { 100, 1, 0, 11 }, // waveform
    { 101, 0, 0, 1 }, // amplitude
    { 102, 1, 0, 5000 }, // attack
    { 103, 1, 0, 5000 }, // hold
    { 104, 1, 0, 5000 }, // decay
    { 105, 1, 0, 24 }, // note level
    { 59, 1, 0, 11 }, // waveform
    { 60, 0, 0, 20 }, // frequency
    { 61, 0, 0, 1 }, // amplitude
    { 62, 1, 0, 11 }, // waveform
    { 63, 0, 0, 20 }, // frequency
    { 64, 0, 0, 1 }, // amplitude
    { 65, 1, 0, 5000 }, // attack
    { 66, 1, 0, 5000 }, // hold
    { 67, 1, 0, 5000 }, // decay
    { 68, 0, 0, 1 }, // sustain
    { 69, 1, 0, 5000 }, // release
    { 70, 1, 0, 100 }, // retrigger release
    { 71, 0, 0, 2 }, // pitch bend
    { 72, 1, 0, 5000 }, // attack bend
    { 73, 1, 0, 5000 }, // hold bend
    { 74, 1, 0, 5000 }, // decay bend
    { 75, 1, 0, 5000 }, // retrigger release bend
    { 76, 0, 0, 1 }, // intensity
    { 77, 1, 0, 600 }, // delay length
    { 78, 1, 0, 5000 }, // delay filter frequency
    { 79, 0, 0.7, 5 }, // delay filter resonance
    { 80, 0, 0, 1 }, // delay lowpass
    { 81, 0, 0, 1 }, // delay bandpass
    { 82, 0, 0, 1 }, // delay highpass
    { 83, 0, 0, 1 }, // dry mix
    { 84, 0, 0, 1 }, // delay mix
    { 85, 0, 0, 1 }, // reverb level
    { 86, 0, 0, 1 }, // crunch level
    { 87, 1, 0, 2 }, // crunch type
    { 88, 1, 0, 5000 }, // frequency
    { 89, 0, 0.7, 5 }, // resonance
    { 90, 0, 0, 1 }, // lowpass
    { 91, 0, 0, 1 }, // bandpass
    { 92, 0, 0, 1 }, // highpass
    { 93, 1, 0, 11 }, // LFO waveform
    { 94, 0, 0, 20 }, // LFO frequency
    { 95, 0, 0, 1 }, // LFO amplitude
    { 96, 0, 0, 5 }, // filter LFO sensitivity
    { 97, 0, 0, 2 }, // output amplifier
    { 3, 0, 0, 1 }, // global gain
    { 120, 1, 0, 5 }, // chord shuffling
    { 198, 1, 0, 4 }, // octave change
    { 121, 0, 0, 1 }, // amplitude 1
    { 122, 1, 0, 11 }, // waveform 1
    { 123, 0, 0.5, 2 }, // frequency multiplier 1
    { 124, 0, 0, 1 }, // amplitude 2
    { 125, 1, 0, 11 }, // waveform 2
    { 126, 0, 0.5, 2 }, // frequency multiplier 2
    { 127, 0, 0, 1 }, // amplitude 3
    { 128, 1, 0, 11 }, // waveform 3
    { 129, 0, 0.5, 2 }, // frequency multiplier 3
    { 130, 0, 0, 1 }, // noise
    { 131, 0, 0, 1 }, // first note
    { 132, 0, 0, 1 }, // second note
    { 133, 0, 0, 1 }, // third note
    { 134, 0, 0, 1 }, // fourth note
    { 135, 1, 0, 100 }, // inter-note delay
    { 136, 1, 0, 100 }, // random note delay
    { 137, 1, 0, 5000 }, // attack
    { 138, 1, 0, 5000 }, // hold
    { 139, 1, 0, 5000 }, // decay
    { 140, 0, 0, 1 }, // sustain
    { 141, 1, 0, 5000 }, // release
    { 142, 1, 0, 100 }, // retrigger release
    { 143, 1, 0, 5000 }, // base frequency
    { 144, 0, 0, 1 }, // keytrack value
    { 145, 0, 0.7, 5 }, // resonance
    { 146, 1, 0, 5000 }, // attack
    { 147, 1, 0, 5000 }, // hold
    { 148, 1, 0, 5000 }, // decay
    { 149, 0, 0, 1 }, // sustain
    { 150, 1, 0, 5000 }, // release
    { 151, 1, 0, 100 }, // retrigger release
    { 152, 1, 0, 11 }, // LFO waveform
    { 153, 0, 0, 20 }, // LFO frequency
    { 154, 0, 0, 1 }, // LFO amplitude
    { 155, 0, 0, 5 }, // filter sensitivity
    { 156, 1, 0, 11 }, // waveform
    { 157, 0, 0, 20 }, // frequency
    { 158, 0, 0, 5 }, // keytrack value
    { 159, 0, 0, 1 }, // amplitude
    { 160, 1, 0, 11 }, // waveform
    { 161, 0, 0, 20 }, // frequency
    { 162, 0, 0, 1 }, // keytrack value
    { 163, 0, 0, 1 }, // amplitude
    { 164, 1, 0, 5000 }, // attack
    { 165, 1, 0, 5000 }, // hold
    { 166, 1, 0, 5000 }, // decay
    { 167, 0, 0, 1 }, // sustain
    { 168, 1, 0, 5000 }, // release
    { 169, 1, 0, 100 }, // retrigger release
    { 170, 0, 0, 2 }, // pitch bend
    { 171, 1, 0, 5000 }, // attack bend 
    { 172, 1, 0, 5000 }, // hold bend
    { 173, 1, 0, 5000 }, // decay bend
    { 174, 1, 0, 100 }, // retrigger release bend
    { 175, 0, 0, 1 }, // intensity
    { 176, 1, 0, 600 }, // delay length
    { 177, 1, 0, 5000 }, // delay filter frequency
    { 178, 0, 0.7, 5 }, // delay filter resonance
    { 179, 0, 0, 1 }, // delay lowpass
    { 180, 0, 0, 1 }, // delay bandpass
    { 181, 0, 0, 1 }, // delay highpass
    { 182, 0, 0, 1 }, // dry mix
    { 183, 0, 0, 1 }, // delay mix
    { 184, 0, 0, 1 }, // reverb level
    { 185, 0, 0, 1 }, // crunch level
    { 186, 1, 0, 2 }, // crunch type
    { 187, 1, 30, 300 }, // default_bpm
    { 188, 1, 1, 16 }, // cycle length
    { 189, 1, 1, 8 }, // measure update
    { 190, 0, 0.5, 1.5 }, // shuffle value
    { 191, 1, 20, 1000 }, // note pushed duration
    { 220, 1, 0, 128 }, // rythm pattern
    { 221, 1, 0, 128 }, // rythm pattern
    { 222, 1, 0, 128 }, // rythm pattern
    { 223, 1, 0, 128 }, // rythm pattern
    { 224, 1, 0, 128 }, // rythm pattern
    { 225, 1, 0, 128 }, // rythm pattern
    { 226, 1, 0, 128 }, // rythm pattern
    { 227, 1, 0, 128 }, // rythm pattern
    { 228, 1, 0, 128 }, // rythm pattern
    { 229, 1, 0, 128 }, // rythm pattern
    { 230, 1, 0, 128 }, // rythm pattern
    { 231, 1, 0, 128 }, // rythm pattern
    { 232, 1, 0, 128 }, // rythm pattern
    { 233, 1, 0, 128 }, // rythm pattern
    { 234, 1, 0, 128 }, // rythm pattern
    { 235, 1, 0, 128 }, // rythm pattern
    { 192, 1, 0, 5000 }, // frequency
    { 193, 0, 0.7, 5 }, // resonance
    { 194, 0, 0, 1 }, // lowpass
    { 195, 0, 0, 1 }, // bandpass
    { 196, 0, 0, 1 }, // highpass
    { 197, 0, 0, 2 }, // output amplifier
};

#endif // PARAMETER_LOOKUP_H
