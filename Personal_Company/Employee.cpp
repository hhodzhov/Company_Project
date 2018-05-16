#include "Employee.h"

Employee::Employee() :
	full_name(""),
	address(""),
	egn(""),
	hire_date(""),
	boss(""),
	position_name(""),
	level("")
{
}

ostream & operator<<(ostream & out, const Analyst & analyst)
{
	out << analyst.full_name << endl << analyst.address << endl << analyst.egn << endl << analyst.hire_date << endl
		<< analyst.boss << endl << analyst.position_name << endl << analyst.level << endl
		<< analyst.project_name << endl << analyst.mails_of_clients << endl;
	return out;
}

istream & operator >> (istream & in, Analyst & analyst)
{
	in >> analyst.full_name >> analyst.address >> analyst.egn >> analyst.hire_date >> analyst.boss
		>> analyst.position_name >> analyst.level >> analyst.project_name >> analyst.mails_of_clients;
	return in;
}
