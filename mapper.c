#ifndef MAPPER_C
#define MAPPER_C

#include "nes.h"
#include "mappers/mapper0.c"
#include "mappers/cnrom.c"

struct mapper mapper_tbl[] = {
	 {0, "Mapper 3: CNROM", &mapper_cnrom}
};

struct mapper *find_mapper(int mapperid)
{
	 int i, tbl_size;

	 tbl_size = sizeof(mapper_tbl) / sizeof(mapper_tbl[0]);
	 for(i=0; i<tbl_size; i++)
		  if(mapper_tbl[i].id == mapperid)
			   return &mapper_tbl[i];

	 return NULL;
}

#endif
