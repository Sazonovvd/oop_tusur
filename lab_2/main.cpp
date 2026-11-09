#include "Taxpayer.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        // Создание объекта с корректными данными
        TaxPayer payer("123456789012", 2023);

        // Добавление доходов
        payer.addIncome(50000.0, true);   // облагаемый
        payer.addIncome(10000.0, false);  // необлагаемый

        // Вывод информации
        std::cout << "=== Информация о налогоплательщике ===" << std::endl;
        payer.print();

        // Демонстрация исключений
        std::cout << "\n=== Проверка исключительных ситуаций ===" << std::endl;

        // 1. Пустой ИНН
        try {
            TaxPayer invalid("", 2023);
        } catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }

        // 2. Неверная длина ИНН
        try {
            TaxPayer invalid("12345", 2023);
        } catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }

        // 3. ИНН содержит нецифровые символы
        try {
            TaxPayer invalid("12345abcde", 2023);
        } catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }

        // 4. Недопустимый год
        try {
            TaxPayer invalid("123456789012", 1800);
        } catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }

        // 5. Отрицательный доход
        try {
            payer.addIncome(-100.0, true);
        } catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }

        // 6. Недопустимый процент налога
        try {
            payer.setTaxRate(150.0);
        } catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Непредвиденная ошибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}