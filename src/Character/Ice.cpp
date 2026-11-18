//
// Created by User on 2025/03/14.
//

#include "Character/Ice.hpp"

Ice::Ice(const std::string& ImagePath): GridObject(ImagePath)
{

}

bool Ice::isCreate() const
{
    return GetVisibility();
}

bool Ice::HasThings(int const NewI, int const NewJ)
{
    if (Map[NewI][NewJ] == '#'||Map[NewI][NewJ] == 'E'||Map2[NewI][NewJ] == 'A')
    {
        return true;
    }
    return false;

}