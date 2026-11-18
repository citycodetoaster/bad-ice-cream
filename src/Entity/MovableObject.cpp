#include "Entity/MovableObject.hpp"

void MovableObject::SetPosition(int const newI, int const newJ)
{
    GridObject::SetPosition(newI, newJ);
    NextI = newI;
    NextJ = newJ;
}

void MovableObject::MoveTo(int const targetI, int const targetJ, Model::Direction const direction)
{
    SetDirection(direction);
    auto& map = GameMap::Instance();
    Layer const layer = OccupancyLayer();
    if (!TowardHasThings(targetI, targetJ)) {
        NextI = targetI;
        NextJ = targetJ;
        map.Set(layer, NextI, NextJ, OccupancyMark());
        map.Clear(layer, i, j);
    } else {
        NextI = i;
        NextJ = j;
        map.Set(layer, NextI, NextJ, OccupancyMark());
    }
}

void MovableObject::MoveLeft()  { MoveTo(i - 1, j, Model::Direction::Left); }
void MovableObject::MoveRight() { MoveTo(i + 1, j, Model::Direction::Right); }
void MovableObject::MoveUp()    { MoveTo(i, j - 1, Model::Direction::Up); }
void MovableObject::MoveDown()  { MoveTo(i, j + 1, Model::Direction::Down); }

void MovableObject::MoveDirection()
{
    switch (currentDirection) {
    case Model::Direction::Up:    MoveUp();    break;
    case Model::Direction::Down:  MoveDown();  break;
    case Model::Direction::Left:  MoveLeft();  break;
    case Model::Direction::Right: MoveRight(); break;
    case Model::Direction::None:  break;
    }
}

bool MovableObject::TowardHasThings(Model::Direction const NewDirection) const
{
    switch (NewDirection) {
    case Model::Direction::Up:    return TowardHasThings(i, j - 1);
    case Model::Direction::Down:  return TowardHasThings(i, j + 1);
    case Model::Direction::Left:  return TowardHasThings(i - 1, j);
    case Model::Direction::Right: return TowardHasThings(i + 1, j);
    default:                      return false;
    }
}

bool MovableObject::IsMoving() const
{
    return glm::distance(m_Transform.translation, CellToPosition(NextI, NextJ)) > .1f;
}

void MovableObject::UpdatePosition()
{
    glm::vec2 const target = CellToPosition(NextI, NextJ);

    if (glm::distance(m_Transform.translation, target) > .1f) {
        m_Transform.translation = glm::mix(m_Transform.translation, target, SlideSpeed());
    } else {
        i = NextI;
        j = NextJ;
        OnArrive();
    }
}

bool MovableObject::IfCollides(const std::shared_ptr<MovableObject>& other, glm::vec2 const Position) const
{
    return std::abs(other->GetPosition().x - Position.x) < cellSize - 20
        && std::abs(other->GetPosition().y - Position.y) < cellSize - 20;
}

void MovableObject::Wander(Model::Move const moveModel)
{
    if (IsMoving()) {
        UpdatePosition();
        return;
    }
    i = NextI;
    j = NextJ;

    if (TowardHasThings(currentDirection)) {
        if (moveModel == Model::Move::Row_Move || moveModel == Model::Move::Column_Move
            || moveModel == Model::Move::Around_Move) {
            SetDirection(Model::RandomDirection(moveModel));
            return;
        }
    }
    MoveDirection();
}
