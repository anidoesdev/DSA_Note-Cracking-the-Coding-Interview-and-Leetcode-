//aabcccccddd would become a2b1c5d3
#include <iostream>
#include <map>
#include <string>

using namespace std;

string compression(string& str){
    map<char,int> mp;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        mp[ch]++;
    }
    string res = "";
    for(auto& ch:mp){
        res+=ch.first;
        res+=to_string(ch.second);
    }
    return res;
}

int main(){
    string str = "aabcccdd";

    cout<< compression(str);

    return 0;
}