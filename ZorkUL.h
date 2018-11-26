#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "Character.h"
#include <iostream>
#include <string>
#include <QApplication>
#include <Character.h>


using namespace std;

class ZorkUL {
private:
	Parser parser;
	Room *currentRoom;
	void createRooms();
	bool processCommand(Command command);




public:
    ZorkUL();
    std::vector<Room*> Rooms; //Vector of Room pointers
    string printHelp();
    void play();
    string printWelcome();
    string teleport();
    bool GetMagicBoxBool();
    string GetLongDescription();
    string goRoom(Command command);
    string go(string direction);
    Character player;
    void UnlockRoom();
    string PrintMap();
};

#endif /*ZORKUL_H_*/
