#include "kamek/kamek.h"

// Set player jump height correction to a custom value

// till i find out how i can just use the float,
// you can use this float -> hex converter
// https://gregstoll.com/~gregstoll/floattohex/

// uncomment this if you want to use it
//kmWrite32(0x808e6a28, 0x40200000); // 2.5f


/* As a side note, the "jump height correction" variable is 
simply a float that is added to the player's base jump height. 
This is set to 0.15f by default. */