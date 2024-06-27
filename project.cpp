#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

ifstream in;
ofstream out;
int arr[100][11];

class doctors {
public:
    string doc_file_name;
    char user_select;
    int doc_index ;

    int doctorchoose() 
    {
        ifstream in;
        if(Is_DoctorList_Empty())
        {
            string doc_names[100];
            in.open("doctors.txt");
            string temp;
            int count = 0;
            while (getline(in, temp)) 
            {
                doc_names[count] = temp;
                count++;
            }
            in.close();

            while (true) 
            {
                char max_index;
                for (char i = 0; i < count; i++)
                {
                    max_index = i + 65;
                    cout << max_index << " - " << doc_names[i] << endl;
                }

                cout << " --> ";
                cin >> user_select;
                user_select = toupper(user_select);
                if (user_select >= 'A' && user_select <= max_index) 
                {
                    doc_index  = user_select - 65;
                    doc_file_name = doc_names[doc_index] + ".txt";
                    array_prepare();
                    break;
                } 
                else 
                {
                    cout << "Error: invalid input\n";
                }
            }
        }
        else 
        {
            cout << "\n Error: there are no doctors now, ask the admin for more data\n";
            return 0;
        }

    return 1;
    }

    bool Is_DoctorList_Empty() 
    {
        ifstream in;
        in.open("doctors.txt");
        if (!in) 
            return false;
    
        in.close();
        return true;
    }

