#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int max_win = (arr.size() & 1) ? arr.size() : arr.size() - 1, // 滑动窗口的最大值
            res = 0, // 保存结果
            cnt, // 统计i位置元素被求和次数
            win; // 窗口长度
        for(int i = 0; i < arr.size(); i++)
        {
            cnt = 0; win = 1;
            while(win <= max_win)
            {
                int a = i - win + 1;
                int b = i + win - 1;
                if(a < 0) a = 0;
                if(b >= arr.size()) b = arr.size() - 1;
                cnt += (b - a + 2  - win); // 注意不是(b - a + 1  - win) 
                win += 2;
            }
            res += cnt * arr[i];
        }
        return res;
    }
};

int main()
{
    int a[] = {1,4,3,5,7};
    vector<int>arr(a, a + sizeof(a) / sizeof(int));
    Solution s;
    cout << s.sumOddLengthSubarrays(arr);
}