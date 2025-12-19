#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100005
#define M 400005

typedef struct {
    int d, u;
} Node;

Node hp[M];
int sz = 0;

void swap_node(Node *x, Node *y) {
    Node t = *x;
    *x = *y;
    *y = t;
}

void push(int d, int u) {
    int i = sz++;
    hp[i].d = d;
    hp[i].u = u;
    while (i > 0) {
        int p = (i - 1) >> 1;
        if (hp[i].d < hp[p].d) {
            swap_node(&hp[i], &hp[p]);
            i = p;
        } else {
            break;
        }
    }
}

Node pop() {
    Node res = hp[0];
    hp[0] = hp[--sz];
    int i = 0;
    while ((i << 1) + 1 < sz) {
        int j = (i << 1) + 1;
        int r = (i << 1) + 2;
        if (r < sz && hp[r].d < hp[j].d) {
            j = r;
        }
        if (hp[i].d <= hp[j].d) break;
        swap_node(&hp[i], &hp[j]);
        i = j;
    }
    return res;
}

int head[N], nxt[M], to[M], w[M], tot;
int vis[N];

void add(int u, int v, int val) {
    to[++tot] = v;
    w[tot] = val;
    nxt[tot] = head[u];
    head[u] = tot;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, val;
        scanf("%d%d%d", &u, &v, &val);
        add(u, v, val);
        add(v, u, val);
    }

    long long ans = 0;
    int cnt = 0;
    
    push(0, 1);

    while (sz > 0 && cnt < n) {
        Node top = pop();
        int u = top.u;
        int d = top.d;

        if (vis[u]) continue;
        vis[u] = 1;
        ans += d;
        cnt++;

        for (int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            if (!vis[v]) {
                push(w[i], v);
            }
        }
    }

    if (cnt == n) printf("%lld\n", ans);
    else printf("orz\n");

    return 0;
}
