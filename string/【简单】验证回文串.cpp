#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        // while(j>=0 && !isalpha(s[j])) j--;
        
        while(i < j)
        {
            while(i<s.size() && !isalpha(s[i]) && !isdigit(s[i])) i++;
            while(j>=0 && !isalpha(s[j]) && !isdigit(s[j])) j--;
            if((j > i) && (!(s[i] == s[j] || abs(s[i]-s[j]) == abs('a'-'A'))))
                return false;
            if((j > i) && !((isdigit(s[i])&&isdigit(s[j]))||(isalpha(s[i])&&isalpha(s[j])))) // 用于处理"0P"这样的输入
                return false;
            i++; j--;
        }
        return true;
    }
};

int main()
{
    return 0;
}