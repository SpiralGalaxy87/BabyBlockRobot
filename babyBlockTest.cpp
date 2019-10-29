
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <iterator>
#include <map>
#include <math.h>
#include "robot_functions.cpp"

using namespace std;

unsigned int cluster();
unsigned int spreader();
unsigned int moveTo(unsigned int, unsigned int);

char slots[20];
unsigned int blockCounter = 0, swapCounter = 0, curPos = 0;
char curBlock = '';

int main(void)
{

    int numBlocks;

    cout << "enter number of blocks: " << endl;
    cin >> numBlocks;
    float inc;
    inc = (20.0 / (numBlocks + 1.0));
    cout << "increment: " << inc << endl;

    for (int i = 0; i <= 19; i++)
    {
        if (numBlocks > 0 && (i + 1) % int(round(inc)) == 0 && (i != 0 || int(round(inc)) == 0))
        {
            numBlocks--;
            cout << "* ";
        }
        else
        {
            cout << "_ ";
        }
    }

    system("pause");
    return 0;
}

unsigned int cluster()
{
    return position;
}

unsigned int spreader()
{
    return position;
}

unsigned int moveTo(unsigned int fromPos, unsigned int toPos)
{
    // Use shift_right() / shift_left() to move to final position
    return position;
}
