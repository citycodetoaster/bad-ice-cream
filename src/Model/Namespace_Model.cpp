//
// Created by User on 2025/05/16.
//

#include "Model/Namespace_Model.hpp"
#include "Util/Logger.hpp"
#include <random>



std::string Model::DirToStr(Model::Direction dir)
{
    switch (dir)
    {
    case Model::Direction::Up:    return "Up";
    case Model::Direction::Down:  return "Down";
    case Model::Direction::Left:  return "Left";
    case Model::Direction::Right: return "Right";
    case Model::Direction::None:  return "None";
    default:                      return "Unknown";
    }
}

int Model::DirToNum(Model::Direction dir)
{
    switch (dir)
    {
        case Model::Direction::Up:    return 0;
        case Model::Direction::Down:  return 1;
        case Model::Direction::Left:  return 2;
        case Model::Direction::Right: return 3;
        default:                      LOG_DEBUG(DirToStr(dir));
    }
}

glm::vec2 Model::DirToPos(Model::Direction dir)
{
    switch (dir)
    {
        case Model::Direction::Up:    return glm::vec2(0, -1);
        case Model::Direction::Down:  return glm::vec2(0, 1);
        case Model::Direction::Left:  return glm::vec2(-1, 0);
        case Model::Direction::Right: return glm::vec2(1, 0);
        default:                      LOG_DEBUG(DirToStr(dir));
    }
}


Model::Direction Model::RandomDirection(Model::Move const moveModel)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(0, 3);

    int const r = dist(gen);
    switch (moveModel)
    {
    case Model::Move::Row_Move:
        return r < 2 ? Model::Direction::Right : Model::Direction::Left;
    case Model::Move::Column_Move:
        return r < 2 ? Model::Direction::Up : Model::Direction::Down;
    case Model::Move::Around_Move:
        switch (r)
        {
        case 0: return Model::Direction::Up;
        case 1: return Model::Direction::Down;
        case 2: return Model::Direction::Left;
        default: return Model::Direction::Right;
        }
    case Model::Move::Dont_Move:
        break;
    }
    return Model::Direction::None;
}
