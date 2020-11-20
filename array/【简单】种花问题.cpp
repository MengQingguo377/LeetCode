#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(!n) return true; // n=0，讲过这个判断之后，下面的所有情况都有n>0成立
        if(flowerbed.empty()) return false; // 花坛为空且n不为0
        if(flowerbed.size() == 1) // 花坛只有一个位置且n不为0
        {
            if(!flowerbed[0] && n==1) return true;
            else return false;
        }
        int cnt = 0, i = 1;
        if(!flowerbed[0] && !flowerbed[1]) 
        {   
            i = 2; cnt++;
            if(cnt >= n) return true; // 这个一定有个判断，否则flowerbed=[0,0],n=1的情况会出错
        }
        flowerbed.push_back(0); // 最后追加一个0，可以减少右零界的判断工作
        while(i < flowerbed.size() - 1)
        {
            if(flowerbed[i]) i += 2;
            else if(flowerbed[i-1] || flowerbed[i+1]) i++;
            else {cnt++; i += 2;}
            if(cnt >= n) return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}