#include<iostream>
#include<fstream>
#include"Employee.h"
#include"Company.h"
using namespace std;

static Company company;
vector<Analyst> analysts;
static vector<Analyst> analyst_arr;


void StoreInformation(string name_of_company, string ceo, string address) {
	ofstream company_information("company-information.txt", ios::app);
	company_information << "Name of company : " << name_of_company << endl;
	company_information << "CEO of company : " << ceo << endl;
	company_information << "Address of company : " << address << endl;
}

void EnterInformationForCompany() {
	string name_of_company, ceo, address;
	cout << "Enter name of company : ";
	getline(cin, name_of_company);
	cout << "Enter CEO of company : ";
	getline(cin, ceo);
	cout << "Enter address of company : ";
	getline(cin, address);
	company.SetInformationForCompany(name_of_company, ceo, address);
	StoreInformation(name_of_company, ceo, address);
}

void GetInformationForCompany() {
	cout << company.GetInformationForCompany() << endl;
}
void StoreInformationForAnalysts(string name, string address, string egn, string date,
	string boss, string position, string level, string project, string mails) {

	ofstream analysts_information("analysts-information.txt", ios::app);
	analysts_information << "Full Name : " << name << endl;
	analysts_information << "Address : " << address << endl;
	analysts_information << "EGN : " << egn << endl;
	analysts_information << "Date of hiring : " << date << endl;
	analysts_information << "Boss : " << boss << endl;
	analysts_information << "Position : " << position << endl;
	analysts_information << "Level : " << level << endl;
	analysts_information << "Project name : " << project << endl;
	analysts_information << "Mails of clients : " << mails << endl << endl;
}
void SerializeObjectAnalyst(Analyst & analyst) {
	ofstream analyst_serialize("analyst-serialize.txt", ios::app);

	analyst_serialize << endl << analyst;
	analyst_serialize.close();
}

void EnterCommonInformation(string& name, string& address, string& egn, string& date, string& boss, string& position, string& level) {
	cout << "Enter name :";
	getline(cin, name);
	cout << "Enter address ";
	getline(cin, address);
	cout << "Enter egn : ";
	getline(cin, egn);
	cout << "Enter date of hiring : ";
	getline(cin, date);
	cout << "Enter name employee's boss : ";
	getline(cin, boss);
	cout << "Enter position : ";
	getline(cin, position);
	cout << "Enter level : ";
	getline(cin, level);
}

void HireAnalyst() {

	string name, address, egn, date, boss, position, level, project, mails;
	EnterCommonInformation(name, address, egn, date, boss, position, level);
	cout << "Enter name of project : ";
	getline(cin, project);
	cout << "Enter mails of clients in one line" << endl;
	getline(cin, mails);

	Analyst current_analyst(name, address, egn, date, boss, position, level, project, mails);
	//analysts.push_back(current_analyst);
	analyst_arr.push_back(current_analyst);

	SerializeObjectAnalyst(current_analyst);

	StoreInformationForAnalysts(name, address, egn, date, boss, position, level, project, mails);

}
void AddEmployeeToStuff() {
	cout << "-----What kind of employee do you want to hire-----" << endl << endl;
	cout << "1 - Analyst" << endl
		<< "2 - Programmer" << endl
		<< "3 - Leader" << endl;
	size_t option;
	cin >> option;
	cin.ignore();
	switch (option) {
	case 1:
		HireAnalyst(); break;
	}
}
void ShowInformationForAllAnalysts() {
	ifstream read_information_all_analysts("analysts-information.txt");
	string current_line;
	while (!read_information_all_analysts.eof()) {
		getline(read_information_all_analysts, current_line);
		cout << current_line << endl;
	}

}

