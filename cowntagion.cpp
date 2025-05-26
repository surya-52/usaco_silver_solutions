#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using std::mt19937_64;
using std::random_device;
using std::uniform_int_distribution;
#include <numeric>
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
#endif
}
int binpow(int a, int b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void dfs(vector<int> *adj,int node,vector<bool> &visited,int &ct){
   if(visited[node]) return;
   visited[node] = true;
   int cur = 0;
   for(auto &x:adj[node]){
    if(!visited[x]) cur++;
   }
   if(cur != 0){
   int x = log2(cur)+1;
   x += cur;
   // cout<<x<<endl;
   ct += x;}
   for(auto &it:adj[node]){
    if(!visited[it]){
        dfs(adj,it,visited,ct);
    }
   }
} 
signed main()
  {   
    // c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
     int n;
     cin >> n;
     vector<int> adj[n];
     for(int i = 0 ; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
     }
     vector<bool> visited(n,false);
     int ans = 0;
     dfs(adj,0,visited,ans);
     cout<<ans<<endl;

    }
    return 0;
  }
