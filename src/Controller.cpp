#include "Controller.h"


GameStatus Controller::start() {
	ConfigReader * cr = new FileConfigReader();
	Move* playerMoves = cr->getMovesFromConfig();
	player.setMoves(playerMoves);
	player.setNumberOfMoves(cr->getNumberOfMoves());

	Logger * cl;
	Logger * fl;


	Observer *gameObserver = new AbstractObserver();
/*
	LogLevel gameLogLevel = commandReader.getLogLevel();
	if (commandReader.isLogNeeded("console")) {
		cl = new ConsoleLogger(gameLogLevel);
		gameObserver->addLogger(cl);
	}
/*
	if (commandReader.isLogNeeded("file")) {
		fl = new FileLogger(gameLogLevel);
		gameObserver->addLogger(fl);
	}
*/
	player.addObserver(gameObserver);


	if (commandReader.readSaveOrLoadCommand("load")) {
		LoadGame(commandReader.readFileName());
	}
	if (!field) {
		field = generateField(gameObserver);
	}


	for (int i = 0; i < field->getHeight(); ++i) {
		for (int j = 0; j < field->getWidth(); ++j) {
			field->getCell(i,j).addObserver(gameObserver);
			if (field->getCell(i,j).getEvent() != nullptr) {
				field->getCell(i,j).getEvent()->addObserver(gameObserver);
			}
		}
	}

	while (gameStatus == InProgress) {
		std::string msg = "Game state is " + GameStatusString();
		Message m(msg, LogLevel::GameState);
		gameObserver->handleEvent(m);
		fieldWriter.PrintField(*field);
		Move &move = commandReader.readMove(player);
		field->makeMove(move, player, true);

		if (player.getHealth() <= 0) {
			gameStatus = Lose;
		}
		if (commandReader.readSaveOrLoadCommand("load")) {
			LoadGame(commandReader.readFileName());
			for (int i = 0; i < field->getHeight(); ++i) {
				for (int j = 0; j < field->getWidth(); ++j) {
					field->getCell(i,j).addObserver(gameObserver);
					if (field->getCell(i,j).getEvent() != nullptr) {
						field->getCell(i,j).getEvent()->addObserver(gameObserver);
					}
				}
			}
			continue;
		}

		if (commandReader.readSaveOrLoadCommand("save")) {
			SaveGame(commandReader.readFileName());
		}

	}

	std::string msg = "Game state is " + GameStatusString();
	Message m(msg, LogLevel::GameState);
	gameObserver->handleEvent(m);
	return gameStatus;
}

std::string Controller::GameStatusString() {
	std::string gss[] = {"Win", "Lose", "InProgress"};
	return gss[(int)gameStatus];
}

Field* Controller::generateField(Observer *obs) {
	int level = commandReader.readLevel(2);
	Field *foo_field;
	if (level == 1) {
		FieldGenerator<ExitEventRule<2>, KeyEventRule<1,1>, AllKeysEventRule<1,0>, PassMapEventRule<0,1>, TrapEventRule<2,2,6>, DiagonalWallRule<1,2,1>> fg;
		foo_field = fg.generate(4,4,player, gameStatus);
	} else {
		FieldGenerator<ExitEventRule<0>, KeyEventRule<1,1>,DiagonalWallRule<1,2,0>, PassMapEventRule<1,0>, TrapEventRule<2,2,2>, TrapEventRule<0,1,4>> fg;
		foo_field = fg.generate(5,5,player, gameStatus);
	}
	return foo_field;
}

void Controller::SaveGame(std::string fileName) {
	try {
		SaveWriter sw(fileName);
		Save s(player,field);
		sw.write(s);
	} catch (FileException e) {
		e.display();
	}
}

void Controller::LoadGame(std::string fileName) {
	try {
		SaveReader sw(fileName);
		field = sw.read(field, player, gameStatus);
	} catch (FileException e) {
		e.display();
	} catch (UnrealSaveException e) {
		e.display();
	}
}

Controller::Controller() {
}

Controller::~Controller() {
    delete field;
}
