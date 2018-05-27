#include<iostream>
#include<fstream>
#include<algorithm>
#include"Employee.h"
#include"Company.h"
#include"Teams.h"
using namespace std;

static Company company;
vector<Analyst> analysts;
static vector<Analyst> analyst_arr;
static vector<Leader> leader_arr;
static vector<Programmer> programmer_arr;
static vector<Teams> teams_arr;

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
/*
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
*/
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

	//StoreInformationForAnalysts(name, address, egn, date, boss, position, level, project, mails);

}
void SerializeObjectLeader(Leader& leader) {
	ofstream leader_serialize("leader-serialize.txt", ios::app);
	leader_serialize << leader;
	leader_serialize.close();
}
void HireLeader() {
	string name, address, egn, date, boss, position, level, project, mails;
	EnterCommonInformation(name, address, egn, date, boss, position, level);
	cout << "Enter name of project : ";
	getline(cin, project);
	cout << "Enter mails of clients in one line" << endl;
	getline(cin, mails);
	Leader current_leader(name, address, egn, date, boss, position, level, project, mails);
	leader_arr.push_back(current_leader);

	SerializeObjectLeader(current_leader);

}
void SerializeObjectProgrammer(Programmer& programmer) {
	ofstream programmer_serialize("programmer-serialize.txt", ios::app);
	programmer_serialize << programmer;
	programmer_serialize.close();

}
void HireProgrammer() {
	string name, address, egn, date, boss, position, level, project;
	EnterCommonInformation(name, address, egn, date, boss, position, level);
	cout << "Enter name of project : ";
	getline(cin, project);
	Programmer current_programmer(name, address, egn, date, boss, position, level, project);
	programmer_arr.push_back(current_programmer);

	SerializeObjectProgrammer(current_programmer);
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
	case 2:
		HireProgrammer(); break;
	case 3:
		HireLeader(); break;
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
void LoadAnalysts() {
	ifstream deserialize_analyst("analyst-serialize.txt");
	while (!deserialize_analyst.eof()) {
		Analyst current;
		deserialize_analyst >> current;
		analyst_arr.push_back(current);

	}
}
void LoadLeaders() {
	ifstream deserialize_leaders("leader-serialize.txt");
	while (!deserialize_leaders.eof()) {
		Leader current;
		deserialize_leaders >> current;
		leader_arr.push_back(current);
	}
}

void LoadProgrammers() {
	ifstream deserialize_programmers("programmer-serialize.txt");
	while (!deserialize_programmers.eof()) {
		Programmer current;
		deserialize_programmers >> current;
		programmer_arr.push_back(current);
	}
}
void LoadInformation() {
	LoadAnalysts();
	LoadLeaders();
	LoadProgrammers();
}
void ShowAllAnalystsNames() {
	for (size_t i = 0; i < analyst_arr.size(); i++)
	{
		cout << analyst_arr[i].GetName() << endl;
	}
}
void ShowAllAnalystsInformation() {
	for (size_t i = 0; i < analyst_arr.size(); i++)
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
}
void DeserializeObjectAnalyst() {

	/*if (analysts.size() != 0) {
		cout << "ASDASDASDASD";
		MoveToAnalystArr();
	}*/
	ShowAllAnalystsInformation();
}
void ShowAllLeadersInformation() {
	for (size_t i = 0; i < leader_arr.size(); i++)
	{
		cout << leader_arr[i].GetInformation() << endl;
	}
}
void DeserializeObjectLeader() {
	ShowAllLeadersInformation();
}
void ShowAllProgrammersInformation() {
	for (size_t i = 0; i < programmer_arr.size(); i++)
	{
		cout << programmer_arr[i].GetInformation() << endl;
	}
}
void DeserializeObjectProgrammer() {
	ShowAllProgrammersInformation();
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
		DeserializeObjectAnalyst(); break;
	case 2:
		DeserializeObjectProgrammer(); break;
	case 3:
		DeserializeObjectLeader(); break;
	}

}
void ShowInfoForSelectedAnalyst(string& selected) {
	for (size_t i = 0; i < analyst_arr.size(); i++)
	{
		if (analyst_arr[i].GetName() == selected) {
			cout << analyst_arr[i].GetInformation() << endl;
		}
	}
}

