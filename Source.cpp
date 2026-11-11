#include "Rabbit.h"
#include "Exeption.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int age, killc;
    double height;
    char* col = new char[20];
    char* food = new char[20];

    cout << "Crate a common rabbit" << endl;
    cout << "jump height:";
    cin >> height;
    cout << "color:";
    cin >> col;
    cout << "age:";
    cin >> age;
    cout << "favorite food:";
    cin >> food;
    try
    {
        CommonR* ComRabbit = new CommonR(height, col, age, food);
        cout << endl;
        ComRabbit->show();
        delete ComRabbit;
    }
    catch (const AgeException& ex)
    {
        cout << "AgeException: " << ex.what() << std::endl;
    }
    catch (const invalid_argument& ex)
    {
        cout << "invalid_argument: " << ex.what() << std::endl;
    }
    catch (const exception&)
    {
        cout << "Something wrong" << std::endl;
    }


    cout << endl;
    cout << "Crate a killer rabbit" << endl;
    cout << "jump height:";
    cin >> height;
    cout << "color:";
    cin >> col;
    cout << "age:";
    cin >> age;
    cout << "favorite food:";
    cin >> food;
    cout << "count of kills:";
    cin >> killc;
    try
    {
        KillerR* KillRabbit = new KillerR(height, col, age, food, killc);
        cout << endl;
        KillRabbit->show();
        delete KillRabbit;
    }
    catch (const AgeException& ex)
    {
        cout << "AgeException: " << ex.what() << std::endl;
    }
    catch (const underflow_error& ex)
    {
        cout << "underflow_error: " << ex.what() << std::endl;
    }
    catch (const overflow_error& ex)
    {
        cout << "overflow_error: " << ex.what() << std::endl;
    }
    catch (const invalid_argument& ex)
    {
        cout << "invalid_argument: " << ex.what() << std::endl;
    }
    catch (const exception&)
    {
        cout << "Something wrong" << std::endl;
    }

    return 0;
}

