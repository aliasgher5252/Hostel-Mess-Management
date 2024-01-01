#ifndef ADMIN_H
#define ADMIN_H
#include"mess.h"
#include"student.h"
using namespace std;
class admin:public Student{
    protected:
    string dueDate;
    int penalty;
    public:
    admin(string dueDate="",int penalty=0);
    void DisplayRecord();
    void GenerateBill(int);
    void UpdateBill();
};
#endif