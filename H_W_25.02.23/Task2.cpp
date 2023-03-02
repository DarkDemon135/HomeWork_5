#include "passport.h"
 
Passport::Passport(const string & _name,const string & _lname,const string & _patron,const string & _serial)
{
    name = _name;
    lname = _lname;
    patron = _patron;
    serial = _serial;
}
void Passport::Show() const
{
    cout << "Имя: " << name << endl;
    cout << "Фамилия: " << lname << endl;
    cout << "Отчество: " << patron << endl;
    cout << "Серийный номер: " << serial << endl;
}
ForeignPassport::ForeignPassport(const string & name,const string & lname,const string & patron,const string & serial,const string * _visa,const string & _id)
    :Passport(name,lname,patron,serial)
{
    for(int i=0;i<VisaSize;++i)
        visa[i] = _visa[i];
    id = _id;
}
ForeignPassport::ForeignPassport(const Passport & p,const string * _visa,const string & _id)
    :Passport(p)
{
    for(int i=0;i<VisaSize;++i)
        visa[i] = _visa[i];
    id = _id;
}
void ForeignPassport::Show() const
{
    Passport::Show();
    cout << "Номер загран. паспорта: " << id << endl;
    cout << "Доступные визы: " << endl;
    for(int i=0;i<VisaSize;++i)
        if(visa[i] != "")
            cout << visa[i] << endl;
}