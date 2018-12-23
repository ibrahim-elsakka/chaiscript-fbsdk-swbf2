#include "chaiscript/chaiscript.hpp"
#include "SDK.h"

extern "C" __declspec(dllexport) void AddExtension(chaiscript::ChaiScript* chai) {
	chai->add(chaiscript::user_type<sdk::PlayerAbilityAsset>(), "PlayerAbilityAsset");
	chai->add(chaiscript::fun(&sdk::PlayerAbilityAsset::GetName), "name");
	chai->add(chaiscript::fun(&sdk::PlayerAbilityAsset::GetUnlockAsset), "unlockAsset");
	chai->add(chaiscript::fun(&sdk::PlayerAbilityAsset::SetUnlockAsset), "unlockAsset");

	chai->add(chaiscript::user_type<sdk::ClientLevel>(), "ClientLevel");
	chai->add(chaiscript::fun(static_cast<sdk::PlayerAbilityAsset(sdk::ClientLevel::*)(const std::string)>(&sdk::ClientLevel::GetPlayerAbilityAsset)), "getPlayerAbilityAsset");
	chai->add(chaiscript::fun(&sdk::ClientLevel::DumpAbilities), "dumpAbilities");

	chai->add(chaiscript::user_type<sdk::Soldier>(), "Soldier");
	chai->add(chaiscript::fun(&sdk::Soldier::GetOverrideVelocity), "overrideVelocity");
	chai->add(chaiscript::fun(&sdk::Soldier::SetOverrideVelocity), "overrideVelocity");
	chai->add(chaiscript::fun(&sdk::Soldier::GetGravity), "gravity");
	chai->add(chaiscript::fun(&sdk::Soldier::SetGravity), "gravity");
	chai->add(chaiscript::fun(&sdk::Soldier::GetSpeed), "speed");
	chai->add(chaiscript::fun(&sdk::Soldier::SetSpeed), "speed");

	chai->add(chaiscript::user_type<sdk::Player>(), "Player");
	chai->add(chaiscript::fun(&sdk::Player::name), "name");
	chai->add(chaiscript::fun(&sdk::Player::team), "team");
	chai->add(chaiscript::fun(&sdk::Player::kills), "kills");
	chai->add(chaiscript::fun(&sdk::Player::deaths), "deaths");
	chai->add(chaiscript::fun(&sdk::Player::score), "score");
	chai->add(chaiscript::fun(&sdk::Player::assists), "assists");
	chai->add(chaiscript::fun(&sdk::Player::IsValid), "IsValid");
	chai->add(chaiscript::fun(&sdk::Player::IsSoldier), "IsSoldier");
	chai->add(chaiscript::fun(static_cast<sdk::Soldier(sdk::Player::*)()>(&sdk::Player::getSoldier)), "getSoldier");

	chai->add(chaiscript::user_type<sdk::RenderSettings>(), "RenderSettings");
	chai->add(chaiscript::constructor<sdk::RenderSettings()>(), "RenderSettings");
	chai->add(chaiscript::fun(&sdk::RenderSettings::GetFOV), "fov");
	chai->add(chaiscript::fun(&sdk::RenderSettings::SetFOV), "fov");
	chai->add(chaiscript::fun(&sdk::RenderSettings::GetResScale), "resScale");
	chai->add(chaiscript::fun(&sdk::RenderSettings::SetResScale), "resScale");

	chai->add(chaiscript::user_type<sdk::Manager>(), "Manager");
	chai->add(chaiscript::constructor<sdk::Manager()>(), "Manager");
	chai->add(chaiscript::fun(&sdk::Manager::getPlayerCount), "getPlayerCount");
	chai->add(chaiscript::fun(static_cast<sdk::Player(sdk::Manager::*)()>(&sdk::Manager::getLocalPlayer)), "getLocalPlayer");
	chai->add(chaiscript::fun(static_cast<sdk::Player(sdk::Manager::*)(const int)>(&sdk::Manager::getPlayerByID)), "getPlayerByID");
	chai->add(chaiscript::fun(static_cast<sdk::ClientLevel(sdk::Manager::*)()>(&sdk::Manager::getClientLevel)), "getClientLevel");
}
