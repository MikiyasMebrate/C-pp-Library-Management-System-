#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

//*******************//
//  Global Functions //
//*******************//
void date();
void HomePage();
void StuLogin();
void StuIDwrite();
void StuPage();
void Bookcat();
void StuBorrow();
void StuReturn();
void StaffBorrow();
void StaffReturn();
void BA();
void CS();
void StaffLogin();
void StaffPage();
void StaffIDwrite();
void libraryanLogin();
void LibrarianPage();
void ADDBook();

//*********************//
//    Global DATE      //
//*********************//
// current date/time based on current system
time_t t = time(NULL);
tm* tPtr = localtime(&t);

const int monthDays[12] = { 31, 59, 90, 120, 151, 181, 212, 243,
273, 304, 334, 365 };   // Helps US to Calculate Two different Dates 
int countLeapYearDays(int d[]) {
	int years = d[2];
	if (d[1] <= 2)
		years--;
	return ((years / 4) - (years / 100) + (years / 400));
}
int countNoOfDays(int date1[], int date2[]) {
	long int dayCount1 = (date1[2] * 365);
	dayCount1 += monthDays[date1[1]];
	dayCount1 += date1[0];
	dayCount1 += countLeapYearDays(date1);
	long int dayCount2 = (date2[2] * 365);
	dayCount2 += monthDays[date2[1]];
	dayCount2 += date2[0];
	dayCount2 += countLeapYearDays(date2);
	return (abs(dayCount1 - dayCount2));
}

//*********************//
//    Global Variables //
//*********************//

string idcheck[12];                                       // List of Student and their Information 
string firstname[12], BorrowedCode[12], BorrowedName[12];
int BorDate[12], Bormon[12], BorYear[12];

string id, finame, StuBorCode, StuBorName;            // TO Identify the user
const int co = 100;

int num[co];
string BookID[co], BookName[co], Aval[co];     // Identifing The avalible Books with their ID, Name, Code , Ava 
string BookNameBorrowed, BookIDBorrowed;   /// Borrowed Books

int line = 0;
string linee;
int csop;

string row[co], rowc[co], rown[co], Avali[co];

int Bookcate;

int borrowchk;
int rowco;

int main()
{
	HomePage();
}

//*********//
// STAFF   //
//*********//

