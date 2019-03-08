#include "TeenVIP.h"



void TeenVIP::setTicketNum()
{
	ticketNum = "TEVIP00" + std::to_string(seatNum);
	ticketClass = "VIP";
}

TeenVIP::TeenVIP()
{
	price *= 2;
}


TeenVIP::~TeenVIP()
{
}
