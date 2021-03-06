/***************************************************************************
    Music Selection Screen.

    This is a combination of a tilemap and overlayed sprites.

    Copyright Chris White.
    See license.txt for more details.
***************************************************************************/

#pragma once

#include "outrun.hpp"

class OMusic
{
public:
    // Music Track Selected By Player
    uint8_t music_selected;

    OMusic(void);
    ~OMusic(void);

    void enable();
    void disable();
    void tick();
    void blit();
    void check_start();

private:
    uint16_t entry_start;

    // Used to preview music track
    int16_t last_music_selected;
    int8_t preview_counter;
    
	void setup_sprite1();
	void setup_sprite2();
	void setup_sprite3();
	void setup_sprite4();
	void setup_sprite5();
    void blit_music_select();
};

extern OMusic omusic;

