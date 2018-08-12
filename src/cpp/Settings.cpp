#include "Settings.h"

Settings::Settings() : Settings::Settings(200)
{
}

Settings::Settings(int msec)
{
	_msec_per_tick = msec;
}

void Settings::setMsecPerTick(int msec)
{
	_msec_per_tick = msec;
}

int Settings::getMsecPerTick()
{
	return _msec_per_tick;
}

