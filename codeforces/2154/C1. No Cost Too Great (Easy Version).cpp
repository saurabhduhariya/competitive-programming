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
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int even=0;
    for(int i=0;i<n;i++){
        if(a[i]%2==0) even++;
        if(even==2) {
            cout<<"0"<<endl;
            return;
        }
    }
    bool flag1=false;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]!=1 && a[j]!=1){
                if((a[i]%a[j]==0) || (a[j]%a[i]==0)){
                    flag1=true;
                }
            }
        }
    }
    if(flag1){
        cout<<"0"<<endl;
        return;
    }
    if(even==1){
        cout<<"1"<<endl;
        return;
    }
    bool flag2=false;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]!=1 && a[j]!=1){
            if(((a[i]+1)%a[j])==0 || ((a[j]+1)%a[i])==0){
                flag2=true;
            }
        }
    }

    }
    if(flag2){
        cout<<"1"<<endl;
        return;
    }
    else{
        cout<<"2"<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    // vector<ll> primes;
    // sieveOfEratosthenes(1000000, primes);
    while(t--){
        solve();
    }
 
    return 0;
}