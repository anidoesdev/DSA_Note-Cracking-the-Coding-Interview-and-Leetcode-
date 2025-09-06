#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class multiStack{
    vector<stack<int>*> st;
    int capacity;
    int curr;
    public:
        multiStack(int capacity){
            curr = -1;
            capacity = capacity;
        }
        void push(int value){
            if(curr == -1 || st[curr]->size()==capacity){
                stack<int>* temp = new stack<int>;
                temp->push(value);
                st.push_back(temp);
                curr++;
                cout<<"new stack created"<<endl;
                return;
            }
            st[curr]->push(value);
        }
        int pop(){
            if(curr > -1){
                int res = -1;
                if(st[curr]->size()>0){
                    res = st[curr]->top();
                    st[curr]->pop();
                    if(st[curr]->size()==0){
                        st.pop_back();
                        curr--;
                        cout<<"stack deleted";
                    }
                    
                }
                return res;
            }
            return -1;
        }
    
};
int main(){
    multiStack super(5);
    super.push(1);
    super.push(2);
    super.push(3);
    super.push(4);
    super.push(5);
    super.push(6);
    super.push(7);
    cout<< super.pop();
    
    return 0;
}