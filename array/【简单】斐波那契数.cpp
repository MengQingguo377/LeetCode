#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int fib(int N) {
        if(!N) return 0;
        if(N <= 2) return 1;
        int a = 1, b = 1, c;
        N -= 2;
        while(N--)
        {
            c = a + b;
            a = b; b = c;
        }
        return c;
    }
};

int main()
{
	return 0;
}

/*
执行用时：
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗：
6 MB
, 在所有 C++ 提交中击败了
22.73%
的用户
*/

