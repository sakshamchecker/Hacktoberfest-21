#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<fstream>
#include<time.h>
#include<math.h>
#include<iomanip.h>
#include<dos.h>
struct phonebook
{
	char name[50];
	char number[15];
	void modify();
}s[500],r;
void phonebook::modify()
{
	cout<<"NAME:"<<name<<endl;
	cout<<"Phone Number:"<<number<<endl;
	cout<<"Enter New Details"<<endl;
	char nm[50]="";
	char num[15]="";
	cout<<"Enter New Name(Enter * To Retain Old One):"<<endl;
	gets(nm);
	cout<<"Enter New Number(Enter * To Retain Old One):"<<endl;
	gets(num);
	if(strcmp(nm,"*")!=0)
	strcpy(name,nm);
	if(strcmp(num,"*")!=0)
	strcpy(number,num);
}


char appMen()
{	clrscr();
	char n;
	cout<<"********Applications*******"<<endl<<endl;
	cout<<"1.  Temperature Converter"<<endl;
	cout<<"2.  Length Converter"<<endl;
	cout<<"3.  Currency Exchange"<<endl;
	cout<<"4.  Calculator"<<endl;
	cout<<"5.  Exit"<<endl;
	cout<<"Enter Your Choice"<<endl;
	cin>>n;
	return n;

}

char gamMenu()
{	clrscr();
	char n;
	cout<<"********Games********"<<endl<<endl;
	cout<<"1.  Science Quiz"<<endl;
	cout<<"2.  Hangman"<<endl;
	cout<<"3.  Exit"<<endl;
	cout<<"Enter Your Choice"<<endl;
	cin>>n;
	return n;
}
struct callDat
{public:
	char num[15];char time[26];
	void putdata()
	{ cout<<num<<'\t'<<time;}
 }cal,retrv;



void box_fill(void)
{
	textcolor(GREEN);
	int xr,xc;
	int la,ra;
	gotoxy(10,2);
		for(xr=1;xr<=51;xr++)
		cprintf("±");
		xc=3;
		for(la=1;la<=19;la++)
{
		textcolor(BLUE);
		gotoxy(10,xc);
		cprintf("±");
		gotoxy(60,xc);
		cprintf("±");
		xc++;
}
		textcolor(GREEN);
		gotoxy(10,22);
		for(xr=1;xr<=51;xr++)
		cprintf("±");
}
char menu()
{       char n;
clrscr();
	box_fill();
	textattr(2 + ((1) << 2));
	gotoxy(24,3);cprintf("    Phone Menu");
	gotoxy(24,4);cprintf("___________________");
	gotoxy(24,5);cprintf("\n1.Call");
	gotoxy(24,7);cprintf("\n2.Phone Book   ");
	gotoxy(24,9);cprintf("\n3.Message   ");

	gotoxy(24,11);cprintf("\n4.Call Log     ");
	gotoxy(24,13);cprintf("\n5.Application ");
	gotoxy(24,15);cprintf("\n6.Games ");
	gotoxy(24,17);cprintf("\n7.Exit");
	gotoxy(24,21);cprintf("Enter Your Choice");
	cin>>n;
	return n;
}

char pbMenu()
{
	char n;
	clrscr();
	cout<<"********Phonebook Menu********"<<endl<<endl;
	cout<<"1.   Add Contact"<<endl;
	cout<<"2.   Search Contacts"<<endl;
	cout<<"3.   Edit Contacts"<<endl;
	cout<<"4.   Delete Contact"<<endl;
	cout<<"5    View   Contacts"<<endl;
	cout<<"6.   Delete All Contacts"<<endl;
	cout<<"7.   Exit"<<endl;
	cout<<"Enter Your Choice"<<endl;
	cin>>n;
	return n;
}

char LogMen()
{       clrscr();
	char n;
	cout<<"********Call Log********"<<endl<<endl;
	cout<<"1.  View Log"<<endl;
	cout<<"2.  Clear Log"<<endl;
	cout<<"3.  Exit"<<endl;
	cout<<"Enter Your Choice"<<endl;
	cin>>n;
	return n;
}
struct sms{
		char msg[160],p_num[15];
	}s1[20],s2;


void send();
void send()
{
	cout<<"sending......"<<endl;
	cout<<"No Connection available"<<endl;
}
char messageMenu(){
		clrscr();
		char n;
		cout<<"******************Message Menu******************"<<endl;
		cout<<"1.	Outbox."<<endl;
		cout<<"2.	Clear Outbox"<<endl;
		cout<<"3.	Type SMS"<<endl;
		cout<<"4.	Exit"<<endl;
		cout<<"Enter Your Choice:";
		cin>>n;
		return n;
		}


void show_sms()
{
	char hold[50],found='n',a='y';
	int i=0;
	while(a=='Y'||a=='y')
	{
		ifstream fi;
		fi.open("C:\sms.dat",ios::in|ios::binary);
		cout<<"Enter Phone Number to read the sms:";
		gets(hold);
		while(!fi.eof())
		{
			fi.read((char*) &s1[i], sizeof(sms));
			if(strcmp(hold,s1[i].p_num)==0)
			{
				cout<<(i+1)<<"-::"<<s1[i].msg<<"::-"<<endl;
				found='y';

			}
			i++;
		}
		if(found=='n')
		cout<<"Name Not Found:"<<endl;
		fi.close();
		cout<<"Do You Want To search again (y/n)?";
		cin>>a;
	}
}


