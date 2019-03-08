#include "StudentVIP.h"

void StudentVIP::setTicketNum()
{
	ticketNum = "STVIP00" + std::to_string(seatNum);
	ticketClass = "VIP";
}

StudentVIP::StudentVIP()
{
	price *= 2;
}


StudentVIP::~StudentVIP()
{
}
