#include "Taxpayer.h"

#include <iostream>
#include <string>

int main() {
    try {
        Taxpayer taxpayer("7707083893", 2024);
        
        taxpayer.addIncome(100000.0, true);
        taxpayer.addIncome(50000.0, true);
        taxpayer.addIncome(30000.0, false);

        taxpayer.print();
    }
}