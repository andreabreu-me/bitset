/*
 * Sample #3
 * Iterator access
 */
#include <bitset.h>
#include <iostream>

void sample3() {
	libbitset::Bitset<5> bs(0b11001); 
	
	std::cout << "Output: " << bs << std::endl;
	int idx = 0;
	for (libbitset::Bitset<5>::iterator i = bs.begin(); i != bs.end(); ++i, ++idx) 
		std::cout << "bs[" << idx << "]=" << i << std::endl;
}
