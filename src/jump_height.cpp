#include "kamek/kamek.h"

// Set player jump height correction from to 4.6f.

kmWrite32(0x808e6a28, 0x40933333);

/* As a side note, the "jump height correction" variable is 
simply a float that is added to the player's base jump height. 
This is set to 0.15f by default. */