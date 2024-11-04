#ifndef SHELF_H
#define SHELF_H

#include <iostream>

class Shelf {
private:
    int* products; // pointer către un bloc de memorie pentru produsele de pe raft
    int quantity;

public:
    // Constructor pentru inițializare
    Shelf(int productCount, int quantity);
    
    // Destructor pentru eliberarea memoriei
    ~Shelf();

    // Supraincarcare operator `=` pentru atribuirea unui raft la altul
    Shelf& operator=(const Shelf& other);

    // Getter pentru cantitatea de produse de la un anumit index
    int getProduct(int index) const;

    // Setter pentru actualizarea cantității de produse la un anumit index
    void setProduct(int index, int count);

    // Metodă pentru afișarea cantităților de produse de pe raft
    void print() const;
};

#endif

