#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator it_end = nums.end(), it_beg = nums.begin();
        return max((*--it_end) * (*--it_end) * (*--it_end), 
                    (*it_beg) * (*++it_beg) * (*--nums.end()));
    }
};

int main()
{
    int a[] = {-4,-1,-4,6,-3,5,-7,3};
    vector<int>arr(a, a+8);
    Solution s;
    int res = s.maximumProduct(arr);
    cout << res;
}