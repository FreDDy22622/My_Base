#include "Person.h"

class database
{
		Person *pers;
		int kol;
	public:
		database();
		~database();
		void InFile(char *);       //сохранение в файл
		void WOD();                     //вывод на экран
		void Add(char *);           //добавление 
		int Delete(char *);           //удаление
		int Sort();                  //сортировка
		int Change(char *);             //изменение
		void Load(char *);          //загрузка
};

