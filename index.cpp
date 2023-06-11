#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <sstream>
#include <windows.h>
using namespace std;
int main();
void AllBooks();
void salam();
void SearchBooks();
void Calculate();
void BorrowedBoks();
void MemberChange();
void MemRenew();
void PayFine();
void memberPanel();
void adminPanel();
void MemLogin();
void MemReg();
void adminLogin();
void AddBook();
void AllBooksAdmin();
void BookModify(int n);
int AdminManageBook;
int ClientBook;
string EnteredUser;
// Pattern Of Saving Data in book.txt
// Title Author FinePerDay LastBorrowDate LastReturnDate AmountOfBorrow LastReader Avaibility BookType[1:historic,2:psychology,3:novel] IsFinePaid
string type;
int FinePaid;
// Pattern Of Saving Data in data.ttx
// UserName FirstName LastName PhoneNum PassWord DayLimit BookLimit regDate ToTalLatency Fine
int day = 30, month = 02, year = 2000; // Default Date
int BookLimit = 14;
double LatencyLimit = 0;
double BookForNow = 0;
double FineInTime = 0;
string BookName[100] = {" "};
struct LibMem
{
    string username;
    string password;
    string FirstName, LastName;
    long long int PhoneNum;
    string JoinDate, ExpDate;
    string BorrowTimeLimit, BorrowCountLimit;
    int BorrowedBooksCount;
    string BorrowedBooksList;
    int TotalLatency;
    int FinePay;
};
struct LibBook
{
    string BookTitle;
    string BookAuthor;
    string BookID = BookAuthor + BookTitle;
    string LastBorrowedUser;
    string FinePerDay;
    string type;
    string LastBorrowDate;
    string LastReturnDate;
    bool IsBorrowed;
};
void BookModify(int n)
{
    system("cls");
    string one, two, three, four, five, six, seven, eight, nine, ten, eleven, tweleve;
    ifstream BookData("book.txt");
    ofstream TemForMOdify("tfm.txt");
    cout << "1. delete Book/s" << endl;
    cout << "2. Edit Fine Price" << endl;
    int q = 1;
    cout << "What Do You Want?" << endl;
    int Anw;
    cin >> Anw;
    while (BookData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve >> type >> FinePaid)
    {
        if (Anw == 1)
        {
            if (n != q)
            {
                TemForMOdify << one << " " << two << " " << three << " " << four << " "
                             << five << " " << six << " " << seven << " " << eight
                             << " " << nine << " " << ten << " " << eleven << " " << tweleve << " " << type << " " << FinePaid << endl;
            }
        }
        else
        {
            if (n == q)
            {
                string FineEdited;
                cout << "Enter Fine You Want: ";
                cin >> FineEdited;
                TemForMOdify << one << " " << two << " " << FineEdited << " " << four << " "
                             << five << " " << six << " " << seven << " " << eight
                             << " " << nine << " " << ten << " " << eleven << " " << tweleve << " " << type << " " << FinePaid << endl;
            }
            else
            {
                TemForMOdify << one << " " << two << " " << three << " " << four << " "
                             << five << " " << six << " " << seven << " " << eight
                             << " " << nine << " " << ten << " " << eleven << " " << tweleve << " " << type << " " << FinePaid << endl;
            }
        }
        q++;
    }
    BookData.close();
    TemForMOdify.close();
    remove("book.txt");
    rename("tfm.txt", "book.txt");
    cout << "Please Wait A Moment..."
         << "We're Redirecting You To The Panel" << endl;
    Sleep(1000);
    adminPanel();
}
void AddBook()
{
    system("cls");
    int BorrowedCount = 0;
    LibBook Books;
    ofstream BookData;
    BookData.open("book.txt", ios::app);
    cout << "Add or Modify book" << endl
         << endl;
    cout << "Enter Book Title :" << endl;
    cin >> Books.BookTitle;
    BookData << Books.BookTitle << " ";
    cout << "Enter Book Author : " << endl;
    cin >> Books.BookAuthor;
    BookData << Books.BookAuthor << " ";
    cout << "Enter Fine Per Day : " << endl;
    cin >> Books.FinePerDay;
    cout << "Enter Book Type : " << endl;
    cout << "1. Historic 2. psychology 3. novel " << endl;
    cin >> Books.type;
    BookData << Books.FinePerDay << " " << day << " " << month << " " << year << " ";
    BookData << day << " " << month << " " << year << " "
             << " " << BorrowedCount << " "
             << "Null"
             << " " << 0 << " " << Books.type << " " << 0 << endl;
    cout << "Book Has Been Added succesfuly" << endl;
    cout << "1. Add Another Book" << endl;
    cout << "0. Back" << endl;
    BookData.close();
    int MenuNum;
    cin >> MenuNum;
    switch (MenuNum)
    {
    case 1:
        AddBook();
        break;

    case 0:
        adminPanel();
        break;
    }
}
void salam(){};

