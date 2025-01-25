# Test Cases for assignment-1 

## Test Case 1: Valid Input
### Input (Command Line): 
./assignment-1 50
### Input (Pieces): 
1, 1
2, 5
5, 10
10, 20
25, 50
### Output: 
0 @ 1 = 1
25 @ 2 = 5
0 @ 5 = 10
0 @ 10 = 20
0 @ 25 = 50
Remainder: 0
Value: 125

## Test Case 2: No Argument for Command Line 
### Input (Command Line): 
./assignment-1 
### Output: 
Usage: C:\Users\kentv\OneDrive\Desktop\OS\Assignment 1\01-rods-KentvTran\assignment-1 <rod_length>
Add the rod length as an argument

## Test Case 3: 0 or Negative Rod Length or Above Max Rod Limit
### Input (Command Line): 
./assignment-1 -50
or 
./assignment-1 0
or
./assignment-1 1000000000000
### Output: 
Rod length must be between 1 and 10000


