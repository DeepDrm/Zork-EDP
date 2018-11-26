#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <vector>
using namespace std;
using std::vector;

class Room {

private:
	string description;
	map<string, Room*> exits;
	string exitString();
    bool Blocked = 0; //if == 1 room is blocked, need to check the master key

public:
	Room(string description);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
    bool BoolRoomHaveMBox = 0; //if == 1 room has a box
    bool IsRoomLocked(); //if == 1 room is blocked, need to check the master key
    void LockRoom();
    void UnlockRoom();
};

#endif
