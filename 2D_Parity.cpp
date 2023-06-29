#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int k;
 cout<<"Enter the number of segments: ";
 cin>>k;
 //assuming 8 bit sequence and 4 segments
 int arr[k+1][9];
 for(int a=0;a<k;a++)
 {
    for(int b=0;b<8;b++)
    {arr[a][b]=0;}

 }
 for(int a=0;a<k;a++)
 {
    for(int b=0;b<8;b++)
    {cin>>arr[a][b];}

 }
 for(int a=0;a<k;a++)
 { 
    int check=0;
    for(int b=0;b<8;b++)
    {
        if(arr[a][b]==1){check++;}        
    }
    if(check%2==0){arr[a][8]=0;}
    else{arr[a][8]=1;}
    check=0;
 }
 for(int a=0;a<9;a++)
 {
    int check=0;
    for(int b=0;b<k;b++)
    {
        if(arr[b][a]==1){check++;}
    }
    if(check%2==0){arr[k][a]=0;}
    else{arr[k][a]=1;}
    check=0;
 }
 for(int a=0;a<(k+1);a++)
 {
    for(int b=0;b<9;b++)
    {
        cout<<arr[a][b];
    }
    cout<<": ";
 }

return 0;
}