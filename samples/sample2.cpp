/*
 * sample bit access
 */
#include <bitset.h>
#include <iostream>

void sample2() {
	libbitset::Bitset<5> bs; 

	bs[0] =	bs[3] = 1;
	std::cout << "Output: " << bs << std::endl;	// 01001
}
