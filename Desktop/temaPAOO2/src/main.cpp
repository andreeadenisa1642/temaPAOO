#include <iostream>
#include "Shelf.h"

int main() {
    std::cout << "Instanțierea unui obiect de tip Shelf:\n";
    Shelf shelf1(10, 3);
    shelf1.print();

    std::cout << "\nInstanțierea unui obiect de tip AdvancedShelf:\n";
    AdvancedShelf shelf2(5, 4, "Raft special");
    shelf2.print();

    std::cout << "\nUtilizarea unui pointer de tip Shelf pentru un AdvancedShelf:\n";
    Shelf* ptr = new AdvancedShelf(7, 2, "Raft dinamic");
    ptr->print();

    std::cout << "\nEliberarea memoriei alocate dinamic:\n";
    delete ptr;

    std::cout << "\nSfârșitul programului.\n";
    return 0;
}

