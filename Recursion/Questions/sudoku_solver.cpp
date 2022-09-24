#include <iostream>

#include <vector>

using namespace std;

bool check_pos(vector<vector< char >> &sudoku, int r, int c, char ch) {
    for(int i=0;i<9;i++){
        if(sudoku[i][c]==ch)
            return false;

        if(sudoku[r][i]==ch)
            return false;

        if(sudoku[3*(r/3)+i/3][3*(c/3)+i%3]==ch)
            return false;
    }
    return true;
}

bool solveSudoku(vector < vector < char >> & board) {
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='.'){
                for(char ch='1';ch<='9';ch++){
                    if(check_pos(board,i,j,ch)){
                        board[i][j]=ch;
                        if(solveSudoku(board))
                            return true;
                        else 
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
   
    solveSudoku(board);
        	
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
            cout<<"\n";
    }
    return 0;
}