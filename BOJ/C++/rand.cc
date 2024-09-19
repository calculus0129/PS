#include <iostream>
#include <ctime>
#include <cstdlib>
int main() {
    std::ios_base::sync_with_stdio(false);
    srand(time(NULL)); // int rand(void)
    for(int i=0;i<20;++i) {
        std::cout << rand() << '\n';
    }
}