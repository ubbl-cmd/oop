#include <iostream>
#include "Exception.h"

#ifndef UNREALSAVEEXCEPTION
#define UNREALSAVEEXCEPTION

class UnrealSaveException: public Exception {
public:
	UnrealSaveException(std::string message):message(message) {}
	virtual void display() {
		std::cout << "SaveError: " << message << std::endl;
	}
private:
	std::string message;
};

#endif

