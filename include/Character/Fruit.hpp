#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <string>

#include "Entity/MovableObject.hpp"

// 水果：被冰淇淋吃掉的目標，部分水果會移動。與 Character 無繼承關係，在 Map3 上以 'F' 佔位。
class Fruit : public MovableObject
{
public:
    explicit Fruit(const std::string& ImagePath);

    void SetModel(Model::Move NewModel) { ModelMove = NewModel; }
    [[nodiscard]] Model::Move GetModel() const { return ModelMove; }

    void MoveTowards();
    [[nodiscard]] Model::Direction GetRandomDirection() const { return Model::RandomDirection(ModelMove); }

    using MovableObject::TowardHasThings;
    bool TowardHasThings(int NewI, int NewJ) const override;

protected:
    std::vector<std::string>& OccupancyMap() const override { return Map3; }
    char OccupancyMark() const override { return 'F'; }
    float SlideSpeed() const override { return 0.1f; }

private:
    Model::Move ModelMove = Model::Move::Dont_Move;
};

#endif //FRUIT_HPP
