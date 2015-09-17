/*
 * Sample #5
 * clear bit
 */
#include <bitset.h>
#include <iostream>

void sample5() {
	libbitset::Bitset<3> bs(7); // 111 
	bs.clear(1);	
	std::cout << "Output: " << bs << std::endl;	// 101
}
