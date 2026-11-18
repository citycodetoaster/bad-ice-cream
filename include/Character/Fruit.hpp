#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <string>

#include "Entity/MovableObject.hpp"

// 水果：被冰淇淋吃掉的目標，部分水果會移動。與 Character 無繼承關係，在水果層以 Cell::Fruit 佔位。
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
    Layer OccupancyLayer() const override { return Layer::Fruit; }
    Cell OccupancyMark() const override { return Cell::Fruit; }
    float SlideSpeed() const override { return 0.1f; }

private:
    Model::Move ModelMove = Model::Move::Dont_Move;
};

#endif //FRUIT_HPP
