#include "robot_functions.h"

// ------------------------------------------------------------------------ //
//																			//
//																			//
//				Functions for robot operations								//
//              Annaleise Kealiher & Tobin Slaven                           //
//																			//
//																			//
// ------------------------------------------------------------------------ //

using namespace std;

void cluster();
void spreader();
void moveTo(unsigned int);

static char slots[20];
unsigned int blockCounter = 0, swapCounter = 0, curPos = 0;
static int tCase = 5;
char curBlock;

int main(void)
{
    blockCounter = 0;
    swapCounter = 0;
    curPos = 0;
    for (int i = 0; i < 19; i++)
    {
        slots[i] = ' ';
    }
    curBlock = get_block_testcase(tCase, 0);
    moveTo(9); //should slot 10 be index 9, or 10? I say 9.
    put_block(curBlock, curPos, slots);
    blockCounter++;

    while (blockCounter < 20)
    {
        // print_slots(slots);
        curBlock = get_block_testcase(tCase, blockCounter);

        moveTo(0);

        while (curPos != 20 && (test_empty(curPos, slots) || !robot_ltoreq_slot(curBlock, slots[curPos])))
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
            // print_slots(slots);
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
                        swapCounter++;
                        moveTo(curPos - 1);
                    }
                    put_block(curBlock, curPos, slots);
                    blockCounter++;
                    // print_slots(slots);
                }
                else //if shuffling right optimizes, then shuffle the blocks right
                {
                    if (curPos != 0)
                        moveTo(curPos + 1);
                    while (curPos < r)
                    {
                        curBlock = switch_blocks(curBlock, curPos, slots);
                        swapCounter++;
                        moveTo(curPos + 1);
                    }
                    put_block(curBlock, curPos, slots);
                    blockCounter++;
                    // print_slots(slots);
                }
            }
        }
    }
    cout << endl
         << "Test Case: " << tCase << endl;
    cout << "Final print: " << endl;
    print_slots(slots);
    cout << "Swaps: " << swapCounter << endl;

    if (tCase > 1)
    {
        tCase--;
        main();
    }
    system("pause");

    return 0;
}

void cluster()
{
    int blocksSeen = blockCounter;
    moveTo(0);

    while (blocksSeen > 0)
    {
        if (!test_empty(curPos, slots))
            blocksSeen--;
        moveTo(curPos + 1);
    }

    moveTo(curPos - 1);
    char temp = remove_block(curPos, slots);

    while (true)
    {
        while (curPos != (19 - blocksSeen))
            moveTo(curPos + 1);

        put_block(temp, curPos, slots);
        blocksSeen++;
        moveTo(curPos - 1);

        if (blocksSeen == blockCounter)
            break;

        while (test_empty(curPos, slots))
            moveTo(curPos - 1);

        temp = remove_block(curPos, slots);
        moveTo(curPos + 1);
    }
    // print_slots(slots);
}

void spreader()
{
    cluster();

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
