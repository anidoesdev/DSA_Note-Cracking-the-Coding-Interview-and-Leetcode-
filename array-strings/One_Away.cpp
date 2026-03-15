```cpp
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool one_away(string& str1, string& str2){
    if(abs(static_cast<int>(str1.length()) - static_cast<int>(str2.length())) > 1) return false;
    int count = 0;
    string first = str1.length() < str2.length() ? str1 : str2;
    string second = str1.length() < str2.length() ? str2 : str1;
    
    int i = 0;
    int j = 0;
    while(i<first.length() && j<second.length()){
        if(first[i]!=second[j]){
            if(count >= 1) return false;
            count++;
            if(first.length() == second.length()){
                i++;
                j++;
            }else{
                j++;
            }
        }else{
            i++;
            j++;
        }
    }
    if(j < second.length()) count++;
    return count <= 1;
}


int main(){
    string str1 = "pale";
    string str2 = "pal";

    cout<< one_away(str1,str2);

    return 0;
}
```