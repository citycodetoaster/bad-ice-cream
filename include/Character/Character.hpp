#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "Entity/MovableObject.hpp"

// 主角與敵人（電器）的共同基底。在 Map 上以 'E' 佔位。
class Character : public MovableObject {
public:
    explicit Character(const std::string& ImagePath);

    using MovableObject::TowardHasThings;
    bool TowardHasThings(int NewI, int NewJ) const override;

protected:
    std::vector<std::string>& OccupancyMap() const override { return Map; }
    char OccupancyMark() const override { return 'E'; }
    void OnArrive() override { MainCharacterPosition = {i, j}; }
};

#endif //CHARACTER_HPP
