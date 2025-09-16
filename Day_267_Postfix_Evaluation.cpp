#include <bits/stdc++.h>
using namespace std;

// Problem: Evaluate a postfix expression given as an array of strings, where each string is either an operand (integer) or an operator (+, -, *, /, ^).
// Approach: Use a stack to evaluate the postfix expression. Traverse the array, pushing operands onto the stack. When an operator is encountered, pop the top two operands from the stack, apply the operator, and push the result back onto the stack. At the end of the traversal, the stack will contain one element, which is the result of the postfix expression.

// Steps:
// 1. Initialize an empty stack to hold operands.
// 2. Traverse each string in the input array:
//    a. If the string is an operand, convert it to an integer and push it onto the stack.
//    b. If the string is an operator, pop the top two operands from the stack, apply the operator, and push the result back onto the stack.
// 3. After processing all strings, the stack will contain one element, which is the result of the postfix expression.
// 4. Return the top element of the stack as the final result.

// Time Complexity: O(n), where n is the number of elements in the input array.
// Space Complexity: O(n), in the worst case, all elements could be operands and pushed

class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
         stack<long long> st;

        for (string &s : arr) {
            if (isOperator(s)) {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                long long res = applyOp(a, b, s);
                st.push(res);
            } else {
                st.push(stoll(s)); // convert string to integer
            }
        }
        return (int)st.top();
    }

  private:
    bool isOperator(const string &s) {
        return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^");
    }

    long long applyOp(long long a, long long b, const string &op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") {
            // floor division handling (important for negatives)
            long long res = a / b;
            if ((a ^ b) < 0 && a % b != 0) res--;
            return res;
        }
        if (op == "^") return pow(a, b);
        return 0;
    }
};