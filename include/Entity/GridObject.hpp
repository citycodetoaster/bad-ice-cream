#ifndef GRIDOBJECT_HPP
#define GRIDOBJECT_HPP

#include <string>

#include "Util/GameObject.hpp"
#include "Model/Namespace_Model.hpp"

// 放在 10x10 格子地圖上的物件：負責圖片與格子座標 (i, j)，不含任何移動行為。
class GridObject : public Util::GameObject {
public:
    explicit GridObject(const std::string& ImagePath);

    GridObject(const GridObject&) = delete;
    GridObject(GridObject&&) = delete;
    GridObject& operator=(const GridObject&) = delete;
    GridObject& operator=(GridObject&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }
    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }
    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    [[nodiscard]] int GetI() const { return i; }
    [[nodiscard]] int GetJ() const { return j; }
    [[nodiscard]] glm::vec2 GetIJ() const { return {i, j}; }
    [[nodiscard]] int GetIndex() const { return GetIndex(i, j); }
    static int GetIndex(int const I, int const J) { return I - 1 + (J - 1) * 10; }

    void SetImage(const std::string& ImagePath);
    virtual void SetPosition(int newI, int newJ);

protected:
    static glm::vec2 CellToPosition(int const I, int const J)
    {
        return glm::vec2(-330 + cellSize * I, 330 - cellSize * J);
    }

    int i = 0;
    int j = 0;

private:
    std::string m_ImagePath;
};

#endif //GRIDOBJECT_HPP
