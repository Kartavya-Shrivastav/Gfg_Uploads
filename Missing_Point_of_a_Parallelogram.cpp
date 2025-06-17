#include <bits/stdc++.h>
using namespace std;

// Problem: Find the missing point of a parallelogram given three points A, B, and C.
// Approach: The missing point D can be calculated using the formula D = A + C - B, and similarly for other combinations.

class Solution {
    public:
        // Function to find the missing point of a parallelogram given three points A, B, and C
        vector<double> findPoint(int A[], int B[], int C[])
        {
                vector<vector<double>> V;
                // Calculate possible missing points using the parallelogram property
                V.push_back({A[0] + C[0] - B[0], A[1] + C[1] - B[1]}); // D = A + C - B
                V.push_back({B[0] + C[0] - A[0], B[1] + C[1] - A[1]}); // D = B + C - A
                V.push_back({A[0] + B[0] - C[0], A[1] + B[1] - C[1]}); // D = A + B - C
                // Sort the points to return the lexicographically smallest one
                sort(V.begin(), V.end());
                return V[0];
        }
};