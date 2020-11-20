#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>ind;
        unordered_map<int, int>::iterator it;
        for(int i = 0; i < nums.size(); i++)
        {
            it = ind.find(nums[i]);
            if(it == ind.end()) // 不存在该键
                // ind[nums[i]] = i;
                ind.insert(make_pair(nums[i], i));
            else
            {
                if(i - ind[nums[i]] <= k) return true;
                else ind[nums[i]] = i;
            }
        }
        return false;
    }
};

int main()
{
    int a[] = {1,2,3,1,2,3};
    vector<int>arr(a, a + sizeof(a) / sizeof(int));
    Solution s;
    bool bo = s.containsNearbyDuplicate(arr, 2);
    cout << bo << endl;
    return 0;
}