#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[])
{
    char* path = argv[1];
    std::ifstream rom (path, std::ios::binary);
    std::vector<char> bin((std::istreambuf_iterator<char>(rom)),
                            std::istreambuf_iterator<char>());

    // need to figure out best way to iterate through ROM here
    // this loop is just to show you that the vector works because first 3 chars
    // are "NES", which is what it should be per http://nesdev.com/NESDoc.pdf
    for (int i = 0; i < 3; i++) {
        std::cout << bin[i];
    }

    return 0;
}
