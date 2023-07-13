#include <stdio.h>

int main() {
    size_t const SIZE=1024;
    char arr[SIZE];
    while(fgets(arr, SIZE, stdin)) printf("%s", arr);
    return 0;
}