#include <iostream>
#include "Shelf.h"

int main() {
    // Creăm primul obiect Shelf
    std::cout << "Creăm shelf1:\n";
    Shelf shelf1(10, 3); // raftul conține 3 produse, fiecare având cantitatea 10
    shelf1.print();

    // Creăm al doilea obiect Shelf
    std::cout << "\nCreăm shelf2:\n";
    Shelf shelf2(5, 3); // raftul conține 3 produse, fiecare având cantitatea 5
    shelf2.print();

    // Testăm supraincarcarea operatorului de atribuire
    std::cout << "\nAtribuim shelf1 lui shelf2:\n";
    shelf2 = shelf1; // operator=
    shelf2.print();

    std::cout << "\nSfârșitul programului - se apelează destructori pentru shelf1 și shelf2.\n";
    return 0;
}

