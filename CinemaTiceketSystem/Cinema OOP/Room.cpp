#include "Room.h"
#include<iostream>
using namespace std;

void coutSeat(vector<bool> vec) {
	for (unsigned int i = 0; i < vec.size(); i++) {
		if (vec[i] == false)
			cout << i + 1 << "\t";
		else
			cout << "\t";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
}

void Room::displayAllSeats()
{
	cout << "Available seat numbers for classic ticket are:\n";
	coutSeat(classicSeat);
	cout << endl;
	cout << "Available seat numbers for VIP ticket are:\n";
	coutSeat(vipSeat);
}

void Room::resetRoom()
{
	for (unsigned int i = 0; i < classicSeat.size(); i++)
		classicSeat[i] = false;
	for (unsigned int i = 0; i < vipSeat.size(); i++)
		vipSeat[i] = false;
}

void Room::bookAll()
{
	for (unsigned int i = 0; i < classicSeat.size(); i++)
		classicSeat[i] = true;
	for (unsigned int i = 0; i < vipSeat.size(); i++)
		vipSeat[i] = true;
}

bool Room::checkSeat(int type, int seatNum) //true = booked
{
	switch (type)
	{
	case 1:
	{
		if (classicSeat[seatNum - 1]) //checking seat availability
			return true;
		else {
			return false;
		}
	}
	case 2:
	{
		if (vipSeat[seatNum - 1]) //checking seat availability
			return true;
		else {
			return false;
		}
	}

	default:
	{
		return false;
		break;
	}
	}
}

bool Room::bookSeat(int type, int seatNum) //false = booked
{
	switch (type)
	{
		case 1:
		{
			if (checkSeat(type, seatNum)) //checking seat availability
				return false;
			else {
				classicSeat[seatNum - 1] = true;
				return true;
			}
			break;
		}
		case 2:
		{
			if (checkSeat(type, seatNum)) //checking seat availability
				return false;
			else {
				vipSeat[seatNum - 1] = true;
				return true;
			}
		}
		break;
		default: 
		{
			return false;
			break;
		}
	}
}

bool Room::checkRoomFull()
{
	for (unsigned int i = 0; i < classicSeat.size(); i++) {
		if (!classicSeat[i])
			return false; //available 
	}
	for (unsigned int i = 0; i < vipSeat.size(); i++) {
		if (!vipSeat[i])
			return false;//available 
	}
	return true;//full 
}

Room::Room(int classic, int vip)
{
	for (int i = 0; i < classic; i++)
		classicSeat.push_back(false);
	for (int i = 0; i < vip; i++)
		vipSeat.push_back(false);
}

Room::Room()
{
}


Room::~Room()
{
}
