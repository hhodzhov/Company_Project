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

ostream & operator<<(ostream & out, const Leader & leader)
{
	out << leader.full_name << endl << leader.address << endl << leader.egn << endl << leader.hire_date << endl
		<< leader.boss << endl << leader.position_name << endl << leader.level << endl
		<< leader.project_name << endl << leader.mails_of_clients << endl;
	return out;
}

istream & operator >> (istream & in, Leader & leader)
{
	in >> leader.full_name >> leader.address >> leader.egn >> leader.hire_date >> leader.boss
		>> leader.position_name >> leader.level >> leader.project_name >> leader.mails_of_clients;
	return in;
}

ostream & operator<<(ostream & out, const Programmer & programmer)
{
	out << programmer.full_name << endl << programmer.address << endl << programmer.egn << endl << programmer.hire_date << endl
		<< programmer.boss << endl << programmer.position_name << endl << programmer.level << endl
		<< programmer.project_name << endl;
	return out;
}

istream & operator >> (istream & in, Programmer & programmer)
{
	in >> programmer.full_name >> programmer.address >> programmer.egn >> programmer.hire_date >> programmer.boss
		>> programmer.position_name >> programmer.level >> programmer.project_name;
	return in;
}

ostream & operator<<(ostream & out, const Analyst & analyst)
{
	out << analyst.full_name << endl << analyst.address << endl << analyst.egn << endl << analyst.hire_date << endl
		<< analyst.boss << endl << analyst.position_name << endl << analyst.level << endl
		<< analyst.project_name << endl << analyst.mails_of_clients;
	return out;
}

istream & operator >> (istream & in, Analyst & analyst)
{
	in >> analyst.full_name >> analyst.address >> analyst.egn >> analyst.hire_date >> analyst.boss
		>> analyst.position_name >> analyst.level >> analyst.project_name >> analyst.mails_of_clients;
	return in;
}