void LoadInformation() {
	ifstream deserialize_analyst("analyst-serialize.txt");
	int index = 0;
	while (!deserialize_analyst.eof()) {
		Analyst current;
		deserialize_analyst >> current;
		
		analyst_arr.push_back(current);

	}
}
void ShowAllAnalystsNames() {
	for (size_t i = 0; i < analyst_arr.size(); i++)
	{
		cout << analyst_arr[i].GetName() << endl;
	}
}
void ShowAllAnalystsInformation() {
	for (size_t i = 0; i < analyst_arr.size() ; i++)
	{
		cout << analyst_arr[i].GetInformation() << endl;
	}
}
void MoveToAnalystArr() {
	int count;
	for (size_t i = 0; i < analysts.size(); i++)
	{
		count = 0;
		for (size_t j = 0; j < analyst_arr.size(); j++)
		{
			if (analyst_arr[j] != analysts[i]) {
				count++;
			}
		}
		cout << "Count is : " << count << endl;
		cout << "Analyst_arr.size() is " << analyst_arr.size() << endl;
		cout << "Vec size is : " << analysts.size() << endl;
		if (count == analyst_arr.size() - 1) {
			analyst_arr.push_back(analysts[i]);
		}

	}
	/*for (size_t i = 0; i < analysts.size(); i++)
	{
		analyst_arr.push_back(analysts[i]);
	}*/

}
void DeserializeObjectAnalyst() {

	//LoadInformation();

	/*for (size_t i = 0; i < analyst_arr.size() - 1; i++)
	{
		cout << analyst_arr[i].GetInformation() << endl;
	}*/
	//ShowAllAnalystsNames();
	if (analysts.size() != 0) {
		cout << "ASDASDASDASD";
		MoveToAnalystArr();
	}
	ShowAllAnalystsInformation();
}
void ShowInformationForEmployeesForCertainPosition() {
	cout << "-----Choose position to see information-----" << endl << endl;
	cout << "1 - Analyst" << endl
		<< "2 - Programmer" << endl
		<< "3 - Leader" << endl;
	size_t operation;
	cin >> operation;
	switch (operation) {
	case 1:
		//ShowInformationForAllAnalysts();
		DeserializeObjectAnalyst(); break;
	}
}


void ShowInformationForCertainAnalyst() {

	cout << "----------All analysts in the company----------" << endl << endl;
	ifstream deserialize_analyst("analyst-serialize.txt");
	vector<Analyst> current_analysts;
	while (!deserialize_analyst.eof()) {
		Analyst current;
		deserialize_analyst >> current;
		current_analysts.push_back(current);
	}

	/*for (size_t i = 0; i < current_analysts.size() - 1; i++)
	{
		cout << current_analysts[i].GetName() << endl;
	}*/
	ShowAllAnalystsNames();

	string analyst_to_choose;
	cin.ignore();
	getline(cin, analyst_to_choose);
	cout << "----------Information for " << analyst_to_choose << "----------" << endl << endl;
	for (size_t i = 0; i < current_analysts.size(); i++)
	{
		if (current_analysts[i].GetName() == analyst_to_choose) {
			cout << current_analysts[i].GetInformation() << endl;
		}
	}
}
void ShowInformationForCertainEmployee() {
	cout << "-----Choose position to see information-----" << endl << endl;
	cout << "1 - Analyst" << endl
		<< "2 - Programmer" << endl
		<< "3 - Leader" << endl;
	size_t operation;
	cin >> operation;
	switch (operation) {
	case 1:
		ShowInformationForCertainAnalyst(); break;
	}
}
void ReSerialize(vector<Analyst> vec, string file_name) {
	ofstream reserialize_employees(file_name, ios::out);

	for (size_t i = 0; i < vec.size(); i++)
	{
		if (i == vec.size() - 1) {
			reserialize_employees << vec[i];
		}
		else {
			reserialize_employees << vec[i] << endl;

		}
	}
}
void FireAnalysts() {
	cout << "----------All analysts in the company----------" << endl << endl;
	ShowAllAnalystsNames();

	string analyst_to_fire;
	cin.ignore();
	getline(cin, analyst_to_fire);
	for (size_t i = 0; i < analyst_arr.size(); i++)
	{
		if (analyst_arr[i].GetName() == analyst_to_fire) {
			analyst_arr.erase(analyst_arr.begin() + i);
		}
	}
	ReSerialize(analyst_arr, "analyst-serialize.txt");
}

