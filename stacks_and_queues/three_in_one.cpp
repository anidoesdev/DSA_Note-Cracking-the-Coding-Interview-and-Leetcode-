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
            if(isFull(stackNum)){
                return;
            }
            int index = getAvailableIndex();
            values[index] = value;
            next[index] = sizes[stackNum] == 0 ? -1 : getTopIndex(stackNum);
            previous[index] = -1;
            if(sizes[stackNum] != 0){
                previous[getTopIndex(stackNum)] = index;
            }
            sizes[stackNum]++;
        }
        int pop(int stackNum){
            if(isEmpty(stackNum)){
                return -1;
            }
            int topIndex = getTopIndex(stackNum);
            int value = values[topIndex];
            values[topIndex] = 0;
            if(previous[topIndex] != -1){
                next[previous[topIndex]] = next[topIndex];
            } else {
                sizes[stackNum]--;
            }
            if(next[topIndex] != -1){
                previous[next[topIndex]] = previous[topIndex];
            } else {
                sizes[stackNum]--;
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
            int offset = 0;
            for(int i = 0; i < stackNum; i++){
                offset += sizes[i];
            }
            int index = 0;
            while(index < values.size()){
                if(next[index] == -1){
                    break;
                }
                index = next[index];
            }
            return index;
        }
        bool isEmpty(int stackNum){
            return sizes[stackNum] == 0;
        }

        bool isFull(int stackNum){
            return false;
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
            values = new_values;
            next = new_next;
            previous = new_previous;
        }
        int getAvailableIndex(){
            if(top_index == values.size()){
                resize();
            }
            int index = top_index;
            top_index++;
            return index;
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