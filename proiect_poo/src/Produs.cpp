#include "Produs.h"

Produs::Produs(char *_numeP, int _codcategorie)
{
    numeP=new char[strlen(_numeP)+1];
    strcpy (numeP, _numeP);
    codcategorie=_codcategorie;
}

Produs::~Produs()
{
    if (numeP!=nullptr)
        delete[] numeP;
}
Produs::Produs(const Produs &p)
{
    if (this!=&p)
    {
        numeP=new char[strlen(p.numeP)+1];
        strcpy (numeP, p.numeP);
        codcategorie=p.codcategorie;
    }
}


void Produs::setNumeProdus(char* numeProdus)
{
    if(numeP!=nullptr)
    {
        delete[] numeP;
    }
    numeP=new char[strlen(numeProdus)+1];
    strcpy (numeP, numeProdus);
}
int Produs::getcodcategorie()
{
    return codcategorie;
}
char *Produs::getNumeProdus()
{
    return numeP;
}
void Produs::setcodcategorie(int codcategorie)
{
    this->codcategorie=codcategorie;
}
ostream& operator <<(ostream &ostr, Produs &p)
{
    ostr<<"\nNumele categoriei:"<<p.numeP<<"\nCod categorie:"<<p.codcategorie;
    return ostr;
}
istream& operator >>(istream &istr, Produs &p)
{
    cout<<"Numele produsului:"<<endl;
    istr>>p.buf;
    p.numeP=new char[strlen(p.buf)+1];
    strcpy (p.numeP, p.buf);
    cout<<",Cod:";
        istr>>p.codcategorie;
    return istr;
}
Produs& Produs::operator=(const Produs &p)
{
    if(numeP!=nullptr)
    {
        delete[] numeP;
        numeP=new char[strlen(p.numeP)+1];
        strcpy (numeP, p.numeP);
        codcategorie=p.codcategorie;
    }
    return *this;
}
void Produs::AfisareProdus() {
    cout << "Nume: " << numeP << ", Cod categorie: " << codcategorie << endl;
}


