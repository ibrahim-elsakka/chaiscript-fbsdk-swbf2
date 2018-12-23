#include <Windows.h>
#include <string>
#include <vector>
#include <ctime>
#include <time.h>
#include <iostream>
#include "SigScan.h"

bool IsValidPtr(void* addr) {
	return !IsBadReadPtr(reinterpret_cast<PVOID>(addr), sizeof(PVOID));
}

namespace fb {

	class ZoomLevelData
	{
	public:
		char pad_0000[40]; //0x0000
		float m_FieldOfView; //0x0028
		char pad_002C[4]; //0x002C
		float m_LookSpeedMultiplier; //0x0030
		float m_SprintLookSpeedMultiplier; //0x0034
		float m_MoveSPeedMultiplier; //0x0038
		char pad_003C[36]; //0x003C
		float m_DispersionMultiplier; //0x0060
		char pad_0064[4]; //0x0064
		float m_RecoilMultiplier; //0x0068
		float m_RecoilFovMultiplier; //0x006C
		float m_CameraImpulseMultiplier; //0x0070
		char pad_0074[208]; //0x0074
	}; //Size: 0x0144

	class ZoomData
	{
	public:
		class ZoomLevelData* zoomLevelData[2]; //0x0000
		char pad_0010[64]; //0x0010
	}; //Size: 0x0050

	class SoldierAimingSimulationData
	{
	public:
		char pad_0000[24]; //0x0000
		class ZoomData* zoomData; //0x0018
		char pad_0020[296]; //0x0020
	}; //Size: 0x0148

	class SoldierWeaponsComponentData
	{
	public:
		char pad_0000[192]; //0x0000
		class SoldierAimingSimulationData* soldierAimingSimulationData; //0x00C0
		char pad_00C8[1400]; //0x00C8
	}; //Size: 0x0640

	class SoldierWeaponComponent
	{
	public:
		char pad_0000[16]; //0x0000
		class SoldierWeaponsComponentData* soldierWeaponsComponentData; //0x0010
		char pad_0018[48]; //0x0018
	}; //Size: 0x0048

	class SoldierBodyComponentData
	{
	public:
		char pad_0000[176]; //0x0000
		float m_OverrideGravityValue; //0x00B0
		float m_OverrideVelocityY; //0x00B4
		float m_SprintMultiplier; //0x00B8
		bool m_OVerrideGravity; //0x00BC
		bool m_OverrideVelocity; //0x00BD
		char pad_00BE[138]; //0x00BE
	}; //Size: 0x0148

	class ClientSoldierBodyComponent
	{
	public:
		char pad_0000[16]; //0x0000
		class SoldierBodyComponentData* soldierBodyComponentData; //0x0010
		char pad_0018[304]; //0x0018
	}; //Size: 0x0148

	class ClientSoldier
	{
	public:
		char pad_0000[48]; //0x0000
		/*class SoldierEntityData*/void* soldierEntityData; //0x0030
		char pad_0038[496]; //0x0038
		class ClientPlayer* clientPlayer; //0x0228
		char pad_0230[88]; //0x0230
		/*class ClientSoldierHealthComponent*/void* clientSoldierHealthComponent; //0x0288
		char pad_0290[104]; //0x0290
		/*class CharacterBlueprint*/void* soldierBlueprint; //0x02F8
		char pad_0300[400]; //0x0300
		float N000006E3; //0x0490
		float HeightOffset; //0x0494
		char pad_0498[640]; //0x0498
		/*class ClientSoldierPrediction*/void* clientSoldierPrediction; //0x0718
		char pad_0720[20]; //0x0720
		float Yaw; //0x0734
		char pad_0738[556]; //0x0738
		float Pitch; //0x0964
		char pad_0968[4]; //0x0968
		int8_t Visibility; //0x096C
		char pad_096D[83]; //0x096D
		class SoldierWeaponComponent* soldierWeaponComponent; //0x09C0
		class ClientSoldierBodyComponent* clientSoldierBodyComponent; //0x09C8
		char pad_09D0[16]; //0x09D0
		/*class ClientAimEntity*/void* ClientAimEntity; //0x09E0
		/*class clientSoldierWeapon*/void* ClientSoldierWeapon; //0x09E8
		char pad_09F0[40]; //0x09F0
		uint8_t Occluded; //0x0A18
		char pad_0A19[1607]; //0x0A19
	}; //Size: 0x1060



