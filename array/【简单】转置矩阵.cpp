#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > transpose(vector<vector<int> >& A) {
        if(A.empty()) return {};
        vector<vector<int> >arr(A[0].size(), vector<int>(A.size()));
        for(int i = 0; i < A.size(); i++)
            for(int j = 0; j < A[0].size(); j++)
                arr[j][i] = A[i][j];
        return arr;
    }
};

int main()
{
    return 0;
}