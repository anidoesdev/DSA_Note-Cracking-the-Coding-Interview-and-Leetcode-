#include <iostream>
#include <string>
#include <vector>

using namespace std;

void URLify (string& str,int n){
    int space_count = 0;
    for(int i=0;i<n;i++){
        if(str[i] == ' '){
            space_count++;
        }
    }
    int index = n + space_count*2;
    if(n < str.length()) str[n] = '\0';
    for(int i = n-1;i>=0;i--){
        if(str[i] == ' '){
            str[index-1] = '0';
            str[index - 2] = '2';
            str[index-3] = '%';
            index = index - 3;
        }else{
            str[index - 1] = str[i];
            index = index - 1;
        }
    }
}


int main() {
    string str = "Mr John Smith    ";
    int n = 13;

    URLify(str,n);

    cout<< str;

    return 0;
}