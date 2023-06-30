#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bitset>
using namespace std;
string xor1(string a, string b){
string result = "";
int n = b.length();
for(int i = 1; i<n; i++){
if(a[i] == b[i])
result += "0";
else
result += "1";
}
return result;
}
string mod2div(string dividend, string divisor){
int pick = divisor.length();
string tmp = dividend.substr(0, pick);
int n = dividend.length();
while(pick<n){
if(tmp[0] == '1'){
tmp = xor1(divisor, tmp) + dividend[pick];
}
else
tmp = xor1(std::string(pick, '0'), tmp)+ dividend[pick];
pick += 1;
}
if(tmp[0] == '1'){
tmp = xor1(divisor, tmp);
}
else
tmp = xor1(std::string(pick, '0'), tmp);
return tmp;
}
string crc(string data, string key){
int l_key = key.length();
string appended_data = (data + std::string(l_key - 1, '0'));
string remainder = mod2div(appended_data, key);
return remainder;
}
int main(){
string data;
cout<<"Enter the data: ";
getline(cin, data);
string start_field = "01111110";
string control_field = "00000111";
string address = "01010101";
string encode_key = "1101";
string trans_data = start_field+address+control_field;
for(int i = 0; i < data.size(); i++){
trans_data += bitset<8>(data[i]).to_string();
}
trans_data += crc(data, encode_key) + "01111110";
cout<<"Transmitted data: "<<trans_data<<endl;
return 0;
}