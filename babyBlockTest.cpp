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
//
// }

unsigned int spreader()
{
    float increment = (20.0 / (blockCounter + 1.0));
    int slotIndex = round(increment);
    int spreadBlocks = 0;

    moveTo(20 - blockCounter);

    while (spreadBlocks != blockCounter)
    {

        curBlock = remove_block();
        moveTo(slotIndex);
        put_block(curBlock, curPos, slots);

        slotIndex += round(increment);
        spreadBlocks++;

        moveTo(20 - blockCounter + spreadBlocks);
    }
}

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
