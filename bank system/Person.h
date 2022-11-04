#pragma once
#include"Validation.h"
using namespace std;
class Person
{
protected:
	//attrib
	string name;
	int id;
	string password;
public:
	//const
	Person() {
		this->name = " ";
		this->id = 0;
		this->password = " ";
	}
	Person(string name, int id, string password) {
		this->name = name;
		this->id = id;
		this->password = password;
	}
	//setters
	void setName(string name) {
		this->name = Validation::enterName();
	}
	void setId(int id) {
		this->id = id;
	}
	void setPassword(string password) {
		this->password = Validation::enterPassword();
	}
	//get
	string getName() {
		return this->name;
	}
	int getId() {
		return this->id;
	}
	string getPassword() {
		return this->password;
	}
	//method
	void display() {
		cout << "Name: " << this->name << endl;
		cout << "Id: " << this->id<< endl;
	}
};

