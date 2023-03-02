#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
 
class Firma
{
private:
 
    string company_name;
    string owner;
    string phone;
    string adress;
    string occupation;
 
public:
    Firma() = default;
    Firma(const string &name, const string &own,
          const string &nphone, const string &adr, const string &occup);
    void Set(const string &name, const string &own,
             const string &nphone, const string &adr, const string &occup);
    void SetFirmName(const string &n);
    void SetOwnerName(const string &on);
    void SetPhone(const string &p);
    void SetAdress(const string &a);
    void SetOccupation(const string &o);
 
    string GetFirmName() const;
    string GetOwnerName() const;
    string GetPhone() const;
    string GetAdress() const;
    string GetOccupation() const;
    friend bool operator == (const Firma &lh, const Firma &rh);
    friend ostream &operator << (ostream &os, const Firma &f);
};
 
 
// Firma.cpp
 
Firma::Firma(const string &name, const string &own, const string &nphone, const string &adr, const string &occup)
{
    Set(name, own, nphone, adr, occup);
}
 
void Firma::Set(const string &name, const string &own, const string &nphone, const string &adr, const string &occup)
{
    company_name = name;
    owner = own;
    phone = nphone;
    adress = adr;
    occupation = occup;
}
 
 
void Firma::SetFirmName(const string &n) {
    company_name = n;
}
void Firma::SetOwnerName(const string &on) {
    owner = on;
}
void Firma::SetPhone(const string &p) {
    phone = p;
}
void Firma::SetAdress(const string &a) {
    adress = a;
}
void Firma::SetOccupation(const string &o) {
    occupation = o;
}
 
string Firma::GetFirmName() const {
    return company_name;
}
string Firma::GetOwnerName() const {
    return owner;
}
string Firma::GetPhone() const {
    return phone;
}
string Firma::GetAdress() const {
    return adress;
}
string Firma::GetOccupation() const {
    return occupation;
}
 
bool operator == (const Firma &lh, const Firma &rh)
{
    return lh.company_name == rh.company_name
        && lh.owner == rh.owner
        && lh.phone == rh.phone
        && lh.adress == rh.adress
        && lh.occupation == rh.occupation;
}
 
ostream &operator << (ostream &os, const Firma &f)
{
    return os
        << f.company_name << '\n'
        << f.owner << '\n'
        << f.phone << '\n'
        << f.adress << '\n'
        << f.occupation << '\n'
        << endl;
}
 
 
// Handbook.h
 
class Handbook
{
private:
    vector<Firma> items;
public:
    void AddItem(const Firma &i);
    bool DeleteItem(const Firma &i);
    void PrintAll(ostream &os);
 
    bool FindByFirmName(const string &name, Firma &f);
    bool FindByOwner(const string &owner, Firma &f);
    bool FindByPhone(const string &phone, Firma &f);
    bool FindByAdress(const string &adress, Firma &f);
    bool FindByOccupation(const string &occupation, Firma &f);
 
    Handbook FindByOwner(const string &owner);
 
    void saveFirms(const string &filename);
    void readFromFirms(const string &filename);
};
 
// Handbook.cpp
 
void Handbook::AddItem(const Firma &i) {
    items.push_back(i);
}
 
bool Handbook::DeleteItem(const Firma &i)
{
    for (vector<Firma>::iterator it = items.begin(); it != items.end(); ++it)
        if (*it == i) {
            items.erase(it);
            return true;
        }
    return false;
}
 
void Handbook::PrintAll(ostream &os) {
    if (items.empty()) {
        os << "Handbook is empty";
        return;
    }
    for (vector<Firma>::iterator it = items.begin(); it != items.end(); ++it) {
        os << *it;
    }
}
 
bool Handbook::FindByFirmName(const string &name, Firma &f) {
    for (vector<Firma>::iterator it = items.begin(); it != items.end(); ++it)
        if (it->GetFirmName() == name) {
            f = *it;
            return true;
        }
    return false;
}
 
bool Handbook::FindByOwner(const string &owner, Firma &f) {
    for (vector<Firma>::iterator it = items.begin(); it != items.end(); ++it)
        if (it->GetOwnerName() == owner) {
            f = *it;
            return true;
        }
    return false;
}
 
bool Handbook::FindByPhone(const string &phone, Firma &f) {
    for (vector<Firma>::iterator it = items.begin(); it != items.end(); ++it)
        if (it->GetPhone() == phone) {
            f = *it;
            return true;
        }
    return false;
}
 
bool Handbook::FindByAdress(const string &adress, Firma &f) {
    for (vector<Firma>::iterator it = items.begin(); it != items.end(); ++it)
        if (it->GetAdress() == adress) {
            f = *it;
            return true;
        }
    return false;
}
 
