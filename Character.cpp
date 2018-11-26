#include "Character.h"

void Character::SetKey1()
{
    Key1.SetKey();
}

void Character::SetKey2()
{
    Key2.SetKey();
}

void Character::SetMasterKey()
{
    MasterKey.SetKey();
}

ItemKey Character::GetKey1()
{
    return Key1;
}

ItemKey Character::GetKey2()
{
    return Key2;
}

bool Character::HaveMasterKey()
{
    if(MasterKey.IsKeyActive() == 2)
    return 1;
    else
        return 0;
}