void ShowInformationForCertainAnalyst() {
	cout << "----------All analysts in the company----------" << endl << endl;
	ShowAllAnalystsNames();
	string analyst_to_chose;
	cin.ignore();
	getline(cin, analyst_to_chose);
	ShowInfoForSelectedAnalyst(analyst_to_chose);
}
void ShowAllLeadersNames() {
	for (size_t i = 0; i < leader_arr.size(); i++)
	{
		cout << leader_arr[i].GetName() << endl;

	}
}
void ShowInfoForSelectedLeader(string& selected) {
	for (size_t i = 0; i < leader_arr.size(); i++)
	{
		if (leader_arr[i].GetName() == selected) {
			cout << leader_arr[i].GetInformation() << endl;
		}
	}
}
void ShowInformationForCertainLeader() {
	cout << "----------All leaders in the company----------" << endl << endl;
	ShowAllLeadersNames();
	string leader_to_chose;
	cin.ignore();
	getline(cin, leader_to_chose);
	ShowInfoForSelectedLeader(leader_to_chose);
}

void ShowAllProgrammersName() {
	for (size_t i = 0; i < programmer_arr.size(); i++)
	{
		cout << programmer_arr[i].GetName() << endl;
	}
}

void ShowInfoForSelectedProgrammer(string selected_programmer) {
	for (size_t i = 0; i < programmer_arr.size(); i++)
	{
		if (programmer_arr[i].GetName() == selected_programmer) {
			cout << programmer_arr[i].GetInformation() << endl;
		}
	}
}

void ShowInformationForCertainProgrammer() {
	cout << "----------All programmers in the company----------" << endl << endl;
	ShowAllProgrammersName();
	string programmer_to_choose;
	cin.ignore();
	getline(cin, programmer_to_choose);
	ShowInfoForSelectedProgrammer(programmer_to_choose);
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
	case 2: ShowInformationForCertainProgrammer(); break;
	case 3:
		ShowInformationForCertainLeader(); break;
	}
}
void ReSerializeAnalysts(vector<Analyst> vec, string file_name) {
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
	ReSerializeAnalysts(analyst_arr, "analyst-serialize.txt");
}
void ReSerializeLeaders(vector<Leader> vec, string filename) {
	ofstream reserialize_employees(filename, ios::out);

	for (size_t i = 0; i < vec.size(); i++)
	{
		reserialize_employees << vec[i];
	}
}

void FireLeaders() {
	cout << "----------All leaders in the company----------" << endl << endl;
	ShowAllLeadersNames();
	string leader_to_fire;
	cin.ignore();
	getline(cin, leader_to_fire);
	for (size_t i = 0; i < leader_arr.size(); i++)
	{
		if (leader_arr[i].GetName() == leader_to_fire) {
			leader_arr.erase(leader_arr.begin() + i);
		}
	}
	ReSerializeLeaders(leader_arr, "leader-serialize.txt");
}

void ReSerializeProgrammers(vector<Programmer> vec, string filename) {
	ofstream reserialize_employees(filename, ios::out);

	for (size_t i = 0; i < vec.size(); i++)
	{
		reserialize_employees << vec[i];
	}
}

void FireProgrammers() {
	cout << "----------All programmers in the company----------" << endl << endl;
	ShowAllProgrammersName();
	string programmer_to_fire;
	cin.ignore();
	getline(cin, programmer_to_fire);
	for (size_t i = 0; i < programmer_arr.size(); i++)
	{
		if (programmer_arr[i].GetName() == programmer_to_fire) {
			programmer_arr.erase(programmer_arr.begin() + i);
		}
	}
	ReSerializeProgrammers(programmer_arr, "programmer-serialize.txt");
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
	case 2: FireProgrammers(); break;
	case 3:
		FireLeaders(); break;
	}
}
Analyst ChangedAnalystInformation(Analyst& current_analyst) {

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
			analyst_arr[i] = ChangedAnalystInformation(analyst_arr[i]);
		}
	}
	ReSerializeAnalysts(analyst_arr, "analyst-serialize.txt");
}

Leader ChangedLeaderInformation() {
	string name, address, egn, date, boss, position, level, project, mails;
	EnterCommonInformation(name, address, egn, date, boss, position, level);
	cout << "Enter name of project : ";
	getline(cin, project);
	cout << "Enter mails of clients in one line" << endl;
	getline(cin, mails);
	Leader updated(name, address, egn, date, boss, position, level, project, mails);

	return updated;
}

void ChangeLeadersData() {
	ShowAllLeadersNames();
	string leader_to_change_information;
	cin.ignore();
	getline(cin, leader_to_change_information);
	for (size_t i = 0; i < leader_arr.size(); i++)
	{
		if (leader_arr[i].GetName() == leader_to_change_information) {
			leader_arr[i] = ChangedLeaderInformation();
		}
	}
	ReSerializeLeaders(leader_arr, "leader-serialize.txt");
}

