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
#include"AdminManager.h"
#include<iostream>
//#include <synchapi.h>
//#include<stdlib.h>
//#include<chrono>
//#include<thread>
//#include<windows.h>
class Screen
{
public:
	static void bankNane() {
		cout << "\t\t@@       @@   @@@@@@@      #######     ##########   ####    ##  ##    ##\n";
		cout << "\t\t@@   @   @@   @@           ##    ##    ##      ##   ## ##   ##  ##   ##\n";
		cout << "\t\t@@  @@@  @@   @@@@@@@      #######     ##########   ## ##   ##  ##  #\n";
		cout << "\t\t@@ @@ @@ @@   @@           ##    ##    ##      ##   ##  ##  ##  ##   ##\n";
		cout << "\t\t@@@      @@@  @@@@@@@      #######     ##      ##   ##   ####   ##    ##\n";
	}
	static void welcome() {
		cout << "\n\n\n\n\n\n\t    ##      ##   #######   ##     #########    ############   #####   #####    ##########\n";
		cout << "\t    ##   #  ##  ##         ##     ##        ##    ##      ##     #  #  ##   ##\n";
		cout << "\t    ##  ### ##  #######    ##     ##         ##    ##      ##      ##   ##   #######\n";
		cout << "\t    ## ## ## ## ##         ##     ##         ##    ##      ##      ##        ##\n";
		cout << "\t    ###      ### ######    ######  ######    ##### ####    #####    #####    #######\n";
		bankNane();
		/*Sleep(3000);*/
		system("cls");
	}
	static void loginoptions() {
		cout << "(1) Admin" << endl;
		cout << "(2) Employee" << endl;
		cout << "(3) Client" << endl;
		cout << "login as: ";
}
	static int loginAs() {
		loginoptions();
		int choice;
		cin >> choice;
		if (choice == 1 || choice == 2 || choice == 3) {
			system("cls");
			return choice;
		}
		else {
			system("cls");
			return loginAs();
		}
	}
	static void invalid(int c) {
		system("cls");
		cout << "Incorrect id or password\n" << endl;
		loginScreen(loginAs());
	}
	static void logout() {
		system("cls");
		loginScreen(loginAs());
	}
	static void loginScreen(int c) {
		int choice = c, id;
		string pass;
		cout << "Enter id: ";
		cin >> id;
		cout << "Enter password: ";
		cin >> pass;
		switch (choice) {
		case 1:
			if (AdminManager::login(id, pass) != NULL) {
				while (AdminManager::adminoptions(AdminManager::login(id, pass)) != false);
				logout();
			}
			else invalid(1);
			break;
		case 2:
			if (EmpolyeeManager::login(id, pass) != NULL) {
				while (EmpolyeeManager::employeeoptions(EmpolyeeManager::login(id, pass)) != false);
				logout();
			}
			else invalid(2);
			break;
		case 3:
			if (ClientManager::login(id, pass) != NULL) {
				while (ClientManager::clientOption(ClientManager::login(id, pass)) != false)
					logout();
			}
			else invalid(3);
			break;
			default:
				system("cls");
				loginoptions();
		}
	}
public:
	static void runApp() {
		FileManager::getAllData();
		welcome();
		loginScreen(loginAs());
	}

};

