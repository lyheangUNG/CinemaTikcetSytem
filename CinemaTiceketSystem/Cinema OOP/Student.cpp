#include "Student.h"




void Student::setTicketNum()
{
	ticketNum = "ST00" + std::to_string(seatNum);
	ticketClass = "Classic";
}

Student::Student()
{
	price = 3;
}


Student::~Student()
{
}
