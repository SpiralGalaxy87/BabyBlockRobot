# BabyBlockRobot

I love you!
OwO

Need:

***Functions****
- Function to decide which way to shift blocks if necessary (we want to shift the fewest possible blocks and we need to have room)
- Function to shift blocks over by one space
- Function to go through slots and identify the proper location for a block to go

***Main***

- Intialize array of length 20 to Null or " "
- Put the first block in slot 10
- 19 times: pick up a block from "the chute", find a proper space, place the block, and shift other blocks down to make room if necessary

***Variables***
- A counter for the number of times the Switch Blocks function is called
- A tracker for the current robot position
- A tracker for the current block in the robot's hand


Remember: 
The Robot Challenge: Your robot will be judged by the fewest number of swapped blocks. To keep up with that number you will need to maintain a count of the number of times the Switch Blocks function is called.

Notes:
- ~~To inlcude the robot_functions as a separate file, we must create a robot_functions.h
~~Currently the code doesn't compile because the included cpp file does not have a "main",
making a header file will fix this.~~
- Also, there were some issues with the robot functions file so I added "using namespace std".
- I think you may be missing the C++ VSCode extension, this will probably help out a lot when things won't compile.
- Moving forward, it would be best for you to actually clone the repo so that it will be easier to merge later on.
What I mean is to have git tracking our changes instead of manually uploading and downloading the files. I'll show you how to do this.
- ILY

