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
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
#endif
}
int power(int A, int B)
{
    if (B == 0)
        return 1;
 
    int res = power(A, B / 2);
 
    if (B % 2)
        return res * res * A;
    else
        return res * res;
}
bool comp(pair<int,int> &a,pair<int,int> &b){
    return (a.ff > b.ff);
}
signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
     int l,n,a,b;
     cin >> l >> n >> a >> b;
     vector<pair<int,int>> v(n);
     for(auto &x:v) cin >> x.ss >> x.ff;
     sort(v.begin(),v.end(),comp);
     int ans = 0;
     int ma = 0;
     for(int i = 0 ; i < n; i++){
        if(v[i].ss > ma){
          ans += v[i].ff*((v[i].ss-ma)*(a-b));
          ma = v[i].ss;
        }
     }
     cout<<ans<<endl;

    }
  return 0;
}
