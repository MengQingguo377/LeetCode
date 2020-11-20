#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int>cnt; // 用于统计元素出现的频数
        unordered_map<int, int>pos_left, pos_right; // 记录元素出现的首位置、尾位置
        int max_cnt; // 记录最大频数对应的元素
        cnt[nums[0]] = 1; 
        pos_left[nums[0]] = 0; 
        pos_right[nums[0]] = 0;
        max_cnt = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            unordered_map<int, int>::iterator it = cnt.find(nums[i]);
            if(it != cnt.end()) // cnt中存在该键值对
            {
                cnt[nums[i]] += 1;
                pos_right[nums[i]] = i;
                if(cnt[nums[i]] == cnt[max_cnt])
                {
                    if(pos_right[nums[i]]-pos_left[nums[i]] < pos_right[max_cnt]-pos_left[max_cnt])
                        max_cnt = nums[i];
                }
                else if(cnt[nums[i]] > cnt[max_cnt]) max_cnt = nums[i];
            }
            else // cnt中不存在该键值对
            {
                cnt[nums[i]] = 1;
                pos_left[nums[i]] = pos_right[nums[i]] = i;
            }
        }
        return pos_right[max_cnt] - pos_left[max_cnt] + 1;
    }
};

int main()
{
    return 0;
}