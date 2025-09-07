#include<iostream>
#include<stack>

using namespace std;

stack<int> sort_stack(stack<int> st){
    stack<int> sort;
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        while(!sort.empty() && sort.top() > temp){

            st.push(sort.top());
            sort.pop();
        }
        sort.push(temp);
    }
    while (!sort.empty())
    {
        st.push(sort.top());
        sort.pop();
    }
    return st;
    
}
void print_stack(stack<int>* st){
    while(!st->empty()){
        cout<< st->top()<<endl;
        st->pop();
    }
}

int main(){
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(6);

    
    st = sort_stack(st);
    print_stack(&st);

    



    return 0;
}