#include<iostream>
using namespace std;
 int grid[10][10];
 
 void print( int n )
 {
     for(int i=0;i<=n-1;i++)
     {
         for(int j=0;j<=n-1;j++)
         {
            cout<< grid[i][j]<<" ";
         }
         cout<<endl;
     }
     cout<<endl;
     cout<<endl;
 }
 
 bool issafe(int col,int row, int n)
 {
     //col
     for(int i=0;i<row;i++)
     {
         if(grid[i][col])
         {
             
             return false;
         }
     }
     //left
     for(int i =row,j=col;i>=0&&j>=0;i--,j--)
     {
         if(grid[i][j])
         {
             return false;
         }
     }
      for(int i =row,j=col;i>=0&&j<n;i--,j++)
     {
         if(grid[i][j])
         {
             return false;
         }
     }
     
    return true; 
 }
 
 bool solve(int n,int row)
 {
     if(n==row)
     {
         print(n);
         return true;
     }
     
     bool res=false;
 
     for(int i=0;i<=n-1;i++){
         if(issafe(i,row,n))
         {
             grid[row][i]=1;
             res=solve(n,row+1)||res;
             grid[row][i]=0;
             
         }
         
     }
         return res;
     }
     
     int main()
     {
         int n;
          cout<<"no of queens"<<endl;
            cin>>n;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    
                    grid[i][j]=0;
                }
            }
         
        bool res=solve(n,0);
        if(res==false)
        {
            
            cout<<-1;
        }
        else
        {
            cout<<endl;
        }
        return 0;
     }
 
