#include "FB.h"
namespace sdk {

	class PlayerAbilityAsset {
	private:
		fb::PlayerAbilityAsset* pPlayerAbilityAsset;
	public:
		PlayerAbilityAsset(void* addr) {
			this->pPlayerAbilityAsset = (fb::PlayerAbilityAsset*)addr;
		}

		std::string GetName() {
			if (!IsValidPtr(this->pPlayerAbilityAsset)) return "null";
			return std::string(this->pPlayerAbilityAsset->m_AbilityName);
		}

		DWORD64 GetUnlockAsset() {
			if (!IsValidPtr(this->pPlayerAbilityAsset)) return 0;
			if (!IsValidPtr(this->pPlayerAbilityAsset->m_Unlock)) return 0;
			return (DWORD64)this->pPlayerAbilityAsset->m_Unlock;
		}

		void SetUnlockAsset(DWORD64 value) {
			if (!IsValidPtr((void*)value)) return;
			if (!IsValidPtr(this->pPlayerAbilityAsset)) return;
			if (!IsValidPtr(this->pPlayerAbilityAsset->m_Unlock)) return;
			this->pPlayerAbilityAsset->m_Unlock = (fb::UnlockAssetBase*)value;
		}
	};


	class ClientLevel {
	private:
		fb::ClientLevel* pClientLevel;
	public:
		ClientLevel(void* addr) {
			this->pClientLevel = (fb::ClientLevel*)addr;
		}
		sdk::PlayerAbilityAsset GetPlayerAbilityAsset(std::string name) {
			if (!IsValidPtr(this->pClientLevel)) return sdk::PlayerAbilityAsset(nullptr);
			if (!IsValidPtr(this->pClientLevel->teamData)) return sdk::PlayerAbilityAsset(nullptr);
			if (!IsValidPtr(this->pClientLevel->teamData->teamEntityData)) return sdk::PlayerAbilityAsset(nullptr);
			if (!IsValidPtr(this->pClientLevel->teamData->teamEntityData->teamLight)) return sdk::PlayerAbilityAsset(nullptr);
			if (!IsValidPtr(this->pClientLevel->teamData->teamEntityData->teamLight->playerAbilties)) return sdk::PlayerAbilityAsset(nullptr);
			for (int i = 0; i < 3096; i++) {
				if (!IsValidPtr(this->pClientLevel->teamData->teamEntityData->teamLight->playerAbilties->m_AllPlayerAbilities[i])) return sdk::PlayerAbilityAsset(nullptr);
				if (strcmp(this->pClientLevel->teamData->teamEntityData->teamLight->playerAbilties->m_AllPlayerAbilities[i]->m_AbilityName, name.c_str()) == 0) {
					return sdk::PlayerAbilityAsset(this->pClientLevel->teamData->teamEntityData->teamLight->playerAbilties->m_AllPlayerAbilities[i]);
				}
			}
			return sdk::PlayerAbilityAsset(nullptr);
		}
		void DumpAbilities() {
			if (!IsValidPtr(this->pClientLevel)) return;
			if (!IsValidPtr(this->pClientLevel->teamData)) return;
			if (!IsValidPtr(this->pClientLevel->teamData->teamEntityData)) return;
			if (!IsValidPtr(this->pClientLevel->teamData->teamEntityData->teamLight)) return;
			if (!IsValidPtr(this->pClientLevel->teamData->teamEntityData->teamLight->playerAbilties)) return;
			for (int i = 0; i < 3096; i++) {
				if (!IsValidPtr(this->pClientLevel->teamData->teamEntityData->teamLight->playerAbilties->m_AllPlayerAbilities[i])) return;
				if (IsValidPtr(this->pClientLevel->teamData->teamEntityData->teamLight->playerAbilties->m_AllPlayerAbilities[i]->m_Unlock)) {
					std::cout << this->pClientLevel->teamData->teamEntityData->teamLight->playerAbilties->m_AllPlayerAbilities[i]->m_AbilityName << std::endl;
				}
			}
		}

	};


