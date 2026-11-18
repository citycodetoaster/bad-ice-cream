#ifndef ICE_HPP
#define ICE_HPP

#include <string>

#include "Entity/GridObject.hpp"

// 冰塊：固定在格子上的物件，不會移動。
class Ice : public GridObject {
public:
    explicit Ice(const std::string& ImagePath);

    bool isCreate() const;

    static bool HasThings(int NewI, int NewJ);
};

#endif //ICE_HPP
