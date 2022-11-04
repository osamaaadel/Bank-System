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
class ClientManager
{
private:
	static void printClientMenu() {
		system("cls");
		cout << "(1) Display my info" << endl;
		cout << "(2) Check balance " << endl;
		cout << "(3) Update password " << endl;
		cout << "(4) Withdraw " << endl;
		cout << "(5) Deposit " << endl;
		cout << "(6) Transfer amount " << endl;
		cout << "(7) logout " << endl;
}
	static void back(Client* client) {
		cout << endl;
		system("pause");
		clientOption(client);
	}
public:
	static void updatePassword(Person* person) {
		person->setPassword(Validation::enterPassword());
		cout <<"\password update.\n";
	}
	static Client* login(int id, string password) {
		for (int i = 0; i < allClients.size(); i++) {
			if (allClients[i].getId() == id && allClients[i].getPassword() == password)return&allClients[i];
	 }
		return NULL;
	}
	static bool clientOption(Client* client) {
		printClientMenu();
		cout << "Your choice is: ";
		Employee e;
		double amount;
		int choice, id;
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			client->display();
			break;
		case 2:
			system("cls");
			client->checkBalance();
			break;
		case 3:
			updatePassword(client);
			FileManager::updateClients();
			break;
		case 4:
			system("cls");
			cout << "Enter amount to withdraw: ";
			cin >> amount;
			client->withdraw(amount);
			FileManager::updateClients();
				break;
		case 5:
			system("cls");
			cout << "Enter amount to deposit: ";
			cin >> amount;
			client->deposit(amount);
			FileManager::updateClients();
			break;
		case 6:
			system("cls");
			cout << "Enter id of the recipient: ";
			cin >> id;
			while (e.searchClient(id) == NULL) {
				system("cls");
				cout << "Invalid id\n";
				cout << "Enter id of the recipient: ";
				cin >> id;
			}
			cout << "\nEnter amount to transfer: ";
			cin >> amount;
			client->transferTo(amount, *e.searchClient(id));
			FileManager::updateClients();
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			clientOption(client);
			return true;
		}
		back(client);
		return true;
	}

};