void outbox(){
		char l;
		ifstream fin;
		fin.open("C:\sms.dat",ios::in|ios::binary|ios::beg);
		fin.seekg(0,ios::end);
		int n=fin.tellg();
		fin.seekg(0,ios::beg);
		while(fin.tellg()!=n)
	{
		fin.read((char*) &s2, sizeof(sms));
		cout<<"Phone Number:"<<s2.p_num<<endl;
	}
	show_sms();
		fin.close();
}
void type(){
		char l='y';
		int i=0;
		ofstream fout;
		fout.open("C:\sms.dat",ios::out|ios::binary|ios::app);
		while(l=='y'||l=='Y')
			{
			clrscr();
			cout<<"Enter The SMS(max 160 characters):"<<endl;
			gets(s1[i].msg);
			cout<<"Enter Number:"<<endl;
			gets(s1[i].p_num);
			fout.write((char*)&s1[i],sizeof(sms));
			send();
			cout<<"Do You Want To Type More SMS(y/n):"<<endl;
			cin>>l;
			i++;
			}
		fout.close();
	}
void type(char phno[15]){
		char l='y';
		int i=0;
		ofstream fout;
		fout.open("C:\sms.dat",ios::out|ios::binary|ios::app);
		while(l=='y'||l=='Y')
			{
			clrscr();
			cout<<"Enter The SMS(max 160 characters):"<<endl;
			gets(s1[i].msg);
			strcpy(s1[i].p_num,phno);
			fout.write((char*)&s1[i],sizeof(sms));
			send();
			cout<<"Do You Want To Type More SMS(y/n):"<<endl;
			cin>>l;
			i++;
			}
		fout.close();
	}


void writeLog(char phno[ ])
{
	int i;
	time_t t;
	time(&t);
	ofstream fout;
	strcpy(cal.num,phno);
	for(i=0;i<26;i++)
	cal.time[i]=*(ctime(& t)+(i*sizeof(char)));
	fout.open("C:\log.dat",ios::app|ios::binary);
	fout.write((char*)&cal,sizeof(cal));
    fout.close();
}

void call(char phn[ ])
{
	writeLog(phn);
	cout<<"Dialling......"<<phn<<endl;
	cout<<"No Connection available"<<endl;
	cout<<"\nPress any key to continue..."<<endl;
	getch();
}

void viewLog()
{
	long m;
	long n=sizeof(callDat);
	ifstream fin;
	fin.open("C:\log.dat",ios::in|ios::binary);
	fin.seekg(0,ios::beg);
	m=fin.tellg();
	fin.seekg(-n,ios::end);
	while(fin.tellg()!=m)
	{

		fin.read((char*)&retrv,sizeof(retrv));
		retrv.putdata();
		fin.seekg(-(2*n),ios::cur);
	}
    fin.read((char*)&retrv,sizeof(retrv));
	retrv.putdata();
	fin.close();
	cout<<"\nPress any key to continue..."<<endl;
	getch();
}
void sendMessage(){}
void add()
{
	ofstream fout;
	fout.open("C:\phbook.dat",ios::out|ios::binary|ios::app);
	char l='y';
	int i=0;
	while(l=='y'||l=='Y')
	{
		cout<<"Enter Name:";
		gets(s[i].name);
		cout<<"Enter Phone Number:";
		gets(s[i].number);
		fout.write((char*)&s[i],sizeof(phonebook));
		cout<<"Do You Want To Enter More Records(y/n)";
		cin>>l;
		i++;
	}
	fout.close();
}

void viewContacts()
{
	ifstream fin("C:\phbook.dat",ios::in|ios::beg);
	fin.seekg(0,ios::end);
	int n=fin.tellg();
	fin.seekg(0,ios::beg);

	while(fin.tellg()!=n)
	{
		fin.read((char*) &r, sizeof(phonebook));
		cout<<"NAME:"<<r.name<<endl;
		cout<<"Phone Number:"<<r.number<<endl;
	}
	cout<<"\nPress any key to continue..."<<endl;
	getch();
	fin.close();
}

void search()
{
	char hold[50],found='n',a='y',d='n',e='n';
	int i=0;
	while(a=='Y'||a=='y')
	{
		ifstream fi;
		fi.open("C:\phbook.dat",ios::in|ios::binary);
		cout<<"Enter Name:";
		gets(hold);
		while(!fi.eof())
		{
			fi.read((char*) &s[i], sizeof(phonebook));
			if(strcmp(hold,s[i].name)==0)
			{
				cout<<s[i].name<<":"<<s[i].number<<endl;
				cout<<"Do you want to call "<<s[i].name<<"(y/n)"<<endl;
				cin>>d;
                                if(d=='y'||d=='Y')
					call(s[i].number);
				cout<<"Send Message to "<<s[i].name<<"\?(y/n)"<<endl;
				cin>>e;

				if(e=='y'||e=='Y')
					type(s[i].number);
				found='y';
				break;
			}
			i++;
		}
		if(found=='n')
		cout<<"Name Not Found:"<<endl;
		fi.close();
		cout<<"Do You Want To search again (y/n)?";
		cin>>a;
	}
}

