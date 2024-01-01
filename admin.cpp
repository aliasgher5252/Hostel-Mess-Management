#include<string>
#include"student.h"
#include"mess.h"
#include"cook.h"
#include"admin.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
using namespace std;
admin::admin(string d,int p){
    dueDate=d;
    penalty=p;
}
void admin::UpdateBill(){
    Student s1;
    system("cls");
    cout<<"Enter username: ";
    cin>>username;
    if(s1.findRecord(username)){
        s1.UpdateMessBill();
        cout<<"Bill Updated Successfully!!"<<endl;
        system("cls");

    }
}
void  admin::DisplayRecord()
{
    system("cls");
    int choice;
    A:
    cout<<"-------------------------ADMIN PAGE-------------------------"<<endl;
    cout<<"1.Generate Bill\n2.Update Bill\n3.Exit"<<endl;
    cout<<"Enter Choice: ";
    cin>>choice;

    switch(choice){
        case 1:
        {
            system("cls");
            cout<<"Enter Due Date: ";
            cin>>dueDate;
            cout<<"Enter Penalty: ";
            cin>>penalty;
            system("cls");
            int choice2;
            cout<<"1.Generate Bill of all Students\n2.Generate Bill of a Hostel\n3.Generate Bill of a student"<<endl;
            cin>>choice2;
            GenerateBill(choice2);
            system("cls");
            cout<<"GENERATED SUCCESSFULLY!!"<<endl;

            cin.get();
            cin.get();
            goto A;

        }
        break;
        case 2:
        {
            UpdateBill();
        }
        break;
        default:
        {
            return;
        }
    }
}
void admin::GenerateBill(int choice){
    switch(choice){
        case 1:
        {
            fstream fin;
            fin.open("database.csv");
            while(getline(fin,username,',')&&!fin.eof()){
                getline(fin,password,',');
                getline(fin,cms,',');
                getline(fin,name,',');
                getline(fin,hostel,',');
                getline(fin,date,',');
                getline(fin,bill,'\n');

                fstream *file=new fstream;
                file->open(username+".txt",ios::out|ios::app);
                *(file)<<"Username: "<<username<<"\nCMS ID: "<<cms<<"\nHostel Name: "<<hostel<<"\nBill: Rs "<<bill<<"\nDue Date: "<<date<<"\nBill After Due Date: Rs "<<stoi(bill)+penalty<<endl;
            }
        }
        break;
        case 2:
        {
            fstream fin;
            fin.open("database.csv");
            string hostelName;
            system("cls");
            cout<<"Enter Hostel Name: ";
            cin>>hostelName;
            fstream file;
            while(getline(fin,username,',')&&!fin.eof()){
                getline(fin,password,',');
                getline(fin,cms,',');
                getline(fin,name,',');
                getline(fin,hostel,',');
                getline(fin,date,',');
                getline(fin,bill,'\n');
                if(hostel==hostelName){
                   
                    file.open(username+".txt",ios::out|ios::app);
                    file<<"Username: "<<username<<"\nCMS ID: "<<cms<<"\nHostel Name: "<<hostel<<"\nBill: Rs "<<bill<<"\nDue Date: "<<date<<"\nBill After Due Date: Rs "<<stoi(bill)+penalty<<endl;
                }
                else{
                    cout<<"HOSTEL NOT FOUND!"<<endl;

                }
            }


        }
        break;
        case 3:
        {
            system("cls");
            Student s1;
            cout<<"Enter username: ";
            cin>>username;
            if(s1.findRecord(username)){
                fstream file;
                file.open(s1.getUsername()+".txt",ios::out|ios::app);
                file<<"Username: "<<s1.getUsername()<<"\nCMS ID: "<<s1.getCms()<<"\nHostel Name: "<<s1.getHostel()<<"\nBill: Rs "<<s1.getbill()<<"\nDue Date: "<<dueDate<<"\nBill After Due Date: Rs "<<stoi(s1.getbill())+penalty<<endl;
            }
        }
        break;
        default:
        {
            return;
        }
    }


}