void FireEmployees() {
	cout << "-----Choose position-----" << endl << endl;
	cout << "1 - Analyst" << endl
		<< "2 - Programmer" << endl
		<< "3 - Leader" << endl;
	size_t operation;
	cin >> operation;
	switch (operation) {
	case 1:
		FireAnalysts(); break;
	}
}
Analyst ChangedInformation(Analyst& current_analyst) {

	string name, address, egn, date, boss, position, level, project, mails;
	EnterCommonInformation(name, address, egn, date, boss, position, level);
	cout << "Enter name of project : ";
	getline(cin, project);
	cout << "Enter mails of clients in one line" << endl;
	getline(cin, mails);
	Analyst updated(name, address, egn, date, boss, position, level, project, mails);

	return updated;
}
void ChangeAnalystsData() {
	ShowAllAnalystsNames();

	string analyst_to_change_information;
	cin.ignore();
	getline(cin, analyst_to_change_information);

	for (size_t i = 0; i < analyst_arr.size(); i++)
	{
		if (analyst_arr[i].GetName() == analyst_to_change_information) {
			analyst_arr[i] = ChangedInformation(analyst_arr[i]);
		}
	}
	ReSerialize(analyst_arr, "analyst-serialize.txt");
}

void ChangeEmployeesData() {
	cout << "-----Choose position-----" << endl << endl;
	cout << "1 - Analyst" << endl
		<< "2 - Programmer" << endl
		<< "3 - Leader" << endl;
	size_t operation;
	cin >> operation;
	switch (operation) {
	case 1:
		ChangeAnalystsData();
	}
}

int main() {

	/*typedef Employee * employees;
	vector<string> mails;
	mails.push_back("firstmail");
	mails.push_back("secondmail");

	employees e[3]{
		new Programmer("Halmi Saliev Hodzhov", "Sofia", "9705245081", "15.05.2018", "Az sym si shefa", "Programmer", "1", "Company Project"),
		new Analyst("Mesut Saliev Hodzhov","Varna","11111111","12.12.12","Toi e shefa","Analyst","2","Some project",mails),
		new Leader("Sali Ahmed Hodzhov","Razgrad","2222222222","13.12.13","Toi e shefa","Leader","3","Some project",mails)
	};

	for (size_t i = 0; i < 3; i++)
	{
		cout << e[i]->GetInformation() << endl;
	}
	cout << endl;
	*/
	size_t operation;
	//DeserializeObjectAnalyst();
	LoadInformation();

	do {
		cout << "---------------MAIN MENU----------------" << endl << endl;
		cout << "1 - Enter information for company" << endl
			<< "2 - Get information for company" << endl
			<< "3 - Add employee" << endl
			<< "4 - Show information for employees" << endl
			<< "5 - Fire employee" << endl
			<< "6 - Show information for employees for certain position" << endl
			<< "7 - Change employee's data" << endl << endl;

		cin >> operation;
		cin.ignore();
		switch (operation) {
		case 1:
			EnterInformationForCompany(); break;
		case 2:
			GetInformationForCompany(); break;
		case 3:
			AddEmployeeToStuff(); break;
		case 4:
			ShowInformationForCertainEmployee(); break;
		case 5:
			FireEmployees(); break;
		case 6:
			ShowInformationForEmployeesForCertainPosition(); break;
		case 7:
			ChangeEmployeesData(); break;
		case 8:
			cout << "Printing current Analyst" << endl;
			for (size_t i = 0; i < analysts.size(); i++)
			{
				cout << analysts[i] << endl;
			} break;
		case 9:
			cout << "Printing current Analyst_Arr" << endl;
			for (size_t i = 0; i < analyst_arr.size(); i++)
			{
				cout << analyst_arr[i] << endl;
			}break;
		}

	} while (operation != 0);
	system("pause");

}