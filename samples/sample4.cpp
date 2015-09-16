/*
 * Sample #4
 * Convert to unsigned long long
 */
#include <bitset.h>
#include <iostream>

void sample4() {
	libbitset::Bitset<40> bs; 
	bs.set(36);	
	std::cout << "Output: " << bs.value() << " = " << bs << std::endl;
}