	class ClientPlayer
	{
	public:
		char pad_0000[24]; //0x0000
		char* Name; //0x0018
		char pad_0020[56]; //0x0020
		int Team; //0x0058
		char pad_005C[420]; //0x005C
		void* attachedControllable; //0x0200
		char pad_0208[8]; //0x0208
		ClientSoldier* controlledControllable; //0x0210
		char pad_0218[4660]; //0x0218
		int Score; //0x144c
		int Unknown; //0x1450
		int Kills; //0x1454
		int Assists; //0x1458
		int Deaths; //0x145C

		bool IsValid() {
			return(IsValidPtr(this) && IsValidPtr(this->Name));
		}
	}; //Size: 0x1040

	class MppPlayer
	{
	public:
		class ClientPlayer* PlayerArray[40]; //0x0000

	}; //Size: 0x0220

	class PlayerManager
	{
	public:
		char pad_0000[1384]; //0x0000
		class ClientPlayer* LocalPlayer; //0x0568
		char pad_0570[504]; //0x0570
		class MppPlayer* mppPlayer; //0x0768
		char pad_0770[6888]; //0x0770

		ClientPlayer* GetLocalPlayer() {
			if (IsValidPtr(this) && IsValidPtr(this->LocalPlayer)) {
				return this->LocalPlayer;
			}
		}
		MppPlayer* GetmPPlayer() {
			if (IsValidPtr(this) && IsValidPtr(this->mppPlayer)) {
				return this->mppPlayer;
			}
		}

		ClientPlayer* GetPlayerByID(int index) {
			if (IsValidPtr(this) && IsValidPtr(this->mppPlayer) && IsValidPtr(this->mppPlayer->PlayerArray[index])) {
				return this->mppPlayer->PlayerArray[index];
			}
			return nullptr;
		}

	}; //Size: 0x2258

	class FiringPatternData
	{
	public:
		char pad_0000[8]; //0x0000
		int32_t m_ID; //0x0008
		int32_t m_WeaponClass; //0x000C
		int32_t m_Intensity; //0x0010
		int32_t m_Delay; //0x0014
		char pad_0018[48]; //0x0018
	}; //Size: 0x0048

	class FiringPatternCollectionData
	{
	public:
		char pad_0000[32]; //0x0000
		class FiringPatternData* m_FiringPatterns[1]; //0x0020
		char pad_0028[24]; //0x0028
	}; //Size: 0x0040

	class TargetingData
	{
	public:
		char pad_0000[48]; //0x0000
		float N00002530; //0x0030
		float N0000255B; //0x0034
		float N00002531; //0x0038
		char pad_003C[4]; //0x003C
		float N00002532; //0x0040
		float m_AquiredTimer; //0x0044
		float N00002533; //0x0048
		float m_AquiredDistanceScale; //0x004C
		float m_TargetAimingTimer; //0x0050
		char pad_0054[244]; //0x0054
	}; //Size: 0x0148

	class PreferedRange
	{
	public:
		char pad_0000[24]; //0x0000
		float m_Start; //0x0018
		float m_Ideal; //0x001C
		float m_End; //0x0020
		char pad_0024[100]; //0x0024
	}; //Size: 0x0088

	class BattleAISystemData
	{
	public:
		char pad_0000[48]; //0x0000
		class FiringPatternCollectionData* firingPatternCollectionData; //0x0030
		class TargetingData* TargetingData; //0x0038
		class PreferedRange* preferedRange; //0x0040
		char pad_0048[248]; //0x0048
	}; //Size: 0x0140

	class LevelData
	{
	public:
		char pad_0000[176]; //0x0000
		class BattleAISystemData* battleAISystemData; //0x00B0
		char pad_00B8[912]; //0x00B8
	}; //Size: 0x0448

	class WSFactionAsset
	{
	public:
		char pad_0000[24]; //0x0000
		char* factionName; //0x0018
		char pad_0020[32]; //0x0020
	}; //Size: 0x0040

	class WSSoldierCustomizationClassAsset
	{
	public:
		char pad_0000[24]; //0x0000
		char* name; //0x0018
		char pad_0020[104]; //0x0020
	}; //Size: 0x0088

