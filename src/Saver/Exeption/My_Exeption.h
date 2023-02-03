#ifndef EXEPTION
#define EXEPTION

#include <iostream>

class My_Exeption: public std::exception {
public:
	My_Exeption(int h) {
		// what += std::to_string(h);
	}
private:
	// std::string ;
};

#endif
