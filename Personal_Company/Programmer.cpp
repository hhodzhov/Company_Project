#include"Employee.h"
#include<sstream>
using std::cout;
using std::endl;
using std::ostringstream;

Programmer::Programmer(string full_name, string address, string egn, string hire_date, string boss, 
	string position_name, string level, string _projectname) :
	Employee(full_name, address, egn, hire_date, boss, position_name, level),
	project_name(_projectname) {}

string Programmer::GetInformation() const
{
	ostringstream stream;
	stream << Employee::GetInformation() << "Project name : " << this->project_name << endl;
	return stream.str();
}

void Programmer::SetProjectName(string name_of_project)
{
	this->project_name = name_of_project;
}

string Programmer::GetProjectName()
{
	return this->project_name;
}

void Programmer::AddNewEmployee()
{
}

void Programmer::FireEmployee()
{
}

void Programmer::ChangeInformation()
{
}

void Programmer::SetLevel(string _level)
{
	level = _level;
}

string Programmer::GetLevel() const
{
	return level;
}

string Programmer::GetName() const
{
	return this->full_name;
}

