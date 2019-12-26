#ifndef _H_MIDI_CONSUMER
#define _H_MIDI_CONSUMER


#include <SupportDefs.h>
#include <MidiConsumer.h>
#include <cstdio>


class MidiConsumer : public BMidiLocalConsumer{
public:
			MidiConsumer();
private:
	void	Data(uchar * data, size_t len, bool atomic, bigtime_t time);
};


#endif // _H_MIDI_CONSUMER
