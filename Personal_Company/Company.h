#pragma once
#ifndef COMPANY
#define COMPANY
#include<string>
#include"Employee.h"
#include"Teams.h"
using namespace std;


static vector<Analyst> analyst_arr1;
static vector<Leader> leader_arr1;
static vector<Programmer> programmer_arr1;
static vector<Teams> teams_arr1;


class Company {
	string name_of_company;
	string ceo_of_company;
	string address_of_company;

public:
	
	Company();
	Company(string name, string ceo, string address);
	void SetInformationForCompany(string name, string ceo, string address);
	void SetNameOfCompany(string name);
	void SetCeo(string ceo_name);
	void SetAddress(string address);
	string GetInformationForCompany() const;
	
};
#endif // COMPANY
