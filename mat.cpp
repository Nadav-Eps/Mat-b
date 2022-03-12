#include <string>
#include <iostream>
#include <vector>
using namespace std;
const int low =33;
const int high =126;

namespace ariel {
   
    string mat(int col , int row , char sym1 , char sym2) {
        if(sym1<low||sym1>high){throw std::invalid_argument{"Invalid char"};}
        if(sym2<low||sym2>high){throw std::invalid_argument{"Invalid char"};}
        if(col%2==0||row%2==0){throw std::invalid_argument{"row and col must be odd numbers"};}
        if(col<0||row<0){throw std::invalid_argument{"row and col must be positive numbers"};}
        vector<vector<char>> ans(col,vector<char> (row, 'c'));
        int t_col=col;
        int t_row=row;
        int even =0;
        int count = 0;
        int tmp = min(row,col);
        while(tmp!=0){
            if(even%2==0){
              for (int i = count; i < t_col; i++)
            {
                ans[i][count]=sym1;
                ans[i][t_row-1]=sym1;
            }
            for (int i = count; i < t_row; i++)
            {
                ans[count][i]=sym1;
                ans[t_col-1][i]=sym1;
            }
            }
            else{
             for (int i = count; i < t_col; i++)
            {
                ans[i][count]=sym2;
                ans[i][t_row-1]=sym2;
            }
            for (int i = count; i < t_row; i++)
            {
                ans[count][i]=sym2;
                ans[t_col-1][i]=sym2;
            }
            }
            tmp--;
            t_col--;
            t_row--;
            count++;
            even++;
        }
        
        string finali;
        for (size_t i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                finali+=ans[j][i];
            }
            finali+="\n";
        }
        
        return  finali;
    }
}
