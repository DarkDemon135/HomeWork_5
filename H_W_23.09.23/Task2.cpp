#include <iostream>
#include <cmath>
#include <random>

double objectiveFunction(double x) {
    return std::sin(x); // Пример целевой функции
}

double acceptanceProbability(double currentEnergy, double newEnergy, double temperature) {
    if (newEnergy < currentEnergy) {
        return 1.0;
    } else {
        return std::exp((currentEnergy - newEnergy) / temperature);
    }
}

double simulatedAnnealing(double initialTemperature, double coolingRate, double minTemperature, double initialSolution) {
    double currentSolution = initialSolution;
    double bestSolution = currentSolution;
    double currentEnergy = objectiveFunction(currentSolution);
    double bestEnergy = currentEnergy;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    double currentTemperature = initialTemperature;
    while (currentTemperature > minTemperature) {
        double newSolution = currentSolution + (dis(gen) - 0.5);
        double newEnergy = objectiveFunction(newSolution);

        if (acceptanceProbability(currentEnergy, newEnergy, currentTemperature) > dis(gen)) {
            currentSolution = newSolution;
            currentEnergy = newEnergy;
        }

        if (currentEnergy < bestEnergy) {
            bestSolution = currentSolution;
            bestEnergy = currentEnergy;
        }

        currentTemperature *= coolingRate;
    }

    return bestSolution;
}

int main() {
    double initialTemperature;
    std::cout << "Введите начальную температуру: ";
    std::cin >> initialTemperature;

    double coolingRate;
    std::cout << "Введите коэффициент охлаждения: ";
    std::cin >> coolingRate;

    double minTemperature;
    std::cout << "Введите минимальную температуру: ";
    std::cin >> minTemperature;

    double initialSolution;
    std::cout << "Введите начальное значение решения: ";
    std::cin >> initialSolution;

    double bestSolution = simulatedAnnealing(initialTemperature, coolingRate, minTemperature, initialSolution);

    std::cout << "Лучшее решение: " << bestSolution << std::endl;
    std::cout << "Значение целевой функции: " << objectiveFunction(bestSolution) << std::endl;

    return 0;
}