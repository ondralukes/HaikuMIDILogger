#include "MidiConsumer.h"

MidiConsumer::MidiConsumer()
{
		
}

void
MidiConsumer::Data(uchar * data, size_t len, bool atomic, bigtime_t time)
{
	printf("Got data\n");	
}