	class UnlockAssetBase
	{
	public:
		char pad_0000[24]; //0x0000
		char* m_UnlockName; //0x0018
		char* m_DebugUnlockId; //0x0020
		char pad_0028[88]; //0x0028
	}; //Size: 0x0080

	class PlayerAbilityAsset
	{
	public:
		char pad_0000[24]; //0x0000
		char* m_AbilityName; //0x0018
		int32_t m_Category; //0x0020
		char pad_0024[4]; //0x0024
		class UnlockAssetBase* m_Unlock; //0x0028
		char pad_0030[280]; //0x0030
	}; //Size: 0x0148

	class PlayerAbilities
	{
	public:
		class PlayerAbilityAsset* m_AllPlayerAbilities[3096]; //0x0000
		char pad_60C0[64]; //0x60C0
	}; //Size: 0x6100

	class PlayerAbilityCollection
	{
	public:
		char pad_0000[24]; //0x0000
		class PlayerAbilities* abilities; //0x0018
		char pad_0020[40]; //0x0020
	}; //Size: 0x0048

	class PlayerAbilityAssetList
	{
	public:
		class PlayerAbilityAsset* abilties[50]; //0x0000
		char pad_0190[64]; //0x0190
	}; //Size: 0x01D0

	class N00002CA1
	{
	public:
		char pad_0000[32]; //0x0000
		class PlayerAbilityCollection* m_AllAbilities; //0x0020
		char pad_0028[24]; //0x0028
		class PlayerAbilityAssetList* m_Emotes; //0x0040
		class PlayerAbilityAssetList* m_VictoryPoses; //0x0048
		char pad_0050[8]; //0x0050
	}; //Size: 0x0058

	class WSSoldierCustomizationGameplayAsset
	{
	public:
		char pad_0000[40]; //0x0000
		class WSSoldierCustomizationClassAsset* m_Class; //0x0028
		class N00002CA1* N00002C67; //0x0030
		char pad_0038[32]; //0x0038
		char* m_KillswitchName; //0x0058
		char pad_0060[232]; //0x0060
	}; //Size: 0x0148

	class CharacterPhysicsData
	{
	public:
		char pad_0000[24]; //0x0000
		char* name; //0x0018
		char pad_0020[48]; //0x0020
		float m_Mass; //0x0050
		char pad_0054[52]; //0x0054
	}; //Size: 0x0088

	class SoldierSprintSettingsData
	{
	public:
		char pad_0000[32]; //0x0000
		float m_FOV; //0x0020
		float m_FovInDelay; //0x0024
		float m_FOVInTime; //0x0028
		float m_FOVOutDelay; //0x002C
		float m_FOVOutTime; //0x0030
		char pad_0034[20]; //0x0034
	}; //Size: 0x0048

	class SoldierEntityData
	{
	public:
		char pad_0000[256]; //0x0000
		class CharacterPhysicsData* characterPhysicsData; //0x0100
		class SoldierSprintSettingsData* soldierSprintSettingsData; //0x0108
		char pad_0110[1840]; //0x0110
	}; //Size: 0x0840

	class CharacterBlueprint
	{
	public:
		char pad_0000[24]; //0x0000
		char* name; //0x0018
		char pad_0020[56]; //0x0020
		class SoldierEntityData* soldierEntityData; //0x0058
		char pad_0060[232]; //0x0060
	}; //Size: 0x0148

	class ObjectBlueprint
	{
	public:
		char pad_0000[24]; //0x0000
		char* name; //0x0018
		char pad_0020[96]; //0x0020
	}; //Size: 0x0080

	class VisualUnlockRootAsset
	{
	public:
		char pad_0000[24]; //0x0000
		char* SkinName; //0x0018
		char* SkinVUR; //0x0020
		char pad_0028[1056]; //0x0028
	}; //Size: 0x0448

	class Appearances
	{
	public:
		class VisualUnlockRootAsset* m_Apperances[5]; //0x0000
		char pad_0028[64]; //0x0028
	}; //Size: 0x0068

