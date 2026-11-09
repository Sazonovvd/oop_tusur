#include "Taxpayer.h"
#include <cstring>
#include <cctype>
#include <stdexcept>

// Проверка корректности ИНН
void TaxPayer::validateInn(const char* inn) const {
    if (inn == nullptr) {
        throw std::invalid_argument("ИНН не может быть nullptr");
    }
    size_t len = std::strlen(inn);
    if (len == 0) {
        throw std::invalid_argument("ИНН не может быть пустым");
    }
    if (len != 10 && len != 12) {
        throw std::invalid_argument("Длина ИНН должна быть 10 или 12 символов");
    }
    for (size_t i = 0; i < len; ++i) {
        if (!std::isdigit(static_cast<unsigned char>(inn[i]))) {
            throw std::invalid_argument("ИНН должен содержать только цифры");
        }
    }
}

// Проверка корректности года
void TaxPayer::validateYear(int year) const {
    if (year < 2000 || year > 2100) {
        throw std::invalid_argument("Год расчёта должен быть в диапазоне от 2000 до 2100");
    }
}

// Конструктор с параметрами
TaxPayer::TaxPayer(const char* inn, int year)
    : inn_(nullptr),
      year_(year),
      taxableIncome_(0.0),
      nonTaxableIncome_(0.0),
      totalTax_(0.0),
      totalIncome_(0.0),
      taxRate_(13.0) {
    validateInn(inn);
    validateYear(year);
    inn_ = new char[std::strlen(inn) + 1];
    std::strcpy(inn_, inn);
}

// Конструктор копирования
TaxPayer::TaxPayer(const TaxPayer& other)
    : year_(other.year_),
      taxableIncome_(other.taxableIncome_),
      nonTaxableIncome_(other.nonTaxableIncome_),
      totalTax_(other.totalTax_),
      totalIncome_(other.totalIncome_),
      taxRate_(other.taxRate_) {
    inn_ = new char[std::strlen(other.inn_) + 1];
    std::strcpy(inn_, other.inn_);
}

// Оператор присваивания
TaxPayer& TaxPayer::operator=(const TaxPayer& other) {
    if (this != &other) {
        delete[] inn_;
        inn_ = new char[std::strlen(other.inn_) + 1];
        std::strcpy(inn_, other.inn_);
        year_ = other.year_;
        taxableIncome_ = other.taxableIncome_;
        nonTaxableIncome_ = other.nonTaxableIncome_;
        totalTax_ = other.totalTax_;
        totalIncome_ = other.totalIncome_;
        taxRate_ = other.taxRate_;
    }
    return *this;
}

// Деструктор
TaxPayer::~TaxPayer() {
    delete[] inn_;
}

// Селекторы
const char* TaxPayer::getInn() const { return inn_; }
int TaxPayer::getYear() const { return year_; }
double TaxPayer::getTaxableIncome() const { return taxableIncome_; }
double TaxPayer::getNonTaxableIncome() const { return nonTaxableIncome_; }
double TaxPayer::getTotalTax() const { return totalTax_; }
double TaxPayer::getTotalIncome() const { return totalIncome_; }
double TaxPayer::getTaxRate() const { return taxRate_; }

// Установка процента налога с проверкой
void TaxPayer::setTaxRate(double rate) {
    if (rate <= 0.0 || rate > 100.0) {
        throw std::invalid_argument("Процент налога должен быть больше 0 и не более 100");
    }
    taxRate_ = rate;
}

// Добавление дохода
void TaxPayer::addIncome(double amount, bool isTaxable) {
    if (amount <= 0.0) {
        throw std::invalid_argument("Доход должен быть положительным");
    }
    if (isTaxable) {
        taxableIncome_ += amount;
        totalTax_ += amount * taxRate_ / 100.0;
    } else {
        nonTaxableIncome_ += amount;
    }
    totalIncome_ += amount;
}

// Вывод всех параметров
void TaxPayer::print() const {
    std::cout << "ИНН: " << inn_ << std::endl;
    std::cout << "Год расчёта: " << year_ << std::endl;
    std::cout << "Налогооблагаемый доход: " << taxableIncome_ << std::endl;
    std::cout << "Неналогооблагаемый доход: " << nonTaxableIncome_ << std::endl;
    std::cout << "Итог суммы подоходного налога: " << totalTax_ << std::endl;
    std::cout << "Итог суммы доходов: " << totalIncome_ << std::endl;
    std::cout << "Процент подоходного налога: " << taxRate_ << "%" << std::endl;
}