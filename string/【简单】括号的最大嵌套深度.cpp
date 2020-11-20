#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0, depth = 0;
        for(char ch : s)
        {
            if(ch == '(')
            {
                depth += 1;
                max_depth = depth > max_depth ? depth : max_depth;
            }
            else if(ch == ')') depth -= 1;
        }
        return max_depth;
    }
};

int main()
{
    return 0;
}