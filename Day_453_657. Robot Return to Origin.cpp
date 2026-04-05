#include <bits/stdc++.h>
using namespace std;

/*
Problem: A robot is located at the origin (0, 0) on a 2D plane. The robot can move in four directions: up (U), down (D), left (L), and right (R). Given a string of moves, determine if the robot returns to the origin after executing all the moves.
Approach: To determine if the robot returns to the origin, we can keep track of the robot's position using two variables, x and y. We will iterate through each character in the moves string and update the x and y coordinates accordingly:
- For 'R', we will increment x by 1.
- For 'L', we will decrement x by 1.
- For 'U', we will increment y by 1.
- For 'D', we will decrement y by 1.

Steps:
1. Initialize two integer variables, x and y, to 0 to represent the robot's current position.
2. Iterate through each character in the moves string:
    - If the character is 'R', increment x by 1.
    - If the character is 'L', decrement x by 1.
    - If the character is 'U', increment y by 1.
    - If the character is 'D', decrement y by 1.
3. After processing all the moves, check if both x and y are equal to 0. If they are, it means the robot has returned to the origin, and we can return true. Otherwise, return false.

Time Complexity: O(n), where n is the length of the moves string, as we need to iterate through each character in the string once.
Space Complexity: O(1), as we are using only a constant amount of extra space to store the x and y coordinates.
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char m : moves) {
            if (m == 'R') x++;
            else if (m == 'L') x--;
            else if (m == 'U') y++;
            else if (m == 'D') y--;
        }
        return x == 0 && y == 0;
    }
};