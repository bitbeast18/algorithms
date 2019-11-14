// Author : bitbeast18
// Modular Inverse of a number.
// Complexity : O(log(N)).

int extendedEuclid(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }

    int x1, y1;
    int g = extendedEuclid(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;

    return g;
}

int modInverse(int a, int m) {
    int x, y;
    int g = extendedEuclid(a, m, x, y);

    if (g != 1) return -1;
    else return (x % m + m) % m;
}

int main() {

    // Usage
    // int modInverse = modInverse(a, m). return -1 if doesn't exist.
}
