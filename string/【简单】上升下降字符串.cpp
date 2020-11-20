#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
   
class Solution {
public:
    string sortString(string s) {
        unordered_map<char, int>ch_cnt;
        string ss = s, s_set = "", s_rnt;
        sort(ss.begin(), ss.end());
        for(char ch : ss) if(!ch_cnt[ch]++) s_set += ch;
        while(true)
        {
            for(char ch : s_set)
            {
                if(ch_cnt[ch]) // 该字符没有被选完
                {
                    s_rnt += ch; ch_cnt[ch]--;
                    if(s.size() == s_rnt.size()) return s_rnt;
                }
            }
            for(int i = s_set.size() - 1; i >= 0; i--)
            {
                if(ch_cnt[s_set[i]])
                {
                    s_rnt += s_set[i]; ch_cnt[s_set[i]]--;
                    if(s.size() == s_rnt.size()) return s_rnt;
                }
            }
        }
    }
};

int main()
{
    return 0;
}
