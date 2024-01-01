#ifndef cook_H
#define cook_H
using namespace std;
#include"student.h"
class cook:public Student{
    public:
    void DisplayRecord();
    void updateMess(Student*);
    
};
#endif