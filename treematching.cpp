#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pyes cout << "YES" << "\n";
#define pno cout << "NO" << "\n";
#define br cout << "\n";

ll dp[1000000][2];

void dfs(int node, int par, vector<int> adj[]){
    dp[node][0] = 0ll;
    dp[node][1] = 0ll;

    for(auto it : adj[node]){
        if(it != par){
            dfs(it, node, adj);
        }
    }
    //calculation of 0 part
    for(auto it : adj[node]){
        if(it == par){
            continue;
        }
        dp[node][0] += max(dp[it][0], dp[it][1]);
    }

    for(auto it : adj[node]){
        if(it == par){
            continue;
        }
        // ll ans = 1ll + dp[it][0];
        // for(auto j : adj[node]){
        //     if(j != par && j != it){
        //         ans += max(dp[j][0], dp[j][1]);
        //     }
        // }
        dp[node][1] = max(dp[node][1], (dp[node][0] - max(dp[it][0], dp[it][1]) + dp[it][0] + 1));
    }
}

void solve(){
    
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //code here

    // int t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }
    // solve();
    //end

    int n;
    cin >> n;
    vector<int> adj[n+1];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, adj);
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
 
}
