class Person
{
		public:
		char last_name[100];                     //Фамилия
		char name[100];                          //Имя
		char middle_name[100];                   //Отчество
		char birthday[10];                       //Дата рождения (пример: 11.08.1892)
		int day;
		int month;
		int year;
		int number;                              //Индивидуальный номер
		int payment;                             //Оклад(Рублей в час)
		int week;                                //Количество часов в неделю
		int salary;   				//зарплата (оклад*часы*4)
		static bool supname(Person, Person);
		static bool supsalary(Person, Person);
		Person();
		~Person();		
};
