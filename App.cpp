#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <Application.h>
#include <Messenger.h>
#include <MidiRoster.h>

class App : public BApplication
{
public:
			App();
			~App();
private:
	BMessenger*		messenger;
	BMidiRoster*	roster;
	void			ReadyToRun();
	bool			QuitRequested();
	void			MessageReceived(BMessage * message);
	void			HandleMIDI(BMessage * message);
};

App::App()
	:
	BApplication("application/x-vnd.Haiku-HaikuMIDILogger")
{
	messenger = new BMessenger(this,NULL);
	messenger->SendMessage(123);
	roster = BMidiRoster::MidiRoster();
	roster->StartWatching(messenger);
}

App::~App(){
	delete messenger;
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
	char type[64];
	int32 producer;
	int32 consumer;
	message->FindInt32("be:op",&op);
	message->FindInt32("be:id",&id);
	message->FindString("be:type",(const char **)&type);
	message->FindInt32("be:producer",&producer);
	message->FindInt32("be:consumer",&consumer);
	switch (op){
		case B_MIDI_REGISTERED:
			printf("MIDI %s %d registered\n",type,id);
			break;
		case B_MIDI_UNREGISTERED:
			printf("MIDI %s %d unregistered\n",type,id);
			break;
		case B_MIDI_CONNECTED:
			
			printf("MIDI: Producer %d connected to consumer %d\n",producer,consumer);
			break;
		case B_MIDI_DISCONNECTED:
			printf("MIDI: Producer %d disconnected from consumer %d\n",producer,consumer);
	}
}
int main()
{
	std::srand(std::time(NULL));
	App app;
	app.Run();
	return 0;
}
