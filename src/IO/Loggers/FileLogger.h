#ifndef FILELOGGER_H
#define FILELOGGER_H
#include <fstream>
#include "AbstractLogger.h"

class FileLogger: public AbstractLogger {
protected:
public:
	FileLogger(LogLevel logLevel);

	~FileLogger() override {
		fout.flush();
		fout.close();
	};

protected:
	std::ofstream fout;
	void _log() override;
};


#endif //FILELOGGER_H
