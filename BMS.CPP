#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>

class account
{
    public :
    char name[20];
    char type[15];
    char branch[20];
    float acc,amount;
    void add();
    void show_all();
    void search();
    void edit();
};

fstream file;
account obj;

void account:: add()
{
    cout<<"\n\n\t Enter Holder Name :";
    cin>>name;
    cout<<"\n\t Enter Type of Account s or c :";
    cin>>type;
    cout<<"\n\t Enter Branch :";
    cin>>branch;
    cout<<"\n\t Enter Account number :";
    cin>>acc;
    cout<<"\n\t Enter Initial Amount :";
    cin>>amount;

    file.open("database.txt",ios::app) ;
    file.write((char*)&obj,sizeof(obj));
    file.close();
}

void account:: show_all()
{
    file.open("database.txt",ios::in);
    file.read((char*)&obj,sizeof(obj));

    while (file.eof()==0)
    {
	    cout<<"\n--------------------------------------------------------"<<endl;
	    cout<<"\t| Holder Name | ";
	    cout<<" Type of Account |";
	    cout<<" Branch |" ;
	    cout<<" Account Number |" ;
	    cout<<"Balance|"<<endl;
	    cout<<"----------------------------------------------------------";
	    cout<<"\n\t|"<<name<<"|"<<type<<"|"<<branch<<"|"<<acc<<"|"<<amount<<"|"<<endl;

	file.read((char*)&obj,sizeof(obj));
    }
    file.close();
    getch();
}

void account::search()
{
    float user;
    cout<<"\t Enter Account Number " ;
    cin>>user;
    file.open("database.txt",ios::in);
    file.read((char*)&obj,sizeof(obj));

    while (file.eof()==0)
    {
	if (obj.acc==user)
	{
	    cout<<"\t Holder Name : "<<name<<endl;
	    cout<<"\t Type of Account :" <<type<<endl;
	    cout<<"\t Branch " <<branch<<endl;
	    cout<<"\t Account Number :" <<acc<<endl<<endl;
	    cout<<"\tBalance :"<<amount<<endl;
	}
	file.read((char*)&obj,sizeof(obj));
    }
    file.close();
    getch();
}

void account::edit()
{
    float user;
    cout<<"\n\tEnter Account Number :";
    cin>>user;

    file.open("database.txt",ios::in||ios::out);

    file.read((char*)&obj,sizeof(obj));

    while (file.eof()==0)
    {
	if(obj.acc==user)
	{
	    cout<<"\t Holder Name : "<<name<<endl;
	    cout<<"\t Type of Account :" <<type<<endl;
	    cout<<"\t Branch " <<branch<<endl;
	    cout<<"\t Account Number :" <<acc<<endl<<endl;
	    cout<<"\tBalance :"<<amount<<endl;

	    cout<<"\nEnter New Name :";
	    cin>>name;

	    file.seekp(file.tellg()-sizeof(obj));
	    file.write((char*)&obj,sizeof(obj));
	    cout<<"\n\n File Updated" ;
	    break;
	}

	file.read((char*)&obj,sizeof(obj));
    }
    file.close();

    getch();
}

void main()
{
    int option;

    while (1)
    {
	cout<<"\n==================================";
	cout<<"\n\t\t\tBank Management system";
	cout<<"\n=================================";
	cout<<"\n\n\t1] New Account\n";
	cout<<"\n\t2] Show all account\n";
	cout<<"\n\t3] Search all account \n";
	cout<<"\n\t4] Modify Account\n";
	cout<<"\n\t5] Exit \n";
	cout<<"\n\n\t Enter Option :";
	cin>>option;

	switch (option)
	{
	case 1:
	cout<<"\n\t===========New Account========= ";
	obj.add();
	cout<<"\n\n\t Recored enterd\n";
	getch();
	break;
	case 2:
	cout<<"\n\t===========All Account========= ";
	obj.show_all();
	getch();
	break;
	case 3:
	cout<<"\n\t===========New Account========= ";
	obj.search();
	getch();
	break;
	case 4:
	cout<<"\n\t===========New Account========= ";
	obj.edit();
	getch();
	break;
	case 5:
	exit(0);
	break;
	default:
	cout<<"\n\tINvalid keuy option";
	}
    }
    getch();
}