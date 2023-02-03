cmake_minimum_required(VERSION 3.23)
project(oop)

set(CMAKE_CXX_STANDARD 23)

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
include_directories(src/Saver/)
include_directories(src/Saver/Exeption)



add_executable(oop
        src/GameLogic/Entities/Player/Player.cpp
        src/GameLogic/Field/Cell.cpp
        src/GameLogic/Field/Field.cpp
        src/GameLogic/Field/Move.cpp
        src/IO/Views/CellView.cpp
        src/IO/Views/FieldView.cpp
        src/IO/FieldWriter.cpp
        src/IO/CommandReader.cpp
        src/Game.cpp
        src/GameLogic/Events/TrapEvent.cpp
        src/GameLogic/Events/AbstractMapEvent.cpp
        src/GameLogic/Events/PassMapEvent.cpp
        src/GameLogic/Events/AbstractPlayerEvent.cpp
        src/GameLogic/Events/KeyEvent.cpp
        src/GameLogic/Events/ExitEvent.cpp
        src/GameLogic/Events/AllKeysEvent.cpp
        src/Obsersers/AbstractObserver.cpp
        src/Obsersers/AbstractObservable.cpp
        src/IO/Loggers/ConsoleLogger.cpp
        src/IO/Loggers/AbstractLogger.cpp
        src/IO/Loggers/FileLogger.cpp
        src/IO/Config/ConfigReader.cpp
        src/IO/Config/FileConfigReader.cpp
        src/Controller.cpp
        src/Saver/Save.cpp
        src/Saver/SaveWriter.cpp
        src/Saver/SaveReader.cpp
        src/Saver/Exeption/My_Exeption.h
        )
