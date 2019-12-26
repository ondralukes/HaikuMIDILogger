#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <Application.h>
#include <Messenger.h>
#include <MidiRoster.h>
#include <MidiProducer.h>
#include <String.h>
#include "MidiConsumer.h"

class App : public BApplication
{
public:
			App();
			~App();
private:
	BMessenger*		messenger;
	BMidiRoster*	roster;
	MidiConsumer*	consumer;
	void			ReadyToRun();
	bool			QuitRequested();
	void			MessageReceived(BMessage * message);
	void			HandleMIDI(BMessage * message);
	void			FindProducers();
};

App::App()
	:
	BApplication("application/x-vnd.Haiku-HaikuMIDILogger")
{
	messenger = new BMessenger(this,NULL);
	consumer = new MidiConsumer();
	roster = BMidiRoster::MidiRoster();
	roster->StartWatching(messenger);
}

App::~App(){
	delete messenger;
	delete consumer;
}

void
App::ReadyToRun()
{
	printf("Ready to run!\n");
}

bool
App::QuitRequested(){
	printf("Bye Bye!\n");
	return true;
}

void
App::MessageReceived(BMessage * message){
	switch (message->what){
		case B_MIDI_EVENT:
			HandleMIDI(message);
			break;
		default:
			break;
	}
}

void
App::HandleMIDI(BMessage * message){
	int32 op;
	int32 id;
	BString *type = new BString();
	int32 producer;
	int32 consumer;
	message->FindInt32("be:op",&op);
	switch (op){
		case B_MIDI_REGISTERED:
			{
			message->FindInt32("be:id",&id);
			message->FindString("be:type",type);
			printf("[MIDIRoster] %s %d registered\n",type->String(),id);
			FindProducers();
			break;
			}
		case B_MIDI_UNREGISTERED:
			message->FindInt32("be:id",&id);
			message->FindString("be:type",type);
			printf("[MIDIRoster] %s %d unregistered\n",type->String(),id);
			break;
		case B_MIDI_CONNECTED:
			message->FindInt32("be:producer",&producer);
			message->FindInt32("be:consumer",&consumer);
			printf("[MIDIRoster] Producer %d connected to consumer %d\n",producer,consumer);
			break;
		case B_MIDI_DISCONNECTED:
			message->FindInt32("be:producer",&producer);
			message->FindInt32("be:consumer",&consumer);
			printf("[MIDIRoster] Producer %d disconnected from consumer %d\n",producer,consumer);
			break;
		case B_MIDI_CHANGED_NAME:
			{
			BString * name = new BString();
			message->FindInt32("be:id",&id);
			message->FindString("be:type", type);
			message->FindString("be:name", name);
			printf("[MIDIRoster] %s %d changed name to %s\n",type->String(),id,name->String());
			delete name;
			break;
			}
		case B_MIDI_CHANGED_LATENCY:
			{
			int64 latency;
			message->FindInt64("be:latency",&latency);
			printf("[MIDIRoster] %s %d changed latency to %d\n",type->String(),id,latency);
			break;
			}
		case B_MIDI_CHANGED_PROPERTIES:
			message->FindInt32("be:id",&id);
			message->FindString("be:type", type);
			printf("[MIDIRoster] %s %d changed properties\n",type->String(),id);
			break;
	}
	delete type;
}

void
App::FindProducers()
{
	int32 id = 0;
	BMidiProducer * producer;
	printf("Looking for producers...\n");
	while((producer = roster->NextProducer(&id))!=NULL){
		printf("Found producer %d\n",id);
		producer->Connect(consumer);
		}
}
int main()
{
	std::srand(std::time(NULL));
	App app;
	app.Run();
	return 0;
}
