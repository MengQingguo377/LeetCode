#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        // string s;
        // if(n & 1) s = string(n, 'a');
        // else
        //     s = string(n-1, 'a') + 'b'; 
        // return s;
        return (n & 1) ? string(n, 'a') : string(n-1, 'a') + 'b';
    }
};

int main()
{
    return 0;
}