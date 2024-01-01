#ifndef STUDENT_H
#define STUDENT_H
#include"mess.h"
#include<string>
#include<vector>
using namespace std;
class Student :public Mess {
protected:
	string name, cms, hostel,date;
	string bill;
	string choiceOfMeal;
	vector<string> record;
public:
	friend bool compare(Student*);
	Student(string username="",string password="", string name = "", string cms = "", string hostel = "");
	
	void setName();
	void setCms();
	string getCms();
	void setHostel();
	void setBill(string);
	string getChoiceOFmeal();
	string getHostel();
	void createAccount();
	bool login(string);
	void forgot();
	bool findRecord(string);
	virtual void DisplayRecord();
	void choice();
	void UpdateRecord();
	string getbill();
	void UpdateMessBill();

};
bool compare();
#endif
