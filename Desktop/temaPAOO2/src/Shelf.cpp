#include "Shelf.h"

// Constructor - inițializează variabilele din listă de inițializare
Shelf::Shelf(int productCount, int quantity) : quantity(quantity) {
    products = new int[quantity];
    for (int i = 0; i < quantity; ++i) {
        products[i] = productCount;
    }
    std::cout << "Constructor: Raft creat cu " << quantity << " produse, fiecare având cantitatea " << productCount << ".\n";
    std::cout << "Memoria a fost alocată la adresa: " << products << "\n";
}

// Destructor - eliberăm memoria alocată pe heap
Shelf::~Shelf() {
    std::cout << "Destructor: Eliberăm memoria pentru raftul de produse la adresa: " << products << "\n";
    delete[] products;
    std::cout << "Memoria a fost eliberată.\n";
}

// Supraincarcare operator `=` pentru atribuirea unui raft la altul
Shelf& Shelf::operator=(const Shelf& other) {
    if (this == &other) return *this; // verificare auto-atribuire

    // Eliberăm memoria alocată anterior
    std::cout << "Operator = : Eliberăm memoria existentă pentru a atribui un nou raft.\n";
    delete[] products;

    // Alocăm din nou memorie și copiem valorile
    quantity = other.quantity;
    products = new int[other.quantity];
    for (int i = 0; i < other.quantity; ++i) {
        products[i] = other.products[i];
    }
    std::cout << "Operator = : Memoria nouă a fost alocată la adresa: " << products << "\n";
    return *this;
}

int Shelf::getProduct(int index) const {
    return products[index];
}

void Shelf::setProduct(int index, int count) {
    if (index >= 0 && index < quantity) {
        products[index] = count;
    }
}

void Shelf::print() const {
    std::cout << "Produsele de pe raft: ";
    for (int i = 0; i < quantity; ++i) {
        std::cout << products[i] << " ";
    }
    std::cout << std::endl;
}

