#ifndef MAPPER_H
#define MAPPER_H

#include "nes.h"

struct mapper_methods
{
	 void (*mapper_init)();
	 void (*mapper_shutdown)();
	 void (*mapper_write)(register word addr, register byte value);
	 void (*mapper_read)();
	 void (*mapper_scanline_start)();
	 void (*mapper_scanline_end)();
	 void (*mapper_save_state)();
	 void (*mapper_restore_state)();
	 void (*ignore_write)();
	 void (*ignore_read)();
};

struct mapper
{
	 int id;
	 char *name;
	 struct mapper_methods *methods;
};

extern struct mapper *find_mapper(int mapperid);

#endif
