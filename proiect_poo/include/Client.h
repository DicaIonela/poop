#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct DateClienti {
    string username;
    string password;
};

class Client {
private:
    vector<DateClienti> dateClienti; // lista de administratori

public:
    Client();
    bool autentificare(const string& username, const string& password);
    bool incarcaDateleDinFisier(const string& numeFisier);
};
#endif // CLIENT_H
