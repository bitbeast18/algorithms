// Author : bitbeast18
// Extended Euclid's to find solution to Linear diophantine equation.
// Complexity : O(log(max(a, b)).

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

int main() {

    // Usage
    // int x, y;
    // int gcd = extendedEuclid(a, b, x, y).
}
