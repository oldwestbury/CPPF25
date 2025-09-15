
#include <iostream> 
using namespace std;


//input
char board[9][9];


bool check_row(int i, char v){
    bool found=false;
    for(int j=0;j<9;j++){
        if(board[i][j]==v) found=true; break;
    }
    return !found;
}

bool check_col(int j, char v){
    bool found=false;
    for(int i=0;i<9;j++){
        if(board[i][j]==v) found=true; break;
    }
    return !found;
}

bool check_square(int n, char v){
    int i=(n/3)*3;
    int j=(n%3)*3;
    bool found=false;
    for(int di=0;di<3;di++){    
        for(int dj=0;dj<3;dj++){
        if(board[i+di][j+dj]==v) found=true; break;
        } 
    }   
    return !found;
}

int solve(int start) {
    if (start ==81){

        cout << "There is a solution \n";
    } else {
    int row=start/9;
    int col=start%9;
    if(board[row][col]==' '){
        //try all the valid values and then go to the next loc
        for (int v=1; v<10;v++){
                int n=(row/3 )*3+(col%3);
               bool check= check_row(row,v) && check_col(col,v  )  && check_square(n,v);
               if(!check)continue;
                board[row][col]=v+'0';//<<
                solve(start+1);
                board[row][col]= ' ';//<<
        }

    }
    solve(start+1);
}


}