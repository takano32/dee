#include "nes.h"
#include "rom.h"
#include "const.h"
#include "util.h"

void usage()
{
	 printf("usage: ./dee [rom]");
}

int main(int argc, char **argv)
{
	 if(argc != 2){
		  usage();
		  exit(0);
	 }

	 printf("load %s\n", argv[1]);
	 load_rom(argv[1]);
	 
	 while(1){
		  timer_start = timer();
		  while(timer_start >= timer_next)
			   timer_start += (1000000ll / 60ll);

		  nes_emulate();
	 }
}
