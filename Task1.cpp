#include<iostream>
#include<locale.h>
#include<stdlib.h>
#include<string.h> 
#include<wchar.h>
void show(int mode, int i);
using namespace std;
class Book
{
private:
	char author[100];
	char title[100];
	char publishing[100];
	int year;
	int count_of_page;
public:
 
	int sravi(int y)
	{
		if (year >= y) return 0;
		else return 1;     
	}
	int srpb(char s[])
	{
		if (strcmp(s, publishing) == 0) return 0;
		else return 1;
	}
	int srav(char s[])
	{
		if (strcmp(s, author) == 0) return 0;
		else return 1;
	}
	void get(void)
	{
		cout << "Автор : " << author << endl;
 
		cout << "Название книги : " << title << endl;
		cout << "Издательство : " << publishing << endl;
		cout << "Год : " << year << endl;
		cout << "Количество страниц : " << count_of_page << endl;
	}
	void set(void)
	{
		cout << "Введите имя автора книги : " << endl;
		cin.get();
		cin.getline(author, 100);
		cout << "Введите название книги : " << endl;
		cin.getline(title, 100);
		cout << "Введите назавние издательства : " << endl;
		cin.getline(publishing, 100);
		cout << "Введите год издания книги : " << endl;
		cin >> year;
		cout << "Введите количество страниц : " << endl;
		cin >> count_of_page;
	}
	friend int alphabit(Book &a, Book &b);
};
class Book *library;
 
int alphabit(Book &a, Book &b)
{
	return strcmp(a.author, b.author);
}
 
int main(void)
{
	int ans, i = 0;
	do
	{
		cout << "Есть еще книги? (1)-да, (2)-нет,любая другая кнопка-выход из программы" << endl;
		cin >> ans;
		if (ans == 1)
		{
			library = (class Book *)realloc(library, (i + 1) * sizeof(class Book));
			library[i].set();
			i++;
		}
		else if (ans == 2)
		{
			for (int k = 0; k < i; k++)
			{
				for (int j = 0; j < i - k; j++)
				{
					if (alphabit(library[j+1], library[j]) < 0)
					{
						Book buf = library[j];
						library[j] = library[j + 1];
						library[j + 1] = buf;
 
					}
				}
			}
			printf("!!!");
			for (int k = 0; k < i; k++)
			{
				library[k].get();
			}
			int ans;
			cout << "Выберите мод для вывода" << endl << "(1) - список книг данного автора" << endl;
			cout << "(2) - список книг от данного издательства" << endl << "(3) - список книг написанных после данного года" << endl;
			cout << "(4) - выход из программы" << endl;
			cin >> ans;
			if (ans >= 1 && ans <= 3)show(ans, i);
			else { cout << "Выход из программы" << endl; return 0; }
		}
		else break;
	} while (1);
	free(library);
	delete library;
	return 0;
}
void show(int mode, int i)
{
	switch (mode)
	{
	case(1):
	{
		char name[100];
		cout << "Введите имя писателя, которого хотите найти" << endl;
		cin.get();
		cin.getline(name, 100);
		for (int k = 0; k < i; k++)
		{
			if (library[k].srav(name) == 0)
				library[k].get();
		}
		break;
	}
	case(2):
	{
		char name[100];
		cout << "Введите название издательства, которого хотите найти" << endl;
		cin.get();
		cin.getline(name, 100);
		for (int k = 0; k < i; k++)
		{
			if (library[k].srpb(name) == 0)
				library[k].get();
		}
		break;
	}
	case(3):
	{
		int a_year;
		cout << "Введите искомый год" << endl;
		cin >> a_year;
		for (int k = 0; k < i; k++)
		{
			if (library[k].sravi(a_year) == 0)
				library[k].get();
		}
		break;
	}
	}
}