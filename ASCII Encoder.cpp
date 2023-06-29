#include <iostream>

using namespace std;

int main()
{
    int num;
    string str;
    cout<<" ASCII Encoder String: ";
    cin>>str;
    int len=str.length();
    char ch;
    for(int a =0;a<len;a++)
    {
        ch=str[a];
        num=(int)ch;
        int temp[8];
        for(int b=0;b<8;b++)
        {
            temp[7-b]=num%2;
            num=num/2;
        }
        for(int c=0;c<8;c++)
        {
            cout<<temp[c];
        }
        cout<<" ";
    }
    return 0;
}