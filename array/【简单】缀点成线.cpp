#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() <= 2) return true;
        double kk, k = (coordinates[0][1]-coordinates[1][1]) / double(coordinates[0][0]-coordinates[1][0]); // 斜率
        if(abs(k) == INFINITY) k = INFINITY;
        for(int i = 2; i < coordinates.size(); i++)
        {
            kk = (coordinates[i-1][1]-coordinates[i][1]) / double(coordinates[i-1][0]-coordinates[i][0]);
            if(abs(kk) == INFINITY) kk = INFINITY;
            // if(k == INFINITY && abs(kk) != INFINITY) return false;
            if(kk != k) return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}
