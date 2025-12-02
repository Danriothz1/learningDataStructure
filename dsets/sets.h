#define 1024 MAX_SIZE
typedef int data;
typedef struct Sets{
    data fa[N];
}diset;

int find(struct Sets *s, int x){
    if (s->fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void unity(struct Sets *s, int x, int y){
    s->fa[x] = s->fa[find(y)];
}



