#include <iostream>
#include "database.h"
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
	if (argc > 1)
	{	
	int menu;
	database base;
	
	cout<< "Hello"<< endl;
	while (1)
	{
		system("clear");
		base.Load(argv[1]);
		
		cout<< "1 - Добавить работника | 2 - Удалить работника | 3 - Сортировать данные | 4 - Изменить данные | 5 - Выход" << endl;
		base.WOD();
		cout<< endl;
		cin>> menu;
		switch(menu)
		{
			case 1:
				base.Add(argv[1]);
				break;
			case 2:
				base.Delete(argv[1]);
				break;
			case 3:
				base.Load(argv[1]);
				base.WOD();
				base.Sort();
				base.InFile(argv[1]);
				break;
			case 4: 
				base.Change(argv[1]);
				base.InFile(argv[1]);
				break;
			case 5: 
				return 0;
			default:
				break;
				
		} 
	}}
	return 0;
}
