#ifndef FLUFF_GIMMICK_PL_STATE_CHANGE_H
#define FLUFF_GIMMICK_PL_STATE_CHANGE_H

#include "game/object/gimmick/gimmick.h"
#include "gfl/gfl.h"


class GmkPlStateChange : public Gimmick {
public:
    GmkPlStateChange(gfl::String::BasicString* stateName);
    ~GmkPlStateChange();
public:
};

#endif