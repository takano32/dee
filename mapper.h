#ifndef MAPPER_H
#define MAPPER_H

#include "nes.h"

struct mapper_methods
{
};

struct mapper
{
	 int id;
	 char *name;
	 struct mapper_methods *methods;
};

#endif
