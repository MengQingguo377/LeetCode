#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<vector<int> > flipAndInvertImage(vector<vector<int> >& A) {
        int a, b, tmp;
        for(int i = 0; i < A.size(); i++)
        {
            a = 0; b = A[i].size() - 1;
            while(a < b)
            {
                swap(A[i][a], A[i][b]);
                // tmp = A[i][a]; A[i][a] = A[i][b]; A[i][b] = tmp; // 交换a b位置的元素
                A[i][a] = !A[i][a];
                A[i][b] = !A[i][b];
                a++; b--;
            }
            if(a == b) A[i][a] = !A[i][a];
        }
        return A;
    }
};

int main()
{
    int a = !0;
    cout << a;
    return 0;
}