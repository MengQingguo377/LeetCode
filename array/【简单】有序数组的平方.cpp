#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int>arr(A.size());
        int i, j;
        for(j = 0; j < A.size(); j++)
            if(A[j] >= 0) break; // j是第一个非负数的位置
        i = j - 1; // i是最后一个负数的位置
        // 如果元素全为非负数，那么j=0，i=-1
        // 如果元素全为负数，那么j=A.size()，i=A.size()-1
        // 以上两种特殊情况在下面代码中不需要考虑

        for(int k = 0; k < A.size(); k++)
        {
            if(i == -1) // 负数已经被处理完毕了
                arr[k] = pow(A[j++], 2); // A[j]的平方
            else if(j == A.size()) // 非负数已经被处理完了
                arr[k] = pow(A[i--], 2);
            else
            {
                if(A[i] + A[j] <= 0) // A[i]的绝对值大于等于A[j]的绝对值
                    arr[k] = pow(A[j++], 2);
                else arr[k] = pow(A[i--], 2);
            }
        }
        return arr;
    }
};

int main()
{
    int a[] = {-5,-4,-3,-2,-1};
    vector<int>arr(a, a+5);
    Solution s;
    arr = s.sortedSquares(arr);
    for(auto x : arr) cout << x << endl;
    return 0;
}