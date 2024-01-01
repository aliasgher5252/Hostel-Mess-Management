#include"mess.h"
#include<iostream>
#include<ctime>
#include<string>
using namespace std;
Mess::Mess(string u,string p){username=u;password=p;}
void Mess::setUsername(){
	cout<<"Enter Username (Same as NUST LMS): ";
	cin>>username;
}
void Mess::setPassword(){
	while(1){
		cout<<"Enter Password: ";
		cin>>password;
		if(password.length()<=8){
			break;

		}
		else{
			cout<<"Password length cannot be greater than 8 characters!!"<<endl;
		}
	}
}
string Mess::getUsername(){
	return username;
}
string Mess::getTime() { 
	time_t now = time(0);
	string date_time = ctime(&now);
	return date_time;
}
void Mess::showMeal() {
	string mealArr[7][4] = { {"Breakfast: Boiled egg with paratha and tea", "\nLunch: Matar Aloo","\nDinner: Aloo Qeema","\0"},
							 {"Breakfast: Kulcha chana with tea", "\nLunch: Daal Maash", "\nDinner: Chicken Manchurian and Egg Fried Rice","\0"},
							 {"Breakfast: Aalu Khakina with paratha and tea", "\nLunch: Pakora Kari", "\nDinner: Chicken Karahi","\0"},
							 {"Breakfast: Bread butter jam", "\nLunch: Aalu Palak","\nDinner: Chicken Biryani", "\0"},
							 {"Breakfast: Omelette and Paratha with tea", "\nLunch: White rice with pulses", "\nDinner: Chicken haleem","\0"},
							 {"Breakfast: Aalu Paratha with Youghurt", "\nLunch: Daal Kaddu", "\nDinner: Daal with Shami Kabab","\0"},
							 {"Breakfast: Halwa Puri", "\nLunch: Red Bean", "\nDinner: Chicken curry and plain rice","\0"} };
	string day = getTime();
	day = day.substr(0, 3);
	if (day == "Mon") {
		for (int i = 0; i < 3; i++) {
			cout << mealArr[1][i];
		}
		cout << "\n";
	}
	if (day == "Tue"){
		for (int i = 0; i < 3; i++) {
			cout << mealArr[2][i];
		}
		cout << "\n";
	}
	if (day == "Wed") {
		for (int i = 0; i < 3; i++) {
			cout << mealArr[3][i];
		}
		cout << "\n";
	}
	if (day == "Thu") {
		for (int i = 0; i < 3; i++) {
			cout << mealArr[4][i];
		}
		cout << "\n";
	}
	if (day == "Fri") {
		for (int i = 0; i < 3; i++) {
			cout << mealArr[5][i];
		}
		cout << "\n";
	}
	if (day == "Sat") {
		for (int i = 0; i < 3; i++) {
			cout << mealArr[6][i];
		}
		cout << "/n";
	}
	if (day == "Sun") {
		for (int i = 0; i < 3; i++) {
			cout << mealArr[0][i];
		}
		cout << "\n";
	}
	cout << "\nAll breakfast and lunch cost RS 68.75/-" << endl;
	cout << "Dinner costs RS 137.5" << endl;
}