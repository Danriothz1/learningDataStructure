#include <iostream>
using namespace std;

const int N = 505;
const int INF = -2100000000;

int n,m;
int map[N][N];
int dp[N][N];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
	for (int j = 1; j <= n; ++j){
	    cin >> map[j][i];
	}
    }
    for (int i = 0; i <= n; ++i){
	for (int j = 0; j <= m; ++j){
            dp[i][j] = INF;
	}
    }
    dp[1][1] = map[1][1];
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
	    if (i == 1 && j == 1) continue;
            if (map[i][j] == -1){
	        dp[i][j] = INF;
		continue;
		}
	    int val = INF;
	    if (i > 1 && dp[i-1][j] != INF) val = max(val, dp[i-1][j]);
	    if (j > 1 && dp[i][j-1] != INF) val = max(val, dp[i][j-1]);
	    if (i > 1 && j > 1 && dp[i-1][j-1] != INF) val = max(val, dp[i-1][j-1]);
	    if (val != INF) dp[i][j] = val + map[i][j];
	    else dp[i][j] = INF;
	    }
	}
    if (dp[n][m] != INF){
	    cout << "Yes" << endl;
	    cout<<dp[n][m];
    }
    else cout << "No";

    return 0;
}	    
