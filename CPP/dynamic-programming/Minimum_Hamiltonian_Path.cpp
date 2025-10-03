#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=(ll)4e15;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    if(!(cin>>n>>m)) return 0;
    vector<vector<ll>> w(n,vector<ll>(n,INF));
    for(int i=0;i<m;++i) {
        int u,v;
        ll wt;
        cin>>u>>v>>wt;
        --u;--v;
        w[u][v]=min(w[u][v],wt);
    }
    
    int ALL=1<<n;
    vector<vector<ll>> dp(ALL,vector<ll>(n,INF));
    
    for(int v=0;v<n;++v)dp[1<<v][v]=0;
    
    for(int w=1;w<ALL;++w) {
        for(int x=0;x<n;++x) {
            if(!(w&(1<<x)))continue;
            ll cur=dp[w][x];
            if(cur==INF)continue;
            int z=(~w)&(ALL-1);
            for(int y=0;y<n;++y) {
                if(!(z&(1<<y)))continue;
                if(w[x][y]==INF)continue;
                int nw=w|(1<<y);
                ll cand=cur+w[x][y];
                if(cand<dp[nw][y])dp[nw][y]=cand;
            }
        }
    }
    
    ll ans=INF;
    int finalw=ALL-1;
    for(int v=0;v<n;++v) {
        ans=min(ans,dp[finalw][v]);
    }
    if(ans>=INF/2)cout<<-1<<'\n';
    else cout<<ans<<'\n';
    
    return 0;
}