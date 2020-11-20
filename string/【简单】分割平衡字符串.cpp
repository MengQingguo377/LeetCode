#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        char base = s[0];
        int base_num = 1, ans = 0;
        for(int i = 1; i < s.size(); i++)
        { // RLRL
            if(s[i] == base)
                base_num++;
            else
            {
                base_num--;
                if(base_num == 0)
                {
                    ans++;
                    if(i+1 < s.size()) 
                        base = s[++i];
                    base_num++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}