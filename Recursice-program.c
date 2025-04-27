//Recursive program 
#include <stdio.h>

long factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n-1);
}

int main() {
    int num;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    printf("Factorial of %d is %ld\n", num, factorial(num));
    return 0;
}