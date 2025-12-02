#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int n, freq;
long long res;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> freq;
        pq.push(freq);
    }
    while (pq.size() > 1){
        int tmp1 = pq.top();
        pq.pop();
        int tmp2 = pq.top();
        pq.pop();
        res += tmp1 + tmp2;
        pq.push(tmp1 + tmp2);
    }
    cout << res;
    return 0;
}

