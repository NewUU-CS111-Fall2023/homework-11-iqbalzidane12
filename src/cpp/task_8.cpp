/*
 * Author:
 * Date:
 * Name:
 */
#include <iostream>
#include <cmath>


int eulerTotientFunction(int p, int q) {
    return (p - 1) * (q - 1);
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

int task_8 () {
    int p, q;

    std::cout << "Enter the first prime number (p): ";
    std::cin >> p;

    std::cout << "Enter the second prime number (q): ";
    std::cin >> q;


    int n = p * q;


    int phiN = eulerTotientFunction(p, q);


    int e = 2;
    while (e < phiN && gcd(e, phiN) != 1) {
        e++;
    }

    int d = modInverse(e, phiN);

    std::cout << "Public key (e, n): (" << e << ", " << n << ")" << std::endl;
    std::cout << "Private key (d, n): (" << d << ", " << n << ")" << std::endl;

    return 0;
}
