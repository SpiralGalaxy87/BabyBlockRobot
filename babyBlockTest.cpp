#include "robot_functions.h"

using namespace std;

//void cluster();
void spreader();
void moveTo(unsigned int);

char slots[20] = {' '};
unsigned int blockCounter = 0, swapCounter = 0, curPos = 0, tCase = 1;
char curBlock;

int main(void)
{
    curBlock = get_block_testcase(tCase, 0);
    moveTo(9); //should slot 10 be index 9, or 10? I say 9.
    put_block(curBlock, curPos, slots);
    blockCounter++;

    while (blockCounter < 20)
    {
        print_slots(slots);
        get_block_testcase(tCase, blockCounter);
        moveTo(0);

        while (curPos != 19 && (test_empty(curPos, slots) || !robot_ltoreq_slot(curBlock, slots[curPos])))
        { //while the robot's block is greater---find the pos directly after the block's ideal pos in the array
            moveTo(curPos + 1);
        }

        if (curPos != 0)
        { //if we are not at the begining of the array, move back one slot, to block's ideal pos
            moveTo(curPos - 1);
        }

        if (blockCounter < 10) //if blocks < 10, you know there is an empty space. Place the block.
        {
            put_block(curBlock, curPos, slots);
            blockCounter++;
            spreader();
        }
        else //if there are more than 10 blocks:
        {
            if (test_empty(curPos, slots)) //check if the proper slot for the block to go in is empty
            {
                put_block(curBlock, curPos, slots);
                blockCounter++;
            }
            else //we have to move blocks out of the way
            {
                unsigned int l = curPos, r = curPos;                   //determine which way to shuffle the blocks
                while (!test_empty(l, slots) && !test_empty(r, slots)) //a race between the left and right
                {
                    if (l > 0)
                        l--;
                    if (r < 19)
                        r++;
                }
                if (test_empty(l, slots)) //if shuffling left optimizes, then shuffle the blocks left
                {
                    while (curPos > l)
                    {
                        curBlock = switch_blocks(curBlock, curPos, slots);
                        moveTo(curPos - 1);
                    }
                }
                else //if shuffling right optimizes, then shuffle the blocks right
                {
                    while (curPos < r)
                    {
                        curBlock = switch_blocks(curBlock, curPos, slots);
                        moveTo(curPos + 1);
                    }
                }
            }
        }
    }

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
