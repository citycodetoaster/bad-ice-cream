#include "Entity/GridObject.hpp"
#include "Util/Image.hpp"

GridObject::GridObject(const std::string& ImagePath)
{
    SetImage(ImagePath);
}

void GridObject::SetImage(const std::string& ImagePath)
{
    m_ImagePath = ImagePath;
    m_Drawable = std::make_shared<Util::Image>(m_ImagePath);
}

void GridObject::SetPosition(int const newI, int const newJ)
{
    i = newI;
    j = newJ;
    m_Transform.translation = CellToPosition(i, j);
}
