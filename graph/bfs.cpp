#include <iostream>
#include <queue>
using namespace std;

const int N = 1050;
int a[N][N];
int vis[N];
queue<int> q;
int n, m;

void bfs(int start){
    q.push(start);
    vis[start] = 1;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int i = 1; i <= n; i++){
            if (a[cur][i] != 0 && vis[i] == 0){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
}

int main(){
    cin >> n >> m;
    int x, y;
    while(m--){
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    bfs(1);
    return 0;
}
