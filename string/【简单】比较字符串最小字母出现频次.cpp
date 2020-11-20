#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>que(queries.size(), 0);
        vector<int>wor(words.size(), 0);
        char min_char;
        for(int i = 0; i < max(queries.size(), words.size()); i++)
        {
            if(i < queries.size())
            {
                min_char = *min_element(queries[i].begin(), queries[i].end());
                for(char ch : queries[i]) if(min_char == ch) que[i]++;
            }
            if(i < words.size())
            {
                min_char = *min_element(words[i].begin(), words[i].end());
                for(char ch : words[i]) if(min_char == ch) wor[i]++;
            }
        }
        for(int i = 0; i < que.size(); i++)
        {
            int N = 0;
            for(int j = 0; j < wor.size(); j++)
                if(wor[j] > que[i]) N++;
            que[i] = N;
        }
        return que; 
    }
};

int main()
{
    return 0;
}