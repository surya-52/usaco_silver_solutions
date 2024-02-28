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
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
#endif
}

signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
     int n,q;
     cin >> n >> q;
     vector<int> a(n+1,0),b(n+1,0),c(n+1,0);
     for(int i = 1 ; i <= n; i++){
        int x;
        cin >> x;
        a[i] = a[i-1]+(x==1);
        b[i] = b[i-1]+(x==2);
        c[i] = c[i-1]+(x==3);
     }
     while(q--){
        int l,r;
        cin >> l >> r;
        cout<<a[r]-a[l-1]<<" "<<b[r]-b[l-1]<<" "<<c[r]-c[l-1]<<endl;
     }
   }
    return 0;
      }
