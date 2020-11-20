#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>ans(n);
        vector<vector<int> >arr(n+1, {1,2,3,4});
        vector<vector<int> >mymap(n+1);
        for(int i = 0; i < paths.size(); i++)
        {
            mymap[paths[i][0]].push_back(paths[i][1]);
            mymap[paths[i][1]].push_back(paths[i][0]);
        }
        for(int i = 1; i <= n; i++)
        {
            int ind = 0;
            while(arr[i][ind] == 0)
                ind++;
            ans[i-1] = ind+1;
            for(int x : mymap[i])
                arr[x][ind] = 0;
        }
        return ans;
    }
};

int main()
{
    return 0;
}