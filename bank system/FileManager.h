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
class FileManager:public DataSourceInterface
{
private:
	static void addClient(Client client) {
				FilesHelper::saveClient(client);
			}
			static void addEmployee(Employee employee) {
				FilesHelper::saveEmployee("Employees.txt", "EmployeeLastId.txt", employee);
			}
			static void addAdmin(Admin admin) {
				FilesHelper::saveEmployee("Admins.txt", "AdminLastId.txt", admin);
			}
			static void getAllClients() {
				FilesHelper::getClients();
			}
			static void getAllEmployees() {
				FilesHelper::getEmployees();
			}
			static void getAllAdmins() {
				FilesHelper::getAdmins();
			}
			static void removeAllClients() {
				FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
			}
			static void removeAllEmployees() {
				FilesHelper::clearFile("Employees.txt", "EmployeeLastId.txt");
			}
			static void removeAllAdmins() {
				FilesHelper::clearFile("Admins.txt", "AdminLastId.txt");
			}
public:
	static void getAllData() {
				getAllClients();
				getAllEmployees();
				getAllAdmins();
			}
			static void updateClients() {
				removeAllClients();
				for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) addClient(*clIt);
			}
			static void updateEmployees() {
				removeAllEmployees();
				for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) addEmployee(*eIt);
			}
			static void updateAdmins() {
				removeAllAdmins();
				for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) addAdmin(*aIt);
			}
};

