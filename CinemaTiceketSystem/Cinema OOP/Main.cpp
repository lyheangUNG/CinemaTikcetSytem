#include<iostream>
#include <algorithm>
#include<string>
#include "Child.h"
#include "Student.h"
#include"Room.h"
#include "TicketManagement.h"
const int MaxClassic = 30, MaxVIP = 10;
using namespace std;
unsigned int issueDay, issueMonth, issueYear;
unsigned int age, room, ticketClass, ticketType, seatNum;
char yesOrNo;
vector<string> movieTitle = {"Avengers", "Iron Man", "Tom and Jerry", "Die Hard 3"};
Room *room1 = new Room(MaxClassic, MaxVIP);
Room *room2 = new Room(MaxClassic, MaxVIP);
Room *room3 = new Room(MaxClassic, MaxVIP);
Room *room4 = new Room(MaxClassic, MaxVIP);


template<class T>
void inputErrorPrevention(T *menuOption) {
	bool check_fail;
	do {
		cin >> *menuOption;
		check_fail = cin.fail();
		if (check_fail) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl;
			cout << "\033[1;33mWarning!\033[0m" << endl;
			cout << "Please enter number only" << endl;
			cout << "========================" << endl;
			cout << "Please reinput: ";
		}
	} while (check_fail == true);
}


bool checkValidDate(int day1, int month1, int year1) {
	switch (month1) {
	case 1: {
		if (day1 > 31 || day1 < 1) { 
			cout << "Error! The day in January must be from 1 to 31!" << endl; 
			return false;
		}
		else {
			return true;
		}
		break;
	}case 2: {
		if ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0)) {
			if (day1 > 29 || day1 < 1) { 
				cout << "Error! The day in February must be from 1 to 29!" << endl; return false; 
			}
			else {
				return true;
			}
		}
		else {
			if (day1 > 28 || day1 < 1) { 
				cout << "Error! The day in February must be from 1 to 28!" << endl; return false; 
			}
			else {
				return true;
			}
		}
		break;
	}case 3: {
		if (day1 > 31 || day1 < 1) { cout << "Error! The day in March must be from 1 to 31!" << endl; return false; }
		else {
			return true;
		}
		break;
	}case 4: {
		if (day1 > 30 || day1 < 1) { cout << "Error! The day in April must be from 1 to 30!" << endl; return false; }
		else {
			return true;
		}
		break;
	}case 5: {
		if (day1 > 31 || day1 < 1) { cout << "Error! The day in May must be from 1 to 31!" << endl; return false; }
		else {
			return true;
		}
		break;
	}case 6: {
		if (day1 > 30 || day1 < 1) { cout << "Error! The day in June must be from 1 to 30!" << endl; return false; }
		else {
			return true;
		}
		break;
	}case 7: {
		if (day1 > 31 || day1 < 1) { cout << "Error! The day in July must be from 1 to 31!" << endl; return false; }
		else {
			return true;
		}
		break;
	}case 8: {
		if (day1 > 31 || day1 < 1) { cout << "Error! The day in August must be from 1 to 31!" << endl; return false; }
		else {
			return true;
		}
		break;
	}case 9: {
		if (day1 > 30 || day1 < 1) { cout << "Error! The day in September must be from 1 to 30!" << endl; return false; }
		else {
			return true;
		}
		break;
	}case 10: {
		if (day1 > 31 || day1 < 1) { cout << "Error! The day in October must be from 1 to 31!" << endl; return false; }
		else {
			return true;
		}
		break;
	}case 11: {
		if (day1 > 30 || day1 < 1) { cout << "Error! The day in Novermber must be from 1 to 30!" << endl; return false; }
		else {
			return true;
		}
		break;
	}case 12: {
		if (day1 > 31 || day1 < 1) { cout << "Error! The day in December must be from 1 to 31!" << endl; return false; }
		else {
			return true;
		}
		break;
	}default: {
		cout << "There is no such month!";
		return false;
		break;
	}
	}
}

