#include "rom.h"

struct rom load_rom(char *file)
{
	 int fd, err;
	 byte ines_magic[4] = {'N', 'E', 'S', 0x1A};
	 byte control_byte1, control_byte2;
	 struct rom rom;
	 struct stat sbuf;

	 memset(&rom, 0, sizeof(rom));
	 strcpy(rom.title, file);

	 fd = open(file, O_RDONLY);
	 if(fd <= 0){
		  err = errno;
		  perror("open");
		  exit(err);
	 }

	 if(stat(file, &sbuf)){
		  err = errno;
		  perror("open");
		  exit(err);
	 }

	 /* ROM HEADER */
	 if(read(fd, rom.header, 16) <= 0){
		  err = errno;
		  perror("read");
		  exit(err);
	 }

	 if(memcmp(rom.header, ines_magic, 4)){
		  printf("No iNES format detected\n");
		  exit(0);
	 }
	 printf("iNES format\n");

	 rom.prg_size = rom.header[4] * 1024 * 16;
	 rom.chr_size = rom.header[5] * 1024 * 8;
	 control_byte1 = rom.header[6];
	 control_byte2 = rom.header[7];
	 
	 if(rom.prg_size > 0)
		  rom.prg = (byte *)malloc(rom.prg_size);

	 if(rom.chr_size > 0)
		  rom.chr = (byte *)malloc(rom.chr_size);

	 if(rom.prg == NULL || rom.chr == NULL){
		  printf("Can't malloc for rom.");
		  exit(0);
	 }

	 /* ROM PRG */
	 if(read(fd, (void *)rom.prg, rom.prg_size) <= 0){
		  err = errno;
		  perror("read ROM PRG");
		  exit(err);
	 }

	 /* ROM CHR */
	 if(read(fd, (void *)rom.chr, rom.chr_size) <= 0){
		  err = errno;
		  perror("read ROM CHR");
		  exit(err);
	 }

	 /* ROM Control Byte 1 */
	 rom.mirror_flag = (control_byte1 & 1) ? MIRROR_VERTICAL : MIRROR_HORIZONTAL;
	 rom.sram_enable = (control_byte1 & 2);
	 rom.trainer = (control_byte1 & 4);
	 rom.four_screen_mirroring = (control_byte1 & 8);
	 
	 close(fd);

	 printf("ROM PRG: %d byte\n", rom.prg_size);
	 printf("ROM CHR: %d byte\n", rom.chr_size);

	 char c[8];
	 byte2binary(control_byte1, c);
	 printf("ROM FLAGS: %s\n", c);
	 printf("ROM MIRROR FLAG: %d\n", rom.mirror_flag);
	 printf("ROM SRAM ENABLE: %d\n", rom.sram_enable);
	 printf("ROM TRAINER: %d\n", rom.trainer);
	 printf("ROM 4 SCREEN MIRRORING: %d\n", rom.four_screen_mirroring);

	 /* ROM Control Byte 1 */
	 byte2binary(control_byte2, c);
	 printf("ROM FLAGS: %s\n", c);

	 return rom;
}
