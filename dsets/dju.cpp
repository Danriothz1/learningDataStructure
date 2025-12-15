#include <iostream>
using namespace std;
int fa[150100];
int n, k, op, x, y, ans;

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unity(int p,int q){
    fa[find(p)]=find(q);
} 

int main(){
    cin  >> n >> k;
    for(int i = 1; i <= 3*n; i++){
        fa[i] = i;
    }
    for(int i=0 ;i<k ;i++){
	cin >> op >> x >> y;
        if(x > n||y > n){
            ans++;
            continue;
        }
        if(op == 1){
            if(find(x) == find(y+n)||find(x) == find(y+2*n)) ans++;
            else{
                unity(x,y);
                unity(x+n,y+n);
                unity(x+2*n,y+2*n);
            }
        } 
	else{
            if(find(x) == find(y)||find(x) == find(y+2*n)) ans++;
            else{
                unity(x,y+n);
                unity(x+n,y+2*n);
                unity(x+2*n,y);
            }
        }
    }
    cout << ans;
    return 0;
}

