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
        vector<int> free;
        int capacity;
    public:
        flexibleMultiStack(int initialCapacity){
            capacity = initialCapacity;
            values.resize(capacity);
            sizes.resize(number_of_stack);
            next.resize(capacity);
            previous.resize(capacity);
            free.resize(capacity);
            for(int i = 0; i < capacity; i++){
                free[i] = i;
            }
        }
        void push(int value,int stackNum){
            if(free.empty()){
                resize();
            }
            int index = free.back();
            free.pop_back();
            values[index] = value;
            if(sizes[stackNum] == 0){
                next[index] = -1;
                previous[index] = -1;
            }else{
                next[index] = next[previous[indexofTop(stackNum)]];
                previous[index] = indexofTop(stackNum);
                if(next[indexofTop(stackNum)] != -1){
                    previous[next[indexofTop(stackNum)]] = index;
                }
                next[indexofTop(stackNum)] = index;
            }
            sizes[stackNum]++;
        }
        int pop(int stackNum){
            if(isEmpty(stackNum)){
                return -1;
            }
            int topIndex = indexofTop(stackNum);
            int value = values[topIndex];
            values[topIndex] = 0;
            free.push_back(topIndex);
            if(next[topIndex] != -1){
                previous[next[topIndex]] = previous[topIndex];
            }else{
                next[previous[topIndex]] = -1;
            }
            if(previous[topIndex] != -1){
                next[previous[topIndex]] = next[topIndex];
            }else{
                previous[next[topIndex]] = -1;
            }
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
            int offset = 0;
            for(int i = 0; i < stackNum; i++){
                offset += sizes[i];
            }
            return offset;
        }
        bool isEmpty(int stackNum){
            return sizes[stackNum] == 0;
        }
        void resize(){
            capacity *= 2;
            values.resize(capacity);
            next.resize(capacity);
            previous.resize(capacity);
            free.resize(capacity);
            for(int i = values.size() / 2; i < capacity; i++){
                free.push_back(i);
            }
        }
};

int main(){
    flexibleMultiStack st(5);
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