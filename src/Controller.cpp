#include "Controller.h"


GameStatus Controller::start() {
	ConfigReader * cr = new FileConfigReader();
	Move* playerMoves = cr->getMovesFromConfig();
	player.setMoves(playerMoves);
	player.setNumberOfMoves(cr->getNumberOfMoves());


	Logger * cl;
	Logger * fl;
	LogLevel gameLogLevel = commandReader.getLogLevel();
	Observer *gameObserver = new AbstractObserver();
	if (commandReader.isLogNeeded("console")) {
		cl = new ConsoleLogger(gameLogLevel);
		gameObserver->addLogger(cl);
	}

	if (commandReader.isLogNeeded("file")) {
		fl = new FileLogger(gameLogLevel);
		gameObserver->addLogger(fl);
	}
	player.addObserver(gameObserver);

	field = generateField(gameObserver);

	// field->getCell(field->getHeight()-1, field->getWidth()-1).setPassable(false);
	// field->getCell(field->getHeight()-1, field->getWidth()-1).setEvent(new ExitEvent(player, gameStatus));
	// field->getCell(1, 1).setEvent(new KeyEvent(player));
	// field->getCell(0, 1).setEvent(new PassMapEvent(field));
	// field->getCell(1, 0).setEvent(new AllKeysEvent(field, player));
	// field->getCell(2, 2).setEvent(new TrapEvent(player, 5));

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
	FieldGenerator<ExitEventRule<2>, KeyEventRule<1,1>, AllKeysEventRule<1,0>, PassMapEventRule<0,1>, TrapEventRule<2,2,6>, DiagonalWallRule<2>> fg;
	Field *foo_field = fg.generate(player, gameStatus);
    // int height = commandReader.readFieldSize("высоту");
    // int width = commandReader.readFieldSize("ширину");
    // Field * foo_field;
    // if (height <= 0 || width <= 0) {
    //     foo_field = new Field();
    // } else {
    //     foo_field = new Field(height, width);
    // }
    // foo_field->addObserver(obs);
    // if (height <= 0 || width <= 0) {
    //     std::string s("Field size < 0");
    //     Message m(s, LogLevel::Critical);
    //     foo_field->notifyObserver(m);
    // }
    return foo_field;
}


Controller::Controller() {
}

Controller::~Controller() {
    delete field;
}
