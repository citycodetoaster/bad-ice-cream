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
    if (GameMap::Instance().Is(Layer::Main, NewI, NewJ, Cell::Wall)||GameMap::Instance().Is(Layer::Main, NewI, NewJ, Cell::Enemy)||GameMap::Instance().Is(Layer::Air, NewI, NewJ, Cell::AirWall))
    {
        return true;
    }
    return false;

}