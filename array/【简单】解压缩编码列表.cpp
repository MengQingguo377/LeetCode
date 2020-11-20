#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int len = 0;
        for(int i = 0; i < nums.size(); i += 2)
            len += nums[i];
        vector<int>arr(len);
        int N, e, ind = 0;
        for(int i = 0; i < nums.size(); i += 2)
        {
            e = nums[i+1]; N = nums[i];
            while(N--)
            {
                arr[ind++] = e;
            }
        }
        return arr;
    }
};

int main()
{
    return 0;
}
/*
执行用时：
8 ms
, 在所有 C++ 提交中击败了
79.39%
的用户
内存消耗：
9.2 MB
, 在所有 C++ 提交中击败了
99.04%
的用户
*/