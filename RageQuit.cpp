#include "RageQuit.h"
BAKKESMOD_PLUGIN(RageQuit, "Rage Quit Plugin", "0.1", PERMISSION_ALL)

void RageQuit::rageQuit_onCommand()
{
	if (GetAsyncKeyState(VK_MENU) && *ragequit_enabled)
	{
		if (!gameWrapper->IsInOnlineGame() || gameWrapper->IsInReplay() || gameWrapper->IsInCustomTraining())
		{
			cvarManager->log("Goodbye Cruel World!");
			cvarManager->executeCommand("unreal_command exit;");
		}
	}
}

void RageQuit::onLoad()
{
	ragequit_enabled = std::make_shared<bool>(true);
	cvarManager->log("Loaded Rage Quit Plugin");
	cvarManager->registerNotifier("ragequitcommand", [this](std::vector<std::string> params) {rageQuit_onCommand();}, "Quits the game by using Alt F4", PERMISSION_ALL);
	cvarManager->registerCvar("ragequit_allowed", "1", "Enabled/Disabled Rage Quit on Alt F4", true, true, 0.f, true, 1.f, true).bindTo(ragequit_enabled);

	cvarManager->executeCommand("exec ragequitplugin.cfg");
}

void RageQuit::onUnload()
{

}