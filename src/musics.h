#include<notes.h>
//*****************************************
// PIRATAS DO CARIBE
//Fonte: https://github.com/xitangg/-Pirates-of-the-Caribbean-Theme-Song/blob/master/Pirates_of_the_Caribbean_-_Theme_Song.ino
int piratas[] = {       //Note of the song, 0 is a rest/pulse
   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,

   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
   NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
   NOTE_A4, NOTE_G4, NOTE_A4, 0,

   NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
   NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
   NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
   NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

   NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
   NOTE_D5, NOTE_E5, NOTE_A4, 0,
   NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
   NOTE_C5, NOTE_A4, NOTE_B4, 0,

   NOTE_A4, NOTE_A4,

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

   NOTE_E5, 0, 0, NOTE_F5, 0, 0,
   NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
   NOTE_D5, 0, 0, NOTE_C5, 0, 0,
   NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4
};
int dur_piratas[] = {
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125,

  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125,

  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125,
  250, 125, 250, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 375,

  250, 125,


  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500,

  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500
};
//*****************************************
//Fonte musica Super Mario:
//https://www.princetronics.com/supermariothemesong/
int mario[] = {
	NOTE_E7, NOTE_E7, 0, NOTE_E7,
	0, NOTE_C7, NOTE_E7, 0,
	NOTE_G7, 0, 0,  0,
	NOTE_G6, 0, 0, 0,
	
	NOTE_C7, 0, 0, NOTE_G6,
	0, 0, NOTE_E6, 0,
	0, NOTE_A6, 0, NOTE_B6,
	0, NOTE_AS6, NOTE_A6, 0,
	
	NOTE_G6, NOTE_E7, NOTE_G7,
	NOTE_A7, 0, NOTE_F7, NOTE_G7,
	0, NOTE_E7, 0, NOTE_C7,
	NOTE_D7, NOTE_B6, 0, 0,
	
	NOTE_C7, 0, 0, NOTE_G6,
	0, 0, NOTE_E6, 0,
	0, NOTE_A6, 0, NOTE_B6,
	0, NOTE_AS6, NOTE_A6, 0,
	
	NOTE_G6, NOTE_E7, NOTE_G7,
	NOTE_A7, 0, NOTE_F7, NOTE_G7,
	0, NOTE_E7, 0, NOTE_C7,
	NOTE_D7, NOTE_B6, 0, 0,
	
		NOTE_E7, NOTE_E7, 0, NOTE_E7,
		0, NOTE_C7, NOTE_E7, 0,
		NOTE_G7, 0, 0,  0,
		NOTE_G6, 0, 0, 0,
		
		NOTE_C7, 0, 0, NOTE_G6,
		0, 0, NOTE_E6, 0,
		0, NOTE_A6, 0, NOTE_B6,
		0, NOTE_AS6, NOTE_A6, 0,
		
		NOTE_G6, NOTE_E7, NOTE_G7,
		NOTE_A7, 0, NOTE_F7, NOTE_G7,
		0, NOTE_E7, 0, NOTE_C7,
		NOTE_D7, NOTE_B6, 0, 0,
		
		NOTE_C7, 0, 0, NOTE_G6,
		0, 0, NOTE_E6, 0,
		0, NOTE_A6, 0, NOTE_B6,
		0, NOTE_AS6, NOTE_A6, 0,
		
		NOTE_G6, NOTE_E7, NOTE_G7,
		NOTE_A7, 0, NOTE_F7, NOTE_G7,
		0, NOTE_E7, 0, NOTE_C7,
		NOTE_D7, NOTE_B6, 0, 0
};
int dur_mario[] = {
	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120,
	
	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120,
	
	90, 90, 90,
	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120,
	
	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120,
	
	90, 90, 90,
	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120,

	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120,
	
	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120,
	
	90, 90, 90,
	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120,
	
	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120,
	
	90, 90, 90,
	120, 120, 120, 120,
	120, 120, 120, 120,
	120, 120, 120, 120
	
	
};

