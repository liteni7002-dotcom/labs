#include "Rabbit.h"
#include "Exeption.h"

using namespace std;

const char* colors[] = { "grey", "white", "black", "brown", "red", "green" };
const char* foods[] = { "carrot", "apple", "cabbage", "grass", "salad" };
const char* Powers[] = { "Water", "Fire", "Earth", "Air" };

Rabbit::Rabbit(const Rabbit& other) {
    HeightJump = new double(*other.HeightJump);
    Age = new int(*other.Age);
    Color = new char[20];
    strcpy_s(Color, 20, other.Color);
    FavFood = new char[30];
    strcpy_s(FavFood, 30, other.FavFood);
}

void Rabbit::SetHeightJump(double height)
{
    if (initHeightJump(height)) {
        *HeightJump = height;
    }
    else { throw invalid_argument("The jump height value is incorrect"); }
}

void Rabbit::SetColor(const char* col)
{
    strcpy_s(Color, 20, col);
}

void Rabbit::SetAge(int age)
{
    if (initAge(age)) {
        *Age = age;
    }
    else { throw AgeException("The age value is incorrect"); }
}

void Rabbit::SetFavFood(const char* food)
{
    strcpy_s(FavFood, 30, food);
}

double Rabbit::GetHeightJump()
{
    return *HeightJump;
}

const char* Rabbit::GetColor()
{
    return this->Color;
}

int Rabbit::GetAge()
{
    return *Age;
}

const char* Rabbit::GetFavFood()
{
    return this->FavFood;
}

bool Rabbit::initAge(int age)
{
    return age > 0 && age <= 12;
}

bool Rabbit::initHeightJump(double height)
{
    return height > 0 && height <= 107;
}

Rabbit::Rabbit()
{
    HeightJump = new double;
    Age = new int;
    Color = new char[20];
    FavFood = new char[30];

    double height = 1.0 + (rand() % 10700) / 100.0;
    int age = 1 + rand() % 12;
    const char* col = colors[rand() % 6];
    const char* food = foods[rand() % 5];
    *Age = age;
    *HeightJump = height;
    strcpy_s(Color, 20, col);
    strcpy_s(FavFood, 30, food);
}

Rabbit::Rabbit(double height, const char* col, int age, const char* food)
{
    if (initHeightJump(height)) {
        if (initAge(age)) {
            HeightJump = new double;
            Age = new int;
            *Age = age;
            *HeightJump = height;
        }
        else {
            throw AgeException("The age value is incorrect");
        }
    }
    else {
        throw invalid_argument("The jump height value is incorrect");
    }
    Color = new char[20];
    FavFood = new char[30];
    strcpy_s(Color, 20, col);
    strcpy_s(FavFood, 30, food);
}

Rabbit::~Rabbit()
{
    delete HeightJump;
    delete Age;
    delete[] Color;
    delete[] FavFood;
}

void KillerR::SetKillCount(int killC)
{
    if (killC >= 0) {
        *KillCount = killC;
    }
    else {
        throw invalid_argument("Kill count cannot be negative");
    }
}

int KillerR::GetKillCount() {
    return *KillCount;
}

KillerR::KillerR() : Rabbit()
{
    KillCount = new int;
    *KillCount = 1 + rand() % 300;
}

KillerR::KillerR(double height, const char* col, int age, const char* food, int killC)
    : Rabbit(height, col, age, food)
{
    if (killC < 0) {
        throw underflow_error("Kill count cannot be negative!");
    }
    else if(killC > 300) {
        throw overflow_error("Kill count cannot be higer, then 300!");
    }
    KillCount = new int(killC);
}

KillerR::~KillerR()
{
    delete KillCount;
}

void KillerR::show() {
    Rabbit::show(); 
    cout << "Kill Count: " << *KillCount << endl;
}

void MagicR::SetMagicPower(const char* magicP)
{
    if (magicP != nullptr) {
        strcpy_s(MagicPower, 20, magicP);
    }
    else {
        throw invalid_argument("Magic power cannot be null");
    }
}

const char* MagicR::GetMagicPower()
{
    return this->MagicPower;
}

MagicR::MagicR() : Rabbit()
{
    MagicPower = new char[20];
    const char* magicP = Powers[rand() % 4];
    strcpy_s(MagicPower, 20, magicP);
}

MagicR::~MagicR()
{
    delete[] MagicPower;
}

void MagicR::show()
{
    Rabbit::show();
    cout << "Magic Power: " << MagicPower << endl;
}

void Rabbit::show() {
    cout << "Rabbit description:" << endl;
    cout << "HeightJump: " << GetHeightJump() << " centimeters" << endl;
    cout << "Color: " << GetColor() << endl;
    cout << "Age: " << GetAge() << endl;
    cout << "FavFood: " << GetFavFood() << endl;
}

int Rabbit::RemainLife() {
    return (12 - GetAge());
}

CommonR::CommonR(const CommonR& other) : Rabbit(other) {
}

Rabbit* CommonR::Copy() {
    return new CommonR(*this);
}

KillerR::KillerR(const KillerR& other) : Rabbit(other) {
    KillCount = new int(*other.KillCount);
}
Rabbit* KillerR::Copy() {
    return new KillerR(*this);
}

MagicR::MagicR(const MagicR& other) : Rabbit(other) {
    MagicPower = new char[20];
    strcpy_s(MagicPower, 20, other.MagicPower);
}
Rabbit* MagicR::Copy() {
    return new MagicR(*this);
}