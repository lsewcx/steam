#include "steam_api.h"
#include<iostream>
#include"isteamuserstats.h"
using namespace std;


bool achievementStatus;
//const char* name="ACH_WIN_ONE_GAME";//�ɾ͵�api
const char* name="01";//�ɾ͵�api
uint32 unlockTime;//����ʱ��

bool InitSteamAPI()
{
    if (!SteamAPI_Init())
    {
        // �����ʼ��ʧ�ܵ��߼�
        return false;
    }
    return true;
}

uint64_t GetCurrentPlayerSteamID()//��ȡ��ǰsteam�û���ID
{
    CSteamID steamID = SteamUser()->GetSteamID();
    return steamID.ConvertToUint64();
}


int main()
{
    if (SteamAPI_RestartAppIfNecessary(480))
    {
        return 1;
    }
    if (!SteamAPI_Init())
    {
        printf("Fatal Error - Steam must be running to play this game (SteamAPI_Init() failed).\n");
        return 1;
    }
    if (InitSteamAPI() == true) {
        ISteamUserStats* steamUserStats = SteamUserStats();//�½�
        bool success = steamUserStats->RequestCurrentStats();// ��ȡ��ǰ�û�״̬
        if (success)
        {
            bool achieved = false;
            steamUserStats->ClearAchievement(name);
            //steamUserStats->SetAchievement(name);//�����ɾ�
            //steamUserStats->GetUserAchievementAndUnlockTime(GetCurrentPlayerSteamID(),name, &achieved, &unlockTime);//��ȡ�ɾͽ���ʱ����Ƿ����
            //cout << achieved << " " << unlockTime;
        }
    }


    return 0;
}