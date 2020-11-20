#include<iostream>
#include<set>
#include<string>
using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size()==0 || A.size()==1 || A.size()!=B.size()) 
            return false;

        int a = -1, b = -1;
        set<char>myset;
        bool f = false;
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] == B[i])
            {
                if(myset.find(A[i]) != myset.end()) f = true;
                else myset.insert(A[i]);
            }
            if(A[i] != B[i])
            {
                if(a!=-1 && b!=-1) return false;
                if(a != -1) b = i;
                else a = i;
            }
        }
        if(a==-1) // A B字符串相等
            return f;
        if(A[a] == B[b] && A[b] == B[a]) return true;
        return false;
    }
};

int main()
{
    return 0;
}