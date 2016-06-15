#include "database.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <iomanip>

using namespace std;

database bus;

database::database()
{
	kol = 0;
}

database::~database()
{
	if (kol != 0)
		delete []pers;
}

void database::WOD()
{
	for (int i = 0; i < kol; i++)
		cout<< pers[i].last_name<< " | "<< pers[i].name<< " | " << pers[i].middle_name << " | " << pers[i].birthday << " | " << pers[i].number << " | " << pers[i].payment << " | " << pers[i].week << " | " << pers[i].salary<< endl;
}

void database::Load(char *filename)
{
	fstream f;
	char a;
	int n = 0;
	if (kol != 0) delete [] pers;
	f.open(filename);
	if (f==NULL)
	{
		cout<<"Error";
	}
	while(!f.eof())
	{	
		a = f.get();
		if(a == '\n')
		n++;
	}
	if (n == 0)
	{
		cout << "Список пуст. Добавьте рабочих или выйдите из программы." << endl;
	}
	pers = new Person[n];
	f.close();
	f.open(filename);
	for(int i = 0; i < n; i++)
	{
		f >> pers[i].last_name >> pers[i].name >> pers[i].middle_name >> pers[i].birthday >> pers[i].number >> pers[i].payment >> pers[i].week;
		pers[i].salary = 4 * pers[i].week*pers[i].payment;
	}
	f.close();
	kol = n;
}

void database::InFile(char *filename)
{
	fstream f;
	f.open(filename, ios::out);
	if (f==NULL)
	{
		cout<<"Error";
	}
	for (int i = 0; i < kol; i ++)
		f << pers[i].last_name<< " "<< pers[i].name<< " " << pers[i].middle_name << " " << pers[i].birthday << " " << pers[i].number << " " << pers[i].payment << " " << pers[i].week <<'\n'; 
	f.close();
}

void database::Add(char *filename)
{
	Person t;
	fstream f;
	cout<< "Введите фамилию: ";
	cin >> t.last_name;
	cout << "Введите имя: ";
	cin >> t.name;
	cout << "Введите отчество: ";
	cin >> t.middle_name;
	cout << "Введите дату рождения" << endl<< "День: ";
	cin >> t.day;
	cout << "Месяц: ";
	cin >> t.month;
	cout << "Год: ";
	cin >> t.year;
	cout << "Введите инд. номер: ";
	cin >> t.number;
	cout << "Введите оклад: ";
	cin >> t.payment;
	cout << "Введите часов в неделю: ";
	cin >> t.week;
	t.salary = 4 * t.week * t.payment;
	cout<< 12<< endl;
	f.open(filename, ios::out | ios::app);	
	if (f==NULL)
	{
		cout<<"Error";
	}
	f << t.last_name<< " "<< t.name<< " " << t.middle_name << " " << t.day << "." << t.month<< "."<< t.year<< " "<< t.number << " " << t.payment << " " << t.week <<'\n';
	f.close();	
}

int database::Delete(char *filename)
{
	int num, i, n;
	fstream f;
	if (kol == 0)
		return 0;
	cout<< "Введите индивидуальный номер сотрудника, которого нужно удалить: "<< endl;
	cin>> num;
	f.open(filename, ios::out);
	for(i = 0; i < kol; i ++)
		if (num == pers[i].number) n = i;
	for(i = 0; i < n; i++)
		f << pers[i].last_name<< " "<< pers[i].name<< " " << pers[i].middle_name << " " << pers[i].birthday << " " << pers[i].number << " " << pers[i].payment << " " << pers[i].week <<'\n';
	for(i = n+1; i < kol; i ++)
		f << pers[i].last_name<< " "<< pers[i].name<< " " << pers[i].middle_name << " " << pers[i].birthday << " " << pers[i].number << " " << pers[i].payment << " " << pers[i].week <<'\n'; 
	f.close();
	return 0;
}

int database::Change(char *filename)
{
	if (kol == 0)
		return 0;
	int haha, num;
	fstream f;
	f.open(filename, ios::out);
	if (f==NULL)
	{
		cout<<"Error";
	}
	cout<< "Введите индивидуальный номер сотрудника, данные которого нужно изменить: "<< endl;
	cin>> num;
	for (int i = 0; i < kol; i ++)
	{
		if (pers[i].number == num)
		{
			cout<< "1-Фамилия: " <<  pers[i].last_name<<endl<<"2- Имя: "<< pers[i].name <<endl<< "3- Отчество: " << pers[i].middle_name<<endl<< "4- Оклад: " <<  pers[i].payment<<endl<< "5-Кол-во часов в неделю: " << pers[i].week<<endl;
			while(1)
			{
				cout<< "Что хотите изменить? "<< endl;
				cin >> haha;
				switch(haha)
				{
					case 1 :
						cout<< "Новая фамилия: ";
						cin >> pers[i].last_name;
						for (int j =0; j < kol; j++)
						{
							f << pers[j].last_name<< " "<< pers[j].name<< " " << pers[j].middle_name << " " << pers[j].birthday << " " << pers[j].number << " " << pers[j].payment << " " << pers[j].week <<'\n';
						}
						return 0;
					case 2 :
						cout<< "Новое имя: ";
						cin >>pers[i].name;
						for (int j =0; j < kol; j++)
						{
							f << pers[j].last_name<< " "<< pers[j].name<< " " << pers[j].middle_name << " " << pers[j].birthday << " " << pers[j].number << " " << pers[j].payment << " " << pers[j].week <<'\n';
						}
						return 0;
					case 3 :
						cout<< "Новое отчество: ";
						cin >>pers[i].middle_name;
						for (int j =0; j < kol; j++)
						{
							f << pers[j].last_name<< " "<< pers[j].name<< " " << pers[j].middle_name << " " << pers[j].birthday << " " << pers[j].number << " " << pers[j].payment << " " << pers[j].week << '\n';
						}
						return 0;
					case 4 :
						cout<< "Новый оклад: ";
						cin >>pers[i].payment;
						for (int j =0; j < kol; j++)
						{
							f << pers[j].last_name<< " "<< pers[j].name<< " " << pers[j].middle_name << " " << pers[j].day<<" "<< pers[i].month << " " << pers[i].year << " " << pers[j].number << " " << pers[j].payment << " " << pers[j].week <<'\n';
						}
						return 0;
					case 5 :
						cout<< "Новое кол-во часов: ";
						cin >>pers[i].week;
						for (int j =0; j < kol; j++)
						{
							f << pers[j].last_name<< " "<< pers[j].name<< " " << pers[j].middle_name << " " << pers[j].day<<" "<< pers[i].month << " " << pers[i].year << " " << pers[j].number << " " << pers[j].payment << " " << pers[j].week <<'\n';
						}
						return 0;
					default:
						cout<< "Такого пункта нет";
						break; 
					return 0;
				}
			}
		}
	}
}

int database::Sort()
{
	if (kol == 0)
		return 0;
	int sorting, we;
	cout<< "Выберите параметр сортировки:" << endl<< "1 - По фамилии | 2 - По зарплате"<< endl;
	cin >> sorting;
	switch(sorting)
	{
		case 1:
			sort (pers, pers+kol, Person::supname);
			break;
		case 2:
			sort (pers, pers+kol, Person::supsalary);
			break;
		default:
			cout<< "Такого нет("<< endl;
			 
	}
}
