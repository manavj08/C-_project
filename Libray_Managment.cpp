#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;
class Data_Book // It help to extract Data of Book from txt file (Data_Book)
{
protected:
    string B_Name[30], B_ID[30], Title[30], CN[30], Shelf_No[30];
    long long int Copies_Available[30];
    int i_B, j_B;
    string login_path, S_Data_path, B_Data_path, R_Data_path, P_Data_path;
    char line[100];
    Data_Book()
    {
        ifstream file("C:\\Library_Managment\\User_Library.txt");
        if (file.is_open())
        {

            file.getline(line, 40);
            login_path = line;
            file.getline(line, 50);
            S_Data_path = line;
            file.getline(line, 50);
            B_Data_path = line;
            file.getline(line, 50);
            R_Data_path = line;
            file.getline(line, 50);
            P_Data_path = line;
            file.close();
        }
        else
        {

            file.close();
            cout << "\nCreat a folder Name Library_Managment(Path :C:\\Library_Managment)!!\n";
            cout << "Enter the Login Path :";
            getline(cin, login_path);
            cout << "Enter the Book Data path :";
            getline(cin, B_Data_path);
            cout << "Enter the Student Data path :";
            getline(cin, S_Data_path);
            cout << "Enter the Rent Data Path :";
            getline(cin, R_Data_path);
            cout << "Enter the presenty Data Path :";
            getline(cin, P_Data_path);
            ofstream S("C:\\Library_Managment\\User_Library.txt");
            S << login_path << "\n";
            S << S_Data_path << "\n";
            S << B_Data_path << "\n";
            S << R_Data_path << "\n";
            S << P_Data_path << "\n";
            S.close();
            system("cls");
        }
        i_B = 0;
        j_B = 0;
        ifstream S;
        S.open(B_Data_path);
        while (S)
        {
            if (i_B % 5 == 0)
            {
                S.getline(line, 30);
                Title[j_B] = line;
                S.getline(line, 30);
                B_Name[j_B] = line;
                S.getline(line, 30);
                B_ID[j_B] = line;
                S.getline(line, 30);
                CN[j_B] = line;
                S.getline(line, 30);
                Shelf_No[j_B] = line;
                j_B++;
            }

            i_B++;
        }
        S.close();
    }

public:
    void R_B()
    {
        ifstream S;
        S.open(B_Data_path);
        while (S)
        {
            if (i_B % 5 == 0)
            {
                S.getline(line, 30);
                Title[j_B] = line;
                S.getline(line, 30);
                B_Name[j_B] = line;
                S.getline(line, 30);
                B_ID[j_B] = line;
                S.getline(line, 30);
                CN[j_B] = line;
                S.getline(line, 30);
                Shelf_No[j_B] = line;
                j_B++;
            }

            i_B++;
        }
        S.close();
    }
};
class Data_Student : public Data_Book // It help to extract Data of Student from txt file (Data_student)
{
protected:
    string S_Name[30], S_EN[30], Department[30], Con[30];
    long long int Contact[30];
    int i_S, j_S;
    char line[30];

public:
    void R_S()
    {
        i_S = j_S = 0;
        ifstream S;
        S.open(S_Data_path);
        while (S)
        {
            if (i_S % 4 == 0)
            {
                S.getline(line, 30);
                S_Name[j_S] = line;
                S.getline(line, 30);
                S_EN[j_S] = line;
                S.getline(line, 30);
                Con[j_S] = line;
                S.getline(line, 30);
                Department[j_S] = line;
                j_S++;
            }
            i_S++;
        }
        S.close();
        for (int i = 0; i < j_S - 1; i++)
        {
            Contact[i] = stoll(Con[i]);
        }
    }
};
class Rent_Date : public Data_Student
{
protected:
    long long int D[30], M[30], Y[30], RD[30], RM[30], RY[30], SD[30], SM[30], SY[30];
    int t, i_R, j_R;
    int Day_M[2][12] = {{31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    float F;
    int TD, TD1, TD2;
    float T_fine[30];
    string d[30], m[30], y[30], rd[30], rm[30], ry[30];
    Rent_Date()
    {

        for (int j = 0; j < 2; j++)
        {

            for (int i = 0; i < 12; i++)
            {

                if (i == 1 && j == 1)
                {
                    Day_M[j][i] = 29;
                }
                else if (i == 1 && j == 0)
                {
                    Day_M[j][i] = 28;
                }
            }
        }
    }
    void getdata_Date(int a)
    {
        cout << "Enter the date of Rent (DD MM YY):";
        cin >> D[a] >> M[a] >> Y[a];
        Retur_Calculate(a);
    }
    void Retur_Calculate(int j)
    {
        RY[j] = Y[j];
        RM[j] = M[j];
        if (Y[j] % 4 == 0 && (Y[j] % 100 != 0 || Y[j] % 400 == 0))
        {
            t = 1;
        }
        else
        {
            t = 0;
        }
        RD[j] = 11 + D[j];
        while (RD[j] > Day_M[t][M[j] - 1])
        {
            RD[j] = RD[j] - Day_M[t][M[j] - 1];
            RM[j]++;
        }
        while (RM[j] > 12)
        {
            RM[j] = RM[j] - 12;
            RY[j]++;
        }
        cout << "\n\nThe return date is " << RD[j] << "/" << RM[j] << "/" << RY[j];
    }
    int calculate_Days(int m, int y)
    {
        TD = 0;
        if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
        {
            t = 1;
        }
        else
        {
            t = 0;
        }
        for (int i = 0; i < (m - 1); i++)
        {
            TD = TD + Day_M[t][i];
        }
        return TD;
    }
    void fine_Calculate(int k)
    {
        cout << "\nEnter the submiting date (DD MM YYYY) :";
        cin >> SD[k] >> SM[k] >> SY[k];
        TD1 = calculate_Days(SM[k], SY[k]);
        TD2 = calculate_Days(RM[k], RY[k]);
        T_fine[k] = ((TD1 + SD[k]) - (TD2 + RD[k])) * 10;
        if (T_fine[k] < 0)
        {
            T_fine[k] = 0;
        }
        cout << "\nThe fine to pay is " << T_fine[k];
    }
};
class Borrowing_Book : public Rent_Date
{
protected:
    stringstream ss;
    string RB_ID[30], RS_En[30], R_CN[30], T, Token[30];
    string R_D[30], R_M[30], R_Y[30], Total[30];
    long long int R_Copies[30];
    int C, i_R, j_R, temp, I;
    char line[30], a[2], b[4];

    Borrowing_Book()
    {
        C = 0;
        i_R = 0;
        j_R = 0;
        for (int i = 0; i < 30; i++)
        {
            R_Copies[i] = 0;
        }
        ifstream S(R_Data_path);
        while (S)
        {
            if (i_R % 7 == 0)
            {
                S.getline(line, 30);
                Token[j_R] = line;
                S.getline(line, 30);
                RB_ID[j_R] = line;
                S.getline(line, 30);
                RS_En[j_R] = line;
                S.getline(line, 30);
                R_D[j_R] = line;
                S.getline(line, 30);
                R_M[j_R] = line;
                S.getline(line, 30);
                R_Y[j_R] = line;
                S.getline(line, 30);
                Total[j_R] = line;
                j_R++;
            }
            i_R++;
        }
        C = j_R - 1;
        for (int i = 0; i < C; i++)
        {
            RD[i] = stoi(R_D[i]);
            RM[i] = stoi(R_M[i]);
            RY[i] = stoi(R_Y[i]);
            T_fine[i] = stoi(Total[i]);
            for (int j = 0; j < j_B - 1; j++)
            {
                if (RB_ID[i] == B_ID[j])
                {
                    R_Copies[j]++;
                }
            }
        }
    }

public:
    void Borrow_Book()
    {

    Enter_Book:
        cout << "\nEnter book ID :";
        cin >> RB_ID[C];
        if (RB_ID[C] == "1")
        {
            RB_ID[C] = "";
            goto exit;
        }

        find_B(RB_ID[C]);
        if (temp == 2)
        {
            RB_ID[C] = "";
            goto Enter_Book;
        }
        else
        {
            cout << "Enter Student Enrollment No. :";
            cin >> RS_En[C];
            if (RS_En[C] == "1")
            {
                goto exit;
            }
            find_S(RS_En[C]);
            if (temp == 1)
            {
                cout << "\nData not found !!";
                RS_En[C] = "";
            }
            else
            {
                cout << "\nYour token No. is " << &RB_ID[C] << "\n\n";
                ss << &RB_ID[C];
                Token[C] = ss.str();
                getdata_Date(C);
                C++;
            }
        }
    exit:
        cout << "\n\nExit";
        Save_Rent();
    }
    void Return_Book()
    {
    Enter_Book:
        cout << "\nEnter Token No. :";
        cin >> T;
        for (int i = 0; i < C; i++)
        {
            if (T == Token[i])
            {
                find_B(RB_ID[i]);
                find_S(RS_En[i]);
                cout << "If the information is true enter 1 :";
                cin >> i_R;
                if (i_R == 1)
                {
                    fine_Calculate(i);
                    if (T_fine[i] != 0)
                    {
                        cout << "\nFor Paying Now enter 0 :";
                        cin >> i_R;
                        if (i_R == 0)
                        {
                            cout << "\nEnter the amount you want to pay :";
                            cin >> i_R;
                            T_fine[i] = T_fine[i] - i_R;
                            if (T_fine[i] != 0)
                            {
                                cout << "\n\nThe remaning amount is " << T_fine[i];
                            }
                            else if (T_fine[i] == 0)
                            {
                                Save_Submited(i);
                            }
                        }
                    }
                }
                else
                {
                    cout << " Exit !!";
                }
            }
        }
        // fine_Calculate(I);
    }
    void Save_Submited(int k)
    {
        for (int i = k; i < C - k; i++)
        {
            Token[i] = Token[i + 1];
            RB_ID[i] = RB_ID[i + 1];
            RS_En[i] = RS_En[i + 1];
            RD[i] = RD[i + 1];
            RM[i] = RM[i + 1];
            RY[i] = RY[i + 1];
            T_fine[i] = T_fine[i + 1];
        }
        C--;
        Save_Rent();
    }
    void find_B(string t)
    {
        for (int i = 0; i < j_B - 1; i++)
        {
            if (t == B_ID[i])
            {
                cout << "\n-----------------------------------------------\n";
                cout << "\nBook Title :" << Title[i];
                cout << "\nBook author name :" << B_Name[i];
                cout << "\nID Number :" << B_ID[i];
                Copies_Available[i] = stoll(CN[i]);
                cout << "\nCopies available :" << Copies_Available[i];
                cout << "\nNumber of copies out of Rent :" << R_Copies[i];
                cout << "\nThe location of Book (Self No.) :" << Shelf_No[i];
                cout << "\n-----------------------------------------------\n\n";
                if (R_Copies[i] == Copies_Available[i])
                {
                    cout << "\n\n Book is not Available right Now !!";
                    break;
                    temp = 2;
                }
                else
                {
                    temp = 1;
                    break;
                }
            }
            else
            {
                temp = 2;
            }
        }
        if (temp == 2)
        {
            cout << "\nThe book is not available in libray \nor Invalid ID !!";
        }
    }
    void find_S(string t)
    {
        for (int i = 0; i < j_S - 1; i++)
        {
            if (t == S_EN[i])
            {
                cout << "\n\n-----------------------------------------------\n\n";
                cout << "Student name :" << S_Name[i];
                cout << "\nEnrollment Number :" << S_EN[i];
                cout << "\nDepartment : " << Department[i];
                cout << "\n\n-----------------------------------------------\n\n";
                temp = 0;
                break;
            }
            else
            {
                temp = 1;
            }
        }
        if (temp == 1)
        {
            cout << "\nThe Student Data not Found \nor Invalid ID !!";
        }
    }
    void Panding_NotSubmit()
    {
        ofstream S("Fine_Panding_Student.txt");
        for (int i = 0; i < C; i++)
        {
            if (T_fine[i] != 0)
            {
                S << "Pending Fine ṇof following Student:\n\n";
                S << "The Token No. :" << Token[i] << "\n";
                S << "Book ID :" << RB_ID[i] << "\n";
                S << "Student ID :" << RS_En[i] << "\n";
                S << "Remaning Fine is :" << T_fine[i];
                S << "\n\n-----------------------------------------------\n\n";
            }
        }
        S << "############################################################\n\n";
        for (int i = 0; i < C; i++)
        {
            if (T_fine[i] == 0)
            {
                S << "Student Not submited Book are as folow :\n\n";
                S << "The Token No. : " << Token[i] << "\n";
                S << "Book ID : " << RB_ID[i] << "\n";
                S << "Student ID : " << RS_En[i] << "\n";
                S << "The Retuning Date : " << RD[i] << "/" << RM[i] << "/" << RY[i];
                S << "\n\n-----------------------------------------------\n\n";
            }
        }
        S.close();
    }
    void Save_Rent()
    {
        ofstream S(R_Data_path);
        for (int i = 0; i < C; i++)
        {
            S << Token[i] << "\n";
            S << RB_ID[i] << "\n";
            S << RS_En[i] << "\n";
            S << RD[i] << "\n";
            S << RM[i] << "\n";
            S << RY[i] << "\n";
            S << T_fine[i] << "\n";
        }
        S.close();
    }
};
class libarary : public Borrowing_Book
{
    int Read_count[30], i_read, i, j;
    string T, Read_ID[50][30];
    int PD[50], PM[50], PY[50], TPD, TPM, TPY, j_read[50];
    ifstream M;
    char T_read[3];

public:
    libarary()
    {
        for (int i = 0; i < 30; i++)
        {
            j_read[i] = Read_count[i] = 0;
        }
        i_read = 0;
        i = j = 0;
    }
    void come_Read()
    {
        cout << "\nEnter the Date (DD/MM/YYYY):";
        cin >> TPD >> TPM >> TPY;
    read:
        for (int i = 0; i < i_read; i++)
        {
            if (TPD == PD[i] && TPM == PM[i] && TPY == PY[i])
            {
                cout << "Enter Student Enrollment No. :";
                cin >> T;
                find_S(T);
                if (temp == 0)
                {
                    Read_ID[i][j_read[i]] = T;
                    j_read[i]++;
                }
                temp = 8;
                break;
            }
            temp = 0;
        }
        if (temp != 8)
        {
            PD[i_read] = TPD;
            PM[i_read] = TPM;
            PY[i_read] = TPY;
            i_read++;
            goto read;
        }
        Save_Prsenty();
    }
    void Save_Prsenty()
    {
        ofstream M;
        M.open(P_Data_path);
        for (int i = 0; i < i_read; i++)
        {
            M << PD[i] << "\n"
              << PM[i] << "\n"
              << PY[i] << "\n";
            M << j_read[i] << "\n";
            for (int j = 0; j < j_read[i]; j++)
            {
                M << Read_ID[i][j] << "\n";
            }
        }
        M.close();
    }
    void prsenty()
    {
        ofstream M;
        M.open("Presenty.txt");
        for (int i = 0; i < i_read; i++)
        {
            M << "-----------------------------------------------\n\n";
            M << "Date :" << PD[i] << " - " << PM[i] << " - " << PY[i];
            M << "\nThe total number of present students is " << j_read[i];
            for (int j = 0; j < j_read[i]; j++)
            {
                M << "\nStudent ID-" << j + 1 << " : " << Read_ID[i][j];
                for (int k = 0; k < j_S; k++)
                {
                    if (Read_ID[i][j] == S_EN[k])
                    {
                        M << "\nStudent Name-" << j + 1 << " : " << S_Name[k];
                        break;
                    }
                }
                M << "\n";
            }
            M << "\n-----------------------------------------------\n\n";
        }
        M.close();
    }
};
class login : public libarary
{
    string Password[5], User_Name[5];
    char line[30];
    int i, j;

public:
    login()
    {
        i = j = 0;
        ifstream S;
        S.open(login_path);
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
    login L;
    string us, pas, T;
    int C;
    cout << "Welcome to the Library Management System!\n";
    cout << "Please follow the on-screen instructions to proceed.\n";
Entry:
    cout << "\nEnter your User Name :";
    cin >> us;
    cout << "Enter your password :";
    cin >> pas;
    system("cls");
    C = L.Check(us, pas);
    if (C == 1)
    {

        cout << "----------Login Successfully !!----------";
        do
        {
            L.R_B();
            L.R_S();
            cout << "\n\n1. Search for Book and Student Details.\n2. Student Entries. \n3. Borrow Book.\n4. Return a Book.\n5. Download Entries(in .txt).\n6. Download data of students with pending fine payments and unreturned books(In .txt). \n7. Exit.\n";
            cout << "Enter your preference number :";
            cin >> C;
            system("cls");
            switch (C)
            {
            case 1:
                cout << "\n1. Book detail Search .\n2. Student detail Search.\n3. Exit,\nEnter:";
                cin >> C;
                system("cls");
                if (C == 1)
                {
                    cout << "Enter book ID :";
                    cin >> T;
                    L.find_B(T);
                }
                else if (C == 2)
                {
                    cout << "Enrollment Number :";
                    cin >> T;
                    L.find_S(T);
                }
                break;
            case 2:
                L.come_Read();
                break;
            case 3:
                L.Borrow_Book();
                break;
            case 4:
                L.Return_Book();
                break;
            case 5:
                L.prsenty();
                break;
            case 6:
                L.Panding_NotSubmit();
                break;

            default:
                cout << "Invalid Entry !!";
                break;
            }
        } while (C != 7);
    }
    else
    {
        cout << "\n\nThe username or password is incorrect !!\n\n";
        goto Entry;
    }
}