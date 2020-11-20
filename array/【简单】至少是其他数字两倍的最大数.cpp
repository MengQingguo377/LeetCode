#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int first_max, second_max;
        first_max = nums[0] > nums[1] ? 0 : 1;
        second_max = 1 - first_max;
        for(int i = 2; i < nums.size(); i++)
        {
            if(nums[i] > nums[first_max])
            {
                second_max = first_max;
                first_max = i;
            }
            else if(nums[i] > nums[second_max])
                second_max = i;
        }
        if(nums[first_max] >= nums[second_max] * 2)
            return first_max;
        return -1;
    }
};
// 执行用时：
// 0 ms
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户
// 内存消耗：
// 10.8 MB
// , 在所有 C++ 提交中击败了
// 79.09%
// 的用户

int main()
{

    return 0;
}