#include "Taxpayer.h"

#include <iostream>
#include <string>

// Тестирование базового поведения класса на константных данных
int main() {
    try {
        // Создание объекта
        Taxpayer taxpayer("7707083893", 2024);

        // Добавляем доходы
        taxpayer.addIncome(100000.0, true);   // облагаемый
        taxpayer.addIncome(50000.0, true);    // облагаемый
        taxpayer.addIncome(30000.0, false);   // необлагаемый

        taxpayer.print();
    }
}