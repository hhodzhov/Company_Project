#pragma once
#ifndef TEAMS
#define TEAMS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ostream>
#include<istream>

using namespace std;

class Teams {
	string team_leader;
	string project_name;
	vector<string> names_of_employees;

public:
	Teams();
	
	Teams(string _team_leader, string _project_name, vector<string> _names_of_employees);
	string GetInformation();
	vector<string> GetMembers();
	string GetTeamLeader() const;
	friend ostream& operator << (ostream& stream, const Teams& team);
	friend istream& operator >> (istream& stream, Teams& team);
	bool isNull();
	void push_new_employee(string name);
	void RemoveEmployee(string name);
	bool HasNoMembers();
		
};




#endif // !TEAMS
