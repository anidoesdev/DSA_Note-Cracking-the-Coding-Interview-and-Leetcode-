//Approach 1: Fixed divisions
//have to complete it with second approach: flexible divisions
#include<iostream>
#include<vector>
using namespace std;

class fixedMultiStack {
    private:
        int number_of_stack = 3;
        int stack_capacity;
        vector<int> values;
        vector<int> sizes;
    public:
        fixedMultiStack(int stackSize){
            stack_capacity = stackSize;
            values.resize(stackSize*number_of_stack);
            sizes.resize(number_of_stack);
        }
        void push(int value,int stackNum){
            if(isFull(stackNum)){
                return;
            }
            sizes[stackNum]++;
            values[indexofTop(stackNum)] = value;
        }
        int pop(int stackNum){
            if(isEmpty(stackNum)){
                return -1;
            }
            int topIndex = indexofTop(stackNum);
            int value = values[topIndex];
            values[topIndex] = 0;
            sizes[stackNum]--;
            return value;
        }
        int top(int stackNum){
            if(isEmpty(stackNum)){
                return -1;
            }
            return values[indexofTop(stackNum)];
        }
        int indexofTop(int stackNum){
            int offset = stackNum * stack_capacity;
            int size = sizes[stackNum];
            return offset + size - 1;
        }
        bool isEmpty(int stackNum){
            return sizes[stackNum] == 0;
        }

        bool isFull(int stackNum){
            return sizes[stackNum] == stack_capacity;
        }
    
    

};

int main(){
    fixedMultiStack st(5);
    st.push(5,1);
    st.push(6,1);
    st.push(1,1);
    st.push(3,1);
    st.push(4,1);
    st.push(10,2);
    cout<< st.pop(1)<<endl;
    // cout<< st.pop(2)<<endl;
    cout<< st.top(2)<<endl;
    cout<<st.top(1);

    return 0;
}