void del_cont()
{
	ifstream fio("C:\phbook.dat",ios::in|ios::binary);
	ofstream file("temp.dat",ios::out);
	fio.seekg(0,ios::end);
	int n=fio.tellg();
	fio.seekg(0,ios::beg);
	char hold[50],found='f',confirm='n',l='y';
	int i=0;
	while(l=='y'||l=='Y')
	{
		cout<<"Enter The Name to me Deleted:";
		gets(hold);
		while(fio.tellg()!=n)
		{	fio.read((char*) &s[i],sizeof(phonebook));
			if(strcmp(hold,s[i].name)==0)
			{	cout<<s[i].name<<":"<<s[i].number<<endl;
				found='t';
				cout<<"Are You Sure You Want To Delete This Record(y/n):";
				cin>>confirm;
				if(confirm=='n')
				file.write((char*)&s[i],sizeof(phonebook));
			}
			else
			file.write((char*)&s[i],sizeof(phonebook));
		}
		if(found=='f')
		cout<<"Record Not Found:"<<endl;
		file.close();
		fio.close();
		remove("C:\phbook.dat");
		rename("temp.dat","C:\phbook.dat");
		cout<<"Contact Deleted.";
		cout<<"Do You Want To Delete More Records(y/n):"<<endl;
		cin>>l;
	}
}

void edit()
{
	ofstream fou("C:\phbook.dat",ios::in|ios::binary);
	ifstream fio("C:\phbook.dat",ios::in|ios::binary);
	fio.seekg(0,ios::end);
	int n=fio.tellg();
	int pos;
	fio.seekg(0,ios::beg);
	char hold[50],found='f',l='y';
	int i=0;
	while(l=='y'||l=='Y')
	{
		cout<<"Enter The name of contact To Be Edited:";
		gets(hold);
		while(fio.tellg()!=n)
		{	pos=fio.tellg();
			fio.read((char*) &s[i],sizeof(phonebook));
			fou.seekp(pos);
			if(strcmp(hold,s[i].name)==0)
			{
				found='t';
				s[i].modify();
				fou.write((char*)&s[i],sizeof(phonebook));
			}
			i++;
		}
		if(found=='f')
			cout<<"Contact not available"<<endl;
		cout<<"Do you want to modify more contacts(y/n)"<<endl;
		cin>>l;

	}
	fou.close();fio.close();
}


void cel2far()
{       char a='y';
	do{	clrscr();
		float c_temp;
		float f_temp;
		cout << "What is the Celsius temperature to convert ? ";
		cin >> c_temp;
		f_temp = c_temp * (9.0 / 5.0) + 32.0;
		cout << "The Fahrenheit equivalent is:"<<setprecision(2)<<f_temp <<"\n";

		cout<<"Do You Want To Continue(y/n)?";
		cin>>a;
		}while(a=='y'||a=='Y');
}


void inch2feet()
{        char a;
	do{	float feet,inc;
		cout << "Enter length in inch : "<<endl;
		cin >> inc;
		feet=inc/12;
		cout << "The length in feet is-: " <<feet<<endl;
		cout<<"Do You Want To Continue(y/n)?"<<endl;
		cin>>a;
	}while(a=='y'||a=='Y') ;
}


void currency()
{
	clrscr();
	int i;
	char a='y';
	double rate,amount;
	cout<<"Enter conversion rate from Other to Re:";
	cin>>rate;
	do{
		cout<<"Do You Want To convert-"<<endl;
		cout<<"1.Others To Rupees."<<endl;
		cout<<"2.Rupees To Other Currency."<<endl;
		cout<<"Enter Your Choice:";
		cin>>i;
		if(i==2)
		{	clrscr();
			cout<<"Enter Amount in Rupees:"<<endl;
			cin>>amount;
			cout<<"Amount in Other Currency="<<(rate/amount);
		}
		else if(i==1)
		{	clrscr();
			cout<<"Enter Amount in Foreign Currency:"<<endl;
			cin>>amount;
			cout<<"Amount In Rupees is Rs."<<(amount*rate)<<endl;
		}
		else
		cout<<"Wrong Choice Inserted!!!!"<<endl;
		cout<<"Do You Want To Continue(y/n)?"<<endl;
		cin>>a;
	    }while(a=='Y'||a=='y');
 }

char a;
int b,i,sc,d,c,p;
void  u(void)
{

	gotoxy(6,3);
	cout<<"------------------------------------------------";
	gotoxy(10,8);
	cout<<"  WELCOME  TO  SCIENCE  QUIZ";
	gotoxy(6,20);
	cout<<"------------------------------------------------";
	getch();
}

void y(void)
{

clrscr();
	 gotoxy(15,11);
	 cout<<"INSTRUCTION  FOR  USER :- ";
	 gotoxy(15,14);
	 cout<<"YOU HAVE GIVEN FOUR OPTIONS";
	 gotoxy(15,16);
	 cout<<"OUT OF WHICH YOU HAVE ";
	 gotoxy(15,18);
	 cout<<"TO CHOSE ANY ONE AS YOUR ANSWER";
	 getch();
}

void q()
{
	int row;
	row=3;
	clrscr();
	for(i=5;i<=60;i++)
	{
	gotoxy(i,row);
	cout<<"*";
	}
	row=23;
	for(i=5;i<=60;i++)
	{
	gotoxy(i,row);
	cout<<"*";
	}

}

