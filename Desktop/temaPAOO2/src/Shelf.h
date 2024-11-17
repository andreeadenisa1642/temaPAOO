#ifndef SHELF_H
#define SHELF_H

#include <iostream>

class Shelf {
private:
    int* products; // pointer către un bloc de memorie pentru produsele de pe raft
    int quantity;

public:
    // Constructor pentru inițializare
     explicit Shelf(int productCount, int quantity);
        
    // Dezactivare funcții generate de compilator pe care nu le dorim
    Shelf() = delete;
    Shelf(const Shelf& other) = delete;
    Shelf& operator=(const Shelf& other) = delete;
    
    // Copy constructor
    //Shelf(const Shelf& other);
    
    // Move constructor
    Shelf(Shelf&& other) noexcept;
    
    // Move assignment operator
    Shelf& operator=(Shelf&& other) noexcept;
    
    // Destructor virtual pentru eliberarea memoriei si suport polimorfism
    virtual ~Shelf();

    // Supraincarcare operator `=` pentru atribuirea unui raft la altul
    //Shelf& operator=(const Shelf& other);

    // Getter pentru cantitatea de produse de la un anumit index
    int getProduct(int index) const;

    // Setter pentru actualizarea cantității de produse la un anumit index
    void setProduct(int index, int count);

    // Metodă pentru afișarea cantităților de produse de pe raft
    virtual void print() const;
};

// Clasa derivată AdvancedShelf
class AdvancedShelf : public Shelf {
private:
    std::string label; // etichetă pentru raft

public:
    // Constructor specific clasei derivate
    AdvancedShelf(int productCount, int quantity, const std::string& label);

    // Destructor
    ~AdvancedShelf() override;

    // Suprascriere funcție print
    void print() const override;
};

#endif

