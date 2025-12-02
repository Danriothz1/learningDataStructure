#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

const int N = 5050;
int val[N];
int n;

inline int lc(int x){ return 2 * x + 1; }
inline int rc(int x){ return 2 * x + 2; }
inline int pa(int x){ return x % 2 ? x / 2 - 1 : x / 2; }

void preorder(void){
    stack<int> st;
    st.push(0);
    while(!st.empty()){
        int cur = st.top();
        st.pop();
        cout << val[cur] << " ";
        int l = lc(cur);
        int r = rc(cur);
        if (r < n) st.push(r);
        if (l < n) st.push(l);
    }
}

void inorder(void){
    stack<int> st;
    int cur = 0;
    while(!st.empty() || cur < n){
        while(cur < n){
            st.push(cur);
            cur = lc(cur);
        }
        cur = st.top();
        st.pop();
        cout << val[cur] << " ";
        cur = rc(cur);
    }
}

void postorder(void){
    stack<int> st;
    int cur = 0;
    int prev = n;
    while(!st.empty() || cur < n){
        while(cur < n){
            st.push(cur);
            cur = lc(cur);
        }
        int top = st.top();
        int r = rc(top);
        if (r >= n || r == prev){
            cout << val[top] << " ";
            st.pop();
            prev = top;
            cur = n;
        } else cur = r;
    }
}

int main(){
    cin >> n;
    for (int i = 0;i < n; i++) cin >> val[i];
    preorder();
    cout << endl;
    inorder();
    cout << endl;
    postorder();
    return 0;
}

