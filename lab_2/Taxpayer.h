#ifndef TAXPAYER_H
#define TAXPAYER_H

#include <iostream>

class TaxPayer {
private:
    char* inn_;                 // ИНН (динамическая строка)
    int year_;                  // год расчёта
    double taxableIncome_;      // налогооблагаемый доход
    double nonTaxableIncome_;   // неналогооблагаемый доход
    double totalTax_;           // итог суммы подоходного налога
    double totalIncome_;        // итог суммы доходов
    double taxRate_;            // процент подоходного налога (по умолчанию 13)

    void validateInn(const char* inn) const;
    void validateYear(int year) const;

public:
    // Конструктор с параметрами
    TaxPayer(const char* inn, int year);

    // Конструктор копирования и оператор присваивания (для безопасной работы с динамической памятью)
    TaxPayer(const TaxPayer& other);
    TaxPayer& operator=(const TaxPayer& other);

    // Деструктор
    ~TaxPayer();

    // Селекторы (константные методы)
    const char* getInn() const;
    int getYear() const;
    double getTaxableIncome() const;
    double getNonTaxableIncome() const;
    double getTotalTax() const;
    double getTotalIncome() const;
    double getTaxRate() const;

    // Модификатор процента налога
    void setTaxRate(double rate);

    // Добавление статьи дохода
    // isTaxable = true  — доход облагается налогом
    // isTaxable = false — доход не облагается налогом
    void addIncome(double amount, bool isTaxable);

    // Вывод всех параметров на консоль
    void print() const;
};

#endif // TAXPAYER_H