
/*
A simple "hello world" example.
Set the screen background color and palette colors.
Then write a message to the nametable.
Finally, turn on the PPU to display video.
*/

#include "neslib.h"

// link the pattern table into CHR ROM
//#link "chr_generic.s"

// main function, run after console reset
void main(void) {

  // set palette colors
  pal_col(0,0x11);	// set screen to dark blue
  pal_col(1,0x00);	// fuchsia
  pal_col(2,0x20);	// grey
  pal_col(3,0x39);	// white

  // write text to name table
  // Centralizei
  vram_adr(NTADR_A(012,14));		// set address
  vram_write("HELLO, WORLD!", 13);	// write bytes to video RAM

  // enable PPU rendering (turn on screen)
  ppu_on_all();

  // infinite loop
  while (1) ;
}
