#ifndef MESS_H
#define MESS_H
#include <string>
using namespace std;
class Mess {
protected:
	string username, password;
public:
	Mess(string username="", string password="");
	string getTime();
	void showMeal();
	virtual void DisplayRecord()=0;
	void setUsername();
	string getUsername();
	void setPassword();
};
#endif // !MESS_H
