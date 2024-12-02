#include "Shelf.h"

// Constructor
Shelf::Shelf(int productCount, int quantity) : products(std::make_unique<int[]>(quantity)), quantity(quantity) {
    if (quantity <= 0) {
        throw std::invalid_argument("Cantitatea trebuie sa fie mai mare decat 0.\n");
    }
    for (int i = 0; i < quantity; ++i) {
        products[i] = productCount;
    }
    std::cout << "Constructor: Raft creat cu " << quantity << " produse, fiecare având cantitatea " << productCount << ".\n";
}

// Destructor
Shelf::~Shelf() {
    std::cout << "Destructor: Resurse eliberate automat.\n";
}

// Move constructor
Shelf::Shelf(Shelf&& other) noexcept {
    std::lock_guard<std::mutex> lock(other.mtx);
    products = std::move(other.products);
    quantity = other.quantity;
    other.quantity = 0;
    std::cout << "Move Constructor: Resurse mutate.\n";
}

// Move assignment operator
Shelf& Shelf::operator=(Shelf&& other) noexcept {
    if (this != &other) {
        std::lock_guard<std::mutex> lock(other.mtx);
        products = std::move(other.products);
        quantity = other.quantity;
        other.quantity = 0;
        std::cout << "Move Assignment Operator: Resurse mutate.\n";
    }
    return *this;
}

// Getter
int Shelf::getProduct(int index) const {
    std::lock_guard<std::mutex> lock(mtx);
    if (index < 0 || index >= quantity) {
        throw std::out_of_range("Index invalid.\n");
    }
    return products[index];
}

// Setter
void Shelf::setProduct(int index, int count) {
    std::lock_guard<std::mutex> lock(mtx);
    if (index >= 0 && index < quantity) {
        products[index] = count;
    }
}

// Print
void Shelf::print() const {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Produsele de pe raft: ";
    for (int i = 0; i < quantity; ++i) {
        std::cout << products[i] << " ";
    }
    std::cout << "\n";
}

// AdvancedShelf
AdvancedShelf::AdvancedShelf(int productCount, int quantity, const std::string& label)
    : Shelf(productCount, quantity), label(label) {
    std::cout << "Constructor: Raft avansat creat cu eticheta \"" << label << "\".\n";
}

AdvancedShelf::~AdvancedShelf() {
    std::cout << "Destructor: Raft avansat cu eticheta \"" << label << "\" distrus.\n";
}

void AdvancedShelf::print() const {
    Shelf::print();
    std::cout << "Eticheta raftului: " << label << "\n";
}
