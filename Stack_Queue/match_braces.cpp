#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s1, res;
int tmp;
stack<char> conv, opt;
stack<int> opnd;

int main(){
    cin >> s1;
    for (int i = 0; i < s1.length(); i++){
	if (s1[i] >= '0' && s1[i] <= '9') res.push_back(s1[i]); 
	else{
		res.push_back(' ');
		if (s1[i] == '*'){
		    while (!conv.empty() && conv.top() == '*') {res.push_back(conv.top());res.push_back(' ');conv.pop();}
		    conv.push('*');
		}
		else if (s1[i] == '+'){
		    while (!conv.empty() && (conv.top() == '*' || conv.top() == '+')) {res.push_back(conv.top());res.push_back(' ');conv.pop();}
		    conv.push('+');
		}
		else if (s1[i] == ')'){
		    while (!conv.empty() && conv.top() != '(') {res.push_back(conv.top());res.push_back(' ');conv.pop();}
		    conv.pop();
		}
		else if (s1[i] == '(') conv.push('(');
	}
    }
    while (!conv.empty()) {res.push_back(' ');res.push_back(conv.top());conv.pop();}
    cout << res;
    return 0;
}
