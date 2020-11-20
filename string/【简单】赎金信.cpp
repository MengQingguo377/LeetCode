#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>arr1('z'-'A'+1, 0);
        vector<int>arr2('z'-'A'+1, 0);
        for(int i = 0; i < max(ransomNote.size(), magazine.size()); i++)
        {
            if(i<ransomNote.size())
                arr1[ransomNote[i]-'a']++;   
            if(i<magazine.size())
                arr2[magazine[i]-'a']++;     
        }
        for(int i = 0; i <= 'z'-'A'; i++)
        {
            if(arr2[i] < arr1[i]) return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}