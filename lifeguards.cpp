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
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
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
bool checkPalindrome(int n) 
{ 
    int reverse = 0; 
    int temp = n; 
        reverse = (reverse * 10) + (temp % 10); 
        temp = temp / 10; 
    return (reverse == n); 
} 
vector<int> prime;
const int N = (int) 200000;
int p[N+1]={0};
void sieve(){
    for(int i=2;i<=N;i++){
        if(!p[i]){
            if(i*i <= N) prime.push_back(i);
            for(int j=i*i;j<=N;j+=i){
                p[j]=1;
            }
        }
    }
}

bool check(vector<int> &v,int mid,int n){
    int ct = 0;
    for(int i = n-1; i >= 0; i--){
        ct++;
      float temp =(float)(mid)/ct;
      if(v[i] >= temp) return true;
    }


    return false;
}
void binary(int n,vector<int> &a){
    for(int i = 0; i <=31; i++){
        if(n&power(2,i)) a[i] +=1;
    }
}
int gcd( int a,  int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
// Function to return LCM of two numbers  
int lcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b;
} 
struct cow{
   int ti;
   int ind;
   bool temp;
   bool operator<(const cow &a){
      return a.ti > ti;
   }
};


signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
     int n;
     cin >> n;
     vector<cow> v;
     for(int i = 0 ; i < n; i++){
        int l,r;
        cin >> l >> r;
        v.pb({l,i,true});
        v.pb({r,i,false});
     }
     sort(v.begin(),v.end());
     set<int> active;
     vector<int> alone_time(n);
     int total_time = 0;
     int prev_time = 0;
     for(cow &x:v){
       if(active.size() > 0){
         total_time += x.ti - prev_time;
       }
       if(active.size() == 1){
        alone_time[*active.begin()] = x.ti - prev_time;
       }
       if(x.temp){
        active.insert(x.ind);
       }
       else{
        active.erase(x.ind);
       }
       prev_time = x.ti;
     }
     // cout<<total_time<<endl;
     int min_time = *min_element(alone_time.begin(),alone_time.end());
     cout<<total_time-max(min_time,(int)0)<<endl;
     // cout<<ans<<endl;
     


    }
  return 0;
}