void question1()
{

  sc=0;
  gotoxy(10,5);
  cout<<" Q1 :  THE ELEMENT WITH LOWEST ";
  gotoxy(16,6);
  cout<<"        MELTING AND BOILING POINT";
  gotoxy(10,7);
  cout<<" A : CU";
	gotoxy(10,8);
  cout<<" B : FE";
	gotoxy(10,9);
  cout<<" C : NI";
	gotoxy(10,10);
  cout<<" D : ZN";
  gotoxy(10,12);
  cout<<" ENTER  CHOICE => ";
  cin>>a;

  if (a=='d')
  {
  gotoxy(10,14);
  cout<<" YOU  ARE  CORRECT";
  sc=sc+1;
  }
  else
  gotoxy(10,14);
  cout<<" YOU ARE WRONG ";
	gotoxy(10,16);
	cout<<"YOUR  SCORE IS ";
	cout<<sc;
	getch();
}

void question2()
{

  gotoxy(10,5);
  cout<<" Q2 :  THE STUDY OF BIRD ";
  gotoxy(10,7);
  cout<<" A : ZOOLOGY ";
	gotoxy(10,8);
  cout<<" B : ASTROLOGY";
	gotoxy(10,9);
  cout<<" C : ORNTHOLOGY";
	gotoxy(10,10);
  cout<<" D : MICROLOGY";
  gotoxy(10,12);
  cout<<" ENTER  CHOICE => ";
  cin>>a;

  if (a=='c')
  {
  gotoxy(10,14);
  cout<<" YOU  ARE  CORRECT";
  sc=sc+1;
  }
  else
  {
  gotoxy(10,14);
  cout<<" YOU ARE WRONG ";
  }
	gotoxy(10,16);
	cout<<"YOUR  SCORE IS ";
	cout<<sc;
	getch();
}
void question3()
{

  gotoxy(10,5);
  cout<<" Q3 :  THE UNIT OF CAPACITANCE IS ";
  gotoxy(10,7);
  cout<<" A : NEWTON";
	gotoxy(10,8);
  cout<<" B : WATT";
	gotoxy(10,9);
  cout<<" C : OHM";
	gotoxy(10,10);
  cout<<" D : FARAD";
  gotoxy(10,12);
  cout<<" ENTER  CHOICE => ";
  cin>>a;

  if (a=='d')
  {
  gotoxy(10,14);
  cout<<" YOU  ARE  CORRECT";
  sc=sc+1;
  }
  else
  {
  gotoxy(10,14);
  cout<<" YOU ARE WRONG ";
  }
	gotoxy(10,16);
	cout<<"YOUR  SCORE IS ";
	cout<<sc;
	getch();
}
void question4()
{

  gotoxy(10,5);
  cout<<" Q4 :  WHO IS THE FATHER ";
  gotoxy(16,6);
  cout<<"        OF COMPUTER";
  gotoxy(10,7);
  cout<<" A : CHARLES BABBAGE";
	gotoxy(10,8);
  cout<<" B : BLAISE PASCAL";
	gotoxy(10,9);
  cout<<" C : NEWTON";
	gotoxy(10,10);
  cout<<" D : FRENKLIN";
  gotoxy(10,12);
  cout<<" ENTER  CHOICE => ";
  cin>>a;

  if (a=='a')
  {
  gotoxy(10,14);
  cout<<" YOU  ARE  CORRECT";
  sc=sc+1;
  }
  else
  {
  gotoxy(10,14);
  cout<<" YOU ARE WRONG ";
  }
	gotoxy(10,16);
	cout<<"YOUR  SCORE IS ";
	cout<<sc;
	getch();
}
void question5()
{

  gotoxy(10,5);
  cout<<" Q5 :  WHICH INSTRUMENT IS USED";
  gotoxy(16,6);
  cout<<"        TO MESURE EARTHQUAKE";
  gotoxy(10,7);
  cout<<" A : BAROMETER";
	gotoxy(10,8);
  cout<<" B : ANOMETER";
	gotoxy(10,9);
  cout<<" C : RICHTER SCALE";
	gotoxy(10,10);
  cout<<" D : GALVONOMETER";
  gotoxy(10,12);
  cout<<" ENTER  CHOICE => ";
  cin>>a;

  if (a=='c')
  {
  gotoxy(10,14);
  cout<<" YOU  ARE  CORRECT";
  sc=sc+1;
  }
  else
  {
  gotoxy(10,14);
  cout<<" YOU ARE WRONG ";
  }
	gotoxy(10,16);
	cout<<"YOUR  SCORE IS ";
	cout<<sc;
	getch();
}
void question6()
{

  gotoxy(10,5);
  cout<<" Q6 :  WHO INVENTED BULB ";
  gotoxy(10,7);
  cout<<" A : MARCONI";
	gotoxy(10,8);
  cout<<" B : RUTHERFORD";	gotoxy(10,9);
	 cout<<" C : EDISON";
	gotoxy(10,10);
  cout<<" D : HOKKINS";
  gotoxy(10,12);
  cout<<" ENTER  CHOICE => ";
  cin>>a;

  if (a=='c')
  {
  gotoxy(10,14);
  cout<<" YOU  ARE  CORRECT";
  sc=sc+1;
  }
  else
  {
  gotoxy(10,14);
  cout<<" YOU ARE WRONG ";
  }
	gotoxy(10,16);
	cout<<"YOUR  SCORE IS ";
	cout<<sc;
	getch();
}
void question7()
{

  gotoxy(10,5);
  cout<<" Q7 :  HEART IS DIVIDED INTO ";
  gotoxy(10,7);
  cout<<" A : ONE PART ";
	gotoxy(10,8);
  cout<<" B : TWO PART";
	gotoxy(10,9);
  cout<<" C : THREE PART";
	gotoxy(10,10);
  cout<<" D : FOUR PART";
  gotoxy(10,12);
  cout<<" ENTER  CHOICE => ";
  cin>>a;

  if (a=='d')
  {
  gotoxy(10,14);
  cout<<" YOU  ARE  CORRECT";
  sc=sc+1;
  }
  else
  {
  gotoxy(10,14);
  cout<<" YOU ARE WRONG ";
  }
	gotoxy(10,16);
	cout<<"YOUR  SCORE IS ";
	cout<<sc;
	getch();
}
void question8()
{

  gotoxy(10,5);
  cout<<" Q8 :  ATOM BOMB IS BASED ";
  gotoxy(16,6);
  cout<<"        ON THE PRINCIPLE OF";
  gotoxy(10,7);
  cout<<" A : NUCLEAR FISSION";
	gotoxy(10,8);
  cout<<" B : NUCLEAR FUSION";
	gotoxy(10,9);
  cout<<" C : NEWTON THIRD LAW";
	gotoxy(10,10);
  cout<<" D : NONE OF THE ABOVE";
  gotoxy(10,12);
  cout<<" ENTER  CHOICE => ";
  cin>>a;

  if (a=='a')
  {
	 gotoxy(10,14);
  cout<<" YOU  ARE  CORRECT";
  sc=sc+1;
  }
  else
  {
	 gotoxy(10,14);
  cout<<" YOU ARE WRONG ";
  }
	gotoxy(10,16);
	cout<<"YOUR  SCORE IS ";
	cout<<sc;
	getch();
}
void question9()
{

  gotoxy(10,5);
  cout<<" Q9 :  DISTANCE OF OZONE LAYER ";
  gotoxy(16,6);
  cout<<"       FROM EARTH";
  gotoxy(10,7);
  cout<<" A : 13 KM";
	gotoxy(10,8);
  cout<<" B : 14 KM";
	gotoxy(10,9);
  cout<<" C : 17 KM";
	gotoxy(10,10);
  cout<<" D : 16 KM";
  gotoxy(10,12);
  cout<<" ENTER  CHOICE => ";
  cin>>a;

  if (a=='d')
  {
	 gotoxy(10,14);
  cout<<" YOU  ARE  CORRECT";
  sc=sc+1;
  }
  else
  {
	 gotoxy(10,14);
  cout<<" YOU ARE WRONG ";
  }
	gotoxy(10,16);
	cout<<"YOUR  SCORE IS ";
	cout<<sc;
	getch();
}
void question10()
{

  gotoxy(10,5);
  cout<<" Q10 :  THE ATOMIC NUMBER ";
  gotoxy(16,6);
  cout<<"        OF GLUCOSE IS";
  gotoxy(10,7);
  cout<<" A : 180";
	gotoxy(10,8);
  cout<<" B : 80";
	gotoxy(10,9);
  cout<<" C : 120";
	gotoxy(10,10);
  cout<<" D : 160";
  gotoxy(10,12);
  cout<<" ENTER  CHOICE => ";
  cin>>a;

  if (a=='a')
  {
	 gotoxy(10,14);
  cout<<" YOU  ARE  CORRECT";
  sc=sc+1;
  }
  else
  {
	 gotoxy(10,14);
  cout<<" YOU ARE WRONG ";
  }
	gotoxy(10,16);
	cout<<"YOUR  SCORE IS ";
	cout<<sc;
	getch();
}
void question11()
{

  gotoxy(10,5);
  cout<<" Q11 :  DIELECTRIC CONSTANT OF WATER";
  gotoxy(10,7);
  cout<<" A : 82";
	gotoxy(10,8);
  cout<<" B : 81";
	gotoxy(10,9);
  cout<<" C : 80";
	gotoxy(10,10);
  cout<<" D : 85";
  gotoxy(10,12);
  cout<<" ENTER  CHOICE => ";
  cin>>a;

  if (a=='b')
  {
	 gotoxy(10,14);
  cout<<" YOU  ARE  CORRECT";
  sc=sc+1;
  }
  else
  {
	 gotoxy(10,14);
  cout<<" YOU ARE WRONG ";
  }
	gotoxy(10,16);
	cout<<"YOUR  SCORE IS ";
	cout<<sc;
	getch();
}
void question12()
{

  gotoxy(10,5);
  cout<<" Q12 :  LACK OF VITAMIN D ";
  gotoxy(10,7);
  cout<<" A : ANAEMIA";
	gotoxy(10,8);
  cout<<" B : RICKETS";
	gotoxy(10,9);
  cout<<" C : SCURVEY";
	gotoxy(10,10);
  cout<<" D : GOITER";
  gotoxy(10,12);
  cout<<" ENTER  CHOICE => ";
  cin>>a;

  if (a=='b')
  {
	 gotoxy(10,14);
  cout<<" YOU  ARE  CORRECT";
  sc=sc+1;
  }
  else
  {
	 gotoxy(10,14);
  cout<<" YOU ARE WRONG ";
  }
	gotoxy(10,16);
	cout<<"YOUR  SCORE IS ";
	cout<<sc;
	getch();
}
void question13()
{

  gotoxy(10,5);
  cout<<" Q14 :  WHICH BLOOD COMPONENT";
  gotoxy(16,6);
  cout<<"        PREVENT DISEASE";
  gotoxy(10,7);
  cout<<" A : RBC";
	gotoxy(10,8);
  cout<<" B : WBC";
	gotoxy(10,9);
  cout<<" C : PLASMA";
	gotoxy(10,10);
  cout<<" D : PLATELETS";
  gotoxy(10,12);
  cout<<" ENTER  CHOICE => ";
  cin>>a;

  if (a=='b')
  {
	 gotoxy(10,14);
  cout<<" YOU  ARE  CORRECT";
  sc=sc+1;
  }
  else
  {
	 gotoxy(10,14);
  cout<<" YOU ARE WRONG ";
  }
	gotoxy(10,16);
	cout<<"YOUR  SCORE IS ";
	cout<<sc;
	getch();
}
void question14()
{

  gotoxy(10,5);
  cout<<" Q14 :  HALEY COMET COMES AFTER ";
  gotoxy(16,6);
  cout<<"        EVERY";
  gotoxy(10,7);
  cout<<" A : 86";
	gotoxy(10,8);
  cout<<" B : 60";
	gotoxy(10,9);
  cout<<" C : 90";
	gotoxy(10,10);
  cout<<" D : 10";
  gotoxy(10,12);
  cout<<" ENTER  CHOICE => ";
  cin>>a;

  if (a=='a')
  {
	 gotoxy(10,14);
  cout<<" YOU  ARE  CORRECT";
  sc=sc+1;
  }
  else
  {
	 gotoxy(10,14);
  cout<<" YOU ARE WRONG ";
  }
	gotoxy(10,16);
	cout<<"YOUR  SCORE IS ";
	cout<<sc;
	getch();
}
void question15()
{

  gotoxy(10,5);
  cout<<" Q15 :  WHICH PHOSPHORUS ";
  gotoxy(16,6);
  cout<<"        IS POISONOUS";
  gotoxy(10,7);
  cout<<" A : RED";
	gotoxy(10,8);
  cout<<" B : WHITE";
	gotoxy(10,9);
  cout<<" C : YELLOW";
	gotoxy(10,10);
  cout<<" D : NONE OF THE ABOVE";
  gotoxy(10,12);
  cout<<" ENTER  CHOICE => ";
  cin>>a;

  if (a=='c')
  {
	 gotoxy(10,14);
  cout<<" YOU  ARE  CORRECT";
  sc=sc+1;
  }
  else
  {
	 gotoxy(10,14);
  cout<<" YOU ARE WRONG ";
  }
	gotoxy(10,16);
	cout<<"YOUR  SCORE IS ";
	cout<<sc;
	getch();
}

