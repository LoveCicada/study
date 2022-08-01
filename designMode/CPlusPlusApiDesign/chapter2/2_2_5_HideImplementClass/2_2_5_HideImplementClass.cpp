
/**
 * @file 2_2_5_HideImplementClass.cpp
 * @author cicada (you@domain.com)
 * @brief 隐藏实现类
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

class FireWorks
{
public:
    FireWorks(){}
    void SetOrigin(double x, double y){}
    void SetColor(float x, float y){}
    void SetGravity(float g){}
    void SetSpeed(float speed){}

    void Start(){}
    void Stop(){}
    void NextFrame(float dt){}

private:
    /**
     * @brief api caller will not need to call this internal class.
     * 
     */
    class FireParticle
    {
    public:
        double mX, mY;
        double mVelocityX, mVelocityY;
        double mAccelerationX, mAccelerationY;
        double mLifeTime;
    };
    
    double mOriginX, mOriginY;
    float mRed, mGreen, mBlue;
    float mGravity;
    float mSpeed;
    bool mIsActive;
    std::vector<FireParticle*> mParticles;
};

int main(int argc, char *argv[])
{

    return 0;
}