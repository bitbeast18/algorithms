// Author : bitbeast18
// Modular exponentiation.
// Complexity : O(log(P)) where p is power.


long long int modpow(long long int n, long long int p, long long int m){
    n %= m;
    if(p == 0) return 1;
    long long int res = modpow(n, p/2, m);
    if(p&1) return (((res * res) % m) * n) % m;
    else return (res * res) % m;
}

int main(){

    // Usage
    // int aPOWbMODm = modpow(a,b);
}
