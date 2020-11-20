#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>arr(nums);
        sort(arr.begin(), arr.end());
        int front = -1, end = -1, N = arr.size();
        for(int i = 0; i < nums.size(); i++)
        {
            if((front == -1) && (nums[i] != arr[i]))
                front = i;
            if((end == -1) && (nums[N-i-1] != arr[N-i-1]))
                end = N - i - 1;
        }
        // cout << front << " " << end << endl;
        if(end == front) return 0;
        return end - front + 1;
    }
};

int main()
{
    Solution s;
    int a[]{2, 6, 4, 8, 10, 9, 15};
    vector<int>arr(a, a + 7);
    cout << s.findUnsortedSubarray(arr) << endl;
    // vector<int>aa(arr);
    // sort(aa.begin(), aa.end());
    // for(int x : arr)
    //     cout << x << endl;
    return 0;
}