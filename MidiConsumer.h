#ifndef _H_MIDI_CONSUMER
#define _H_MIDI_CONSUMER


#include <SupportDefs.h>
#include <MidiConsumer.h>
#include <cstdio>


class MidiConsumer : public BMidiLocalConsumer{
public:
			MidiConsumer();
private:
	void	NoteOn(uchar channel, uchar note, uchar velocity, bigtime_t time);
	void	NoteOff(uchar channel, uchar note, uchar velocity, bigtime_t time);
};


#endif // _H_MIDI_CONSUMER
