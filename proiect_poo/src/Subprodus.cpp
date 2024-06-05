#include "Subprodus.h"

Subprodus::Subprodus(char *_numeP, int _codcategorie,char *_numeS, int _greutate, int _nrproduse):Produs(_numeP,_codcategorie)
{
    strcpy (numeS, _numeS);
    greutate=_greutate;
    nrproduse=_nrproduse;
}

Subprodus::~Subprodus()
{
    if (numeS!=nullptr)
        delete[] numeS;
}
Subprodus::Subprodus(const Subprodus &s)
{
    if (this!=&s)
    {
        strcpy (numeS,s.numeS);
        greutate=s.greutate;
        nrproduse=s.nrproduse;
    }
}


void Subprodus::setNumeSubprodus(char* numeSubprodus)
{
    if(numeS!=nullptr)
    {
        delete[] numeS;
    }
    strcpy (numeS, numeSubprodus);
}
int Subprodus::getgreutate()
{
    return greutate;
}
int Subprodus::getnrproduse()
{
    return nrproduse;
}
char *Subprodus::getNumeSubprodus()
{
    return numeS;
}
void Subprodus::setgreutate(int greutate)
{
    this->greutate=greutate;
}
void Subprodus::setnrproduse(int nrproduse)
{
    this->nrproduse=nrproduse;
}
ostream& operator <<(ostream &ostr, Subprodus &s)
{
    ostr<<"\nCategorie:"<<s.getNumeProdus()<<"\nNumele produsului:"<<s.numeS<<"\nGreutate:"<<s.greutate<<"\nNr. produse in stoc:"<<s.nrproduse;
    return ostr;
}
istream& operator >>(istream &istr, Subprodus &s)
{
    cout<<"Introdu datele:"<<endl;
    cout<<"Categorie produs:"<<endl;
    istr>>(Produs&)s;
    cout<<"\nNumele produsului:"<<endl;
    istr>>s.buf;
    s.numeP=new char[strlen(s.buf)+1];
    strcpy (s.numeP, s.buf);
    cout<<"\nGreutate:";
    istr>>s.greutate;
    cout<<"\nNrProduse:";
    istr>>s.nrproduse;
    return istr;
}
Subprodus& Subprodus::operator=(const Subprodus &s)
{
    if(numeS!=nullptr)
    {
        delete[] numeS;
        strcpy (numeS, s.numeS);
        greutate=s.greutate;
    }
    return *this;
}
char* Subprodus::retProdusSubprodus()
{
    int lenP=strlen(getNumeProdus());
    int lenS= strlen(numeS);
    char* rez= new  char[lenP+lenS+1];
    sprintf (rez, "%s: %s", getNumeProdus(),numeS);
    return rez;
}
bool operator ==(const Subprodus &a, const Subprodus &b)
{
    return (strcmp (a.numeS,b.numeS)==0);
}
 Subprodus& Subprodus::operator+(int nradd)
{
    this->nrproduse += nradd;
    return *this;
}
Subprodus& Subprodus::operator- (int nrsc)
{
    this->nrproduse-=nrsc;
    return *this;
}
void Subprodus::AfisareSubprodus() {

    cout << "Nume subprodus: " << numeS << ", Greutate: " << greutate << ", Numar produse: " << nrproduse << endl;
}

