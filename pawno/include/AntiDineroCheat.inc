/*======================Anti Money Cheat================================|
||                     Anti Cheat de Dinero                             |
||                            BY                                        |
||                       Tribisk_Transk                                 |
||=====================================================================*/

stock ObtenerDineroJugador(playerid) return GetPlayerMoney(playerid);

stock DarDineroJugador(playerid,CantidadM)
{
	SetPVarInt(playerid,"DineroS",GetPVarInt(playerid,"DineroS") + CantidadM);
	return GivePlayerMoney(playerid,CantidadM);
}

stock QuitarDineroJugador(playerid)
{
	SetPVarInt(playerid,"DineroS",0);
	return ResetPlayerMoney(playerid);
}
public OnPlayerUpdate(playerid)
{
    if( GetPlayerMoney(playerid) != GetPVarInt(playerid,"DineroS"))
	{
		ResetPlayerMoney(playerid);
		GivePlayerMoney(playerid,GetPVarInt(playerid,"DineroS"));
	}
    return CallLocalFunction( "AntiCheat_OnPlayerUpdate", "i", playerid );
}
#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate AntiCheat_OnPlayerUpdate
forward AntiCheat_OnPlayerUpdate( playerid );

#define GetPlayerMoney ObtenerDineroJugador
#define GivePlayerMoney DarDineroJugador
#define ResetPlayerMoney QuitarDineroJugador
