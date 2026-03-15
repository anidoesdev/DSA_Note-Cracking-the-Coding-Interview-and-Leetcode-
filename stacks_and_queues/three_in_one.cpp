```cpp
#include<iostream>
#include<vector>
using namespace std;

class flexibleMultiStack {
    private:
        vector<vector<int>> stacks;
    public:
        flexibleMultiStack(int number_of_stack){
            for(int i = 0; i < number_of_stack; i++){
                vector<int> stack;
                stacks.push_back(stack);
            }
        }
        void push(int value,int stackNum){
            if(stackNum < 0 || stackNum >= stacks.size()){
                return;
            }
            stacks[stackNum].push_back(value);
        }
        int pop(int stackNum){
            if(stackNum < 0 || stackNum >= stacks.size()){
                return -1;
            }
            if(stacks[stackNum].empty()){
                return -1;
            }
            int value = stacks[stackNum].back();
            stacks[stackNum].pop_back();
            return value;
        }
        int top(int stackNum){
            if(stackNum < 0 || stackNum >= stacks.size()){
                return -1;
            }
            if(stacks[stackNum].empty()){
                return -1;
            }
            return stacks[stackNum].back();
        }
        bool isEmpty(int stackNum){
            if(stackNum < 0 || stackNum >= stacks.size()){
                return true;
            }
            return stacks[stackNum].empty();
        }

};

int main(){
    flexibleMultiStack st(3);
    st.push(5,0);
    st.push(6,0);
    st.push(1,0);
    st.push(3,0);
    st.push(4,0);
    st.push(10,1);
    cout<< st.pop(0)<<endl;
    cout<< st.top(1)<<endl;
    cout<<st.top(0);

    return 0;
}
```