void HomePage()   // Home Page of The Application
{
	date();
	int op;
	cout << "===================|\n";
	cout << "=====HOEM-PAGE=====|\n";
	cout << "1.Student          |\n";
	cout << "2.Staff            |\n";
	cout << "3.Librarian        |\n";
	cout << "4.Exit             |\n";
	cout << "===================|\n";
	cout << "Enter Option: ";

	cin >> op;   // To identify user input

	if (op == 1)
	{
		cout << endl;
		StuLogin();       // To Start Student Login Page
	}
	else if (op == 2) {
		cout << endl;
		StaffLogin();
	}
	else if (op == 3) {
		libraryanLogin();
	}
	else if (op == 4) {
		exit(0);
	}
	else {         // if the user input incorrect character 
		op;
		cout << endl;
		cout << "=========================|\n";
		cout << "Incorrect number input   |\n";
		cout << "1.Return To previous Menu|\n";
		cout << "2.Exit                   |\n";
		cout << "=========================|\n";
		cout << "Enter OPtion: ";
		cin >> op;
		cout << endl;

		if (op == 1) {
			HomePage();   //return to homepage
		}if (op == 2) {
			exit(0);      // exit from the application 
		}
	}
}
void date()
{
	// print various components of tm structure.
	cout << "*************************\n";
	cout << " Current Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
	cout << "*************************\n";
}
void StuLogin()
{
	cout << endl;
	cout << "==============================|\n";
	cout << "======STUDENT-LOGIN-PAGE======|\n";
	cout << "Enter Your ID Number: ";
	cin >> id;                                   //user id
	cout << "Enter Your First Name: ";
	cin >> finame;                              //user name
	cout << endl;

	ifstream check;
	check.open("C:\\Users\\mikiy\\Desktop\\LMS\\StudentTbl2.txt");  //to input Student list 
	if (check)
	{
		for (int count = 0; count <= 11; count++) {  // Student List
			check >> idcheck[count] >> firstname[count] >> BorrowedCode[count] >> BorrowedName[count] >> BorDate[count] >> Bormon[count] >> BorYear[count];
			// cout << idcheck[count] << " " << firstname[count] << " " << BorrowedCode[count] << " " << BorrowedName[count] << " " <<  BorDate[count] << " " << Bormon[count] << " " << BorYear[count] << endl;
		}
		int rop;

		if ((idcheck[0] == id && firstname[0] == finame) || (idcheck[1] == id && firstname[1] == finame) || (idcheck[2] == id && firstname[2] == finame) || (idcheck[3] == id && firstname[3] == finame) || (idcheck[4] == id && firstname[4] == finame) ||
			(idcheck[5] == id && firstname[5] == finame) || (idcheck[6] == id && firstname[6] == finame) || (idcheck[7] == id && firstname[7] == finame) || (idcheck[8] == id && firstname[8] == finame) || (idcheck[9] == id && firstname[9] == finame) ||
			(idcheck[10] == id && firstname[10] == finame) || (idcheck[11] == id && firstname[11] == finame))
			// to check user id and name 
		{
			for (int ass = 0; ass < 12; ass++) {
				if (id == idcheck[ass] && firstname[ass] == finame)    // TO identify who use the system as user 
				{
					StuBorCode = BorrowedCode[ass];
					StuBorName = BorrowedName[ass];
				}
			}
			StuPage();   // if its is correct and it contionu to Student Page 
		}
		else  //for Incorrect ID and Name
		{
			cout << endl;
			cout << "==========================|\n";
			cout << "Incorrect ID or Name      |\n";
			cout << "==========================|\n";
			cout << "1.Return to previous Menu |\n";
			cout << "2.Exit                    |\n";
			cout << "==========================|\n";
			cout << "Enter Option: ";
			cin >> rop;
			cout << endl;

			if (rop == 1) {
				HomePage();
			}if (rop == 2) {
				exit(0);
			}
		}
		check.close();
	}

}
void StuPage()
{
	int sop;  // Student option login 

	cout << "\n";
	cout << "=============================|\n";
	cout << "=======STUDENT-PAGE==========|\n";
	cout << "1.Borrow Book                |\n";
	cout << "2.Return Book                |\n";
	cout << "3.List All Book              |\n";
	cout << "4.Return to previous Menu    |\n";
	cout << "5.Exit                       |\n";
	cout << "=============================|\n";
	cout << "Enter Option: ";
	cin >> sop;

	cout << endl;

	if (sop == 1) {  //TO Borrow book
		StuBorrow();
	}
	else if (sop == 2) {
		StuReturn();
	}
	else if (sop == 3) {
		CS();
		BA();
		cout << endl;
		cout << "1.Return to previous Menu\n";
		cout << "2.Exit";
		cout << "Enter Option: ";

		int opp;
		cin >> opp;
		if (opp == 1)
		{
			StaffPage();
		}
		else if (opp == 2) {
			exit(0);
		}
	}
	else if (sop == 4) {
		HomePage();
	}
	else if (sop == 5) {
		exit(0);
	}

}
void StuBorrow()
{
	ifstream update;
	update.open("C:\\Users\\mikiy\\Desktop\\LMS\\StudentTbl2.txt");
	if (update) {

		for (int count = 0; count < 12; count++) {
			update >> idcheck[count] >> firstname[count] >> BorrowedCode[count] >> BorrowedName[count] >> BorDate[count] >> Bormon[count] >> BorYear[count];
			// cout << idcheck[count] << " " << firstname[count] << " " << BorrowedCode[count] << " " << BorrowedName[count] << " " << BorrowedDate[count] << endl;   // Student List		
			if ((id == idcheck[count]) && (BorrowedCode[count] == "NO") && (BorDate[count] == 0 && Bormon[count] == 0 && BorYear[count] == 0))
			{
				Bookcat();
				
				cout << "\nEnter Book number to Borrow: ";
				cin >> csop;

				for (int k = 0; k < (line - 1); k++) {    // To Determine the Book Can Borrow or not
					if (csop == num[k]) {
						if (Aval[k] == "NOT") {   // If the Book is not Avalibile
							cout << endl;
							cout << "=============================|\n";
							cout << "You can not borrow this Book |\n";
							cout << "=============================|\n";
							int oop; // to exit or return to previous menu
							cout << endl;
							cout << "===============|\n";
							cout << "1.Home Page    |\n";
							cout << "2.Exit         |\n";
							cout << "===============|\n";
							cout << "Enter Option: ";
							cin >> oop;
							if (oop == 1) {
								HomePage();
							}
							else if (oop == 2) {
								exit(0);
							}
						}
						else             // If the Book is Avalibile
						{
							cout << endl;
							cout << "====================================\n";
							cout << "You Borrow: " << BookID[k] << " " << BookName[k]<<"\n\n";
							cout << "Please return the Book before 6 Day,\nBut after 6 days you will be Charged\n";
							cout << "=====================================\n";

							BookIDBorrowed = BookID[k], BookNameBorrowed = BookName[k];
							Bookcate;
							borrowchk = 1;
						
							fstream BAout;
							BAout.open("C:\\Users\\mikiy\\Desktop\\LMS\\BABOOK.txt");

							fstream CSout;
							CSout.open("C:\\Users\\mikiy\\Desktop\\LMS\\CSBOOK.txt");
							if (CSout && Bookcate == 1) {
								Aval[k] = "NOT";
								for (int a = 0; a < k+1; a++) {
									if (a == 0) {
										CSout << row[0] << " " << rowc[0] << " " << rown[0] << " " << Avali[0] << endl;
									}
									CSout << num[a] << " " << BookID[a] << " " << BookName[a] << " " << Aval[a] << endl;
								}
								StuIDwrite();
							} else if (BAout && Bookcate == 2) {
								Aval[k] = "NOT";
								for (int a = 0; a < k+1; a++) {
									if (a == 0) {
										BAout << row[0] << " " << rowc[0] << " " << rown[0] << " " << Avali[0] << endl;
									}
									BAout << num[a] << " " << BookID[a] << " " << BookName[a] << " " << Aval[a] << endl;
								}
								StuIDwrite();
							}
						}
					}
				}
				int oop; // to exit or return to previous menu
	cout << endl;
	cout << "==============|\n";
	cout << "1.Home Page   |\n";
	cout << "2.Exit        |\n";
	cout << "==============|\n";
	cout << "Enter Option: ";
	cin >> oop;
	if (oop == 1) {
		HomePage();
	}
	else if (oop == 2) {
		exit(0);

	}
			}
			else if ((id == idcheck[count]) && (BorrowedCode[count] != "NO")) {    // if the user Borrowed he/she can not borrow a book a again must be return first
				int inc;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
				cout << "!Please first Return the Book that you borrow!\n";
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
				cout << "1.Return to previous Menu                   ||\n";
				cout << "2.Exit                                      ||\n";
				cout << "=============================================\n";
				cout << "Enter Option: ";
				cin >> inc;

				if (inc == 1) {
					StuPage();
				}
				else if (inc == 2) {
					exit(0);
				}
			}
		}
		update.close();
	}
}
void StuReturn()
{
	ifstream update;
	update.open("C:\\Users\\mikiy\\Desktop\\LMS\\StudentTbl2.txt");
	if (update) {

		for (int count = 0; count < 12; count++) {
			update >> idcheck[count] >> firstname[count] >> BorrowedCode[count] >> BorrowedName[count] >> BorDate[count] >> Bormon[count] >> BorYear[count];
			// cout << idcheck[count] << " " << firstname[count] << " " << BorrowedCode[count] << " " << BorrowedName[count] << " "  << BorDate[count] << " " << Bormon[count] << " " <<  BorYear[count] << endl;   // Student List		
			if ((id == idcheck[count]) && (BorrowedCode[count] != "NO"))
			{
				Bookcat();

				cout << "\nEnter Book number to Return: ";
				cin >> csop;

				for (int k = 0; k < (line - 1); k++) {    // To Determine the Book Can return  or not
					if (csop == num[k]) {
						if (Aval[k] == "YES") {   // If the Book is not Avalibile
							cout << endl;
							cout << "======================================|\n";
							cout << "You can not return this Book\nbecause you are not borrowed this book\n";
							cout << "===================================|\n";
							int oop; // to exit or return to previous menu
							cout << endl;
							cout << "===============|\n";
							cout << "1.Home Page    |\n";
							cout << "2.Exit         |\n";
							cout << "===============|\n";
							cout << "Enter Option: ";
							cin >> oop;
							if (oop == 1) {
								HomePage();
							}
							else if (oop == 2) {
								exit(0);
							}
						}
						else             // If the Book is Avalibile
						{
	
							int date1[3] = {BorDate[count], Bormon[count], BorYear[count]};
							int date2[3] = { (tPtr->tm_mday), (tPtr->tm_mon) + 1, (tPtr->tm_year) + 1900 };
							cout << "\nThe number of days you Borrow: " << countNoOfDays(date1, date2) << " days\n";

							if (countNoOfDays(date1, date2) > 5)   // Charge will be  started after 5 day 1.5 each day
							{
								cout << "Your Charge is: " << (countNoOfDays(date1, date2) - 5) * 0.25 << " Birr" << endl;
							}

							cout << endl;
							cout << "====================================\n";
							cout << "You Return: " << BookID[k] << " " << BookName[k] << endl;
							cout << "=====================================\n";

							BookIDBorrowed = BookID[k], BookNameBorrowed = BookName[k];
							Bookcate;
							borrowchk = 2;

							fstream BAout;
							BAout.open("C:\\Users\\mikiy\\Desktop\\LMS\\BABOOK.txt");

							fstream CSout;
							CSout.open("C:\\Users\\mikiy\\Desktop\\LMS\\CSBOOK.txt");

							if (CSout && Bookcate == 1) {
								Aval[k] = "YES";
								for (int a = 0; a < k + 1; a++) {
									if (a == 0) {
										CSout << row[0] << " " << rowc[0] << " " << rown[0] << " " << Avali[0] << endl;
									}
									CSout << num[a] << " " << BookID[a] << " " << BookName[a] << " " << Aval[a] << endl;
								}
								StuIDwrite();
							}
							else if (BAout && Bookcate == 2) {
								Aval[k] = "YES";
								for (int a = 0; a < k + 1; a++) {
									if (a == 0) {
										BAout << row[0] << " " << rowc[0] << " " << rown[0] << " " << Avali[0] << endl;
									}
									BAout << num[a] << " " << BookID[a] << " " << BookName[a] << " " << Aval[a] << endl;
								}
								StuIDwrite();
							}
							int ret;
							cout << "\n*******************\n";
							cout << "1.Previous Menu\n";
							cout << "2. Exit\n";
							cout << "Enter option: ";
							cin >> ret;

							if (ret == 1) {
								cout << endl;
								StuPage();
							}
							else if (ret == 2) {
								exit(0);
							}
							 
						}
					}
				}

			}
			else if ((id == idcheck[count]) && (BorrowedCode[count] == "NO")) {
				int ret;
				cout << "To return a book first you have to borrow\n";
				cout << "1.Previous Menu\n";
				cout << "2. Exit\n";
				cout << "Enter option: ";
				cin >> ret;

				if (ret == 1) {
					cout << endl;
					StuPage();
				}
				else if (ret == 2) {
					exit(0);
				}

			}
		}
	}
}
void StuIDwrite()
{
	BookIDBorrowed; // Book ID That Borrowed 
	BookNameBorrowed; //Book Name 
	id; // Student Id That Login
	finame; // Student Name 
	StuBorCode;  //Student Borrowed Book Code
	StuBorName;  // Student Borrowed Book Name

	ifstream update;
	update.open("C:\\Users\\mikiy\\Desktop\\LMS\\StudentTbl2.txt");
	if (update) {

		for (int count = 0; count < 12; count++) {
			update >> idcheck[count] >> firstname[count] >> BorrowedCode[count] >> BorrowedName[count] >> BorDate[count] >> Bormon[count] >> BorYear[count];   // Student List
			// cout << idcheck[count] << " " << firstname[count] << " " << BorrowedCode[count] << " " << BorrowedName[count] << endl;   // Student List		
		}
		update.close();
	}
	ofstream upda;
	upda.open("C:\\Users\\mikiy\\Desktop\\LMS\\StudentTbl2.txt");
	if (upda && (borrowchk == 1)) {   // Borro
		for (int up = 0; up < 12; up++) {
			if (id == idcheck[up] && finame == firstname[up]) {
				upda << id << " " << finame << " " << BookIDBorrowed << " " << BookNameBorrowed << " "<< (tPtr->tm_mday) << " " << (tPtr->tm_mon) + 1 << " " << (tPtr->tm_year) + 1900 << endl;
			}
			else
			{
				upda << idcheck[up] << " " << firstname[up] << " " << BorrowedCode[up] << " " << BorrowedName[up] << " "<< BorDate[up] << " " << Bormon[up] << " " << BorYear[up] << endl;	
			}
		}
	}
	else if (upda && borrowchk == 2) {   // Return 
		BookIDBorrowed = "NO";
		BookNameBorrowed = "NO";
		for (int up = 0; up < 12; up++) {
			if (id == idcheck[up] && finame == firstname[up]) {
				upda << id << " " << finame << " " << BookIDBorrowed << " " << BookNameBorrowed << " " << 0 << " " << 0 << " " << 0 << endl;
			}
			else
			{
				upda << idcheck[up] << " " << firstname[up] << " " << BorrowedCode[up] << " " << BorrowedName[up] << " " << BorDate[up] << " " << Bormon[up] << " " << BorYear[up] << endl;
			}
		}
	}
}

