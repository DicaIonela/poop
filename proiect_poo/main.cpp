#include "Magazin.h"
#include "Administrator.h"
using namespace std;

void MeniuAdministrator()
{
    cout << "1. Autentificare" << endl;
    cout << "2. Adauga produs" << endl;
    cout << "3. Adauga subprodus" << endl;
    cout << "4. Afiseaza toate produsele" << endl;
    cout << "5. Sterge produs" << endl;
    cout << "6. Iesire" << endl;
    cout << "Alege o optiune: ";
}
void MeniuClient()
{
    cout << "1. Afiseaza toate produsele" << endl;
    cout << "2. Modifica-ti datele de conectare" << endl;
    cout << "3. Promotie disponibila pentru dumneavoastra" << endl;
    cout << "4. Cauta produs" << endl;
    cout << "4. Iesire" << endl;
    cout << "Alege o optiune: ";
}
void MeniuPrincipal()
{
    cout << "1. Administrator" << endl;
    cout << "2. Client" << endl;
    cout << "Alege o optiune: ";
}
int main()
{
    Magazin magazin;
    Administrator admin;
    bool autentificat = false;
    int optiune;
    if (!admin.incarcaDateleDinFisier("Administratori.txt"))
    {
        cerr << "Eroare la incarcarea datelor administratorilor." << endl;
        return 1;
    }
    MeniuPrincipal();
    int optmp;
    cin>>optmp;
    switch (optmp)
    {
    case 1:
    {
        string username, password;
        cout << "Introdu username: ";
        cin >> username;
        cout << "Introdu password: ";
        cin >> password;

        if (admin.autentificare(username, password))
        {
            cout << "Autentificare reusita!" << endl;
            do
            {
                MeniuAdministrator();
                int optiune;
                cin >> optiune;

                switch (optiune)
                {
                case 1:
                {
                    string username, password;
                    cout << "Introdu username: ";
                    cin >> username;
                    cout << "Introdu password: ";
                    cin >> password;

                    if (admin.autentificare(username, password))
                    {
                        autentificat = true;
                        cout << "Autentificare reusita!" << endl;
                    }
                    else
                    {
                        cout << "Autentificare esuata. Username sau parola gresita." << endl;
                    }
                    break;
                }
                case 2:
                {
                    if (!autentificat)
                    {
                        cout << "Trebuie sa fii autentificat pentru a adauga un produs." << endl;
                        break;
                    }
                    char numeP[100];
                    int codcategorie;

                    cout << "Introdu numele produsului: ";
                    cin.ignore();
                    cin.getline(numeP, 100);
                    cout << "Introdu codul categoriei: ";
                    cin >> codcategorie;

                    Produs* produs = new Produs(numeP, codcategorie);
                    magazin.adaugaProdus(produs);
                    cout << "Produs adaugat cu succes!" << endl;
                    break;
                }
                case 3:
                {
                    if (!autentificat)
                    {
                        cout << "Trebuie sa fii autentificat pentru a adauga un subprodus." << endl;
                        break;
                    }
                    char numeP[100], numeS[30];
                    int codcategorie, greutate, nrproduse;

                    cout << "Introdu numele produsului: ";
                    cin.ignore();
                    cin.getline(numeP, 100);
                    cout << "Introdu codul categoriei: ";
                    cin >> codcategorie;
                    cout << "Introdu numele subprodusului: ";
                    cin.ignore();
                    cin.getline(numeS, 30);
                    cout << "Introdu greutatea: ";
                    cin >> greutate;
                    cout << "Introdu numarul de produse: ";
                    cin >> nrproduse;

                    Produs* subprodus = new Subprodus(numeP, codcategorie, numeS, greutate, nrproduse);
                    magazin.adaugaProdus(subprodus);
                    cout << "Subprodus adaugat cu succes!" << endl;
                    break;
                }
                case 4:
                {
                    magazin.afiseazaProduse();
                    break;
                }
                case 5:
                {
                    if (!autentificat)
                    {
                        cout << "Trebuie sa fii autentificat pentru a sterge un produs." << endl;
                        break;
                    }
                    char numeProdus[100];
                    cout << "Introdu numele produsului de sters: ";
                    cin.ignore();
                    cin.getline(numeProdus, 100);

                    magazin.stergeProdus(numeProdus);
                    cout << "Produs sters (daca a fost gasit)!" << endl;
                    break;
                }

                case 6:
                {
                    cout << "Iesire..." << endl;
                    break;
                }
                default:
                {
                    cout << "Optiune invalida. Te rog sa incerci din nou." << endl;
                    break;
                }
                }
            }
            while (optiune != 6);
        }
        else
        {
            cout << "Autentificare esuata. Username sau parola gresita." << endl;
        }
    }

    case 2:
        MeniuClient();
    }
}
