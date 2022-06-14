#include <bits/stdc++.h>
using namespace std;

class Nqueen {
    int board[100][100],n;
    public:
    Nqueen(int m){
        n=m;        
    }
    void printSol() {
        cout<<"Solution : \n";
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++)
                cout<<board[i][j]<<" ";
            cout<<endl;
        }
    }
    bool isSafe(int row,int col) {
        for(int i=0;i<col;i++) 
            if(board[row][i]==1)
                return false;
        for(int i=row,j=col;i>=0 && j>=0;i--,j--) 
            if(board[i][j]==1)
                return false;
        for(int i=row,j=col;i<n && j>=0;i++,j--)
            if(board[i][j]==1)
                return false;
        
        return true;
    }

    void nqueen(int col) {
        
        if(col>=n){
            printSol();
            return;
        }
        for(int i=0;i<n;i++) {

            if(isSafe(i,col)) {
                board[i][col]=1;
                nqueen(col+1);
                board[i][col]=0;
            }

        }

    }

};

int main() {
    int n;
    cout<<"Enter size of board : ";
    cin>>n;
    Nqueen ob(n);    
    ob.nqueen(0);
    return 0;
}