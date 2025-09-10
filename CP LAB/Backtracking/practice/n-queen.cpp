#include<bits/stdc++.h>
using namespace std;  
bool isSafe(vector<int>&board,int row ,int col)
{
    for(int r=0;r<row;r++)
    {
        int c = board[r];
        if(c == col || abs(c-col) == abs(r-row))
        return false ;
    }
    return true ;
}

void queenSolve(vector<int>&board,int row, int n)
{
    if(row == n)
    {
        cout<<"[ ";
        for(int i=0;i<n;i++)cout<<board[i]+1<<" ";
        cout<<"]"<<endl;
    }
   for(int col = 0 ; col < n ; col++)
   {
    if(isSafe(board,row,col))
    {
        board[row] = col ;
        queenSolve(board,row+1,n);
        board[row]=-1;
    }
   }
}  
int main()
{
    int n;
    cout<<"Enter queen :"<<endl;
    cin>>n;
    vector<int>board(n,-1);
    queenSolve(board,0,n);
}