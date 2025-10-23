#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<ll,ll> pi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<bool> vb;
typedef stack<ll> si;
typedef queue<ll> qi;
typedef set<ll> sti;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define MOD 1000000007
#define INF 1e18
#define PI 3.141592653589793238462643383279502884

void sieveOfEratosthenes(ll N, vi& primes) {
    vb isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (ll i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for(ll i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes.PB(i);
        }
    }
}

ll mod(ll a, ll n){
    return (a%n+n)%n;
}

bool isPrime(ll n){
    if(n<=1) return false;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

void prllarr(vi& arr){
    for(ll i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

ll bins(vi& arr, ll x){
    ll l=0, r=arr.size()-1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

ll lbins(vi& arr, ll x){
    ll l=0, r=arr.size()-1, ind=-1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(arr[mid]<=x){
            ind=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ind;
}

void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    ll n1=n/x;
    ll n2=n/y;
    ll lcm_xy=lcm(x,y);
    ll n3=n/lcm_xy;
    n1-=n3;
    n2-=n3;
    ll sumx=n1*(2*n-n1+1)/2;
    ll sumy=n2*(n2+1)/2;
    ll ans=sumx-sumy;
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin>>t;
    // vi primes;
    // sieveOfEratosthenes(1000000, primes);
    while(t--){
        solve();
    }
 
    return 0;
}