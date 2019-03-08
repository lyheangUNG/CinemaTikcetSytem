#pragma once
#include<vector>
class Room
{
public:
	std::vector<bool> classicSeat, vipSeat; //True=booked, False=available;

public:
	void displayAllSeats();
	void resetRoom();
	void bookAll(); //for testing
	bool checkSeat(int type, int seatNum); //true = booked
	bool bookSeat(int type, int seatNum); //false = booked
	bool checkRoomFull();
	Room(int classic, int vip);
	Room();
	~Room();
};

