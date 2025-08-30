#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool is_rotation(string& s1, string& s2){
    int len = s1.length();
    if(len == s2.length() && len>0){
        string str = s1 + s1;
        return str.find(s2);
    }
    return false;

}

int main(){

    string s1 = "waterbottle";
    string s2 = "erbottlewat";

    cout<< is_rotation(s1,s2);

    return 0;
}