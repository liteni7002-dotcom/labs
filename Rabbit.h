#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class Rabbit {
protected:
    double* HeightJump;
    int* Age;
    char* Color;
    char* FavFood;

public:
    void SetHeightJump(double height);
    void SetColor(const char* col);
    void SetAge(int age);
    void SetFavFood(const char* food);

    double GetHeightJump();
    const char* GetColor();
    int GetAge();
    const char* GetFavFood();

    bool initAge(int age);
    bool initHeightJump(double height);

    Rabbit();
    Rabbit(double height, const char* col, int age, const char* food);
    Rabbit(const Rabbit& other);
    virtual ~Rabbit();

    virtual void show() = 0;
    int RemainLife();
    virtual Rabbit* Copy() = 0;
};

class CommonR : public Rabbit {
public:
    CommonR() : Rabbit() {}
    CommonR(double height, const char* col, int age, const char* food): Rabbit(height, col, age, food){}
    CommonR(const CommonR& other);
    void show() override { Rabbit::show(); }
    Rabbit* Copy() override;
};

class KillerR : public Rabbit {
    int* KillCount;
public:
    void SetKillCount(int killC);
    int GetKillCount();
    KillerR();
    KillerR(double height, const char* col, int age, const char* food, int killC);
    ~KillerR() override;
    KillerR(const KillerR& other);
    void show() override;
    Rabbit* Copy() override;
};

class MagicR : public Rabbit {
    char* MagicPower;
public:
    void SetMagicPower(const char* magicP);
    const char* GetMagicPower();
    MagicR();
    ~MagicR() override;
    MagicR(const MagicR& other);
    void show() override;
    Rabbit* Copy() override;
};