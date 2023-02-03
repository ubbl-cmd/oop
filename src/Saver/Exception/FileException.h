#include <iostream>
#include "Exception.h"

#ifndef FILEEXCEPTION
#define FILEEXCEPTION

class FileException: public Exception {
public:
	FileException(std::string fileName):fileName(fileName) {}
	virtual void display() {
		std::cout << "File not Found: " << fileName << std::endl;
	}
private:
	std::string fileName;
};

#endif
