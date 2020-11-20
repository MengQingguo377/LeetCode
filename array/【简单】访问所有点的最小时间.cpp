#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Solution { // 数学问题
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int h_distance, v_distance;
        for(int i = 1; i < points.size(); i++)
        {
            h_distance = abs(points[i][0] - points[i-1][0]);
            v_distance = abs(points[i][1] - points[i-1][1]);
            ans += h_distance + v_distance - min(h_distance, v_distance);
        }
        return ans;
    }
};

class Solution1 { // 只需要选取x或y轴上的最大绝对值就行了
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 1; i < points.size(); i++)
            ans += max(abs(points[i][0] - points[i-1][0]), abs(points[i][1] - points[i-1][1]));
        return ans;
    }
};

int main()
{

    return 0;
}