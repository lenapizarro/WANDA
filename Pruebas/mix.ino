
#include "Peine_mixer.h"
#include <peine_lib.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=221,373
AudioAmplifier           gain1;           //xy=377,279
AudioAmplifier           gain2;           //xy=379,445
LinCompressor     dec1;
LinCompressor     dec2;
AudioFilterBiquad        high1; //xy=544,224
AudioFilterBiquad        low1; //xy=544,331
AudioFilterBiquad        medium1; //xy=546,278
AudioFilterBiquad        high2;  //xy=546,388
AudioFilterBiquad        low2; //xy=546,495
AudioFilterBiquad        medium2; //xy=548,442
AudioMixer4              eq1; //xy=708,282
AudioMixer4              eq2; //xy=710,446
AudioAmplifier           l2; //xy=945,471
AudioAmplifier           l1; //xy=947,316
AudioAmplifier           r2; //xy=948,411
AudioAmplifier           r1;           //xy=950,256
AudioMixer4              l; //xy=1141,447
AudioMixer4              r; //xy=1144,293
AudioFilterBiquad        r_high_master; //xy=1313,233
AudioFilterBiquad        r_low_master; //xy=1313,340
AudioFilterBiquad        r_medium_master; //xy=1315,287
AudioFilterBiquad        l_high_master; //xy=1315,397
AudioFilterBiquad        l_low_master; //xy=1315,504
AudioFilterBiquad        l_medium_master; //xy=1317,451
AudioMixer4              r_eq_master; //xy=1477,291
AudioMixer4              l_eq_master; //xy=1479,455
AudioAmplifier           r_master; //xy=1620,291
AudioAmplifier           l_master; //xy=1623,456
AudioOutputI2S           i2sout; //xy=1769,373
AudioConnection          patchCord1(i2s1, 0, gain1, 0);
AudioConnection          patchCord2(i2s1, 1, gain2, 0);
AudioConnection          patchCord3(gain1, dec1);
AudioConnection          patchCord4(gain2, dec2);
AudioConnection          patchCord5(dec1, high1);
AudioConnection          patchCord6(dec1, medium1);
AudioConnection          patchCord7(dec1, low1);
AudioConnection          patchCord8(dec2, high2);
AudioConnection          patchCord9(dec2, medium2);
AudioConnection          patchCord10(dec2, low2);
AudioConnection          patchCord11(high1, 0, eq1, 0);
AudioConnection          patchCord12(low1, 0, eq1, 2);
AudioConnection          patchCord13(medium1, 0, eq1, 1);
AudioConnection          patchCord14(high2, 0, eq2, 0);
AudioConnection          patchCord15(low2, 0, eq2, 2);
AudioConnection          patchCord16(medium2, 0, eq2, 1);
AudioConnection          patchCord17(eq1, r1);
AudioConnection          patchCord18(eq1, l1);
AudioConnection          patchCord19(eq2, r2);
AudioConnection          patchCord20(eq2, l2);
AudioConnection          patchCord21(l2, 0, l, 1);
AudioConnection          patchCord22(l1, 0, l, 0);
AudioConnection          patchCord23(r2, 0, r, 1);
AudioConnection          patchCord24(r1, 0, r, 0);
AudioConnection          patchCord25(l, l_high_master);
AudioConnection          patchCord26(l, l_medium_master);
AudioConnection          patchCord27(l, l_low_master);
AudioConnection          patchCord28(r, r_high_master);
AudioConnection          patchCord29(r, r_medium_master);
AudioConnection          patchCord30(r, r_low_master);
AudioConnection          patchCord31(r_high_master, 0, r_eq_master, 0);
AudioConnection          patchCord32(r_low_master, 0, r_eq_master, 2);
AudioConnection          patchCord33(r_medium_master, 0, r_eq_master, 1);
AudioConnection          patchCord34(l_high_master, 0, l_eq_master, 0);
AudioConnection          patchCord35(l_low_master, 0, l_eq_master, 2);
AudioConnection          patchCord36(l_medium_master, 0, l_eq_master, 1);
AudioConnection          patchCord37(r_eq_master, r_master);
AudioConnection          patchCord38(l_eq_master, l_master);
AudioConnection          patchCord39(r_master, 0, i2sout, 0);
AudioConnection          patchCord40(l_master, 0, i2sout, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=338,200
// GUItool: end automatically generated code




// Method definition
float lineal(float input, float m){
  input = input/m;
  input = (input*50)-10;
  input = (float)pow(10,(input/20));
  return input;
}

float freq(float input, int m){
  input = (input*7900/m)+100;
  return input;
}


  float max_read = 1023.0;
  
  //Create channel objects
  channel ch1;
  channel ch2;
  channel master;




void setup() {
  Serial.begin(9600);
  AudioMemory(12);
  sgtl5000_1.enable();
  sgtl5000_1.volume(1);
  sgtl5000_1.inputSelect(AUDIO_INPUT_MIC);
  //sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN);
  sgtl5000_1.micGain(1);
  
  
  //
  //
  //DO PIN LAYOUT
  //Declar bounces para el switch de activación
  //0 ch1 1 ch2
  //
  //

  
  //Set non-changing parameters
  //Channel 1
  high1.setHighpass(0,12000,0.7071);
  low1.setLowpass(0,80,0.7071);
  
  //Channel 2
  high2.setHighpass(0,12000,0.7071);
  low2.setLowpass(0,80,0.7071);
  
  //Master
  r_high_master.setHighpass(0,12000,0.7071);
  r_low_master.setLowpass(0,80,0.7071);
  l_high_master.setHighpass(0,12000,0.7071);
  l_low_master.setLowpass(0,80,0.7071);
  
  
}

void loop() {
  /*
  if(!switch){
    
    ch1.gain = static_cast<float>(analogRead());
    ch1.hp = static_cast<float>(analogRead());
    ch1.bpgain = static_cast<float>(analogRead());
    ch1.bpfreq = static_cast<float>(analogRead());
    ch1.lp = static_cast<float>(analogRead());
    ch1.pan = static_cast<float>(analogRead());
    ch1.level = static_cast<float>(analogRead());
  
  }else{

    ch2.gain = static_cast<float>(analogRead());
    ch2.hp = static_cast<float>(analogRead());
    ch2.bpgain = static_cast<float>(analogRead());
    ch2.bpfreq = static_cast<float>(analogRead());
    ch2.lp = static_cast<float>(analogRead());
    ch2.pan = static_cast<float>(analogRead());
    ch2.level = static_cast<float>(analogRead());
      
  }
  
  master.hp = static_cast<float>(analogRead());
  master.bpgain = static_cast<float>(analogRead());
  master.bpfreq = static_cast<float>(analogRead());
  master.lp = static_cast<float>(analogRead());
  master.level = static_cast<float>(analogRead());
  */
  

    
  ch1.gain = 300;
  ch1.hp = 600;
  ch1.bpgain = 300;
  ch1.bpfreq = 605;
  ch1.lp = 650;
  ch1.pan = 1023;
  ch1.level = 200;


  ch2.gain = 300;
  ch2.hp = 300;
  ch2.bpgain = 100;
  ch2.bpfreq = 304;
  ch2.lp = 450;
  ch2.pan = 1023;
  ch2.level = 200;

  
  master.hp = 200 ;
  master.bpgain = 100;
  master.bpfreq = 240;
  master.lp = 1;
  master.level = 200;
  
  //Modify gain
  gain1.gain(lineal(ch1.gain, max_read));
  gain2.gain(lineal(ch2.gain,max_read));
  
  
  //Modify 3 band eq
  eq1.gain(0,lineal(ch1.hp,max_read));
  eq1.gain(1,lineal(ch1.bpgain,max_read));
  medium1.setBandpass(0, freq(ch1.bpfreq,max_read), 0.707);
  eq1.gain(2,lineal(ch1.lp,max_read));
  
  eq2.gain(0,lineal(ch2.hp,max_read));
  eq2.gain(1,lineal(ch2.bpgain,max_read));
  medium2.setBandpass(0, freq(ch2.bpfreq, max_read), 0.707);
  eq2.gain(2,lineal(ch2.lp,max_read));
  
  
  //Modify pan
  r1.gain(ch1.pan/max_read);
  l1.gain(1-(ch1.pan/max_read));
  
  r2.gain(ch2.pan/max_read);
  l2.gain(1-(ch2.pan/max_read));

  
  //Modify level
  r.gain(0,lineal(ch1.level,max_read));
  l.gain(0,lineal(ch1.level,max_read));
  
  r.gain(0,lineal(ch2.level,max_read));
  l.gain(0,lineal(ch2.level,max_read));

  
  
  //Master 
  //Eq
  r_eq_master.gain(0,lineal(master.hp,max_read));
  r_eq_master.gain(1,lineal(master.bpgain,max_read));
  r_medium_master.setBandpass(0, freq(master.bpfreq, max_read), 0.707);
  r_eq_master.gain(2,lineal(master.lp,max_read));
  
  l_eq_master.gain(0,lineal(master.hp,max_read));
  l_eq_master.gain(1,lineal(master.bpgain,max_read));
  l_medium_master.setBandpass(0, freq(master.bpfreq, max_read), 0.707);
  l_eq_master.gain(2,lineal(master.lp,max_read));
  
  
  //Level
  r_master.gain(lineal(master.level,max_read));
  l_master.gain(lineal(master.level,max_read));

  delay(100);   
}
