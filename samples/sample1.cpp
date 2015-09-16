#include <bitset.h>
#include <iostream>

#define xstr(s) str(s)
#define str(s) #s
#define CODE \
	Bitset<3> bs(0b110); \
	std::cout << "Output: " << bs << std::endl;

using namespace libbitset;

void sample1() {
	Bitset<5> bs(0b110); 
	std::cout << "Output: " << bs << std::endl;	// 00110
}

#undef CODE
