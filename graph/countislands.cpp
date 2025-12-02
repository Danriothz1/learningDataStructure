#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 310;
int a[N][N];
int res;
int m, n;
typedef struct node{
    int x;
    int y;
    node(int u, int v) : x(u), y(v) {}
}node;
queue<node> q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] == 1){
                q.push(node(i, j));
                a[i][j] = 0;
                res++;
                while (!q.empty()){
                    node tmp = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++){
                        int nx = tmp.x + dx[k];
                        int ny = tmp.y + dy[k];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n){
                            if (a[nx][ny] == 1){
                                a[nx][ny] = 0;
                                q.push(node(nx, ny));
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(){
    cin >> m >> n;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    bfs();
    cout << res;
    return 0;
}

