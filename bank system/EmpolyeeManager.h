#pragma once
#include<sstream>
#include"Admin.h"
#include<vector>
#include<string>
#include"Client.h"
#include"Parser.h"
#include"Employee.h"
#include<fstream>
#include"Parser.h"
#include"FilesHelper.h"
#include"DataSourceInterface.h"
#include"FileManager.h"
#include"Person.h"
#include"Validation.h"
#include"ClientManager.h"
class EmpolyeeManager
{
private:
	static void printEmpolyeeMenu() {
		system("cls");
		cout << "(1) Display my info" << endl;
		cout << "(2) Update password " << endl;
		cout << "(3) Add new client " << endl;
		cout << "(4) Search for client " << endl;
		cout << "(5) list all clients " << endl;
		cout << "(6) Edit client info " << endl;
		cout << "(7) Logout\n" << endl;
}
	static void back(Employee* employee) {
		cout << endl;
		system("pause");
		employeeoptions(employee);
	}
public:
	static void newClient(Employee* employee) {
		Client client;
		client.setId(FilesHelper::getLast("ClaientLastId.txt") + 1);
		string password;
		client.setName(Validation::enterName());
		client.setPassword(Validation::enterPassword());
		employee->addClient(client);
		FileManager::updateClients();
		cout << "\nClient added successfully.\n";
  }
	static void searchforClient(Employee* employee) {
		int id;
		system("cls");
		cout << "Enter client id: ";
		cin >> id;
		if (employee->searchClient(id) == NULL)
			cout << "\client not found\n";
		else
			employee->searchClient(id)->display();
	}
	static void listAllClients(Employee* employee) {
		system("cls");
		cout << "All clients: " << endl;
		employee->listClient();
	}
	static void editClientInfo(Employee* employee) {
		int id;
		system("cls");
		cout << "Enter client id: ";
		cin >> id;
		if (employee->searchClient(id) == NULL)
			cout << "\Client not found\n";
		else {
			string name = Validation::enterName();
			string password = Validation::enterPassword();
			double balance = Validation::enterBlanace();
			employee->editClient(id, name, password, balance);
			FileManager::updateClients();
			cout <<"\Client info updated\n";
		}
	}
	static Employee* login(int id, string password) {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getId() == id && eIt->getPassword() == password)
				return eIt._Ptr;

	 }
		return NULL;
	}
	static bool employeeoptions(Employee* employee) {
		printEmpolyeeMenu();
		cout << "your choice is: ";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			employee->display();
			break;
		case 2:
			ClientManager::updatePassword(employee);
			FileManager::updateEmployees();
			break;
		case 3:
			newClient(employee);
			break;
		case 4:
			searchforClient(employee);
			break;
		case 5:
			listAllClients(employee);
			break;
		case 6:
			editClientInfo(employee);
			break;
		case 7:
			return false;
		default:
			system("cls");
			employeeoptions(employee);
			return true;
		}
		back(employee);
		return true;
	}
};

