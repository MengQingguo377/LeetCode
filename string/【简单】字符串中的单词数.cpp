#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        if(s.empty()) return 0;
        int num = (s[0] != ' ') ? 1 : 0;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] != ' ' && s[i-1] == ' ') num++;
        }
        return num;
    }
};


int main()
{
    return 0;
}