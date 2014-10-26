// Game.h: interface for the CGame class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAME_H__C3D29FC5_755B_11D2_A8E6_00001C7030A6__INCLUDED_)
#define AFX_GAME_H__C3D29FC5_755B_11D2_A8E6_00001C7030A6__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif

#include <windows.h>
#include <winbase.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <memory.h>
#include <direct.h>
#include <vector>

#include "winmain.h"
#include "StrTok.h"
#include "Xsocket.h"
#include "Client.h"
#include "Npc.h"
#include "Map.h"
#include "ActionID.h"
#include "UserMessages.h"
#include "NetMessages.h"
#include "MessageIndex.h"
#include "Misc.h"
#include "Msg.h"
#include "Magic.h"
#include "Skill.h"
#include "DynamicObject.h"
#include "DelayEvent.h"
#include "Version.h"
#include "Fish.h"
#include "DynamicObject.h"
#include "DynamicObjectID.h"
#include "Portion.h"
#include "Mineral.h"
#include "Quest.h"
#include "BuildItem.h"
#include "TeleportLoc.h"
#include "GlobalDef.h"
#include "Teleport.h"
#include "Crafting.h"

#define DEF_MAXADMINS				50
#define DEF_MAXMAPS					100
#define DEF_MAXAGRICULTURE			200
#define DEF_MAXNPCTYPES				200
#define DEF_MAXBUILDITEMS			300
#define DEF_SERVERSOCKETBLOCKLIMIT	300
#define DEF_MAXBANNED				500
#define DEF_MAXCLIENTS				2000
#define DEF_MAXNPCS					5000
#define DEF_MAXITEMTYPES			5000
#define DEF_CLIENTTIMEOUT			10000
#define DEF_SPUPTIME				10000
#define DEF_POISONTIME				12000
#define DEF_HPUPTIME				15000
#define DEF_MPUPTIME				20000
#define DEF_HUNGERTIME				60000
#define DEF_NOTICETIME				80000
#define DEF_SUMMONTIME				300000
#define DEF_AUTOSAVETIME			60000*3
//morla1 AFK CHECKER
#define DEF_AFKTIME               150000 // 2 o 1 min no lo probe

#define DEF_EXPSTOCKTIME		1000*10		// ExpStock을 계산하는 시간 간격 
#define DEF_MSGQUENESIZE		100000		// 메시지 큐 사이즈 10만개 
#define DEF_AUTOEXPTIME			1000*60*6	// 자동으로 경험치가 올라가는 시간간격 
#define DEF_TOTALLEVELUPPOINT	3			// 레벨업시 할당하는 총 포인트 수 


#define DEF_MAXDYNAMICOBJECTS	60000
#define DEF_MAXDELAYEVENTS		60000
#define DEF_GUILDSTARTRANK		12

#define DEF_SSN_LIMIT_MULTIPLY_VALUE	2	// SSN-limit 곱하는 수 

#define DEF_MAXNOTIFYMSGS		300			// 최대 공지사항 메시지 
#define DEF_MAXSKILLPOINTS		2400		// Morla 2.3 - Max Skills
#define DEF_NIGHTTIME			40

#define DEF_CHARPOINTLIMIT		1000		// 각각의 특성치의 최대값 
#define DEF_RAGPROTECTIONTIME	7000		// 몇 초 이상 지나면 랙으로 부터 보호를 받는지 
#define DEF_MAXREWARDGOLD		99999999	// 포상금 최대치 

#define DEF_ATTACKAI_NORMAL				1	// 무조건 공격 
#define DEF_ATTACKAI_EXCHANGEATTACK		2	// 교환 공격 - 후퇴 
#define DEF_ATTACKAI_TWOBYONEATTACK		3	// 2-1 공격, 후퇴 

#define DEF_MAXFISHS					200
#define DEF_MAXMINERALS					200
#define	DEF_MAXCROPS					200
#define DEF_MAXENGAGINGFISH				30  // 한 물고기에 낚시를 시도할 수 있는 최대 인원 
#define DEF_MAXPORTIONTYPES				500 // 최대 포션 정의 갯수
#define DEF_MAXCRAFTINGTYPES				500

#define DEF_SPECIALEVENTTIME			300000 //600000 // 10분
#define DEF_MAXQUESTTYPE				200

#define DEF_MAXSUBLOGSOCK				10

#define DEF_ITEMLOG_GIVE				1
#define DEF_ITEMLOG_DROP				2
#define DEF_ITEMLOG_GET					3
#define DEF_ITEMLOG_DEPLETE				4
#define DEF_ITEMLOG_NEWGENDROP			5
#define DEF_ITEMLOG_DUPITEMID			6

// New 07/05/2004
#define DEF_ITEMLOG_BUY					7
#define DEF_ITEMLOG_SELL				8
#define DEF_ITEMLOG_RETRIEVE			9
#define DEF_ITEMLOG_DEPOSIT				10
#define DEF_ITEMLOG_EXCHANGE			11
#define DEF_ITEMLOG_MAKE				13
#define DEF_ITEMLOG_SUMMONMONSTER		14
#define DEF_ITEMLOG_POISONED			15
#define DEF_ITEMLOG_REPAIR				17
#define DEF_ITEMLOG_SKILLLEARN			12
#define DEF_ITEMLOG_MAGICLEARN			16
#define DEF_ITEMLOG_USE					32
#define DEF_ITEMEFFECTTYPE_TICKETLOTERIA   33

//apocalypse
//#define DEF_CRUSADELOG_APOCALYPSE		21

#define DEF_CRUSADELOG_ENDHELDENIAN		11
#define DEF_CRUSADELOG_STARTHELDENIAN	12
#define DEF_CRUSADELOG_GETHELDENIANEXP	14
#define DEF_CRUSADELOG_HELDENIANVICTORY	15
#define DEF_CRUSADELOG_HELDENIANWARNOW	16
#define DEF_CRUSADELOG_STARTHAPPYHOUR	17
#define DEF_CRUSADELOG_ENDHAPPYHOUR		18

#define DEF_RECALLTIMEDAMAGE			1000*15  // MORLA 2.11 - tiempo para hacer recall

#define DEF_MAXDUPITEMID				100

#define DEF_MAXGUILDS					1000 // 동시에 접속할 수 있는 길드수 
#define DEF_MAXONESERVERUSERS			800	// 800 // 한 서버에서 허용할 수 있는 최대 사용자수. 초과된 경우 부활존 혹은 블리딩 아일, 농경지로 보내진다.

#define DEF_MAXGATESERVERSTOCKMSGSIZE	10000

#define DEF_MAXCONSTRUCTNUM				10
#define DEF_MAXSCHEDULE					10


//v1.4311-3  사투장의 최대 숫자
#define DEF_MAXFIGHTZONE 10 

//============================
#define DEF_LEVELLIMIT		20				// 체험판 레벨 제한치!!!			
//============================

//============================
#define DEF_MINIMUMHITRATIO 15				// 최저 명중 확률 
//============================		

//============================
#define DEF_MAXIMUMHITRATIO	99				// 최대 명중 확률
//============================

//============================
#define DEF_PLAYERMAXLEVEL	200				// Morla 2.3 - LVL Maximo
//============================

//============================
// New Changed 12/05/2004
#define DEF_GMGMANACONSUMEUNIT	15			// Grand Magic Generator 마나 흡수 단위.
//============================

#define DEF_MAXCONSTRUCTIONPOINT 30000		// 최대 소환 포인트 
#define DEF_MAXSUMMONPOINTS		 30000

#define DEF_MAXHELDENIANSUMMONPOINT		12000
#define MAX_HELDENIANTOWER			200
#define DEF_DEF_MAXHELDENIANDOOR			10
#define DEF_MAXHELDENIAN				10
#define DEF_MAXWARCONTRIBUTION	 200000

#define DEF_MAXPARTYNUM			5000

#define MSGID_LEVELUPSETTINGS				0x11A01000
#define MSGID_STATECHANGEPOINT				0x11A01001

