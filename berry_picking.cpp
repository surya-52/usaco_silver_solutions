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
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
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
void check(vector<int> &v,int mid,int k,int n,int &ans){
    priority_queue<int> pq;
    int ct = 0;
    int i = 0;
   while(i < n and ct < (k/2)){
     if(v[i] < mid){
        pq.push(v[i]);
     }
     else{
        int x = v[i]/mid;
        x = min(x,k/2-ct);
        pq.push(v[i]-(x*mid));
        ct+=x;
     }
     i++;
   }
   if(ct == (k/2)){
     for(i; i < n; i++){
        pq.push(v[i]);
     }
     int cur = 0;
     ct = 0;
     while(!pq.empty() and (ct<(k/2))){
        if(pq.top() < mid){
            cur += pq.top();
            ct++;
            pq.pop();
        }
        else{
            int x = pq.top()/mid;
            x = min(x,(k/2)-ct);
            cur += x*(mid);
            ct += x;
            pq.push(pq.top()-(x*mid));
            pq.pop();
        }
     }
     ans = max(ans,cur);
     // cout<<mid<<" "<<cur<<endl;
   }

  return;
}
signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
     int n,k;
     cin >> n >> k;
     vector<int> v(n);
     for(auto &x:v) cin >> x;
     sort(v.begin(),v.end());
     int ans = 0;
     for(int mid = v[0]; mid <= v[n-1]; mid++){
       check(v,mid,k,n,ans);
     }
     cout<<ans<<endl;
    }
  return 0;
}
