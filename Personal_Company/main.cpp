#include<iostream>
#include<fstream>
#include"Teams.h"
#include"Executor.h"
#include"Company.h"
using namespace std;

Executor executor;
Company company;

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
		//HireAnalyst(); break;
		executor.HireAnalyst(); break;
	case 2:
		//HireProgrammer(); break;
		executor.HireProgrammer(); break;
	case 3:
		//HireLeader(); break;
		executor.HireLeader(); break;
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
	case 1: // ShowInformationForCertainAnalyst(); break;
		executor.ShowInformationForCertainAnalyst(); break;
	case 2: //ShowInformationForCertainProgrammer(); break;
		executor.ShowInformationForCertainProgrammer(); break;
	case 3: //ShowInformationForCertainLeader(); break;
		executor.ShowInformationForCertainLeader(); break;
	}
}


void FireEmployees() {
	cout << "-----Choose position-----" << endl << endl;
	cout << "1 - Analyst" << endl
		<< "2 - Programmer" << endl
		<< "3 - Leader" << endl;
	size_t operation;
	cin >> operation;
	switch (operation) {
	case 1: //FireAnalysts(); break;
		executor.FireAnalysts(); break;
	case 2: //FireProgrammers(); break;
		executor.FireProgrammers(); break;
	case 3: //FireLeaders(); break;
		executor.FireLeaders(); break;
	}
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
		executor.DeserializeObjectAnalyst(); break;
	case 2:
		executor.DeserializeObjectProgrammer(); break;
	case 3:
		executor.DeserializeObjectLeader(); break;
	}
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
		executor.ChangeAnalystsData(); break;
	case 2:
		executor.ChangeProgrammersData(); break;
	case 3:
		executor.ChangeLeadersData(); break;
		
	}
}

int main() {

	size_t operation;
	executor.LoadInformation();
	executor.LoadInformationForTeams();

	do {
		cout << "---------------MAIN MENU----------------" << endl << endl;
		cout << "1 - Enter information for company" << endl
			<< "2 - Get information for company" << endl
			<< "3 - Add employee" << endl
			<< "4 - Show information for employees" << endl
			<< "5 - Fire employee" << endl
			<< "6 - Show information for employees for certain position" << endl
			<< "7 - Change employee's data" << endl
			<< "0 - Go to team menu" << endl;

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
		}
	} while (operation != 0);


	do {
		cout << "---------TEAM MENU----------" << endl << endl;
		cout << "1 - Create new team" << endl
			<< "2 - Transfer members from one team to another" << endl
			<< "3 - Delete team" << endl
			<< "4 - Show information for all teams" << endl
			<< "0 - Exit" << endl;

		cin >> operation;
		cin.ignore();

		switch (operation) {
		case 1: //AddNewTeam(); break;
			executor.AddNewTeam(); break;
		case 2: //TransferMembers(); break;
			executor.TransferMembers(); break;
		case 3:// DeleteTeams(); break;
			executor.DeleteTeams(); break;
		case 4: //ShowInformationForAllTeams(); break;
			executor.ShowInformationForAllTeams(); break;
		}
	} while (operation != 0);

	system("pause");
}
