#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

stack<int> s1, s2;
queue<int> q;

int main(){
    int n,k;
    cin >> n;
    for (int i = 0; i < n; ++i){
	cin >> k;
	s2.push(k);
    }
    for (int j = 0; j < n; ++j){
         cin >> k;
	 q.push(k);
	 s1.push(s2.top());
	 s2.pop();
    }
    while (!q.empty()){
	if (!s2.empty() && s2.top() == q.front()){
	    s2.pop();
	    q.pop();
	}
	else if (!s1.empty()){
            s2.push(s1.top());
	    s1.pop();
	} else
	{
	    cout << "No";
	    return 0;
	}
    }
    cout << "Yes";
    return 0;
}
    
    



