#ifndef TAXPAYER_H
#define TAXPAYER_H

#include <iostream>

class TaxPayer {
private:
    static constexpr int    innLengtLegalEntity  = 10;   // Длина ИНН юр. лица
    static constexpr int    innLengthIndividual   = 12;   // Длина ИНН физ. лица
    static constexpr int    minYear               = 2000; // Минимальный год с которого инн считаем
    static constexpr int    maxYear               = 2100; // Максимальный год с которого инн считаем
    static constexpr double defaultTaxRate        = 13.0; // Процент подоходного налога
    static constexpr double minTaxRate            = 0.0;
    static constexpr double maxTaxRate            = 100.0;

    char* inn_;                 // ИНН (динамическая строка)
    int year_;                  // год расчёта
    double taxableIncome_;      // налогооблагаемый доход
    double nonTaxableIncome_;   // неналогооблагаемый доход
    double totalTax_;           // итог суммы подоходного налога
    double totalIncome_;        // итог суммы доходов
    double taxRate_;            // процент подоходного налога

    void validateInn(const char* inn) const;
    void validateYear(int year) const;

public:
    // перегрузка конструктора 
    TaxPayer(const char* inn, int year,
             double taxableIncome    = 0.0,
             double nonTaxableIncome = 0.0);

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
// перегрузка operator>>
// >> читает сумму налога
std::istream& operator>>(std::istream& in, TaxPayer& obj);

// перегрузка operator+=
// += накапливает сумму налога
double& operator+=(double& sum, const TaxPayer& obj);

#endif // TAXPAYER_H