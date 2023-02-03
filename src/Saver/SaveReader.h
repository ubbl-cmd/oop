#include "Save.h"
#include <fstream>

#include "Event.h"
#include "ExitEvent.h"
#include "TrapEvent.h"
#include "PassMapEvent.h"
#include "KeyEvent.h"
#include "AllKeysEvent.h"

#include "FileException.h"
#include "UnrealSaveException.h"

#ifndef SAVEREADER
#define SAVEREADER

class SaveReader {
public:
	SaveReader(std::string fileName) {
		ifs.open(fileName, std::ios::binary);
		if(!ifs.is_open()) throw (FileException(fileName));
		if (!check_file(fileName)) {
			throw UnrealSaveException("wrong save's hash");
		}
	};

	bool check_file(std::string fileName) {
		std::ifstream f(fileName, std::ios::binary);
		if (!f.is_open()) {
			return 0;
		}
		std::string st;
		std::string line = "";
		std::string prev_line = "";
		while (std::getline(f, line)) {
			st += prev_line;
			prev_line = line;
		}
		int x,y;
		y = atoi(line.c_str());
		x = st[0];
		for (int i = 1; i < st.length(); i++) {
			x ^= st[i];
		}
		return x == y;
	}
	Field* read(Field * field, Player & player, GameStatus & gs);
	~SaveReader() {ifs.close();}
private:
	std::ifstream ifs;
};

#endif

