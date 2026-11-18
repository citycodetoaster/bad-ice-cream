#ifndef MOVABLEOBJECT_HPP
#define MOVABLEOBJECT_HPP

#include <memory>
#include <string>
#include <vector>

#include "Entity/GridObject.hpp"

// 會在格子間移動的物件（角色、水果的共同基底）。
// 移動流程只寫在這裡；子類別只需要回答三件事：
//   1. TowardHasThings：這格能不能走
//   2. OccupancyLayer / OccupancyMark：自己在地圖哪一層、用什麼內容佔位
//   3. SlideSpeed / OnArrive：滑動速度與抵達後的額外動作
class MovableObject : public GridObject {
public:
    using GridObject::GridObject;

    [[nodiscard]] int GetNextI() const { return NextI; }
    [[nodiscard]] int GetNextJ() const { return NextJ; }
    [[nodiscard]] glm::vec2 GetNextIJ() const { return {NextI, NextJ}; }
    [[nodiscard]] int GetNextIndex() const { return GetIndex(NextI, NextJ); }

    void SetPosition(int newI, int newJ) override;

    [[nodiscard]] Model::Direction GetDirection() const { return currentDirection; }
    void SetDirection(Model::Direction direction) { currentDirection = direction; }

    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
    void MoveDirection(); // 往目前方向走一格

    [[nodiscard]] bool TowardHasThings(Model::Direction NewDirection) const;
    virtual bool TowardHasThings(int NewI, int NewJ) const = 0;

    [[nodiscard]] bool IsMoving() const;
    void UpdatePosition(); // 滑動而非等速移動

    [[nodiscard]] bool IfCollides(const std::shared_ptr<MovableObject>& other, glm::vec2 Position) const;

    [[nodiscard]] bool InGame() const { return inGame; }
    void SetInGame(bool a)
    {
        inGame = a;
        if (!a) {
            SetVisible(false);
        }
    }

protected:
    // 依 Model::Move 的規則漫遊：走到頭就隨機換方向。
    void Wander(Model::Move moveModel);

    virtual Layer OccupancyLayer() const = 0; // 自己在哪一層佔位
    virtual Cell OccupancyMark() const = 0;   // 佔位時寫入的內容
    virtual float SlideSpeed() const { return 0.2f; }
    virtual void OnArrive() {}

    int NextI = 0;
    int NextJ = 0;

private:
    void MoveTo(int targetI, int targetJ, Model::Direction direction);

    Model::Direction currentDirection = Model::Direction::None;
    bool inGame = false;
};

#endif //MOVABLEOBJECT_HPP
