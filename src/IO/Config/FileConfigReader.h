#ifndef FILECONFIGREADER
#define FILECONFIGREADER

#include <fstream>

#include "ConfigReader.h"

class FileConfigReader: public ConfigReader {
public:
	explicit FileConfigReader();
	virtual int readInt() override;
	virtual bool readBool() override;
	virtual std::string readString() override;
	virtual void writeDefaultConfig() override;
	virtual ~FileConfigReader();
private:
	std::ifstream fin;
};

#endif
