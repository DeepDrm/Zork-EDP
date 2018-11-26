#ifndef CHARACTER_H_
#define CHARACTER_H_
#include <string>
using namespace std;
#include <vector>
using std::vector;
#include "ItemKey.h"

class Character {

private:
    ItemKey MasterKey;
    bool BoolKey = 0;
    ItemKey Key1;
    ItemKey Key2;

public:	
    void SetKey1();
    void SetKey2();
    ItemKey GetKey1();
    ItemKey GetKey2();
    void SetMasterKey();
    bool HaveMasterKey();
};

#endif /*CHARACTER_H_*/