void AllBooks()
{
    system("cls");
    cout << "** Book Library  **";
    cout << endl
         << endl;
    ifstream BookData;
    BookData.open("book.txt");
    string one, two, three, four, five, six, seven, eight, nine, ten, eleven, tweleve;
    int BookNum = 0;
    int k = 0;
    cout << "Which Order Do you prefer" << endl;
    cout << "1. By Add Time:" << endl;
    cout << "2. By Book Type:" << endl;
    int showBook;
    cin >> showBook;
    while (BookData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve >> type >> FinePaid)
    {

        if (showBook == 1)
        {
            BookNum++;
            BookName[BookNum - 1] = one;
            cout << "Book Num     : "
                 << "00" << BookNum << endl;
            cout << "BookID       : " << one << two << endl;
            cout << "title        : " << one << endl;
            cout << "Author       : " << two << endl;
            cout << "Fine Per Day : " << three << "$" << endl;
            if (tweleve == "0")
            {
                cout << "The Book Is Borrowable!" << endl;
            }
            else
                cout << "You Can't Borrow This Book" << endl;
            cout << "      ***************** " << endl;
            if (eleven == EnteredUser && tweleve == "1")
            {
                k++;
            }
        }
    }
    BookData.close();

    if (showBook == 2)
    {
        ifstream BookData("book.txt");
        cout << "Historic Book:" << endl;
        while (BookData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve >> type >> FinePaid)
        {

            BookNum++;
            if (type == "1")
            {
                BookName[BookNum - 1] = one;
                cout << "Book Num     : "
                     << "00" << BookNum << endl;
                cout << "BookID       : " << one << two << endl;
                cout << "title        : " << one << endl;
                cout << "Author       : " << two << endl;
                cout << "Fine Per Day : " << three << "$" << endl;
                if (tweleve == "0")
                {
                    cout << "The Book Is Borrowable!" << endl;
                }
                else
                    cout << "You Can't Borrow This Book" << endl;
                cout << "      ***************** " << endl;
                if (eleven == EnteredUser && tweleve == "1")
                {
                    k++;
                }
            }
        }
        BookNum = 0;
        BookData.close();
        BookData.open("book.txt");
        cout << "psychology Book:" << endl;
        while (BookData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve >> type >> FinePaid)
        {

            BookNum++;
            if (type == "2")
            {
                BookName[BookNum - 1] = one;
                cout << "Book Num     : "
                     << "00" << BookNum << endl;
                cout << "BookID       : " << one << two << endl;
                cout << "title        : " << one << endl;
                cout << "Author       : " << two << endl;
                cout << "Fine Per Day : " << three << "$" << endl;
                if (tweleve == "0")
                {
                    cout << "The Book Is Borrowable!" << endl;
                }
                else
                    cout << "You Can't Borrow This Book" << endl;
                cout << "      ***************** " << endl;
                if (eleven == EnteredUser && tweleve == "1")
                {
                    k++;
                }
            }
        }
        BookNum = 0;

        cout << "Novel Book:" << endl;
        BookData.close();
        BookData.open("book.txt");

        while (BookData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve >> type >> FinePaid)
        {

            BookNum++;
            if (type == "3")
            {
                BookName[BookNum - 1] = one;
                cout << "Book Num     : "
                     << "00" << BookNum << endl;
                cout << "BookID       : " << one << two << endl;
                cout << "title        : " << one << endl;
                cout << "Author       : " << two << endl;
                cout << "Fine Per Day : " << three << "$" << endl;
                if (tweleve == "0")
                {
                    cout << "The Book Is Borrowable!" << endl;
                }
                else
                    cout << "You Can't Borrow This Book" << endl;
                cout << "      ***************** " << endl;
                if (eleven == EnteredUser && tweleve == "1")
                {
                    k++;
                }
            }
        }
        BookData.close();
    }
    BookData.close();
    BookForNow = k;
    cout << BookNum + 1 << ". Search" << endl;
    cout << "0. Back" << endl;
    int MenuNum;
    cin >> MenuNum;
    ClientBook = MenuNum;

    if (MenuNum == BookNum + 1)
    {
        SearchBooks();
    }
    else if (MenuNum == 0)
    {
        system("cls");
        cout << "** Member Panel **" << endl;
        cout << "Welcome Dear " << EnteredUser << " :)" << endl;
        memberPanel();
    }
    else
    {
        string oneA, twoA, threeA, fourA, fiveA, sixA, sevenA, eightA, nineA, elevenA;
        int tenA;
        int tweleveA;
        int i = 1;
        system("cls");
        cout << "Are You Sure That Your Chosen Book is : " << BookName[ClientBook - 1] << "?"
             << "[Y/N]" << endl;
        char Ans;
        cin >> Ans;
        if (Ans == 'Y' || Ans == 'y')
        {
            cout << "Your Fine Is : ";
            Calculate();
            cout << "$" << endl;
            ifstream LibraryData("data.txt");
            while (LibraryData >> oneA >> twoA >> threeA >> fourA >> fiveA >> sixA >> sevenA >> eightA >> nineA >> tenA >> elevenA >> tweleveA)
            {
                FineInTime = tweleveA;
            }
            LibraryData.close();
            BookData.open("book.txt");
            ofstream TempFiles;
            TempFiles.open("tempfiles.txt");
            while (BookData >> oneA >> twoA >> threeA >> fourA >> fiveA >> sixA >> sevenA >> eightA >> nineA >> tenA >> elevenA >> tweleveA >> type >> FinePaid)
            {
                if (i == MenuNum && tweleveA == 1)
                {
                    cout << "You can't Borrow This Book Please Choose Another one:";
                    Sleep(500);
                    AllBooks();
                }
                else if (i == MenuNum && tweleveA == 0)
                {

                    if (BookLimit >= BookForNow + 1 && FineInTime <= 50)
                    {
                        TempFiles << oneA << " " << twoA << " " << threeA << " "
                                  << day << " " << month << " " << year << " " << sevenA
                                  << " " << eightA << " " << nineA << " " << tenA + 1 << " ";
                        TempFiles << EnteredUser << " " << 1 << " " << type << " " << 1 << endl;
                        cout << "DONE" << endl;
                        cout << "*********************" << endl;
                    }
                    else if (FineInTime >= 51)
                    {
                        cout << "For Continue You Have To Pay Your Fine..." << endl;
                        cout << "We'll Redirect You To The PaymentBar" << endl;
                        Sleep(1000);
                        BookData.close();
                        TempFiles.close();
                        PayFine();
                    }
                    else if (BookLimit < BookForNow + 1)
                    {
                        cout << "You Have To Return Some Book For Borrowing Another Book" << endl;
                        cout << "We'll Redirect You To The BorrowedBooks" << endl;
                        Sleep(1000);
                        BookData.close();
                        TempFiles.close();

                        BorrowedBoks();
                    }
                }
                else
                {
                    TempFiles << oneA << " " << twoA << " " << threeA << " "
                              << fourA << " " << fiveA << " " << sixA << " " << sevenA
                              << " " << eightA << " " << nineA << " " << tenA << " ";
                    TempFiles << elevenA << " " << tweleveA << " " << type << " " << FinePaid << endl;
                }
                i++;
            }
            BookData.close();
            TempFiles.close();
            remove("book.txt");
            rename("tempfiles.txt", "book.txt");
            Sleep(750);
            system("cls");
            cout << endl
                 << "1. View all books" << endl;
            cout << "2. Search in Books" << endl;
            cout << "3. View all borrowed books" << endl;
            cout << "4. Membership renewal" << endl;
            cout << "5. Pay fine" << endl;
            cout << "0. Back" << endl
                 << endl;
            int MenuNum;
            cin >> MenuNum;
            switch (MenuNum)
            {
            case 0:
                main();
                break;
            case 1:
                AllBooks();
                break;
            case 2:
                SearchBooks();
                break;
            case 3:
                BorrowedBoks();
                break;
            case 4:
                MemRenew();
                break;
            case 5:
                PayFine();
                break;
            }
        }
        else
            AllBooks();
    }
}

