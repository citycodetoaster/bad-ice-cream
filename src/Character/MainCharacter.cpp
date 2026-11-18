//
// Created by User on 2025/03/13.
//

#include "Character/MainCharacter.hpp"

MainCharacter::MainCharacter(const std::string& ImagePath)
    : Character(ImagePath)
{
}

void MainCharacter::UpdateMovement(std::vector<Util::Keycode> keyOrder){

    if (IsMoving())
    {
        UpdatePosition();
        return;
    }

    i = NextI;
    j = NextJ;
    if (keyOrder.empty()||keyOrder.front()==Util::Keycode::SPACE) return;  // 沒有按鍵時不移動
    switch (keyOrder.front()) {
    case Util::Keycode::W:
    case Util::Keycode::UP:
        this->MoveUp();GameMap::Instance().Set(Layer::Main, NextI, NextJ, Cell::Player);GameMap::Instance().Set(Layer::Main, i, j, Cell::Empty);
        break;
    case Util::Keycode::S:
    case Util::Keycode::DOWN:
        this->MoveDown();GameMap::Instance().Set(Layer::Main, NextI, NextJ, Cell::Player);GameMap::Instance().Set(Layer::Main, i, j, Cell::Empty);
        break;

    case Util::Keycode::A:
    case Util::Keycode::LEFT:
        this->MoveLeft();GameMap::Instance().Set(Layer::Main, NextI, NextJ, Cell::Player);GameMap::Instance().Set(Layer::Main, i, j, Cell::Empty);
        break;
    case Util::Keycode::D:
    case Util::Keycode::RIGHT:
        this->MoveRight();GameMap::Instance().Set(Layer::Main, NextI, NextJ, Cell::Player);GameMap::Instance().Set(Layer::Main, i, j, Cell::Empty);
        break;
    default:
        return;
    }
}

bool MainCharacter::TowardHasThings(int const NewI, int const NewJ) const
{
    if (GameMap::Instance().Is(Layer::Main, NewI, NewJ, Cell::Ice)||GameMap::Instance().Is(Layer::Main, NewI, NewJ, Cell::Wall)||GameMap::Instance().Is(Layer::Air, NewI, NewJ, Cell::AirWall))
    {
        return true;
    }
    return false;
}

bool MainCharacter::IsitIce(int NewI, int NewJ)
{
    if (GameMap::Instance().Is(Layer::Main, NewI, NewJ, Cell::Ice))
    {
        return true;
    }
    return false;
}