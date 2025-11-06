#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool check(string t){
    stack<char> s;
    int len = t.size();
    for (int i = 0; i < len; i++) {
        if (t[i] == '(') s.push('(');
        if (t[i] == ')'){
            if (s.empty()) return false;
            else s.pop();
        }
    }
    return s.empty();
}

int main(){
    string inp;
    getline(cin,inp);
    if (check(inp)) cout << "YES";
    else cout << "NO";
    return 0;
}
