#include "Character/Character.hpp"

Character::Character(const std::string& ImagePath) : MovableObject(ImagePath) {}

bool Character::TowardHasThings(int const NewI, int const NewJ) const
{
    // '@' 似乎用不到，但為了避免刪掉後出錯而保留
    char const c = Map[NewI][NewJ];
    return c == '@' || c == '#' || c == '!';
}