void chooseTicketClass(int roomNum, Room *roomC, TicketManagement &TM, int expHour, int expMin, 
	int expDay, int expMonth, int expYear) {

re_bookYear:
	cout << "Book Year: ";
	inputErrorPrevention(&issueYear);
	if (issueYear > expYear)
	{
		cout << "Year cannot be later than "<< expYear;
		goto re_bookYear;
	}
re_bookMonth:
	if (issueYear < expYear) {
		cout << "Book Month: ";
		inputErrorPrevention(&issueMonth);
		if (issueMonth < 1 || issueMonth>12)
		{
			cout << "Invalid month\n" ;
			goto re_bookMonth;
		}
		else 
		{
re_bookDayNotEqualYear:
			cout << "Book day: ";
			inputErrorPrevention(&issueDay);
			if (!checkValidDate(issueDay, issueMonth, issueYear))
			{
				goto re_bookDayEqualYear;
			}
		}
	}else {
		cout << "Book Month: ";
		inputErrorPrevention(&issueMonth);
		if(issueMonth < 1)
		{
			cout << "Invalid month\n";
			goto re_bookMonth;
		}
		else if (issueMonth > expMonth) {
			cout << "Movie already aired\n";
			goto re_bookMonth;
		}
		else 
		{
re_bookDayEqualYear:
			cout << "Book day: ";
			inputErrorPrevention(&issueDay);
			if (checkValidDate(issueDay, issueMonth, issueYear))
			{
				if (issueMonth == expMonth) {
					if (issueDay > expDay) {
						cout << "Movie already aired\n";
						goto re_bookDayEqualYear;
					}
				}
			}
			else {
				goto re_bookDayEqualYear;
			}

		}
	}
	cout << "\nTicket Class\n1. Classic\n2. VIP\n";
	cout << "Pleas choose ticket class: ";
	inputErrorPrevention(&ticketClass);
re_seat:
	cout << "Enter seat number: ";
	inputErrorPrevention(&seatNum);
	switch (ticketClass)
	{
	case 1:
		if (seatNum<0 || seatNum>MaxClassic)
		{
			cout << "Wrong seat number!\n";
			system("PAUSE");
			goto re_seat;
		}
		else if (roomC->checkSeat(ticketClass, seatNum)) {
			cout << "Seat already booked!\n";
			system("PAUSE");
			goto re_seat;
		}
		else {
			TM.addTicket(roomNum, ticketType, ticketClass, roomC, movieTitle[room - 1], seatNum, expHour,
				expMin, issueDay, issueMonth, issueYear, expDay, expMonth, expYear);//airing hour
			
		}
		break;
	case 2:
		if (seatNum<0 || seatNum>MaxVIP)
		{
			cout << "Wrong seat number!\n";
		}
		else if (roomC->checkSeat(ticketClass, seatNum)) {
			cout << "Seat already booked!\n";
			goto re_seat;
		}
		else {
			TM.addTicket(roomNum, ticketType, ticketClass, roomC, movieTitle[room - 1], seatNum, expHour,
				expMin, issueDay, issueMonth, issueYear, expDay, expMonth, expYear);//airing hour

		}
		break;
	default:
		break;
	}

}
void bookMovieTicket(TicketManagement *TM) {
	system("CLS");
	cout << "-----Movie Schedules------\n";
	cout << "1. " << movieTitle[0] << endl;
	cout << "2. " << movieTitle[1] << endl;
	cout << "3. " << movieTitle[2] << endl;
	cout << "4. " << movieTitle[3] << endl;
	cout << "Choose movie: ";
	inputErrorPrevention(&room);
	switch (room)
	{
	case 1:
	{
		//room1->bookAll();
		if (room1->checkRoomFull())
		{
			cout << "Room is full!\n";
re_GotoRoomFull:
			cout << "Do you want to book ticket for another movie? Y/N: ";
			cin >> yesOrNo;
			switch (yesOrNo)
			{
			case 'Y':
			case 'y':
			{
				bookMovieTicket(TM);
				break;
			}
			case 'N':
			case 'n':
			{
				cout << "Good bye!";
				system("PAUSE");
				break;
			}
			default:
				cout << "Error Input\n";
				system("PAUSE");
				goto re_GotoRoomFull;
				break;
			}
		}
		else {
			system("CLS");
			room1->displayAllSeats();
			chooseTicketClass(room, room1, *TM, 3, 30, 15, 3, 2019);
		}		
		break;
	}
	case 2:
		if (room2->checkRoomFull())
		{
			cout << "Room is full!\n";
			cout << "Do you want to book ticket for another movie? Y/N: ";
			cin >> yesOrNo;
			switch (yesOrNo)
			{
			case 'Y':
			case 'y':
			{
				bookMovieTicket(TM);
				break;
			}
			case 'N':
			case 'n':
			{
				cout << "Good bye!";
				system("PAUSE");
				break;
			}
			default:
				cout << "Error Input\n";
				system("PAUSE");
				break;
			}
		}
		else {
			system("CLS");
			room2->displayAllSeats();
			chooseTicketClass(room, room2, *TM, 2, 30, 15, 3, 2019);
		}
		break;
	case 3:
		if (room3->checkRoomFull())
		{
			cout << "Room is full!\n";
			cout << "Do you want to book ticket for another movie? Y/N: ";
			cin >> yesOrNo;
			switch (yesOrNo)
			{
			case 'Y':
			case 'y':
			{
				bookMovieTicket(TM);
				break;
			}
			case 'N':
			case 'n':
			{
				cout << "Good bye!";
				system("PAUSE");
				break;
			}
			default:
				cout << "Error Input\n";
				system("PAUSE");
				break;
			}
		}
		else {
			system("CLS");
			room3->displayAllSeats();
			chooseTicketClass(room, room3, *TM, 1, 30, 15, 3, 2019);
		}
		break;
	case 4:
		if (room4->checkRoomFull())
		{
			cout << "Room is full!\n";
			cout << "Do you want to book ticket for another movie? Y/N: ";
			cin >> yesOrNo;
			switch (yesOrNo)
			{
			case 'Y':
			case 'y':
			{
				bookMovieTicket(TM);
				break;
			}
			case 'N':
			case 'n':
			{
				cout << "Good bye!";
				system("PAUSE");
				break;
			}
			default:
				cout << "Error Input\n";
				system("PAUSE");
				break;
			}
		}
		else {
			system("CLS");
			room4->displayAllSeats();
			chooseTicketClass(room, room4, *TM, 4, 20, 15, 3, 2019);
		}
		break;
	default:
		break;
	}
}


