#pragma once
#include "Rabbit.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class DedMazay {
private:
    double* BoatCapacity;
protected:
    Rabbit* R;
public:
    DedMazay(Rabbit* r1, double capacity);
    virtual ~DedMazay();
    void ShowBoatInfo();
    void ResetKillerCount(int newCount);
};

class MagicMazay : public DedMazay {
private:
    MagicMazay(MagicR* mr, double capacity);
public:
    virtual ~MagicMazay();
    static MagicMazay* CreateInstance(double capacity);
    void UpgradeRabbitPower(const char* newPower);
};