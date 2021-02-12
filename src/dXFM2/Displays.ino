/*
*  Module for the Displays
*
*  this module contains the code to setup a particular display
*
*/
void showDisplay(uint8_t op) {
  switch (greenSelect) {
    case 0: showLFODisplay(op); break;
    case 1: showOSCDisplay(op); break;
    case 2: showOPSDisplay(op); break;
    case 3: showEFXDisplay(op); break;
    case 4: showMasterDisplay(op); break;
    case 5: showEFXDisplay(op); break;
    case 6: showOPSDisplay(op); break;
    case 7: showOSCDisplay(op); break;
    case 8: showLFODisplay(op); break;
  }
}

void showLFODisplay(uint8_t op) {
  switch (blueSelect) {
    case 0: showLFO(op); break;
    case 1: showKeyTracking(op); break;
    case 2: showKeyTracking(op); break;
    case 3: showKeyTracking(op); break;
    case 4: showPMS(op); break;
    case 5: showAMS(op); break;
  }
}

void showOSCDisplay(uint8_t op) {
  switch (blueSelect) {
    case 0: showWave(op,2); break;
    case 1: showOSCRatio(op); break;
    case 2: showWave(op,1); break;
    case 3: showPhase(op); break;
    case 4: showPitchEnvelope(op); break;
    case 5: showPitchEnvelope(op); break;
  }
}

void showOPSDisplay(uint8_t op) {
  switch (blueSelect) {
    case 0: showLevel(op); break;
    case 1: showRatio(op); break;
    case 2: showPitch(op); break;
    case 3: showFeedback(op); break;
    case 4: showAmplitudeEnvelope(op); break;
    case 5: showAmplitudeEnvelope(op); break;
  }
}

void showEFXDisplay(uint8_t op) {
  //Missing: Bitcrusher & Decimator
  //EFX routing could be done via screen swapping
  //Routing is:
  //Bitcrusher->Decimator->Filter->Chorus->Phaser->AM->Delay
  //Bitcrusher->Decimator->Filter->Delay->Chorus->Phaser->AM
  switch (op) {
    case 0: showParamValueOnScreen(F("AM"),0,getParam(greenSelect,blueSelect,operatorSelect,0,0).param); break;
    case 1: showParamValueOnScreen(F("Delay"),1,getParam(greenSelect,blueSelect,operatorSelect,1,0).param); break;
    case 2: showParamValueOnScreen(F("Phaser"),2,getParam(greenSelect,blueSelect,operatorSelect,2,0).param); break;
    case 3: showParamValueOnScreen(F("Reverb"),3,getParam(greenSelect,blueSelect,operatorSelect,3,0).param); break;
    case 4: showParamValueOnScreen(F("Chorus"),4,getParam(greenSelect,blueSelect,operatorSelect,4,0).param); break;
    case 5: showParamValueOnScreen(F("Effects"),5,getParam(greenSelect,blueSelect,operatorSelect,5,0).param); break;
    case 6: showParamValueOnScreen(F("Filter"),6,getParam(greenSelect,blueSelect,operatorSelect,6,0).param); break;
  }
}

void showMasterDisplay(uint8_t op) {
  switch (blueSelect) {
    case 0: showMaster(op); break;
    case 1: showReserved(op); break;
    case 2: showVeloSense(op,0); break;
    case 3: showVeloSense(op,1); break;
    case 4: showMixer(op,0); break;
    case 5: showMixer(op,1); break;
  }
}

//
// LFO submenu
//
void showAMS(uint8_t op) {
  showParamValueOnScreen(F("AMS"),op,getParam(greenSelect,blueSelect,operatorSelect,op,0).param);
}

void showPMS(uint8_t op) {
  showParamValueOnScreen(F("PMS"),op,getParam(greenSelect,blueSelect,operatorSelect,op,0).param);
}

void showKeyTracking(uint8_t op) {
  showParamValueOnScreen(F("Tracking"),op,getParam(greenSelect,blueSelect,operatorSelect,op,0).param);
}

void showLFO(uint8_t op) {
  switch (op) {
    case 0: showParamValueOnScreen(F("LFO Wave"),0,getParam(greenSelect,blueSelect,operatorSelect,0,0).param); break;
    case 1: showParamValueOnScreen(F("LFO Speed"),1,getParam(greenSelect,blueSelect,operatorSelect,1,0).param); break;
    case 2: showParamValueOnScreen(F("LFO Sync"),2,getParam(greenSelect,blueSelect,operatorSelect,2,0).param); break;
    case 3: showParamValueOnScreen(F("LFO Fade"),3,getParam(greenSelect,blueSelect,operatorSelect,3,0).param); break;
    case 4: showParamValueOnScreen(F("LFO P.Depth"),4,getParam(greenSelect,blueSelect,operatorSelect,4,0).param); break;
    case 5: showParamValueOnScreen(F("LFO A.Depth"),5,getParam(greenSelect,blueSelect,operatorSelect,5,0).param); break;
    case 6: showParamValueOnScreen(F("Volume"),6,getParam(greenSelect,blueSelect,operatorSelect,6,0).param); break;
  }
}

//
// Oscillator submenu
//
void showPitchEnvelope(uint8_t op) {
  showParamValueOnScreen(F("Pitch Env"),op,getParam(greenSelect,blueSelect,operatorSelect,op,0).param);
}

void showPhase(uint8_t op) {
  if (op==6) {
    showParamValueOnScreen(F("NOP"),6,getParam(greenSelect,blueSelect,operatorSelect,6,0).param);
  } else {
    showParamValueOnScreen(F("Phase"),op,getParam(greenSelect,blueSelect,operatorSelect,op,0).param);
  }
}

