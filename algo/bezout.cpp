#include <iostream>

int main() {
    for (int i = -1000; i < 1000; i++) {
        for (int j = -1000; j < 1000; j++) {
            if (84*i + 62*j == 2) {
                std::cout << "i is: " << i <<"j is: " << j << std::endl;
            }
        }
    }
    return 0;
}
