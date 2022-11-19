#include "FileConfigReader.h"
FileConfigReader::FileConfigReader() {
	fin.open("game.conf", std::ios::binary);
	if (!fin.is_open()) {
		writeDefaultConfig();
		fin.open("game.conf", std::ios::binary);
	}
}

int FileConfigReader::readInt() {
	int a;
	fin >> a;
	return a;
}

bool FileConfigReader::readBool() {
	bool b;
	fin >> b;
	return b;
}

std::string FileConfigReader::readString() {
	std::string s;
	fin >> s;
	return s;
}

void FileConfigReader::writeDefaultConfig() {
	std::ofstream ofs("game.conf", std::ios::binary);
	ofs << "9\nMove 0 0 0 0 *\nMove 1 1 0 0 c\nMove 1 1 0 1 z\nMove 1 1 1 0 e\nMove 1 1 1 1 q\nMove 0 1 0 0 d\nMove 0 1 0 1 a\nMove 1 0 0 0 s\nMove 1 0 1 0 w";
	ofs.close();
}

FileConfigReader::~FileConfigReader() {
	fin.close();
}
