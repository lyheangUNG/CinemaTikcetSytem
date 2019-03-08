#include "AdultVIP.h"



void AdultVIP::setTicketNum()
{
	ticketNum = "ADVIP00" + std::to_string(seatNum);
	ticketClass = "VIP";
}

AdultVIP::AdultVIP()
{
	price *= 2;
}


AdultVIP::~AdultVIP()
{
}
