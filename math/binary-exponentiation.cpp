// Author : bitbeast18
// Binary exponentiation.
// Complexity : O(log(P)) where p is power.

int expo(int n, int p){
    if(p == 0) return 1;
    int res = expo(n, p/2);
    if(p&1) return res * res * n;
    else return res * res;
}

int main(){

    // Usage
    // int aPOWb = expo(a,b);

}
