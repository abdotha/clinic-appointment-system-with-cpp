#include <iostream>
#include <fstream>
#include<string>
#include <cctype>
using namespace std;
ifstream in;
ofstream out;
int arr[100][11];

class doctors
{
public:
	string nn;
	char z ;
	int q;
	int doctorchoose()
	{
		ifstream in;
		int chk = ch();
		if (chk == 0)
			return 0;
		else
		{
			string arrx[100];
			in.open("doctors.txt");
			string temp;
			int x = 0;
			while (getline(in, temp))
			{
				arrx[x] = temp;
				x++;
			}
			in.close();
		lll:	char k;
			for (int i = 0; i < x; i++)
			{
				k = i + 65;
				cout << k << " - " << arrx[i] << endl;
			}

			cout << " --> ";
			cin >> z;
			z = toupper(z);
			if (z >= 'A')
			{
				if (z <= k)
				{
					q = z - 65;
					nn = arrx[q] + ".txt";
					fun();
				}
				else
				{
					cout << "Error:invalid input\n";
					goto lll;
				}
			}
			else
			{
				cout << "Error:invalid input\n";
				goto lll;
			}
		}
	}
	int ch()
	{
		ifstream in;
		in.open("doctors.txt");
		if (!in)
		{
			cout << "\n Error : there is no doctors now ask the admin for more data\n";
			return 0;
		}
		else
			return 1;
		in.close();
	}
	void fun()
	{
		ifstream in;
		ofstream out;
		in.open(nn);
		if (!in)
		{
			in.close();
			out.open(nn, ios::app);
			for (int i = 0; i < 11; i++)
				arr[q][i] = 0;
			out.close();
		}
	}
};
class admin
{
private:
	string username = "Admin";
	string password = "project.cpp";
public:
	doctors d2;
	void editarr(int arr[], string dname)
	{
		in.open(dname);
		string temp;
		//using getline to store line data in variable..
		while (getline(in, temp))
		{
			//temp[0] to get the frist letter in the variable..
			int index = (temp[0] - 65);
			arr[index] = 1;
		}
		in.close();
	}
	int usname(string usname)
	{
		if (usname == username)
			return 1;
		else
			return 0;
	}
	int pass(string pass)
	{
		if (pass == password)
			return 1;
		else
			return 0;
	}

