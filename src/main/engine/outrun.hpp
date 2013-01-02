/***************************************************************************
    OutRun Engine Entry Point.

    This is the hub of the ported OutRun code.

    Copyright Chris White.
    See license.txt for more details.
***************************************************************************/

#pragma once

#include "stdint.hpp"
#include "roms.hpp"
#include "globals.hpp"

#include "sdl/video.hpp"

#include "frontend/config.hpp"

// Main include for Ported OutRun Code
#include "oaddresses.hpp"
#include "otiles.hpp"
#include "oentry.hpp"
#include "osprite.hpp"
#include "osprites.hpp"
#include "oferrari.hpp"
#include "osmoke.hpp"
#include "otraffic.hpp"
#include "olevelobjs.hpp"
#include "ologo.hpp"
#include "oroad.hpp"
#include "oinitengine.hpp"
#include "oinputs.hpp"
#include "ohud.hpp"
#include "ocrash.hpp"
#include "oattractai.hpp"
#include "oanimseq.hpp"
#include "ostats.hpp"
#include "omap.hpp"
#include "ohiscore.hpp"
#include "omusic.hpp"
#include "obonus.hpp"
#include "audio/osoundint.hpp"

// Globals
enum 
{
	GS_INIT = 0,				//0  = Initalize Game
	GS_ATTRACT = 1,				//1  = Attract Mode
	GS_INIT_BEST1 = 2,			//2  = Load Best Outrunners
	GS_BEST1 = 3,				//3  = Best Outrunners (Attract Mode)
	GS_INIT_LOGO = 4,			//4  = Load Outrun Logo
	GS_LOGO = 5,				//5  = Outrun Logo (Attract Mode)
	GS_INIT_MUSIC = 6,			//6  = Load Music Selection Screen
	GS_MUSIC = 7,				//7  = Music Selection Screen
	GS_INIT_GAME = 8,			//8  = Loading In-Game
	GS_START1 = 9,				//9  = Start Game, Car Driving In
	GS_START2 = 10,				//A  = Start Game, Countdown
	GS_START3 = 11,				//B  = Start Game, Countdown 2
	GS_INGAME = 12,				//C  = Start Game, User in control
	GS_INIT_BONUS = 13,			//D  = Load Bonus Points
	GS_BONUS = 14,				//E  = Display Bonus Points
	GS_INIT_GAMEOVER = 15,	    //F  = Load Game Over
	GS_GAMEOVER = 16,           //10 = Game Over Text
	GS_INIT_MAP = 17,			//11 = Load Course Map
	GS_MAP = 18,				//12 = Course Map
	GS_INIT_BEST2 = 19,			//13 = Load Best Outrunners
	GS_BEST2 = 20,			    //14 = Best Outrunners
	GS_REINIT = 21,				//15 = Reinitalize Game (after outrunners screen)
};

struct adr_t
{
    // CPU 0
    uint32_t tiles_def_lookup;
    uint32_t tiles_table;

    uint32_t sprite_master_table;
    uint32_t sprite_type_table;
    uint32_t sprite_def_props1;
    uint32_t sprite_def_props2;
    uint32_t sprite_cloud;
    uint32_t sprite_minitree;
    uint32_t sprite_grass;
    uint32_t sprite_sand;
    uint32_t sprite_stone;
    uint32_t sprite_water;
    uint32_t sprite_ferrari_frames;
    uint32_t sprite_skid_frames;
    uint32_t sprite_pass_frames;
    uint32_t sprite_pass1_skidl;
    uint32_t sprite_pass1_skidr;
    uint32_t sprite_pass2_skidl;
    uint32_t sprite_pass2_skidr;
    uint32_t sprite_crash_spin1;
    uint32_t sprite_crash_spin2;
    uint32_t sprite_bump_data1;
    uint32_t sprite_bump_data2;
    uint32_t sprite_crash_man1;
    uint32_t sprite_crash_girl1;
    uint32_t sprite_crash_flip;
    uint32_t sprite_crash_flip_m1;
    uint32_t sprite_crash_flip_g1;
    uint32_t sprite_crash_flip_m2;
    uint32_t sprite_crash_flip_g2;
    uint32_t sprite_crash_man2;
    uint32_t sprite_crash_girl2;
    uint32_t smoke_data;
    uint32_t spray_data;
    uint32_t shadow_data;
    uint32_t shadow_frames;
    uint32_t sprite_shadow_small;

    uint32_t sprite_logo_bg;
    uint32_t sprite_logo_car;
    uint32_t sprite_logo_bird1;
    uint32_t sprite_logo_bird2;
    uint32_t sprite_logo_base;
    uint32_t sprite_logo_text;
    uint32_t sprite_logo_palm1;
    uint32_t sprite_logo_palm2;
    uint32_t sprite_logo_palm3;

    uint32_t sprite_fm_left;
    uint32_t sprite_fm_centre;
    uint32_t sprite_fm_right;
    uint32_t sprite_dial_left;
    uint32_t sprite_dial_centre;
    uint32_t sprite_dial_right;
    uint32_t sprite_eq;
    uint32_t sprite_radio;
    uint32_t sprite_hand_left;
    uint32_t sprite_hand_centre;
    uint32_t sprite_hand_right;

    uint32_t sprite_coursemap_top;
    uint32_t sprite_coursemap_bot;
    uint32_t sprite_coursemap_end;
    uint32_t sprite_minicar_right;
    uint32_t sprite_minicar_up;
    uint32_t sprite_minicar_down;

    uint32_t anim_seq_flag;
    uint32_t anim_ferrari_curr;
    uint32_t anim_ferrari_next;
    uint32_t anim_pass1_curr;
    uint32_t anim_pass1_next;
    uint32_t anim_pass2_curr;
    uint32_t anim_pass2_next;

    uint32_t anim_ferrari_frames;
    uint32_t anim_endseq_obj1;
    uint32_t anim_endseq_obj2;
    uint32_t anim_endseq_obj3;
    uint32_t anim_endseq_obj4;
    uint32_t anim_endseq_obj5;
    uint32_t anim_endseq_obj6;
    uint32_t anim_endseq_obj7;
    uint32_t anim_endseq_obj8;
    uint32_t anim_endseq_objA;
    uint32_t anim_endseq_objB;
    uint32_t anim_end_table;

    uint32_t traffic_props;
    uint32_t traffic_data;
    uint32_t sprite_porsche;

    uint32_t sprite_coursemap;
    uint32_t road_seg_table;
    uint32_t road_seg_end;
    uint32_t road_seg_split;
    
    // CPU 1
    uint32_t road_height_lookup;
};

class Outrun
{
public:
    // Service Mode Toggle: Not implemented yet.
    bool service_mode;

    // Frame counter
	uint32_t frame;

    // Tick Logic. Used when running at non-standard > 30 fps
    bool tick_frame;

    // Tick Counter (always syncd to 30 fps to flash text and other stuff)
    uint32_t tick_counter;

    // Main game state
    int8_t game_state;

    // Address structures
    adr_t adr;

	Outrun();
	~Outrun();
	void init();
	void tick();
	void vint();
    void select_course(bool jap);

private:    
    // Set to debug a particular level
    static const uint8_t LOAD_LEVEL = 0;

    // Car Increment Backup for attract mode
    uint32_t car_inc_bak;

    // Debug to denote when fork has been chosen
    int8_t fork_chosen;
	void jump_table();
	void init_jump_table();
	void main_switch();
    void controls();
    bool decrement_timers();
};

extern Outrun outrun;
