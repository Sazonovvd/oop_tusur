#include "Taxpayer.h"
#include <iostream>
#include <stdexcept>
#include <clocale> // Для setlocale

int main() {
    // Устанавливаем локаль для корректного вывода кириллицы в консоли
    setlocale(LC_ALL, "Russian");

    try {
        // ==========================================
        // LAB_2: Базовая работа
        // ==========================================
        std::cout << "=== 1. Информация о налогоплательщике (Лаба 2) ===" << std::endl;
        TaxPayer payer("123456789012", 2023);
        
        // Добавление доходов
        payer.addIncome(50000.0, true);   // облагаемый
        payer.addIncome(10000.0, false);  // необлагаемый
        payer.print();

        // ==========================================
        // LAB_3: Перегрузка конструктора (частично рассчитанный доход)
        // ==========================================
        std::cout << "\n=== 2. Конструктор с частично рассчитанным доходом (Лаба 3) ===" << std::endl;
        TaxPayer payer2("9876543210", 2024, 100000.0, 20000.0);
        payer2.print();

        // ==========================================
        // LAB_3: Добавление дохода ПОСЛЕ вычета налога
        // ==========================================
        std::cout << "\n=== 3. Добавление дохода ПОСЛЕ вычета налога (Лаба 3) ===" << std::endl;
        // Допустим, человек получил на руки 87000 руб. При ставке 13% это значит, 
        // что "грязный" доход был 100000, а налог 13000.
        payer.addIncomeAfterTax(87000.0);
        std::cout << "После добавления 87000 руб. 'на руки':" << std::endl;
        payer.print();

        // ==========================================
        // LAB_3: Проверка оператора >>
        // ==========================================
        std::cout << "\n=== 4. Проверка оператора >> (Лаба 3) ===" << std::endl;
        TaxPayer payer3("112233445566", 2023);
        std::cout << "Введите сумму дохода 'на руки' (например, 43500) и нажмите Enter: ";
        std::cin >> payer3; // Вызовет operator>>, который внутри вызовет addIncomeAfterTax
        std::cout << "Результат после ввода через cin >>:" << std::endl;
        payer3.print();

        // ==========================================
        // LAB_3: Проверка оператора += для суммирования налогов
        // ==========================================
        std::cout << "\n=== 5. Проверка оператора += для суммирования налогов (Лаба 3) ===" << std::endl;
        double totalTaxesAllPayers = 0.0;
        totalTaxesAllPayers += payer;
        totalTaxesAllPayers += payer2;
        totalTaxesAllPayers += payer3;
        std::cout << "Суммарный налог, уплаченный всеми налогоплательщиками: " 
                  << totalTaxesAllPayers << " руб." << std::endl;

        // ==========================================
        // LAB_2: Демонстрация исключительных ситуаций (минимум 6)
        // ==========================================
        std::cout << "\n=== 6. Проверка исключительных ситуаций ===" << std::endl;

        // 1. Пустой ИНН
        try {
            TaxPayer invalid("", 2023);
        } catch (const std::exception& e) {
            std::cout << "1. Ошибка: " << e.what() << std::endl;
        }

        // 2. Неверная длина ИНН
        try {
            TaxPayer invalid("12345", 2023);
        } catch (const std::exception& e) {
            std::cout << "2. Ошибка: " << e.what() << std::endl;
        }

        // 3. ИНН содержит нецифровые символы
        try {
            TaxPayer invalid("12345abcde", 2023);
        } catch (const std::exception& e) {
            std::cout << "3. Ошибка: " << e.what() << std::endl;
        }

        // 4. Недопустимый год
        try {
            TaxPayer invalid("123456789012", 1800);
        } catch (const std::exception& e) {
            std::cout << "4. Ошибка: " << e.what() << std::endl;
        }

        // 5. Отрицательный доход
        try {
            payer.addIncome(-100.0, true);
        } catch (const std::exception& e) {
            std::cout << "5. Ошибка: " << e.what() << std::endl;
        }

        // 6. Недопустимый процент налога
        try {
            payer.setTaxRate(150.0);
        } catch (const std::exception& e) {
            std::cout << "6. Ошибка: " << e.what() << std::endl;
        }
        
        // 7. Отрицательный доход "на руки" (дополнительно для Лабы 3)
        try {
            payer.addIncomeAfterTax(-500.0);
        } catch (const std::exception& e) {
            std::cout << "7. Ошибка: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Непредвиденная ошибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}