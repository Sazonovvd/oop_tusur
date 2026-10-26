#ifndef TAXPAYER_H
#define TAXPAYER_H

#include <string>

class Taxpayer {
public:
    // Константа процента налога по умолчанию
    static constexpr double kDefaultTaxRate = 13.0;

    // Конструкт#ifndef TAXPAYER_H
#define TAXPAYER_H

#include <string>

class Taxpayer {
public:
    // Константа процента налога по умолчанию
    static constexpr double kDefaultTaxRate = 13.0;

    // Конструктор с параметрами (ИНН и год расчета)
    Taxpayer(const char* const inn, const int& year);
    // Конструктор копирования (нужен, т.к. владеем динамической памятью)
    Taxpayer(const Taxpayer& other);
    ~Taxpayer();

    // Селекторы (константные методы, т.к. не меняют состояние)
    const char* const getInn() const;
    int getYear() const;
    double getTaxableIncome() const;
    double getNonTaxableIncome() const;
    double getTotalTax() const;
    double getTotalIncome() const;
    double getTaxRate() const;

    // Модификатор процента налога (с проверкой диапазона)
    void setTaxRate(const double& rate);

    // Добавление статьи дохода.
    // income  — размер дохода (> 0)
    // taxable — true: облагается налогом, false: не облагается
    void addIncome(const double& income, const bool& taxable);

    // Вывод всех параметров на консоль
    void print() const;

private:
    char* inn_        = nullptr;  // ИНН
    int   year_       = 0;        // год расчета
    double taxable_   = 0.0;      // налогооблагаемый доход
    double nonTaxable_= 0.0;      // неналогооблагаемый доход
    double totalTax_  = 0.0;      // итог налога
    double totalIncome_ = 0.0;    // итог доходов
    double taxRate_   = kDefaultTaxRate; // процент налога

    // Вспомогательный приватный метод — освобождение ресурсов
    void freeInn();
};

#endif // TAXPAYER_Hор с параметрами (ИНН и год расчета)
    Taxpayer(const char* const inn, const int& year);

    // Конструктор копирования (нужен, т.к. владеем динамической памятью)
    Taxpayer(const Taxpayer& other);

    // Деструктор — освобождает строку ИНН
    ~Taxpayer();

    // Селекторы (константные методы, т.к. не меняют состояние)
    const char* const getInn() const;
    int getYear() const;
    double getTaxableIncome() const;
    double getNonTaxableIncome() const;
    double getTotalTax() const;
    double getTotalIncome() const;
    double getTaxRate() const;

    // Модификатор процента налога (с проверкой диапазона)
    void setTaxRate(const double& rate);

    // Добавление статьи дохода.
    // income  — размер дохода (> 0)
    // taxable — true: облагается налогом, false: не облагается
    void addIncome(const double& income, const bool& taxable);

    // Вывод всех параметров на консоль
    void print() const;

private:
    char* inn_        = nullptr;  // ИНН
    int   year_       = 0;        // год расчета
    double taxable_   = 0.0;      // налогооблагаемый доход
    double nonTaxable_= 0.0;      // неналогооблагаемый доход
    double totalTax_  = 0.0;      // итог налога
    double totalIncome_ = 0.0;    // итог доходов
    double taxRate_   = kDefaultTaxRate; // процент налога

    // Вспомогательный приватный метод — освобождение ресурсов
    void freeInn();
};

#endif