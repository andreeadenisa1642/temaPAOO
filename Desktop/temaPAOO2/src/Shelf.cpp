#include "Shelf.h"

// Constructor clasa de baza - inițializează variabilele din listă de inițializare
Shelf::Shelf(int productCount, int quantity) : quantity(quantity) {
	if (quantity <= 0) {
    	throw std::invalid_argument("Cantitatea trebuie sa fie mai mare decat 0.\n");
    	}
	
    products = new int[quantity];
    for (int i = 0; i < quantity; ++i) {
        products[i] = productCount;
    }
    std::cout << "Constructor: Raft creat cu " << quantity << " produse, fiecare având cantitatea " << productCount << ".\n";
    std::cout << "Memoria a fost alocată la adresa: " << products << "\n";
}

// Destructor clasei de baza - eliberăm memoria alocată pe heap
Shelf::~Shelf() {
    std::cout << "Destructor: Eliberăm memoria pentru raftul de produse la adresa: " << products << "\n";
    delete[] products;
    std::cout << "Memoria a fost eliberată.\n";
}

/*
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
*/

//Copy constructor
/*
Shelf::Shelf(const Shelf& other) : quantity(other.quantity) {
    products = new int[quantity];
    for (int i = 0; i < quantity; ++i) {
        products[i] = other.products[i];
    }
    std::cout << "Copy Constructor: Raft copiat. Memoria alocată la adresa: " << products << "\n";
}
*/


//Move constructor
Shelf::Shelf(Shelf&& other) noexcept : products(other.products), quantity(other.quantity) {
    other.products = nullptr;
    other.quantity = 0;
    std::cout << "Move Constructor: Resurse mutate. Memoria a fost transferată la adresa: " << products << "\n";
}


// Move assignment operator
Shelf& Shelf::operator=(Shelf&& other) noexcept {
    if (this != &other) {
       delete[] products;  // Eliberăm resursele curente
        
        // Mutăm resursele
        products = other.products;
        quantity = other.quantity;

        // Resetăm obiectul sursă
        other.products = nullptr;
        other.quantity = 0;

        std::cout << "Move Constructor: Resurse mutate. Memoria a fost transferată la adresa: " << products << "\n";
    }
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

// Constructorul clasei derivate
AdvancedShelf::AdvancedShelf(int productCount, int quantity, const std::string& label)
    : Shelf(productCount, quantity), label(label) {
    std::cout << "Constructor: Raft avansat creat cu eticheta \"" << label << "\".\n";
}

// Destructorul clasei derivate
AdvancedShelf::~AdvancedShelf() {
    std::cout << "Destructor: Raft avansat cu eticheta \"" << label << "\" distrus.\n";
}

// Suprascriere funcție print
void AdvancedShelf::print() const {
    Shelf::print();
    std::cout << "Eticheta raftului: " << label << "\n";
}

