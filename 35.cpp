#include <iostream>
#include <string>
#include <functional>
class GameCharacter;
int defaultHealthCalc(const GameCharacter &gc)
{
    return 10;
}
short calcHealth(const GameCharacter &) //计算健康函数，注意返回类型为non-int
{
    return 20;
}

struct HealthCalculator //为计算健康而设计的函数对象
{
    int operator()(const GameCharacter &) const
    {
        return 30;
    }
};
class GameLevel
{
public:
    float health(const GameCharacter &) const //成员函数，用来计算健康，注意其返回为non-int类型
    {
        return 40;
    }
};

class GameCharacter
{
public:
    typedef std::function<int(const GameCharacter &)> HealthCalcFunc;
    explicit GameCharacter(HealthCalcFunc hcf = defaultHealthCalc) : healthFunc(hcf)
    {
    }
    int healthValue() const
    {
        //...
        int retVal = healthFunc(*this);
        std::cout << retVal << "\n";
        return retVal;
    }

private:
    HealthCalcFunc healthFunc;
};

class EvilBadGuy : public GameCharacter //一个对象
{
public:
    explicit EvilBadGuy(HealthCalcFunc hcf = defaultHealthCalc) : GameCharacter(hcf)
    {
    }
};
class EyeCandyCharacter : public GameCharacter //另外一个对象
{
public:
    explicit EyeCandyCharacter(HealthCalcFunc hcf = defaultHealthCalc) : GameCharacter(hcf)
    {
    }
};

int main()
{
    GameCharacter CommonGay{};
    CommonGay.healthValue();

    EvilBadGuy ebg1(calcHealth); //人物1 使用某一个函数计算健康指数
    ebg1.healthValue();

    EyeCandyCharacter ecc1{HealthCalculator()}; //人物2 使用某个函数对象计算健康指数
    ecc1.healthValue();

    GameLevel currentLevel;

    EvilBadGuy ebg2(std::bind(&GameLevel::health, &currentLevel, std::placeholders::_1));
    ebg2.healthValue();

    return 0;
}
