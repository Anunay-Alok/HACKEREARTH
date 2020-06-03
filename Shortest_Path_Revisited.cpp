#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define ll long long
#define ii tuple<ll, ll>
#define vii vector<ii>
#define rep(i,a,b) for(ll i = (ll)a;i<(ll)b;i++) 
using qii = priority_queue<ii, vii, greater<ii>>;
 
struct Edge{
    ll source;
    ll dest;
    ll weight;
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, u, v, w, y,k;
    cin >> n >> m >> k;
    vector<Edge>vec;
    vector<vii> g(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        vec.eb((Edge){u,v,w});
        vec.eb((Edge){v,u,w});
    }
 
    ll dp[k+1][n];
    rep(i,0,k+1) rep(j,0,n) dp[i][j] = 1000000LL * m + 1LL;
    rep(i,0,k+1){
        vector<ll> d(n, 1000000LL * m + 1LL), s(n);
        d[0] = 0;
        dp[i][0] = 0;
        qii q;
        q.push({0, 0});
        while (!q.empty()) {
            tie(w, u) = q.top();
            q.pop();
            if (s[u]) continue;
            s[u] = 1;
            for (ii x : g[u]) {
                tie(v, y) = x;
                if(i==0){
                    if (d[u] + y < d[v]) {
                        d[v] = d[u] + y;
                        dp[i][v] = d[v];
                        q.push({d[v], v});
                    }
                }
                else{
                    if(dp[i-1][v] < d[v]){
                        d[v] = dp[i-1][v];
                        dp[i][v] = d[v];
                        q.push({d[v],v});
                    }
                    if(dp[i][u] + y < d[v]){
                        d[v] = dp[i][u] + y;
                        dp[i][v] = d[v];
                        q.push({d[v],v});
                    }
                    if(dp[i-1][u] < d[v]){
                        d[v] = dp[i-1][u];
                        dp[i][v] = d[v];
                        q.push({d[v],v});
                    }
                }
            }
        }
    }
    rep(i,0,n) cout<<dp[k][i]<<" ";
}
