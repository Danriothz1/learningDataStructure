#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static char ch[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

int main(){
    int num = 0, m, n;
    string input,res;
    cin >> n >> input >> m;
    int l = input.length();
    for (int i = 0; i < l; i++){
	if (input[i] == 'A') num += 10;
	if (input[i] == 'B') num += 11;
	if (input[i] == 'C') num += 12;
	if (input[i] == 'D') num += 13;
	if (input[i] == 'E') num += 14;
	if (input[i] == 'F') num += 15;
	if (input[i] >= '0' && input[i] <= '9') num += input[i] - '0';
	num *= n;
    }
    num /= n;
    while (num > 0){
	int j = num % m;
	res.push_back(ch[j]);
	num /= m;
    }
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}
