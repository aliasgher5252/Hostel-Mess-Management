#include<iostream>
#include<fstream>
#include<istream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<ctime>
#include"student.h"
#include"student.cpp"
#include"mess.h"
#include"mess.cpp"
#include"cook.h"
#include"cook.cpp"
#include"admin.h"
#include"admin.cpp"
#pragma warning(disable:4996)
class mess;
class student;

using namespace std;
int main(){
    Mess *m1;
    int choice,choice2;
    string username,password;
	cout << "1.LOGIN\n2.Register\n3.Forgot password\n4.Cook Access\n5.Admin Access\n6.Exit" << endl;
	cout << "Enter your choice: ";
	cin >> choice;


	switch (choice) {
	case 1:
        { 
        system("cls");
		Student *s1=new Student;
        cout<<"Enter Username: ";
        cin>>username;
        cout<<"Enter Password: ";
        cin>>password;
        if(s1->findRecord(username) && s1->login(password)){
            A:
            s1->DisplayRecord();
            cout<<"--------------------------MENUE-----------------------------"<<endl;
            cout<<"1.View Tomorrow's Meal\n2.Enter Number Of Meals For Tomorrow\n3.View Current Mess bill\n5.Logout"<<endl;
            cout<<"Enter your Choice: ";
            cin>>choice2;
            switch(choice2){
                case 1:
                {   
                    system("cls");
                    s1->showMeal();
                }
                break;
                case 2:
                {  
                    cook *c1=new cook;
                    system("cls"); 
                    if(compare(s1)){
                       
                        s1->choice();
                        
                        s1->UpdateRecord();
                        c1->updateMess(s1);
                        cin.get();
                        cin.get();
                        system("cls");
                        goto A;
                    }
                    else{
                        cout<<"Record for tomorrow already saved"<<endl;
                        cin.get();
                        cin.get();
                        system("cls");
                        goto A;
                    }
                }
                break;
                case 3:
                {
                    system("cls");
                    cout<<"Your current Mess Bill is: Rs "<<s1->getbill()<<endl;
                    cin.get();
                    cin.get();
                    system("cls");
                    goto A;
                }
                break;
                case 4:
                {
                    
                    system("cls");
                    main();
                    
                }
                break;
                default:
                {
                    return 0;
                }

            }

        }
        
        
        else{
            cout<<"Invalid Username or Password"<<endl;
            
        }
        
    }
    cin.get();
    cin.get();
    system("cls");
    main();
	break;
	case 2:
        {
        Student *s2=new Student;
		s2->createAccount();
        }
        cin.get();
        cin.get();
        system("cls");
        main();
		break;
	case 3:
        {
        system("cls");
		Student *s3=new Student;
        cout<<"Enter username: ";
        cin>>username;
        if(s3->findRecord(username)){
            s3->forgot();
        }
        else{
            cout<<"INVALID RECORD"<<endl;
        }
        
        }
        cin.get();
        cin.get();
        system("cls");
        main();
		break;
    case 4:
    {
        system("cls");
        cook c1;
        m1=&c1;
        cout<<"Enter Username: ";
        cin>>username;
        cout<<"Enter Password: ";
        cin>>password;
        if(username=="cook123"&&password=="cook"){
            
            m1->DisplayRecord();
        }
         else{
            cout<<"Invalid Username and password for cook Access"<<endl;
        }
    }
    cin.get();
    cin.get();
    main();
    break;
    case 5:
    {
        system("cls");
        cout<<"Enter Username: "<<endl;
        cin>>username;
        cout<<"Enter Password; "<<endl;
        cin>>password;
        if(username=="admin123"&&password=="admin"){
            admin a1;
            m1=&a1;
            m1->DisplayRecord();
        }
        else{
            cout<<"Invalid Username and password for Admin Access"<<endl;
        }

    }
    cin.get();
    cin.get();
    main();
	default:
		return 0;
	}
    return 0;
}
    


