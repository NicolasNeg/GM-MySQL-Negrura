
#if defined _profile_included
	#endinput
#endif

#define _profile_included

#include <a_samp>

stock Profile_SetTrusted(playerid, bool:set)
return CallRemoteFunction("Profile_SetTrusted", "ii", playerid, (set?1:0));

stock Profile_SetFeatured(playerid, bool:set)
return CallRemoteFunction("Profile_SetFeatured", "ii", playerid, (set?1:0));

stock Profile_SetPro(playerid, bool:set)
return CallRemoteFunction("Profile_SetPro", "ii", playerid, (set?1:0));

stock Profile_GiveRep(playerid, value)
return CallRemoteFunction("Profile_GiveRep", "ii", playerid, value);

stock Profile_GetRep(playerid)
return CallRemoteFunction("Profile_GetRep", "i", playerid);

stock Profile_SetVip(playerid, bars, status[])
return CallRemoteFunction("Profile_SetVip", "iis", playerid, bars, status);

stock Profile_SetAdminLevel(playerid, bars, status[])
return CallRemoteFunction("Profile_SetAdminLevel", "iis", playerid, bars, status);

stock Profile_SetRegisterDate(playerid, date[])
return CallRemoteFunction("Profile_SetRegisterDate", "is", playerid, date);

stock Profile_SetInfo(playerid, text[])
return CallRemoteFunction("Profile_SetRegisterDate", "is", playerid, text);
