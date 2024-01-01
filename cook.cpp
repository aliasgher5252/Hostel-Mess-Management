#include<string>
#include"student.h"
#include"mess.h"
#include"cook.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
using namespace std;
void cook::updateMess(Student *s){
    fstream fin,f2;
    string a,b,c,d;
    cout<<s->getHostel()<<endl;
    fin.open("messRecord.csv",ios::in|ios::app);
    f2.open("messRecordNew.csv",ios::out|ios::app);
    if(s->getChoiceOFmeal()=="b"){
        while(getline(fin,a,',')&&!fin.eof()){
            getline(fin,b,',');
            getline(fin,c,',');
            getline(fin,d,'\n');
            if(a==s->getHostel()){
                b=to_string(stoi(c)+1);
                f2<<a<<','<<b<<','<<c<<','<<d<<endl;
            }
            else{
                f2<<a<<','<<b<<','<<c<<','<<d<<endl;
            }
            
            
        }
    }
    else if(s->getChoiceOFmeal()=="l"){
        while(getline(fin,a,',')&&!fin.eof()){
            getline(fin,b,',');
            getline(fin,c,',');
            getline(fin,d,'\n');
            if(a==s->getHostel()){
                c=to_string(stoi(c)+1);
                f2<<a<<','<<b<<','<<c<<','<<d<<endl;
            }
            else{
                f2<<a<<','<<b<<','<<c<<','<<d<<endl;
            }
            
            
        }
    }
    else if(s->getChoiceOFmeal()=="d"){
		while(getline(fin,a,',')&&!fin.eof()){
            getline(fin,b,',');
            getline(fin,c,',');
            getline(fin,d,'\n');
            if(a==s->getHostel()){
                d=to_string(stoi(d)+1);
                f2<<a<<','<<b<<','<<c<<','<<d<<endl;
            }
            else{
                f2<<a<<','<<b<<','<<c<<','<<d<<endl;
            }
            
            
        }
	}
	else if(s->getChoiceOFmeal()=="ld"){
		while(getline(fin,a,',')&&!fin.eof()){
            getline(fin,b,',');
            getline(fin,c,',');
            getline(fin,d,'\n');
            if(a==s->getHostel()){
                c=to_string(stoi(c)+1);
                d=to_string(stoi(d)+1);

                f2<<a<<','<<b<<','<<c<<','<<d<<endl;
            }
            else{
                f2<<a<<','<<b<<','<<c<<','<<d<<endl;
            }
            
            
        }
	}
    else if(s->getChoiceOFmeal()=="bd"){
        while(getline(fin,a,',')&&!fin.eof()){
            getline(fin,b,',');
            getline(fin,c,',');
            getline(fin,d,'\n');
            if(a==s->getHostel()){
                b=to_string(stoi(b)+1);
                d=to_string(stoi(d)+1);
                f2<<a<<','<<b<<','<<c<<','<<d<<endl;
            }
            else{
                f2<<a<<','<<b<<','<<c<<','<<d<<endl;
            }
            
            
        }
    }
	else if(s->getChoiceOFmeal()=="bl"){
        cout<<"CALLED 2"<<endl;
		while(getline(fin,a,',')&&!fin.eof()){
            getline(fin,b,',');
            getline(fin,c,',');
            getline(fin,d,'\n');
            if(a==s->getHostel()){
                b=to_string(stoi(b)+1);
                c=to_string(stoi(c)+1);
                f2<<a<<','<<b<<','<<c<<','<<d<<endl;
            }
            else{
                f2<<a<<','<<b<<','<<c<<','<<d<<endl;
            }
            
            
        }
	}
	else{
        cout<<"CALLED!!"<<endl;

		while(getline(fin,a,',')&&!fin.eof()){
            getline(fin,b,',');
            getline(fin,c,',');
            getline(fin,d,'\n');

            if(a==s->getHostel()){
                
                b=to_string(stoi(b)+1);
                c=to_string(stoi(c)+1);
                d=to_string(stoi(d)+1);
                cout<<b<<endl;
                f2<<a<<','<<b<<','<<c<<','<<d<<endl;
            }
            else{
                cout<<hostel<<endl;
                f2<<a<<','<<b<<','<<c<<','<<d<<endl;
            }
            
            
        }
	}
    fin.close();
    f2.close();
    remove("messRecord.csv");
    rename("messRecordNew.csv","messRecord.csv");
    f2.clear();
}
void cook::DisplayRecord(){
    int choice;
    string breakfast,lunch,dinner;
    string x;
    system("cls");
    A:
    cout<<"1.Display all hostels data\n2.Display particular hostel data\n3.exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
        {
            system("cls");
            fstream fin;
            fin.open("messRecord.csv");
            while(getline(fin,hostel,',')&&!fin.eof()){
                getline(fin,breakfast,',');
                getline(fin,lunch,',');
                getline(fin,dinner,'\n');
                cout<<"-------------------------------------------------------"<<endl;
                cout<<"HOSTEL NAME: "<<hostel<<endl;
                cout<<"Breakfast Meals: "<<breakfast<<endl;
                cout<<"Lunch Meals: "<<lunch<<endl;
                cout<<"Dinner Meals: "<<dinner<<endl;
                

            }
            cin.get();
            cin.get();
            goto A;
            break;
        }
        case 2:
        {
            
            int exist=0;
            fstream fin;
            fin.open("messRecord.csv");
            system("cls");
            cout<<"Enter Hostel name: ";
            cin>>x;
            while(getline(fin,hostel,',')&&!fin.eof()){
                getline(fin,breakfast,',');
                getline(fin,lunch,',');
                getline(fin,dinner,'\n');
                if(hostel==x){
                    cout<<"Hostel Name: "<<hostel<<endl;
                    cout<<"Breakfast Meals: "<<breakfast<<endl;
                    cout<<"Lunch Meals: "<<lunch<<endl;
                    cout<<"Dinner Meals: "<<dinner<<endl;
                    break;
                    exist=1;
                }
            }
            if(exist=0){
                cout<<"Record Not Found!!!"<<endl;
            }
            cin.get();
            cin.get();
            goto A;
            

        }
        break;
        default:
        {
            return;
        }
    }
}