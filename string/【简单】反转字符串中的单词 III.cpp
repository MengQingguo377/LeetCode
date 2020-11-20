#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // int N = s.size();
        s += " ";
        int i = 0, j = 0;
        while(true)
        {
            while(i<s.size() && s[i]==' ') i++;
            j = i + 1;
            while(j<s.size() && s[j]!=' ') j++;
            int a = i, b = j - 1;
            while(a < b)
            { // "Let's take LeetCode contest "
                swap(s[a], s[b]);
                a++; b--;
            }
            i = j + 1;
            if(i >= s.size() - 1) break;
        }
        return s.substr(0, s.size()-1);
    }
};

int main()
{
    return 0;
}