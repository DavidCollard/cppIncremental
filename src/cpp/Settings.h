#ifndef SETTINGS
#define SETTINGS

class Settings
{
public:
	Settings();
	Settings(int);
	void setMsecPerTick(int);
	int getMsecPerTick();
private:
	int _msec_per_tick;
};

#endif
