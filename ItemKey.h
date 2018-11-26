#ifndef BOXROOM_H
#define BOXROOM_H

#endif // BOXROOM_H

#include <map>
#include <vector>
#include "item.h"


using namespace std;
using std::vector;

class ItemKey : public Item //Inheritence
{

private:
    string description;
    int a = 0;


public:
   void SetKey() {a = 1;}
   int IsKeyActive();      //Override so this sub-class isn't abstract


   friend inline int operator+(ItemKey KeyA, ItemKey KeyB) //
   {
       return (KeyA.a + KeyB.a);
   }

   virtual ~ItemKey(); //Virtual
};


