#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int> >& moves) {
        if(moves.size() < 5) return "Pending";
        short qp[3][3];
        fill(qp[0], qp[2] + 3, 0);
        int a = 0, b = 0;
        for(int i = 0; i < moves.size(); i++)
            qp[moves[i][0]][moves[i][1]] = (i & 1) ? -1 : 1;
        // -1是B 1是A
        int sum_row, sum_col;
        for(int i = 0; i < 3; i++)
        {
            sum_row = qp[i][0] + qp[i][1] + qp[i][2];
            sum_col = qp[0][i] + qp[1][i] + qp[2][i];
            if(sum_row == 3 || sum_col == 3)
                return "A";
            if(sum_row == -3 || sum_col == -3)
                return "B";
        }
        sum_row = qp[0][0] + qp[1][1] + qp[2][2];
        sum_col = qp[0][2] + qp[1][1] + qp[2][0];
        if(sum_row == 3 || sum_col == 3)
            return "A";
        if(sum_row == -3 || sum_col == -3)
            return "B";
        if(moves.size() == 9) return "Draw";
        else return "Pending";
    }
};

int main()
{

    return 0;
}