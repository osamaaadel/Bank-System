#pragma once
#include"Validation.h"
#include"Person.h"
#include<vector>
using namespace std;
class Client:public Person
{
private:
//attrib
	double balance;
public:
	//const
	Client() :Person() {
		this->balance = 0.0;
	}
	Client(string name, int id, string password, double balance) :Person(name, id, password) {
		this->balance = balance;
	}
	//sett
	void setBalance(double balance) {
		this->balance = Validation::enterBlanace();

	}
	//get
	double getBalance() {
		return this->balance;
	}
	//methods
	void display() {
		Person::display();
		cout << "Balance: " << this->balance << endl;
	}
	void deposit(double amount) {
		this->balance += amount;
		cout << "\nSuccessful transaction.\n";
	}
	void withdraw(double amount) {
		if (amount <= this->balance) {
			this->balance -= amount;
			cout << "\nSuccessful transaction.\n";
		}
		else
			cout << "\nAmount Exceeded.\n";
	}
	void transferTo(double amount, Client& recipient) {
		if (amount <= balance) {
			this->balance -= amount;
			recipient.balance += amount;
			cout << "\nSuccessful transaction.\n";
	 }
		else 
			cout << "\nAmount Exceeded.\n";
	}
	void checkBalance() {
		cout << "Balance: " << this->balance << endl;
	}
	/*static vector<Client> allClients;
	static vector<Client>::iterator c1It;*/
};
static vector<Client> allClients;
static vector<Client>::iterator clIt;

