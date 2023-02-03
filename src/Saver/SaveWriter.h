#include "Save.h"
#include <fstream>
#include "FileException.h"

#ifndef SAVEWRITER
#define SAVEWRITER

class SaveWriter {
public:
	SaveWriter(std::string fileName) {
		ofs.open(fileName, std::ios::binary); if (!ofs) throw( FileException("fileName") );
	};
	void write(Save &save);
	~SaveWriter() {ofs.close();}
private:
	std::ofstream ofs;
};

#endif
