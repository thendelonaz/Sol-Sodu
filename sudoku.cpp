#include<iostream>
#include<stack>
#include<vector>
#include<array>
using namespace std;

const int N = 9;

void printsol(int grid[N][N]){
    for ( int r = 0 ; r < N ; r++){
        for ( int c = 0 ; c < N ; c++){
            cout << grid[r][c];
            if (c < (N-1)){
                cout << " ";
            }
        }
        cout << endl;
    } 
}

bool canplace(int grid[N][N], int row, int col, int n){
    if (grid[row][col] != 0){return false;}
    bool status = true;
    int gridx = (col/3)*3;
    int gridy = (row/3)*3;
    for (int i = 0 ; i < N; i++){
        if ( grid[row][i]== n){status = false; break;}
        if ( grid[i][col]== n){status = false; break;}
        if ( grid[gridy+i/3][gridx + i%3]== n){status = false; break;}
    }
    return status;
}

bool solve(int grid[N][N]){
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++){
            if(grid[row][col] == 0){
                for(int num=1; num<=N; num++){
                    if(canplace(grid, row, col, num)){
                        grid[row][col] = num;
                        if(solve(grid)){
                            return true;
                        }
                        else{
                            grid[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){

    int Grid[N][N]={
        {0,4,0,0,0,0,1,7,9},
        {0,0,2,0,0,8,0,5,4},            
        {0,0,6,0,0,5,0,0,8},
        {0,8,0,0,7,0,9,1,0},
        {0,5,0,0,9,0,0,3,0},
        {0,1,9,0,6,0,0,4,0},
        {3,0,0,4,0,0,7,0,0},
        {5,7,0,1,0,0,2,0,0},
        {9,2,8,0,0,0,0,6,0} 
    };
    
    if (solve(Grid)){
        printsol(Grid);
    }
    else {
        cout<< "No Solution"<< endl;
    }
    
    return 0;
}