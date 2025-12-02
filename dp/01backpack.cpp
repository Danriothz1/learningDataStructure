#include <iostream>
using namespace std;

const int N = 1010;
int n, w, weight[N], value[N];
int dp[N][N];

int main(){
    cin >> n >> w;
    for (int i = 0; i < n; ++i) cin >> weight[i] >> value[i];
    for (int i = 0; i <= w; ++i) i >= weight[0]?dp[0][i] = value[0]:dp[0][i] = 0;
    for (int i = 1; i < n; ++i){
	 for (int j = 1; j <= w; ++j){
		 if (j < weight[i]) dp[i][j] = dp[i-1][j];
		 else dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
	 }
    }
    cout << dp[n-1][w];
    return 0;
}
