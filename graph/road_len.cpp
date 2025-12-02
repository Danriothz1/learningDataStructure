#include <iostream>
#include <queue>
using namespace std;

const int N = 1050;
int a[N][N];
int dis[N];
queue<int> q;
int n, m;

void bfs(int start){
    q.push(start);
    dis[start] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int i = 1; i <= n; i++){
            if (a[cur][i] != 0 && dis[i] == -1){
                    q.push(i);
                    dis[i] = dis[cur] + 1;
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
    for (int i = 1; i <= n; i++) dis[i] = -1;
    bfs(1);
    for (int i = 1; i <= n; i++) cout << dis[i] << " ";
    return 0;
}
