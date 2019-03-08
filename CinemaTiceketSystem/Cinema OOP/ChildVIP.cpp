#include "ChildVIP.h"

void ChildVIP::setTicketNum()
{
	ticketNum = "CHVIP00" + std::to_string(seatNum);
	ticketClass = "VIP";
}

ChildVIP::ChildVIP()
{
	price *= 2;
}


ChildVIP::~ChildVIP()
{
}
