#include "mat.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace ariel {
    /*
    The function gets 2 int and 2 symbols and if the parameters are legal - the function
    return the carpet(representing by vector).
    The idea is to fill the matrix from outside in, like frames, starts from the outer frame.
    Outer Loop: Counts the number of frames to fill [min(row, col)/2].
    Inner loop: In each iteration we fill the frame(top and bottom rows,right and left column), 
    according to the frame in the outer loop. 
    @param cols 
    @param rows 
    @param sign1 
    @param sign2
    @return string 
     */
    string mat(int cols, int rows, char sign1, char sign2) {
        //Checking exceptions
        int const minChar = 33;
        int const maxChar = 126;
        if (sign1 < minChar || sign2 < minChar || sign1 > maxChar || sign2 > maxChar)
        {
            throw invalid_argument("unvalid symbol");
        }
        if(cols %2 == 0 || rows % 2 == 0){
            throw invalid_argument("Mat size is always odd");
        }
        if(cols < 0 || rows < 0){
            throw invalid_argument("Rows and columns size is not negative");
        }
        vector<vector<char>> matrix(rows, vector<char> (cols, sign1));

        int temp_row =0;
        int temp_col =0;
        char cur_sign = sign1;
        int iterations = min(rows,cols)/2 +1;
        //Fill the matrix from outside in
        for(int i_num = 0; i_num < iterations; i_num++)
        {
            temp_row = rows -2*i_num;
            temp_col = cols -2*i_num;
            for (int i = 0; i < temp_col; i++) {
                matrix[i_num][i + i_num] = cur_sign; //top row
                matrix[i_num + temp_row - 1][i + i_num] = cur_sign; //bottom row
            }
            for (int i = 0; i < temp_row; i++) {
                matrix[i + i_num][i_num] = cur_sign; //right column
                matrix[i + i_num][i_num + temp_col - 1] = cur_sign; //left column
            }
            //Change sign every frame
            cur_sign = (cur_sign == sign1) ? sign2 : sign1;
        }
        string ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans += matrix[i][j];
            }
            ans += '\n';
        }        
        return ans;
    }
}