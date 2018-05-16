#include"Employee.h"
#include<vector>
#include<sstream>
using std::ostringstream;
using std::vector;

Analyst::Analyst(string full_name, string address, string egn, string hire_date, string boss, string position_name, string level, string _projectname, string mails) :
	Employee(full_name, address, egn, hire_date, boss, position_name, level),
	project_name(_projectname),
	mails_of_clients(mails) {}

string Analyst::GetInformation() const
{
	ostringstream stream;
	stream << Employee::GetInformation();
	stream << "Project name : " << this->project_name << endl << "Mails of clients : ";
	for (int i = 0; i < mails_of_clients.size(); i++) {
		if (i != mails_of_clients.size() - 1) {
			stream << mails_of_clients[i] << ", ";
		}
		else {
			stream << mails_of_clients[i] << " ";
		}
	}
	stream << endl;

	return stream.str();
}

string Analyst::GetProjectName() const
{
	return this->project_name;
}

void Analyst::SetProjectName(string name_of_project)
{
	this->project_name = name_of_project;
}

void Analyst::SetMailsOfClients(string mails)
{
	this->mails_of_clients = mails;
}

string Analyst::GetMailsOfClients() const
{
	return mails_of_clients;
}

void Analyst::AddNewEmployee()
{
}

void Analyst::FireEmployee()
{
}

void Analyst::ChangeInformation()
{
}

void Analyst::SetLevel(string _level)
{
	level = _level;
}

string Analyst::GetLevel() const
{
	return level;
}

