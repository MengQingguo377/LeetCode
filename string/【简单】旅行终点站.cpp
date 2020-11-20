#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string>city_map;
        for(int i = 0; i < paths.size(); i++)
        {
            city_map[paths[i][0]] = paths[i][1];
        }
        string outset = paths[0][0];
        while(city_map.find(outset) != city_map.end())
            outset = city_map[outset];
        return outset;
    }   
};

int main()
{
    return 0;
}