	int mainadmin()
	{
		ofstream out;
		string x;
	ladmin3:	system("cls");
		cout << "doctors Editor\n" << "--------------------------------\n";
		cout << "\n1 - Add doctor. \n";
		cout << "2 - view doctors. \n";
		cout << "3 - deleting an appointment.\n";
		cout << "4 - back to main page. \n";
		cout << " --> ";
		cin >> x;
		if (x == "1")
		{
			string newd;
			out.open("doctors.txt", ios::app);
			cout << "Enter the doctor name: ";
			getchar();
			getline(cin, newd);
			out << newd << "\n";
			cout << "Doctor: " << newd << " added  successfully \n";
			out.close();
			string q;
		ladmin:		cout << "do you want to continue (yes, no)" << endl;
			cout << " --> ";
			cin >> q;
			if (q == "yes")
				goto ladmin3;
			else if (q == "no")
				return 0;
			else
			{
				cout << "Error:invalid input\n";
				goto ladmin;
			}
		}
		else if (x == "2")
		{
			string arrx[100];
			in.open("doctors.txt");
			string temp;
			int x = 0;
			while (getline(in, temp))
			{
				arrx[x] = temp;
				x++;
			}
			for (int i = 0; i < x; i++)
			{
				cout << i + 1 << " - " << arrx[i] << endl;
			}
			string q;
		ladmin2: cout << "do you want to continue (yes, no)" << endl;
			cout << " --> ";
			cin >> q;
			if (q == "yes")
				goto ladmin3;
			else if (q == "no")
				return 0;
			else
			{
				cout << "Error:invalid input\n";
				goto ladmin2;
			}
		}
		else if (x == "4")
			return 1;
		else if (x == "3")
		{
			doctors d2;
			string qq;
			cout << "which doctor do you want\n";
			d2.doctorchoose();
			del(d2.q,d2.nn);
	ladmin4:		cout << "do you want to continue (yes, no)" << endl;
			cout << " --> ";
			cin >> qq;
			if (qq == "yes")
				goto ladmin3;
			else if (qq == "no")
				return 0;
			else
			{
				cout << "Error:invalid input\n";
				goto ladmin4;
			}
		}
		else
		{
			cout << "Error:invalid input\n";
			cout << "Enter any thing to back";
			getchar(); getchar();
			goto ladmin3;
		}
	}
	int del(int y, string nn)
	{
		
		ifstream in;
		ofstream out;
		string temparr[100];
		in.open(nn);
		int x = 0;
		string temp;
		while (getline(in, temp))
		{
			temparr[x] = temp;
				int k = temparr[x][0] - 65;
				if (k >= 0 & k <= 10)
				{
					if (k == 0)
					{
						cout << "(0" << k + 9 << ":" << k + 10 << ") : " << temparr[x] << endl;
						x++;
					}
					else
					{
						cout << "(" << k + 9 << ":" << k + 10 << ") : " << temparr[x] << endl;
						x++;
					}
				}
		}
		in.close();
		if (x == 0)
		{
			cout << "there is no appointments" << endl;
			return 0;
		}
		else
		{
			cout << "enter the appointment letter : ";
			char delet;
			cin >> delet;
			delet = toupper(delet);
			arr[y][delet-65] = 0;
			string tarr[100];
			int xx = 0;
			int tt=0;
			for (int i = 0; i < x; i++)
			{
				if (temparr[i][0] != delet)
				{
					tarr[xx] = temparr[i];
					xx++;
				}
				else
					 tt = 1;
			}
			if (tt == 0)
			{
				cout << "Error : this appointment isn't booked\n";
				return 0;
			}
			else
			{
				out.open(nn);
				for (int i = 0; i < x; i++)
					out << tarr[i] << endl;
				out.close();
				cout << "The appointment deleted successfully\n";
				editarr(arr[y], nn);
				return 0;
			}
		}
		
	}
	
};
void editarr(int arr[], string dname)
{
	ifstream in;
	in.open(dname);
	string temp;
	//using getline to store line data in variable..
	while (getline(in, temp))
	{
		//temp[0] to get the frist letter in the variable..
		int index = (temp[0] - 65);
		arr[index] = 1;
	}
	in.close();
}
int booking(int arr[], string dname)
{
	ifstream in;
	ofstream out;
	cout << "Booking section\n" << "--------------------------------\n" << endl;
loop3:string name;
	editarr(arr, dname);
	for (int i = 0; i < 10; i++)
	{
		char temp = i + 65;
		if (arr[i] == 1)
		{
			if (i == 0)
				cout << temp << " - (0" << (i + 9) << ":" << (i + 10) << ")  --> " << "(booked)" << endl;
			else
				cout << temp << " - (" << (i + 9) << ":" << (i + 10) << ")  --> " << "(booked)" << endl;
		}
		else
		{
			if(i==0)
				cout << temp << " - (0" << (i + 9) << ":" << (i + 10) << ")  -->  " << "(empty)" << endl;
			else
					cout << temp << " - (" << (i + 9) << ":" << (i + 10) << ")  -->  " << "(empty)" << endl;
		}
	}
	char uschoice;
loop1:	cout << "\n Which period do you want to book ?\n" << "--> ";
	cin >> uschoice;
	// toupper used to convert any letter to uppercase..
	uschoice = toupper(uschoice);
	if ((uschoice >= 'A' && uschoice <= 'J'))
	{
		int temp = uschoice - 65;
		if (arr[temp] == 1)
		{
			cout << "Error : this period is booked already!!\n";
			goto loop1;
		}
		else
		{
			cout << "\n Enter your name" << "\n --> ";
			getchar();
			getline(cin, name);
		}
	}
	else
	{
		cout << "Error : your choice must be form A to J\n";
		goto loop1;
	}
	// iso::app make the code take the file with it's data without genrate new one ....
	out.open(dname, ios::app);
	if (out)
	{
		out << uschoice << " : " << name << "\n";
		out.close();
		cout << "\n Appointment has been booked for : " << (uschoice - 65) + 9 << " o'clock  successfully !!\n";
		cout << "Patient Name: " << name << endl;
	}
	editarr(arr, dname);
loop2: cout << "\n 1 - continue. " << "\n 2 - back to main page." << "\n 3 - exit " << endl << " --> ";
	string rr;
	cin >> rr;
	if (rr == "1")
	{
		//system("cls") used to clean the console from data..
		system("cls");
		goto loop3;
	}
	else if (rr == "3")
		return 0;
	else if (rr == "2")
		return 1;
	else
	{
		cout << "Error:invalid input\n";
		goto loop2;
	}
}
int main()
{
	doctors d1;
	string uoa;
	admin admin1;
l2:	system("cls");
	cout << " Doctors Appointment system\n" << "--------------------------------\n";
l1:	cout << "\n1 - User.\n" << "2 - Admin.\n" << "3 - Exit.\n";
	cout << " --> ";
	cin >> uoa;
	if (uoa == "1")
	{
		cout << "Which doctor do you want ?\n";
		int chk = d1.doctorchoose();
		if (chk == 0)
		{
			string qqq;
		lx:	cout << "do you want to continue (yes, no)" << endl;
			cout << " --> ";
			cin >> qqq;
			if (qqq == "yes")
				goto l2;
			else if (qqq == "no")
				return 0;
			else
			{
				cout << "Error:invalid input\n";
				goto lx;
			}

		}
		else
		{
			system("cls");
			int x = booking(arr[d1.q], d1.nn);
			if (x == 1)
				goto l2;
			else
				return 0;
		}
	}
	else if (uoa == "2")
	{
		string usname;
		string password;
		system("cls");
	l3:  cout << "Enter your Data\n" << "--------------------------------\n";
		cout << "\nEnter user name\n" << " --> ";
		cin >> usname;
		cout << "Enter Password\n" << " --> ";
		cin >> password;

		int right = admin1.usname(usname) & (admin1.pass(password));
		if (right == 1)
		{
			cout << "right Data\n";
			int z = admin1.mainadmin();
			if (z == 1)
				goto l2;
			else
				return 0;
		}
		else
		{
			system("cls");
			cout << " Error : wrong Data !!\n";
			goto l3;
		}
	}
	else if (uoa == "3")
		return 0;
	else
	{
		cout << "Error:invalid input";
		goto l1;
	}
}