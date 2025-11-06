#include <iostream>
using namespace std;

const int N = 50050;
int fa[N];

int find(int x){
    if (x == fa[x]) return x;
    else return fa[x] = find(fa[x]);
}
void unity(int x, int y){
    fa[find(y)] = find(x);
}

int main(){

