#pragma once
#ifndef PERSONAL_COMPANY
#define PERSONAL_COMPANY
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using std::string;
using std::cout;
using std::endl;
using std::ostringstream;
using std::vector;
class Employee {
protected:
	string full_name;
	string address;
	string egn;
	string hire_date;
	string boss;
	string position_name;
	string level;

public:
	Employee(string _fullname, string _address, string _egn, string _hiredate, string _boss, string _position_name, string _level) :
		full_name(_fullname),
		address(_address),
		egn(_egn),
		hire_date(_hiredate),
		boss(_boss),
		position_name(_position_name),
		level(_level) {}

	virtual void AddNewEmployee() = 0;
	virtual void FireEmployee() = 0;
	virtual string GetInformation() const {
		ostringstream stream;
		stream << "Full name : " << full_name << endl << "Address : " << address << endl << "EGN: " << egn << endl
			<< "Hire date: " << hire_date << endl << "Boss : " << boss << endl << "Position name : " << position_name
			<< endl << "Level : " << level << endl;
		return stream.str();
	}
	virtual void ChangeInformation() = 0;
	virtual void SetLevel(string _level) = 0;
	virtual string GetLevel()  const = 0;
};

class Leader : public virtual Employee {
	string project_name;
	vector<string> mails_of_clients;

public:

	Leader(string full_name, string address, string egn, string hire_date, string boss, string position_name, string level, string _projectname, vector<string> mails);
	string GetInformation() const override;
	void AddNewEmployee();
	void FireEmployee();
	void ChangeInformation() override;
	void SetLevel(string _level) override;
	string GetLevel() const override;

};
class Programmer : public virtual Employee {
	string project_name;

public:

	Programmer(string full_name, string address, string egn, string hire_date, string boss,
		string position_name, string level, string _projectname);
	string GetInformation() const override;
	void SetProjectName(string name_of_project);
	string GetProjectName();
	void AddNewEmployee() override;
	void FireEmployee() override;
	void ChangeInformation() override;
	void SetLevel(string _level) override;
	string GetLevel() const override;

};

class Analyst : public virtual Employee {
	string project_name;
	string mails_of_clients;

public:

	Analyst(string full_name, string address, string egn, string hire_date, string boss,
		string position_name, string level, string _projectname,string mails);
	string GetInformation() const override;
	string GetProjectName() const;
	void SetProjectName(string name_of_project);
	void SetMailsOfClients(string mails);
	string GetMailsOfClients() const;
	void AddNewEmployee();
	void FireEmployee();
	void ChangeInformation();
	void SetLevel(string _level);
	string GetLevel() const;
};



#endif // !PERSONAL_COMPANY