void quiz()
{
	a='y';
	do
	{
	 clrscr();
	u();y();q();
	question1();q();question2();q();question3();q();
	question4();q();question5();q();question6();q();
	question7();q();question8();q();question9();q();;
	question10();q();question11();q();question12();q();
	question13();q();question14();q();question15();q();
	clrscr();
	gotoxy(10,10);
	cout<<"your final sum is => "<<sc;
	if(sc<10)
	{
	gotoxy(10,14);
	cout<<"you are weak in science";
	}
	else
	{
	gotoxy(10,14);
	cout<<"well done keep it up";
	}
	gotoxy(10,18);
	cout<<"do you want to continue";
	cin>>a;
	}while(a=='y');
	gotoxy(10,20);
	cout<<"job is over";

}

void calculator();
void calculator(){
char l='y',d;
int a,j,n;
const int max=100;
float z,v,e[max],q[max];
long mul=1,sum=0;
while(l=='y'||l=='Y')
{	clrscr();
	cout<<"Calculator Menu:"<<endl;
	cout<<"1.Add."<<endl;
	cout<<"2.Subtract."<<endl;
	cout<<"3.Multiply."<<endl;
	cout<<"4.Divide:"<<endl;
	cout<<"Enter the choice:"<<endl;
	cin>>a;
	if (a==1)
	{	clrscr();
		cout<<"Enter The Number Of Numbers To Add(max 100):"<<endl;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<"Enter the "<<(i+1)<<" number:"<<endl;
			cin>>e[i];
		}
		for(i=0;i<n;i++)
		{	sum=sum+e[i];
			cout<<"Total= "<<sum<<endl;
		}
	}
	else if(a==2)
	{
		clrscr();
		cout<<"Enter Two Numbers:"<<endl;
		cin>>z>>v;
		cout<<"Total="<<z-v;
	}

	else if(a==3)
	{
		clrscr();
		cout<<"Enter Number of Numbers to multiply(max 100):"<<endl;
		cin>>n;
		for(int i=0;i<n;i++)
		{	cout<<"Enter The "<<(i+1)<<" Number:"<<endl;
			cin>>q[i];
		}
		for(i=0;i<n;i++)
		{	mul=mul*q[i];
			cout<<"Total= "<<mul;
		}
	}
	else if(a==4)
	{
		clrscr();
		cout<<"Enter Two Number(a/b):"<<endl;
		cin>>z>>v;
		cout<<"Total="<<z/v;
	}
	else
	cout<<"Error!!!!!!!!";
cout<<"Do you want to continue?(Y/N)"<<endl;
cin>>l;
}}