Programmer ChangeProgrammerInformation() {

	string name, address, egn, date, boss, position, level, project;
	EnterCommonInformation(name, address, egn, date, boss, position, level);
	cout << "Enter name of project : ";
	getline(cin, project);

	Programmer updated(name, address, egn, date, boss, position, level, project);

	return updated;
}

void ChangeProgrammersData() {
	ShowAllProgrammersName();
	string programmer_to_change_information;
	cin.ignore();
	getline(cin, programmer_to_change_information);
	for (size_t i = 0; i < programmer_arr.size(); i++)
	{
		if (programmer_arr[i].GetName() == programmer_to_change_information) {
			programmer_arr[i] = ChangeProgrammerInformation();
		}
	}
	ReSerializeProgrammers(programmer_arr, "programmer-serialize.txt");
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
		ChangeAnalystsData(); break;
	case 2:
		ChangeProgrammersData(); break;
	case 3:
		ChangeLeadersData(); break;
	}
}



//TODO :: you can make global variable in main.cpp vector<Employee> employees_arr, and in every adding
//add current type of employee in this variable
//then in this function just employees_arr[i].GetName() i vsichko tochno
vector<string> GetAllEmployees() {
	vector<string> all;
	for (size_t i = 0; i < analyst_arr.size(); i++)
	{
		all.push_back(analyst_arr[i].GetName());
	}
	for (size_t i = 0; i < leader_arr.size(); i++)
	{
		all.push_back(leader_arr[i].GetName());
	}
	for (size_t i = 0; i < programmer_arr.size(); i++)
	{
		all.push_back(programmer_arr[i].GetName());
	}
	return all;
}

void ShowProgrammers() {
	cout << "----All programmers----" << endl;
	for (size_t i = 0; i < programmer_arr.size(); i++)
	{
		cout << programmer_arr[i].GetName() << endl;
	}
}

void ShowAnalysts() {
	cout << "----All analysts----" << endl;
	for (size_t i = 0; i < analyst_arr.size(); i++)
	{
		cout << analyst_arr[i].GetName() << endl;
	}
}

void ShowLeaders() {
	cout << "----All leaders----" << endl;
	for (size_t i = 0; i < leader_arr.size(); i++)
	{
		cout << leader_arr[i].GetName() << endl;
	}
}


void ShowAllEmployees() {
	vector<string> all_employees = GetAllEmployees();
	cout << "----------All employees in the company----------" << endl << endl;
	
	ShowProgrammers();
	ShowAnalysts();
	ShowLeaders();
}
vector<string> GetAllBusyEmployees() {
	vector<string> all_busy_employees;

	for (size_t i = 0; i < teams_arr.size(); i++)
	{
		vector<string> current_team_employees = teams_arr[i].GetMembers();
		current_team_employees.push_back(teams_arr[i].GetTeamLeader());
		for (size_t j = 0; j < current_team_employees.size(); j++)
		{
			all_busy_employees.push_back(current_team_employees[j]);
		}
	}
	return all_busy_employees;
}


bool IsAlreadyInSomeTeam(string employee) {
	
	vector<string> all_busy_ones = GetAllBusyEmployees();
	for (size_t i = 0; i < all_busy_ones.size(); i++)
	{
		if (employee == all_busy_ones[i]) {
			return true;
		}
	}
	return false;
}

void AddParticipantsToCurrentTeam(vector<string>& members) {
	cout << "Enter employee name : ";
	string to_add;

	bool stay_in = true;
	string end;
	while (stay_in) {

		getline(cin, to_add);
		if (IsAlreadyInSomeTeam(to_add)) {
			cout << "Selected employee already participates in one of the teams, please select other employee!" << endl;
		}
		else {
			if (to_add == "end") {
				stay_in = false;
			}
			else {
				members.push_back(to_add);
				//getline(cin, to_add);
			}
		}

	}
}
void LoadInformationForTeams() {
	ifstream deserialize_teams("teams-serialize.txt");

	while (!deserialize_teams.eof()) {
		Teams current;
		deserialize_teams >> current;
		if (current.isNull()) {
			break;
		}
		else {
			teams_arr.push_back(current);
		}
	}
}

void SerializeObjectTeams(Teams& current_team, int participants) {
	ofstream teams_serialize("teams-serialize.txt", ios::app);

	teams_serialize << participants << endl << current_team;
	teams_serialize.close();
}


