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
int digit(int n){
    int a=n/2;
     if(a%10!=9){
        return a;
        }
    return digit(a/10);
}
void solve(){
    int n;
    cin>>n;
    // if(n%2==0){
    //     int a=n/2;
    //     cout<<a<<" "<<a<<endl;
    // }
    // else{
    //     int a=n/2;
    //     if(a%10!=9){
    //         cout<<a<<" "<<a+1<<endl;
    //     }
    //     else{
    //         int ans=digit(n);
    //         cout<<10
    //     }
    // }

     long long x = 0, y = 0;
    long long place = 1; 
    bool toggle = false; 

    while (n > 0) {
        int ai = n % 10; 
        n /= 10;

        if (ai % 2 == 0) {
            x += (ai / 2) * place;
            y += (ai / 2) * place;
        } else {
            if (toggle) {
                x += (ai / 2) * place;
                y += (ai / 2 + 1) * place;
            } else {
                x += (ai / 2 + 1) * place;
                y += (ai / 2) * place;
            }
            toggle = !toggle;
        }

        place *= 10;
    }

    cout << x << " " << y << "\n";
}
//}

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