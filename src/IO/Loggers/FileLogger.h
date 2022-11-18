#ifndef FILELOGGER_H
#define FILELOGGER_H
#include <fstream>
#include "AbstractLogger.h"

class FileLogger: public AbstractLogger {
protected:
public:
	FileLogger(LogLevel logLevel/*, std::ofstream& ofs*/);

	~FileLogger() override {
		fout.close();
	};

protected:
	std::ofstream fout;
	void _log() override;
};


#endif //FILELOGGER_H
