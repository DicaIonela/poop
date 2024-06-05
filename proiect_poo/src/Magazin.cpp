#include "Magazin.h"

Magazin::Magazin( char *_numeM,char *_adresaM)
{
    numeM=new char[strlen(_numeM)+1];
    strcpy (numeM, _numeM);
    adresaM=new char[strlen(_adresaM)+1];
    strcpy (adresaM, _adresaM);
}
Magazin::~Magazin() {
    for (auto produs : produse) {
        delete produs;
    }
}

void Magazin::adaugaProdus(Produs* produs) {
    produse.push_back(produs);
}

void Magazin::afiseazaProduse() const {
    for (const auto& produs : produse) {
        produs->AfisareProdus();
        cout << endl;
    }
}

void Magazin::stergeProdus(const char* numeProdus) {
    auto it = produse.begin();
    while (it != produse.end()) {
        if (strcmp((*it)->getNumeProdus(), numeProdus) == 0) {
            delete *it;
            it = produse.erase(it);
        } else {
            ++it;
        }
    }
}
