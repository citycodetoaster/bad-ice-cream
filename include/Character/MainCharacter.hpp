#ifndef MAINCHARACTER_HPP
#define MAINCHARACTER_HPP

#include <vector>
#include <string>

#include "Character/Character.hpp"
#include "Util/Input.hpp"

class MainCharacter : public Character
{
public:
    explicit MainCharacter(const std::string& ImagePath);

    void UpdateMovement(std::vector<Util::Keycode> keyOrder);

    using MovableObject::TowardHasThings;
    bool TowardHasThings(int NewI, int NewJ) const override;

    virtual bool IsItIce(int NewI, int NewJ);
private:

};

















#endif //MAINCHARACTER_HPP
