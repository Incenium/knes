#include <iostream>
#include <fstream>
#include <vector>
#include "../header/cpu.h"

int main(int argc, char* argv[])
{
    char* path = argv[1];
    std::ifstream rom (path, std::ios::binary);
    std::vector<char> bin((std::istreambuf_iterator<char>(rom)),
                            std::istreambuf_iterator<char>());

    // example code for main emulator loop
    // while (true) {
    //  int op = MMU.rb(CPU.pc++);
    //  CPU.handleOp(op)
    //  CPU.clock += CPU.rClock

    return 0;
}
