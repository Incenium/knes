#include "../header/cpu.h"

// 8 bit registers
int ac = 0; // accumulator
int x = 0;
int y = 0;
int sp = 0; // stack pointer

// status register (only 7 because one bit is not used)
int c = 0; // carry
int z = 0; // zero
int i = 0; // interrupt enable/disable
int d = 0; // decimal mode
int b = 0; // software interrupt
int v = 0; // overflow
int s = 0; // sign

// 16 bit registers
int pc = 0; // program counter

// clock for last instruction
int rClock = 0;

// CPU clock
int clock = 0;

void Cpu::ADCImmediate(int val)
{
    ac += val + c;
    c = 0;
    if (ac == 0) { z = 1; }
    if (ac > 255) { v = 1; }
    ac &= 255; // mask to 8 bits
    rClock = 2;
}
