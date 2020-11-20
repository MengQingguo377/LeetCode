#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0, j = S.size() - 1;
        while(1)
        {
            while(!((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z')) && (i < S.size())) i++;
            while(!((S[j] >= 'a' && S[j] <= 'z') || (S[j] >= 'A' && S[j] <= 'Z')) && (j >= 0)) j--;
            // cout << i << " " << j << endl;
            if(i < j) swap(S[i], S[j]);
            else return S;
            i++; j--;
        }
    }
};

int main()
{
    string s = "a---b";
    Solution ss;
    s = ss.reverseOnlyLetters(s);
    cout << s << endl;

    return 0;
}