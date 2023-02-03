#include "Save.h"
#include <fstream>

#include "Event.h"
#include "ExitEvent.h"
#include "TrapEvent.h"
#include "PassMapEvent.h"
#include "KeyEvent.h"
#include "AllKeysEvent.h"

#ifndef SAVEREADER
#define SAVEREADER

class SaveReader {
public:
	SaveReader(std::string fileName) {ifs.open(fileName, std::ios::binary);};
	void read(Field * field, Player & player, GameStatus & gs);
	~SaveReader() {ifs.close();}
private:
	std::ifstream ifs;
};

#endif

