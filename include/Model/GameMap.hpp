#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP

#include <array>

// 格子上的內容。數值刻意與舊版地圖字元相同，除錯時印出來仍然看得懂。
enum class Cell : char {
    Empty   = '.',
    Wall    = '#',
    Ice     = 'I',
    Enemy   = 'E',
    Player  = '!',
    AirWall = 'A', // 擋主角與冰，不擋敵人與水果
    Fruit   = 'F',
};

// 地圖分層：不同種類的物件會重疊，所以各放一層。
enum class Layer {
    Main,  // 牆、冰、敵人、主角
    Air,   // 空氣牆
    Fruit, // 水果（可與主角、敵人重疊）
};

// 12x12（含外圈牆）的格子地圖，座標為 (i, j)。
// 所有關於「哪一格有什麼」的讀寫都經過這裡。
class GameMap {
public:
    static constexpr int Size = 12;

    static GameMap& Instance();

    void Reset();            // 全部分層回到「只有外圈牆」的空地圖
    void Reset(Layer layer); // 只重設單一分層

    [[nodiscard]] Cell Get(Layer layer, int i, int j) const { return cells[Index(layer)][i][j]; }
    [[nodiscard]] bool Is(Layer layer, int i, int j, Cell cell) const { return Get(layer, i, j) == cell; }
    void Set(Layer layer, int i, int j, Cell cell) { cells[Index(layer)][i][j] = cell; }
    void Clear(Layer layer, int i, int j) { Set(layer, i, j, Cell::Empty); }

private:
    GameMap() { Reset(); }

    static constexpr int LayerCount = 3;
    static int Index(Layer layer) { return static_cast<int>(layer); }

    std::array<std::array<std::array<Cell, Size>, Size>, LayerCount> cells{};
};

#endif //GAMEMAP_HPP
