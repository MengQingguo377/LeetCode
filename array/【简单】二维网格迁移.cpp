#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(grid.empty()) return grid;
        int m = grid.size(); // è¡Œæ•°
        int n = grid[0].size(); // åˆ—æ•°
        vector<int>tmp(m);
        while(k--)
        {
            for(int i = 0; i < m; i++)
                tmp[i] = grid[i][n - 1];
            for(int i = n - 2; i >= 0; i--)
            {
                for(int j = 0; j < m; j++)
                {
                    grid[j][i + 1] = grid[j][i];
                }
            }
            for(int i = 1; i < m; i++)
            {
                grid[i][0] = tmp[i - 1];
            }
            grid[0][0] = tmp[m - 1];
        }
        return grid;
    }
};

class Solution1 { 
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(grid.empty()) return grid;
        int m = grid.size(), n = grid[0].size();
        int N = m * n; // gridÔªËØ×ÜÊý
        k %= N;
        vector<vector<int> >arr(m, vector<int>(n));
        int row1, col1;
        int row2, col2;
        for(int i = 0; i < N; i++)
        {
            row1 = i / n; col1 = i - row1 * n;
            row2 = ((i + k) % N) / n; col2 = ((i + k) % N) - row2 * n;
            arr[row2][col2] = grid[row1][col1];
        }
        return arr;
    }
};

int main()
{

    return 0;
}
