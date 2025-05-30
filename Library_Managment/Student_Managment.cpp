#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class Student
{
    string Name[100], EN[100], Department[100], Contact[100];
    int C, i_S, j_S, temp;
    string Data_path;
    char line[100];

protected:
    string login_Path;

public:
    string T = "Student";
    Student()
    {
        C = 0;
        ifstream file("C:\\Student\\User_Student.txt");
        if (file.is_open())
        {

            file.getline(line, 100);
            login_Path = line;
            file.getline(line, 100);
            Data_path = line;
            file.close();
        }
        else
        {

            file.close();
            system("mkdir C:\\Student");
            cout << "Enter the Login Path :";
            getline(cin, login_Path);
            cout << "Enter the Data path :";
            getline(cin, Data_path);
            ofstream S("C:\\Student\\User_Student.txt");
            S << login_Path << "\n";
            S << Data_path;
            S.close();
            system("cls");
        }
    }
    void Start_S()
    {
        ifstream Stu1;
        Stu1.open(Data_path);
        i_S = j_S = 0;
        while (Stu1)
        {
            if (i_S % 4 == 0)
            {
                Stu1.getline(line, 30);
                Name[j_S] = line;
                Stu1.getline(line, 30);
                EN[j_S] = line;
                Stu1.getline(line, 30);
                Contact[j_S] = line;
                Stu1.getline(line, 30);
                Department[j_S] = line;
                j_S++;
            }
            i_S++;
        }
        C = j_S - 1;
        Stu1.close();
    }
    void GetData_S()
    {
    Entry:
        cout << "Enter student name :";
        cin >> Name[C];
        cout << "Student Enrollment Number :";
        cin >> EN[C];
        for (int i = 0; i < C; i++)
        {
            if (EN[C] == EN[i])
            {
                cout << "\nThis ID already exists !!\n";
                goto Entry;
            }
        }
    Cont:
        cout << "Contact Number :";
        cin >> Contact[C];
        if (Contact[C].length() != 10)
        {
            cout << "\nEnter the Contact No. of 10 digits !!\n\n";
            goto Cont;
        }
        cout << "Department in short (e.g CSE,AI&ML,...) :";
        cin >> Department[C];
        C++;
        Save_S();
    }
    void Display_S()
    {
        for (int i = 0; i < C; i++)
        {
            cout << "\n-----------------------------------------------\n\n";
            cout << i + 1 << ".\n";
            cout << "Student name :" << Name[i];
            cout << "\nEnrollment Number :" << EN[i];
            cout << "\nContact Number : " << Contact[i];
            cout << "\nDepartment in short (e.g CSE,AI&ML,...) : " << Department[i];
            cout << "\n-----------------------------------------------\n\n";
        }
    }
    void Save_S()
    {
        ofstream Stu;
        Stu.open(Data_path);
        for (int i = 0; i < C; i++)
        {
            Stu << Name[i] << "\n";
            Stu << EN[i] << "\n";
            Stu << Contact[i] << "\n";
            Stu << Department[i] << "\n";
        }
        Stu.close();
    }
    void edit_S(string T)
    {
        for (int i = 0; i < C; i++)
        {
            if (T == EN[i])
            {
                cout << "\nStudent name :" << Name[i];
                cout << "\nEnrollment Number :" << EN[i];
                cout << "\nContact Number : " << Contact[i];
                cout << "\nDepartment in short (e.g CSE,AI&ML,...) : " << Department[i];
                cout << "\n\nEnter your required changes !!\n\n";
                EN[i] = "";
            Entry_S:
                cout << "Enter student name :";
                cin >> Name[i];
                cout << "Student Enrollment Number :";
                cin >> T;
                for (int j = 0; j < C; j++)
                {
                    if (j != i)
                    {
                        if (T == EN[j])
                        {
                            EN[i] = "";
                            cout << "\nThis ID already exists !!\n";
                            goto Entry_S;
                        }
                        EN[i] = T;
                    }
                }
            Contact:
                cout << "Contact Number :";
                cin >> Contact[i];
                if (Contact[i].length() != 10)
                {
                    cout << "\nEnter the Contact No. of 10 digits !!\n\n";
                    goto Contact;
                }
                cout << "Department in short (e.g CSE,AI&ML,...) :";
                cin >> Department[i];
            }
        }
        Save_S();
    }
    void Get_Student()
    {
        ofstream Stu;
        Stu.open("student.txt");
        for (int i = 0; i < C; i++)
        {
            Stu << "\n-----------------------------------------------\n\n";
            Stu << i + 1 << ".\n";
            Stu << "Student name :" << Name[i];
            Stu << "\nEnrollment Number :" << EN[i];
            Stu << "\nContact Number : " << Contact[i];
            Stu << "\nDepartment in short (e.g CSE,AI&ML,...) : " << Department[i];
            Stu << "\n-----------------------------------------------\n\n";
        }
        Stu.close();
    }
    void S_delet()
    {
        cout << "Student Enrollment Number :";
        cin >> line;
        for (int i = 0; i < C; i++)
        {
            if (EN[i] == line)
            {
                i_S = i;
                temp = 0;
                break;
            }
            else
            {
                temp = 1;
            }
        }
        if (temp == 0)
        {
            for (int i = 0; i < (C - i_S); i++)
            {
                Name[i_S + i] = Name[i_S + 1 + i];
                EN[i_S + i] = EN[i_S + 1 + i];
                Contact[i_S + i] = Contact[i_S + 1 + i];
                Department[i_S + i] = Department[i_S + 1 + i];
            }
            cout << "\n\nDeleted Succesfully !!";
            C--;
            Save_S();
        }
        else
        {
            cout << "\n\nData not found !!";
        }
    }
};
class login_S : public Student
{
    string Password[5], User_Name[5];
    char line[30];
    int i, j;

public:
    login_S()
    {
        i = j = 0;
        ifstream S;
        S.open(login_Path);
        while (S)
        {
            if (i % 2 == 0)
            {
                S.getline(line, 30);
                User_Name[j] = line;
                S.getline(line, 30);
                Password[j] = line;
                j++;
            }
            i++;
        }
    }
    int Check(string Us, string Pas)
    {
        int C = 0;
        for (i = 0; i < j - 1; i++)
        {
            if (Us == User_Name[i] && Pas == Password[i])
            {
                C++;
            }
        }
        if (C == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
int main()
{

    login_S Log_S;
    string T, us, pas;
    int c, count = 0;
    cout << "\nWelcome to the Student Management System!\n";
    cout << "Please follow the on-screen instructions to proceed.\n";
Entry_B:
    cout << "\nEnter your User Name :";
    cin >> us;
    cout << "Enter your password :";
    cin >> pas;
    c = Log_S.Check(us, pas);
    if (c == 1)
    {
        system("cls");
        cout << "----------Login Successfully !!----------";

        do
        {
            Log_S.Start_S();
            cout << "\nMenu Options:";
            cout << "\n1. Add a Student.";
            cout << "\n2. Display Student.";
            cout << "\n3. Edit Data.";
            cout << "\n4. Download Data(in .txt).";
            cout << "\n5. Delete Data.";
            cout << "\n6. Exit.";
            cout << "\nEnter your choice: ";
            cin >> c;
            system("cls");
            switch (c)
            {
            case 1:
                Log_S.GetData_S();
                break;
            case 2:
                Log_S.Display_S();
                break;
            case 3:
                cout << "Enter student ID : ";
                cin >> T;
                Log_S.edit_S(T);
                break;
            case 4:
                Log_S.Get_Student();
                break;
            case 5:
                Log_S.S_delet();
                break;
            case 6:
                cout << "Exiting the Student Management System.\nHave a great day!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
                break;
            }
        } while (c != 6);
    }
    else
    {
        cout << "\n\nThe username or password is incorrect !!\n\n";
        goto Entry_B;
    }
}