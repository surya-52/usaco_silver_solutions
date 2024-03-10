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
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
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
    while (temp != 0) { 
        reverse = (reverse * 10) + (temp % 10); 
        temp = temp / 10; 
    } 
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

signed main()
{   
    // c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
     int n;
     cin >> n;
     vector<int> a(n),b(n),c(n);
     char x;
     cin >> x;
     if(x=='P') a[0]++;
     else if(x=='H') b[0]++;
     else c[0]++;
     for(int i = 1 ; i < n; i++){
        cin >> x;
        a[i] = a[i-1];
        b[i] = b[i-1];
        c[i] = c[i-1];
        if(x=='P') a[i]++;
        else if(x=='H') b[i]++;
        else c[i]++;
     }
     int ans = 0;
     for(int i = 0 ; i < n; i++){
       ans = max(ans,a[i]+b[n-1]-b[i]);
       ans = max(ans,a[i]+c[n-1]-c[i]);
       ans = max(ans,b[i]+a[n-1]-a[i]);
       ans = max(ans,b[i]+c[n-1]-c[i]);
       ans = max(ans,c[i]+b[n-1]-b[i]);
       ans = max(ans,c[i]+a[n-1]-a[i]);
     }
     cout<<ans<<endl;
     


    }
  return 0;
}
