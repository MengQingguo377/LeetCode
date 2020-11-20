#include<iostream>
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int>chars_count;
        unordered_map<char, int>words_count;
        for(char ch : chars) // 统计chars中的词频
            chars_count[ch]++;
        int ans = 0;
        for(int i = 0; i < words.size(); i++)
        {
            for(char ch : words[i]) // 统计words[i]中的词频
                words_count[ch]++;
            bool f = true;
            for(int j = 0; j < words[i].size(); j++)
            {
                if(words_count[words[i][j]] > chars_count[words[i][j]])  // chars中对应字符数量不足以拼写该单词
                { f = false; break; }
            }
            if(f) ans += words[i].length();
            words_count.clear(); // 清空映射表
        }
        return ans;
    }
};

int main()
{

    return 0;
}