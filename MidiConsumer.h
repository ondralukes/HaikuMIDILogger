#ifndef _H_MIDI_CONSUMER
#define _H_MIDI_CONSUMER


#include <SupportDefs.h>
#include <MidiConsumer.h>
#include <cstdio>


class MidiConsumer : public BMidiLocalConsumer{
public:
			MidiConsumer();
private:
	void	NoteOn (uchar channel, uchar note, uchar velocity, bigtime_t time);
	void	NoteOff (uchar channel, uchar note, uchar velocity, bigtime_t time);
	void	ChannelPressure (uchar channel, uchar pressure, bigtime_t time);
	void	ControlChange (uchar channel, uchar controlNumber, uchar controlValue, bigtime_t time);
	void	KeyPressure (uchar channel, uchar note, uchar pressure, bigtime_t time);
	void	PitchBend (uchar channel, uchar lsb, uchar msb, bigtime_t time);
	void	ProgramChange (uchar channel, uchar programNumber, bigtime_t time);
	void 	SystemCommon (uchar status, uchar data1, uchar data2, bigtime_t time);
	void	SystemExclusive (void * data, size_t length, bigtime_t time);
	void	SystemRealTime	(uchar status, bigtime_t time);
	void 	TempoChange (int32 bpm, bigtime_t time);
};


#endif // _H_MIDI_CONSUMER
