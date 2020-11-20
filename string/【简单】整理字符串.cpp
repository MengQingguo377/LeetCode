#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string ss;
        while(true)
        {
            if(s.empty()) return s;
            bool f = true;
            int j = 0;
            ss = "";
            for(int i = 0; i < s.size()-1; i++)
            {
                if(abs(s[i] - s[i+1]) == abs('a' - 'A'))
                {
                    f = false;
                    ss += s.substr(j, i-j);
                    j = i + 2;
                    i++;
                }
            }

            if(f) return s;
            s = ss + s.substr(j);
        }
    }
};

int main()
{
    Solution s;
    cout << s.makeGood("leEeetcode") << endl;
    return 0;
}