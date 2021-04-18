#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fib(int n)
{
    if (n<=1)
      return n;
    else if(n%60==0)
      return 0;
    int fib[60]{};
    fib[0]=1;
    fib[1]=1;
    for(int i=2; i<60; i++)
    {
      fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[(n%60)-1]%10;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fib(n);
    std::cout << c << '\n';
    }
