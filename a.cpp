#include<iostream>
#include<cassert>

int main () {
    assert(0);
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        if (n % 4 == 0) std::cout << "Bob\n";
        else std::cout << "bob\n";
    }
    return 0;
}