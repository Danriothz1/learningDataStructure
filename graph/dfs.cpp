#include <iostream>
using namespace std;

const int N = 1050;
int a[N][N];
int vis[N];
int n, m;

void dfs(int x){
    if (x > n) return;
    vis[x] = 1;
    cout << x << " ";
    for (int i = 1; i <= n; i++){
        if (a[x][i] != 0 && vis[i] == 0){
            dfs(i);
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
    dfs(1);
    return 0;
}
