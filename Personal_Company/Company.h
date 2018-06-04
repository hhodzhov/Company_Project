#pragma once
#ifndef COMPANY
#define COMPANY
#include<string>
#include"Employee.h"

using namespace std;


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
