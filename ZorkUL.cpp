#include <iostream>
#include <vector>
#include <QApplication>
#include <cstdlib>
#include "mainwindow.h"


using namespace std;
#include "ZorkUL.h"


ZorkUL::ZorkUL(){

	createRooms();
}

void ZorkUL::createRooms()  {
Room *a, *b, *c, *d, *e, *f, *g, *h, *i;

    a = new Room("a");
    b = new Room("b");
    c = new Room("c");
    d = new Room("d");
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");

    Rooms.push_back(a); //Push a in to the array
    Rooms.push_back(b);
    Rooms.push_back(c);
    Rooms.push_back(d);
    Rooms.push_back(e);
    Rooms.push_back(f);
    Rooms.push_back(g);
    Rooms.push_back(h);
    Rooms.push_back(i);

//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);

    //Final Room
    i->setExits(NULL, d, NULL, NULL);

    //Block the room, just opens with the master key
    i->LockRoom();


    //Start room
        currentRoom = a;

    //Put a key in the room
    b->BoolRoomHaveMBox = 1;
    g->BoolRoomHaveMBox = 1;
}


void ZorkUL::play() {
	printWelcome();

    //Create character
    Character Chris;
}

 string ZorkUL::printWelcome() {
    return "start\ninfo for help\n"+ currentRoom->longDescription() + "\n";
}

bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

    else if (commandWord.compare("teleport") == 0)
        teleport();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("put") == 0)
    {

    }
      else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}

string ZorkUL::teleport()
{

    int x= (rand() % 9); //Randomize function for choosing the room
    currentRoom = Rooms[x];
    cout << currentRoom->longDescription() << endl;

    if(x == 0)
        return "a";
    else if(x==1)
            return "b";
    else if(x==2)
            return "c";
    else if(x==3)
            return "d";
    else if(x==4)
            return "e";
    else if(x==5)
            return "f";
    else if(x==6)
            return "g";
    else if(x==7)
            return "h";
    else if(x==8)
            return "d";
    else if(x==9)
            return "h";
    else if(x==10)
            return "a";

}

string ZorkUL::GetLongDescription()
{
 return currentRoom->longDescription();
}


bool ZorkUL::GetMagicBoxBool() //Check the room if it has a key
{
    return this->currentRoom->BoolRoomHaveMBox;
}

string ZorkUL::printHelp() {
    return "\nFind two keys to build the MasterKey and escape the castle";
}

string ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        return "0";
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == nullptr){
        cout << endl << "No exit in that direction"<< endl;
        cout << endl << currentRoom->longDescription() << endl;
        return "0";}

    else if(nextRoom->IsRoomLocked() == 0 ){   //Check if room is locked
		currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
        return currentRoom->shortDescription();
        }
        else if(nextRoom->IsRoomLocked() == 1)
        {
            //Room blocked
            cout<<"Room blocked, find the keys!!";
            return "Blocked";
        }
	}


string ZorkUL::go(string direction) {

	Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == nullptr)
        return("No exit in that direction");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}

void ZorkUL::UnlockRoom()
{
    //Unlock final room
    cout<<"Room unlocked :)";
  Rooms[8]->UnlockRoom(); //Room[8] it's our final room
}

string ZorkUL::PrintMap()
{
        return  "\n[h] --- [f] --- [g]\n"
                "           |       \n"
                "           |       \n"
                "[c] --- [a] --- [b]\n"
                "           |       \n"
                "           |       \n"
                "[i] --- [d] --- [e]\n";

}
