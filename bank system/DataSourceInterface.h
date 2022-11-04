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
class DataSourceInterface
{
protected:
		virtual void addClient(Client) = 0;
	    virtual void addEmployee(Employee) = 0;
		virtual void addAdmin(Admin) = 0;
		virtual void getAllClients() = 0;
		virtual void getAllEmployees() = 0;
		virtual void getAllAdmins() = 0;
		virtual void removeAllClients() = 0;
		virtual void removeAllEmployees() = 0;
		virtual void removeAllAdmins() = 0;
};

