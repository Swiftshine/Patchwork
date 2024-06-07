#ifndef FLUFF_WIIMOTE_H
#define FLUFF_WIIMOTE_H

enum InputFlags {
    Input_None          = 0,
    Input_DPAD_Left     = 0x1,
    Input_DPAD_Right    = 0x2,
    Input_DPAD_Down     = 0x4,
    Input_DPAD_Up       = 0x8,
    Input_ButtonPlus    = 0x10,
    /* classic controller would go here but KEY doesnt support classic controller */
    Input_Button2       = 0x100,
    Input_Button1       = 0x200,
    Input_ButtonB       = 0x400,
    Input_ButtonA       = 0x800,
    Input_ButtonMinus   = 0x1000,
    Input_ButtonZ       = 0x2000, // nunchuk-only
    Input_ButtonC       = 0x4000, // nunchuk-only
    Input_ButtonHome    = 0x8000,
};


#endif