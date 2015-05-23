class Cpu {
    public:
        void ADCImmediate(int val);
        void ADCZeroPage(int addr);
        void ADCZeroPageX(int addr);
        void ADCAbsolute(int addr);
        void ADCAbsoluteX(int addr);
        void ADCAbsoluteY(int addr);
        void ADCIndirectX(int addr);
        void ADCIndrectY(int addr);
        // more functions for CPU

    private:
        // 8 bit registers
        int ac; // accumulator
        int x;
        int y;
        int sp; // stack pointer
        int status;

        // 16 bit registers
        int pc; // program counter

        // status register (only 7 because one bit is not used)
        int c; // carry
        int z; // zero
        int i; // interrupt enable/disable
        int d; // decimal mode
        int b; // software interrupt
        int v; // overflow
        int s; // sign

        // clock for last instruction
        int rClock;

        // CPU clock
        int clock;
};
