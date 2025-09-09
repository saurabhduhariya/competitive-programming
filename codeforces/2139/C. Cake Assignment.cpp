#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<bool> vb;
typedef stack<int> si;
typedef queue<int> qi;
typedef set<int> sti;

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
    int k,x;
    cin>>k>>x;
    vi powt(62);
    powt[0]=1;
    for(int i=1;i<=61;i++){
    powt[i] = powt[i-1] * 2;
    }

    if(powt[k]==x){
        cout<<0<<endl;
        return;
    }
    int val1=x;
    int val2=powt[k+1]-x;

    vi ans;
    while(val1!=val2){
        if(val2>powt[k]){
            val2=val2-val1;
            val1=val1*2;  
            ans.push_back(1);
        }
        else{
            val1=val1-val2;
            val2=val2*2;  
            ans.push_back(2);
        }
    }
   cout<<ans.size()<<endl;
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    // vi primes;
    // sieveOfEratosthenes(1000000, primes);
    while(t--){
        solve();
    }
 
    return 0;
}

