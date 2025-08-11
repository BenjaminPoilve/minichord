#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     string_vibrato_dc; //xy=485.50006103515625,1107
AudioSynthWaveform       string_vibrato_lfo; //xy=497.50006103515625,1040
AudioEffectEnvelope      envelope_string_vibrato_dc; //xy=651.5000610351562,1143
AudioEffectEnvelope      envelope_string_vibrato_lfo; //xy=676.5000610351562,1084
AudioSynthWaveformDc     chords_vibrato_dc; //xy=727.5000610351562,1782
AudioSynthWaveform       chords_vibrato_lfo; //xy=730.5000610351562,1696
AudioMixer4              string_vibrato_mixer; //xy=851.5000610351562,1145
AudioEffectEnvelope      voice4_vibrato_dc_envelope; //xy=936.5000610351562,2596
AudioEffectEnvelope      voice3_vibrato_envelope; //xy=940.5000610351562,2266
AudioEffectEnvelope      voice3_vibrato_dc_envelope; //xy=943.5000610351562,2351
AudioEffectEnvelope      voice4_vibrato_envelope; //xy=949.5000610351562,2530
AudioEffectEnvelope      voice2_vibrato_dc_envelope; //xy=958.5000610351562,2052
AudioEffectEnvelope      voice2_vibrato_envelope; //xy=959.5000610351562,1978
AudioEffectEnvelope      voice1_vibrato_envelope; //xy=973.5000610351562,1696
AudioEffectEnvelope      voice1_vibrato_dc_envelope; //xy=973.5000610351562,1781
AudioSynthWaveformModulated waveform_string_4; //xy=1037.5000610351562,1299
AudioSynthWaveformModulated waveform_string_2; //xy=1038.5000610351562,1231
AudioSynthWaveformModulated waveform_string_5; //xy=1038.5000610351562,1336
AudioSynthWaveformModulated waveform_string_7; //xy=1038.5000610351562,1407
AudioSynthWaveformModulated waveform_string_10; //xy=1038.5000610351562,1514
AudioSynthWaveformModulated waveform_string_3; //xy=1039.5000610351562,1265
AudioSynthWaveformModulated waveform_string_12; //xy=1038.5000610351562,1581
AudioSynthWaveformModulated waveform_string_6; //xy=1039.5000610351562,1373
AudioSynthWaveformModulated waveform_string_8; //xy=1039.5000610351562,1443
AudioSynthWaveformModulated waveform_string_1; //xy=1040.5000610351562,1196
AudioSynthWaveformModulated waveform_string_9; //xy=1040.5000610351562,1479
AudioSynthWaveformModulated waveform_string_11; //xy=1040.5000610351562,1549
AudioSynthWaveformDc     filter_dc;      //xy=1063.5000610351562,765
AudioSynthWaveform       waveform_transient_9;      //xy=1079.4285507202148,608.000036239624
AudioSynthWaveform       waveform_transient_6;      //xy=1080.4046783447266,513.2618799209595
AudioSynthWaveform       waveform_transient_5;      //xy=1080.6427001953125,480.642822265625
AudioSynthWaveform       waveform_transient_1;      //xy=1081.3213577270503,347.39285469055153
AudioSynthWaveform       waveform_transient_2;      //xy=1081.3213424682617,379.8928394317627
AudioSynthWaveform       waveform_transient_3;      //xy=1081.3213424682617,412.3928394317627
AudioSynthWaveform       waveform_transient_4;      //xy=1081.3213424682617,447.3928394317627
AudioSynthWaveform       waveform_transient_7;      //xy=1081.8332328796387,544.6904239654541
AudioSynthWaveform       waveform_transient_8;      //xy=1082.7858047485352,576.5952339172363
AudioSynthWaveform       waveform_transient_11;     //xy=1083.7143554687495,667.9999561309812
AudioSynthWaveform       waveform_transient_10;     //xy=1085.1426811218262,639.4285202026367
AudioSynthWaveform       waveform_transient_12;     //xy=1086.571411132812,699.4284572601316
AudioMixer4              voice3_vibrato_mixer; //xy=1165.5000610351562,2296
AudioMixer4              voice4_vibrato_mixer; //xy=1171.5000610351562,2539
AudioMixer4              voice2_vibrato_mixer; //xy=1196.5000610351562,2005
AudioMixer4              voice1_vibrato_mixer; //xy=1204.5000610351562,1716
AudioEffectEnvelope      envelope_filter_2; //xy=1255.5000610351562,796
AudioEffectEnvelope      envelope_filter_3; //xy=1255.5000610351562,826
AudioEffectEnvelope      envelope_filter_5; //xy=1255.5000610351562,888
AudioEffectEnvelope      envelope_filter_6; //xy=1255.5000610351562,920
AudioEffectEnvelope      envelope_filter_7; //xy=1255.5000610351562,951
AudioEffectEnvelope      envelope_filter_1; //xy=1256.5000610351562,765
AudioEffectEnvelope      envelope_filter_4; //xy=1256.5000610351562,856
AudioEffectEnvelope      envelope_filter_12; //xy=1255.5000610351562,1109
AudioEffectEnvelope      envelope_filter_9; //xy=1256.5000610351562,1014
AudioEffectEnvelope      envelope_filter_11; //xy=1256.5000610351562,1078
AudioEffectEnvelope      envelope_filter_10; //xy=1259.5000610351562,1047
AudioEffectEnvelope      envelope_filter_8; //xy=1260.5000610351562,981
AudioEffectEnvelope      envelope_string_6; //xy=1260.5000610351562,1371
AudioEffectEnvelope      envelope_string_8; //xy=1260.5000610351562,1442
AudioEffectEnvelope      envelope_string_10; //xy=1260.5000610351562,1510
AudioEffectEnvelope      envelope_string_12; //xy=1260.5000610351562,1579
AudioEffectEnvelope      envelope_string_5; //xy=1261.5000610351562,1336
AudioEffectEnvelope      envelope_string_7; //xy=1261.5000610351562,1406
AudioEffectEnvelope      envelope_string_9; //xy=1261.5000610351562,1476
AudioEffectEnvelope      envelope_string_3; //xy=1262.5000610351562,1265
AudioEffectEnvelope      envelope_string_4; //xy=1263.5000610351562,1299
AudioEffectEnvelope      envelope_string_11; //xy=1263.5000610351562,1545
AudioEffectEnvelope      envelope_string_1; //xy=1265.5000610351562,1198
AudioEffectEnvelope      envelope_string_2; //xy=1265.5000610351562,1231
AudioEffectEnvelope      envelope_transient_7;      //xy=1306.5715713500972,545.1429061889646
AudioEffectEnvelope      envelope_transient_8;      //xy=1308.0000190734859,575.1428976058958
AudioEffectEnvelope      envelope_transient_9;      //xy=1308.0001239776607,606.5715065002439
AudioEffectEnvelope      envelope_transient_10;     //xy=1307.9999847412105,638.0000782012937
AudioEffectEnvelope      envelope_transient_5;      //xy=1309.4285049438472,478.00003433227516
AudioEffectEnvelope      envelope_transient_6;      //xy=1309.4284667968745,510.8571491241453
AudioEffectEnvelope      envelope_transient_11;     //xy=1309.4284858703609,668.0000343322752
AudioEffectEnvelope      envelope_transient_12;     //xy=1309.4285202026363,696.5714092254636
AudioEffectEnvelope      envelope_transient_4;      //xy=1310.8572311401363,443.71434211730934
AudioEffectEnvelope      envelope_transient_1;      //xy=1312.2858047485347,349.4286079406736
AudioEffectEnvelope      envelope_transient_2;      //xy=1312.2857856750484,380.8571052551267
AudioEffectEnvelope      envelope_transient_3;      //xy=1312.2858047485347,412.28571987152077
AudioSynthNoiseWhite     voice3_noise;   //xy=1359.5000610351562,2365
AudioSynthWaveformModulated voice3_osc3;    //xy=1362.5000610351562,2331
AudioSynthNoiseWhite     voice4_noise;   //xy=1362.5000610351562,2642
AudioSynthWaveformModulated voice3_osc2;    //xy=1364.5000610351562,2295
AudioSynthWaveformModulated voice4_osc3;    //xy=1364.5000610351562,2605
AudioSynthWaveformModulated voice3_osc1;    //xy=1368.5000610351562,2257
AudioSynthWaveformModulated voice4_osc2;    //xy=1367.5000610351562,2568
AudioSynthWaveformModulated voice4_osc1;    //xy=1369.5000610351562,2533
AudioSynthWaveform       chords_filter_LFO; //xy=1382.5000610351562,1888
AudioSynthNoiseWhite     voice2_noise;   //xy=1385.5000610351562,2088
AudioSynthWaveformModulated voice2_osc3;    //xy=1387.5000610351562,2051
AudioSynthWaveformModulated voice2_osc2;    //xy=1389.5000610351562,2015
AudioSynthWaveformModulated voice2_osc1;    //xy=1390.5000610351562,1978
AudioSynthNoiseWhite     voice1_noise;   //xy=1398.5000610351562,1806
AudioSynthWaveformModulated voice1_osc3;    //xy=1403.5000610351562,1770
AudioSynthWaveformModulated voice1_osc1;    //xy=1404.5000610351562,1700
AudioSynthWaveformModulated voice1_osc2;    //xy=1404.5000610351562,1735
AudioFilterStateVariable filter_string_4; //xy=1497.5000610351562,1266
AudioFilterStateVariable filter_string_5; //xy=1497.5000610351562,1312
AudioFilterStateVariable filter_string_1; //xy=1498.5000610351562,1131
AudioFilterStateVariable filter_string_7; //xy=1497.5000610351562,1404
AudioFilterStateVariable filter_string_2; //xy=1498.5000610351562,1176
AudioFilterStateVariable filter_string_8; //xy=1498.5000610351562,1451
AudioFilterStateVariable filter_string_3; //xy=1499.5000610351562,1221
AudioFilterStateVariable filter_string_6; //xy=1500.5000610351562,1361
AudioFilterStateVariable filter_string_9; //xy=1500.5000610351562,1496
AudioFilterStateVariable filter_string_11; //xy=1501.5000610351562,1588
AudioFilterStateVariable filter_string_12; //xy=1501.5000610351562,1634
AudioFilterStateVariable filter_string_10; //xy=1502.5000610351562,1541
AudioMixer4              transient_mix_2;         //xy=1529.4285621643062,470.85714721679665
AudioMixer4              transient_mix_1;         //xy=1530.8570442199702,373.71434211730934
AudioMixer4              transient_mix_3;         //xy=1535.1428451538081,572.2857532501218
AudioEffectEnvelope      voice4_envelope_filter; //xy=1561.5000610351562,2708
AudioMixer4              voice3_mixer;   //xy=1565.5000610351562,2289
AudioMixer4              voice4_mixer;   //xy=1566.5000610351562,2552
AudioMixer4              voice2_mixer;   //xy=1570.5000610351562,2004
AudioEffectEnvelope      voice3_envelope_filter; //xy=1569.5000610351562,2395
AudioEffectEnvelope      voice2_envelope_filter; //xy=1585.5000610351562,2122
AudioEffectEnvelope      voice1_envelope_filter; //xy=1587.5000610351562,1891
AudioMixer4              voice1_mixer;   //xy=1589.5000610351562,1734
AudioMixer4              transient_full_mix;         //xy=1759.428557259695,442.28574589320567
AudioMixer4              string_mix_3;   //xy=1755.5000610351562,1524
AudioMixer4              string_mix_1;   //xy=1758.5000610351562,1212
AudioMixer4              string_mix_2;   //xy=1772.5000610351562,1341
AudioSynthWaveform       chords_tremolo_lfo; //xy=1837.5000610351562,1892
AudioFilterStateVariable voice4_filter;  //xy=1870.5000610351562,2556
AudioFilterStateVariable voice2_filter;  //xy=1878.5000610351562,2009
AudioFilterStateVariable voice3_filter;  //xy=1877.5000610351562,2285
AudioFilterStateVariable voice1_filter;  //xy=1899.5000610351562,1741
AudioMixer4              all_string_mix; //xy=1972.5000610351562,1341
AudioEffectEnvelope      voice1_envelope; //xy=2055.5000610351562,1892
AudioEffectEnvelope      voice3_envelope; //xy=2057.5000610351562,2423
AudioEffectEnvelope      voice2_envelope; //xy=2060.5000610351562,2143
AudioEffectEnvelope      voice4_envelope; //xy=2064.5000610351562,2742
AudioEffectMultiply      voice2_tremolo_mult; //xy=2103.5000610351562,2005
AudioEffectMultiply      voice3_tremolo_mult; //xy=2105.5000610351562,2285
AudioEffectMultiply      voice4_tremolo_mult; //xy=2108.5000610351562,2560
AudioEffectMultiply      voice1_tremolo_mult; //xy=2113.5000610351562,1735
AudioEffectWaveshaper    string_waveshape; //xy=2205.5000610351562,1159
AudioMixer4              string_waveshaper_mix; //xy=2257.5000610351562,1337
AudioMixer4              chord_voice_mixer; //xy=2414.5000610351562,1756
AudioFilterStateVariable filter_delay_strings; //xy=2441.5000610351562,1125
AudioEffectWaveshaper    chord_waveshape; //xy=2592.5000610351562,1652
AudioMixer4              string_delay_mix; //xy=2623.5000610351562,1213
AudioMixer4              chord_waveshaper_mix; //xy=2745.5000610351562,1737
AudioSynthWaveform       string_tremolo_lfo; //xy=2780.5000610351562,1516
AudioMixer4              strings_effect_mix; //xy=2827.5000610351562,1394
AudioFilterStateVariable filter_delay_chords; //xy=2837.5000610351562,1612
AudioEffectDelay         delay_strings;  //xy=2937.5000610351562,1224
AudioSynthWaveform       string_filter_lfo; //xy=3033.5000610351562,1563
AudioMixer4              chord_delay_mix; //xy=3037.5000610351562,1712
AudioEffectMultiply      string_multiply; //xy=3054.5000610351562,1475
AudioMixer4              chords_effect_mix; //xy=3185.5000610351562,1860
AudioFilterStateVariable string_filter;  //xy=3252.5000610351562,1509
AudioEffectDelay         delay_chords;   //xy=3335.5000610351562,1732
AudioInputI2S            i2s1;           //xy=3440.5000610351562,1260
AudioMixer4              string_filter_mixer; //xy=3457.5000610351562,1510
AudioFilterStateVariable chords_main_filter; //xy=3503.5000610351562,1793
AudioMixer4              chords_main_filter_mixer; //xy=3786.5000610351562,1808
AudioConnection          patchCord1(string_vibrato_dc, envelope_string_vibrato_dc);
AudioConnection          patchCord2(string_vibrato_lfo, envelope_string_vibrato_lfo);
AudioConnection          patchCord3(envelope_string_vibrato_dc, 0, string_vibrato_mixer, 1);
AudioConnection          patchCord4(envelope_string_vibrato_lfo, 0, string_vibrato_mixer, 0);
AudioConnection          patchCord5(chords_vibrato_dc, voice1_vibrato_dc_envelope);
AudioConnection          patchCord6(chords_vibrato_dc, voice2_vibrato_dc_envelope);
AudioConnection          patchCord7(chords_vibrato_dc, voice3_vibrato_dc_envelope);
AudioConnection          patchCord8(chords_vibrato_dc, voice4_vibrato_dc_envelope);
AudioConnection          patchCord9(chords_vibrato_lfo, voice1_vibrato_envelope);
AudioConnection          patchCord10(chords_vibrato_lfo, voice2_vibrato_envelope);
AudioConnection          patchCord11(chords_vibrato_lfo, voice3_vibrato_envelope);
AudioConnection          patchCord12(chords_vibrato_lfo, voice4_vibrato_envelope);
AudioConnection          patchCord13(string_vibrato_mixer, 0, waveform_string_1, 0);
AudioConnection          patchCord14(string_vibrato_mixer, 0, waveform_string_2, 0);
AudioConnection          patchCord15(string_vibrato_mixer, 0, waveform_string_3, 0);
AudioConnection          patchCord16(string_vibrato_mixer, 0, waveform_string_4, 0);
AudioConnection          patchCord17(string_vibrato_mixer, 0, waveform_string_5, 0);
AudioConnection          patchCord18(string_vibrato_mixer, 0, waveform_string_6, 0);
AudioConnection          patchCord19(string_vibrato_mixer, 0, waveform_string_7, 0);
AudioConnection          patchCord20(string_vibrato_mixer, 0, waveform_string_8, 0);
AudioConnection          patchCord21(string_vibrato_mixer, 0, waveform_string_9, 0);
AudioConnection          patchCord22(string_vibrato_mixer, 0, waveform_string_10, 0);
AudioConnection          patchCord23(string_vibrato_mixer, 0, waveform_string_11, 0);
AudioConnection          patchCord24(string_vibrato_mixer, 0, waveform_string_12, 0);
AudioConnection          patchCord25(voice4_vibrato_dc_envelope, 0, voice4_vibrato_mixer, 1);
AudioConnection          patchCord26(voice3_vibrato_envelope, 0, voice3_vibrato_mixer, 0);
AudioConnection          patchCord27(voice3_vibrato_dc_envelope, 0, voice3_vibrato_mixer, 1);
AudioConnection          patchCord28(voice4_vibrato_envelope, 0, voice4_vibrato_mixer, 0);
AudioConnection          patchCord29(voice2_vibrato_dc_envelope, 0, voice2_vibrato_mixer, 1);
AudioConnection          patchCord30(voice2_vibrato_envelope, 0, voice2_vibrato_mixer, 0);
AudioConnection          patchCord31(voice1_vibrato_envelope, 0, voice1_vibrato_mixer, 0);
AudioConnection          patchCord32(voice1_vibrato_dc_envelope, 0, voice1_vibrato_mixer, 1);
AudioConnection          patchCord33(waveform_string_4, envelope_string_4);
AudioConnection          patchCord34(waveform_string_2, envelope_string_2);
AudioConnection          patchCord35(waveform_string_5, envelope_string_5);
AudioConnection          patchCord36(waveform_string_7, envelope_string_7);
AudioConnection          patchCord37(waveform_string_10, envelope_string_10);
AudioConnection          patchCord38(waveform_string_3, envelope_string_3);
AudioConnection          patchCord39(waveform_string_12, envelope_string_12);
AudioConnection          patchCord40(waveform_string_6, envelope_string_6);
AudioConnection          patchCord41(waveform_string_8, envelope_string_8);
AudioConnection          patchCord42(waveform_string_1, envelope_string_1);
AudioConnection          patchCord43(waveform_string_9, envelope_string_9);
AudioConnection          patchCord44(waveform_string_11, envelope_string_11);
AudioConnection          patchCord45(filter_dc, envelope_filter_1);
AudioConnection          patchCord46(filter_dc, envelope_filter_2);
AudioConnection          patchCord47(filter_dc, envelope_filter_3);
AudioConnection          patchCord48(filter_dc, envelope_filter_4);
AudioConnection          patchCord49(filter_dc, envelope_filter_5);
AudioConnection          patchCord50(filter_dc, envelope_filter_6);
AudioConnection          patchCord51(filter_dc, envelope_filter_7);
AudioConnection          patchCord52(filter_dc, envelope_filter_8);
AudioConnection          patchCord53(filter_dc, envelope_filter_9);
AudioConnection          patchCord54(filter_dc, envelope_filter_10);
AudioConnection          patchCord55(filter_dc, envelope_filter_11);
AudioConnection          patchCord56(filter_dc, envelope_filter_12);
AudioConnection          patchCord57(waveform_transient_9, envelope_transient_9);
AudioConnection          patchCord58(waveform_transient_6, envelope_transient_6);
AudioConnection          patchCord59(waveform_transient_5, envelope_transient_5);
AudioConnection          patchCord60(waveform_transient_1, envelope_transient_1);
AudioConnection          patchCord61(waveform_transient_2, envelope_transient_2);
AudioConnection          patchCord62(waveform_transient_3, envelope_transient_3);
AudioConnection          patchCord63(waveform_transient_4, envelope_transient_4);
AudioConnection          patchCord64(waveform_transient_7, envelope_transient_7);
AudioConnection          patchCord65(waveform_transient_8, envelope_transient_8);
AudioConnection          patchCord66(waveform_transient_11, envelope_transient_11);
AudioConnection          patchCord67(waveform_transient_10, envelope_transient_10);
AudioConnection          patchCord68(waveform_transient_12, envelope_transient_12);
AudioConnection          patchCord69(voice3_vibrato_mixer, 0, voice3_osc1, 0);
AudioConnection          patchCord70(voice3_vibrato_mixer, 0, voice3_osc2, 0);
AudioConnection          patchCord71(voice3_vibrato_mixer, 0, voice3_osc3, 0);
AudioConnection          patchCord72(voice4_vibrato_mixer, 0, voice4_osc1, 0);
AudioConnection          patchCord73(voice4_vibrato_mixer, 0, voice4_osc2, 0);
AudioConnection          patchCord74(voice4_vibrato_mixer, 0, voice4_osc3, 0);
AudioConnection          patchCord75(voice2_vibrato_mixer, 0, voice2_osc1, 0);
AudioConnection          patchCord76(voice2_vibrato_mixer, 0, voice2_osc2, 0);
AudioConnection          patchCord77(voice2_vibrato_mixer, 0, voice2_osc3, 0);
AudioConnection          patchCord78(voice1_vibrato_mixer, 0, voice1_osc1, 0);
AudioConnection          patchCord79(voice1_vibrato_mixer, 0, voice1_osc2, 0);
AudioConnection          patchCord80(voice1_vibrato_mixer, 0, voice1_osc3, 0);
AudioConnection          patchCord81(envelope_filter_2, 0, filter_string_2, 1);
AudioConnection          patchCord82(envelope_filter_3, 0, filter_string_3, 1);
AudioConnection          patchCord83(envelope_filter_5, 0, filter_string_5, 1);
AudioConnection          patchCord84(envelope_filter_6, 0, filter_string_6, 1);
AudioConnection          patchCord85(envelope_filter_7, 0, filter_string_7, 1);
AudioConnection          patchCord86(envelope_filter_1, 0, filter_string_1, 1);
AudioConnection          patchCord87(envelope_filter_4, 0, filter_string_4, 1);
AudioConnection          patchCord88(envelope_filter_12, 0, filter_string_12, 1);
AudioConnection          patchCord89(envelope_filter_9, 0, filter_string_9, 1);
AudioConnection          patchCord90(envelope_filter_11, 0, filter_string_11, 1);
AudioConnection          patchCord91(envelope_filter_10, 0, filter_string_10, 1);
AudioConnection          patchCord92(envelope_filter_8, 0, filter_string_8, 1);
AudioConnection          patchCord93(envelope_string_6, 0, filter_string_6, 0);
AudioConnection          patchCord94(envelope_string_8, 0, filter_string_8, 0);
AudioConnection          patchCord95(envelope_string_10, 0, filter_string_10, 0);
AudioConnection          patchCord96(envelope_string_12, 0, filter_string_12, 0);
AudioConnection          patchCord97(envelope_string_5, 0, filter_string_5, 0);
AudioConnection          patchCord98(envelope_string_7, 0, filter_string_7, 0);
AudioConnection          patchCord99(envelope_string_9, 0, filter_string_9, 0);
AudioConnection          patchCord100(envelope_string_3, 0, filter_string_3, 0);
AudioConnection          patchCord101(envelope_string_4, 0, filter_string_4, 0);
AudioConnection          patchCord102(envelope_string_11, 0, filter_string_11, 0);
AudioConnection          patchCord103(envelope_string_1, 0, filter_string_1, 0);
AudioConnection          patchCord104(envelope_string_2, 0, filter_string_2, 0);
AudioConnection          patchCord105(envelope_transient_7, 0, transient_mix_2, 2);
AudioConnection          patchCord106(envelope_transient_8, 0, transient_mix_2, 3);
AudioConnection          patchCord107(envelope_transient_9, 0, transient_mix_3, 0);
AudioConnection          patchCord108(envelope_transient_10, 0, transient_mix_3, 1);
AudioConnection          patchCord109(envelope_transient_5, 0, transient_mix_2, 0);
AudioConnection          patchCord110(envelope_transient_6, 0, transient_mix_2, 1);
AudioConnection          patchCord111(envelope_transient_11, 0, transient_mix_3, 2);
AudioConnection          patchCord112(envelope_transient_12, 0, transient_mix_3, 3);
AudioConnection          patchCord113(envelope_transient_4, 0, transient_mix_1, 3);
AudioConnection          patchCord114(envelope_transient_1, 0, transient_mix_1, 0);
AudioConnection          patchCord115(envelope_transient_2, 0, transient_mix_1, 1);
AudioConnection          patchCord116(envelope_transient_3, 0, transient_mix_1, 2);
AudioConnection          patchCord117(voice3_noise, 0, voice3_mixer, 3);
AudioConnection          patchCord118(voice3_osc3, 0, voice3_mixer, 2);
AudioConnection          patchCord119(voice4_noise, 0, voice4_mixer, 3);
AudioConnection          patchCord120(voice3_osc2, 0, voice3_mixer, 1);
AudioConnection          patchCord121(voice4_osc3, 0, voice4_mixer, 2);
AudioConnection          patchCord122(voice3_osc1, 0, voice3_mixer, 0);
AudioConnection          patchCord123(voice4_osc2, 0, voice4_mixer, 1);
AudioConnection          patchCord124(voice4_osc1, 0, voice4_mixer, 0);
AudioConnection          patchCord125(chords_filter_LFO, voice1_envelope_filter);
AudioConnection          patchCord126(chords_filter_LFO, voice2_envelope_filter);
AudioConnection          patchCord127(chords_filter_LFO, voice3_envelope_filter);
AudioConnection          patchCord128(chords_filter_LFO, voice4_envelope_filter);
AudioConnection          patchCord129(voice2_noise, 0, voice2_mixer, 3);
AudioConnection          patchCord130(voice2_osc3, 0, voice2_mixer, 2);
AudioConnection          patchCord131(voice2_osc2, 0, voice2_mixer, 1);
AudioConnection          patchCord132(voice2_osc1, 0, voice2_mixer, 0);
AudioConnection          patchCord133(voice1_noise, 0, voice1_mixer, 3);
AudioConnection          patchCord134(voice1_osc3, 0, voice1_mixer, 2);
AudioConnection          patchCord135(voice1_osc1, 0, voice1_mixer, 0);
AudioConnection          patchCord136(voice1_osc2, 0, voice1_mixer, 1);
AudioConnection          patchCord137(filter_string_4, 0, string_mix_1, 3);
AudioConnection          patchCord138(filter_string_5, 0, string_mix_2, 0);
AudioConnection          patchCord139(filter_string_1, 0, string_mix_1, 0);
AudioConnection          patchCord140(filter_string_7, 0, string_mix_2, 2);
AudioConnection          patchCord141(filter_string_2, 0, string_mix_1, 1);
AudioConnection          patchCord142(filter_string_8, 0, string_mix_2, 3);
AudioConnection          patchCord143(filter_string_3, 0, string_mix_1, 2);
AudioConnection          patchCord144(filter_string_6, 0, string_mix_2, 1);
AudioConnection          patchCord145(filter_string_9, 0, string_mix_3, 0);
AudioConnection          patchCord146(filter_string_11, 0, string_mix_3, 2);
AudioConnection          patchCord147(filter_string_12, 0, string_mix_3, 3);
AudioConnection          patchCord148(filter_string_10, 0, string_mix_3, 1);
AudioConnection          patchCord149(transient_mix_2, 0, transient_full_mix, 1);
AudioConnection          patchCord150(transient_mix_1, 0, transient_full_mix, 0);
AudioConnection          patchCord151(transient_mix_3, 0, transient_full_mix, 2);
AudioConnection          patchCord152(voice4_envelope_filter, 0, voice4_filter, 1);
AudioConnection          patchCord153(voice3_mixer, 0, voice3_filter, 0);
AudioConnection          patchCord154(voice4_mixer, 0, voice4_filter, 0);
AudioConnection          patchCord155(voice2_mixer, 0, voice2_filter, 0);
AudioConnection          patchCord156(voice3_envelope_filter, 0, voice3_filter, 1);
AudioConnection          patchCord157(voice2_envelope_filter, 0, voice2_filter, 1);
AudioConnection          patchCord158(voice1_envelope_filter, 0, voice1_filter, 1);
AudioConnection          patchCord159(voice1_mixer, 0, voice1_filter, 0);
AudioConnection          patchCord160(transient_full_mix, 0, all_string_mix, 3);
AudioConnection          patchCord161(string_mix_3, 0, all_string_mix, 2);
AudioConnection          patchCord162(string_mix_1, 0, all_string_mix, 0);
AudioConnection          patchCord163(string_mix_2, 0, all_string_mix, 1);
AudioConnection          patchCord164(chords_tremolo_lfo, voice1_envelope);
AudioConnection          patchCord165(chords_tremolo_lfo, voice2_envelope);
AudioConnection          patchCord166(chords_tremolo_lfo, voice3_envelope);
AudioConnection          patchCord167(chords_tremolo_lfo, voice4_envelope);
AudioConnection          patchCord168(voice4_filter, 0, voice4_tremolo_mult, 0);
AudioConnection          patchCord169(voice2_filter, 0, voice2_tremolo_mult, 0);
AudioConnection          patchCord170(voice3_filter, 0, voice3_tremolo_mult, 0);
AudioConnection          patchCord171(voice1_filter, 0, voice1_tremolo_mult, 0);
AudioConnection          patchCord172(all_string_mix, string_waveshape);
AudioConnection          patchCord173(all_string_mix, 0, string_waveshaper_mix, 0);
AudioConnection          patchCord174(voice1_envelope, 0, voice1_tremolo_mult, 1);
AudioConnection          patchCord175(voice3_envelope, 0, voice3_tremolo_mult, 1);
AudioConnection          patchCord176(voice2_envelope, 0, voice2_tremolo_mult, 1);
AudioConnection          patchCord177(voice4_envelope, 0, voice4_tremolo_mult, 1);
AudioConnection          patchCord178(voice2_tremolo_mult, 0, chord_voice_mixer, 1);
AudioConnection          patchCord179(voice3_tremolo_mult, 0, chord_voice_mixer, 2);
AudioConnection          patchCord180(voice4_tremolo_mult, 0, chord_voice_mixer, 3);
AudioConnection          patchCord181(voice1_tremolo_mult, 0, chord_voice_mixer, 0);
AudioConnection          patchCord182(string_waveshape, 0, string_waveshaper_mix, 1);
AudioConnection          patchCord183(string_waveshaper_mix, 0, strings_effect_mix, 0);
AudioConnection          patchCord184(string_waveshaper_mix, 0, string_delay_mix, 0);
AudioConnection          patchCord185(chord_voice_mixer, chord_waveshape);
AudioConnection          patchCord186(chord_voice_mixer, 0, chord_waveshaper_mix, 0);
AudioConnection          patchCord187(filter_delay_strings, 0, string_delay_mix, 1);
AudioConnection          patchCord188(filter_delay_strings, 1, string_delay_mix, 2);
AudioConnection          patchCord189(filter_delay_strings, 2, string_delay_mix, 3);
AudioConnection          patchCord190(chord_waveshape, 0, chord_waveshaper_mix, 1);
AudioConnection          patchCord191(string_delay_mix, delay_strings);
AudioConnection          patchCord192(string_delay_mix, 0, strings_effect_mix, 1);
AudioConnection          patchCord193(chord_waveshaper_mix, 0, chord_delay_mix, 0);
AudioConnection          patchCord194(chord_waveshaper_mix, 0, chords_effect_mix, 0);
AudioConnection          patchCord195(string_tremolo_lfo, 0, string_multiply, 1);
AudioConnection          patchCord196(strings_effect_mix, 0, string_multiply, 0);
AudioConnection          patchCord197(filter_delay_chords, 0, chord_delay_mix, 1);
AudioConnection          patchCord198(filter_delay_chords, 1, chord_delay_mix, 2);
AudioConnection          patchCord199(filter_delay_chords, 2, chord_delay_mix, 3);
AudioConnection          patchCord200(delay_strings, 0, filter_delay_strings, 0);
AudioConnection          patchCord201(string_filter_lfo, 0, string_filter, 1);
AudioConnection          patchCord202(chord_delay_mix, delay_chords);
AudioConnection          patchCord203(chord_delay_mix, 0, chords_effect_mix, 1);
AudioConnection          patchCord204(string_multiply, 0, string_filter, 0);
AudioConnection          patchCord205(chords_effect_mix, 0, chords_main_filter, 0);
AudioConnection          patchCord206(string_filter, 0, string_filter_mixer, 0);
AudioConnection          patchCord207(string_filter, 1, string_filter_mixer, 1);
AudioConnection          patchCord208(string_filter, 2, string_filter_mixer, 2);
AudioConnection          patchCord209(delay_chords, 0, filter_delay_chords, 0);
AudioConnection          patchCord210(chords_main_filter, 0, chords_main_filter_mixer, 0);
AudioConnection          patchCord211(chords_main_filter, 1, chords_main_filter_mixer, 1);
AudioConnection          patchCord212(chords_main_filter, 2, chords_main_filter_mixer, 2);
// GUItool: end automatically generated code


