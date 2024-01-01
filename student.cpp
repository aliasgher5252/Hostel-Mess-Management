#include<string>
#include"student.h"
#include"mess.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
using namespace std;
#pragma warning(disable:4996)
string getDate() {
	string month = "0";
	time_t now = time(0);
	string date_time = ctime(&now);
	string strMonth = date_time.substr(4, 4);
	if (strMonth == "Jan ") {
		month = "01";
	}
	if (strMonth == "Feb ") {
		month = "02";
	}
	if (strMonth == "Mar ") {
		month = "03";
	}
	if (strMonth == "Apr ") {
		month = "04";
	}
	if (strMonth == "May ") {
		month = "05";
	}
	if (strMonth == "Jun ") {
		month = "06";
	}
	if (strMonth == "Jul ") {
		month = "07";
	}
	if (strMonth == "Aug ") {
		month = "08";
	}
	if (strMonth == "Sep ") {
		month = "09";
	}
	if (strMonth == "Oct ") {
		month = "10";
	}
	if (strMonth == "Nov ") {
		month = "11";
	}
	if (strMonth == "Dec ") {
		month = "12";
	}
	string year = date_time.substr(20, 12);
	string day = date_time.substr(8, 2);
	return (day + month + year).substr(0,8);
}
Student::Student(string u, string p, string n, string c, string h):Mess(u,p) {  name = n; cms = c; hostel = h; }
void Student::setName() { 
	while(1){
		cout << "Enter your name: ";
		cin >> name;
		if(name.length()<=15){
			break;
		}
		else{
			cout<<"NAME CAN NOT BE GREATER THAN 15 CHARCTERS!!"<<endl;
		}
	}
	
}
void Student::setCms() {
	while(1){
		cout << "Enter your CMS ID: ";
		cin >> cms;
		if(cms.length()==6){
			break;
		}
		else{
			cout<<"Invalid CMS ID!!"<<endl;
		}
	}
}
string Student::getCms(){
	return cms;
}

void Student::setHostel() {
	while(1){
		cout << "Enter your Hostel: ";
		cin >> hostel;
		if(hostel=="ghazali"||hostel=="razi"||hostel=="attar"){
			break;
		}
		else{
			cout<<"Invalid Choice!!"<<endl;
		}
	}
}
string Student::getHostel(){
	return hostel;
}
string Student::getChoiceOFmeal(){
	return choiceOfMeal;
}

string Student::getbill(){
	return bill;
}
void Student::setBill(string a){
	bill=a;
}
void Student::createAccount(){
	bill='0';
	date="01012000";
	fstream fin;
    system("cls");
	setName();
	setCms();
	setUsername();
	setPassword();
	setHostel();
	
	
	
		
	fin.open("database.csv",ios::out|ios::app);
	

	fin<<username<<','<<password<<','<<cms<<','<<name<<','<<hostel<<','<<date<<','<<bill<<endl;
	cout<<"Registration Successfull!"<<endl;
	fin.close();
	fin.clear();

}
bool Student::findRecord(string a){
	int exist=0;
	fstream fin;
	fin.open("database.csv",ios::in|ios::app);
	while(getline(fin,username,',')&&exist==0){
		record.clear();
		getline(fin,password,',');
		getline(fin,cms,',');
		getline(fin,name,',');
		getline(fin,hostel,',');
		getline(fin,date,',');
		getline(fin,bill,'\n');
		if(username==a){
			
			record.push_back(username);
			record.push_back(password);
			record.push_back(cms);
			record.push_back(name);
			record.push_back(hostel);
			record.push_back(date);
			record.push_back(bill);
			username=record[0];
			password=record[1];
			cms=record[2];
			name=record[3];
			hostel=record[4];
			date=record[5];
			bill=record[6];
			return 1;

		}
		
	}	
	return 0;
}
bool Student::login(string a){
	if(password==a){
		return 1;
	}
	return 0;
}
void Student::DisplayRecord(){
	system("cls");
	cout<<"-------------------HOME PAGE--------------------"<<endl;
	cout<<"Hello "<<name<<endl;
	cout<<"Nust Cms ID: "<<cms<<endl;
	cout<<"Hostel: "<<hostel<<endl;
}
void Student::forgot(){
	cout<<"Your Password is: "<<password<<endl;

}
void Student::choice() {
	Mess::showMeal();
	while(1){
		cout << "Do you want to eat tomorrow's breakfast, lunch, or dinner? [Enter b, l, d, bl, ld, bd, bld]: ";
		cin>>choiceOfMeal;
	 	if(choiceOfMeal=="b"||choiceOfMeal=="l"){
			bill=to_string(stoi(bill)+68);
			break;
		}
		else if(choiceOfMeal=="d"){
			bill=to_string(stoi(bill)+137);
			break;
		}
		else if(choiceOfMeal=="ld"||choiceOfMeal=="bd"){
			bill=to_string(stoi(bill)+206);
			break;
		}
		else if(choiceOfMeal=="bl"){
			bill=to_string(stoi(bill)+2*68);
			break;
		}
		else if (choiceOfMeal=="bld"){
			bill=to_string(stoi(bill)+275);
			break;
		}
		else{
			cout<<"INVALID CHOICE!!"<<endl;
		}
	}

}


