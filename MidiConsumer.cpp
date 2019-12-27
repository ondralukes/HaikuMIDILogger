#include "MidiConsumer.h"

MidiConsumer::MidiConsumer()
{
		
}

void
MidiConsumer::NoteOn(uchar channel, uchar note, uchar velocity, bigtime_t time)
{
	int32 id = GetProducerID();
	printf("%lu: [Producer %d][Channel %d / Note %d]  Note on with velocity %d\n", time, id, channel, note, velocity);
}

void
MidiConsumer::NoteOff(uchar channel, uchar note, uchar velocity, bigtime_t time)
{
	int32 id = GetProducerID();
	printf("%lu: [Producer %d][Channel %d / Note %d]  Note off with velocity %d\n", time, id, channel, note, velocity);
}

void
MidiConsumer::ChannelPressure(uchar channel, uchar pressure, bigtime_t time)
{
	int32 id = GetProducerID();
	printf("%lu: [Producer %d][Channel %d]  Changed pressure to %d\n", time, id, channel, pressure);
}

void
MidiConsumer::ControlChange(uchar channel, uchar controlNumber, uchar controlValue, bigtime_t time)
{
	int32 id = GetProducerID();
	printf("%lu: [Producer %d][Channel %d]  Control %d changed to %d\n", time, id, channel, controlNumber, controlValue);
}

void
MidiConsumer::KeyPressure(uchar channel, uchar note, uchar pressure, bigtime_t time)
{
	int32 id = GetProducerID();
	printf("%lu: [Producer %d][Channel %d / Note %d]  Changed pressure to %d\n", time, id, channel, note, pressure);
}

void
MidiConsumer::PitchBend(uchar channel, uchar lsb, uchar msb, bigtime_t time)
{
	int32 id = GetProducerID();
	printf("%lu: [Producer %d][Channel %d]  Pitch bend LSB=%d MSB=%d\n", time, id, channel, lsb, msb);
}

void
MidiConsumer::ProgramChange(uchar channel, uchar programNumber, bigtime_t time)
{
	int32 id = GetProducerID();
	printf("%lu: [Producer %d][Channel %d]  Program changed to %d\n", time, id, channel, programNumber);
}

void
MidiConsumer::SystemCommon(uchar status, uchar data1, uchar data2, bigtime_t time)
{
	int32 id = GetProducerID();
	printf("%lu: [Producer %d]  System common status=%d data1=%d data2=%d\n", time, id, status, data1, data2);
}

void
MidiConsumer::SystemExclusive(void * data, size_t length, bigtime_t time)
{
	int32 id = GetProducerID();
	printf("%lu: [Producer %d]  System exclusive\n", time, id);
}

void
MidiConsumer::SystemRealTime(uchar status, bigtime_t time)
{
	int32 id = GetProducerID();
	printf("%lu: [Producer %d]  System realtime status=%d\n", time, id, status);
}

void
MidiConsumer::TempoChange(int32 bpm, bigtime_t time)
{
	int32 id = GetProducerID();
	printf("%lu: [Producer %d]  Changed tempo to %d bpm\n", time, id, bpm);
}
