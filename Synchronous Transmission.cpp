#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bitset>
using namespace std;
string receiver(string input){
string output;
for(int i = 0; i < input.length(); i += 8){
bitset<8> bits(input.substr(i, 8));
output += char(bits.to_ulong());
}
return output;
}
int main(){
string data;
cout<<"Enter the data: ";
getline(cin, data);
string str1 = "01111110";
string str2 = "00000111";
string trans_data = str1 + str2;
for(int i = 0; i < data.size(); i++){
trans_data += bitset<8>(data[i]).to_string();
}
trans_data += "01111110";
cout<<"Transmitted data: "<<trans_data<<endl;
cout<<"Received data: "<<receiver(trans_data)<<endl;
return 0;
