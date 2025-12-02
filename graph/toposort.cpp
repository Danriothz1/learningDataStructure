#include <iostream>
#include <vector>
#include <queue>
#include <functional> 

using namespace std;

const int MAXN = 1050; 
int n, m;
vector<int> adj[MAXN];      
int in_degree[MAXN];        
vector<int> res;         

void topo_sort() {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        res.push_back(u);
        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                pq.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        in_degree[v2]++;
    }
    topo_sort();
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}