#define DEF_STR 0x01 //Correct
#define DEF_DEX 0x02 //Correct
#define DEF_INT	0x03 //Correct
#define DEF_VIT 0x04 //Correct
#define DEF_MAG	0x05 //Correct
#define DEF_CHR 0x06 //Correct

class CGame  
{
public:

        //morla1 - AFK CHECKER
    	void AFKChecker();

        //void PlayerOrder_GetSkills(int iClientH);
        BOOL _bDecodeWorldConfig(char *pFn);

        void AdminOrder_CheckPlayer(int iClientH, char* pData, DWORD dwMsgSize);

        // D2 Teleport Handler
        void RequestTeleportListHandler(int iClientH, char * pData, DWORD dwMsgSize);
        void RequestChargedTeleportHandler(int iClientH, char *pData, DWORD dwMsgSize);
        BOOL _bDecodeTeleportConfig(char *pFn);

        void AdminOrder_BanIp(int iClientH, char *pData, DWORD dwMsgSize);

        void AdminOrder_EnableAdminAttack(int iClientH, char *pData, DWORD dwMsgSize);

	// Apocalypse
	void GlobalStartApocalypseMode(int iClientH, char *pData, DWORD dwMsgSize);
	void GlobalEndApocalypseMode();
	void LocalStartApocalypseMode(DWORD dwApocalypseGUID);
	void LocalEndApocalypseMode();
	void _CreateApocalypseGUID(DWORD dwApocalypseGUID);
	BOOL bReadApocalypseGUIDFile(char * cFn);
        void DoAbaddonThunderDamageHandler(char cMapIndex);
        void SendThunder(int iClient, short sX, short sY, short sV3, short sV4);
        //~Apocalypse

        void SetAngelFlag(short sOwnerH, char cOwnerType, int iStatus, int iTemp);
        void GetAngelHandler(int iClientH, char * pData, DWORD dwMsgSize);

        void PlayerOrder_GetDkSet(int iClientH);
        int iUpgradeHeroCapeRequirements(int iClientH, int iItemIndex);
        int HeroItemChecker(int iItemID, short sEnemyKill, char cContribution, char cSide);
	void AdminOrder_GetFightzoneTicket(int iClientH);

	BOOL _bCheckCharacterData(int iClientH);
	void GlobalUpdateConfigs(char cConfigType);
	void LocalUpdateConfigs(char cConfigType);
	void SetHeroFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SetInhibitionCastingFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void CalculateEnduranceDecrement(short sTargetH, short sAttackerH, char cTargetType, int iArmorType);
	char _cCheckHeroItemEquipped(int iClientH);
	BOOL bPlantSeedBag(int iMapIndex, int dX, int dY, int iItemEffectValue1, int iItemEffectValue2, int iClientH);
	void _CheckFarmingAction(short sAttackerH, short sTargetH, BOOL bType);
	BOOL bReadScheduleConfigFile(char *pFn);
	void CheckDenialServiceAttack(int iClientH, DWORD dwClientTime);




	///////////////////////////////////////////////////////////
	//         H E L D E N I A N    C O D E                  //
	///////////////////////////////////////////////////////////
	void HeldenianWarStarter();
	BOOL bReadHeldenianGUIDFile(char * cFn);
	void GlobalEndHeldenianMode();
	void LocalEndHeldenianMode(DWORD dwHeldenianGUID, int iWinner);
	BOOL bNotifyHeldenianWinner();
	void RemoveHeldenianNpc(int iNpcH);
	void _CreateHeldenianGUID(DWORD dwHeldenianGUID, int iWinnerSide);
	BOOL bCheckHeldenianMap(int sAttackerH, int iMapIndex, char cType);
	void GlobalStartHeldenianMode();
	void LocalStartHeldenianMode(short sV1, short sV2, DWORD dwHeldenianGUID);
	void ManualStartHeldenianMode(int iClientH, char *pData, DWORD dwMsgSize);
	void ManualStartHappyHour(int iClientH, char *pData, DWORD dwMsgSize);
	void ManualEndHeldenianMode(int iClientH, char *pData, DWORD dwMsgSize);
	void SetHeldenianMode();
	BOOL UpdateHeldenianStatus(int iClientH);
	void HeldenianEndWarNow();
	void HeldenianVictoryNow(int iSide);
	void CheckHeldenianResultCalculation(int iClientH);
	void RemoveOccupyFlags(int iMapIndex);
	void HeldenianStartWarNow();
	BOOL __bSetOccupyFlag(char cMapIndex, int dX, int dY, int iSide, int iEKNum, int iClientH, BOOL bAdminFlag);
	void RequestHeldenianTeleportList(int iClientH, char * pData, DWORD dwMsgSize);
	void RequestHeldenianScroll(int iClientH, char * pData, DWORD dwMsgSize);
	void RequestHeldenianTeleportNow(int iClientH, char * pData, DWORD dwMsgSize);
	char m_cHeldenianMapName[11];
	///////////////////////////////////////////////////////////
	//       H E L D E N I A N    C O D E   E N D            //
	///////////////////////////////////////////////////////////
	// KLKS clean tiles
	void AdminOrder_CleanMap(int iClientH, char * pData, DWORD dwMsgSize);
	
	// Lists
	BOOL bReadBannedListConfigFile(char *pFn);
	BOOL bReadAdminListConfigFile(char *pFn);

	void AdminOrder_CheckStats(int iClientH, char *pData,DWORD dwMsgSize);
        
        BOOL _bDecodeCraftingConfig(char *pFn);
        void ReqCreateCraftingHandler(int iClientH, char *pData);

	// Crusade
	void ManualEndCrusadeMode(int iWinnerSide); // 2.17 (x) 2.14 ( )
	void CrusadeWarStarter();
	BOOL bReadCrusadeGUIDFile(char * cFn);
	void _CreateCrusadeGUID(DWORD dwCrusadeGUID, int iWinnerSide);
	void GlobalStartCrusadeMode();
	void GSM_SetGuildTeleportLoc(int iGuildGUID, int dX, int dY, char * pMapName);
	void SyncMiddlelandMapInfo();
	void RemoveCrusadeStructures();
	void _SendMapStatus(int iClientH);
	void MapStatusHandler(int iClientH, int iMode, char * pMapName);
	void SelectCrusadeDutyHandler(int iClientH, int iDuty);
	void RequestSummonWarUnitHandler(int iClientH, int dX, int dY, char cType, char cNum, char cMode);
	void RequestGuildTeleportHandler(int iClientH);
	void RequestSetGuildTeleportLocHandler(int iClientH, int dX, int dY, int iGuildGUID, char * pMapName);
	void MeteorStrikeHandler(int iMapIndex);
	void _LinkStrikePointMapIndex();
	void MeteorStrikeMsgHandler(char cAttackerSide);
	void _NpcBehavior_GrandMagicGenerator(int iNpcH);
	void CollectedManaHandler(WORD wAresdenMana, WORD wElvineMana);
	void SendCollectedMana();
	void CreateCrusadeStructures();
	void _GrandMagicLaunchMsgSend(int iType, char cAttackerSide);
	void GrandMagicResultHandler(char *cMapName, int iCrashedStructureNum, int iStructureDamageAmount, int iCasualities, int iActiveStructure, int iTotalStrikePoints, char * cData);
	void CalcMeteorStrikeEffectHandler(int iMapIndex);
	void DoMeteorStrikeDamageHandler(int iMapIndex);
	void RequestSetGuildConstructLocHandler(int iClientH, int dX, int dY, int iGuildGUID, char * pMapName);
	void GSM_SetGuildConstructLoc(int iGuildGUID, int dX, int dY, char * pMapName);
	void GSM_ConstructionPoint(int iGuildGUID, int iPoint);
	void CheckCommanderConstructionPoint(int iClientH);
	BOOL bReadCrusadeStructureConfigFile(char * cFn);
	void SaveOccupyFlagData();
	void LocalEndCrusadeMode(int iWinnerSide);
	void LocalStartCrusadeMode(DWORD dwGuildGUID);
	void CheckCrusadeResultCalculation(int iClientH);
	BOOL _bNpcBehavior_Detector(int iNpcH);
	BOOL _bNpcBehavior_ManaCollector(int iNpcH);
	BOOL __bSetConstructionKit(int iMapIndex, int dX, int dY, int iType, int iTimeCost, int iClientH);

