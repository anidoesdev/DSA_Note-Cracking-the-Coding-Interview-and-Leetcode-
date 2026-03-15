```cpp
#include<iostream>
#include<vector>
using namespace std;

class flexibleMultiStack {
    private:
        int number_of_stack = 3;
        vector<int> values;
        vector<int> sizes;
        vector<int> start_index;
    public:
        flexibleMultiStack(){
            values.resize(10);
            sizes.resize(number_of_stack);
            start_index.resize(number_of_stack);
            for(int i = 0; i < number_of_stack; i++) {
                start_index[i] = i;
            }
        }
        void push(int value,int stackNum){
            if(sizes[stackNum] == 0) {
                start_index[stackNum] = values.size();
                values.push_back(value);
                sizes[stackNum]++;
            } else {
                if(start_index[stackNum] + sizes[stackNum] == values.size()) {
                    values.push_back(value);
                } else {
                    values[start_index[stackNum] + sizes[stackNum]] = value;
                }
                sizes[stackNum]++;
            }
            if(values.size() == start_index[stackNum] + sizes[stackNum]) {
                values.resize(values.size() * 2);
            }
        }
        int pop(int stackNum){
            if(isEmpty(stackNum)){
                return -1;
            }
            int topIndex = start_index[stackNum] + sizes[stackNum] - 1;
            int value = values[topIndex];
            values[topIndex] = 0;
            sizes[stackNum]--;
            return value;
        }
        int top(int stackNum){
            if(isEmpty(stackNum)){
                return -1;
            }
            return values[start_index[stackNum] + sizes[stackNum] - 1];
        }
        bool isEmpty(int stackNum){
            return sizes[stackNum] == 0;
        }

};

int main(){
    flexibleMultiStack st;
    st.push(5,1);
    st.push(6,1);
    st.push(1,1);
    st.push(3,1);
    st.push(4,1);
    st.push(10,2);
    cout<< st.pop(1)<<endl;
    cout<< st.pop(2)<<endl;
    cout<< st.top(2)<<endl;
    cout<<st.top(1);

    return 0;
}
```