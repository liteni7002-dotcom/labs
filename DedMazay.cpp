#include "DedMazay.h"

using namespace std;

DedMazay::DedMazay(Rabbit* r1, double capacity) {
    cout << "DedMazay::DedMazay(Rabbit* r1, double capacity)" << endl;
    R = r1->Copy();
    BoatCapacity = new double;
    *BoatCapacity = capacity;
}

DedMazay::~DedMazay() {
    cout << "DedMazay::~DedMazay" << endl;
    delete BoatCapacity;
    delete R;
}

void DedMazay::ShowBoatInfo() {
    cout << "DedMazay::ShowBoatInfo" << endl;
    cout << "Boat capacity: " << *BoatCapacity << " kg" << endl;
    cout << "Rabbit in the boat:" << endl;
    R->show();
}

void DedMazay::ResetKillerCount(int newCount)
{
    cout << "DedMazay::ResetKillerCount" << endl;
    KillerR* killerPtr = dynamic_cast<KillerR*>(R);
    if (killerPtr != nullptr) {
        killerPtr->SetKillCount(newCount);
        cout << "Ded Mazay successfully reset the killer's counter!" << endl;
    }
    else {
        cout << "Notice: This rabbit is not a killer, no need to reform him." << endl;
    }
}

MagicMazay::MagicMazay(MagicR* mr, double capacity) : DedMazay(mr, capacity) {
    cout << "MagicMazay::MagicMazay(MagicR* mr, double capacity)" << endl;
}

MagicMazay::~MagicMazay() {
    cout << "MagicMazay::~MagicMazay" << endl;
}

MagicMazay* MagicMazay::CreateInstance(double capacity) {
    cout << "MagicMazay* MagicMazay::CreateInstance(double capacity)" << endl;

    MagicR* tempMagicRabbit = new MagicR();

    MagicMazay* newMazay = new MagicMazay(tempMagicRabbit, capacity);

    delete tempMagicRabbit;

    return newMazay;
}

void MagicMazay::UpgradeRabbitPower(const char* newPower) {
    cout << "MagicMazay::UpgradeRabbitPower" << endl;

    MagicR* magicPtr = dynamic_cast<MagicR*>(R);

    if (magicPtr != nullptr) {
        magicPtr->SetMagicPower(newPower);
        cout << "Ded Mazay successfully changed the rabbit's magic power!" << endl;
    }
    else {
        cout << "Error: This rabbit is not magical. Upgrade Rabbit Power failed!" << endl;
    }
}