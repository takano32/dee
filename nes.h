#ifndef NES_H
#define NES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <assert.h>

#include "M6502.h"
#include "mapper.h"

#define MIRROR_HORIZONTAL 0
#define MIRROR_VERTICAL 1
#define MIRROR_NONE 2
#define MIRROR_ONESCREEN 3

struct rom
{
	 char title[512];
	 byte header[16];

	 byte *prg;
	 int prg_size;

	 byte *chr;
	 int chr_size;

	 byte control_byte1;
	 byte control_byte2;
	 
	 int mapperid;
	 int mirror_flag;
	 int sram_enable;
	 int trainer;
	 int four_screen_mirroring;

	 struct mapper mapper;
};

struct ppu
{
};

struct spu
{
};

struct joypad_info
{
   byte pad[4];
   int connected;
   int state[2];
};

struct nes
{
	 M6502 _cpu;
	 struct rom _rom;
	 struct ppu _ppu;
	 struct spu _spu;
	 byte ram[0x800];
	 byte save[0x2000];
	 int scanline;
	 int time;
	 int mirror_mode, onescreen_page;
	 
	 unsigned last_sound_cycle;
	 unsigned scanline_start_cycle;
	 
	 struct joypad_info joypad;
};

struct nes nes;
void nes_init();
void nes_emulate();

#endif