static void playGame() ;
static void printMistakes(int n) ;
static int const MAXGUESS =8 ;
static char String[][15] = { "apple","banana","cat","dog","elephant","fish","giraffe",
			     "hippopotamus","ice cream","jelly","kangaroo","lion","monkey",
			     "noodles","octopus","parrot","queen","rabbit","sun","tree",
			     "umbrella","van","window","x-ray","yellow","zebra"
			   } ;
enum boolean {false, true} ;
void hangman()
{  boolean again ;
char answer ;
clrscr() ;
cout<<"\n\n\tThis is the word guessing game called Hangman." ;
cout<<"\n\tThe computer will pick a word and you must try to guess" ;
cout<<"\n\tthe word with less than "<<MAXGUESS<<" mistakes ,Then you win!" ;
do
{       playGame() ;
	cout<<"\n\nWould you like to play another game?(Y or N)" ;
	cin>>answer ;
	if(answer == 'y'||answer == 'Y')
	   again = true ;
	else if (answer == 'n'||answer=='N')
	   again = false;
	else
	{
	   again=false;
	   cout<<"\nYour answer"<<answer<<"\"should be Y or N." ;
	}
}while (again) ;
cout<<"\nThank you for playing Hangman!"<<endl ;
 cout<<"\nPress any key to continue..."<<endl;
 getch();
}
static void playGame()
{
       boolean*already;
       char c;
       boolean*display ;
       int found;
       int i;
       char inputChar ;
       char inputString[15];
       int length ;
       int letters;
       int mistakes,guesses ;
       boolean playing ;
       char word[15] ;
       mistakes = 0 ;
       guesses = 0 ;
       randomize() ;
      strcpy(word,String[(int)(rand()%26)]) ;
       length = strlen(word) ;

	 display = new boolean[length] ;
	 letters = 0 ;
	 for(i=0 ; i<length ; i++)
	 {      c = word[i] ;
	 if ((c>='a')&&(c<='z'))
	 {
	 display[i] = false ;
	 letters++ ;
	 }
	 else
	     display[i] = true ;
}
cout<<"\n\nI am thinking of a word .";


     cout<<"The word has "<<letters<<" letters "<<endl ;
     already = new boolean[26];

     for( i = 0 ; i<26 ; i++)
	already[i] = false ;
	playing = true ;
	while (playing)
	{                cout<<"\nThe word is: ";
			 for(i = 0;i<length ;i++)
			 {cout<<"" ;
			 if (display[i])
			    cout<<word[i] ;
			 else
			    cout<<"*" ;
			 }

			 cout<<"\nWhat is your guess?" ;
			 if((MAXGUESS - guesses )<=1)
			     cout<<"This is your last guess"<<endl ;
			 else
			     cout<<"you have "<<(MAXGUESS - guesses) <<" guesses remaining."<<endl ;
			     gets(inputString) ;
			     strlwr(inputString) ;
			     if (strlen(inputString) == length)
			     {    if(strcmp(inputString,word) == 0)
				  {  cout<<"Yes,the word is \""<<word<<" \"!" ;
				  printMistakes(mistakes) ;
				  playing = false ;
			     }
			     else
			     {    cout<<"Sorry, the word is not \""<<inputString<<"\"." ;
				  mistakes++ ;guesses++;
			     }
			 }
else if (strlen(inputString) != 1)
{  cout<<"Your Guess \""<<inputString<<"\" must be one letter or the entire word." ;
}
else
{


       inputChar = inputString[0] ;
       if ((inputChar<'a')||(inputChar >'z'))
       {     cout<<"Your guess \""<<inputChar
		 <<"\" must be a letter from A to Z, or the entire word."<<endl ;
       }
       else if (already[inputChar - 'a'])
       {
       cout<<"You have already guessed the folowing letters :"<<endl ;
       for( i =0;i<26 ;i++)
	  if (already[i])
	      cout<<""<<(char)(i + 'a') ;
	  cout<<"\n" ;
       }

       else
       {


       already[inputChar - 'a'] = true ;
       found = 0 ;
       for(i = 0 ; i < length ; i++)
	    if (word[i] == inputChar)
	    {    display[i] = true ;
	    found++  ;
	    }
       if(found <= 0)
       {   cout<<" Sorry,the letter  \""<<inputChar<<"\" is not in the word." ;
	       mistakes++;guesses++;
       }
       else
       {
	  if (found == 1)
	  cout<<"Yes , here is one letter \""<<inputChar<<"\" in the word ." ;
	  else
	     cout<<"Yes, there are "<<found<<" letters\""<<inputChar
	     <<"\" in the word." ;
             guesses++;
	     playing = false ;
		for(i = 0 ; i<length ; i++)
		    playing = playing || !display[i] ;
		if(!playing)
		{   cout<<"you found all the letters in the word\""<<word<<"\"." ;
			    printMistakes(mistakes) ;
		}
		}
	     }
	  }
	  if(guesses>=MAXGUESS)
	  {  cout<<"The word was \""<<word<<"\" ." ;
	     playing = false ;
	  }
       }
}

