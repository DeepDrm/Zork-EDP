#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {   //Abstract class
private:
	string description;

public:
    virtual ~Item();
    virtual int IsKeyActive() = 0; //With = 0 we are saying it's an Abstract class, we need to override in the sub-classes

};

#endif /*ITEM_H_*/
