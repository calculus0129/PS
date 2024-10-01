#include <iostream>
// #include <ctime>
// #include <cstdlib>

#include <random>

int main() {
    std::ios_base::sync_with_stdio(false);

    // Method 1: Using C rand()
    // srand(time(NULL)); // int rand(void)
    // for(int i=0;i<20;++i) {
    //     std::cout << rand() << '\n';
    // }
    // https://nx006.tistory.com/19 => NO!

    // Method 2: random
    // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd; // a seed source for the random number engine
    std::mt19937 gen(rd()); // mt19937: C++에서 제공하는 랜덤 엔진이다. 메르센 트위스터 방법을 사용한다.
    std::uniform_int_distribution<int> dtb(1,4); // [1,4]
    for(int i=0;i!=10;++i) std::cout << dtb(gen) << ' ';
    std::cout << std::endl;
    return 0;
}