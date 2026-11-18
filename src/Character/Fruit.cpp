#include "Character/Fruit.hpp"

Fruit::Fruit(const std::string& ImagePath) : MovableObject(ImagePath) {}

void Fruit::MoveTowards()
{
    Wander(ModelMove);
}

bool Fruit::TowardHasThings(int const NewI, int const NewJ) const
{
    return GameMap::Instance().Is(Layer::Main, NewI, NewJ, Cell::Wall) || GameMap::Instance().Is(Layer::Main, NewI, NewJ, Cell::Ice) || GameMap::Instance().Is(Layer::Fruit, NewI, NewJ, Cell::Fruit);
}