bool Handbook::FindByOccupation(const string &occupation, Firma &f) {
    for (vector<Firma>::iterator it = items.begin(); it != items.end(); ++it)
        if (it->GetOccupation() == occupation) {
            f = *it;
            return true;
        }
    return false;
}
 
Handbook Handbook::FindByOwner(const string &owner) {
    Handbook t;
    for (vector<Firma>::iterator it = items.begin(); it != items.end(); ++it)
        if (it->GetOwnerName() == owner) {
            t.AddItem(*it);
        }
    return t;
}
 
 
 
void Handbook::saveFirms(const string &filename)
{
    ofstream fs;
    fs.open(filename, fstream::out);
    if (fs.is_open()) {
        for (vector<Firma>::iterator it = items.begin(); it != items.end(); ++it) {
            fs << "FirmName: " << it->GetFirmName() << endl
                << "OwnerName: " << it->GetOwnerName() << endl
                << "Phone: " << it->GetPhone() << endl
                << "Adress: " << it->GetAdress() << endl
                << "Occupation: " << it->GetOccupation() << endl
                << "---------------------------" << endl;
        }
    }
    fs.close();
}
 
void Handbook::readFromFirms(const string &filename)
{
    ifstream fs;
    Firma firma;
    string buf;
    int j = 0;
    items.clear();
    fs.open(filename, ios::in);
    if (fs.is_open())
    {
        do
        {
            fs >> buf >> buf;
            firma.SetFirmName(buf);
            fs >> buf >> buf;
            firma.SetOwnerName(buf);
            fs >> buf >> buf;
            firma.SetPhone(buf);
            fs >> buf >> buf;
            firma.SetAdress(buf);
            fs >> buf >> buf;
            firma.SetOccupation(buf);
            fs >> buf;
            if (!fs.eof())
                items.push_back(firma);
        } while (!fs.eof());
    }
    fs.close();
}
 
// main.cpp
 
const char *indata[][5] = {
    { "Peter-I",    "Peter",    "Phone0", "Adress0", "Occupation0" },
    { "Boanerges",  "John",     "Phone1", "Adress1", "Occupation1" },
    { "Thomas&Co",  "Thomas",   "Phone2", "Adress2", "Occupation2" },
    { "J&J",        "John",     "Phone3", "Adress3", "Occupation3" },
    { "Peter-II",   "Peter",    "Phone4", "Adress4", "Occupation4" },
    { "Peter-III",  "Peter",    "Phone5", "Adress5", "Occupation5" }
};
 
const char *succ = "Success!\n";
const char *fail = "Fail ((\n";
 
int main() {
    string filename = "Firms.txt";
    Handbook h;
    Firma f;
    for (size_t i = 0; i < sizeof(indata) / sizeof(indata[0]); ++i) {
        f.Set(indata[i][0], indata[i][1], indata[i][2], indata[i][3], indata[i][4]);
        h.AddItem(f);
    }
 
    cout << "--- Initial data:\n";
    h.PrintAll(cout);
 
    h.saveFirms(filename);
    h.readFromFirms(filename);
    cout << "--- Data from file:\n";
    h.PrintAll(cout);
 
    cout << "--- Find by FirmName:\n";
    if (h.FindByFirmName(indata[1][0], f))
        cout << succ << "\"" << indata[1][0] << "\" found\n" << f << endl;
    else
        cout << fail << "\"" << indata[1][0] << "\" not found" << endl;
 
    if (h.FindByFirmName(indata[1][1], f))
        cout << succ << "\"" << indata[1][1] << "\" found\n" << f << endl;
    else
        cout << fail << "\"" << indata[1][1] << "\" not found" << endl;
 
    cout << "--- Find by Owner:\n";
    if (h.FindByOwner(indata[4][1], f))
        cout << succ << "\"" << indata[4][1] << "\" found\n" << f << endl;
    else
        cout << fail << "\"" << indata[4][1] << "\" not found" << endl;
 
    if (h.FindByOwner(indata[4][2], f))
        cout << succ << "\"" << indata[4][2] << "\" found\n" << f << endl;
    else
        cout << fail << "\"" << indata[4][2] << "\" not found" << endl;
 
    // ... etc.
 
    // find all occurrences!
    cout << "--- Find by Owner all occurrences of \"" << indata[4][1] << "\":\n";
    Handbook found = h.FindByOwner(indata[4][1]);
    found.PrintAll(cout);
 
    cout << "--- Find by Owner all occurrences of \"" << indata[4][2] << "\":\n";
    found = h.FindByOwner(indata[4][2]);
    found.PrintAll(cout);
 
    return 0;
}