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
using namespace std;
class FilesHelper
{
private:
	//write
	static void saveLast(string fileName, int id) {
		ofstream file;
		file.open(fileName);
		file << id;
		file.close();
	}
public:
	//read
	static int getLast(string filename) {
		ifstream file;
		file.open(filename);
		int id;
		file >> id;
		file.close();
		return id;
	}
	static void saveClient(Client c) {
		int id = getLast("ClientLast.txt");
		fstream file;
		file.open("Clients.txt", ios::app);
		file << id + 1 << '&' << c.getName() << '&' << c.getPassword() << '&' << c.getBalance() << "\n";
		file.close();
		saveLast("Clients.txt", id + 1);
	}
	static void saveEmployee(string fileName, string lastIdfile, Employee e) {
		int id = getLast(lastIdfile);
		fstream file;
		file.open(fileName, ios::app);
	file << id + 1 << '&' << e.getName() << '&' << e.getPassword() << '&' << e.getSalary() << "\n";
	file.close();
	saveLast(lastIdfile, id + 1);
	}
	static void getClients() {
		string line;
		ifstream file;
		file.open("Clients.txt");
		while (getline(file, line)) {
			Client c = Parser::parseToClient(line);
			allClients.push_back(c);
		}
		file.close();
   }
	static void getEmployees() {
		string line;
		ifstream file;
		file.open("Employees.txt");
		while (getline(file, line)) {
			Employee e = Parser::parseToEmployee(line);
			allEmployees.push_back(e);
		}
		file.close();
	}
	static void getAdmins() {
		string line;
		ifstream file;
		file.open("Admins.txt");
		while (getline(file, line)) {
			Admin a = Parser::parseToAdmin(line);
			allAdmins.push_back(a);
		}
		file.close();
 }
	static void clearFile(string filename, string lastIdFile) {
		fstream file1, file2;
		file1.open(filename, ios::out, ios::trunc);
		file1.close();
		file2.open(lastIdFile, ios::out);
		file2 << 0;
		file2.close();
	}
};

