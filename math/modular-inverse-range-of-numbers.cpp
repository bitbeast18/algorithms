// Author : bitbeast18
// Modular Inverse of a range of number (0, M-1) when M is prime.
// Complexity : O(M * log(M)).

#include <vector>

std::vector<int> inv;

int modInverse(int m) {
    inv.assign(m, 0);
    inv[1] = 1;

    for (int i = 2; i < m; i++)
        inv[i] = (m - (m / i) * inv[m % i] % m) % m;
}

int main() {

    // Usage
    // access mod of any numbers as inv[number].
}
