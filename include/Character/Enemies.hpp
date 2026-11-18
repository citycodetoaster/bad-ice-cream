#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include <vector>
#include <string>
#include <random>
#include <string>
#include <chrono>
#include "Character/Character.hpp"

class Enemies : public Character
{
public:
    explicit Enemies(const std::string& ImagePath, Model::Move ModelMove,Model::Fired Fired=Model::Fired::None);

    void MoveTowards();
    Model::Direction GetRandomDirection() const { return Model::RandomDirection(ModelMove); }
    using MovableObject::TowardHasThings;
    bool TowardHasThings(int NewI, int NewJ) const override;

    void SetModel(Model::Move NewModel){ModelMove=NewModel;}
    Model::Move GetModel() const {return ModelMove;}

    //廢案
    // Model::Direction AutoMove(glm::vec2 MainPosition);
    //
    // bool AutoMoveTest(Model::Direction Now, Model::Direction New, glm::vec2 NowPos);

    bool fired();
    Model::Fired GetFireModel(){return Fired;}

    void ResetTimer()
    {
        lastTime=std::chrono::steady_clock::now();
    }

    Cell TowardIs(int I,int J) const
    {
        return GameMap::Instance().Get(Layer::Main, I, J);
    }
    Cell TowardIs(Model::Direction NewDirection) const;

    void ChangeImage(int a);
protected:
    float SlideSpeed() const override { return 0.1f; }
    void OnArrive() override {}

private:
    std::chrono::steady_clock::time_point lastTime;  // 記錄上次創建冰的時間
    const std::chrono::milliseconds cooldownTime{2000};

    Model::Move ModelMove;
    Model::Fired Fired;
    bool Firing=false;
};




#endif //ENEMIES_HPP
