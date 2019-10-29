#include "robot_functions.h"

using namespace std;

//void cluster();
//void spreader();
void moveTo(unsigned int);

char slots[20] = {' '};
unsigned int blockCounter = 0, swapCounter = 0, curPos = 0;
char curBlock;

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

    cout << "move to 6" << endl;
    moveTo(6);
    cout << "move to 4" << endl;
    moveTo(4);

    system("pause");
    return 0;
}

// unsigned int cluster()
// {
//     return position;
// }

// unsigned int spreader()
// {
//     return position;
// }

void moveTo(unsigned int toPos)
{
    while (curPos < toPos)
    {
        curPos = shift_right(curPos);
    }
    while (curPos > toPos)
    {
        curPos = shift_left(curPos);
    }
}
