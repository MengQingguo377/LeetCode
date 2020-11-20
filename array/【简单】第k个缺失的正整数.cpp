#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr.empty()) return k;
        int miss;
        int i = 0;
        for(int num = 1; k; num++)
        {
            if(i < arr.size() && num == arr[i])
                i++;
            else
            {
                miss = num;
                k--;
            }
        }
        return miss;
    }
};

int main()
{
	return 0;
}

/*
执行用时：
12 ms
, 在所有 C++ 提交中击败了
55.68%
的用户
内存消耗：
9.4 MB
, 在所有 C++ 提交中击败了
63.87%
的用户
*/
