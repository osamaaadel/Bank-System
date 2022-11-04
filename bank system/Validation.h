#pragma once
#include <iostream>
#include<string>
using namespace std;
class Validation
{
private:
	static bool validName(string name) {
		for (int i = 0; i < name.length(); i++) {
			if (!isalpha(name[i]) || name.length() < 5 || name.length() > 20)return false;
	}
		return true;
	}
	static bool validPassword(string password) {
		for (int i = 0; i < password.length(); i++) {
			if (password[i] == ' ' || password.length() < 8 || password.length() > 20)return false;
		}
		return true;
	}
public:
	static string enterName() {
		string name;
		cout << "Please enter your name: ";
		cin >> name;
		while (!validName(name)) {
			cout << "Invalid name\n";
			cout << "Name must be 5 to 20 alphabetic characters.\n" << endl;
			cout << "Please enter your name again.";
			cin >> name;
		}
		return name;
}
	static string enterPassword() {
		string password;
		cout << "Enter password: ";
		cin >> password;
		while (!validPassword(password)) {
			cout << "Invalid password \n";
			cout << "Password must be 8 to 20 charactera.\n" << endl;
			cin >> password;
		}
		return password;
 }
	static double enterBlanace() {
		double balance;
		cout << "enter balance: ";
		cin >> balance;
		while (balance < 1500) {
			cout << "Invalid balance\n";
			cout << "Balance must be at least 1500.\n" << endl;
			cout << "enter balance ";
			cin >> balance;
		}
		return balance;
	}
	static double enterSalary() {
		double salary;
		cout << "enter salary: ";
		cin >> salary;
		while (salary < 5000) {
			cout << "Invalid salary\n";
			cout << "salary must be at least 1500.\n" << endl;
			cout << "enter salary ";
			cin >> salary;
		}
		return salary;
	}

};