void Bookcat()
{
	int bkop;

	cout << endl;
	cout << "==============================|\n";
	cout << "=======Book-Categories========|\n";
	cout << "1.Computer Science            |\n";
	cout << "2.Business Administration     |\n";
	cout << "3.Previous Menu               |\n";
	cout << "4.Exit                        |\n";
	cout << "==============================|\n";
	cout << "Enter Option: ";

	cin >> bkop;    //to identify options of Book Categories 
	if (bkop == 1) {
		CS();
	}
	else if (bkop == 2) {
		BA();
	}
	else if (bkop == 3) {
		StuPage();
	}
	else if (bkop == 4) {
		exit(0);
	}
	else {   //for incorrect number input 
		bkop;
		cout << endl;
		cout << "============================|\n";
		cout << "Incorrect number input      |\n";
		cout << "============================|\n";
		cout << "1.Return To previous Menu   |\n";
		cout << "2.Exit                      |\n";
		cout << "============================|\n";
		cout << "Enter OPtion: ";
		cin >> bkop;
		if (bkop == 1) {
			StuPage();
		}
		else if (bkop == 2) {
			exit(0);
		}
	}
}
void CS()
{
	cout << endl;
	cout << "==================================|\n";
	cout << "======COMPUTER-SCIENCE-BOOKS======|\n";
	cout << "==================================|\n";
	line = 0;

	ifstream CScount;
	CScount.open("C:\\Users\\mikiy\\Desktop\\LMS\\CSBOOK.txt");  // Book Lists counter

	if (CScount)
	{
		while (getline(CScount, linee))
		{
			line++;
		}
		CScount.close();
	}
	int const rowco = (line-1); // Number of Rows in file list 
	
	fstream CS;
	CS.open("C:\\Users\\mikiy\\Desktop\\LMS\\CSBOOK.txt");  // Book Lists 

	if (CS)
	{
		for (int i = 0; i < rowco; i++) {
			if (i == 0) {
				CS >> row[0] >> rowc[0] >> rown[0] >> Avali[0];

				cout << "====================================================\n";
				cout << setw(2) << row[0] << "|" << left << setw(10) << rowc[0] << "|" << left << setw(25) << rown[0] << "|" << left << setw(8) << Avali[0] << endl;
				cout << "====================================================\n";
			}
			CS >> num[i] >> BookID[i] >> BookName[i] >> Aval[i];
			cout << setw(2) << num[i] << "|" << left << setw(10) << BookID[i] << "|" << left << setw(25) << BookName[i] << "|" << setw(8) << Aval[i] << endl;
		}
	}
	Bookcate = 1;
}
void BA()
{
	cout <<"\n\n";
	cout << "=========================================|\n";
	cout << "======BUSINESS-ADMINISTRATION-BOOKS======|\n";
	cout << "=========================================|\n";
	line = 0;

	ifstream BAcount;
	BAcount.open("C:\\Users\\mikiy\\Desktop\\LMS\\BABOOK.txt");  // Book Lists counter

	if (BAcount)
	{
		while (getline(BAcount, linee))
		{
			line++;
		}
		BAcount.close();
	}
	int const rowco = (line - 1);

	fstream BA;
	BA.open("C:\\Users\\mikiy\\Desktop\\LMS\\BABOOK.txt");  // Book Lists 

	if (BA)
	{
		for (int i = 0; i < (rowco); i++) {
			if (i == 0) {
				BA >> row[0] >> rowc[0] >> rown[0] >> Avali[0];

				cout << "====================================================\n";
				cout << setw(2) << row[0] << "|" << left << setw(10) << rowc[0] << "|" << left << setw(25) << rown[0] << "|" << left << setw(8) << Avali[0] << endl;
				cout << "====================================================\n";
			}
			BA >> num[i] >> BookID[i] >> BookName[i] >> Aval[i];
			cout << setw(2) << num[i] << "|" << left << setw(10) << BookID[i] << "|" << left << setw(25) << BookName[i] << "|" << setw(8) << Aval[i] << endl;
		}
	}
	
	Bookcate = 2; 
}