	void AdminOrder_SummonGuild(int iClientH, char * pData, DWORD dwMsgSize);

	// Acidx commands
	void AdminOrder_Time(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_CheckRep(int iClientH, char *pData);
	void AdminOrder_Pushplayer(int iClientH, char * pData, DWORD dwMsgSize);

	void AdminOrder_CheckRep(int iClientH, char *pData,DWORD dwMsgSize);

	void SetForceRecallTime(int iClientH);
	void ApplyCombatKilledPenalty(int iClientH, int cPenaltyLevel, BOOL bIsSAattacked);

	//	void AdminOrder_ClearTiles(int iClientH);
	void AdminOrder_ClearNpc(int iClientH);

	// Settings.cfg
	BOOL bReadSettingsConfigFile(char * cFn);
	
	// Daryl - AdminSettings.cfg
	BOOL bReadAdminSetConfigFile(char * cFn);


	// Hack Checks
	BOOL bCheckClientMoveFrequency(int iClientH, DWORD dwClientTime);
	BOOL bCheckClientMagicFrequency(int iClientH, DWORD dwClientTime);
	BOOL bCheckClientAttackFrequency(int iClientH, DWORD dwClientTime);

	// BOOL bCheckClientInvisibility(short iClientH);

	//Hypnotoad functions
	void SetDefenseShieldFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SetMagicProtectionFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SetProtectionFromArrowFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SetIllusionMovementFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SetIllusionFlag(short sOwnerH, char cOwnerType, BOOL bStatus);

	void RequestChangePlayMode(int iClientH);
	void GetHeroMantleHandler(int iClientH,int iItemID,char * pString);
	void AdminOrder_Weather(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_SendMSG(int iClientH, char *pData, DWORD dwMsgSize);
	void SendMsg(short sOwnerH, char cOwnerType, BOOL bStatus, long lPass);
	BOOL bCheckMagicInt(int iClientH);
	BOOL bChangeState(char cStateChange, char* cStr, char *cVit,char *cDex,char *cInt,char *cMag,char *cChar);
	void StateChangeHandler(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_SetStatus(int iClientH, char *pData, DWORD dwMsgSize);
	void SetStatusFlag(short sOwnerH, char cOwnerType, BOOL bStatus, int iPass);
	void SetPoisonFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void AdminOrder_SummonStorm(int iClientH, char* pData, DWORD dwMsgSize);
	void AdminOrder_CallMagic(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_SummonDeath(int iClientH);
	void AdminOrder_SetZerk(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_SetFreeze(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_Kill(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_Revive(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_SetObserverMode(int iClientH);
	void AdminOrder_EnableAdminCommand(int iClientH, char *pData, DWORD dwMsgSize);
	void AdminOrder_CreateItem(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_Summon(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_SummonAll(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_SummonPlayer(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_UnsummonDemon(int iClientH);
	void AdminOrder_UnsummonAll(int iClientH);
	void AdminOrder_SetAttackMode(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_SummonDemon(int iClientH);
	void AdminOrder_SetInvi(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_Polymorph(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_GetNpcStatus(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_CheckIP(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_CreateFish(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_Teleport(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_ReserveFightzone(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_CloseConn(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_CallGuard(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_DisconnectAll(int iClientH, char * pData, DWORD dwMsgSize);

	BOOL bCopyItemContents(class CItem * pOriginal, class CItem * pCopy);
	int  iGetMapLocationSide(char * pMapName);
	void ChatMsgHandlerGSM(int iMsgType, int iV1, char * pName, char * pData, DWORD dwMsgSize);
	void RemoveClientShortCut(int iClientH);
	BOOL bAddClientShortCut(int iClientH);

	void GSM_RequestFindCharacter(WORD wReqServerID, WORD wReqClientH, char *pName, char * pFinder); // New 16/05/2001 Changed
	void ServerStockMsgHandler(char * pData);
	void SendStockMsgToGateServer();
	BOOL bStockMsgToGateServer(char * pData, DWORD dwSize);
	void RequestHelpHandler(int iClientH);
	
	void CheckConnectionHandler(int iClientH, char *pData);

	void AgingMapSectorInfo();
	void UpdateMapSectorInfo();
	//BOOL bGetItemNameWhenDeleteNpc(char * pItemName, short sNpcType);
	BOOL bGetItemNameWhenDeleteNpc(int & iItemID, short sNpcType, int iItemprobability);
	int iGetItemWeight(class CItem * pItem, int iCount);
	void CancelQuestHandler(int iClientH);
	void ActivateSpecialAbilityHandler(int iClientH);
	void EnergySphereProcessor(BOOL bIsAdminCreate = FALSE, int iClientH = NULL);
	BOOL bCheckEnergySphereDestination(int iNpcH, short sAttackerH, char cAttackerType);
	void _DeleteRandomOccupyFlag(int iMapIndex);
	void RequestSellItemListHandler(int iClientH, char * pData);
	void RequestRestartHandler(int iClientH);
	int iRequestPanningMapDataRequest(int iClientH, char * pData);
	void GetMagicAbilityHandler(int iClientH);
	void Effect_Damage_Spot_DamageMove(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sAtkX, short sAtkY, short sV1, short sV2, short sV3, BOOL bExp, int iAttr);
	void _TamingHandler(int iClientH, int iSkillNum, char cMapIndex, int dX, int dY);
	void RequestCheckAccountPasswordHandler(char * pData, DWORD dwMsgSize);
	int _iTalkToNpcResult_Guard(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	void SetIceFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void _bDecodeNoticementFileContents(char * pData, DWORD dwMsgSize);
	void RequestNoticementHandler(int iClientH, char * pData);
	void _AdjustRareItemValue(class CItem * pItem);
	BOOL _bCheckDupItemID(class CItem * pItem);
	BOOL _bDecodeDupItemIDFileContents(char * pData, DWORD dwMsgSize);
	void NpcDeadItemGenerator(int iNpcH, short sAttackerH, char cAttackerType);
	int  iGetPlayerABSStatus(int iWhatH, int iRecvH);
	void CheckSpecialEvent(int iClientH);
	char _cGetSpecialAbility(int iKindSA);
	void BuildItemHandler(int iClientH, char * pData);
	BOOL _bDecodeBuildItemConfigFileContents(char * pData, DWORD dwMsgSize);
	BOOL _bCheckSubLogSocketIndex();
	void _CheckGateSockConnection();
	void OnSubLogRead(int iIndex);
	void OnSubLogSocketEvent(UINT message, WPARAM wParam, LPARAM lParam);
	void _CheckStrategicPointOccupyStatus(char cMapIndex);
	void GetMapInitialPoint(int iMapIndex, short * pX, short * pY, char * pPlayerLocation = NULL);
	int  iGetMaxHP(int iClientH);
	int  iGetMaxMP(int iClientH);
	int  iGetMaxSP(int iClientH);
	void _ClearQuestStatus(int iClientH);
	BOOL _bCheckItemReceiveCondition(int iClientH, class CItem * pItem);
	void SendItemNotifyMsg(int iClientH, WORD wMsgType, class CItem * pItem, int iV1);
	
	int _iTalkToNpcResult_WTower(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	int _iTalkToNpcResult_WHouse(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	int _iTalkToNpcResult_BSmith(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	int _iTalkToNpcResult_GShop(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	int _iTalkToNpcResult_GuildHall(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	BOOL _bCheckIsQuestCompleted(int iClientH);
	void _CheckQuestEnvironment(int iClientH);
	void _SendQuestContents(int iClientH);
	void QuestAcceptedHandler(int iClientH);
	BOOL _bDecodeQuestConfigFileContents(char * pData, DWORD dwMsgSize);
	
	void CancelExchangeItem(int iClientH);
	BOOL bAddItem(int iClientH, class CItem * pItem, char cMode);
	void ConfirmExchangeItem(int iClientH);
	void SetExchangeItem(int iClientH, int iItemIndex, int iAmount);
	void ExchangeItemHandler(int iClientH, short sItemIndex, int iAmount, short dX, short dY, WORD wObjectID, char * pItemName);

	void _BWM_Command_Shutup(char * pData);
	void _BWM_Init(int iClientH, char * pData);
	void CheckUniqueItemEquipment(int iClientH);
	void _SetItemPos(int iClientH, char * pData);
	//void GetHeroMantleHandler(int iClientH);
	
	BOOL _bDecodeOccupyFlagSaveFileContents(char * pData, DWORD dwMsgSize);
	void GetOccupyFlagHandler(int iClientH);
	int  _iComposeFlagStatusContents(char * pData);
	void SetSummonMobAction(int iClientH, int iMode, DWORD dwMsgSize, char * pData = NULL);
	BOOL _bDepleteDestTypeItemUseEffect(int iClientH, int dX, int dY, short sItemIndex, short sDestItemID);
	void SetDownSkillIndexHandler(int iClientH, int iSkillIndex);
	int iGetComboAttackBonus(int iSkill, int iComboCount);
	int  _iGetWeaponSkillType(int iClientH);
	void CheckFireBluring(char cMapIndex, int sX, int sY);
	void NpcTalkHandler(int iClientH, int iWho);
	BOOL bDeleteMineral(int iIndex);
	void _CheckMiningAction(int iClientH, int dX, int dY);
	int iCreateMineral(char cMapIndex, int tX, int tY, char cLevel);
	void MineralGenerator();
	void LocalSavePlayerData(int iClientH);
	BOOL _bDecodePortionConfigFileContents(char * pData, DWORD dwMsgSize);
	void ReqCreatePortionHandler(int iClientH, char * pData);
	void _CheckAttackType(int iClientH, short * spType);
	BOOL bOnClose();
	void ForceDisconnectAccount(char * pAccountName, WORD wCount);
	void NpcRequestAssistance(int iNpcH);
	void ToggleSafeAttackModeHandler(int iClientH);
	void SetBerserkFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SpecialEventHandler();
	int iGetPlayerRelationship_SendEvent(int iClientH, int iOpponentH);
	int iGetNpcRelationship_SendEvent(int iNpcH, int iOpponentH);
	int _iForcePlayerDisconect(int iNum);
	int iGetMapIndex(char * pMapName);
	//int iGetNpcRelationship(int iClientH, int iOpponentH);
	int iGetNpcRelationship(int iWhatH, int iRecvH);
	int iGetPlayerRelationship(int iClientH, int iOpponentH);
	int iGetWhetherMagicBonusEffect(short sType, char cWheatherStatus);
	void WhetherProcessor();
	int _iCalcPlayerNum(char cMapIndex, short dX, short dY, char cRadius);
	void FishGenerator();
	void ReqGetFishThisTimeHandler(int iClientH);
	void FishProcessor();
	int iCheckFish(int iClientH, char cMapIndex, short dX, short dY);
	BOOL bDeleteFish(int iHandle, int iDelMode);
	int  iCreateFish(char cMapIndex, short sX, short sY, short sDifficulty, class CItem * pItem, int iDifficulty, DWORD dwLastTime);
	void UserCommand_DissmissGuild(int iClientH, char * pData, DWORD dwMsgSize);
	// v1.4311-3 변경 함수 선언  Expire -> Ban 으로 
	void UserCommand_BanGuildsman(int iClientH, char * pData, DWORD dwMsgSize);
	// v1.4311-3 추가 함수 선언 이벤트를 대비하여 운영자가 사투장을 예약해놓는다.
	int iGetExpLevel(int iExp);
	void ___RestorePlayerRating(int iClientH);
	void CalcExpStock(int iClientH);
	void ResponseSavePlayerDataReplyHandler(char * pData, DWORD dwMsgSize);
	void NoticeHandler();
	BOOL bReadNotifyMsgListFile(char * cFn);
	void SetPlayerReputation(int iClientH, char * pMsg, char cValue, DWORD dwMsgSize);
	void ShutUpPlayer(int iClientH, char * pMsg, DWORD dwMsgSize);
	void CheckDayOrNightMode();
	BOOL bCheckBadWord(char * pString);
	BOOL bCheckResistingPoisonSuccess(short sOwnerH, char cOwnerType);
	void PoisonEffect(int iClientH, int iV1);
	void bSetNpcAttackMode(char * cName, int iTargetH, char cTargetType, BOOL bIsPermAttack);
	BOOL _bGetIsPlayerHostile(int iClientH, int sOwnerH);
	BOOL bAnalyzeCriminalAction(int iClientH, short dX, short dY, BOOL bIsCheck = FALSE);
	void RequestAdminUserMode(int iClientH, char * pData);
	int _iGetPlayerNumberOnSpot(short dX, short dY, char cMapIndex, char cRange);
	void CalcTotalItemEffect(int iClientH, int iEquipItemID, BOOL bNotify = TRUE);
	void ___RestorePlayerCharacteristics(int iClientH);
	void GetPlayerProfile(int iClientH, char * pMsg, DWORD dwMsgSize);
	void SetPlayerProfile(int iClientH, char * pMsg, DWORD dwMsgSize);
	void ToggleWhisperPlayer(int iClientH, char * pMsg, DWORD dwMsgSize);
	void CheckAndNotifyPlayerConnection(int iClientH, char * pMsg, DWORD dwSize);
	int iCalcTotalWeight(int iClientH);
	void ReqRepairItemCofirmHandler(int iClientH, char cItemID, char * pString);
	void ReqRepairItemHandler(int iClientH, char cItemID, char cRepairWhom, char * pString);
	void ReqSellItemConfirmHandler(int iClientH, char cItemID, int iNum, char * pString);
	void ReqSellItemHandler(int iClientH, char cItemID, char cSellToWhom, int iNum, char * pItemName);
	void UseSkillHandler(int iClientH, int iV1, int iV2, int iV3);
	int  iCalculateUseSkillItemEffect(int iOwnerH, char cOwnerType, char cOwnerSkill, int iSkillNum, char cMapIndex, int dX, int dY);
	void ClearSkillUsingStatus(int iClientH);
	void DynamicObjectEffectProcessor();
	int _iGetTotalClients();
	void SendObjectMotionRejectMsg(int iClientH);
	void SetInvisibilityFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	BOOL bRemoveFromDelayEventList(int iH, char cType, int iEffectType);
	void DelayEventProcessor();
	BOOL bRegisterDelayEvent(int iDelayType, int iEffectType, DWORD dwLastTime, int iTargetH, char cTargetType, char cMapIndex, int dX, int dY, int iV1, int iV2, int iV3);
	int iGetFollowerNumber(short sOwnerH, char cOwnerType);
	int  _iCalcSkillSSNpoint(int iLevel);
	void OnKeyUp(WPARAM wParam, LPARAM lParam);
	void OnKeyDown(WPARAM wParam, LPARAM lParam);
	BOOL bCheckTotalSkillMasteryPoints(int iClientH, int iSkill);
	BOOL bSetItemToBankItem(int iClientH, class CItem * pItem);
	void NpcMagicHandler(int iNpcH, short dX, short dY, short sType);
	BOOL bCheckResistingIceSuccess(char cAttackerDir, short sTargetH, char cTargetType, int iHitRatio);
	BOOL bCheckResistingMagicSuccess(char cAttackerDir, short sTargetH, char cTargetType, int iHitRatio);
	void Effect_SpUp_Spot(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sV1, short sV2, short sV3);
	void Effect_SpDown_Spot(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sV1, short sV2, short sV3);
	void Effect_HpUp_Spot(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sV1, short sV2, short sV3);
	void Effect_Damage_Spot(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sV1, short sV2, short sV3, BOOL bExp, int iAttr = NULL);
	void Effect_Damage_Spot_Type2(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sAtkX, short sAtkY, short sV1, short sV2, short sV3, BOOL bExp, int iAttr);
	void UseItemHandler(int iClientH, short sItemIndex, short dX, short dY, short sDestItemID);
	void NpcBehavior_Stop(int iNpcH);
	void ItemDepleteHandler(int iClientH, short sItemIndex, BOOL bIsUseItemResult);
	int _iGetArrowItemIndex(int iClientH);
	void RequestFullObjectData(int iClientH, char * pData);
	void DeleteNpc(int iNpcH);
	void CalcNextWayPointDestination(int iNpcH);
	void MobGenerator();
	void CalculateSSN_SkillIndex(int iClientH, short sSkillIndex, int iValue);
	void CalculateSSN_ItemIndex(int iClientH, short sWeaponIndex, int iValue);
	void CheckDynamicObjectList();
	int  iAddDynamicObjectList(short sOwner, char cOwnerType, short sType, char cMapIndex, short sX, short sY, DWORD dwLastTime, int iV1 = NULL);
	int _iCalcMaxLoad(int iClientH);
	void GetRewardMoneyHandler(int iClientH);
	void _PenaltyItemDrop(int iClientH, int iTotal, BOOL bIsSAattacked = FALSE);
	//void ApplyCombatKilledPenalty(int iClientH, char cPenaltyLevel, BOOL bIsSAattacked = FALSE);
	void EnemyKillRewardHandler(int iAttackerH, int iClientH);
	void PK_KillRewardHandler(short sAttackerH, short sVictumH);
	void ApplyPKpenalty(short sAttackerH, short sVictumH);
	BOOL bSetItemToBankItem(int iClientH, short sItemIndex);
	void RequestRetrieveItemHandler(int iClientH, char * pData);
	void RequestCivilRightHandler(int iClientH, char * pData);
	BOOL bCheckLimitedUser(int iClientH);
	void LevelUpSettingsHandler(int iClientH, char * pData, DWORD dwMsgSize);
	// v1.4311-3 선언 함수  사투장 예약 함수 선언 FightzoneReserveHandler
	void FightzoneReserveHandler(int iClientH, char * pData, DWORD dwMsgSize);
	BOOL bCheckLevelUp(int iClientH);
	int iGetLevelExp(int iLevel);
	void TimeManaPointsUp(int iClientH);
	void TimeStaminarPointsUp(int iClientH);
	void Quit();
	BOOL __bReadMapInfo(int iMapIndex);
	BOOL bBankItemToPlayer(int iClientH, short sItemIndex);
	BOOL bPlayerItemToBank(int iClientH, short sItemIndex);
	int  _iGetSkillNumber(char * pSkillName);
	void TrainSkillResponse(BOOL bSuccess, int iClientH, int iSkillNum, int iSkillLevel);
	int _iGetMagicNumber(char * pMagicName, int * pReqInt, int * pCost);
	void RequestStudyMagicHandler(int iClientH, char * pName, BOOL bIsPurchase = TRUE);
	BOOL _bDecodeSkillConfigFileContents(char * pData, DWORD dwMsgSize);
	BOOL _bDecodeMagicConfigFileContents(char * pData, DWORD dwMsgSize);
	void ReleaseFollowMode(short sOwnerH, char cOwnerType);
	BOOL bSetNpcFollowMode(char * pName, char * pFollowName, char cFollowOwnerType);
	void RequestTeleportHandler(int iClientH, char * pData, char * cMapName = NULL, int dX = -1, int dY = -1);
	void PlayerMagicHandler(int iClientH, int dX, int dY, short sType, BOOL bItemEffect = FALSE, int iV1 = NULL);
	int  iClientMotion_Magic_Handler(int iClientH, short sX, short sY, char cDir);
	void SendMsgToGateServer(DWORD dwMsg, int iClientH, char * pData = NULL);
	void OnGateRead();
	void OnGateSocketEvent(UINT message, WPARAM wParam, LPARAM lParam);
	void ToggleCombatModeHandler(int iClientH);
	void GuildNotifyHandler(char * pData, DWORD dwMsgSize);
	void SendGuildMsg(int iClientH, WORD wNotifyMsgType, short sV1, short sV2, char * pString);
	void DelayEventProcess();
	void TimeHitPointsUp(int iClientH);
	void CalculateGuildEffect(int iVictimH, char cVictimType, short sAttackerH);
	void OnStartGameSignal();
	int iDice(int iThrow, int iRange);
	BOOL _bInitNpcAttr(class CNpc * pNpc, char * pNpcName, short sClass, char cSA);
	BOOL _bDecodeNpcConfigFileContents(char * pData, DWORD dwMsgSize);
	void ReleaseItemHandler(int iClientH, short sItemIndex, BOOL bNotice);
	void ClientKilledHandler(int iClientH, int iAttackerH, char cAttackerType, short sDamage);
	int  SetItemCount(int iClientH, char * pItemName, DWORD dwCount);
	int  SetItemCount(int iClientH, int iItemIndex, DWORD dwCount);
	DWORD dwGetItemCount(int iClientH, char * pName);
	void DismissGuildRejectHandler(int iClientH, char * pName);
	void DismissGuildApproveHandler(int iClientH, char * pName);
	void JoinGuildRejectHandler(int iClientH, char * pName);			    
	void JoinGuildApproveHandler(int iClientH, char * pName);
	void SendNotifyMsg(int iFromH, int iToH, WORD wMsgType, DWORD sV1, DWORD sV2, DWORD sV3, char * pString, DWORD sV4 = NULL, DWORD sV5 = NULL, DWORD sV6 = NULL, DWORD sV7 = NULL, DWORD sV8 = NULL, DWORD sV9 = NULL, char * pString2 = NULL);
	void GiveItemHandler(int iClientH, short sItemIndex, int iAmount, short dX, short dY, WORD wObjectID, char * pItemName);
	void RequestPurchaseItemHandler(int iClientH, char * pItemName, int iNum);
	void RequestPurchaseItemHandler2(int iClientH, char * pItemName, int iNum); // MORLA 2.4 - Para el trade items
	void ResponseDisbandGuildHandler(char * pData, DWORD dwMsgSize);
	void RequestDisbandGuildHandler(int iClientH, char * pData, DWORD dwMsgSize);
	void RequestCreateNewGuildHandler(int iClientH, char * pData, DWORD dwMsgSize);
	void ResponseCreateNewGuildHandler(char * pData, DWORD dwMsgSize);
	int  iClientMotion_Stop_Handler(int iClientH, short sX, short sY, char cDir);
	
	BOOL bEquipItemHandler(int iClientH, short sItemIndex, BOOL bNotify = TRUE);
	BOOL _bAddClientItemList(int iClientH, class CItem * pItem, int * pDelReq);
	int  iClientMotion_GetItem_Handler(int iClientH, short sX, short sY, char cDir);
	void DropItemHandler(int iClientH, short sItemIndex, int iAmount, char * pItemName, BOOL bByPlayer = TRUE);
	void ClientCommonHandler(int iClientH, char * pData);
	BOOL __fastcall bGetMsgQuene(char * pFrom, char * pData, DWORD * pMsgSize, int * pIndex, char * pKey);
	void MsgProcess();
	BOOL __fastcall bPutMsgQuene(char cFrom, char * pData, DWORD dwMsgSize, int iIndex, char cKey);
	void NpcBehavior_Flee(int iNpcH);
	int iGetDangerValue(int iNpcH, short dX, short dY);
	void NpcBehavior_Dead(int iNpcH);
	void NpcKilledHandler(short sAttackerH, char cAttackerType, int iNpcH, short sDamage);
	//int  iCalculateAttackEffect(short sTargetH, char cTargetType, short sAttackerH, char cAttackerType, int tdX, int tdY, int iAttackMode, BOOL bNearAttack = FALSE);
	int iCalculateAttackEffect(short sTargetH, char cTargetType, short sAttackerH, char cAttackerType, int tdX, int tdY, int iAttackMode, BOOL bNearAttack = FALSE, BOOL bIsDash = FALSE, BOOL bArrowUse = FALSE);
	void RemoveFromTarget(short sTargetH, char cTargetType, int iCode = NULL);
	void NpcBehavior_Attack(int iNpcH);
	void TargetSearch(int iNpcH, short * pTarget, char * pTargetType);
	void NpcBehavior_Move(int iNpcH);
	BOOL bGetEmptyPosition(short * pX, short * pY, char cMapIndex);
	char cGetNextMoveDir(short sX, short sY, short dstX, short dstY, char cMapIndex, char cTurn, int * pError);
	int  iClientMotion_Attack_Handler(int iClientH, short sX, short sY, short dX, short dY, short wType, char cDir, WORD wTargetObjectID, BOOL bResponse = TRUE, BOOL bIsDash = FALSE);
	void ChatMsgHandler(int iClientH, char * pData, DWORD dwMsgSize);
	void NpcProcess();
	int bCreateNewNpc(char * pNpcName, char * pName, char * pMapName, short sClass, char cSA, char cMoveType, int * poX, int * poY, char * pWaypointList, RECT * pArea, int iSpotMobIndex, char cChangeSide, BOOL bHideGenMode, BOOL bIsSummoned = FALSE, BOOL bFirmBerserk = FALSE, BOOL bIsMaster = FALSE, int iGuildGUID = NULL);
	//BOOL bCreateNewNpc(char * pNpcName, char * pName, char * pMapName, short sX, short sY);
	BOOL _bReadMapInfoFiles(int iMapIndex);
	
	BOOL _bGetIsStringIsNumber(char * pStr);
	BOOL _bInitItemAttr(class CItem * pItem, char * pItemName);
	BOOL bReadProgramConfigFile(char * cFn);
	void GameProcess();
	void InitPlayerData(int iClientH, char * pData, DWORD dwSize);
	void ResponsePlayerDataHandler(char * pData, DWORD dwSize);
	BOOL bSendMsgToLS(DWORD dwMsg, int iClientH, BOOL bFlag = TRUE, char *pData = NULL);
	void OnMainLogRead();
	void OnMainLogSocketEvent(UINT message, WPARAM wParam, LPARAM lParam);
	void CheckClientResponseTime();
	void OnTimer(char cType);
	int iComposeMoveMapData(short sX, short sY, int iClientH, char cDir, char * pData);
	void SendEventToNearClient_TypeB(DWORD dwMsgID, WORD wMsgType, char cMapIndex, short sX, short sY, short sV1, short sV2, short sV3, short sV4 = NULL);
	void SendEventToNearClient_TypeA(short sOwnerH, char cOwnerType, DWORD dwMsgID, WORD wMsgType, short sV1, short sV2, short sV3);
	void DeleteClient(int iClientH, BOOL bSave, BOOL bNotify, BOOL bCountLogout = TRUE, BOOL bForceCloseConn = FALSE);
	int  iComposeInitMapData(short sX, short sY, int iClientH, char * pData);
	void RequestInitDataHandler(int iClientH, char * pData, char cKey);
	void RequestInitPlayerHandler(int iClientH, char * pData, char cKey);
	int iClientMotion_Move_Handler(int iClientH, short sX, short sY, char cDir, char cMoveType);
	void ClientMotionHandler(int iClientH, char * pData);
	void DisplayInfo(HDC hdc);
	void OnClientRead(int iClientH);
	BOOL bInit();
	void OnClientSocketEvent(UINT message, WPARAM wParam, LPARAM lParam);
	BOOL bAccept(class XSocket * pXSock);
	// v1.4311-3 함수 선언 입장권 받는 함수 .. void GetFightzoneTicketHandler(int iClientH);
	void GetFightzoneTicketHandler(int iClientH);
	// v1.4311-3 2 시간마다 사투장 예약을 초기화 시킨다.
	void FightzoneReserveProcessor() ;

	// New 06/05/2004
	// Upgrades
	BOOL bCheckIsItemUpgradeSuccess(int iClientH, int iItemIndex, int iSomH, BOOL bBonus = FALSE);
	void RequestItemUpgradeHandler(int iClientH, int iItemIndex);

	// ArchAngle's Codes
	void StormBringer(int iClientH, short dX, short dY);
	void FireBow(short iClientH, short dX, short dY);
	
	//Party Codes
	void CreateNewPartyHandler(int iClientH);
        void GetExp(int iClientH, int iExp, BOOL bIsAttackerOwn = FALSE);
	void JoinPartyHandler(int iClientH, int iV1, char *pMemberName);
	void PartyOperationResultHandler(char *pData);
	void PartyOperationResult_Create(int iClientH, char *pName, int iResult, int iPartyID);
	void PartyOperationResult_Join(int iClientH, char *pName, int iResult, int iPartyID);
	void PartyOperationResult_Dismiss(int iClientH, char *pName, int iResult, int iPartyID);
	void PartyOperationResult_Delete(int iPartyID);
	void PartyOperationResult_Info(int iClientH, char * pName, int iTotal, char *pNameList);
	void RequestAcceptJoinPartyHandler(int iClientH, int iResult);
        void RequestCreatePartyHandler(int iClientH);
        void RequestJoinPartyHandler(int iClientH, char *pData, DWORD dwMsgSize);
        void RequestDismissPartyHandler(int iClientH);
        void GetPartyInfoHandler(int iClientH);
        void RequestDeletePartyHandler(int iClientH);

	// New 07/05/2004
	// Guild Codes
	void RequestGuildNameHandler(int iClientH, int iObjectID, int iIndex);
	void RequestRango(int iClientH, int iObjectID); // Morla2.2 - Pide EK y PK
	void RequestWho(int iClientH); // Morla2.2 - Pide Players On 
	void SetSkillAll(int iClientH);
	void RefreshDeathmach(int iClientH);	
	BOOL bReadTopPlayersFile(char * cFn);
	void calcularTopEkPlayer(int iClientH); // MORLA 2.4 - Calcular top players de Enemy Kill
	void calcularTopPkPlayer(int iClientH); // MORLA 2.4 - Calcular top players de Player Kill (jiji osea deaths, no tenia ganas de cambiarlo)
	void _CreateTopPlayers(); // MORLA 2.4 - Guardar Datos
	//void PlayerOrder_ShowDefense(int iClientH);
	void CalcularRaidTime(int _dia, int _tiempo);
	void SetPlayerDGPoint(int iClientH, char * pMsg, char cValue, DWORD dwMsgSize);
	void calcularTop15Deathmach(int iClientH);
	void ordenarTop15Deathmach();
	void calcularTop15HB(int iClientH);
	void ordenarTop15HB(int iClientH);
	void closeDeathmach();
	void openDeathmach();
	void closeHappyHour();
	void openHappyHour();
	void AdminOrder_GetRepxMJ(int iClientH);
	void AdminOrder_speed(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_ChangeCity(int iClientH);
	void AdminOrder_MorlearPj(int iClientH, char* pData, DWORD dwMsgSize); // MORLA 2.12 - Morlear PJ
	void PlayerOrder_UseHack(int iClientH, int iHack); // MORLA 2.14 - Anti Hack

	// Item Logs
	BOOL _bItemLog(int iAction,int iClientH , char * cName, class CItem * pItem);
	BOOL _bItemLog(int iAction,int iGiveH, int iRecvH, class CItem * pItem,BOOL bForceItemLog = FALSE);
	BOOL _bCheckGoodItem( class CItem * pItem );

	BOOL bCheckAndConvertPlusWeaponItem(int iClientH, int iItemIndex);
	void ArmorLifeDecrement(int iAttackerH, int iTargetH, char cOwnerType, int iValue);

	// MultiDrops
	BOOL bGetMultipleItemNamesWhenDeleteNpc(short sNpcType, int iProbability, int iMin, int iMax, short sBaseX, short sBaseY,
											   int iItemSpreadType, int iSpreadRange,
											   int *iItemIDs, POINT *BasePos, int *iNumItem);

	// Player shutup
	void GSM_RequestShutupPlayer(char * pGMName,WORD wReqServerID, WORD wReqClientH, WORD wTime,char * pPlayer );

	// PK Logs
	BOOL _bPKLog(int iAction,int iAttackerH , int iVictumH, char * pNPC);

	CGame(HWND hWnd);
	virtual ~CGame();

	char m_cServerName[11];
	char m_cGameServerAddr[16];
	char m_cGameServerAddrInternal[16];
	char m_cGameServerAddrExternal[16];
	int  m_iGameServerMode;
	char m_cLogServerAddr[16];
	char m_cGateServerAddr[16];
	int  m_iGameServerPort;
	int  m_iLogServerPort;
	int  m_iGateServerPort;

	int  m_iLimitedUserExp, m_iLevelExp20;

//private:
	BOOL _bDecodeItemConfigFileContents(char * pData, DWORD dwMsgSize);
	int _iComposePlayerDataFileContents(int iClientH, char * pData);
	BOOL _bDecodePlayerDatafileContents(int iClientH, char * pData, DWORD dwSize);
	BOOL _bRegisterMap(char * pName);

	class CClient * m_pClientList[DEF_MAXCLIENTS];
	class CNpc    * m_pNpcList[DEF_MAXNPCS];
	class CMap    * m_pMapList[DEF_MAXMAPS];
	class CDynamicObject * m_pDynamicObjectList[DEF_MAXDYNAMICOBJECTS];
	class CDelayEvent    * m_pDelayEventList[DEF_MAXDELAYEVENTS];

	class CMsg    * m_pMsgQuene[DEF_MSGQUENESIZE];
	int             m_iQueneHead, m_iQueneTail;
	int             m_iTotalMaps;
	class XSocket * m_pMainLogSock, * m_pGateSock;
	int				m_iGateSockConnRetryTimes;
	class CMisc     m_Misc;
	BOOL			m_bIsGameStarted;
	BOOL            m_bIsLogSockAvailable, m_bIsGateSockAvailable;
	BOOL			m_bIsItemAvailable, m_bIsBuildItemAvailable, m_bIsNpcAvailable, m_bIsMagicAvailable;
	BOOL			m_bIsSkillAvailable, m_bIsPortionAvailable, m_bIsQuestAvailable, m_bIsTeleportAvailable;

	class CItem   * m_pItemConfigList[DEF_MAXITEMTYPES];
	class CNpc    * m_pNpcConfigList[DEF_MAXNPCTYPES];
	class CMagic  * m_pMagicConfigList[DEF_MAXMAGICTYPE];
	class CSkill  * m_pSkillConfigList[DEF_MAXSKILLTYPE];
	class CQuest  * m_pQuestConfigList[DEF_MAXQUESTTYPE];
	char            m_pMsgBuffer[DEF_MSGBUFFERSIZE+1];

	// D2 Teleport Handler
	class CTeleport * m_pTeleportConfigList[DEF_MAXTELEPORTLIST];

	HWND  m_hWnd;
	int   m_iTotalClients, m_iMaxClients, m_iTotalGameServerClients, m_iTotalGameServerMaxClients;
	int   m_iTotalBots, m_iMaxBots, m_iTotalGameServerBots, m_iTotalGameServerMaxBots;
	SYSTEMTIME m_MaxUserSysTime;

	BOOL  m_bF1pressed, m_bF4pressed, m_bF12pressed, m_bF5pressed;
	BOOL  m_bOnExitProcess;
	DWORD m_dwExitProcessTime;

	DWORD m_dwWhetherTime, m_dwGameTime1, m_dwGameTime2, m_dwGameTime3, m_dwGameTime4, m_dwGameTime5, m_dwGameTime6, m_dwFishTime;
	
	// Crusade Schedule
	BOOL m_bIsCrusadeWarStarter;
	int m_iLatestCrusadeDayOfWeek;

	char  m_cDayOrNight;		// 1이면 주간, 2면 야간 
 	int   m_iSkillSSNpoint[102];

	class CMsg * m_pNoticeMsgList[DEF_MAXNOTIFYMSGS];
	int   m_iTotalNoticeMsg, m_iPrevSendNoticeMsg;
	DWORD m_dwNoticeTime, m_dwSpecialEventTime;
	BOOL  m_bIsSpecialEventTime;
	char  m_cSpecialEventType;

	int m_iLevelExpTable[3500];	//New 22/10/04

 	class CFish * m_pFish[DEF_MAXFISHS];
	class CPortion * m_pPortionConfigList[DEF_MAXPORTIONTYPES];
        class CCrafting * m_pCraftingConfigList[DEF_MAXCRAFTINGTYPES];

	BOOL  m_bIsServerShutdowned;
	char  m_cShutDownCode;
	class CMineral * m_pMineral[DEF_MAXMINERALS];

	int   m_iMiddlelandMapIndex;	// 전쟁터인 미들랜드 맵 인덱스: 이 값이 -1이면 미들랜드 맵이 없음을 의미 
	int   m_iAresdenMapIndex;		// 아레스덴 맵 인덱스 
	int	  m_iElvineMapIndex;		
	int   m_iAresdenOccupyTiles;
	int   m_iElvineOccupyTiles;
	int   m_iCurMsgs, m_iMaxMsgs;

	// v1.4311-3 변수 선언  예약된 시간을 가지는 변수 DWORD m_dwCanFightzoneReserveTime 
	DWORD m_dwCanFightzoneReserveTime ;

	// v1.4311-3 변수 선언 각 사투장의 예약 여부를 저장 int  m_iFightZoneReserve[DEF_MAXFIGHTZONE];
	int  m_iFightZoneReserve[DEF_MAXFIGHTZONE] ;
	// v1.4311-3 변수 선언 사투장에 들어갔을때 운영자 명령어로 강콜 않되게 함.
	int  m_iFightzoneNoForceRecall  ;
	char cPoints;
	struct {
		__int64 iFunds;
		__int64 iCrimes;
		__int64 iWins;

	} m_stCityStatus[3];
	
	int	  m_iStrategicStatus;
	
	class XSocket * m_pSubLogSock[DEF_MAXSUBLOGSOCK];
	int   m_iSubLogSockInitIndex;
	BOOL  m_bIsSubLogSockAvailable[DEF_MAXSUBLOGSOCK];
	int	  m_iCurSubLogSockIndex;
	int   m_iSubLogSockFailCount;
	int   m_iSubLogSockActiveCount;	// v1.5 현재 연결 상태가 유지되고 있는 sub-log-socket 갯수
	int   m_iAutoRebootingCount;	// v1.5 자동 재부팅 된 횟수 

	class CBuildItem * m_pBuildItemList[DEF_MAXBUILDITEMS];
	class CItem * m_pDupItemIDList[DEF_MAXDUPITEMID];

	char * m_pNoticementData;
	DWORD  m_dwNoticementDataSize;

	DWORD  m_dwMapSectorInfoTime;
	int    m_iMapSectorInfoUpdateCount;

	// Crusade 처리용
	int	   m_iCrusadeCount;			// 0이면 전면전 대기상태. 1이면 카운트 다운 시작. 
	BOOL   m_bIsCrusadeMode;		// 크루세이드 모드
	// Daryl - Chat logging option
	BOOL m_bLogChatOption;

	// Apocalypse
	BOOL	 m_bIsApocalypseMode;
	DWORD  m_dwApocalypseGUID;

	struct {
		char cMapName[11];			// 설치되는 맵 위치
		char cType;					// 건축물 종류. 사실 NPC 종류임.
		int  dX, dY;				// 설치되는 맵상의 위치

	} m_stCrusadeStructures[DEF_MAXCRUSADESTRUCTURES];

	
	int m_iCollectedMana[3];
	int m_iAresdenMana, m_iElvineMana;

	class CTeleportLoc m_pGuildTeleportLoc[DEF_MAXGUILDS];
	//

	WORD  m_wServerID_GSS;
	char  m_cGateServerStockMsg[DEF_MAXGATESERVERSTOCKMSGSIZE];
	int   m_iIndexGSS;

	int m_iLastCrusadeWinner; 	// New 13/05/2004
	struct {
		int iCrashedStructureNum;
		int iStructureDamageAmount;
		int iCasualties;
	} m_stMeteorStrikeResult;

	// 미들랜드의 정보를 저장하는 구조체. 미들랜드를 운용하지 않는 서버에서는 이 정보를 받아 갱신한다.
	struct {
		char cType;			// 이게 NULL이면 정의되지 않은것을 의미.
		char cSide;			// 사이드
		short sX, sY;		// 설치된 위치 
	} m_stMiddleCrusadeStructureInfo[DEF_MAXCRUSADESTRUCTURES];

	struct {
		char m_cBannedIPaddress[21];		 // 클라이언트의 IP address
	} m_stBannedList[DEF_MAXBANNED];

	struct {
		char m_cGMName[11];
	} m_stAdminList[DEF_MAXADMINS];

	// Crusade Scheduler
	struct {
		int iDay;
		int iHour;
		int iMinute;
	} m_stCrusadeWarSchedule[DEF_MAXSCHEDULE];

	struct {
		int iDay;
		int StartiHour;
		int StartiMinute;
		int EndiHour;
		int EndiMinute;
	} m_stHeldenianSchedule[DEF_MAXHELDENIAN];

	int m_iTotalMiddleCrusadeStructures;
 
	// 이 변수 안에는 현재 접속한 클라이언트의 인덱스가 공백없이 저장되어 있다. 0이 나오면 리스트의 끝이라는 의미
	int m_iClientShortCut[DEF_MAXCLIENTS+1];

	int m_iNpcConstructionPoint[DEF_MAXNPCTYPES];
	DWORD m_dwCrusadeGUID;
	short m_sLastCrusadeDate;
	int   m_iCrusadeWinnerSide;
	int   m_iPlayerMaxLevel;
        int   m_iWorldMaxUser;

	struct {
		int iTotalMembers;
		int iIndex[DEF_MAXPARTYMEMBERS];
	} m_stPartyInfo[DEF_MAXPARTYNUM];

	// Daryl - Admin level adjustments
	int m_iAdminLevelGMKill;
	int m_iAdminLevelGMRevive;
	int m_iAdminLevelGMCloseconn;
	int m_iAdminLevelGMCheckRep;
	int m_iAdminLevelEnergySphere;
	int m_iAdminLevelShutdown;
	int m_iAdminLevelObserver;
	int m_iAdminLevelShutup;
	int m_iAdminLevelCallGaurd;
	int m_iAdminLevelSummonDemon;
	int m_iAdminLevelSummonDeath;
	int m_iAdminLevelReserveFightzone;
	int m_iAdminLevelCreateFish;
	int m_iAdminLevelTeleport;
	int m_iAdminLevelCheckIP;
	int m_iAdminLevelPolymorph;
	int m_iAdminLevelSetInvis;
	int m_iAdminLevelSetZerk;
	int m_iAdminLevelSetIce;
	int m_iAdminLevelGetNpcStatus;
	int m_iAdminLevelSetAttackMode;
	int m_iAdminLevelUnsummonAll;
	int m_iAdminLevelUnsummonDemon;
	int m_iAdminLevelSummon;
	int m_iAdminLevelSummonAll;
	int m_iAdminLevelSummonPlayer;
	int m_iAdminLevelDisconnectAll;
	int m_iAdminLevelEnableCreateItem;
	int m_iAdminLevelCreateItem;
	int m_iAdminLevelStorm;
	int m_iAdminLevelWeather;
	int m_iAdminLevelSetStatus;
	int m_iAdminLevelGoto;
	int m_iAdminLevelMonsterCount;
	int m_iAdminLevelSetRecallTime;
	int m_iAdminLevelUnsummonBoss;
	int m_iAdminLevelClearNpc;
	int m_iAdminLevelTime;
	int m_iAdminLevelPushPlayer;
	int m_iAdminLevelSummonGuild;
	int m_iAdminLevelCheckStatus;
	int m_iAdminLevelCleanMap;
        int m_iAdminLevelEnableAdminAttack;
        int m_iAdminLevelBanIp;
        int m_iAdminLevelCheckPlayer;

	// 09/26/2004
	short m_sSlateSuccessRate;

	// 17/05/2004
	short m_sForceRecallTime;

	// 25/05/2004
	int m_iFinalShutdownCount;

	// New 06/07/2004
	BOOL m_bEnemyKillMode;
	int m_iEnemyKillAdjust;
	BOOL m_bAdminSecurity;
	
	// Configurable Raid Time 
	short m_sRaidTimeMonday; 
	short m_sRaidTimeTuesday; 
	short m_sRaidTimeWednesday; 
	short m_sRaidTimeThursday; 
	short m_sRaidTimeFriday; 
	short m_sRaidTimeSaturday; 
	short m_sRaidTimeSunday; 

	BOOL m_bManualTime;
	int m_iSummonGuildCost;


	// Slate exploit
	int m_sCharPointLimit;

	// Limit Checks
	short m_sCharStatLimit;
	BOOL m_bAllow100AllSkill;
	short m_sCharSkillLimit;
	char  m_cSecurityNumber[11];
	short m_sMaxPlayerLevel;
	
//BOOL var_89C, var_8A0;
			BOOL	var_89C, var_8A0, var_A38, var_88C, m_bIsHeldenianScheduleLoaded, m_bIsHeldenianSchedule, 
			m_bHeldenianInitiated, m_bHeldenianRunning, m_bIsHeldenianMode, m_bIsHeldenianTeleport;
	char	m_cHeldenianVictoryType, m_sLastHeldenianWinner, m_cHeldenianModeType, m_cHeldenianWinner, 
			m_cHeldenianFirstDestroyedTowerWinner;
	int		m_iHeldenianAresdenDead, m_iHeldenianElvineDead, m_iHeldenianAresdenLeftTower, 
			m_iHeldenianElvineLeftTower, m_iHeldenianAresdenFlags, 
			m_iHeldenianElvineFlags, m_iBTFieldMapIndex, m_iRampartMapIndex, m_iGodHMapIndex;
	DWORD	m_dwHeldenianGUID, m_dwHeldenianStartHour, m_dwHeldenianStartMinute, m_dwHeldenianFinishTime, 
			m_dwHeldenianWarTime, m_dwHeldenianEndTime, m_dwHeldenianWarStartTime;

	char  m_cHeldenianSummonMode;
	BOOL	m_bHeldenianWarInitiated;	// War has begun		-> can Fight 
	char	m_cHeldenianType;			// Type 1: (BtField) 
										// Type 2: (Casttle siege) Previous winner will defend.

private:
	int __iSearchForQuest(int iClientH, int iWho, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	int _iTalkToNpcResult_Cityhall(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	void _ClearExchangeStatus(int iToH);
	int _iGetItemSpaceLeft(int iClientH);

public:
	void AdminOrder_GoTo(int iClientH, char* pData, DWORD dwMsgSize);
	void AdminOrder_MonsterCount(int iClientH, char* pData, DWORD dwMsgSize);
	void AdminOrder_SetForceRecallTime(int iClientH, char* pData, DWORD dwMsgSize);
	void AdminOrder_UnsummonBoss(int iClientH);
	void RemoveCrusadeNpcs(void);
	void RemoveCrusadeRecallTime(void);
	BOOL _bCrusadeLog(int iAction,int iClientH,int iData, char * cName);
	int iGetPlayerABSStatus(int iClientH);
	BOOL _bInitItemAttr(class CItem * pItem, int iItemID);
	void ReqCreateSlateHandler(int iClientH, char* pData);
	void SetSlateFlag(int iClientH, short sType, bool bFlag);
	void CheckForceRecallTime(int iClientH);
	void SetPlayingStatus(int iClientH);
	void ForceChangePlayMode(int iClientH, bool bNotify);
	void ShowClientMsg(int iClientH, char* pMsg, int iChatType);
	void RequestResurrectPlayer(int iClientH, bool bResurrect);
};

#endif // !defined(AFX_GAME_H__C3D29FC5_755B_11D2_A8E6_00001C7030A6__INCLUDED_)
