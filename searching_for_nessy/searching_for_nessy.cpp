#include<iostream>  
using namespace std;
int main()
{
    int row,col,test,i;
    cin>>test;
    for(i=0;i<test;i++){
     cin>>row>>col;
     cout<<(row/3)*(col/3);
 
    }
  return 0;
}