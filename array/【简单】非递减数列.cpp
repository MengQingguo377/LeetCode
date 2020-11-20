#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int fal = 0, j = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i-1])
            {
                fal++;
                if(fal > 1) return false;
                if(i-2 >= 0 && nums[i-2] > nums[i]) nums[i] = nums[i-1];
                else nums[i-1] = nums[i];
            }
        }   
        return true;
    }
};

int main()
{
    return 0;
}