    void array_prepare() 
    {
        ifstream in;
        ofstream out;
        in.open(doc_file_name);
        if (!in) 
        {
            in.close();
            out.open(doc_file_name, ios::app);
            for (int i = 0; i < 11; i++)
                arr[doc_index ][i] = 0;
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

    void editarr(int arr[], string dname) {
        in.open(dname);
        string temp;
        while (getline(in, temp)) {
            int index = (temp[0] - 65);
            arr[index] = 1;
        }
        in.close();
    }

    int usname(string usname) {
        return usname == username ? 1 : 0;
    }

    int pass(string pass) {
        return pass == password ? 1 : 0;
    }

    int mainadmin() 
    {
        ofstream out;
        string x;

        while (true) 
        {
            system("cls");
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
                cout << "Doctor: " << newd << " added successfully \n";
                out.close();
                string doc_index ;
                while (true) {
                    cout << "do you want to continue (yes, no)" << endl;
                    cout << " --> ";
                    cin >> doc_index ;
                    if (doc_index  == "yes")
                        break;
                    else if (doc_index  == "no")
                        return 0;
                    else
                        cout << "Error: invalid input\n";
                }
            }
            else if (x == "2") 
            {
                string doc_names[100];
                in.open("doctors.txt");
                string temp;
                int x = 0;
                while (getline(in, temp)) {
                    doc_names[x] = temp;
                    x++;
                }
                in.close();
                for (int i = 0; i < x; i++) {
                    cout << i + 1 << " - " << doc_names[i] << endl;
                }
                string doc_index ;
                while (true) {
                    cout << "do you want to continue (yes, no)" << endl;
                    cout << " --> ";
                    cin >> doc_index ;
                    if (doc_index  == "yes")
                        break;
                    else if (doc_index  == "no")
                        return 0;
                    else
                        cout << "Error: invalid input\n";
                }
            } 
            else if (x == "3") 
            {
                doctors d2;
                string qq;
                cout << "which doctor do you want\n";
                d2.doctorchoose();
                del_appointment(d2.doc_index , d2.doc_file_name);
                while (true) {
                    cout << "do you want to continue (yes, no)" << endl;
                    cout << " --> ";
                    cin >> qq;
                    if (qq == "yes")
                        break;
                    else if (qq == "no")
                        return 0;
                    else
                        cout << "Error: invalid input\n";
                }
            } 
            else if (x == "4") 
            {
                return 1;
            } 
            else 
            {
                cout << "Error: invalid input\n";
                cout << "Enter anything to go back";
                getchar();
                getchar();
            }
        }
    }

    int del_appointment(int y, string file_name) 
    {
        ifstream in;
        ofstream out;
        string temparr[100];
        in.open(file_name);
        int x = 0;
        string temp;
        while (getline(in, temp)) {
            temparr[x] = temp;
            int k = temparr[x][0] - 65;
            if (k >= 0 && k <= 10) 
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
            cout << "there are no appointments" << endl;
            return 0;
        } else 
        {
            cout << "enter the appointment letter: ";
            char delet;
            cin >> delet;
            delet = toupper(delet);
            arr[y][delet - 65] = 0;
            string tarr[100];
            int xx = 0;
            int tt = 0;
            for (int i = 0; i < x; i++) {
                if (temparr[i][0] != delet) {
                    tarr[xx] = temparr[i];
                    xx++;
                } else
                    tt = 1;
            }
            if (tt == 0) {
                cout << "Error: this appointment isn't booked\n";
                return 0;
            } else {
                out.open(file_name);
                for (int i = 0; i < xx; i++)
                    out << tarr[i] << endl;
                out.close();
                cout << "The appointment deleted successfully\n";
                editarr(arr[y], file_name);
                return 0;
            }
        }
    }
};





int booking(int arr[], string dname) ;
void editarr(int arr[], string dname);

int main() 
{
    doctors d1;
    string user_or_admin;
    admin admin1;

    while (true) {
        system("cls");
        cout << "Doctors Appointment system\n" << "--------------------------------\n";
        cout << "\n1 - User.\n2 - Admin.\n3 - Exit.\n";
        cout << " --> ";
        cin >> user_or_admin;

        if (user_or_admin == "1") 
        {
            cout << "Which doctor do you want?\n";
            int chk = d1.doctorchoose();
            if (chk == 0) 
            {
                string continue_check;
                while (true) 
                {
                    cout << "do you want to continue (yes, no)" << endl;
                    cout << " --> ";
                    cin >> continue_check;
                    if (continue_check == "yes")
                        break;
                    else if (continue_check == "no")
                        return 0;
                    else
                        cout << "Error: invalid input\n";
                }
            }
             else 
            {
                system("cls");
                int x = booking(arr[d1.doc_index ], d1.doc_file_name);
                if (x == 1)
                    continue;
                else
                    return 0;
            }
        } 
        else if (user_or_admin == "2") 
        {
            string usname;
            string password;
            system("cls");
            while (true) {
                cout << "Enter your Data\n" << "--------------------------------\n";
                cout << "\nEnter user name\n --> ";
                cin >> usname;
                cout << "Enter Password\n --> ";
                cin >> password;
                if (admin1.usname(usname) && admin1.pass(password)) 
                {
                    cout << "right Data\n";
                    int user_select = admin1.mainadmin();
                    if (user_select == 1)
                        break;
                    else
                        return 0;
                }
                 else
                {
                    system("cls");
                    cout << "Error: wrong Data!!\n";
                }
            }
        } 
        else if (user_or_admin == "3") 
            return 0;
        else 
            cout << "Error: invalid input";
    }
}
void editarr(int arr[], string dname) 
{
    ifstream in;
    in.open(dname);
    string temp;
    while (getline(in, temp)) {
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
    string name;
    editarr(arr, dname);
    for (int i = 0; i < 10; i++) {
        char temp = i + 65;
        if (arr[i] == 1) {
            if (i == 0)
                cout << temp << " - (0" << (i + 9) << ":" << (i + 10) << ")  --> " << "(booked)" << endl;
            else
                cout << temp << " - (" << (i + 9) << ":" << (i + 10) << ")  --> " << "(booked)" << endl;
        } else {
            if (i == 0)
                cout << temp << " - (0" << (i + 9) << ":" << (i + 10) << ")  -->  " << "(empty)" << endl;
            else
                cout << temp << " - (" << (i + 9) << ":" << (i + 10) << ")  -->  " << "(empty)" << endl;
        }
    }
    char Time_choice;
    while (true) {
        cout << "\n Which period do you want to book?\n" << "--> ";
        cin >> Time_choice;
        Time_choice = toupper(Time_choice);
        if ((Time_choice >= 'A' && Time_choice <= 'J')) {
            int temp = Time_choice - 65;
            if (arr[temp] == 1) {
                cout << "Error: this period is booked already!!\n";
            } else {
                cout << "\n Enter your name\n --> ";
                getchar();
                getline(cin, name);
                break;
            }
        } else {
            cout << "Error: your choice must be from A to J\n";
        }
    }
    out.open(dname, ios::app);
    if (out) {
        out << Time_choice << " : " << name << "\n";
        out.close();
        cout << "\n Appointment has been booked for: " << (Time_choice - 65) + 9 << " o'clock successfully!!\n";
        cout << "Patient Name: " << name << endl;
    }
    editarr(arr, dname);
    while (true) {
        cout << "\n1 - back to main page.\n 2 - exit \n --> ";
        string select;
        cin >> select; 
        if (select == "2") {
            return 0;
        } 
        else if (select == "1") {
            return 1;
        } else {
            cout << "Error: invalid input\n";
        }
    }
}
