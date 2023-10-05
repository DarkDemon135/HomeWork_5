#include <iostream>
#include <vector>

long long sumOfPrimes(int limit) {
    std::vector<bool> isPrime(limit, true);
    
    long long sum = 0;

    for (int i = 2; i < limit; ++i) {
        if (isPrime[i]) { // Если число i является простым
            sum += i;

            // Помечаем все кратные числа как составные
            for (int j = i + i; j < limit; j += i)
                isPrime[j] = false;
        }
    }

    return sum;
}

int main() {
    int limit = 2000000;
  
   long long result = sumOfPrimes(limit);

   std::cout << "Сумма всех простых чисел меньше "<<limit<<": "<< result << std::endl;

   return 0;
}