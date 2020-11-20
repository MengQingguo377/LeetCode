#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool binarySearch(vector<int>&arr, int target)
    {
        int i = 0, j = arr.size() - 1;
        while(i <= j)
        {
            int m = i - (i - j) / 2;
            if(arr[m] == target) return true;
            if(arr[m] > target)
                j = m - 1;
            else i = m + 1;
        }
        return false;
    }
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int N = matrix[0].size();
        for(int i = 0; i < matrix.size(); i++)
        {
            if(matrix[i][0] <= target && matrix[i][N-1] && binarySearch(matrix[i], target))
                return true;
        }
        return false;
    }
};

int main()
{
	return 0;
}

/*
执行用时：
52 ms
, 在所有 C++ 提交中击败了
93.78%
的用户
内存消耗：
12.7 MB
, 在所有 C++ 提交中击败了
70.16%
的用户
*/