//MANUAL OUTPUT SECTION
#include "effect_platervbstereo.h"
AudioSynthWaveformDc     string_gain; 
AudioEffectMultiply      string_multiplier;  
AudioAmplifier           string_amplifier; 
AudioSynthWaveformDc     string_l_stereo_gain;        
AudioSynthWaveformDc     string_r_stereo_gain;        
AudioEffectMultiply      string_l_stereo_multiply;  
AudioEffectMultiply      string_r_stereo_multiply;  
AudioSynthWaveformDc     chords_gain;        
AudioEffectMultiply      chords_multiplier;  
AudioAmplifier           chords_amplifier; 
AudioSynthWaveformDc     chords_l_stereo_gain;        
AudioSynthWaveformDc     chords_r_stereo_gain;        
AudioEffectMultiply      chords_l_stereo_multiply;  
AudioEffectMultiply      chords_r_stereo_multiply;  
AudioMixer4              reverb_mixer;   
AudioEffectPlateReverb   main_reverb;    
AudioMixer4              stereo_l_mixer;        
AudioMixer4              stereo_r_mixer;   
AudioOutputI2S           DAC_out;    
AudioOutputUSB           USB_out;      

AudioConnection          patchCord2000(string_filter_mixer, 0, string_multiplier, 0);
AudioConnection          patchCord2001(string_gain, 0, string_multiplier, 1);
AudioConnection          patchCord2002(string_multiplier, 0, string_amplifier, 0);
AudioConnection          patchCord2003(string_amplifier, 0, string_l_stereo_multiply, 0);
AudioConnection          patchCord2004(string_l_stereo_gain, 0, string_l_stereo_multiply, 1);
AudioConnection          patchCord2005(string_amplifier, 0, string_r_stereo_multiply, 0);
AudioConnection          patchCord2006(string_r_stereo_gain, 0, string_r_stereo_multiply, 1);
AudioConnection          patchCord2007(string_r_stereo_multiply, 0, stereo_r_mixer, 0);
AudioConnection          patchCord2008(string_l_stereo_multiply, 0, stereo_l_mixer, 0);
AudioConnection          patchCord2009(string_amplifier, 0, reverb_mixer, 0);

