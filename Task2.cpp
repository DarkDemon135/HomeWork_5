#include <iostream>
#include <string>

using namespace std;

class Worker
{
    string surname;
    string name;
    string post;
    int year;
    int salary;
public:
    Worker() {}
    void Set();
    void Show();
    void PostList(string p);
    void SalaryList(int s);
    void ExperienceList(int y, int current);
};

void Worker::Set()
{
    cout << "Введите фамилию: "; cin >> surname;
    cout << "Введите имя: "; cin >> name;
    cout << "Введите должность: "; cin >> post;
    cout << "Введите год поступления: "; cin >> year;
    cout << "Введите зарплату: "; cin >> salary;
}

void Worker::Show()

{
    cout << "Имя :" << surname << " " << name << endl;
    cout << "Должность:" << post << endl;
    cout << "Год :" << year << endl;
    cout << "Зарплата:" << salary << endl;
}

void Worker::PostList(string p)

{
    if (post == p) cout << surname << " " << name << endl;
}

void Worker::SalaryList(int s)
{
    if (salary>s) cout << surname << " " << name << endl;
}

void Worker::ExperienceList(int y, int current)
{
    int Year = year - current;
    if (Year>y) cout << surname << " " << name << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите кол-во сотрудников: "; cin >> n;
    Worker* worker = new Worker[n];
    for (int i = 0; i<n; i++)
        worker[i].Set();
    cout << "Список сотрудников: " << endl;
    for (int i = 0; i<n; i++)
        worker[i].Show();
    string post;
    cout << "Введите должность: "; cin >> post;
    for (int i = 0; i<n; i++)
        worker[i].PostList(post);
    int salary;
    cout << "Введите зарплату: "; cin >> salary;
    for (int i = 0; i<n; i++)
        worker[i].SalaryList(salary);
    int current, year;
    cout << "Введите текущий год: "; cin >> current;
    cout << "Введите кол-во рабочих лет: "; cin >> year;
    for (int i = 0; i<n; i++)
        worker[i].ExperienceList(year, current);
    delete[] worker;
    return 0;
}