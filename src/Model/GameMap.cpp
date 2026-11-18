#include "Model/GameMap.hpp"

GameMap& GameMap::Instance()
{
    static GameMap instance;
    return instance;
}

void GameMap::Reset()
{
    Reset(Layer::Main);
    Reset(Layer::Air);
    Reset(Layer::Fruit);
}

void GameMap::Reset(Layer const layer)
{
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            bool const border = i == 0 || j == 0 || i == Size - 1 || j == Size - 1;
            Set(layer, i, j, border ? Cell::Wall : Cell::Empty);
        }
    }
}
