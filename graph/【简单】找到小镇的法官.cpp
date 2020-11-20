/*
 * @Description: LeetCode刷题记录
 * @Author: 孟庆国
 * @LastEditTime: 2020-11-08 21:23:59
 * @LastEditors: 孟庆国
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(trust.empty()) return N==1?1:-1;
        vector<int>arr(N+1,0);
        set<int>s;
        for(int i = 0; i < trust.size(); i++)
            s.insert(trust[i][0]);
        for(int i = 0; i < trust.size(); i++)
        {
            if((++arr[trust[i][1]]) == N-1 && s.find(trust[i][1]) == s.end())
                return trust[i][1];
        }
        return -1;
    }
};

class Solution1 {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<int> >arr(N+1, vector<int>(2,0));
        for(int i = 0; i < trust.size(); i++)
        {
            arr[trust[i][0]][0]++; // 出度
            arr[trust[i][1]][1]++; // 入度
        }
        for(int i = 1; i <= N; i++)
        {
            if(arr[i][0]==0 && arr[i][1]==N-1)
                return i;
        }
        return -1;
    }
};

int main()
{
	return 0;
}
