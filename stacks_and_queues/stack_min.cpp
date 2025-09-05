#include<iostream>
#include<stack>

using namespace std;

class stack_min{
    stack<int> st1;
    stack<int> st2;
    public:
        void push(int value){
            if(value<=min()){
                st2.push(value);
            }
            st1.push(value);
        }
        int pop(){
            if(st1.empty()){
                return -1;
            }
            int value = st1.top();
            st1.pop();
            if(value == min()){
                st2.pop();
            }
            return value;
        }
        int min(){
            if(st2.empty()){
                return INT_MAX;
            }
            return st2.top();
        }
};

int main(){
    stack_min super;
    super.push(2);
    super.push(1);
    super.push(4);
    super.push(10);
    super.push(11);
    cout<< super.min()<<endl;
    cout<< super.pop()<<endl;
    cout<< super.min();
    


    return 0;
}