void AllBooksAdmin()
{
    system("cls");
    cout << "** Book Library Management **";
    cout << endl
         << endl;
    ifstream BookData;
    BookData.open("book.txt");
    string one, two, three, four, five, six, seven, eight, nine, ten, eleven, tweleve;
    int BookNum = 0;
    while (BookData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve >> type >> FinePaid)
    {
        BookNum++;
        cout << "Book Num        : "
             << "00" << BookNum << endl;
        cout << "BookID          : " << one << two << endl;
        cout << "title           : " << one << endl;
        cout << "Author          : " << two << endl;
        cout << "Fine Per Day    : " << three << "$" << endl;
        cout << "Book Genre      : " << type << endl;
        cout << "Last.T Borrowed : " << four << "/" << five << "/" << six << endl;
        cout << "Last.T Returned : " << seven << "/" << eight << "/" << nine << endl;
        cout << "AmountOfBorrow  : " << ten << endl;
        cout << "LastOneBorrowed : " << eleven << endl;
        cout << "      *****************" << endl;
    }
    cout << BookNum + 1 << ". Add Book" << endl;
    cout << BookNum + 2 << ". Modify Book" << endl;
    cout << "0. Back" << endl;
    BookData.close();
    int MenuNum;
    cin >> MenuNum;
    AdminManageBook = MenuNum;
    if (MenuNum == BookNum + 1)
    {
        AddBook();
    }
    else if (MenuNum == BookNum + 2)
    {
        cout << "Enter The Number Of Book You Want To Delete Or Modify" << endl;
        int n;
        cin >> n;
        BookModify(n);
    }
    else if (MenuNum == 0)
    {
        adminPanel();
    }
    else
    {
        AllBooksAdmin();
    }
}
void SearchBooks()
{
    system("cls");
    cout << "For Search In Books Enter The KeyWord You Want:" << endl;
    string KeyWord;
    cin >> KeyWord;
    ifstream BookData;
    BookData.open("book.txt");
    string one, two, three, four, five, six, seven, eight, nine, ten, eleven, tweleve;
    int i = 1;
    while (BookData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve >> type >> FinePaid)
    {
        if (!one.find(KeyWord))
        {
            cout << "Book Num     : "
                 << "00" << i << endl;
            cout << "title        : " << one << endl;
            cout << "Author       : " << two << endl;
            cout << "Fine Per Day : " << three << "$" << endl;
            if (tweleve == "0")
            {
                cout << "The Book Is Borrowable!" << endl;
            }
            else
                cout << "You Can't Borrow This Book" << endl;
            cout << "      ***************** " << endl;
        }
        else if (!two.find(KeyWord))
        {
            cout << "Book Num     : "
                 << "00" << i << endl;
            cout << "title        : " << one << endl;
            cout << "Author       : " << two << endl;
            cout << "Fine Per Day : " << three << "$" << endl;
            if (tweleve == "0")
            {
                cout << "The Book Is Borrowable!" << endl;
            }
            else
                cout << "You Can't Borrow This Book" << endl;
            cout << "      ***************** " << endl;
        }
        i++;
    }
    BookData.close();
    cout << "1. Search Another one" << endl;
    cout << "0. Back" << endl;
    int MenuNum;
    cin >> MenuNum;
    switch (MenuNum)
    {
    case 1:
        SearchBooks();
        break;
    case 0:
        system("cls");
        AllBooks();
        break;
    }
    BookData.close();
}
void BorrowedBoks()
{
    system("cls");
    cout << "Here Is Your Borrowed Books:" << endl;
    cout << endl;
    string one, two, three, four, five, six, seven, eight, nine, ten, eleven, tweleve;
    ifstream BookData;
    BookData.open("book.txt");
    int i = 1;
    int k = 0;
    while (BookData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve >> type >> FinePaid)
    {

        if (eleven == EnteredUser && tweleve == "1")
        {
            cout << "BookNum      : "
                 << "00" << i << endl;
            cout << "title        : " << one << endl;
            cout << "Author       : " << two << endl;
            cout << "Fine Per Day : " << three << "$" << endl;
            cout << "        ***************  " << endl;
            k++;
        }
        i++;
    }
    BookData.close();
    if (k == 0)
    {
        cout << "Your Borrow List Is Empty!" << endl;
    }
    else
        cout << "You have Totally " << k << " books!" << endl;
    cout << "0. Back" << endl
         << endl;
    int MenuNum;
    cin >> MenuNum;
    if (MenuNum == 0)
    {
        system("cls");
        cout << "** Member Panel **" << endl;
        cout << "Welcome Dear " << EnteredUser << " :)" << endl;
        memberPanel();
    }
    else
    {
        system("cls");
        cout << "Returning The Book You Want..." << endl;
        // ifstream BookData;
        BookData.open("book.txt");
        ofstream TempFileForBor;
        TempFileForBor.open("tempfileForBor.txt");
        int j = 1;
        while (BookData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve >> type >> FinePaid)
        {
            if (j == MenuNum && eleven == EnteredUser && FinePaid == 1)
            {
                cout << "You Have To Pay Your Fine First" << endl;
                cout << "Redirecting To Payment Page ..." << endl;
                Sleep(1250);
                BookData.close();
                TempFileForBor.close();
                remove("tempfileForBor.txt");
                PayFine();
            }
            else if (j == MenuNum && eleven == EnteredUser && FinePaid == 0)
            {
                TempFileForBor << one << " " << two << " " << three << " " << four << " " << five << " " << six << " "
                               << day << " " << month << " " << year << " " << ten << " " << eleven << " "
                               << "0"
                               << " " << type << " " << FinePaid << endl;
                cout << "DONE" << endl;
            }
            else
            {
                TempFileForBor << one << " " << two << " " << three << " " << four << " " << five << " " << six << " "
                               << seven << " " << eight << " " << nine << " " << ten << " " << eleven << " "
                               << tweleve << " " << type << " " << FinePaid << endl;
            }
            j++;
        }

        BookData.close();
        TempFileForBor.close();
        remove("book.txt");
        rename("tempfileForBor.txt", "book.txt");
        cout << "1. Pay And See Fine" << endl;
        cout << "0. Back To Your Panel" << endl;
        int SwitchNumber;
        cin >> SwitchNumber;
        switch (SwitchNumber)
        {
        case 1:
            PayFine();
            break;
        case 0:
            system("cls");
            cout << "** Member Panel **" << endl;
            cout << "Welcome Dear " << EnteredUser << " :)" << endl;
            memberPanel();
            break;
        }
    }
}
void MemberChange()
{
    system("cls");
    ifstream libdata("data.txt");
    ofstream tempinmemchange("timc.txt");
    cout << "For change any detalis enter your prefer else enter 0" << endl;
    LibMem deta;
    string one, two, three, four, five, six, seven, eight, nine, ten, eleven, tweleve;
    while (libdata >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve)
    {
        if (one == EnteredUser)
        {
            cout << "Username :(0)" << endl;
            cin >> deta.username;
            if (deta.username != "0")
            {
                one = deta.username;
            }
            cout << "password :(0)" << endl;
            cin >> deta.password;
            if (deta.password != "0")
            {
                five = deta.password;
            }
            cout << "First Name :(0)" << endl;
            cin >> deta.FirstName;
            if (deta.FirstName != "0")
            {
                two = deta.FirstName;
            }
            cout << "Last Name :(0)" << endl;
            cin >> deta.LastName;
            if (deta.LastName != "0")
            {
                three = deta.LastName;
            }
            tempinmemchange << one << " " << two << " " << three << " " << four << " "
                            << five << " " << six << " " << seven << " " << eight
                            << " " << nine << " " << ten << " " << eleven << " " << tweleve << endl;
            cout << "Your Information Changed!" << endl;
            cout << "Login again to confirm.." << endl;
        }
        else
        {
            tempinmemchange << one << " " << two << " " << three << " " << four << " "
                            << five << " " << six << " " << seven << " " << eight
                            << " " << nine << " " << ten << " " << eleven << " " << tweleve << endl;
        }
    }
    libdata.close();
    tempinmemchange.close();
    remove("data.txt");
    rename("timc.txt", "data.txt");
    cout << "1. LogIn"
         << endl;
    int MenuNum;
    cin >> MenuNum;
    switch (MenuNum)
    {
    case 1:
        MemLogin();
        break;
    }
}
void MemList()
{
    system("cls");
    string one, two, three, four, five, six, seven, eight, nine, ten, eleven, tweleve;
    int i = 1;
    ifstream LibraryData("data.txt");
    while (LibraryData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve)
    {
        cout << "User Number     : "
             << "00" << i << endl;
        cout << "Client UserName : " << one << endl;
        cout << "F&L Name        : " << two << " " << three << endl;
        i++;
    }
    LibraryData.close();
    cout << "Enter the number of user that you want to change his/her Accessibility OR choose from the menu" << endl;
    cout << i << ". Delete user " << endl;
    cout << "0. back" << endl;
    int MenuNum;
    cin >> MenuNum;
    if (MenuNum == 0)
    {
        adminPanel();
    }
    else if (MenuNum == i)
    {
        LibraryData.open("data.txt");
        ofstream TempForMemberMod("TempForMemberMod.txt");
        cout << "Enter the Number : ";
        int client;
        cin >> client;
        int k = 1;
        while (LibraryData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve)
        {
            if (k != client)
            {
                TempForMemberMod << one << " " << two << " " << three << " " << four << " "
                                 << five << " " << six << " " << seven << " " << eight
                                 << " " << nine << " " << ten << " " << eleven << " " << tweleve << endl;
            }
            k++;
        }
        cout << "Deleted!" << endl
             << "     *************    " << endl;
        cout << "Please Wait A Moment..."
             << "We're Redirecting You To The Panel" << endl;
        LibraryData.close();
        TempForMemberMod.close();
        remove("data.txt");
        rename("TempForMemberMod.txt", "data.txt");
    }
    else
    {
        LibraryData.open("data.txt");
        ofstream TempHelp("Temphelp.txt");

        int j = 1;
        while (LibraryData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve)
        {
            if (j == MenuNum)
            {
                string BookCountLimited;
                cout << "What Do You Want To Change?" << endl;
                cout << "1. BookCount Limit" << endl;
                cout << "2. EachBook Latency" << endl;
                int ChangeUser;
                cin >> ChangeUser;
                string EachBookLatency;
                cout << "Enter The Limit: ";
                switch (ChangeUser)
                {
                case 1:
                    cin >> BookCountLimited;
                    break;

                case 2:
                    cin >> EachBookLatency;
                    break;
                }
                if (ChangeUser == 1)
                {
                    TempHelp << one << " " << two << " " << three << " " << four << " "
                             << five << " " << six << " " << BookCountLimited << " " << eight
                             << " " << nine << " " << ten << " " << eleven << " " << tweleve << endl;
                    cout << "Please Wait A Moment..."
                         << "We're Redirecting You To The Panel" << endl;
                }
                else
                {
                    TempHelp << one << " " << two << " " << three << " " << four << " "
                             << five << " " << EachBookLatency << " " << seven << " " << eight
                             << " " << nine << " " << ten << " " << eleven << " " << tweleve << endl;
                }
            }
            else
            {
                TempHelp << one << " " << two << " " << three << " " << four << " "
                         << five << " " << six << " " << seven << " " << eight
                         << " " << nine << " " << ten << " " << eleven << " " << tweleve << endl;
            }
            j++;
        }
        LibraryData.close();
        TempHelp.close();
        remove("data.txt");
        rename("Temphelp.txt", "data.txt");
    }
    Sleep(1000);
    adminPanel();
}
void ManageDate()
{
    system("cls");
    cout << "current date is : " << day << "/" << month << "/" << year << endl
         << endl;
    cout << "1. Change Date" << endl;
    cout << "0. Back" << endl;
    cout << endl;
    int MenuNum;
    cin >> MenuNum;

    switch (MenuNum)
    {
    case 1:
        system("cls");
        cout << "Enter New Date (dd mm yyyy) : ";
        cin >> day >> month >> year;
        ManageDate();
        break;

    case 0:
        adminPanel();
        break;
    }
}
void MemRenew()
{
    system("cls");
    ifstream LibraryData;
    LibraryData.open("data.txt");
    string one, two, three, four, five, six, seven, eight, nine, eleven, tweleve;
    int ten;
    string TempDay, TempMonth;
    int TempYear;
    while (LibraryData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve)
    {
        if (one == EnteredUser)
        {
            TempDay = eight;
            TempMonth = nine;
            TempYear = ten;
        }
    }
    cout << "You Have Registered In " << TempDay << "/" << TempMonth << "/" << TempYear;
    cout << endl;
    cout << "So...\nDo You Want To Renew Your MemberShip For a Year as 100$ ?[y/n]";
    char Ans;
    cin >> Ans;

    LibraryData.close();
    LibraryData.open("data.txt");
    if (Ans == 'y' || Ans == 'Y' || Ans == '\n')
    {
        ofstream TempFileForRenew;
        TempFileForRenew.open("tempForRenew.txt");
        while (LibraryData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve)
        {
            if (one == EnteredUser)
            {
                TempFileForRenew << one << " " << two << " " << three << " " << four << " " << five << " " << six << " "
                                 << seven << " " << eight << " " << nine << " " << ten + 1 << " " << eleven << " "
                                 << tweleve << endl;
                cout << "DONE Habibi :)" << endl;
            }
            else
            {
                TempFileForRenew << one << " " << two << " " << three << " " << four << " " << five << " " << six << " "
                                 << seven << " " << eight << " " << nine << " " << ten << " " << eleven << " "
                                 << tweleve << endl;
            }
        }
        LibraryData.close();
        TempFileForRenew.close();
        remove("data.txt");
        rename("tempForRenew.txt", "data.txt");
        Sleep(750);
        system("cls");
        cout << "** Member Panel **" << endl;
        cout << "Welcome Dear " << EnteredUser << " :)" << endl;
        cout << endl
             << "1. View all books" << endl;
        cout << "2. Search in Books" << endl;
        cout << "3. View all borrowed books" << endl;
        cout << "4. Membership renewal" << endl;
        cout << "5. Pay fine" << endl;
        cout << "6. Change Information" << endl;
        cout << "0. Back" << endl
             << endl;
        int MenuNum;
        cin >> MenuNum;
        switch (MenuNum)
        {
        case 0:
            main();
            break;
        case 1:
            AllBooks();
            break;
        case 2:
            SearchBooks();
            break;
        case 3:
            BorrowedBoks();
            break;
        case 4:
            MemRenew();
            break;
        case 5:
            PayFine();
            break;
        case 6:
            MemberChange();
            break;
        }
    }
    else
    {
        system("cls");
        cout << "** Member Panel **" << endl;
        cout << "Welcome Dear " << EnteredUser << " :)" << endl;
        memberPanel();
    }
}
void PayFine()
{
    system("cls");
    cout << "Hello My Friend" << endl
         << "So You Wanna check Your Fine Bill" << endl;
    cout << "Here You Are: ";
    Calculate();
    cout << "$" << endl;
    cout << "For Pay And Accses To All Books Enter [y/n]";
    char Ans;
    cin >> Ans;
    string one, two, three, four, five, six, seven, eight, nine, ten, eleven, tweleve;
    if (Ans == 'y' || Ans == 'Y')
    {
        ifstream LibraryData("data.txt");
        ofstream TempFileForCalculate("TempFileForCalculate.txt");
        cout << "Enter Your CardNumber Below:" << endl;
        long long int CardNum;
        cin >> CardNum;
        while (LibraryData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve)
        {
            if (one == EnteredUser)
            {
                TempFileForCalculate << one << " " << two << " " << three << " " << four << " " << five << " " << six << " "
                                     << seven << " " << eight << " " << nine << " " << ten << " " << eleven << " "
                                     << "0" << endl;
                cout << "Thanks\nHope You Like our Library" << endl;
                cout << "Please Wait A Moment..."
                     << "We're Redirecting You To The Library" << endl;
            }
            else
            {
                TempFileForCalculate << one << " " << two << " " << three << " " << four << " " << five << " " << six << " "
                                     << seven << " " << eight << " " << nine << " " << ten << " " << eleven << " "
                                     << tweleve << endl;
            }
        }
        LibraryData.close();
        TempFileForCalculate.close();
        remove("data.txt");
        rename("TempFileForCalculate.txt", "data.txt");
        ifstream Bookdata("book.txt");
        ofstream TempForShowPaidFine("tfspf.txt");
        while (Bookdata >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve >> type >> FinePaid)
        {
            if (eleven == EnteredUser && FinePaid == 1)
            {
                TempForShowPaidFine << one << " " << two << " " << three << " " << four << " "
                                    << five << " " << six << " " << seven << " " << eight
                                    << " " << nine << " " << ten << " " << eleven << " " << tweleve << " " << type << " " << 0 << endl;
            }
            else
            {
                TempForShowPaidFine << one << " " << two << " " << three << " " << four << " "
                                    << five << " " << six << " " << seven << " " << eight
                                    << " " << nine << " " << ten << " " << eleven << " " << tweleve << " " << type << " " << FinePaid << endl;
            }
        }
        Bookdata.close();
        TempForShowPaidFine.close();
        remove("book.txt");
        rename("tfspf.txt", "book.txt");
    }
    Sleep(1000);
    system("cls");
    cout << "Welcome Back";
    memberPanel();
}
void Calculate()
{
    double FineForUser = 0;
    int Mabda = 0;
    int Maqsad = 0;
    int FineForDays = 0;
    string one, two, seven, eight, nine, ten, eleven, tweleve;
    double three, four, five, six;
    ifstream BookData("book.txt");
    while (BookData >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> tweleve >> type >> FinePaid)
    {
        // How Fine Will Calculate ::
        if (eleven == EnteredUser && FinePaid == 1)
        {
            Mabda = (six * 365) + (five * 30) + four;
            Maqsad = (year * 365) + (month * 30) + day;
            if (Maqsad - Mabda >= 14)
            {
                int FinalDays = Maqsad - Mabda;
                FinalDays -= 14;
                FineForDays += FinalDays;
                FineForUser += (three * FineForDays);
            }
        }
    }
    BookData.close();
    string oneA, twoA, threeA, fourA, fiveA, sixA, sevenA, eightA, nineA, tenA;
    double elevenA, tweleveA;
    ifstream LibraryData("data.txt");
    ofstream TempForFine("tempForFine.txt");
    while (LibraryData >> oneA >> twoA >> threeA >> fourA >> fiveA >> sixA >> sevenA >> eightA >> nineA >> tenA >> elevenA >> tweleveA)
    {
        if (oneA == EnteredUser)
        {
            TempForFine << oneA << " " << twoA << " " << threeA << " "
                        << fourA << " " << fiveA << " " << sixA << " " << sevenA
                        << " " << eightA << " " << nineA << " " << tenA << " ";
            TempForFine << FineForDays + elevenA << " " << FineForUser + tweleveA << endl;
        }
        else
        {
            TempForFine << oneA << " " << twoA << " " << threeA << " "
                        << fourA << " " << fiveA << " " << sixA << " " << sevenA
                        << " " << eightA << " " << nineA << " " << tenA << " ";
            TempForFine << elevenA << " " << tweleveA << endl;
        }
    }
    TempForFine.close();
    LibraryData.close();
    remove("data.txt");
    rename("tempForFine.txt", "data.txt");
    remove("TempForFine.txt");
    cout << FineForUser;
}
void memberPanel()
{
    cout << endl
         << "1. View all books" << endl;
    cout << "2. Search in Books" << endl;
    cout << "3. View all borrowed books" << endl;
    cout << "4. Membership renewal" << endl;
    cout << "5. Pay fine" << endl;
    cout << "6. Change Information" << endl;

    cout << "0. Back" << endl;
    int MenuNum;
    cin >> MenuNum;
    switch (MenuNum)
    {
    case 0:
        main();
        break;
    case 1:
        AllBooks();
        break;
    case 2:
        SearchBooks();
        break;
    case 3:
        BorrowedBoks();
        break;
    case 4:
        MemRenew();
        break;
    case 5:
        PayFine();
        break;
    case 6:
        MemberChange();
        break;
    }
}
void adminPanel()
{
    system("cls");
    cout << "** Manager Panel **\n";
    cout << endl;
    cout << "1. Manage Books" << endl;
    cout << "2. Manage Members" << endl;
    cout << "3. Manage Date" << endl;
    cout << "0. Back" << endl;
    int MenuNum;
    cin >> MenuNum;
    switch (MenuNum)
    {
    case 0:
        main();
        break;
    case 1:
        AllBooksAdmin();
        break;
    case 2:
        MemList();
        break;
    case 3:
        ManageDate();
        break;
    }
}
void MemLogin()
{
    bool IsValid = false;
    system("cls");
    ifstream LibraryData;
    LibraryData.open("data.txt");
    string LogUser;
    string LogText;
    cout << "Enter Your UserName" << endl;
    cin >> LogUser;
    cout << "Enter Your Password" << endl;
    string LogPass;
    EnteredUser = LogUser;
    char pass = ' ';
    while (pass != 13)
    {
        pass = getch();
        if (pass != 13 && pass != 8)
        {
            LogPass += pass;
            cout << "*";
        }
        else if (pass == 13)
        {
            cout << endl;
        }
        else if (pass == 8)
        {
            if (LogPass.length() == 0)
            {
                continue;
            }

            cout << "\b \b";
            int PassLength = LogPass.length();
            LogPass.erase(PassLength - 1, 1);
        }
    }
    string DefUser, DefFName, DefLName, DefPhone, DefPass, eight, nine, ten, eleven;
    double six, seven, twleve;
    while (LibraryData >> DefUser >> DefFName >> DefLName >> DefPhone >> DefPass >> six >> seven >> eight >> nine >> ten >> eleven >> twleve)
    {
        if (LogUser == DefUser && LogPass == DefPass)
        {
            IsValid = true;
            break;
            LatencyLimit = six;
            BookLimit = seven;
            FineInTime = twleve;
        }
    }
    LibraryData.close();
    if (!IsValid)
    {
        system("COLOR 4C");
        cout << "Wrong PassWord Or UserName!!\nTry Again in 1 sec";
        Sleep(1000);
        system("COLOR E0");
        MemLogin();
    }
    else
    {
        system("cls");
        cout << "** Member Panel **" << endl;
        cout << "Welcome Dear " << LogUser << " :)" << endl;
        memberPanel();
    }
}
void MemReg()
{

    system("cls");
    string DefUser, DefPass;
    LibMem Member;
    cout << "Enter Your UserName" << endl;
    cin >> Member.username;
    bool IsMojood = false;
    ifstream LibraryData;
    LibraryData.open("data.txt");
    while (LibraryData >> DefUser)
        if (DefUser == Member.username)
            IsMojood = true;
    if (IsMojood)
    {
        system("COLOR 4C");
        cout << "UserName Is Already Taken";
        Sleep(750);
        system("COLOR E0");
        MemReg();
    }
    else
    {
        LibraryData.close();
        ofstream LibraryData("data.txt", ios::app);
        LibraryData << Member.username << " ";
        cout << "Enter Your FirstName\n";
        cin >> Member.FirstName;
        LibraryData << Member.FirstName << " ";
        cout << "Enter Your LastName\n";
        cin >> Member.LastName;
        LibraryData << Member.LastName << " ";
        cout << "Enter Your Number\n";
        cin >> Member.PhoneNum;
        LibraryData << Member.PhoneNum << " ";
        cout << "Enter Your Password\n";
        char pass = ' ';
        while (pass != 13)
        {
            pass = getch();
            if (pass != 13 && pass != 8)
            {
                Member.password += pass;
                cout << "*";
            }
            else if (pass == 13)
            {
                cout << endl;
            }
            else if (pass == 8)
            {
                if (Member.password.length() == 0)
                {
                    continue;
                }

                cout << "\b \b";
                int PassLength = Member.password.length();
                Member.password.erase(PassLength - 1, 1);
            }
        }
        LibraryData << Member.password << " ";
        LibraryData << 14 << " " << 10 << " ";

        LibraryData << day << " " << month << " " << year << " " << 0 << " " << 0 << endl;
        LibraryData.close();
        cout << "you have registered succesfuly in " << day << "/" << month << "/" << year << endl;
        cout << "1. Member Login" << endl;
        cout << "0. Back" << endl;
        int MenuNum;
        cin >> MenuNum;
        switch (MenuNum)
        {
        case (1):
            MemLogin();
            break;
        case (0):
            main();
            break;
        }
    }
}
void adminLogin()
{
    system("cls");
    string LogUser;
    cout << "Enter Your UserName" << endl;
    cin >> LogUser;
    cout << "Enter Your Password" << endl;
    string LogPass;
    char pass = ' ';
    while (pass != 13)
    {
        pass = getch();
        if (pass != 13 && pass != 8)
        {
            LogPass += pass;
            cout << "*";
        }
        else if (pass == 13)
        {
            cout << endl;
        }
        else if (pass == 8)
        {
            if (LogPass.length() == 0)
            {
                continue;
            }

            cout << "\b \b";
            int PassLength = LogPass.length();
            LogPass.erase(PassLength - 1, 1);
        }
    }
    if (LogPass == "admin" && LogUser == "admin")
    {
        cout << "Welcome Master\n";
        Sleep(500);
        cout << "Loading Panel... 33%";
        Sleep(750);
        system("cls");
        cout << "Loading Panel... 50%";
        Sleep(700);
        system("cls");
        cout << "Loading Panel... 90%";
        Sleep(500);
        system("cls");

        adminPanel();
    }
    else
    {
        system("COLOR 4C");

        cout << "are you sure that you are admin?\n";
        cout << "try again in 1 sec \n";

        Sleep(750);
        system("COLOR E0");
        adminLogin();
    }
}
int main()
{
    system("cls");
    system("COLOR E0");

    int num = 0;
    cout << "** Welcome to our Library **" << endl
         << "\n";
    num++;
    cout << num << ". Member Login" << endl;
    num++;
    cout << num << ". Member Register" << endl;
    num++;
    cout << num << ". Manager Login" << endl;
    cout
        << "0. Exit" << endl
        << "\n";

    int MenuNum;
    cin >> MenuNum;
    switch (MenuNum)
    {
    case 0:
        cout << "Thanks For Visiting ...";
        exit(0);
    case (1):
        MemLogin();
        break;
    case (2):
        MemReg();
        break;
    case (3):
        adminLogin();
        break;
    }
}
