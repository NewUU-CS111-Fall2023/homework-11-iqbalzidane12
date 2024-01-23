/*
 * Author:
 * Date:
 * Name:Muxtorov Abdulaziz
 */
#include <iostream>

int eulerTotientFunction(int a, int b) {
    return (a - 1) * (b - 1);
}

int task_ 7() {
    int a, b;

    std::cout << "Enter the first prime number (a): ";
    std::cin >> a;

    std::cout << "Enter the second prime number (b): ";
    std::cin >> b;


    int result = eulerTotientFunction(a, b);

    std::cout << "Euler's totient function for n = " << a * b << " is: " << result << std::endl;

    return 0;
}
