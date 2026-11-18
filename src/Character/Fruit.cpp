#include "Character/Fruit.hpp"

Fruit::Fruit(const std::string& ImagePath) : MovableObject(ImagePath) {}

void Fruit::MoveTowards()
{
    Wander(ModelMove);
}

bool Fruit::TowardHasThings(int const NewI, int const NewJ) const
{
    return Map[NewI][NewJ] == '#' || Map[NewI][NewJ] == 'I' || Map3[NewI][NewJ] == 'F';
}
