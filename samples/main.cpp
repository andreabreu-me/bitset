#include <iostream>

#define CONCAT(a,b) a##b
#define RUN_SAMPLE(sample_num) std::cout<<"-------Sample " << sample_num << "------" << \
	std::endl; \
	CONCAT(sample,sample_num)();

extern void sample1();

int main(int argc, const char* argv[]){
	RUN_SAMPLE(1);
	RUN_SAMPLE(1);
	RUN_SAMPLE(1);
	return 0;
}
