#include "SaveWriter.h"

void SaveWriter::write(Save &save) {
	ofs << save.getStateString();
}