static void printMistakes(int n)
{  if(n <= 0)
      cout<<"You didn't make any mistakes. Excellent!" ;
   else if (n == 1)
      cout<<"You made only 1 mistake. Great!" ;
   else
      cout<<"You made only "<<n<<" mistakes.Good!" ;
}

void end()
{
int i,j,k;
char a[30]="THIS PROGRAM IS MADE BY :";
char b[25]=" SOURAV KUMAR BAIDYA     ";
char c[25]=" AND     ";
char f[30]=" ARUNAVA SAHA    ";
char g[30]="	 ";
char h[30]="	 ";
char d[30]="THANK ";
char e[30]=" YOU";
clrscr();
for(i=25;i>13;i--)
{
	textcolor(1+i);
	gotoxy(35,i);
	cprintf("%s",a);
	gotoxy(45,i+2);
	cprintf("%s",b);
	gotoxy(35,i+4);
	cprintf("%s",c);
	cprintf("%s",f);
	gotoxy(35,i+6);
	cprintf("%s",g);
	cprintf("%s",h);
	sleep(1);
	clrscr();
}
for(j=0;j<25;j++)
{
	clrscr();
	gotoxy(j,10);
	cprintf("%s",d);
	for(k=31;k>28;k--)
	gotoxy(k,10);
	cprintf("%s",e);
	delay(200);
}
sleep(0.5);
}