void Student::UpdateRecord(){
	fstream fin,f2;
	fin.open("database.csv");
	f2.open("databasenew.csv",ios::out|ios::app);
	string a,b,c,d,e,f,g;
	
	while(getline(fin,a,',') && !fin.eof()){
		
		getline(fin,b,',');
		getline(fin,c,',');
		getline(fin,d,',');
		getline(fin,e,',');
		getline(fin,f,',');
		getline(fin,g,'\n');
		if(username==a){
			
			
			f2<<a<<","<<b<<","<<c<<","<<d<<","<<e<<","<<getDate()<<","<<bill<<endl;
			

		}
		else{
			f2<<a<<","<<b<<","<<c<<","<<d<<","<<e<<","<<f<<","<<g<<endl;
		}
		
	}
	fin.close();
	f2.close();
		
	remove("database.csv");
	rename("databasenew.csv","database.csv");
	f2.clear();

}
void Student::UpdateMessBill(){
	fstream fin,f2;
	fin.open("database.csv");
	f2.open("databasenew.csv",ios::out|ios::app);
	string a,b,c,d,e,f,g;
	
	while(getline(fin,a,',') && !fin.eof()){
		
		getline(fin,b,',');
		getline(fin,c,',');
		getline(fin,d,',');
		getline(fin,e,',');
		getline(fin,f,',');
		getline(fin,g,'\n');
		if(username==a){
			
			
			f2<<a<<","<<b<<","<<c<<","<<d<<","<<e<<","<<f<<","<<"0"<<endl;
			

		}
		else{
			f2<<a<<","<<b<<","<<c<<","<<d<<","<<e<<","<<f<<","<<g<<endl;
		}
		
	}
	fin.close();
	f2.close();
		
	remove("database.csv");
	rename("databasenew.csv","database.csv");
	f2.clear();

}

class Student;
bool compare(Student* obj){
	int month = 0;
	time_t now = time(0);
	string date_time = ctime(&now);
	string strMonth = date_time.substr(4, 4);
	if (strMonth == "Jan ") {
		month = 1;
	}
	if (strMonth == "Feb ") {
		month = 2;
	}
	if (strMonth == "Mar ") {
		month = 3;
	}
	if (strMonth == "Apr ") {
		month = 4;
	}
	if (strMonth == "May ") {
		month = 5;
	}
	if (strMonth == "Jun ") {
		month = 6;
	}
	if (strMonth == "Jul ") {
		month = 7;
	}
	if (strMonth == "Aug ") {
		month = 8;
	}
	if (strMonth == "Sep ") {
		month = 9;
	}
	if (strMonth == "Oct ") {
		month = 10;
	}
	if (strMonth == "Nov ") {
		month = 11;
	}
	if (strMonth == "Dec ") {
		month = 12;
	}
	string year = date_time.substr(20, 12);
	string day = date_time.substr(8, 2);
	if (stoi(year) > stoi(obj->date.substr(4, 7))) {
		return true;
		cout << 1 << endl;
	}
	else if (month > stoi(obj->date.substr(2, 3))) {
		return true;
		cout << 1 << endl;
	}
	else if (stoi(date_time.substr(8, 2)) > stoi(obj->date.substr(0, 2))) {
		return true;
		cout << 1 << endl;
	}
	else {
		return false;
	}
}