//*********//
// STAFF   //
//*********//

void StaffLogin() 
{
	cout << endl;
	cout << "==============================|\n";
	cout << "======STAFF-LOGIN-PAGE======|\n";
	cout << "Enter Your ID Number: ";
	cin >> id;                                   //user id
	cout << "Enter Your First Name: ";
	cin >> finame;                              //user name
	cout << endl;

	ifstream check;
	check.open("C:\\Users\\mikiy\\Desktop\\LMS\\StaffTbl.txt");  //to input Student list 
	if (check)
	{
		for (int count = 0; count <= 11; count++) {
			check >> idcheck[count] >> firstname[count] >> BorrowedCode[count] >> BorrowedName[count] >> BorDate[count] >> Bormon[count] >> BorYear[count];
		}
		int rop;

		if ((idcheck[0] == id && firstname[0] == finame) || (idcheck[1] == id && firstname[1] == finame) || (idcheck[2] == id && firstname[2] == finame) || (idcheck[3] == id && firstname[3] == finame) || (idcheck[4] == id && firstname[4] == finame) ||
			(idcheck[5] == id && firstname[5] == finame) || (idcheck[6] == id && firstname[6] == finame) || (idcheck[7] == id && firstname[7] == finame) || (idcheck[8] == id && firstname[8] == finame) || (idcheck[9] == id && firstname[9] == finame) ||
			(idcheck[10] == id && firstname[10] == finame) || (idcheck[11] == id && firstname[11] == finame))
		{
			for (int ass = 0; ass < 12; ass++) {
				if (id == idcheck[ass] && firstname[ass] == finame)    // TO identify who use the system as user 
				{
					StuBorCode = BorrowedCode[ass];
					StuBorName = BorrowedName[ass];
				}
			}
			 StaffPage();   // if it is correct and it contionu to Student Page 
		}
		else  //for Incorrect ID and Name
		{
			cout << endl;
			cout << "==========================|\n";
			cout << "Incorrect ID or Name      |\n";
			cout << "==========================|\n";
			cout << "1.Return to previous Menu |\n";
			cout << "2.Exit                    |\n";
			cout << "==========================|\n";
			cout << "Enter Option: ";
			cin >> rop;
			cout << endl;

			if (rop == 1) {
				HomePage();
			}if (rop == 2) {
				exit(0);
			}
		}
		check.close();
	}
}
void StaffPage()
{
	int sop;  // Student option login 

	cout << "\n";
	cout << "=============================|\n";
	cout << "=======STAFF-PAGE==========|\n";
	cout << "1.Borrow Book                |\n";
	cout << "2.Return Book                |\n";
	cout << "3.List All Book              |\n";
	cout << "4.Return to previous Menu    |\n";
	cout << "5.Exit                       |\n";
	cout << "=============================|\n";
	cout << "Enter Option: ";
	cin >> sop;

	cout << endl;

	if (sop == 1) {  //TO Borrow book
		StaffBorrow();
	}
	else if (sop == 2) {
		StaffReturn();
	}
	else if (sop == 3) {
		CS();
		BA();
		cout << endl;
		cout << "1.Return to previous Menu\n";
		cout << "2.Exit";
		int opp;
		cin >> opp;
		if (opp == 1)
		{
			StaffPage();
		}
		else if (opp == 2) {
			exit(0);
		}
	}
	else if (sop == 4) {
		HomePage();
	}
	else if (sop == 5) {
		exit(0);
	}
}
void StaffBorrow()
{
	ifstream update;
	update.open("C:\\Users\\mikiy\\Desktop\\LMS\\StaffTbl.txt");
	if (update) {

		for (int count = 0; count < 12; count++) {
			update >> idcheck[count] >> firstname[count] >> BorrowedCode[count] >> BorrowedName[count] >> BorDate[count] >> Bormon[count] >> BorYear[count];
			// cout << idcheck[count] << " " << firstname[count] << " " << BorrowedCode[count] << " " << BorrowedName[count] << " " << BorrowedDate[count] << endl;   // Student List		
			if ((id == idcheck[count]) && (BorrowedCode[count] == "NO") && (BorDate[count] == 0 && Bormon[count] == 0 && BorYear[count] == 0))
			{
				Bookcat();

				cout << "\nEnter Book number to Borrow: ";
				cin >> csop;

				for (int k = 0; k < (line - 1); k++) {    // To Determine the Book Can Borrow or not
					if (csop == num[k]) {
						if (Aval[k] == "NOT") {   // If the Book is not Avalibile
							cout << endl;
							cout << "=============================|\n";
							cout << "You can not borrow this Book |\n";
							cout << "=============================|\n";
							int oop; // to exit or return to previous menu
							cout << endl;
							cout << "===============|\n";
							cout << "1.Home Page    |\n";
							cout << "2.Exit         |\n";
							cout << "===============|\n";
							cout << "Enter Option: ";
							cin >> oop;
							if (oop == 1) {
								HomePage();
							}
							else if (oop == 2) {
								exit(0);
							}
						}
						else             // If the Book is Avalibile
						{
							cout << endl;
							cout << "====================================\n";
							cout << "You Borrow: " << BookID[k] << " " << BookName[k] <<"\n\n";
							cout << "Please return the Book before 10 Day,\nBut after 10 days you will be Charged\n";
							cout << "=====================================\n";

							BookIDBorrowed = BookID[k], BookNameBorrowed = BookName[k];
							Bookcate;
							borrowchk = 1;

							fstream BAout;
							BAout.open("C:\\Users\\mikiy\\Desktop\\LMS\\BABOOK.txt");

							fstream CSout;
							CSout.open("C:\\Users\\mikiy\\Desktop\\LMS\\CSBOOK.txt");
							if (CSout && Bookcate == 1) {
								Aval[k] = "NOT";
								for (int a = 0; a < k + 1; a++) {
									if (a == 0) {
										CSout << row[0] << " " << rowc[0] << " " << rown[0] << " " << Avali[0] << endl;
									}
									CSout << num[a] << " " << BookID[a] << " " << BookName[a] << " " << Aval[a] << endl;
								}
								StaffIDwrite();
							}
							else if (BAout && Bookcate == 2) {
								Aval[k] = "NOT";
								for (int a = 0; a < k + 1; a++) {
									if (a == 0) {
										BAout << row[0] << " " << rowc[0] << " " << rown[0] << " " << Avali[0] << endl;
									}
									BAout << num[a] << " " << BookID[a] << " " << BookName[a] << " " << Aval[a] << endl;
								}
								StaffIDwrite();
							}
						}
					}
				}
				int oop; // to exit or return to previous menu
				cout << endl;
				cout << "==============|\n";
				cout << "1.Home Page   |\n";
				cout << "2.Exit        |\n";
				cout << "==============|\n";
				cout << "Enter Option: ";
				cin >> oop;
				if (oop == 1) {
					HomePage();
				}
				else if (oop == 2) {
					exit(0);

				}
			}
			else if ((id == idcheck[count]) && (BorrowedCode[count] != "NO")) {    // if the user Borrowed he/she can not borrow a book a again must be return first
				int inc;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
				cout << "!Please first Return the Book that you borrow!\n";
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
				cout << "1.Return to previous Menu                   ||\n";
				cout << "2.Exit                                      ||\n";
				cout << "=============================================\n";
				cout << "Enter Option: ";
				cin >> inc;

				if (inc == 1) {
					StaffPage();
				}
				else if (inc == 2) {
					exit(0);
				}
			}
		}
		update.close();
	}
}
void StaffReturn()
{
	ifstream update;
	update.open("C:\\Users\\mikiy\\Desktop\\LMS\\StaffTbl.txt");
	if (update) {

		for (int count = 0; count < 12; count++) {
			update >> idcheck[count] >> firstname[count] >> BorrowedCode[count] >> BorrowedName[count] >> BorDate[count] >> Bormon[count] >> BorYear[count];
			// cout << idcheck[count] << " " << firstname[count] << " " << BorrowedCode[count] << " " << BorrowedName[count] << " "  << BorDate[count] << " " << Bormon[count] << " " <<  BorYear[count] << endl;   // Student List		
			if ((id == idcheck[count]) && (BorrowedCode[count] != "NO"))
			{
				Bookcat();

				cout << "\nEnter Book number to Return: ";
				cin >> csop;

				for (int k = 0; k < (line - 1); k++) {    // To Determine the Book Can return  or not
					if (csop == num[k]) {
						if (Aval[k] == "YES") {   // If the Book is not Avalibile
							cout << endl;
							cout << "======================================|\n";
							cout << "You can not return this Book\nbecause you are not borrowed this book\n";
							cout << "===================================|\n";
							int oop; // to exit or return to previous menu
							cout << endl;
							cout << "===============|\n";
							cout << "1.Home Page    |\n";
							cout << "2.Exit         |\n";
							cout << "===============|\n";
							cout << "Enter Option: ";
							cin >> oop;
							if (oop == 1) {
								HomePage();
							}
							else if (oop == 2) {
								exit(0);
							}
						}
						else             // If the Book is Avalibile
						{
							int date1[3] = { BorDate[count], Bormon[count], BorYear[count] };
							int date2[3] = { (tPtr->tm_mday), (tPtr->tm_mon) + 1, (tPtr->tm_year) + 1900 };
							cout << "\nThe number of days you Borrow: " << countNoOfDays(date1, date2) << " days\n";

							if (countNoOfDays(date1, date2) > 10)   // Charge will be  started after 5 day 1.5 each day
							{
								cout << "Your Charge is: " << (countNoOfDays(date1, date2) - 10) * 0.25 << " Birr" << endl;
							}

							cout << endl;
							cout << "====================================\n";
							cout << "You Return: " << BookID[k] << " " << BookName[k] << endl;
							cout << "=====================================\n";

							BookIDBorrowed = BookID[k], BookNameBorrowed = BookName[k];
							Bookcate;
							borrowchk = 2;

							fstream BAout;
							BAout.open("C:\\Users\\mikiy\\Desktop\\LMS\\BABOOK.txt");

							fstream CSout;
							CSout.open("C:\\Users\\mikiy\\Desktop\\LMS\\CSBOOK.txt");

							if (CSout && Bookcate == 1) {
								Aval[k] = "YES";
								for (int a = 0; a < k + 1; a++) {
									if (a == 0) {
										CSout << row[0] << " " << rowc[0] << " " << rown[0] << " " << Avali[0] << endl;
									}
									CSout << num[a] << " " << BookID[a] << " " << BookName[a] << " " << Aval[a] << endl;
								}
								StaffIDwrite();
							}
							else if (BAout && Bookcate == 2) {
								Aval[k] = "YES";
								for (int a = 0; a < k + 1; a++) {
									if (a == 0) {
										BAout << row[0] << " " << rowc[0] << " " << rown[0] << " " << Avali[0] << endl;
									}
									BAout << num[a] << " " << BookID[a] << " " << BookName[a] << " " << Aval[a] << endl;
								}
								StaffIDwrite();
							}
							int ret;
							cout << "\n*******************\n";
							cout << "1.Previous Menu\n";
							cout << "2. Exit\n";
							cout << "Enter option: ";
							cin >> ret;

							if (ret == 1) {
								cout << endl;
								StaffPage();
							}
							else if (ret == 2) {
								exit(0);
							}

						}
					}
				}

			}
			else if ((id == idcheck[count]) && (BorrowedCode[count] == "NO")) {
				int ret;
				cout << "To return a book first you have to borrow\n";
				cout << "1.Previous Menu\n";
				cout << "2. Exit\n";
				cout << "Enter option: ";
				cin >> ret;

				if (ret == 1) {
					cout << endl;
					StaffPage();
				}
				else if (ret == 2) {
					exit(0);
				}
			}
		}
	}
}
void StaffIDwrite()
{
	ifstream update;
	update.open("C:\\Users\\mikiy\\Desktop\\LMS\\StaffTbl.txt");
	if (update) {

		for (int count = 0; count < 12; count++) {
			update >> idcheck[count] >> firstname[count] >> BorrowedCode[count] >> BorrowedName[count] >> BorDate[count] >> Bormon[count] >> BorYear[count];   // Student List
			// cout << idcheck[count] << " " << firstname[count] << " " << BorrowedCode[count] << " " << BorrowedName[count] << endl;   // Student List		
		}
		update.close();
	}

	ofstream upda;
	upda.open("C:\\Users\\mikiy\\Desktop\\LMS\\StaffTbl.txt");
	if (upda && (borrowchk == 1)) {   // Borro
		for (int up = 0; up < 12; up++) {
			if (id == idcheck[up] && finame == firstname[up]) {
				upda << id << " " << finame << " " << BookIDBorrowed << " " << BookNameBorrowed << " " << (tPtr->tm_mday) << " " << (tPtr->tm_mon) + 1 << " " << (tPtr->tm_year) + 1900 << endl;
			}
			else
			{
				upda << idcheck[up] << " " << firstname[up] << " " << BorrowedCode[up] << " " << BorrowedName[up] << " " << BorDate[up] << " " << Bormon[up] << " " << BorYear[up] << endl;

			}
		}
	}
	else if (upda && borrowchk == 2) {   // Return 
		BookIDBorrowed = "NO";
		BookNameBorrowed = "NO";
		for (int up = 0; up < 12; up++) {
			if (id == idcheck[up] && finame == firstname[up]) {
				upda << id << " " << finame << " " << BookIDBorrowed << " " << BookNameBorrowed << " " << 0 << " " << 0 << " " << 0 << endl;
			}
			else
			{
				upda << idcheck[up] << " " << firstname[up] << " " << BorrowedCode[up] << " " << BorrowedName[up] << " " << BorDate[up] << " " << Bormon[up] << " " << BorYear[up] << endl;
			}
		}
	}
}

