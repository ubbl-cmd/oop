#ifndef EXCEPTION
#define EXCEPTION

#include <iostream>

class Exception: public std::exception {
public:
	virtual void display() = 0;
};

#endif
