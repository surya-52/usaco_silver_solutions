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
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
#endif
}


signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
    int n,m,r;
    cin >> n >> m >> r;
    vector<pair<int,int>> v(n);
    for(auto &x:v) {cin >> x.first;x.second = 0;}
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    vector<pair<int,int>> cost(m);
    for(auto &x:cost) cin >> x.second >> x.first;
    sort(cost.begin(),cost.end());
    reverse(cost.begin(),cost.end());
    int sum = 0;
    vector<int> farmer(r);
    for(auto &x:farmer) cin >> x;
    sort(farmer.begin(),farmer.end(),greater<int>());
    int j = 0;
    for(int i = n-1; i >= max((int)0,n-r); i--){
       v[i].second = farmer[j];
       sum += farmer[j];
       j++;
    }
    // cout<<sum<<endl;
    // for(auto &x:v) cout<<x.first<<" "<<x.second<<endl;
    int ans = sum;
    int cur = 0;
    int i = 0;j = 0;
    int mil_rem = 0;
    while((i<m) and (j < n)){
      if(cost[i].second >= v[j].first){
        cur += v[j].second;
        ans = max(ans,sum-cur+v[j].first * cost[i].first);
        sum = sum+v[j].first * cost[i].first;
        cost[i].second -= v[j].first;
        j++;
        if(cost[i].second == 0) i++;
      }
      else{
            ans = max(ans,sum - cur - v[j].second+ cost[i].first * cost[i].second);
            v[j].first -= cost[i].second;
            sum += cost[i].first*cost[i].second;
            i++;
      }
      // cout<<sum<<" "<<ans<<endl;
      // cout<<i<<" "<<j<<endl;
    }
    cout<<ans<<endl;

     
     


    }
  return 0;
}
