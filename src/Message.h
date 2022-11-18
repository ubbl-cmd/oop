#ifndef OOP_MESSAGE_H
#define OOP_MESSAGE_H

#include "string"

enum LogLevel {
    NotLoggable, Critical, GameState, GameLogic
};
class Message {
public:
	std::string to_string() {
		return convertLogLevel() + messageString;
	}

	LogLevel getLogLevel() {
		return logLevel;
	}
	Message(std::string &messageString, LogLevel logLevel):messageString(messageString), logLevel(logLevel) {}
	~Message() = default;

private:
	std::string convertLogLevel() {
		switch (logLevel) {
			case GameLogic:
				return "[GameLogic] ";
			case GameState:
				return "[GameState] ";
			case Critical:
				return "[Critical] ";
		}
		return "[ZVO] ";
	}
	std::string &messageString;
	LogLevel logLevel{LogLevel::GameLogic};
};


#endif //OOP_MESSAGE_H
