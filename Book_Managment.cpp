#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class Book
{
    string Name[100], ID[100], Title[100], Shelf_No[100], CN[100], path;
    long long int Copies_Available[100];
    int i_B, j_B, C, temp;
    string Data_path, Save_path;
    char line[100];

protected:
    string login_Path;

public:
    Book()
    {
        ifstream file("C:\\BooK\\User_Book.txt"); 
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
            cout << "\nCreat a folder Name Book(Path :C:\\Book)!!\n";
            cout << "Enter the Login Path :";
            getline(cin, login_Path);
            cout << "Enter the Data path :";
            getline(cin, Data_path);
            ofstream S("C:\\Book\\User_Book.txt");
            S << login_Path << "\n";
            S << Data_path;
            S.close();
            system("cls");
        }
        C = 0;
    }
    void start_B()
    {
        i_B = 0;
        j_B = 0;
        ifstream S;
        S.open(Data_path);
        while (S)
        {
            if (i_B % 5 == 0)
            {
                S.getline(line, 30);
                Title[j_B] = line;
                S.getline(line, 30);
                Name[j_B] = line;
                S.getline(line, 30);
                ID[j_B] = line;
                S.getline(line, 30);
                CN[j_B] = line;
                S.getline(line, 30);
                Shelf_No[j_B] = line;
                j_B++;
            }
            i_B++;
        }
        C = j_B - 1;
        S.close();
        for (int i = 0; i < C; i++)
        {
            Copies_Available[i] = stoll(CN[i]);
        }
    }
    void GetData_B()
    {
    Entry:
        cout << "Enter book title: ";
        cin >> Title[C];
        cout << "Enter book ID : ";
        cin >> ID[C];
        for (int i = 0; i < C; i++)
        {
            if (ID[C] == ID[i])
            {
                cout << "\nThis ID already exists! Please enter a different ID.\n";
                goto Entry;
            }
        }

        cout << "Enter the author's name: ";
        cin >> Name[C];
        cout << "Enter the total number of copies available in the library: ";
        cin >> Copies_Available[C];
        cout << "Enter the book location (Shelf Number): ";
        cin >> Shelf_No[C];
        C++;
        cout << "Book data added successfully!\n";
        save_B();
        // system("cls");
    }
    void Display_B()
    {
        cout << "Book details:\n";
        for (int i = 0; i < C; i++)
        {
            cout << "\n-----------------------------------------------\n\n";
            cout << "Book Title: " << Title[i];
            cout << "\nAuthor's Name: " << Name[i];
            cout << "\nBook ID Number: " << ID[i];
            cout << "\nCopies Available: " << Copies_Available[i];
            cout << "\nShelf Number: " << Shelf_No[i];
            cout << "\n-----------------------------------------------\n\n";
        }
    }
    void edit_B(string T)
    {
        for (int i = 0; i < C; i++)
        {
            if (T == ID[i])
            {
                cout << "\nBook Title :" << Title[i];
                cout << "\nID Number :" << ID[i];
                cout << "\nBook author name :" << Name[i];
                cout << "\nCopies available" << Copies_Available[i];
                cout << "\n\nEnter required changes !!\n\n";
                ID[i] = " ";
            Entry:
                cout << "Enter Book Title :";
                cin >> Title[i];
                cout << "Book ID Number :";
                cin >> T;
                for (int j = 0; j < C; j++)
                {
                    if (j != i)
                    {
                        if (T == ID[j])
                        {
                            ID[i] = "";
                            cout << "\nThis ID already exists! Please enter a different ID.\n";
                            goto Entry;
                        }
                        ID[i] = T;
                    }
                }
                cout << "Enter Book Author Name :";
                cin >> Name[i];
                cout << "Total No. of copies available in library :";
                cin >> Copies_Available[i];
            }
        }
        save_B();
    }
    void save_B()
    {
        ofstream Stu;
        Stu.open(Data_path);
        for (int i = 0; i < C; i++)
        {
            Stu << Title[i] << "\n";
            Stu << Name[i] << "\n";
            Stu << ID[i] << "\n";
            Stu << Copies_Available[i] << "\n";
            Stu << Shelf_No[i] << "\n";
        }
        Stu.close();
    }
    void Book_Data()
    {
        cout << "Enter the path where you want to Save the text file :";
        cin >> Save_path;
        ofstream Stu;
        Stu.open(Save_path);
        for (int i = 0; i < C; i++)
        {
            Stu << "-----------------------------------------------\n\n";
            Stu << "\nBook Title :" << Title[i];
            Stu << "\nBook author name :" << Name[i];
            Stu << "\nID Number :" << ID[i];
            Stu << "\nCopies available :" << Copies_Available[i];
            Stu << "\nThe location of Book (Self No.) :" << Shelf_No[i];
            Stu << "\n-----------------------------------------------\n\n";
        }
        Stu.close();
    }
    void B_delet()
    {
        cout << "Book ID :";
        cin >> line;
        for (int i = 0; i < C; i++)
        {
            if (ID[i] == line)
            {
                i_B = i;
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
            for (int i = 0; i < (C - i_B); i++)
            {
                Title[i_B + i] = Title[i_B + 1 + i];
                Name[i_B + i] = Name[i_B + 1 + i];
                ID[i_B + i] = ID[i_B + 1 + i];
                Copies_Available[i_B + i] = Copies_Available[i_B + 1 + i];
                Shelf_No[i_B + i] = Shelf_No[i_B + 1 + i];
            }
            cout << "\n\nDeleted Succesfully !!";
            C--;
            save_B();
        }
        else
        {
            cout << "\n\nData not found !!";
        }
    }
};
class login_B : public Book
{
    string Password[5], User_Name[5];
    char line[30];
    int i, j;

public:
    login_B()
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
    login_B L;
    string T, us, pas;
    int c;
    cout << "\nWelcome to the Book Management System!\n";
    cout << "Please follow the on-screen instructions to proceed.\n";
Entry_B:
    cout << "\nEnter User Name :";
    cin >> us;
    cout << "Enter password :";
    cin >> pas;
    c = L.Check(us, pas);
    if (c == 1)
    {

        system("cls");
        cout << "----------Login Successfully !!----------";
        do
        {
            L.start_B();
            cout << "\nMenu Options:";
            cout << "\n1. Add a Book.";
            cout << "\n2. Display Books.";
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

                L.GetData_B();
                break;
            case 2:
                L.Display_B();
                break;
            case 3:
                cout << "Enter Book Id : ";
                cin >> T;
                L.edit_B(T);
                break;
            case 4:
                L.Book_Data();
                break;
            case 5:
                L.B_delet();
                break;
            case 6:
                cout << "\nCode Exit !!";
                break;
            default:
                cout << "\n\nWrong Entry !!\n\n";
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