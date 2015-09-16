/*
 * Sample 1
 * Output bitset to console
 */
#include <bitset.h>
#include <iostream>

void sample1() {
	libbitset::Bitset<5> bs(0b110); 
	std::cout << "Output: " << bs << std::endl;	// 00110
}
