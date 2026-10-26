#include "Taxpayer.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>
#include <string>


void Taxpayer::freeInn() {
    if (inn_ != nullptr) {
        delete[] inn_;
        inn_ = nullptr;
    }
}


Taxpayer::Taxpayer(const char* const inn, const int& year)
    : year_(year) {

    if (inn == nullptr) {
        throw std::string("Taxpayer::Taxpayer: ИНН не может быть nullptr");
    }

    const std::size_t len = std::strlen(inn);
    if (len == 0) {
        throw std::string("Taxpayer::Taxpayer: ИНН не может быть пустой строкой");
    }

    for (std::size_t i = 0; i < len; ++i) {
        if (inn[i] < '0' || inn[i] > '9') {
            throw std::string("Taxpayer::Taxpayer: ИНН должен содержать только цифры");
        }
    }

    if (len != 10 && len != 12) {
        throw std::string("Taxpayer::Taxpayer: ИНН должен содержать 10 или 12 цифр");
    }

    if (year < 1991 || year > 2100) {
        throw std::string("Taxpayer::Taxpayer: недопустимый год расчета");
    }

    inn_ = new char[len + 1];
    std::memset(inn_, 0, sizeof(char) * (len + 1));
    std::strcpy(inn_, inn);
}

Taxpayer::Taxpayer(const Taxpayer& other)
    : year_(other.year_)
    , taxable_(other.taxable_)
    , nonTaxable_(other.nonTaxable_)
    , totalTax_(other.totalTax_)
    , totalIncome_(other.totalIncome_)
    , taxRate_(other.taxRate_)
{
    if (other.inn_ != nullptr) {
        const std::size_t len = std::strlen(other.inn_);
        inn_ = new char[len + 1];
        std::memset(inn_, 0, sizeof(char) * (len + 1));
        std::strcpy(inn_, other.inn_);
    }
}

Taxpayer::~Taxpayer() {
    freeInn();
}


const char* const Taxpayer::getInn() const {
    return inn_;
}

int Taxpayer::getYear() const {
    return year_;
}

double Taxpayer::getTaxableIncome() const {
    return taxable_;
}

double Taxpayer::getNonTaxableIncome() const {
    return nonTaxable_;
}

double Taxpayer::getTotalTax() const {
    return totalTax_;
}

double Taxpayer::getTotalIncome() const {
    return totalIncome_;
}

double Taxpayer::getTaxRate() const {
    return taxRate_;
}


void Taxpayer::setTaxRate(const double& rate) {
    if (rate < 0.0 || rate > 100.0) {
        throw std::string("Taxpayer::setTaxRate: процент налога должен быть в диапазоне [0; 100]");
    }
    taxRate_ = rate;
}

void Taxpayer::addIncome(const double& income, const bool& taxable) {
    if (income <= 0.0) {
        throw std::string("Taxpayer::addIncome: доход должен быть положительным");
    }

    if (taxable) {
        taxable_ += income;
        totalTax_ += income * (taxRate_ / 100.0);
    } else {
        nonTaxable_ += income;
    }
    totalIncome_ += income;
}

void Taxpayer::print() const {
    std::printf("===== Налогоплательщик =====\n");
    std::printf("ИНН:                      %s\n", inn_ ? inn_ : "(нет)");
    std::printf("Год расчета:              %d\n", year_);
    std::printf("Налогооблагаемый доход:   %.2f руб.\n", taxable_);
    std::printf("Неналогооблагаемый доход: %.2f руб.\n", nonTaxable_);
    std::printf("Итог доходов:             %.2f руб.\n", totalIncome_);
    std::printf("Процент налога:           %.2f %%\n", taxRate_);
    std::printf("Итог подоходного налога:  %.2f руб.\n", totalTax_);
    std::printf("============================\n\n");
}