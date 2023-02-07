#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
 
using namespace std;
 
string SOGL = "бвгджзйклмнпрстфхцчшщъьБВГДЖЗЙКЛМНПРСТФХЦЧШЩЪЬ";
string GLAS = "аеэиоуюяыАЕЭИОУЮБЫ";
string NUMB = "1234567890";
 
bool search(char ch, string arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (ch == arr[i]) {
            return true;
        }
    }
}
 
int symFile() {
    int sym = 0;
    ifstream N("file.txt");
    if (!N)
    {
        exit(-1);
    }
    else
    {
        while (!N.eof())
        {
            char ch;
            N >> ch;
            sym++;
        }
    }
 
    return sym - 1;
}
 
int strFile() {
    int str = 0;
    ifstream N("file.txt");
    if (!N) {
        exit(-1);
    }
    else {
        string line;
        while (getline(N, line)) {
            str++;
        }
    }
    N.close();
    return str;
}
 
int glasFile() {
    int glas = 0;
    ifstream N("file.txt");
    if (!N)
    {
        exit(-1);
    }
    else
    {
        while (!N.eof())
        {
            char ch;
            N >> ch;
            if (search(ch, GLAS) == true) {
                glas++;
            }
        }
    }
    N.close();
    return glas;
}
 
int soglFile() {
    int sogl = 0;
    ifstream N("file.txt");
    if (!N)
    {
        exit(-1);
    }
    else
    {
        while (!N.eof())
        {
            char ch;
            N >> ch;
            if (search(ch, SOGL) == true) {
                sogl++;
            }
        }
    }
    N.close();
    return sogl;
}
 
int numbFile() {
    int numb = 0;
    ifstream N("file.txt");
    if (!N)
    {
        exit(-1);
    }
    else
    {
        while (!N.eof())
        {
            char ch;
            N >> ch;
            if (search(ch, NUMB) == true) {
                numb++;
            }
        }
    }
    N.close();
    return numb;
}
 
int main()
{
    
    int SYM = symFile();
    int STR = strFile();
    int Glas = glasFile();
    int Sogl = soglFile();
    int Numb = numbFile();
 
    cout << "Символов в Файле: " << SYM << endl;
    cout << "Строк в Файле: " << STR << endl;
    cout << "Гласных в Файле: " << Glas << endl;
    cout << "Согласных в Файле: " << Sogl << endl;
    cout << "Чисел в Файле: " << Numb << endl;
          
    ofstream out("out.txt");
    out << "Символов в Файле: " << SYM << endl;
    out << "Строк в Файле: " << STR << endl;
    out << "Гласных в Файле: " << Glas << endl;
    out << "Согласных в Файле: " << Sogl << endl;
    out << "Чисел в Файле: " << Numb << endl;
    out.close();
 
    cout << endl;
    return 0;
}