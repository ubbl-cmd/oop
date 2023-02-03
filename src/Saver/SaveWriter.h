#include "Save.h"
#include <fstream>

#ifndef SAVEWRITER
#define SAVEWRITER

class SaveWriter {
public:
	SaveWriter(std::string fileName) {ofs.open(fileName, std::ios::binary);};
	void write(Save &save);
	~SaveWriter() {ofs.close();}
private:
	std::ofstream ofs;
};

#endif
