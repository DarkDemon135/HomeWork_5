#include <iostream>

int main() {
    int targetSum = 1000; // Целевая сумма a + b + c

    for (int a = 1; a < targetSum / 3; ++a) {
        for (int b = a+1; b < targetSum / 2; ++b) {
            int c = targetSum - a - b;

            if (a * a + b * b == c * c) { // Проверка условия тройки Пифагора
                std::cout << "Тройка Пифагора найдена: " << a << ", " << b << ", " << c << std::endl;
                std::cout << "Произведение abc: " << a * b * c << std::endl;
                return 0;
            }
        }
    }

    std::cout <<"Не удалось найти тройку Пифагора, удовлетворяющую условию."<<std::endl;

    return 0;
}