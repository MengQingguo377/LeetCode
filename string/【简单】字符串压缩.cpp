#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string compressString(string S) {
        string s = S.substr(0,1) + "1";
        for(int i = 1; i < S.size(); i++)
        {
            if(S[i] != S[i-1])
                s += S.substr(i,1) + "1";
            else
            {

                int p = s.size() - 1;
                if(s[p] < '9') s[p] += 1;
                else
                {
                    while(s[p] <= '9' && s[p] >= '0') p--;
                    int n = stoi(s.substr(p+1));
                    s = s.substr(0, p+1) + to_string(stoi(s.substr(p+1)) + 1);
                }
            }
        }
        // cout << s << endl;
        return s.size() < S.size() ? s : S;
    }
};

int main()
{
    string s = "aaaaaaaaaaaabbAA";
    Solution solu;
    cout << solu.compressString(s) << endl;
}