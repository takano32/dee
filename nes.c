#include "nes.h"

void nes_init()
{
}

void nes_emulate()
{
	nes_init();
    //run_until(nes.scanline_start_cycle + scan_cycles * PPU_CLOCK_DIVIDER);

    nes.time++;
}

void Wr6502 (register word Addr, register byte Value)
{
	 switch (Addr & 0xE000) {
	 case 0x0000:
		  nes.ram[Addr & 0x7FF] = Value;
		  break;

	 case 0x2000:
		  /*
		  switch ((Addr & 0x0007) | 0x2000) {
		  case ppu_cr1:
		  case ppu_cr2:
		  case ppu_status:
		  case spr_addr:
		  case spr_data:
		  case ppu_bgscroll:
		  case ppu_addr:
		  case ppu_data:
		  default:
			   printf ("Wr6502 is broken.\n");
			   break;
		  }
		  break;
		  */
	 case 0x4000:
	 case 0x6000:    
	 case 0x8000:
	 case 0xA000:
	 case 0xC000:
	 case 0xE000:
		  break;
	 }
}

byte Rd6502 (register word Addr)
{
	 switch (Addr & 0xE000) {
	 case 0x0000: return nes.ram[Addr & 0x07FF];
	 case 0x2000:
		  /*
		  switch ((Addr & 0x0007) | 0x2000) {
		  case ppu_cr1:
		  case ppu_cr2:
		  case ppu_addr:
		  case spr_addr:
		  case ppu_status:
		  case spr_data:
		  case ppu_data:
		  default:
			   printf ("PPU: Read from unknown ppu register 0x%04X\n", (int) Addr);
			   break;
		  }
		  break;      
		  */
	 case 0x4000:
	 case 0x6000:
	 case 0x8000:
	 case 0xA000:
	 case 0xC000:
	 case 0xE000:
		  break;
	 }
	 
	 return 0;
}

byte Debug6502 (register M6502 * R)
{
    char buffer[64];
    byte tmp[4];
    tmp[0] = Rd6502 (R->PC.W);
    tmp[1] = Rd6502 (R->PC.W + 1);
    tmp[2] = Rd6502 (R->PC.W + 2);
    tmp[3] = Rd6502 (R->PC.W + 3);
    //DAsm (buffer, tmp, R->PC.W);
    //nes_printtime ();
    printf ("$%04X  A=%02X X=%02X Y=%02X S=%02X  %17s   ", 
            (unsigned)R->PC.W, (unsigned)R->A, 
            (unsigned)R->X, (unsigned)R->Y, (unsigned)R->S,
            buffer);
    printf("\n");
    return 1;
}

void note_brk (void)
{
	 /*
	 if (debug_brk) {
	 byte code = Rd6502(nes.cpu.PC.W);
	 printf("%sBRK %02X: ", nes_time_string(), code);
	 regs();
	 
	 nes.cpu.Trace = code >> 7;
	 if (cputrace) nes.cpu.Trace |= 1;
	 }
	 */
}
