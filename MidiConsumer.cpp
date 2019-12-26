#include "MidiConsumer.h"

MidiConsumer::MidiConsumer()
{
		
}

void
MidiConsumer::NoteOn(uchar channel, uchar note, uchar velocity, bigtime_t time)
{
	int32 id = GetProducerID();
	printf("[Producer %d] Note %d on on channel %d with velocity %d\n",id,note,channel,velocity);
}

void
MidiConsumer::NoteOff(uchar channel, uchar note, uchar velocity, bigtime_t time)
{
	int32 id = GetProducerID();
	printf("[Producer %d] Note %d off on channel %d with velocity %d\n",id,note,channel,velocity);
}