//*************//
//  LIBRARIAN  //
//*************//

void libraryanLogin() {                      //THIS FUNCTION IS THE LOGINPAGE OF A LIBRARIAN
	
	cout << endl;
	cout << "======LIBRARIAN-LOGIN-PAGE======|\n\n";
	string libId;
	cout << "Enter your ID: ";
	cin >> libId;

	if (libId == "ACT/LIB/01/21") {            //THIS IF FUNCTION PROCIDES IF THE USER INPUT A CORRECT ID
		cout << "\n========LIBRARIAN-LOGIN-PAGE========\n";
		cout << "********Welcome ABEBE WORKU********\nPlease insert your password: ";
		string passLIB;
		string passcheck;
		cin >> passLIB;

		ifstream check;
		check.open("C:\\Users\\mikiy\\Desktop\\LMS\\LibPass.txt"); // TO IDENTIFY USER PASSWORD
		check >> passcheck;

		if (passcheck == passLIB) {       //THIS IF FUNCTION PROCIDES IF THE USER INPUT A CORRECT ID AND PASSWORD
			cout << endl;
			LibrarianPage();
			
		} else {
			cout << "\n==================";
			cout << "\nWRONG PASSWORD\n";
			cout << "==================\n";
			int cho;
			cout << "1.MAIN MENU \n2.LIBRARIAN MENU\n3.EXIT\n";
			cout << "Enter Option: ";
			cin >> cho;
			if (cho == 1) {
				HomePage();
			}
			else if (cho == 2) {
				libraryanLogin();
			}
			else if (cho == 3) {
				exit(0);
			}
			else {
				exit(0);
			}
		}
	} else {

		cout << "\n============\n";
		cout << "Invalid ID" << endl;
		cout << "============\n";
		int cho2;
		cout << "1.MAIN MENU \n2.LIBRARIAN MENU\n3.EXIT\n";
		cout << "Enter option: ";
		cin >> cho2;

		if (cho2 == 1) {
			HomePage();
		}
		else if (cho2 == 2) {
			libraryanLogin();
		}
		else if (cho2 == 3) {
			exit(0);
		}
		else {
			exit(0);
		}
	}
}
void LibrarianPage()
{
	cout << "\n=================================\n";
	cout << "WHAT WOULD YOU LIKE TO DO" << endl;
	cout << "=================================\n";
	cout << "1.ADD A BOOK \n2.SEE AVALAIBLE BOOKS FOR CS\n3.SEE AVALAIBLE BOOKS FOR BA\n4.CHANGE PASSWORD\n5.List of Student\n6.List of Staff\n7.Exit\n";
	cout << "=================================\n";
	cout << "Enter Option: ";

	int opfrlibr;
	cin >> opfrlibr;
	if (opfrlibr == 1) {            //THIS IF FUNCTION PROCIDES IF THE USER WANTS TO ADD A BOOK
		cout << endl;
		ADDBook();
	}
	else if (opfrlibr == 2) {
		CS();

		int opcs;
		cout << endl;
		cout << "=================\n";
		cout << "1.Previous Menu\n";
		cout << "2.Exit\n";
		cout << "=================\n";
		cout << "Enter Option: ";
		cin >> opcs;

		if (opcs == 1)
		{
			LibrarianPage();
		}
		else if (opcs == 2)
		{
			exit(0);
		}
		else {
			exit(0);
		}
	}
	else if (opfrlibr == 3) {
		BA();
		int opba;

		cout << endl;
		cout << "=================\n";
		cout << "1.Previous Menu\n";
		cout << "2.Exit\n";
		cout << "=================\n";
		cout << "Enter Option: ";
		cin >> opba; 

		if (opba == 1)
		{
			LibrarianPage();
		}
		else if (opba == 2)
		{
			exit(0);
		}
		else {
			exit(0);
		}
	}
	else if (opfrlibr == 4) {

		string newpassword;
		string confirmNP;
		cout << "ENTER YOUR NEW PASSWORD: " ;
		cin >> newpassword;
		cout << "CONFIRM YOUR  PASSWORD: ";
		cin >> confirmNP;

		if (newpassword == confirmNP) {
			ofstream cpass;
			cpass.open("C:\\Users\\mikiy\\Desktop\\LMS\\LibPass.txt");
			if (cpass) {
				cpass << confirmNP;
			}
			cpass.close();

			cout << "\n============================================\n";
			cout << "YOUR PASSWORD HAS BEEN CHANGED SUCSSESSEFULLY" << endl;
			cout << "============================================\n";

			int opba;

			cout << endl;
			cout << "=================\n";
			cout << "1.Previous Menu\n";
			cout << "2.Exit\n";
			cout << "=================\n";
			cout << "Enter Option: ";
			cin >> opba;

			if (opba == 1)
			{
				LibrarianPage();
			}
			else if (opba == 2)
			{
				exit(0);
			}
			else {
				exit(0);
			}
		} else {
			cout << "\n====================================\n";
			cout << "THE PASSWORD YOU ENTERD DOESNT MUCH" << endl;
			cout << "====================================\n";
			int cho;
			cout << "1.MAIN MENU \n2.LIBRARIAN MENU\n3.CLOSE PROGRAM\n";
			cout << "Enter OPtion: ";
			cin >> cho;

			if (cho == 1) {
				HomePage();
			}
			else if (cho == 2) {
				libraryanLogin();
			}
			else if (cho == 3) {
				exit(0);
			}
			else {
				exit(0);
			}
		}
	}
	else if (opfrlibr == 5)
	{

		ifstream check;
		check.open("C:\\Users\\mikiy\\Desktop\\LMS\\StudentTbl2.txt");  //Student list 
		if (check)
		{ 
			cout << "=====================================================================================\n";
			cout<<left << setw(14) << "ID NUMBER" << "|" << left << setw(10) << "Name" << "|" << left << setw(8) << "Book-Code" << "|" << left << setw(20) << "Book-Name" << "|" <<
			setw(8) << "Bor-Date" << "|" << left << setw(8) << "Bor-Month" << "|" << left << setw(8) << "Bor-Year" << endl;
			cout << "=====================================================================================\n";
			for (int count = 0; count <= 11; count++) {
				check >> idcheck[count] >> firstname[count] >> BorrowedCode[count] >> BorrowedName[count] >> BorDate[count] >> Bormon[count] >> BorYear[count];
				cout << left <<setw(14) << idcheck[count] << "|" << left << setw(10) << firstname[count] << "|" << left << setw(9) << BorrowedCode[count] << "|" << left << setw(20) << BorrowedName[count] <<
				 "|" << setw(8) << BorDate[count] << "|" << setw(9) << Bormon[count] << "|" << setw(8) << BorYear[count] << endl;
			}
		}
		int cho;
		cout << "\n1.MAIN MENU \n2.LIBRARIAN MENU\n3.EXIT\n";
		cout << "Enter Option: ";
		cin >> cho;
		if (cho == 1) {
			HomePage();
		}
		else if (cho == 2) {
			LibrarianPage();
		}
		else if (cho == 3) {
			exit(0);
		}
		else {
			exit(0);
		}
	}
	else if (opfrlibr == 6) {

	ifstream check;
	check.open("C:\\Users\\mikiy\\Desktop\\LMS\\StaffTbl.txt");  //STAFF list 
	if (check)
	{
		cout << "=====================================================================================\n";
		cout << left << setw(14) << "ID NUMBER" << "|" << left << setw(10) << "Name" << "|" << left << setw(8) << "Book-Code" << "|" << left << setw(20) << "Book-Name" << "|" <<
			setw(8) << "Bor-Date" << "|" << left << setw(8) << "Bor-Month" << "|" << left << setw(8) << "Bor-Year" << endl;
		cout << "=====================================================================================\n";
		for (int count = 0; count <= 11; count++) {
			check >> idcheck[count] >> firstname[count] >> BorrowedCode[count] >> BorrowedName[count] >> BorDate[count] >> Bormon[count] >> BorYear[count];
			cout << left << setw(14) << idcheck[count] << "|" << left << setw(10) << firstname[count] << "|" << left << setw(9) << BorrowedCode[count] << "|" << left << setw(20) << BorrowedName[count] <<
				"|" << setw(8) << BorDate[count] << "|" << setw(9) << Bormon[count] << "|" << setw(8) << BorYear[count] << endl;
		}
	}
	int cho;
	cout << "\n1.MAIN MENU \n2.LIBRARIAN MENU\n3.EXIT\n";
	cout << "Enter Option: ";
	cin >> cho;
	if (cho == 1) {
		HomePage();
	}
	else if (cho == 2) {
		LibrarianPage();
	}
	else if (cho == 3) {
		exit(0);
	}
	else {
		exit(0);
	}
	}
	else if (opfrlibr == 7) {
	        exit(0);
		} else {
		cout << "Invalid option";
		int cho;
		cout << "1.MAIN MENU \n2.LIBRARIAN MENU\n3.EXIT\n";
		cout << "Enter Option: ";
		cin >> cho;
		if (cho == 1) {
			HomePage();
		}
		else if (cho == 2) {
			libraryanLogin();
		}
		else if (cho == 3) {
			exit(0);
		}
		else {
			exit(0);
		}
	}
}
void ADDBook()
{
	cout << "==============================================\n";
	cout << "To what department do you want to add the book\n";
	cout << "==========================================\n";
	cout << "1.For Computer sceince\n2.For  Bunsiness Administration\n3.Previous Menu\n4.Exit\n";
	cout << "==============================================\n";
	cout << "Enter Option: ";
	int depopt;
	cin >> depopt;

	if (depopt == 1) {        //THIS IF FUNCTION PROCIDES IF THE USER WANTS TO ADD A BOOK IN CS DEPARTMENT
		string newbookCS;
		string newbookCScc;
		cout << "Enter the CourseName of the book: ";
		cin >> newbookCS;
		cout << "Enter the CourseName of the book respectively: ";
		cin >> newbookCScc;

		ofstream csbfile;
		ifstream csbfile1("C:\\Users\\mikiy\\Desktop\\LMS\\CSBOOK.txt", ios::app);

		std::size_t lines_count = 0;   /// 
		std::string line;

		if (csbfile) {
		while (getline(csbfile1, line))
			++lines_count;      //THIS FUNCTION COUNTS THE NUMBER OF LINES IN THE CSBOOK FILE
		    csbfile.open("C:\\Users\\mikiy\\Desktop\\LMS\\CSBOOK.txt", ios::app);
		    csbfile << endl << lines_count++ << " " << newbookCScc << "  " << newbookCS << " YES";
		csbfile.close();
		}

		cout << "\n\n";
		cout << "YOUR COMMAND WAS SUCCSSES FULL" << endl;

		int opl;
		cout << "1.Home Page\n";
		cout << "2.Previous Menu\n";
		cout << "3.Exit\n";
		cout << "Enter option: ";
		cin >> opl;

		if (opl == 1)
		{
			HomePage();
		}
		else if (opl == 2)
		{
			ADDBook();
		}
		else if (opl == 3)
		{
			exit(0);
		}
		else {
			exit(0);
		}

		
	}
	else if (depopt == 2) {     //THIS IF FUNCTION PROCIDES IF THE USER WANTS TO ADD A BOOK IN BA DEPARTMENT
		
		string newbookBA;
		string newbookBAcc;
		cout << "Enter the CourseName of the book: ";
		cin >> newbookBA;
		cout << "Enter the CourseCode of the book respectively: ";
		cin >> newbookBAcc;

		ofstream csbfile;
		ifstream csbfile1("C:\\Users\\mikiy\\Desktop\\LMS\\BABOOK.txt", ios::app);
		std::size_t lines_count = 0;
		std::string line;

		if (csbfile) {
		while (getline(csbfile1, line))
			++lines_count;      //THIS FUNCTION COUNTS THE NUMBER OF LINES IN THE BABOOK FILE
		csbfile.open("C:\\Users\\mikiy\\Desktop\\LMS\\BABOOK.txt", ios::app);
		csbfile << endl << lines_count++ << " " << newbookBAcc << " " << newbookBA << " YES";
		csbfile.close();
		}
		cout << "\n\n";
		cout << "YOUR COMMAND WAS SUCCSSES FULL" << endl;

		int opl;
		cout << "1.Home Page\n";
		cout << "2.Previous Menu\n";
		cout << "3.Exit\n";
		cout << "Enter option: ";
		cin >> opl;

		if (opl == 1)
		{
			HomePage();
		}
		else if (opl == 2)
		{
			ADDBook();
		}
		else if (opl == 3)
		{
			exit(0);
		}
		else {
			exit(0);
		}
	}
	else if (depopt == 3)
	{
		LibrarianPage();
	}
	else if (depopt == 4) {
		exit(0);
	}
	else {
		cout << "Invalid option\n";

		int cho;
		cout << "1.MAIN MENU \n2.LIBRARIAN MENU\n3.CLOSE PROGRAM\n";
		cout << "Enter Option: ";
		cin >> cho;
		if (cho == 1) {
			HomePage();
		}
		else if (cho == 2) {
			libraryanLogin();
		}
		else if (cho == 3) {
			exit(0);
		}
		else {
			exit(0);
		}
	}
}
