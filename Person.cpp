#include "Person.h"

Person::Person()
{}
Person::~Person()
{}

bool Person::supname(Person per1, Person per2)
{
	return per1.last_name < per2.last_name;
}
bool Person::supsalary(Person per1, Person per2)
{
	return per1.salary > per2.salary;
}
