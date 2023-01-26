cmake_minimum_required(VERSION 3.23)
project(oop)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(src/GameLogic)
include_directories(src/GameLogic/Entities)
include_directories(src/GameLogic/Entities/Player)
include_directories(src/GameLogic/Events)
include_directories(src/GameLogic/Field)
include_directories(src/GameLogic/Generator)
include_directories(src/GameLogic/Generator/Rules)
include_directories(src/Obsersers)
include_directories(src/IO)
include_directories(src/IO/Views)
include_directories(src/IO/Config/)
include_directories(src/IO/Loggers/)




add_executable(oop
        # src/GameLogic/Generator/FieldGenerator.h
        # src/GameLogic/Generator/Rules/ExitEventRule.h
        # src/GameLogic/Generator/Rules/KeyEventRule.h
        # src/GameLogic/Generator/Rules/AllKeysEventRule.h
        src/GameLogic/Entities/Player/Player.cpp
        # src/GameLogic/Entities/Player/Player.h
        # src/GameLogic/Events/Event.h
        src/GameLogic/Field/Cell.cpp
        # src/GameLogic/Field/Cell.h
        src/GameLogic/Field/Field.cpp
        # src/GameLogic/Field/Field.h
        src/GameLogic/Field/Move.cpp
        # src/GameLogic/Field/Move.h
        src/IO/Views/CellView.cpp
        # src/IO/Views/CellView.h
        src/IO/Views/FieldView.cpp
        # src/IO/Views/FieldView.h
        src/IO/FieldWriter.cpp
        # src/IO/FieldWriter.h
        src/IO/CommandReader.cpp
        # src/IO/CommandReader.h
        # src/GameStatus.h
        src/Game.cpp
        src/GameLogic/Events/TrapEvent.cpp
        # src/GameLogic/Events/TrapEvent.h
        src/GameLogic/Events/AbstractMapEvent.cpp
        # src/GameLogic/Events/AbstractMapEvent.h
        src/GameLogic/Events/PassMapEvent.cpp
        # src/GameLogic/Events/PassMapEvent.h
        src/GameLogic/Events/AbstractPlayerEvent.cpp
        # src/GameLogic/Events/AbstractPlayerEvent.h
        src/GameLogic/Events/KeyEvent.cpp
        # src/GameLogic/Events/KeyEvent.h
        src/GameLogic/Events/ExitEvent.cpp
        # src/GameLogic/Events/ExitEvent.h
        src/GameLogic/Events/AllKeysEvent.cpp
        # src/GameLogic/Events/AllKeysEvent.h
        # src/Obsersers/Observer.h
        # src/Obsersers/Observable.h
        src/Obsersers/AbstractObserver.cpp
        # src/Obsersers/AbstractObserver.h
        # src/IO/Loggers/Logger.h
        src/Obsersers/AbstractObservable.cpp
        # src/Obsersers/AbstractObservable.h
        src/IO/Loggers/ConsoleLogger.cpp
        # src/IO/Loggers/ConsoleLogger.h
        src/IO/Loggers/AbstractLogger.cpp
        # src/IO/Loggers/AbstractLogger.h
        src/IO/Loggers/FileLogger.cpp
        # src/IO/Loggers/FileLogger.h

        # src/IO/Config/ConfigReader.h
        src/IO/Config/ConfigReader.cpp
        # src/IO/Config/FileConfigReader.h
        src/IO/Config/FileConfigReader.cpp

        src/Controller.cpp
        # src/Controller.h
        )