void main()
{
	char k,p;
	while(k!='7')
	{
		k=menu();
		if(k=='1')
		 {      char iphno[15 ];clrscr();
			cout<<("Enter phone number :");
			cin>>iphno;
			call(iphno);
		}
		if(k=='2')
		{       p='0';
			while(p!='7')
			{	p=pbMenu();
				if(p=='1'){
					clrscr();
					add();
					}
				if(p=='2'){
					clrscr();
					search();
					}
				if(p=='3'){
					clrscr();
					edit();
					}
				if(p=='4'){
					clrscr();
					del_cont();
					}
				if(p=='5'){
					clrscr();
					viewContacts();
					}
				if(p=='6')
				{       clrscr();
					char a='n';
					cout<<"Are You Sure That You Want To Delete All Records(y/n)?"<<endl;
					cin>>a;
					if(a=='y'||a=='Y'){
					ofstream fout;
					fout.open("C:\phbook.dat",ios::trunc);
					cout<<"Deleting Records..........."<<endl;
					cout<<"All Records Deleted!!!"<<endl;
					fout.close();
					cout<<"Press any key to continue..."<<endl;
					getch();
					}
				}


		}       }

			if(k=='3')
		{
		p='0';
		while(p!='4'){

				p=messageMenu();
				if(p=='1'){
					clrscr();
					outbox();
                                        cout<<"\nPress any key to continue..."<<endl;
					getch();
					}
				if(p=='2'){
					char confirm;
					cout<<"Do You Want To Clear Outbox(y/n)?";
					cin>>confirm;
					if(confirm=='y'||confirm=='Y')
						{
						cout<<"Clearing Outbox...";
						ofstream fout;
						fout.open("C:\sms.dat",ios::trunc);
						fout.close();
                                                cout<<"\nPress any key to continue..."<<endl;
						getch();
					}	}
				if(p=='3'){
					clrscr();
					type();
                                        cout<<"\nPress any key to continue..."<<endl;
					getch();
					}
				}

		}

		if(k=='4')
		{       p=0;
			while(p!='3')
			{
				p=LogMen();
				if(p=='1')
					viewLog();
				if (p=='2')

				{      	char n;
					cout<<"Do You Want To Clear Call Register(y/n)?"<<endl;
					cin>>n;
					if(n=='y'||n=='Y')
					{
					ofstream fout;
					fout.open("C:\log.dat",ios::beg,ios::trunc);
					cout<<"Clearing Log..."<<endl;
					cout<<"Logs Deleted"<<endl;
					fout.close();
					cout<<"\nPress any key to continue..."<<endl;
					getch();
					}
				}

			}
		}
	if(k=='5')
		{   p='0';
		    while(p!='5'){
				p=appMen();
					if(p=='1'){
						clrscr();
						cel2far();
						cout<<"\nPress any key to continue..."<<endl;
						getch();
						}
					if(p=='2'){
						clrscr();
						inch2feet();
						cout<<"\nPress any key to continue..."<<endl;
						getch();
						}
					if(p=='3'){
						clrscr();
						currency();
						cout<<"\nPress any key to continue..."<<endl;
						getch();
						}
					if(p=='4'){
						clrscr();
						calculator();
						cout<<"\nPress any key to continue..."<<endl;
						getch();
						}
				    }




		}
	if(k=='6'){         p='0';
			  while(p!='3'){
			  p=gamMenu();
			  if(p=='1'){
				clrscr();
						quiz();
						getch();
						}
					if(p=='2'){hangman();

						}
				}
		}        }
end();
}


