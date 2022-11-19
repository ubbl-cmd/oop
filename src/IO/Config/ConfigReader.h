#ifndef CONFIGREADER
#define CONFIGREADER

#include <string>
#include <vector>

#include "Move.h"

class ConfigReader {
public:
	Move* getMovesFromConfig();
	virtual int readInt() = 0;
	virtual bool readBool() = 0;
	virtual std::string readString() = 0;
	int getNumberOfMoves() {return numberOfMoves;};
protected:
	int numberOfMoves;
	virtual void writeDefaultConfig() = 0;
};

#endif
