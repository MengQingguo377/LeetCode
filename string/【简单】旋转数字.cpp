#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        unordered_map<char, char>mp {{'2','5'}, {'5','2'}, {'6','9'}, {'9','6'}, {'1','1'}, {'0','0'}, {'8','8'}};
        string s, ss;
        bool f;
        int ans = 0;
        for(int i = 1; i <= N; i++)
        {
            f = true;
            ss = "";
            s = to_string(i);
            for(char ch : s)
            {
                if(ch=='3' || ch=='4' || ch=='7')
                {
                    f = false; break;
                }
                else ss += mp[ch];
            }
            if(!f) continue;
            if(stoi(ss) != i) ans++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}