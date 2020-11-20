#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string modifyString(string s) {
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '?')
            {
                for(char ch : "abc")
                {
                    if(i==0)
                    {
                        if(s[i+1] != ch) {s[i] = ch; break;}
                    }
                    else if(i==s.length())
                    {
                        if(s[i-1]!=ch) {s[i] = ch; break;}
                    }
                    else if(s[i-1]!=ch && s[i+1]!=ch)
                    {
                        s[i] = ch; break;
                    }
                }
            }
        }
        return s;
    }
};

int main()
{
    return 0;
}