#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i = 0, j = 1, k = 2; k < arr.size(); i++, j++, k++)
        {
            if((arr[i] & 1) && (arr[j] & 1) && (arr[k] & 1)) return true;
            // &按位与运算符，正负数的二进制补码的最后一位一定是1
        }
        return false;
    }
};

// 上述方法中，当判断过i j k位置的奇偶性之后，下一次循环中的i j就被重复判断了
// 下面可以通过计数方法消除这种重复性
class Solution2 {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            // if(cnt == 3) return true; // 这行代码不能放在这个位置，否则对[1,3,5]这种情况会出错
            if(!(arr[i] & 1)) cnt = 0;
            else cnt++;
            if(cnt == 3) return true;
        }
        return false;
    }
};

int main()
{
    int a[] = {1,1,3,4,5,7,7,8,76};
    vector<int>arr(a, a+3);
    Solution2 s;
    bool bo = s.threeConsecutiveOdds(arr);
    cout << bo << endl;
}