int main() {
	TicketManagement TM;
	Ticket t;
	int menuOption;
	while (1) 
	{
		system("CLS");
		//TM.displayAllTicket();
		cout << "-----Cinema Menu Option------\n";
		cout << "1. Book ticket\n";
		cout << "2. Validate ticket\n";
		cout << "3. Display all ticket\n";
		cout << "4. Search ticket by class\n";
		cout << "5. Sort tickets by issued date\n";
		cout << "option: ";
		inputErrorPrevention(&menuOption);
		switch (menuOption)
		{
		case 1: 
		{
re_StudentReinput:
			system("CLS");
			cout << "Student ID? Y/N: ";
			cin >> yesOrNo;
			switch (yesOrNo)
			{
			case 'Y':
			case 'y':
			{
				ticketType = 1;
				bookMovieTicket(&TM);
				break;
			}
			case 'N':
			case 'n':
			{
				cout << "Your age: ";
				inputErrorPrevention(&age);
				if (age <= 12)
					ticketType = 2;
				else if (age <= 26)
				{
					ticketType = 3;
					//t.price = 3.5;
				}
				else
				{
					ticketType = 4;
					t.price = 4;
				}
				bookMovieTicket(&TM);
				break;
			}
			default:
				system("CLS");
				cout << "Error Input\n";
				system("PAUSE");
				goto re_StudentReinput;
				break;
			}
			break;
		}
		case 2:
		{
			system("CLS");
			TM.find_barcode();
			break;
		}
		case 3:
		{
			system("CLS");
			TM.displayAllTicket();
			system("PAUSE");
			break;
		}
		case 4:
		{
			system("CLS");
			TM.searchTicket();
			system("PAUSE");
			break;
		}
		case 5:
		{
			system("CLS");
			TM.Sort_By_issueDate();
			TM.displayAllTicket();
			system("PAUSE");
			break;
		}
		default:
			system("PAUSE");
			break;
		}
		
		
	}
	
	return 0;
}