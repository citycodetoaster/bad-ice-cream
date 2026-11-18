#ifndef WALL_HPP
#define WALL_HPP

#include <string>

#include "Map/BackGround.hpp"
#include "Model/Namespace_Model.hpp"

class Wall : public BackGround {
public:
    explicit Wall(const std::string& ImagePath);
    int GetI()
    {
        return i;
    }
    int GetJ(){
        return j;
    }
    void SetPosition(int const newI, int const newJ)
    {
        i=newI;j=newJ;
        m_Transform.translation = glm::vec2(-330+(cellSize*newI),330-(cellSize*newJ));
    }
private:
    int i,j;
    std::string m_ImagePath;
};

#endif //WALL_HPP
