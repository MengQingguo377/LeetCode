#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(k >= 0)
        {
            if(i < 0)
                nums1[k--] = nums2[j--];
            else if(j < 0) break;
            else if(nums1[i] >= nums2[j])
                nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
    }
};

int main()
{
    int a[] = {1,0};
    int b[] = {5};
    vector<int>aa(a, a + 2);
    vector<int>bb(b, b + 1);
    Solution s;
    s.merge(aa, 1, bb, 1);
    for(int x : aa)
        cout << x << endl;
    return 0;
}