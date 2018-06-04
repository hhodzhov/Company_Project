#include<iostream>
#include<vector>
#include<fstream>
#include"Executor.h"
using namespace std;


static vector<Analyst> analyst_arr1;
static vector<Leader> leader_arr1;
static vector<Programmer> programmer_arr1;
static vector<Teams> teams_arr1;



Executor::Executor()
{
}

 void Executor::LoadInformationForTeams()
{
	ifstream deserialize_teams("teams-serialize1.txt");

	while (!deserialize_teams.eof()) {
		Teams current;
		deserialize_teams >> current;
		if (current.isNull()) {
			break;
		}
		else {
			teams_arr1.push_back(current);
		}
	}
}

 void Executor::LoadAnalysts()
{
	ifstream deserialize_analyst("analyst-serialize1.txt");
	while (!deserialize_analyst.eof()) {
		Analyst current;
		deserialize_analyst >> current;

		if (!current.IsNull()) {
			analyst_arr1.push_back(current);
		}
		else {
			break;
		}
	}
}

 void Executor::LoadLeaders()
{
	ifstream deserialize_leaders("leader-serialize1.txt");
	while (!deserialize_leaders.eof()) {
		Leader current;
		deserialize_leaders >> current;

		if (!current.IsNull()) {
			leader_arr1.push_back(current);
		}
		else {
			break;
		}

	}
}

 void Executor::LoadProgrammers()
{
	ifstream deserialize_programmers("programmer-serialize1.txt");
	while (!deserialize_programmers.eof()) {
		Programmer current;
		deserialize_programmers >> current;

		if (!current.IsNull()) {
			programmer_arr1.push_back(current);
		}
		else {
			break;
		}

	}
}

 void Executor::LoadInformation()
{
	LoadAnalysts();
	LoadLeaders();
	LoadProgrammers();
}

 void Executor::EnterCommonInformation(string & name, string & address, string & egn, string & date, string & boss, string & position, string & level)
{
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

 void Executor::SerializeObjectAnalyst(Analyst & analyst)
{
	ofstream analyst_serialize("analyst-serialize1.txt", ios::app);

	analyst_serialize << analyst;
	analyst_serialize.close();
}

 void Executor::HireAnalyst()
{

	string name, address, egn, date, boss, position, level, project, mails;
	EnterCommonInformation(name, address, egn, date, boss, position, level);
	cout << "Enter name of project : ";
	getline(cin, project);
	cout << "Enter mails of clients in one line" << endl;
	getline(cin, mails);

	Analyst current_analyst(name, address, egn, date, boss, position, level, project, mails);
	analyst_arr1.push_back(current_analyst);

	SerializeObjectAnalyst(current_analyst);

}

 void Executor::SerializeObjectProgrammer(Programmer & programmer)
{
	ofstream programmer_serialize("programmer-serialize1.txt", ios::app);
	programmer_serialize << programmer;
	programmer_serialize.close();

}

 void Executor::HireProgrammer()
{
	string name, address, egn, date, boss, position, level, project;
	EnterCommonInformation(name, address, egn, date, boss, position, level);
	cout << "Enter name of project : ";
	getline(cin, project);
	Programmer current_programmer(name, address, egn, date, boss, position, level, project);
	programmer_arr1.push_back(current_programmer);

	SerializeObjectProgrammer(current_programmer);
}

 void Executor::SerializeObjectLeader(Leader & leader)
{
	ofstream leader_serialize("leader-serialize1.txt", ios::app);
	leader_serialize << leader;
	leader_serialize.close();
}

 void Executor::HireLeader()
{
	string name, address, egn, date, boss, position, level, project, mails;
	EnterCommonInformation(name, address, egn, date, boss, position, level);
	cout << "Enter name of project : ";
	getline(cin, project);
	cout << "Enter mails of clients in one line" << endl;
	getline(cin, mails);
	Leader current_leader(name, address, egn, date, boss, position, level, project, mails);
	leader_arr1.push_back(current_leader);

	SerializeObjectLeader(current_leader);

}

 void Executor::ShowInfoForSelectedAnalyst(string & selected) {
	for (size_t i = 0; i < analyst_arr1.size(); i++)
	{
		if (analyst_arr1[i].GetName() == selected) {
			cout << analyst_arr1[i].GetInformation() << endl;
		}
	}
}

 void Executor::ShowAllAnalystsNames() {
	for (size_t i = 0; i < analyst_arr1.size(); i++)
	{
		cout << analyst_arr1[i].GetName() << endl;
	}
}

 void Executor::ShowInformationForCertainAnalyst() {
	cout << "----------All analysts in the company----------" << endl << endl;
	ShowAllAnalystsNames();
	string analyst_to_chose;
	cin.ignore();
	getline(cin, analyst_to_chose);
	ShowInfoForSelectedAnalyst(analyst_to_chose);

}

 void Executor::
ShowAllProgrammersName() {
	for (size_t i = 0; i < programmer_arr1.size(); i++)
	{
		cout << programmer_arr1[i].GetName() << endl;
	}
}

 void Executor::ShowInfoForSelectedProgrammer(string selected_programmer) {
	for (size_t i = 0; i < programmer_arr1.size(); i++)
	{
		if (programmer_arr1[i].GetName() == selected_programmer) {
			cout << programmer_arr1[i].GetInformation() << endl;
		}
	}
}

 void Executor::ShowInformationForCertainProgrammer() {
	cout << "----------All programmers in the company----------" << endl << endl;
	ShowAllProgrammersName();
	string programmer_to_choose;
	cin.ignore();
	getline(cin, programmer_to_choose);
	ShowInfoForSelectedProgrammer(programmer_to_choose);
}

 void Executor::ShowAllLeadersNames() {
	for (size_t i = 0; i < leader_arr1.size(); i++)
	{
		cout << leader_arr1[i].GetName() << endl;

	}
}

 void Executor::ShowInfoForSelectedLeader(string & selected) {
	for (size_t i = 0; i < leader_arr1.size(); i++)
	{
		if (leader_arr1[i].GetName() == selected) {
			cout << leader_arr1[i].GetInformation() << endl;
		}
	}
}

 void Executor::ShowInformationForCertainLeader() {
	cout << "----------All leaders in the company----------" << endl << endl;
	ShowAllLeadersNames();
	string leader_to_chose;
	cin.ignore();
	getline(cin, leader_to_chose);
	ShowInfoForSelectedLeader(leader_to_chose);
}

 void Executor::ReSerializeAnalysts(vector<Analyst> vec, string file_name) {
	ofstream reserialize_employees(file_name, ios::out);

	for (size_t i = 0; i < vec.size(); i++)
	{
		reserialize_employees << vec[i];

	}
}

 void Executor::FireAnalysts() {
	cout << "----------All analysts in the company----------" << endl << endl;
	ShowAllAnalystsNames();

	string analyst_to_fire;
	cin.ignore();
	getline(cin, analyst_to_fire);
	for (size_t i = 0; i < analyst_arr1.size(); i++)
	{
		if (analyst_arr1[i].GetName() == analyst_to_fire) {
			analyst_arr1.erase(analyst_arr1.begin() + i);
		}
	}
	ReSerializeAnalysts(analyst_arr1, "analyst-serialize1.txt");
}

 void Executor::ReSerializeProgrammers(vector<Programmer> vec, string filename) {
	ofstream reserialize_employees(filename, ios::out);

	for (size_t i = 0; i < vec.size(); i++)
	{
		reserialize_employees << vec[i];
	}
}

 void Executor::FireProgrammers() {
	cout << "----------All programmers in the company----------" << endl << endl;
	ShowAllProgrammersName();
	string programmer_to_fire;
	cin.ignore();
	getline(cin, programmer_to_fire);
	for (size_t i = 0; i < programmer_arr1.size(); i++)
	{
		if (programmer_arr1[i].GetName() == programmer_to_fire) {
			programmer_arr1.erase(programmer_arr1.begin() + i);
		}
	}
	ReSerializeProgrammers(programmer_arr1, "programmer-serialize1.txt");
}

 void Executor::ReSerializeLeaders(vector<Leader> vec, string filename) {
	ofstream reserialize_employees(filename, ios::out);

	for (size_t i = 0; i < vec.size(); i++)
	{
		reserialize_employees << vec[i];
	}
}

 void Executor::FireLeaders() {
	cout << "----------All leaders in the company----------" << endl << endl;
	ShowAllLeadersNames();
	string leader_to_fire;
	cin.ignore();
	getline(cin, leader_to_fire);
	for (size_t i = 0; i < leader_arr1.size(); i++)
	{
		if (leader_arr1[i].GetName() == leader_to_fire) {
			leader_arr1.erase(leader_arr1.begin() + i);
		}
	}
	ReSerializeLeaders(leader_arr1, "leader-serialize1.txt");
}

 void Executor::ShowAllProgrammersInformation() {
	for (size_t i = 0; i < programmer_arr1.size(); i++)
	{
		cout << programmer_arr1[i].GetInformation() << endl;
	}
}

 void Executor::DeserializeObjectProgrammer() {
	ShowAllProgrammersInformation();
}

 void Executor::ShowAllAnalystsInformation() {
	for (size_t i = 0; i < analyst_arr1.size(); i++)
	{
		cout << analyst_arr1[i].GetInformation() << endl;
	}
}

 void Executor::DeserializeObjectAnalyst() {

	ShowAllAnalystsInformation();
}

 void Executor::ShowAllLeadersInformation() {
	for (size_t i = 0; i < leader_arr1.size(); i++)
	{
		cout << leader_arr1[i].GetInformation() << endl;
	}
}

 void Executor::DeserializeObjectLeader() {
	ShowAllLeadersInformation();
}

 Analyst Executor::ChangedAnalystInformation(Analyst & current_analyst) {

	string name, address, egn, date, boss, position, level, project, mails;
	EnterCommonInformation(name, address, egn, date, boss, position, level);
	cout << "Enter name of project : ";
	getline(cin, project);
	cout << "Enter mails of clients in one line" << endl;
	getline(cin, mails);
	Analyst updated(name, address, egn, date, boss, position, level, project, mails);

	return updated;
}

 void Executor::ChangeAnalystsData() {
	ShowAllAnalystsNames();

	string analyst_to_change_information;
	cin.ignore();
	getline(cin, analyst_to_change_information);

	for (size_t i = 0; i < analyst_arr1.size(); i++)
	{
		if (analyst_arr1[i].GetName() == analyst_to_change_information) {
			analyst_arr1[i] = ChangedAnalystInformation(analyst_arr1[i]);
		}
	}
	ReSerializeAnalysts(analyst_arr1, "analyst-serialize1.txt");
}

 Programmer Executor::ChangeProgrammerInformation() {

	string name, address, egn, date, boss, position, level, project;
	EnterCommonInformation(name, address, egn, date, boss, position, level);
	cout << "Enter name of project : ";
	getline(cin, project);

	Programmer updated(name, address, egn, date, boss, position, level, project);

	return updated;
}

 void Executor::ChangeProgrammersData() {
	ShowAllProgrammersName();
	string programmer_to_change_information;
	cin.ignore();
	getline(cin, programmer_to_change_information);
	for (size_t i = 0; i < programmer_arr1.size(); i++)
	{
		if (programmer_arr1[i].GetName() == programmer_to_change_information) {
			programmer_arr1[i] = ChangeProgrammerInformation();
		}
	}
	ReSerializeProgrammers(programmer_arr1, "programmer-serialize1.txt");
}

 Leader Executor::ChangedLeaderInformation() {
	string name, address, egn, date, boss, position, level, project, mails;
	EnterCommonInformation(name, address, egn, date, boss, position, level);
	cout << "Enter name of project : ";
	getline(cin, project);
	cout << "Enter mails of clients in one line" << endl;
	getline(cin, mails);
	Leader updated(name, address, egn, date, boss, position, level, project, mails);

	return updated;
}

 void Executor::ChangeLeadersData() {
	ShowAllLeadersNames();
	string leader_to_change_information;
	cin.ignore();
	getline(cin, leader_to_change_information);
	for (size_t i = 0; i < leader_arr1.size(); i++)
	{
		if (leader_arr1[i].GetName() == leader_to_change_information) {
			leader_arr1[i] = ChangedLeaderInformation();
		}
	}
	ReSerializeLeaders(leader_arr1, "leader-serialize1.txt");
}

 void Executor::ShowProgrammers() {
	cout << "----All programmers----" << endl;
	for (size_t i = 0; i < programmer_arr1.size(); i++)
	{
		cout << programmer_arr1[i].GetName() << endl;
	}
}

 void Executor::ShowAnalysts() {
	cout << "----All analysts----" << endl;
	for (size_t i = 0; i < analyst_arr1.size(); i++)
	{
		cout << analyst_arr1[i].GetName() << endl;
	}
}

 void Executor::ShowLeaders() {
	cout << "----All leaders----" << endl;
	for (size_t i = 0; i < leader_arr1.size(); i++)
	{
		cout << leader_arr1[i].GetName() << endl;
	}
}

 void Executor::ShowAllEmployees() {

	cout << "----------All employees in the company----------" << endl << endl;

	ShowProgrammers();
	ShowAnalysts();
	ShowLeaders();
}

 vector<string> Executor::GetAllBusyEmployees() {
	vector<string> all_busy_employees;

	for (size_t i = 0; i < teams_arr1.size(); i++)
	{
		vector<string> current_team_employees = teams_arr1[i].GetMembers();
		current_team_employees.push_back(teams_arr1[i].GetTeamLeader());
		for (size_t j = 0; j < current_team_employees.size(); j++)
		{
			all_busy_employees.push_back(current_team_employees[j]);
		}
	}
	return all_busy_employees;
}

 vector<string> Executor::GetAllEmployees() {
	vector<string> all;
	for (size_t i = 0; i < analyst_arr1.size(); i++)
	{
		all.push_back(analyst_arr1[i].GetName());
	}
	for (size_t i = 0; i < leader_arr1.size(); i++)
	{
		all.push_back(leader_arr1[i].GetName());
	}
	for (size_t i = 0; i < programmer_arr1.size(); i++)
	{
		all.push_back(programmer_arr1[i].GetName());
	}
	return all;
}

 void Executor::ShowAllEmployeesWhichAreNotMemberOfTeams() {
	cout << "----------All employees which are already in some team and you cannot choose them----------" << endl << endl;
	vector<string> all_employees = GetAllEmployees();
	vector<string> all_busy_employees = GetAllBusyEmployees();

	for (size_t i = 0; i < all_busy_employees.size(); i++)
	{
		cout << all_busy_employees[i] << endl;
	}

}

 bool Executor::IsAlreadyInSomeTeam(string employee) {

	vector<string> all_busy_ones = GetAllBusyEmployees();
	for (size_t i = 0; i < all_busy_ones.size(); i++)
	{
		if (employee == all_busy_ones[i]) {
			return true;
		}
	}
	return false;
}

 void Executor::AddParticipantsToCurrentTeam(vector<string>& members) {
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
			}
		}

	}
}

 void Executor::SerializeObjectTeams(Teams & current_team, int participants) {
	ofstream teams_serialize("teams-serialize1.txt", ios::app);

	teams_serialize << participants << endl << current_team;
	teams_serialize.close();
}

 void Executor::AddNewTeam() {

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
	teams_arr1.push_back(current_team);

	SerializeObjectTeams(current_team, participants.size());
}

 void Executor::ReserializeTeams() {
	//deleting all content of the file in order to rewrite with updated data
	ofstream teams_reserialize("teams-serialize1.txt", ios::out);
	teams_reserialize.close();

	for (size_t i = 0; i < teams_arr1.size(); i++)
	{
		int number_of_current_participants = teams_arr1[i].GetMembers().size();
		SerializeObjectTeams(teams_arr1[i], number_of_current_participants);
	}

}

 void Executor::MoveEmployeeToOtherTeam(string name, int source, int destination) {

	teams_arr1[destination - 1].push_new_employee(name);
	vector<string> members_of_destination_team = teams_arr1[destination - 1].GetMembers();

	teams_arr1[source - 1].RemoveEmployee(name);
	vector<string> members_of_source_team = teams_arr1[source - 1].GetMembers();

	ReserializeTeams();
}

 void Executor::ShowInformationForAllTeams() {
	cout << endl << "----------INFORMATION FOR ALL TEAMS----------" << endl << endl;
	for (size_t i = 0; i < teams_arr1.size(); i++)
	{
		cout << "TEAM " << i + 1 << endl << teams_arr1[i].GetInformation() << endl;
	}
}

 void Executor::TransferMembers() {
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

 void Executor::DeleteTeams() {
	//ShowInformationForAllTeams();
	cout << "----------Deleting Team----------" << endl;
	cout << "Before deleting a team, you should transfer all members to other teams!" << endl;
	cout << "Enter team number of the team you want to delete: ";
	int number_of_team_to_delete;
	cin >> number_of_team_to_delete;
	while (!teams_arr1[number_of_team_to_delete - 1].HasNoMembers()) {
		TransferMembers();
	}

	cout << "Transferring team leader from this team" << endl;
	cout << "Enter to which team you want to transfer the team leader: ";
	string name_of_team_leader = teams_arr1[number_of_team_to_delete - 1].GetTeamLeader();
	int to_which_team;
	cin >> to_which_team;

	teams_arr1[to_which_team - 1].push_new_employee(name_of_team_leader);
	teams_arr1.erase(teams_arr1.begin() + (number_of_team_to_delete - 1));

	ReserializeTeams();


}
