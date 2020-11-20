#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>res(arr);
        unordered_map<int, int>ele_rank; 
        sort(arr.begin(), arr.end());
        int rank = 1;
        for(int x : arr)
        {
            if(ele_rank.find(x) == ele_rank.end()) // 不存在
                ele_rank[x] = rank++;
        }
        for(int i = 0; i < arr.size(); i++)
        {
            res[i] = ele_rank[res[i]];
        }
        return res;
    }
};

int main()
{
    int a[] = {12,123,342,23,342,87};
    vector<int>arr(a, a + sizeof(a) / sizeof(int));
    Solution s;
    for(int x : s.arrayRankTransform(arr))
        cout << x << endl;
    return 0;
}