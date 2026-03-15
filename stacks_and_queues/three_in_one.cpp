```cpp
#include<iostream>
#include<vector>
using namespace std;

class flexibleMultiStack {
    private:
        int number_of_stack = 3;
        vector<int> values;
        vector<int> sizes;
        vector<int> next;
        vector<int> previous;
        int top_index = 0;
    public:
        flexibleMultiStack(){
            values.resize(10);
            sizes.resize(number_of_stack);
            next.resize(10);
            previous.resize(10);
            for(int i = 0; i < 10; i++){
                next[i] = i + 1;
            }
            next[9] = -1;
            for(int i = 0; i < 10; i++){
                previous[i] = i - 1;
            }
            previous[0] = -1;
        }
        void push(int value,int stackNum){
            if(top_index == values.size()){
                resize();
            }
            if(isEmpty(stackNum)){
                int index = getAvailableIndex();
                values[index] = value;
                sizes[stackNum] = 1;
                next[index] = -1;
                previous[index] = -1;
            } else {
                int index = getAvailableIndex();
                values[index] = value;
                sizes[stackNum]++;
                int topIndex = getTopIndex(stackNum);
                next[index] = -1;
                previous[index] = topIndex;
                next[topIndex] = index;
            }
        }
        int pop(int stackNum){
            if(isEmpty(stackNum)){
                return -1;
            }
            int topIndex = getTopIndex(stackNum);
            int value = values[topIndex];
            values[topIndex] = 0;
            sizes[stackNum]--;
            if(sizes[stackNum] == 0){
                next[top_index] = -1;
                previous[top_index] = -1;
            } else {
                int newTopIndex = previous[topIndex];
                next[newTopIndex] = -1;
                previous[topIndex] = -1;
            }
            return value;
        }
        int top(int stackNum){
            if(isEmpty(stackNum)){
                return -1;
            }
            return values[getTopIndex(stackNum)];
        }
        int getTopIndex(int stackNum){
            for(int i = 0; i < values.size(); i++){
                if(values[i] != 0 && previous[i] == -1 && next[i] != -1){
                    return i;
                }
            }
            return -1;
        }
        bool isEmpty(int stackNum){
            return sizes[stackNum] == 0;
        }
        void resize(){
            vector<int> new_values(values.size() * 2);
            vector<int> new_next(next.size() * 2);
            vector<int> new_previous(previous.size() * 2);
            for(int i = 0; i < values.size(); i++){
                new_values[i] = values[i];
                new_next[i] = next[i];
                new_previous[i] = previous[i];
            }
            for(int i = values.size(); i < new_values.size(); i++){
                new_next[i] = i + 1;
            }
            new_next[new_values.size() - 1] = -1;
            for(int i = values.size(); i < new_values.size(); i++){
                new_previous[i] = i - 1;
            }
            new_previous[values.size()] = -1;
            values = new_values;
            next = new_next;
            previous = new_previous;
        }
        int getAvailableIndex(){
            for(int i = 0; i < values.size(); i++){
                if(values[i] == 0){
                    return i;
                }
            }
            resize();
            return values.size() - 1;
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