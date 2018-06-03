#include "Company.h"
#include<fstream>
#include<sstream>
using std::ostringstream;
using std::endl;
using std::ifstream;

Company::Company():
	name_of_company(""),
	ceo_of_company(""),
	address_of_company("")
{
}

Company::Company(string name, string ceo, string address) :
	name_of_company(name),
	ceo_of_company(ceo),
	address_of_company(address)
{
}

void Company::SetInformationForCompany(string company_name, string ceo, string address)
{
	SetNameOfCompany(company_name);
	SetCeo(ceo);
	SetAddress(address);
}

void Company::SetNameOfCompany(string company_name)
{
	this->name_of_company = company_name;
}

void Company::SetCeo(string ceo_name)
{
	this->ceo_of_company = ceo_name;
}

void Company::SetAddress(string address)
{
	this->address_of_company = address;
}

string Company::GetInformationForCompany() const
{
	ostringstream stream;
	ifstream read_information("company-information.txt");
	string current_line;
	while (!read_information.eof()) {
		getline(read_information, current_line);
		stream << current_line << endl;
	}
	return stream.str();
}