void ShowAllEmployeesWhichAreNotMemberOfTeams() {
	cout << "----------All employees which are already in some team and you cannot choose them----------" << endl << endl;
	vector<string> all_employees = GetAllEmployees();
	vector<string> all_busy_employees = GetAllBusyEmployees();

	for (size_t i = 0; i < all_busy_employees.size(); i++)
	{
		cout << all_busy_employees[i] << endl;
	}

}

void AddNewTeam() {

	ShowAllEmployees();
	ShowAllEmployeesWhichAreNotMemberOfTeams();
	cout << "FOR EXIT ENTER 'end'" << endl << endl;

	cout << "Enter team leader : ";
	string team_leader;
	getline(cin, team_leader);
	if (team_leader == "end") {
		return;
	}
	bool exit = false;
	while (IsAlreadyInSomeTeam(team_leader)) {
		cout << "Selected employee is already member of some team, please select other employee" << endl;
		getline(cin, team_leader);
	}
	cout << "Enter project name : ";
	string project_name;
	getline(cin, project_name);
	cout << "---Adding members to team---" << endl;
	vector<string> participants;
	AddParticipantsToCurrentTeam(participants);

	Teams current_team(team_leader, project_name, participants);
	teams_arr.push_back(current_team);

	SerializeObjectTeams(current_team, participants.size());
}


void ShowInformationForAllTeams() {
	cout << endl << "----------INFORMATION FOR ALL TEAMS----------" << endl << endl;
	for (size_t i = 0; i < teams_arr.size(); i++)
	{
		cout << "TEAM "<<i+1<<endl<< teams_arr[i].GetInformation() << endl;
	}
}
void ReserializeTeams() {
	//deleting all content of the file in order to rewrite with updated data
	ofstream teams_reserialize("teams-serialize.txt", ios:: out);

	for (size_t i = 0; i < teams_arr.size(); i++)
	{
		int number_of_current_participants = teams_arr[i].GetMembers().size();
		SerializeObjectTeams(teams_arr[i], number_of_current_participants);
	}

}

void MoveEmployeeToOtherTeam(string name, int source, int destination) {
	
	teams_arr[destination - 1].push_new_employee(name);
	vector<string> members_of_destination_team = teams_arr[destination-1].GetMembers();

	teams_arr[source - 1].RemoveEmployee(name);
	vector<string> members_of_source_team = teams_arr[source - 1].GetMembers();


	/*cout << "Members in dest teams" << endl;
	for (size_t i = 0; i < members_of_destination_team.size(); i++)
	{
		cout << members_of_destination_team[i] << endl;
	}

	cout << "Members in source team" << endl;
	for (size_t i = 0; i < members_of_source_team.size(); i++)
	{
		cout << members_of_source_team[i] << endl;
	}*/

	ReserializeTeams();
}

void TransferMembers() {
	ShowInformationForAllTeams();
	cout << "-----From which team you want to transfer? Enter number of the team-----" << endl;
	int team_number_from;
	cin >> team_number_from;
	cout << "-----Enter the name of employee you want to transfer-----" << endl;
	string name_of_employee;
	cin >> name_of_employee;
	cout << "-----To which team you want to transfer the selected employee? Enter number of the team-----" << endl;
	int team_number_to;
	cin >> team_number_to;

	MoveEmployeeToOtherTeam(name_of_employee, team_number_from, team_number_to);

}

void DeleteTeams() {
	//ShowInformationForAllTeams();
	cout << "----------Deleting Team----------" << endl;
	cout << "Before deleting a team, you should transfer all members to other teams!" << endl;
	cout << "Enter team number of the team you want to delete: ";
	int number_of_team_to_delete;
	cin >> number_of_team_to_delete;
	while (!teams_arr[number_of_team_to_delete - 1].HasNoMembers()) {
		TransferMembers();
	}

	cout << "Transferring team leader from this team" << endl;
	cout << "Enter to which team you want to transfer the team leader: ";
	string name_of_team_leader = teams_arr[number_of_team_to_delete - 1].GetTeamLeader();
	int to_which_team;
	cin >> to_which_team;

	teams_arr[to_which_team - 1].push_new_employee(name_of_team_leader);
	teams_arr.erase(teams_arr.begin() + (number_of_team_to_delete-1));

	ReserializeTeams();


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

	LoadInformationForTeams();
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
		case 1: AddNewTeam(); break;
		case 2: TransferMembers(); break;
		case 3: DeleteTeams(); break;
		case 4: ShowInformationForAllTeams(); break;
		}
	} while (operation != 0);

	system("pause");

}