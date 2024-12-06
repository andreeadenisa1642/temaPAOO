#include <iostream>
#include <thread>
#include "Shelf.h"

void accessShelf(Shelf& shelf, int index, int newValue) {
    try {
        int currentValue = shelf.getProduct(index);
        std::cout << "Produsul de la indexul " << index << " are cantitatea " << currentValue << ".\n";
        shelf.setProduct(index, newValue);
        std::cout << "Cantitatea a fost actualizată la " << newValue << ".\n";
    } catch (const std::exception& e) {
        std::cerr << "Eroare: " << e.what() << "\n";
    }
}

int main() {
    std::cout << "Instanțierea unui obiect de tip Shelf:\n";
    Shelf shelf1(10, 3);
    shelf1.print();

    std::cout << "\nMutarea resurselor unui Shelf într-un alt Shelf:\n";
    Shelf shelf2 = std::move(shelf1); // Constructorul de mutare este utilizat aici
    shelf2.print();

    std::cout << "\nInstanțierea unui obiect de tip AdvancedShelf:\n";
    AdvancedShelf shelf3(5, 4, "Raft special");
    shelf3.print();

    std::cout << "\nAcces simultan la un Shelf folosind thread-uri:\n";
    std::thread t1(accessShelf, std::ref(shelf3), 1, 20);
    std::thread t2(accessShelf, std::ref(shelf3), 2, 30);

    t1.join();
    t2.join();

    std::cout << "\nUtilizarea unui SharedShelf:\n";
    SharedShelf shared1("Resursa Partajată 1");
    SharedShelf shared2 = shared1; // Partajare resursă între obiecte
    shared1.useResource();
    shared2.useResource();

    std::cout << "\nSfârșitul programului.\n";
    return 0;
}
