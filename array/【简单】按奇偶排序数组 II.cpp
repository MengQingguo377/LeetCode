#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int odd = 1, even = 0;
        while(odd < A.size() && even < A.size())
        {
            if(!(A[odd] & 1) && (A[even] & 1))
            {
                swap(A[odd], A[even]);
                odd += 2; even += 2;
            }
            else
            {
                if(A[odd] & 1) odd += 2;
                if(!(A[even] & 1)) even += 2;
            }
        }
        return A;
    }
};

int main()
{
    return 0;
}