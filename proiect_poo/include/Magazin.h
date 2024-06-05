#ifndef MAGAZIN_H
#define MAGAZIN_H

#include <vector>
#include "Subprodus.h"

class Magazin {
private:
    vector<Produs*> produse;  // Lista de pointeri la produse (pentru a permite polimorfismul)

public:
    char *numeM=nullptr;
    char *adresaM=nullptr;
    Magazin(char *_numeM=(char*)"N/D",char *_adresaM=(char*)"N/D");
    ~Magazin();
    void adaugaProdus(Produs* produs);
    void afiseazaProduse() const;
    void stergeProdus(const char* numeProdus);
};

#endif // MAGAZIN_H
