cmake_minimum_required(VERSION 3.23)
project(oop)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/GameLogic)
include_directories(src/GameLogic/Events)
include_directories(src/IO)
include_directories(src/IO/Views)

add_executable(oop
        src/GameLogic/Entities/Player/Player.cpp
        src/GameLogic/Entities/Player/Player.h
        src/GameLogic/Events/Event.h
        src/GameLogic/Field/Cell.cpp
        src/GameLogic/Field/Cell.h
        src/GameLogic/Field/Field.cpp
        src/GameLogic/Field/Field.h
        src/GameLogic/Field/Move.cpp
        src/GameLogic/Field/Move.h
        src/IO/Views/CellView.cpp
        src/IO/Views/CellView.h
        src/IO/Views/FieldView.cpp
        src/IO/Views/FieldView.h
        src/IO/FieldWriter.cpp
        src/IO/FieldWriter.h
        src/IO/CommandReader.cpp
        src/IO/CommandReader.h
        src/Controller.cpp
        src/Controller.h
        src/Game.cpp src/GameLogic/Events/TrapEvent.cpp src/GameLogic/Events/TrapEvent.h src/GameLogic/Events/AbstractMapEvent.cpp src/GameLogic/Events/AbstractMapEvent.h src/GameLogic/Events/PassMapEvent.cpp src/GameLogic/Events/PassMapEvent.h src/GameLogic/Events/AbstractPlayerEvent.cpp src/GameLogic/Events/AbstractPlayerEvent.h src/GameLogic/Events/KeyEvent.cpp src/GameLogic/Events/KeyEvent.h src/GameLogic/Events/ExitEvent.cpp src/GameLogic/Events/ExitEvent.h src/GameLogic/GameStatus.h src/GameLogic/Events/AllKeysEvent.cpp src/GameLogic/Events/AllKeysEvent.h)
