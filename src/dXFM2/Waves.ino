/*
*  Module for the waves
*
*  this module is about storing the wavesforms that can be displayed
*
*/

//Data is structured as a sample value range -127 to 127

const int8_t SINE_WAVE[114] PROGMEM = {0,6,7,13,14,20,21,27,28,34,34,40,41,47,48,54,54,60,61,66,67,72,73,78,78,83,84,88,89,93,94,98,98,102,103,106,107,110,110,113,114,117,117,119,119,122,122,123,124,125,125,126,126,127,127,127,127,127,127,127,126,127,125,126,124,125,122,123,119,122,117,119,114,117,110,113,107,110,103,106,98,102,94,98,89,93,84,88,78,83,73,78,67,72,61,66,54,60,48,54,41,47,34,40,28,34,21,27,14,20,7,13,0,6,-7,0,-14,-7,-21,-14,-28,-21,-34,-28,-41,-35,-48,-42,-54,-48,-61,-55,-67,-61,-73,-67,-78,-73,-84,-79,-89,-84,-94,-89,-98,-94,-103,-99,-107,-103,-110,-107,-114,-111,-117,-114,-119,-117,-122,-120,-124,-122,-125,-124,-126,-125,-127,-126,-127,-127,-127,-127,-127,-127,-127,-126,-126,-125,-125,-123,-123,-122,-121,-119,-119,-117,-116,-113,-113,-110,-110,-106,-106,-102,-102,-98,-97,-93,-93,-88,-88,-83,-83,-78,-77,-72,-71,-66,-65,-60,-59,-54,-53,-47,-46,-40,-40,-34,-33,-27,-26,-20,-19,-13,-12,-6,-5,0}

void displayWave() {
  showWave(SINE_WAVE);
}