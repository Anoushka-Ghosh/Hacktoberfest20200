#include <iostream>
#include <iomanip>
#include <cmath>
#include <thread>
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif

using namespace std;

int level = 0;
double randNum;
int userInput;

void levelCreator(int level)
{
    randNum = rand() % ((int)pow(10, level) + 1 - (int)pow(10, level - 1)) + (int)pow(10, level - 1);
    cout << fixed << setprecision(0) << randNum << endl;
    this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(5));
    if (system("CLS")) system("clear");
    cout << "Enter the number: ";
    cin >> userInput;
    if (userInput == randNum)
    {
        level++;
        cout << "Congrats moving to level " << level << endl;
        levelCreator(level);
    }
    else
    {
        cout << "Sorry wrong number!";
        cout << "You reached level " << level << endl;
    }
}

int main()
{
    srand((unsigned)time(0));
    cout << setw(40) << setfill('=') << "" << endl;
    cout << setw(17) << setfill(' ') << "" << "Number Game" << endl;
    cout << setw(40) << setfill('=') << "" << endl;
    level = 1;
    levelCreator(level);
}