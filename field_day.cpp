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
// #define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             (int) 1e17+1
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void cpc()
{
#ifndef ONLINE_JUDGE
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
#endif
}
// int dx[] = {-1, 0, 1, 0};
// int dy[] = {0, 1, 0, -1};
int exp(int x, int n, int m) {
    if(x == 0 and n == 0) return 1;
    x %= m; 
    int res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        n /= 2;
    }
    return res;
}
int gcd(int a,int b){
    if(a == 0) return b;
    return gcd(b%a,a);
}

signed main()
{  
   // cpc();
   int t=1;
   // cin >> t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   while(t--){
    int n,c;
    cin >> c >> n;
    vector<pair<int,int>> v(n);
    int x = c/2;
    int y = c-x;
    int si = (1<<x);
    int si2 = (1<<y);
    vector<vector<int>> value((si),vector<int>(si2,0));
    vector<bool> pres2(si,false);
    for(int i = 0 ; i < n; i++){
        int x = 0;
        for(int j = 0; j < c/2; j++){
            char a;
            cin >> a;
            if(a == 'G') (x+= (1<<j));
        }
        v[i].ff = x;
        pres2[v[i].ff] = true;
        x = 0;
        for(int j = c/2; j < c; j++){
            char a;
            cin >> a;
            if(a == 'G') (x += (1<<(j-c/2)));
        }
        v[i].ss = x;
        for(int j = 0; j < si2; j++){
        value[v[i].ff][j] = max(value[v[i].ff][j],__builtin_popcount(j^v[i].ss));
        }
    }
    // for(int i = 0 ; i < si; i++){
    //     for(int j = 0 ; j < si2; j++) cout<<value[i][j]<<" ";
    //     cout<<endl;
    // }
    vector<int> ans(n,0);
    for(int i = 0 ; i < n; i++){
      for(int j = 0; j < si; j++){
        if(pres2[j]){
            int temp = __builtin_popcount(v[i].ff^j);
          ans[i] = max(ans[i],(temp+value[j][v[i].ss]));
        }
      }
    }
    for(auto &x:ans) cout<<x<<endl;
    
    

    
    
    }
return 0;
}
