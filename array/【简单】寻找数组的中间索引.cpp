#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int N = nums.size();
        if(!N) return -1;
        if(N == 1) return 0;
        vector<int>arr1(N), arr2(N);
        arr1[0] = nums[0]; arr2[N-1] = nums[N-1];
        for(int i = 1; i < N; i++)
        {
            arr1[i] = nums[i] + arr1[i-1];
            arr2[N-1-i] = nums[N-1-i] + arr2[N-i];
        }
        if(!arr2[1]) return 0;
        for(int i = 1; i < N-1; i++)
        {
            if(arr1[i-1] == arr2[i+1]) return i;
        }
        if(!arr1[N-2]) return N-1;
        return -1;
    }
};

int main()
{
    return 0;
}