	class WSSoldierCustomizationKitAsset
	{
	public:
		char pad_0000[24]; //0x0000
		char* m_Name; //0x0018
		char pad_0020[40]; //0x0020
		class WSSoldierCustomizationGameplayAsset* m_SoldierCustomizationGameplayAsset; //0x0048
		class CharacterBlueprint* m_Blueprint; //0x0050
		char pad_0058[8]; //0x0058
		class ObjectBlueprint* m_UIBlueprint; //0x0060
		class Appearances* appearances; //0x0068
		char pad_0070[216]; //0x0070
	}; //Size: 0x0148

	class SoldierCustomization
	{
	public:
		class WSSoldierCustomizationKitAsset* m_Kits[10]; //0x0000
		char pad_0050[56]; //0x0050
	}; //Size: 0x0088

	class WSSoldierCustomizationKitList
	{
	public:
		char pad_0000[32]; //0x0000
		class SoldierCustomization* soldierCustomization; //0x0020
		char pad_0028[32]; //0x0028
	}; //Size: 0x0048

	class WSTeamData
	{
	public:
		char pad_0000[24]; //0x0000
		char* teamName; //0x0018
		char pad_0020[32]; //0x0020
		class WSFactionAsset* m_WSFaction; //0x0040
		class WSSoldierCustomizationKitList* m_Soldiers; //0x0048
		class WSSoldierCustomizationKitList* m_Heros; //0x0050
		class WSSoldierCustomizationKitList* m_SpecialSoldiers; //0x0058
		char pad_0060[96]; //0x0060
		class PlayerAbilities* playerAbilties; //0x00C0
		char pad_00C8[112]; //0x00C8
	}; //Size: 0x0138

	class TeamEntityData
	{
	public:
		char pad_0000[40]; //0x0000
		class WSTeamData* teamLight; //0x0028
		char pad_0030[40]; //0x0030
		class WSTeamData* teamDark; //0x0058
		char pad_0060[232]; //0x0060
	}; //Size: 0x0148

	class TeamData
	{
	public:
		char pad_0000[16]; //0x0000
		class TeamEntityData* teamEntityData; //0x0010
		char pad_0018[304]; //0x0018
	}; //Size: 0x0148

	class MatchInfo
	{
	public:
		char pad_0000[8]; //0x0000
		char* gameMode; //0x0008
		char pad_0010[1064]; //0x0010
	}; //Size: 0x0438

	class ClientLevel
	{
	public:
		char pad_0000[32]; //0x0000
		class LevelData* levelData; //0x0020
		class TeamData* teamData; //0x0028
		class MatchInfo* matchInfo; //0x0030
		char* LevelName; //0x0038
		char pad_0040[184]; //0x0040
		class PhysicsManager* physicsManager; //0x00F8
		char pad_0100[840]; //0x0100
	}; //Size: 0x0448

	class GameContext
	{
	public:
		char pad_0000[56]; //0x0000
		ClientLevel* clientLevel; //0x0038
		char pad_0040[24]; //0x0040
		class PlayerManager* playerManager; //0x0058
		char pad_0060[232]; //0x0060

		PlayerManager* GetPlayerManager() {
			if (IsValidPtr(this) && IsValidPtr(this->playerManager)) {
				return this->playerManager;
			}
		}
		static GameContext* GetInstance() {
			return *(GameContext**)SigScan::Get_OFFSET_CLIENTGAMECONTEXT();
		}

	}; //Size: 0x0148

	class GameRenderSettings
	{
	public:
		char pad_0000[40]; //0x0000
		float m_ResolutionScale; //0x0028
		char pad_002C[32]; //0x002C
		float m_FOV; //0x004C
		char pad_0050[664]; //0x0050
	}; //Size: 0x02E8

	/*class RenderView
	{
	public:
		char pad_0000[800]; //0x0000
		D3DXVECTOR3 CameraPos; //0x0320
		char pad_032C[260]; //0x032C
		Matrix4x4 viewProj; //0x0430
		char pad_0470[288]; //0x0470
	}; //Size: 0x0590*/

	class GameRenderer
	{
	public:
		char pad_0000[1304]; //0x0000
		class GameRenderSettings* gameRenderSettings; //0x0518
		char pad_0520[24]; //0x0520
		/*class RenderView**/void* renderView; //0x0538
		static GameRenderer* GetInstance()
		{
			return *(GameRenderer**)SigScan::Get_OFFSET_GAMERENDERER();
		}
	}; //Size: 0x0C48
}
