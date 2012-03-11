
void mapper3_write(register word addr, register byte value)
{
	 //unsigned tmp = value*0x2000;
}

struct mapper_methods mapper_cnrom = {
	 mapper0_init,
	 mapper0_shutdown,
	 mapper3_write,
	 mapper0_read,
	 mapper0_scanline_start,
	 mapper0_scanline_end,
	 mapper0_save_state,
	 mapper0_restore_state,
	 ignore_write,
	 ignore_read
};
