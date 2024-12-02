#ifndef SHELF_H
#define SHELF_H

#include <iostream>
#include <memory>
#include <mutex>
#include <string>

class Shelf {
private:
    std::unique_ptr<int[]> products; // Gestionare automată a resurselor
    int quantity;
    mutable std::mutex mtx; // Mutex pentru sincronizare

public:
    explicit Shelf(int productCount, int quantity);

    // Dezactivare funcții generate de compilator pe care nu le dorim
    Shelf() = delete;
    Shelf(const Shelf& other) = delete;
    Shelf& operator=(const Shelf& other) = delete;

    // Copy constructor și operator de mutare
    Shelf(Shelf&& other) noexcept;
    Shelf& operator=(Shelf&& other) noexcept;

    virtual ~Shelf();

    int getProduct(int index) const;
    void setProduct(int index, int count);

    virtual void print() const;
};

// Clasa derivată AdvancedShelf
class AdvancedShelf : public Shelf {
private:
    std::string label;

public:
    AdvancedShelf(int productCount, int quantity, const std::string& label);
    ~AdvancedShelf() override;

    void print() const override;
};

#endif
