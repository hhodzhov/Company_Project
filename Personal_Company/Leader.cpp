#include"Employee.h"
#include<vector>
#include<sstream>
using std::vector;
using std::ostringstream;

Leader::Leader(string full_name, string address, string egn, string hire_date, string boss, string position_name, string level,
	string _projectname, vector<string> mails) :
	Employee(full_name, address, egn, hire_date, boss, position_name, level),
	project_name(_projectname),
	mails_of_clients(mails) {}

string Leader::GetInformation() const
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
	return stream.str();
}

void Leader::AddNewEmployee()
{
}

void Leader::FireEmployee()
{
}

void Leader::ChangeInformation()
{
}

void Leader::SetLevel(string _level)
{
	level = _level;
}

string Leader::GetLevel() const
{
	return level;
}
