#include "robot_functions.h"

using namespace std;

//void cluster();
void spreader();
void moveTo(unsigned int);

char slots[20] = {' '};
unsigned int blockCounter = 0, swapCounter = 0, curPos = 0;
char curBlock;

int main(void)
{

    system("pause");
    return 0;
}

// void cluster()
// {
//
// }

void spreader()
{
    int slotIndex = 1;
    int spreadBlocks = 0;

    moveTo(20 - blockCounter);

    while (spreadBlocks != blockCounter)
    {

        curBlock = remove_block(curPos, slots);
        moveTo(slotIndex);
        put_block(curBlock, curPos, slots);

        spreadBlocks++;
        slotIndex += 2;

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
