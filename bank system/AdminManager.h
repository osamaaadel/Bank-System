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
#include"EmpolyeeManager.h"
class AdminManager
{
private:
	static void printAdminMenu() {
		system("cls");
		cout << "(1) Display my info" << endl;
		cout << "(2) Update password " << endl;
		cout << "(3) Add new client " << endl;
		cout << "(4) Search for client " << endl;
		cout << "(5) list all clients " << endl;
		cout << "(6) Edit client info " << endl;
		cout << "(7) Add new employee " << endl;
		cout << "(8) Search for employee " << endl;
		cout << "(9) list all employee " << endl;
		cout << "(10) Editemployee info " << endl;
		cout << "(11) Logout\n" << endl;
	}
	static void back(Admin* admin) {
		cout << endl;
		system("pause");
		adminoptions(admin);
	}
public:
	static Admin* login(int id, string password) {
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) {
			if (aIt->getId() == id && aIt->getPassword() == password)
				return aIt._Ptr;
		}
		return NULL;
	}
	static bool adminoptions(Admin* admin) {
		printAdminMenu();
		cout << "your choice is: ";
		Employee e;
		int choice, id;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			admin->display();
			break;
		case 2:
			ClientManager::updatePassword(admin);
			FileManager::updateAdmins();
			break;
		case 3:
			EmpolyeeManager::newClient(admin);
			break;
		case 4:
			EmpolyeeManager::searchforClient(admin);
			break;
		case 5:
			EmpolyeeManager::listAllClients(admin);
			break;
		case 6:
			EmpolyeeManager::editClientInfo(admin);
			break;
		case 7:
			e.setName(Validation::enterName());
			e.setPassword(Validation::enterPassword());
			e.setSalary(Validation::enterSalary());
			e.setId(FilesHelper::getLast("Employees.txt") + 1);
			admin->addEmployee(e);
			FileManager::updateEmployees();
			cout << "\nEmployee added successfully\n";
			break;
		case 8:
			system("cls");
			cout << "Enter employee id: ";
			cin >> id;
			if (admin->searchEmployee(id) == NULL)
				cout << "\nEmployee not founded\n";
			else
				admin->searchEmployee(id)->display();
			break;
		case 9:
			system("cls");
			cout << "All employees: \n" << endl;
			admin->listEmployee();
			break;
		case 10:
			system("cls");
			cout << "Enter employee id: ";
			cin >> id;
			if (admin->searchEmployee(id) == NULL)
				cout << "\nEmployee not founded\n";
			else {
				string name = Validation::enterName();
				string password = Validation::enterPassword();
				double salary = Validation::enterSalary();
				admin->editEmployee(id, name, password, salary);
				FileManager::updateEmployees();
				cout << "\nEmployee info updated\n";
			}
			break;
		case 11:
				return false;
				break;
		default:
			system("cls");
			adminoptions(admin);
			return true;
		}
		back(admin);
		return true;
	}
};

