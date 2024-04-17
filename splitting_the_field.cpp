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
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
#endif
}
bool comp(const pair<int,int> &a,const pair<int,int> &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second<b.second;
}
signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
      int n;
      cin >> n;
      vector<pair<int,int>> v(n);
      for(auto &x:v) cin >> x.first >> x.second;
      sort(v.begin(),v.end());
      int le = v[0].first, ri = v[n-1].first;
      vector<int> max_height(n);
      vector<int> min_height(n);
      max_height[n-1] = v[n-1].second;
      min_height[n-1] = v[n-1].second;
      for(int i = n-2; i >= 0; i--){
        max_height[i] = max(max_height[i+1],v[i].second);
        min_height[i] = min(min_height[i+1],v[i].second);
      }
      int total = (v[n-1].first - v[0].first) * (max_height[0]-min_height[0]);
      // cout<<total<<endl;
      int cur_min = total;
      int min_h = total;
      int max_h = 0;
      for(int i = 0 ; i < n-1; i++){
        min_h = min(min_h,v[i].second);
        max_h = max(max_h,v[i].second);
        if(v[i].first != v[i+1].first){
           cur_min = min(cur_min,(v[i].first-v[0].first)*(max_h-min_h)+(v[n-1].first-v[i+1].first)*(max_height[i+1]-min_height[i+1]));
        }
      }
     sort(v.begin(),v.end(),comp);
     max_height[n-1] = v[n-1].first;
      min_height[n-1] = v[n-1].first;
      for(int i = n-2; i >= 0; i--){
        max_height[i] = max(max_height[i+1],v[i].first);
        min_height[i] = min(min_height[i+1],v[i].first);
      }
       min_h = total;
       max_h = 0;
       for(int i = 0 ; i < n-1; i++){
        min_h = min(min_h,v[i].first);
        max_h = max(max_h,v[i].first);
        if(v[i].second != v[i+1].second){
           cur_min = min(cur_min,(v[i].second-v[0].second)*(max_h-min_h)+(v[n-1].second-v[i+1].second)*(max_height[i+1]-min_height[i+1]));
        }
      }
     // for(auto &x:v) cout<<x.first<<" "<<x.second<<endl;
     cout<<total-cur_min<<endl;


    }
  return 0;
}
