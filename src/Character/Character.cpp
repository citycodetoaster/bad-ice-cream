#include "Character/Character.hpp"

Character::Character(const std::string& ImagePath) : MovableObject(ImagePath) {}

bool Character::TowardHasThings(int const NewI, int const NewJ) const
{
    Cell const c = GameMap::Instance().Get(Layer::Main, NewI, NewJ);
    return c == Cell::Wall || c == Cell::Player;
}
