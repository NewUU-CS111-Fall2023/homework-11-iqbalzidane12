/*
 * Author:
 * Date:Muxtorov Abdulaziz
 * Name:
 */
#include <iostream>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    int sqrtNum = sqrt(num);
    for (int i = 2; i <= sqrtNum; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void generatePrimesGreaterThanN(int n, int& prime1, int& prime2) {
    prime1 = n + 1;

    while (true) {
        if (isPrime(prime1)) {
            prime2 = prime1 + 1;
            while (!isPrime(prime2)) {
                ++prime2;
            }

            return;
        }
        ++prime1;
    }
}

int task_6 () {
    int n;
    std::cout << "Enter a number (n): ";
    std::cin >> n;

    int prime1, prime2;
    generatePrimesGreaterThanN(n, prime1, prime2);

    std::cout << "Two prime numbers greater than " << n << " are: " << prime1 << " and " << prime2 << std::endl;

    return 0;
}
