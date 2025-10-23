#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int,int> pi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<bool> vb;
typedef stack<int> si;
typedef queue<int> qi;
typedef set<int> sti;

#define int long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define MOD 1000000007
#define INF 1e18
#define PI 3.141592653589793238462643383279502884

void sieveOfEratosthenes(int N, vi& primes) {
    vb isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for(int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes.PB(i);
        }
    }
}

int mod(int a, int n){
    return (a%n+n)%n;
}

bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

void printarr(vi& arr){
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int bins(vi& arr, int x){
    int l=0, r=arr.size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

int lbins(vi& arr, int x){
    int l=0, r=arr.size()-1, ind=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]<=x){
            ind=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ind;
}

void solve(){
    int n,c;
    cin>>n>>c;
    vi s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    int l=1,r=1e9;
    int ans=0;
    while(l<=r){
        int mid=l+(r-l)/2;
        int check=0;
        for(int i=0;i<n;i++){
            check+=(2*mid+s[i])*(2*mid+s[i]);
            if(check>c){
                break;
            }
        }
        if(check==c){
            ans=mid;
            break;
        }
        else if(check>c){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
 
    return 0;
}