#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int i, j, k;
        int cnt = 0;
        for(i = 0; i < arr.size(); i++)
        {
            for(j = i + 1; j < arr.size(); j++)
            {
                if(abs(arr[i] - arr[j]) <= a)
                {
                    for(k = j + 1; k < arr.size(); k++)
                        if(abs(arr[j] - arr[k]) <= b && abs(arr[k] - arr[i]) <= c)
                            cnt++;
                }
            }
        }
        return cnt;
    }
};

int main()
{

    return 0;
}