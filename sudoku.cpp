
#include <iostream> 
using namespace std;

//input


void print_board(char board[9][9]){
    for (int i=0;i<9;i++){
    for (int j=0;j<9;j++) {
        cout << board[i][j];
    }
    cout <<"\n";
   }
}

bool check_row(char board[9][9],int i, char v){
    bool found=false;
    for(int j=0;j<9;j++){
        if(board[i][j]==v) {found=true; 
            
             break;}
    }
    return !found;
}

bool check_col(char board[9][9],int j, char v){
    bool found=false;
    for(int i=0;i<9;i++){
        if(board[i][j]==v) {
            found=true; 
            
            break;
        }
    }
    return !found;
}

bool check_square(char board[9][9],int n, char v){
    int i=(n/3)*3;
    int j=(n%3)*3;
    bool found=false;
    for(int di=0;di<3;di++){    
        for(int dj=0;dj<3;dj++){
        if(board[di+i][dj+j]==v) {
            found=true;            
            break;}
        } 
    }   
    return !found;
}
void solve(char board[9][9],int start) {
    if (start ==81){

        cout << "There is a solution \n";
        print_board(board);
        cout <<"\n\n";
    } else {
    int row=start/9;
    int col=start%9;
    if(board[row][col]==' '){
        //try all the valid values and then go to the next loc
        for (int v=1; v<10;v++){
                int n=(row/3)*3+(col/3);
                char vchar=v+'0';
               bool check= check_row(board,row,vchar) && check_col(board,col,vchar)  
               && check_square(board,n,vchar);
               if(!check) continue;
                //cout << " row" << row << " col " << col <<"\n";
                board[row][col]=vchar;//<<
                solve(board,start+1);
                board[row][col]= ' ';//<<
               
        }

    }
    else
        solve(board,start+1);
}


}
int main(){
    /*char board[9][9]={{ '5', '3', ' ', ' ', '7', ' ', ' ', ' ', ' ' },
        { '6', ' ', ' ', '1', '9', '5', ' ', ' ', ' ' },
        { ' ', '9', '8', ' ', ' ', ' ', ' ', '6', ' ' },
        { '8', ' ', ' ', ' ', '6', ' ', ' ', ' ', '3' },
        { '4', ' ', ' ', '8', ' ', '3', ' ', ' ', '1' },
        { '7', ' ', ' ', ' ', '2', ' ', ' ', ' ', '6' },
        { ' ', '6', ' ', ' ', ' ', ' ', '2', '8', ' ' },
        { ' ', ' ', ' ', '4', '1', '9', ' ', ' ', '5' },
        { ' ', ' ', ' ', ' ', '8', ' ', ' ', '7', '9' }
    };*/
char board[9][9]=
      {
        { ' ', ' ', ' ', '2', ' ', ' ', '7', '8', ' ' }, // row 0
        { ' ', '8', ' ', ' ', ' ', ' ', '1', ' ', ' ' }, // row 1
        { ' ', ' ', '1', '9', ' ', ' ', ' ', ' ', ' ' }, // row 2
        { ' ', ' ', '3', ' ', ' ', '5', ' ', ' ', ' ' }, // row 3
        { ' ', ' ', ' ', ' ', ' ', '7', '8', ' ', ' ' }, // row 4
        { ' ', '2', ' ', ' ', ' ', ' ', ' ', ' ', '9' }, // row 5
        { '8', ' ', ' ', '1', ' ', ' ', '5', '6', ' ' }, // row 6
        { ' ', '6', ' ', '3', ' ', ' ', ' ', '2', ' ' }, // row 7
        { ' ', ' ', ' ', ' ', ' ', '4', ' ', ' ', ' ' }  // row 8
    };
    print_board  (board);
    solve(board,0);



}