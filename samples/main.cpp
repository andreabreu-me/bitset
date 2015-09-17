#include <iostream>

#define CONCAT(a,b) a##b
#define RUN_SAMPLE(sample_num) std::cout<<"-------Sample " << sample_num << "------" << \
	std::endl; \
	CONCAT(sample,sample_num)();

extern void sample1();
extern void sample2();
extern void sample3();
extern void sample4();
extern void sample5();

int main(int argc, const char* argv[]){
	RUN_SAMPLE(1);
	RUN_SAMPLE(2);
	RUN_SAMPLE(3);
	RUN_SAMPLE(4);
	RUN_SAMPLE(5);
	return 0;
}