void showWave(uint8_t op, uint8_t widx) {
  if (op==6) {
    if (widx==1) {
      showParamValueOnScreen(F("Volume"),6,getParam(greenSelect,blueSelect,operatorSelect,6,0).param);
    } else {
      showParamValueOnScreen(F("NOP"),6,getParam(greenSelect,blueSelect,operatorSelect,6,0).param);
    }
  } else {
    showParamValueOnScreen(F("Wave"),op,getParam(greenSelect,blueSelect,operatorSelect,op,0).param);
  }
}

void showOSCRatio(uint8_t op) {
  if (op==6) {
    showParamValueOnScreen(F("NOP"),6,getParam(greenSelect,blueSelect,operatorSelect,6,0).param);
  } else {
    showParamValueOnScreen(F("OSC Ratio"),op,getParam(greenSelect,blueSelect,operatorSelect,op,0).param);
  }
}

//
// Operator submenu
//
void showAmplitudeEnvelope(uint8_t op) {
  if (op==6) {
    showValueOnScreen(F("NOP"),6,getParamValue(greenSelect,blueSelect,6,0,0));
  } else {
    env_type env;
    env.level[0] = getParamValue(greenSelect,5,op,0,0); //Start level
    env.level[1] = getParamValue(greenSelect,5,op,1,0); //Level at end of attack phase
    env.level[2] = getParamValue(greenSelect,5,op,2,0); //Level at end of decay-1 phase
    env.level[3] = getParamValue(greenSelect,5,op,3,0); //Level at end of decay-2 phase (= sustain level)
    env.level[4] = getParamValue(greenSelect,5,op,4,0); //Level at end of release-1 phase
    env.level[5] = getParamValue(greenSelect,5,op,5,0); //Level at end of release-2 phase (= end level)
    env.rate[0] = getParamValue(greenSelect,4,op,6,0); //Delay
    env.rate[1] = getParamValue(greenSelect,4,op,0,0); //Rate of attack phase
    env.rate[2] = getParamValue(greenSelect,4,op,1,0); //Rate of decay-1 phase
    env.rate[3] = getParamValue(greenSelect,4,op,2,0); //Rate of decay-2 phase
    env.rate[4] = getParamValue(greenSelect,4,op,4,0); //Rate of releease-1 phase
    env.rate[5] = getParamValue(greenSelect,4,op,5,0); //Rate of releease-2 phase
    
    showEnvelopeOnScreen(op,(blueSelect-4)*7+operatorUsed,env,(op==operatorSelect),getParamValue(greenSelect,blueSelect,operatorSelect,operatorUsed,0));
    //showValueOnScreen(F("Envelope"),op,getParamValue(greenSelect,blueSelect,operatorSelect,op,0));
  }
}

void showFeedback(uint8_t op) {
  if (op==6) {
    showValueOnScreen(F("NOP"),6,getParamValue(greenSelect,blueSelect,operatorSelect,6,0));
  } else {
    showValueOnScreen(F("Feedback"),op,getParamValue(greenSelect,blueSelect,operatorSelect,op,0));
  }
}

void showPitch(uint8_t op) {
  if (op==6) {
    showValueOnScreen(F("NOP"),6,getParamValue(greenSelect,blueSelect,operatorSelect,6,0));
  } else {
    showValueOnScreen(F("Pitch"),op,getParamValue(greenSelect,blueSelect,operatorSelect,op,0));
  }
}

void showRatio(uint8_t op) {
  if (op==6) {
    showValueOnScreen(F("Volume"),6,getParamValue(greenSelect,blueSelect,operatorSelect,6,0));
  } else {
    showRatioOnScreen(op,toggleMode,getParamValue(greenSelect,blueSelect,operatorSelect,op,0),getParamValue(greenSelect,blueSelect,operatorSelect,op,1));
  }
}

void showLevel(uint8_t op) {
  if (op==6) {
    showValueOnScreen(F("Volume"),6,getParamValue(greenSelect,blueSelect,operatorSelect,6,0));
  } else {
    showValueOnScreen(F("Level"),op,getParamValue(greenSelect,blueSelect,operatorSelect,op,0));
  }
}

//
// Effects submenu
//

//
// Master submenu
//
void showMixer(uint8_t op, uint8_t unit) {
  showParamValueOnScreen(F("Mixer"),op,getParam(greenSelect,blueSelect,operatorSelect,op,0).param);
}

void showVeloSense(uint8_t op, uint8_t unit) {
  showParamValueOnScreen(F("Velo sense"),op,getParam(greenSelect,blueSelect,operatorSelect,op,0).param);
}

void showReserved(uint8_t op) {
  showParamValueOnScreen(F("Reserved"),op,getParam(greenSelect,blueSelect,operatorSelect,op,0).param);
}

void showMaster(uint8_t op) {
  switch (op) {
    case 0: showParamValueOnScreen(F("Pan"),0,getParam(greenSelect,blueSelect,operatorSelect,0,0).param); break;
    case 1: showParamValueOnScreen(F("Transpose"),1,getParam(greenSelect,blueSelect,operatorSelect,1,0).param); break;
    case 2: showParamValueOnScreen(F("Mono-Poly"),2,getParam(greenSelect,blueSelect,operatorSelect,2,0).param); break;
    case 3: showParamValueOnScreen(F("Porta time"),3,getParam(greenSelect,blueSelect,operatorSelect,3,0).param); break;
    case 4: showParamValueOnScreen(F("Porta mode"),4,getParam(greenSelect,blueSelect,operatorSelect,4,0).param); break;
    case 5: showParamValueOnScreen(F("Tuning"),5,getParam(greenSelect,blueSelect,operatorSelect,5,0).param); break;
    case 6: showParamValueOnScreen(F("Output/Gain"),6,getParam(greenSelect,blueSelect,operatorSelect,6,0).param); break;
  }
}