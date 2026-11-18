//
// Created by User on 2025/03/14.
//
#include "Character/Enemies.hpp"

#include "Character/MainCharacter.hpp"
#include "spdlog/spdlog.h"
#include "Util/Logger.hpp"
Enemies::Enemies(const std::string& ImagePath,Model::Move ModelMove,Model::Fired Fired): Character(ImagePath),ModelMove(ModelMove),Fired(Fired)
{

}
void Enemies::MoveTowards(){
    if (!IsMoving())
    {
        i = NextI;
        j = NextJ;
        if (Firing)                                     //生火中
        {
            return;
        }
    }
    Wander(ModelMove);
}

bool Enemies::TowardHasThings(int const NewI, int const NewJ) const
{
    char const c = Map[NewI][NewJ];
    return c == '#' || c == 'I' || c == 'E';
}

bool Enemies::fired()
{
    if (Fired==Model::Fired::None||IsMoving())
    {
        return false;
    }
    if (Firing)
    {
        if (std::chrono::steady_clock::now()-lastTime < cooldownTime)
        {
            Firing = true;
            return true;
        }
        ChangeImage(2);
        Firing = false;
        return false;
    }

    if (TowardHasThings(GetDirection()))
    {
        if (TowardIs(GetDirection())!='I')
        {
            return false;
        }
        static std::random_device rd;   // 產生隨機種子
        static std::mt19937 gen(rd());  // 使用 Mersenne Twister 隨機數引擎
        static std::uniform_int_distribution<int> dist(0, 39);  // 產生 0~100 的整數
        if (dist(gen) == 0)
        {
            ResetTimer();
            ChangeImage(1);
            Firing = true;
            return true;
        }

    }
    return false;

}
char Enemies::TowardIs(Model::Direction NewDirection) const
{
    switch (NewDirection)
    {
    case Model::Direction::Up:
        return TowardIs(i, j-1);
    case Model::Direction::Down:
        return TowardIs(i, j+1);
    case Model::Direction::Left:
        return TowardIs(i-1, j);
    case Model::Direction::Right:
        return TowardIs(i+1, j);
    default:
        return '.';
    }
}
void Enemies::ChangeImage(int a)//圖片變更功能，生火的變化圖
{

    std::string Image1="1.png";
    std::string Image2="2.png";
    std::string Image3=GetImagePath();
    size_t pos1 = Image3.rfind(Image1);
    size_t pos2 = Image3.rfind(Image2);
    if (a==1&&pos1!=std::string::npos) {
        Image3.replace(pos1, Image1.length(), Image2);
    }
    else if (a==2&&pos2!=std::string::npos) {
        Image3.replace(pos2, Image2.length(), Image1);
    }
    SetImage(Image3);
}

