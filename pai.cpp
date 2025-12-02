#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

string s1, res;
stack<char> conv;
stack<int> nums;

int main(){
    cin >> s1;
    for (int i = 0; i < s1.length(); i++){
        if (s1[i] >= '0' && s1[i] <= '9') {
            res.push_back(s1[i]);
        } else {
            if (!res.empty() && res.back() != ' ') {
                res.push_back(' ');
            }
            
            if (s1[i] == '*'){
                while (!conv.empty() && conv.top() == '*') {
                    res.push_back(conv.top());
                    res.push_back(' ');
                    conv.pop();
                }
                conv.push('*');
            }
            else if (s1[i] == '+'){
                while (!conv.empty() && (conv.top() == '*' || conv.top() == '+')) {
                    res.push_back(conv.top());
                    res.push_back(' ');
                    conv.pop();
                }
                conv.push('+');
            }
            else if (s1[i] == ')'){
                while (!conv.empty() && conv.top() != '(') {
                    res.push_back(conv.top());
                    res.push_back(' ');
                    conv.pop();
                }
                conv.pop();
            }
            else if (s1[i] == '(') {
                conv.push('(');
            }
        }
    }
    while (!conv.empty()) {
        if (!res.empty() && res.back() != ' ') {
            res.push_back(' ');
        }
        res.push_back(conv.top());
        conv.pop();
    }
    stringstream ss(res);
    string c;

    while (ss >> c) {
        if (c == "+") {
            int a = nums.top(); nums.pop();
            int b = nums.top(); nums.pop();
            nums.push(a + b);
        } else if (c == "*") {
            int a = nums.top(); nums.pop();
            int b = nums.top(); nums.pop();
            nums.push(a * b);
        } else {
            nums.push(stoi(c));  
        }
    }

    cout << res << endl;
    cout << nums.top();
    return 0;
}
