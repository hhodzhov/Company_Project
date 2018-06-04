#pragma once
#ifndef SOFTWARE_COMPANY
#define SOFTWARE_COMPANY

#include<iostream>
#include<string>
#include<vector>
#include"Company.h"
#include"Teams.h"
using namespace std;


class Executor {

	void LoadAnalysts();
	void LoadLeaders();
	void LoadProgrammers();
	void SerializeObjectAnalyst(Analyst & analyst);
	void SerializeObjectProgrammer(Programmer& programmer);
	void SerializeObjectLeader(Leader& leader);

	void ShowAllAnalystsNames();
	void ShowAllProgrammersName();
	void ShowAllLeadersNames();

	void ShowInfoForSelectedAnalyst(string& selected);
	void ShowInfoForSelectedLeader(string& selected);
	void ShowInfoForSelectedProgrammer(string selected_programmer);

	void ReSerializeAnalysts(vector<Analyst> vec, string file_name);
	void ReSerializeProgrammers(vector<Programmer> vec, string filename);
	void ReSerializeLeaders(vector<Leader> vec, string filename);

	void ShowAllProgrammersInformation();
	void ShowAllAnalystsInformation();
	void ShowAllLeadersInformation();

	Analyst ChangedAnalystInformation(Analyst& current_analyst);
	Programmer ChangeProgrammerInformation();
	Leader ChangedLeaderInformation();

	void ShowProgrammers();
	void ShowAnalysts();
	void ShowLeaders();

	vector<string> GetAllBusyEmployees();
	vector<string> GetAllEmployees();
	void ShowAllEmployeesWhichAreNotMemberOfTeams();

	bool IsAlreadyInSomeTeam(string employee);
	void AddParticipantsToCurrentTeam(vector<string>& members);
	void SerializeObjectTeams(Teams& current_team, int participants);
	void ReserializeTeams();
	void MoveEmployeeToOtherTeam(string name, int source, int destination);
	void ShowAllEmployees();


public:

	Executor();

	void LoadInformationForTeams();
	void LoadInformation();

	void EnterCommonInformation(string& name, string& address, string& egn, string& date, string& boss, string& position, string& level);

	void HireAnalyst();
	void HireProgrammer();
	void HireLeader();

	void ShowInformationForCertainAnalyst();
	void ShowInformationForCertainProgrammer();
	void ShowInformationForCertainLeader();

	void FireAnalysts();
	void FireProgrammers();
	void FireLeaders();

	void DeserializeObjectProgrammer();
	void DeserializeObjectAnalyst();
	void DeserializeObjectLeader();

	void ChangeAnalystsData();
	void ChangeProgrammersData();
	void ChangeLeadersData();

	void AddNewTeam();
	void ShowInformationForAllTeams();
	void TransferMembers();
	void DeleteTeams();

};






#endif // !SOFTWARE_COMPANY

