#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include "Teams.h"
using namespace std;

Teams::Teams() : 
	team_leader(""),
	project_name(""),
	names_of_employees(NULL)
{
}

Teams::Teams(string _team_leader, string _project_name, vector<string> _names_of_employees):
	team_leader(_team_leader),
	project_name(_project_name),
	names_of_employees(_names_of_employees)
{
}

string Teams::GetInformation()
{
	ostringstream stream;
	stream << "Team leader : " << team_leader << endl << "Project name : " << project_name << endl
		<< "Members : " << endl;
	for (size_t i = 0; i < names_of_employees.size(); i++)
	{
		stream << names_of_employees[i] << endl;
	}
	return stream.str();
}

vector<string> Teams::GetMembers()
{
	//names_of_employees.push_back(team_leader);

	return this->names_of_employees;
}

string Teams::GetTeamLeader() const
{
	return this->team_leader;
}

bool Teams::isNull()
{
	return team_leader == "";
}

void Teams::push_new_employee(string name)
{
	this->names_of_employees.push_back(name);
}

void Teams::RemoveEmployee(string name)
{
	names_of_employees.erase(std::remove(names_of_employees.begin(), names_of_employees.end(), name));
}

bool Teams::HasNoMembers()
{
	return names_of_employees.empty();
}

ostream & operator<<(ostream & stream, const Teams & team)
{
	stream << team.team_leader << endl << team.project_name << endl;
		
	for (size_t i = 0; i < team.names_of_employees.size(); i++)
	{
		stream << team.names_of_employees[i] << endl;
	}

	return stream;
}

istream & operator >> (istream & stream, Teams & team)
{
	int number_of_members;
	stream >> number_of_members>>team.team_leader >> team.project_name;
	int index = 0;
	vector<string> temp;
	bool isTrue = true;
	for(int i=0; i<number_of_members; i++){
		string current;
		stream >> current;
		team.names_of_employees.push_back(current);
	}
	
	return stream;
}