AudioConnection          patchCord2010(chords_main_filter_mixer, 0, chords_multiplier, 0);
AudioConnection          patchCord2011(chords_gain, 0, chords_multiplier, 1);
AudioConnection          patchCord2012(chords_multiplier, 0, chords_amplifier, 0);
AudioConnection          patchCord2013(chords_amplifier, 0, chords_l_stereo_multiply, 0);
AudioConnection          patchCord2014(chords_l_stereo_gain, 0, chords_l_stereo_multiply, 1);
AudioConnection          patchCord2015(chords_amplifier, 0, chords_r_stereo_multiply, 0);
AudioConnection          patchCord2016(chords_r_stereo_gain, 0, chords_r_stereo_multiply, 1);
AudioConnection          patchCord2017(chords_r_stereo_multiply, 0, stereo_r_mixer, 1);
AudioConnection          patchCord2018(chords_l_stereo_multiply, 0, stereo_l_mixer, 1);
AudioConnection          patchCord2019(chords_amplifier, 0, reverb_mixer, 1);

AudioConnection          patchCord2020(reverb_mixer, 0, main_reverb, 0);
AudioConnection          patchCord2021(main_reverb, 0, stereo_r_mixer, 2);
AudioConnection          patchCord2022(main_reverb, 1, stereo_l_mixer, 2);

AudioConnection          patchCord2023(stereo_l_mixer, 0, DAC_out, 1);
AudioConnection          patchCord2024(stereo_r_mixer, 0, DAC_out, 0);

AudioConnection          patchCord2025(stereo_l_mixer, 0, USB_out, 1);
AudioConnection          patchCord2026(stereo_r_mixer, 0, USB_out, 0);
