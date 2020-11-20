#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int>mp;
        int ans = 0, a, b, key;
        for(auto x : dominoes)
        {
            a = x[0], b = x[1];
            if(a > b) key = a*10 + b;
            else key = b*10 + a;
            if(mp[key])
            {
                ans += mp[key]; mp[key]++;
            }
            else mp[key]++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}