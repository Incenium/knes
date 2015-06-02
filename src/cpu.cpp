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
int pc = 0x4020; // program counter - http://wiki.nesdev.com/w/index.php/CPU_memory_map

// clock for last instruction
int rClock = 0;

// CPU clock
int clock = 0;

void Cpu::ADCImmediate(int val)
{
    ac += val + c;
    c = 0;
    z = ac == 0 ? 1 : 0;
    v = ac > 255 ? 1 : 0;
    ac &= 255; // mask to 8 bits
    rClock = 2;
}

void Cpu::ADCZeroPage(int addr)
{
    ac += mmu.rb(addr) + c;
    c = 0;
    z = ac == 0 ? 1 : 0;
    v = ac > 255 ? 1 : 0;
    ac &= 255; // mask to 8 bits
    rClock = 3;
}

void Cpu::ADCZeroPageX(int addr)
{
    ac += mmu.rb(addr) + x + c;
    c = 0;
    z = ac == 0 ? 1 : 0;
    v = ac > 255 ? 1 : 0;
    ac &= 255; // mask to 8 bits
    rClock = 3;
}

void Cpu::ADCAbsolute(int addr)
{
    ac += mmu.rb(addr) + c;
    c = 0;
    z = ac == 0 ? 1 : 0;
    v = ac > 255 ? 1 : 0;
    ac &= 255; // mask to 8 bits
    rClock = 4; // * Add 1 if page boundary is crossed. (need to investigate what this means in docs)
}

void Cpu::ADCAbsoluteX(int addr)
{
    ac += mmu.rb(addr) + x + c;
    c = 0;
    z = ac == 0 ? 1 : 0;
    v = ac > 255 ? 1 : 0;
    ac &= 255; // mask to 8 bits
    rClock = 4; // * Add 1 if page boundary is crossed. (need to investigate what this means in docs)
}

void Cpu::ADCAbsoluteY(int addr)
{
    ac += mmu.rb(addr) + y + c;
    c = 0;
    z = ac == 0 ? 1 : 0;
    v = ac > 255 ? 1 : 0;
    ac &= 255; // mask to 8 bits
    rClock = 4; // * Add 1 if page boundary is crossed. (need to investigate what this means in docs)
}