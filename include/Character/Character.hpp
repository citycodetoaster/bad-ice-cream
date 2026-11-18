#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "Entity/MovableObject.hpp"

// 主角與敵人（電器）的共同基底。在 Map 上以 Cell::Enemy 佔位。
class Character : public MovableObject {
public:
    explicit Character(const std::string& ImagePath);

    using MovableObject::TowardHasThings;
    bool TowardHasThings(int NewI, int NewJ) const override;

protected:
    Layer OccupancyLayer() const override { return Layer::Main; }
    Cell OccupancyMark() const override { return Cell::Enemy; }
    void OnArrive() override { MainCharacterPosition = {i, j}; }
};

#endif //CHARACTER_HPP
