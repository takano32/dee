
void mapper0_init()
{
}

void mapper0_shutdown()
{
}

void mapper0_write(register word addr, register byte value)
{
}

void mapper0_read()
{
}

void mapper0_scanline_start()
{
}

void mapper0_scanline_end()
{
}

void mapper0_save_state()
{
}

void mapper0_restore_state()
{
}

void ignore_write()
{
}

void ignore_read()
{
}

struct mapper_methods mapper0 = {
	 mapper0_init,
	 mapper0_shutdown,
	 mapper0_write,
	 mapper0_read,
	 mapper0_scanline_start,
	 mapper0_scanline_end,
	 mapper0_save_state,
	 mapper0_restore_state,
	 ignore_write,
	 ignore_read
};

