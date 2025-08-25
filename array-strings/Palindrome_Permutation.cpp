#include <iostream>
#include <string>
#include <map>

using namespace std;

bool permutation_of_palindrome (string& str){
    map<char,int> mp;
    int n = str.length();
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        mp[ch]++;
    }
    int count = 0;
    for(auto& m:mp){
        if(n%2 == 0){
            if(m.second % 2 != 0){
                return false;
            }
        }else{
            if(m.second % 2 !=0){
                count++;
            }
            if(count > 1){
                return false;
            }
        }
    }
    return true;

}

int main(){
    
    string str = "tactcoa";
    cout<< permutation_of_palindrome(str);
    return 0;
}

