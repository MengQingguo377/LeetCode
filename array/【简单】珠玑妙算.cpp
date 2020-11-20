#include<iostream>
#include<string>
#include<set>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        unordered_map<char, int>mp;
        int correct = 0, false_correct = 0;
        for(int i = 0; i < guess.length(); i++)
        {
            if(solution[i] == guess[i]) correct++;
            else mp[solution[i]]++;
        }
        for(int i = 0; i < guess.length(); i++)
        {
            if(solution[i]!=guess[i] && mp[guess[i]]>0)
            {
                false_correct++;
                mp[guess[i]]--;
            }      
        }
        return {correct, false_correct};
    }
};

int main()
{
    Solution s;
    vector<int>arr(2);
    arr = s.masterMind("BGBG", "RGBR");
    cout << arr[0] << " " << arr[1] << endl;
    return 0;
}