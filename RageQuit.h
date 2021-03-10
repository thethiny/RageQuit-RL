#pragma once
#pragma comment(lib, "pluginsdk.lib")
#include "bakkesmod/plugin/bakkesmodplugin.h"

class RageQuit : public BakkesMod::Plugin::BakkesModPlugin
{
public:
	virtual void onLoad();
	virtual void onUnload();
	std::shared_ptr<bool> ragequit_enabled;
	void rageQuit_onCommand();
};

