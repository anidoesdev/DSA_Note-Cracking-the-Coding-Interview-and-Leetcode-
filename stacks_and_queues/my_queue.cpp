#include<iostream>
#include<stack>

using namespace std;
class MyQueue{
    stack<int>* st1;
    stack<int>* st2;
    void shiftStack(){
            if(st2->empty()){
                while(!st1->empty()){
                    st2->push(st1->top());
                    st1->pop();
                }
            }
    }
    public:
        MyQueue(){
            st1 = new stack<int>;
            st2 = new stack<int>;
        }
        void push(int value){
            st1->push(value);
        }
        int peek(){
            shiftStack();
            return st2->top();
        }
        int remove(){
            shiftStack();
            int value = st2->top();
            st2->pop();
            return value;
        }
};


int main(){
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    cout<< queue.peek()<<endl;
    queue.remove();
    cout<< queue.peek();

    return 0;
}