	class Soldier {
	private:
		fb::ClientPlayer* pClientPlayer;
	public:
		Soldier(void* addr) {
			this->pClientPlayer = (fb::ClientPlayer*)addr;
		}

		bool GetOverrideVelocity() {
			if (!IsValidPtr(this->pClientPlayer)) return 0;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable)) return 0;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->clientSoldierBodyComponent)) return 0;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->clientSoldierBodyComponent->soldierBodyComponentData)) return 0;
			return this->pClientPlayer->controlledControllable->clientSoldierBodyComponent->soldierBodyComponentData->m_OverrideVelocity;
		}
		void SetOverrideVelocity(bool value) {
			if (!IsValidPtr(this->pClientPlayer)) return;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable)) return;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->clientSoldierBodyComponent)) return;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->clientSoldierBodyComponent->soldierBodyComponentData)) return;
			this->pClientPlayer->controlledControllable->clientSoldierBodyComponent->soldierBodyComponentData->m_OverrideVelocity = value;
		}

		float GetGravity() {
			if (!IsValidPtr(this->pClientPlayer)) return 0;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable)) return 0;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->clientSoldierBodyComponent)) return 0;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->clientSoldierBodyComponent->soldierBodyComponentData)) return 0;
			return this->pClientPlayer->controlledControllable->clientSoldierBodyComponent->soldierBodyComponentData->m_OverrideVelocityY;
		}
		void SetGravity(float value) {
			if (!IsValidPtr(this->pClientPlayer)) return;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable)) return;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->clientSoldierBodyComponent)) return;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->clientSoldierBodyComponent->soldierBodyComponentData)) return;
			this->pClientPlayer->controlledControllable->clientSoldierBodyComponent->soldierBodyComponentData->m_OverrideVelocityY = value;
		}

		void SetSpeed(float value) {
			if (!IsValidPtr(this->pClientPlayer)) return;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable)) return;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->soldierWeaponComponent)) return;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->soldierWeaponComponent->soldierWeaponsComponentData)) return;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->soldierWeaponComponent->soldierWeaponsComponentData->soldierAimingSimulationData)) return;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->soldierWeaponComponent->soldierWeaponsComponentData->soldierAimingSimulationData->zoomData)) return;
			for (int i = 0; i < 2; i++) {
				if (!IsValidPtr(this->pClientPlayer->controlledControllable->soldierWeaponComponent->soldierWeaponsComponentData->soldierAimingSimulationData->zoomData->zoomLevelData[i])) return;
				this->pClientPlayer->controlledControllable->soldierWeaponComponent->soldierWeaponsComponentData->soldierAimingSimulationData->zoomData->zoomLevelData[i]->m_MoveSPeedMultiplier = value;
			}
		}
		float GetSpeed() {
			if (!IsValidPtr(this->pClientPlayer)) return 0;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable)) return 0;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->soldierWeaponComponent)) return 0;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->soldierWeaponComponent->soldierWeaponsComponentData)) return 0;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->soldierWeaponComponent->soldierWeaponsComponentData->soldierAimingSimulationData)) return 0;
			if (!IsValidPtr(this->pClientPlayer->controlledControllable->soldierWeaponComponent->soldierWeaponsComponentData->soldierAimingSimulationData->zoomData)) return 0;

			if (!IsValidPtr(this->pClientPlayer->controlledControllable->soldierWeaponComponent->soldierWeaponsComponentData->soldierAimingSimulationData->zoomData->zoomLevelData[0])) return 0;
			return this->pClientPlayer->controlledControllable->soldierWeaponComponent->soldierWeaponsComponentData->soldierAimingSimulationData->zoomData->zoomLevelData[0]->m_MoveSPeedMultiplier;
		}

	};


	class Player {
	private:
		fb::ClientPlayer* pClientPlayer;
	public:
		Player(void* addr) {
			if (IsValidPtr(addr)) {
				this->pClientPlayer = (fb::ClientPlayer*)addr;
			}
		}
		bool IsValid() {
			return IsValidPtr(this->pClientPlayer) && this->pClientPlayer->IsValid();
		}
		std::string name() {
			if (this->IsValid()) {
				return std::string(this->pClientPlayer->Name);
			}
			return "Invalid Player";
		}
		int team() {
			if (this->IsValid()) {
				return this->pClientPlayer->Team;
			}
			return 0;
		}
		int kills() {
			if (this->IsValid()) {
				return this->pClientPlayer->Kills;
			}
			return 0;
		}
		int deaths() {
			if (this->IsValid()) {
				return this->pClientPlayer->Deaths;
			} return 0;
		}
		int score() {
			if (this->IsValid()) {
				return this->pClientPlayer->Score;
			} return 0;
		}
		int assists() {
			if (this->IsValid()) {
				return this->pClientPlayer->Assists;
			} return 0;
		}
		bool IsSoldier() {
			return ((!IsValidPtr(this->pClientPlayer->attachedControllable)) && (IsValidPtr(this->pClientPlayer->controlledControllable)));
		}

		sdk::Soldier getSoldier() {
			return sdk::Soldier(this->pClientPlayer);
		}

	};

	class RenderSettings
	{
	public:
		RenderSettings(){}

		float GetFOV()
		{
			if (!IsValidPtr(fb::GameRenderer::GetInstance())) return 0;
			if (!IsValidPtr(fb::GameRenderer::GetInstance()->gameRenderSettings)) return 0;
			return fb::GameRenderer::GetInstance()->gameRenderSettings->m_FOV;
		}
		void SetFOV(float value)
		{
			if (!IsValidPtr(fb::GameRenderer::GetInstance())) return;
			if (!IsValidPtr(fb::GameRenderer::GetInstance()->gameRenderSettings)) return;
			fb::GameRenderer::GetInstance()->gameRenderSettings->m_FOV = value;
		}

		float GetResScale()
		{
			if (!IsValidPtr(fb::GameRenderer::GetInstance())) return 0;
			if (!IsValidPtr(fb::GameRenderer::GetInstance()->gameRenderSettings)) return 0;
			return fb::GameRenderer::GetInstance()->gameRenderSettings->m_ResolutionScale;
		}
		void SetResScale(float value)
		{
			if (!IsValidPtr(fb::GameRenderer::GetInstance())) return;
			if (!IsValidPtr(fb::GameRenderer::GetInstance()->gameRenderSettings)) return;
			fb::GameRenderer::GetInstance()->gameRenderSettings->m_ResolutionScale = value;
		}
	};

	class Manager {
	public:
		Manager() { }
		sdk::Player getLocalPlayer() {
			return sdk::Player(fb::GameContext::GetInstance()->GetPlayerManager()->GetLocalPlayer());
		}
		sdk::Player getPlayerByID(int id) {
			return sdk::Player(fb::GameContext::GetInstance()->GetPlayerManager()->GetPlayerByID(id));
		}

		sdk::ClientLevel getClientLevel() {
			return sdk::ClientLevel(fb::GameContext::GetInstance()->clientLevel);
		}

		int getPlayerCount() {
			for (int i = 0; i < 40; i++) {
				if (!IsValidPtr(fb::GameContext::GetInstance()->GetPlayerManager()->GetmPPlayer()->PlayerArray[i])) {
					return i;
				}
			}
		}
		std::vector<sdk::Player> getPlayers() {
			std::vector<sdk::Player> outvect;
			for (int i = 0; i < 40; i++) {
				fb::ClientPlayer* player = fb::GameContext::GetInstance()->GetPlayerManager()->GetPlayerByID(i);
				if (IsValidPtr(player)) {
					outvect.push_back(sdk::Player(player));
				}
				else {
					break;

				}
			}
			return outvect;
		}
	};
}
