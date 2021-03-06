#include"Employee.h"
#include<sstream>
using std::cout;
using std::endl;
using std::ostringstream;

Programmer::Programmer(string full_name, string address, string egn, string hire_date, string boss, 
	string position_name, string level, string _projectname) :
	Employee(full_name, address, egn, hire_date, boss, position_name, level),
	project_name(_projectname) {}

Programmer::Programmer() : Employee(),
	project_name("")
{
}

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

bool Programmer::operator!=(Programmer & other)
{
	return this->full_name != other.full_name && this->address != other.address && this->egn != other.egn
		&& this->hire_date != other.hire_date && this->boss != other.boss  && this->position_name != other.position_name
		&& this->level != other.level && this->project_name != other.project_name;
}

bool Programmer::IsNull()
{
	return full_name == "";
}

