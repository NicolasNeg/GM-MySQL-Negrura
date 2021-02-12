/*----------------------------------------------------------------------------*-
					===========================
					         ZCRP BD
					===========================
Descripción:
	Sin este include el gamemode no compilará
Add:
     OnPlayerOfflineLogin and  OnPlayerOfflineSave.
Fix:
     pCrack and pPot.

------------------------------------------------------------------------------*/
/*DEFINES*/
#define \
			function%0(%1) \
							forward %0(%1); public %0(%1)
/*NATIVES*/
native OnPlayerUpdateTime(playerid);
native OnPlayerRegister(playerid, password[]);
native OnPlayerLogin(playerid);
native OnPlayerOfflineLogin(playername[]);
native OnPlayerOfflineSave(playername[]);

/*START*/
function OnPlayerUpdateTime(playerid)
{
    if(GetPVarInt(playerid, "TempName") == 1) return 1;
	if(IsPlayerConnected(playerid))
	{
		if(gPlayerLogged[playerid])
		{
			new string3[64];
			new playername3[MAX_PLAYER_NAME];
			GetPlayerName(playerid, playername3, sizeof(playername3));
			format(string3, sizeof(string3), "users/%s.ini", playername3);
			new File: hFile = fopen(string3, io_write);
			if (hFile)
			{
				new var[64];
				format(var, 32, "Key=%s\n", Info[playerid][pKey]);fwrite(hFile, var);
				format(var, 32, "Level=%d\n",Info[playerid][pLevel]);fwrite(hFile, var);
				format(var, 32, "AdminNivel=%d\n",Info[playerid][pAdminNivel]);fwrite(hFile, var);
				format(var, 32, "BanAppealer=%d\n",Info[playerid][pBanAppealer]);fwrite(hFile, var);
				format(var, 32, "FactionModerator=%d\n",Info[playerid][pFactionModerator]);fwrite(hFile, var);
				format(var, 32, "GangModerator=%d\n",Info[playerid][pGangModerator]);fwrite(hFile, var);
				format(var, 32, "Helper=%d\n",Info[playerid][pHelper]);fwrite(hFile, var);
				format(var, 32, "ConnectedTime=%d\n",Info[playerid][pConnectTime]);fwrite(hFile, var);
				format(var, 32, "Registered=%d\n",Info[playerid][pReg]);fwrite(hFile, var);
				format(var, 32, "Sex=%d\n",Info[playerid][pSex]);fwrite(hFile, var);
				format(var, 32, "Age=%d\n",Info[playerid][pAge]);fwrite(hFile, var);
				format(var, 32, "Origin=%d\n",Info[playerid][pOrigin]);fwrite(hFile, var);
                format(var, 32, "Walk=%d\n",Info[playerid][pWalk]);fwrite(hFile, var);
				format(var, 32, "Respect=%d\n",Info[playerid][pExp]);fwrite(hFile, var);
				format(var, 32, "Money=%d\n",GetPVarInt(playerid, "Cash"));fwrite(hFile, var);
				format(var, 32, "Bank=%d\n",Info[playerid][pAccount]);fwrite(hFile, var);
				format(var, 32, "IP=%s\n",Info[playerid][pIP]);fwrite(hFile, var);
				format(var, 32, "Kills=%d\n",Info[playerid][pKills]);fwrite(hFile, var);
				format(var, 32, "Deaths=%d\n",Info[playerid][pDeaths]);fwrite(hFile, var);
				format(var, 32, "Arrested=%d\n",Info[playerid][pArrested]);fwrite(hFile, var);
				format(var, 32, "JailAdmin=%d\n",Info[playerid][pJailAdmin]);fwrite(hFile, var);
				format(var, 32, "LottoNr=%d\n",Info[playerid][pLottoNr]);fwrite(hFile, var);
				format(var, 32, "Job=%d\n",Info[playerid][pJob]);fwrite(hFile, var);
				format(var, 32, "NewMuted=%d\n",Info[playerid][pNMute]);fwrite(hFile, var);
				format(var, 32, "NewMutedTotal=%d\n",Info[playerid][pNMuteTotal]);fwrite(hFile, var);
				format(var, 32, "Warns=%d\n",Info[playerid][pWarn]);fwrite(hFile, var);
				format(var, 32, "WRestricted=%d\n",Info[playerid][pWRestricted]);fwrite(hFile, var);
				format(var, 32, "Jailed=%d\n",Info[playerid][pJailed]);fwrite(hFile, var);
				format(var, 32, "JailTime=%d\n",Info[playerid][pJailTime]);fwrite(hFile, var);
				format(var, 32, "Materials=%d\n",Info[playerid][pMats]);fwrite(hFile, var);
				format(var, 32, "Packages=%d\n",GetPVarInt(playerid, "Packages"));fwrite(hFile, var);
				format(var, 32, "Drugs=%d\n",Info[playerid][pDrugs]);fwrite(hFile, var);
				format(var, 32, "Cosecha=%d\n",Info[playerid][pCosecha]);fwrite(hFile, var);
				format(var, 32, "Crack=%d\n",Info[playerid][pCrack]);fwrite(hFile, var);
				format(var, 32, "Pot=%d\n",Info[playerid][pPot]);fwrite(hFile, var);
				format(var, 32, "Crates=%d\n",Info[playerid][pCrates]);fwrite(hFile, var);
				format(var, 32, "Adic=%d\n",Info[playerid][pAdiccion]);fwrite(hFile, var);
				format(var, 32, "Leader=%d\n",Info[playerid][pLeader]);fwrite(hFile, var);
				format(var, 32, "Member=%d\n",Info[playerid][pMember]);fwrite(hFile, var);
				format(var, 32, "FMember=%d\n",Info[playerid][pFMember]);fwrite(hFile, var);
				format(var, 32, "Division=%d\n",Info[playerid][pDivision]);fwrite(hFile, var);
				format(var, 32, "Rank=%d\n",Info[playerid][pRank]);fwrite(hFile, var);
				format(var, 32, "Char=%d\n",Info[playerid][pChar]);fwrite(hFile, var);
				if(GetPVarInt(playerid, "EventToken") != 2 && GetPVarInt(playerid, "IsInArena") == 0)
				{
				    GetPlayerHealth(playerid,Info[playerid][pHealth]);
				}
	            format(var, 32, "pHealth=%.1f\n",Info[playerid][pHealth]);fwrite(hFile, var);
				if(GetPVarInt(playerid, "EventToken") != 2 && GetPVarInt(playerid, "IsInArena") == 0)
				{
					GetPlayerArmour(playerid,Info[playerid][pArmour]);
				}
				format(var, 32, "pArmour=%.1f\n",Info[playerid][pArmour]);fwrite(hFile, var);
				format(var, 32, "Team=%d\n",Info[playerid][pTeam]);fwrite(hFile, var);
				format(var, 32, "Model=%d\n",Info[playerid][pModel]);fwrite(hFile, var);
				format(var, 32, "PhoneNr=%d\n",Info[playerid][pPnumber]);fwrite(hFile, var);
				format(var, 32, "Sprunk=%d\n",Info[playerid][pSprunk]);fwrite(hFile, var);
				format(var, 32, "Phonebook=%d\n",Info[playerid][pPhoneBook]);fwrite(hFile, var);
				format(var, 32, "House=%d\n",Info[playerid][pPhousekey]);fwrite(hFile, var);
				format(var, 32, "House2=%d\n",Info[playerid][pPhousekey2]);fwrite(hFile, var);
				format(var, 32, "Int=%d\n",Info[playerid][pInt]);fwrite(hFile, var);
				format(var, 32, "Pos_x=%.1f\n",Info[playerid][pPos_x]);fwrite(hFile, var);
				format(var, 32, "Pos_y=%.1f\n",Info[playerid][pPos_y]);fwrite(hFile, var);
				format(var, 32, "Pos_z=%.1f\n",Info[playerid][pPos_z]);fwrite(hFile, var);
				format(var, 32, "SPos_r=%.1f\n",Info[playerid][pPos_r]);fwrite(hFile, var);
				format(var, 32, "CarLic=%d\n",Info[playerid][pCarLic]);fwrite(hFile, var);
                format(var, 32, "FlyLic=%d\n",Info[playerid][pFlyLic]);fwrite(hFile, var);
				format(var, 32, "BoatLic=%d\n",Info[playerid][pBoatLic]);fwrite(hFile, var);
				format(var, 32, "GunLic=%d\n",Info[playerid][pGunLic]);fwrite(hFile, var);
				format(var, 32, "Gafas=%d\n",Info[playerid][pGafas]);fwrite(hFile, var);
				format(var, 32, "Tutorial=%d\n",Info[playerid][pTut]);fwrite(hFile, var);
				format(var, 32, "Test=%d\n",Info[playerid][pTestTut]);fwrite(hFile, var);
				format(var, 32, "VWorld=%d\n",Info[playerid][pVW]);fwrite(hFile, var);
				format(var, 32, "Lighter=%d\n",Info[playerid][pLighter]);fwrite(hFile, var);
				format(var, 32, "Cigarettes=%d\n",Info[playerid][pCigarettes]);fwrite(hFile, var);
				format(var, 32, "Hachis=%d\n",Info[playerid][pHachis]);fwrite(hFile, var);
				format(var, 32, "Papel=%d\n",Info[playerid][pPapel]);fwrite(hFile, var);
				format(var, 32, "Ban=%d\n",Info[playerid][pBanned]);fwrite(hFile, var);
				format(var, 32, "Disabled=%d\n",Info[playerid][pDisabled]);fwrite(hFile, var);
				format(var, 32, "BlockBug=%d\n",Info[playerid][pBlockBug]);fwrite(hFile, var);
				format(var, 32, "DNI=%d\n",Info[playerid][pDNI]);fwrite(hFile, var);
				format(var, 32, "VSkill=%d\n",Info[playerid][pArmsSkill]);fwrite(hFile, var);
				format(var, 32, "TSkill=%d\n",Info[playerid][pTruckSkill]);fwrite(hFile, var);
				format(var, 32, "SmugglerSkill=%d\n",Info[playerid][pSmugSkill]);fwrite(hFile, var);
				format(var, 32, "DrugsSkill=%d\n",Info[playerid][pDrugsSkill]);fwrite(hFile, var);
				format(var, 32, "SIDA=%d\n",Info[playerid][pSIDA]);fwrite(hFile, var);
				format(var, 32, "Cancer=%d\n",Info[playerid][pCancer]);fwrite(hFile, var);
				format(var, 32, "Epilepsia=%d\n",Info[playerid][pEpilepsia]);fwrite(hFile, var);
				format(var, 32, "Dengue=%d\n",Info[playerid][pDengue]);fwrite(hFile, var);
				format(var, 32, "FStyle=%d\n",Info[playerid][pFStyle]);fwrite(hFile, var);
				format(var, 32, "Busqueda=%d\n",Info[playerid][pWantedLevel]);fwrite(hFile, var);
				format(var, 32, "AntiSIDA=%d\n",Info[playerid][pAntiSIDA]);fwrite(hFile, var);
				format(var, 32, "AntiCancer=%d\n",Info[playerid][pAntiCancer]);fwrite(hFile, var);
				format(var, 32, "AntiEpilepsia=%d\n",Info[playerid][pAntiEpilepsia]);fwrite(hFile, var);
				format(var, 32, "Rent=%d\n",Info[playerid][pRenting]);fwrite(hFile, var);
				format(var, 32, "prMoney=%d\n",Info[playerid][p_Pr_Money]);fwrite(hFile, var);
				format(var, 32, "prTime=%d\n",Info[playerid][p_Pr_Time]);fwrite(hFile, var);
    			format(var, 32, "Rob=%d\n",Info[playerid][pRob]);fwrite(hFile, var);
				format(var, 32, "Premium=%d\n",Info[playerid][pPremium]);fwrite(hFile, var);
				format(var, 32, "CarPremium=%d\n",Info[playerid][pCarKey2]);fwrite(hFile, var);
				format(var, 32, "BanDuda=%d\n",Info[playerid][pBanDuda]);fwrite(hFile, var);
    			format(var, 32, "ReportMuted=%d\n",Info[playerid][pRMuted]);fwrite(hFile, var);
    			format(var, 32, "ReportMutedTotal=%d\n",Info[playerid][pRMutedTotal]);fwrite(hFile, var);
    			format(var, 32, "ReportMutedTime=%d\n",Info[playerid][pRMutedTime]);fwrite(hFile, var);
				format(var, 32, "Pasaporte=%d\n",Info[playerid][pPasaporte]);fwrite(hFile, var);
				format(var, 32, "RadioP=%d\n",Info[playerid][pRadio]);fwrite(hFile, var);
				format(var, 32, "KHZ=%d\n",Info[playerid][pRadioFreq]);fwrite(hFile, var);
			    format(var, 32, "Ipad=%d\n",Info[playerid][pIpadMusic]);fwrite(hFile, var);
				format(var, 32, "GiftTime=%d\n",Info[playerid][pGiftTime]);fwrite(hFile, var);
				for(new s = 0; s < 12; s++)
				{
					format(var, 32, "Gun%d=%d\n", s, Info[playerid][pGuns][s]);fwrite(hFile, var);
				}
				format(var, 32, "Acento=%d\n",Info[playerid][pAccent]);fwrite(hFile, var);
				format(var, 32, "PTokens=%d\n",Info[playerid][pPaintTokens]);fwrite(hFile, var);
				format(var, 32, "Undercover=%d\n",Info[playerid][pUndercover]);fwrite(hFile, var);
				format(var, 32, "Head=%d\n",Info[playerid][pHead]);fwrite(hFile, var);
				format(var, 32, "TaxiLicense=%d\n", Info[playerid][pTaxiLicense]);fwrite(hFile, var);
                format(var, 32, "Hospital=%d\n",Info[playerid][pHospital]);fwrite(hFile, var);
				format(var, 32, "CHits=%d\n",Info[playerid][pCHits]);fwrite(hFile, var);
				format(var, 32, "FHits=%d\n",Info[playerid][pFHits]);fwrite(hFile, var);
				format(var, 32, "Spraycan=%d\n",Info[playerid][pSpraycan]);fwrite(hFile, var);
				format(var, 32, "Married=%d\n",Info[playerid][pMarried]);fwrite(hFile, var);
				format(var, 32, "MarriedTo=%s\n",Info[playerid][pMarriedTo]);fwrite(hFile, var);
				format(var, 32, "ContractBy=%s\n",Info[playerid][pContractBy]);fwrite(hFile, var);
				format(var, 64, "ContractDetail=%s\n",Info[playerid][pContractDetail]);fwrite(hFile, var);
				format(var, 32, "pWExists=%d\n",Info[playerid][pWExists]);fwrite(hFile, var);
				format(var, 32, "pWX=%f\n",Info[playerid][pWX]);fwrite(hFile, var);
				format(var, 32, "pWY=%f\n",Info[playerid][pWY]);fwrite(hFile, var);
				format(var, 32, "pWZ=%f\n",Info[playerid][pWZ]);fwrite(hFile, var);
				format(var, 32, "pWVW=%d\n",Info[playerid][pWVW]);fwrite(hFile, var);
				format(var, 32, "pWInt=%d\n",Info[playerid][pWInt]);fwrite(hFile, var);
				format(var, 32, "pWValue=%d\n",Info[playerid][pWValue]);fwrite(hFile, var);
				format(var, 32, "pWSeeds=%d\n",Info[playerid][pWSeeds]);fwrite(hFile, var);
				format(var, 32, "PayEx=%d\n",Info[playerid][YaCobre]);fwrite(hFile, var);
				for(new v = 0; v < MAX_PLAYERTOYS; v++)
	    		{
					format(var, 32, "pt%dModelID=%d\n", v, PlayerToyInfo[playerid][v][ptModelID]);fwrite(hFile, var);
					format(var, 32, "pt%dBone=%d\n", v, PlayerToyInfo[playerid][v][ptBone]);fwrite(hFile, var);
	        		format(var, 32, "pt%dPosX=%.5f\n", v, PlayerToyInfo[playerid][v][ptPosX]);fwrite(hFile, var);
	    			format(var, 32, "pt%dPosY=%.5f\n", v, PlayerToyInfo[playerid][v][ptPosY]);fwrite(hFile, var);
	    			format(var, 32, "pt%dPosZ=%.5f\n", v, PlayerToyInfo[playerid][v][ptPosZ]);fwrite(hFile, var);
	    			format(var, 32, "pt%dRotX=%.5f\n", v, PlayerToyInfo[playerid][v][ptRotX]);fwrite(hFile, var);
	    			format(var, 32, "pt%dRotY=%.5f\n", v, PlayerToyInfo[playerid][v][ptRotY]);fwrite(hFile, var);
	    			format(var, 32, "pt%dRotZ=%.5f\n", v, PlayerToyInfo[playerid][v][ptRotZ]);fwrite(hFile, var);
	    			format(var, 32, "pt%dSizX=%.5f\n", v, PlayerToyInfo[playerid][v][fScaleX]);fwrite(hFile, var);
	    			format(var, 32, "pt%dSizY=%.5f\n", v, PlayerToyInfo[playerid][v][fScaleY]);fwrite(hFile, var);
	    			format(var, 32, "pt%dSizZ=%.5f\n", v, PlayerToyInfo[playerid][v][fScaleZ]);fwrite(hFile, var);
	    		}
				for(new v = 0; v < MAX_PLAYERVEHICLES; v++)
	    		{
	        		format(var, 32, "pv%dPosX=%.1f\n", v, PlayerVehicleInfo[playerid][v][pvPosX]);fwrite(hFile, var);
	    			format(var, 32, "pv%dPosY=%.1f\n", v, PlayerVehicleInfo[playerid][v][pvPosY]);fwrite(hFile, var);
	    			format(var, 32, "pv%dPosZ=%.1f\n", v, PlayerVehicleInfo[playerid][v][pvPosZ]);fwrite(hFile, var);
	    			format(var, 32, "pv%dPosAngle=%.1f\n", v, PlayerVehicleInfo[playerid][v][pvPosAngle]);fwrite(hFile, var);
	    			format(var, 32, "pv%dModelId=%d\n", v, PlayerVehicleInfo[playerid][v][pvModelId]);fwrite(hFile, var);
	    			format(var, 32, "pv%dLock=%d\n", v, PlayerVehicleInfo[playerid][v][pvLock]);fwrite(hFile, var);
	    			format(var, 32, "pv%dLocked=%d\n", v, PlayerVehicleInfo[playerid][v][pvLocked]);fwrite(hFile, var);
	    			format(var, 32, "pv%dPaintJob=%d\n", v, PlayerVehicleInfo[playerid][v][pvPaintJob]);fwrite(hFile, var);
	    			format(var, 32, "pv%dColor1=%d\n", v, PlayerVehicleInfo[playerid][v][pvColor1]);fwrite(hFile, var);
	   			 	format(var, 32, "pv%dColor2=%d\n", v, PlayerVehicleInfo[playerid][v][pvColor2]);fwrite(hFile, var);
	   			 	format(var, 32, "pv%dPrice=%d\n", v, PlayerVehicleInfo[playerid][v][pvPrice]);fwrite(hFile, var);
	   			 	format(var, 32, "pv%dTicket=%d\n", v, PlayerVehicleInfo[playerid][v][pvTicket]);fwrite(hFile, var);
	   			 	format(var, 32, "pv%dWeapon0=%d\n", v, PlayerVehicleInfo[playerid][v][pvWeapons][0]);fwrite(hFile, var);
	   			 	format(var, 32, "pv%dWeapon1=%d\n", v, PlayerVehicleInfo[playerid][v][pvWeapons][1]);fwrite(hFile, var);
	   			 	format(var, 32, "pv%dWeapon2=%d\n", v, PlayerVehicleInfo[playerid][v][pvWeapons][2]);fwrite(hFile, var);
	   			 	format(var, 32, "pv%dWepUpgrade=%d\n", v, PlayerVehicleInfo[playerid][v][pvWepUpgrade]);fwrite(hFile, var);
	   			 	if(PlayerVehicleInfo[playerid][v][pvImpounded] == 0) PlayerVehicleInfo[playerid][v][pvFuel] = VehicleFuel[PlayerVehicleInfo[playerid][v][pvId]];
	   			 	format(var, 32, "pv%dFuel=%d\n", v, PlayerVehicleInfo[playerid][v][pvFuel]);fwrite(hFile, var);
					format(var, 32, "pv%dImpound=%d\n", v, PlayerVehicleInfo[playerid][v][pvImpounded]);fwrite(hFile, var);
					format(var, 32, "pv%dHealth=%.1f\n", v, PlayerVehicleInfo[playerid][v][pvHealth]);fwrite(hFile, var);
	   			 	//format(var, 32, "pv%dNumPlate=%s\n", v, PlayerVehicleInfo[playerid][v][pvNumberPlate]);fwrite(hFile, var);
	    			for(new m = 0; m < MAX_MODS; m++)
	     	   		{
                		format(var, 32, "pv%dMod%d=%d\n", v, m, PlayerVehicleInfo[playerid][v][pvMods][m]);fwrite(hFile, var);
	        		}
	        		//format(var, 32, "pv%dAllowedPlayer=%s\n", v, PlayerVehicleInfo[playerid][v][pvAllowPlayer]);fwrite(hFile, var);
	    		}
				fclose(hFile);
			}
		}
	}
	return 1;
}

function OnPlayerLogin(playerid,password[])
{
    new string2[128];
    new string[256];
	new playername2[MAX_PLAYER_NAME];
	GetPlayerName(playerid, playername2, sizeof(playername2));
	format(string2, sizeof(string2), "users/%s.ini", playername2);
	new File: UserFile = fopen(string2, io_read);
	if ( UserFile )
	{
	    new PassData[128];
	    new keytmp[128], valtmp[128];
	    fread( UserFile , PassData , sizeof( PassData ) );
	    keytmp = ini_GetKey( PassData );
	    if( strcmp( keytmp , "Key" , true ) == 0 )
		{
			valtmp = ini_GetValue( PassData );
			strmid(Info[playerid][pKey], valtmp, 0, strlen(valtmp)-1, 24);
		}
		if(strcmp(Info[playerid][pKey],password, true ) == 0 )
		{
			    new key[ 128 ] , val[ 128 ];
			    new Data[ 128 ];
			    while ( fread( UserFile , Data , sizeof( Data ) ) )
				{
					key = ini_GetKey( Data );
					if( strcmp( key , "Level" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pLevel] = strval( val ); }
			    	if( strcmp( key , "AdminNivel" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pAdminNivel] = strval( val ); }
					if( strcmp( key , "BanAppealer" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pBanAppealer] = strval( val ); }
					if( strcmp( key , "FactionModerator" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pFactionModerator] = strval( val ); }
                    if( strcmp( key , "GangModerator" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pGangModerator] = strval( val ); }
					if( strcmp( key , "Helper" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pHelper] = strval( val ); }
			        if( strcmp( key , "ConnectedTime" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pConnectTime] = strval( val ); }
			        if( strcmp( key , "Registered" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pReg] = strval( val ); }
			        if( strcmp( key , "Sex" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pSex] = strval( val ); }
			        if( strcmp( key , "Age" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pAge] = strval( val ); }
			        if( strcmp( key , "Origin" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pOrigin] = strval( val ); }
			        if( strcmp( key , "Walk" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pWalk] = strval( val ); }
			        if( strcmp( key , "Respect" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pExp] = strval( val ); }
			        if( strcmp( key , "Money" , true ) == 0 ) { val = ini_GetValue( Data ); SetPVarInt(playerid, "Cash", strval( val )); }
					if( strcmp( key , "Bank" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pAccount] = strval( val ); }
					if( strcmp( key , "IP" , true ) == 0 ) { val = ini_GetValue( Data ); strmid(Info[playerid][pIP], val, 0, strlen(val)-1, 255); }
					if( strcmp( key , "Kills" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pKills] = strval( val ); }
			        if( strcmp( key , "Deaths" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pDeaths] = strval( val ); }
           			if( strcmp( key , "Arrested" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pArrested] = strval( val ); }
           			if( strcmp( key , "JailAdmin" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pJailAdmin] = strval( val ); }
			        if( strcmp( key , "LottoNr" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pLottoNr] = strval( val ); }
			        if( strcmp( key , "Job" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pJob] = strval( val ); }
           			if( strcmp( key , "NewMuted" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pNMute] = strval( val ); }
           			if( strcmp( key , "NewMutedTotal" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pNMuteTotal] = strval( val ); }
           			if( strcmp( key , "Warn" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pWarn] = strval( val ); }
                    if( strcmp( key , "WRestricted" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pWRestricted] = strval( val ); }
					if( strcmp( key , "Jailed" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pJailed] = strval( val ); }
			        if( strcmp( key , "JailTime" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pJailTime] = strval( val ); }
			        if( strcmp( key , "Materials" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pMats] = strval( val ); }
                    if( strcmp( key , "Packages" , true ) == 0 ) { val = ini_GetValue( Data ); SetPVarInt(playerid, key, strval( val )); }
					if( strcmp( key , "Drugs" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pDrugs] = strval( val ); }
                    if( strcmp( key , "Cosecha" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pCosecha] = strval( val ); }
					if( strcmp( key , "Crack" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pCrack] = strval( val ); }
                    if( strcmp( key , "Pot" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pPot] = strval( val ); }
                    if( strcmp( key , "Crates" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pCrates] = strval( val ); }
					if( strcmp( key , "Adic" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pAdiccion] = strval( val ); }
					if( strcmp( key , "Leader" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pLeader] = strval( val ); }
					if( strcmp( key , "Member" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pMember] = strval( val ); }
                    if( strcmp( key , "FMember" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pFMember] = strval( val ); }
					if( strcmp( key , "Division" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pDivision] = strval( val ); }
			        if( strcmp( key , "Rank" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pRank] = strval( val ); }
			        if( strcmp( key , "Char" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pChar] = strval( val ); }
			        if( strcmp( key , "pHealth" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pHealth] = floatstr( val ); }
			        if( strcmp( key , "pArmour" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pArmour] = floatstr( val ); }
			        if( strcmp( key , "Team" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pTeam] = strval( val ); }
			        if( strcmp( key , "Model" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pModel] = strval( val ); }
			        if( strcmp( key , "PhoneNr" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pPnumber] = strval( val ); }
					if( strcmp( key , "Sprunk" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pSprunk] = strval( val ); }
					if( strcmp( key , "Phonebook" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pPhoneBook] = strval( val ); }
			        if( strcmp( key , "House" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pPhousekey] = strval( val ); }
                    if( strcmp( key , "House2" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pPhousekey2] = strval( val ); }
					if( strcmp( key , "Int" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pInt] = strval( val ); }
					if( strcmp( key , "Pos_x" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pPos_x] = floatstr( val ); }
			        if( strcmp( key , "Pos_y" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pPos_y] = floatstr( val ); }
			        if( strcmp( key , "Pos_z" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pPos_z] = floatstr( val ); }
                    if( strcmp( key , "SPos_r" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pPos_r] = floatstr( val ); }
					if( strcmp( key , "CarLic" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pCarLic] = strval( val ); }
                    if( strcmp( key , "FlyLic" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pFlyLic] = strval( val ); }
					if( strcmp( key , "BoatLic" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pBoatLic] = strval( val ); }
			        if( strcmp( key , "GunLic" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pGunLic] = strval( val ); }
			        if( strcmp( key , "Gafas" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pGafas] = strval( val ); }
					if( strcmp( key , "Tutorial" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pTut] = strval( val ); }
                    if( strcmp( key , "Test" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pTestTut] = strval( val ); }
					if( strcmp( key , "VWorld" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pVW] = strval( val ); }
			        if( strcmp( key , "Lighter" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pLighter] = strval( val ); }
			        if( strcmp( key , "Cigarettes" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pCigarettes] = strval( val ); }
			        if( strcmp( key , "Hachis" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pHachis] = strval( val ); }
			        if( strcmp( key , "Papel" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pPapel] = strval( val ); }
			        if( strcmp( key , "Ban" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pBanned] = strval( val ); }
			        if( strcmp( key , "Disabled" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pDisabled] = strval( val ); }
					if( strcmp( key , "BlockBug" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pBlockBug] = strval( val ); }
					if( strcmp( key , "DNI" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pDNI] = strval( val ); }
			        if( strcmp( key , "VSkill" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pArmsSkill] = strval( val ); }
			        if( strcmp( key , "TSkill" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pTruckSkill] = strval( val ); }
                    if( strcmp( key , "SmugglerSkill" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pSmugSkill] = strval( val ); }
                    if( strcmp( key , "DrugsSkill" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pDrugsSkill] = strval( val ); }
					if( strcmp( key , "SIDA" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pSIDA] = strval( val ); }
					if( strcmp( key , "Cancer" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pCancer] = strval( val ); }
			        if( strcmp( key , "Epilepsia" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pEpilepsia] = strval( val ); }
			        if( strcmp( key , "Dengue" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pDengue] = strval( val ); }
			        if( strcmp( key , "FStyle" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pFStyle] = strval( val ); }
			        if( strcmp( key , "Busqueda" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pWantedLevel] = strval( val ); }
			        if( strcmp( key , "AntiSIDA" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pAntiSIDA] = strval( val ); }
			        if( strcmp( key , "AntiCancer" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pAntiCancer] = strval( val ); }
			        if( strcmp( key , "AntiEpilepsia" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pAntiEpilepsia] = strval( val ); }
			        if( strcmp( key , "Rent" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pRenting] = strval( val ); }
			        if( strcmp( key , "prMoney" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][p_Pr_Money] = strval( val ); }
			        if( strcmp( key , "prTime" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][p_Pr_Time] = strval( val ); }
			        if( strcmp( key , "Rob" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pRob] = strval( val ); }
                    if( strcmp( key , "Premium" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pPremium] = strval( val ); }
                    if( strcmp( key , "CarPremium" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pCarKey2] = strval( val ); }
                    if( strcmp( key , "BanDuda" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pBanDuda] = strval( val ); }
					if( strcmp( key , "ReportMuted" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pRMuted] = strval( val ); }
                    if( strcmp( key , "ReportMutedTotal" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pRMutedTotal] = strval( val ); }
					if( strcmp( key , "ReportMutedTime" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pRMutedTime] = strval( val ); }
				    if( strcmp( key , "Pasaporte" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pPasaporte] = strval( val ); }
                    if( strcmp( key , "RadioP" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pRadio] = strval( val ); }
					if( strcmp( key , "KHZ" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pRadioFreq] = strval( val ); }
					if( strcmp( key , "Ipad" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pIpadMusic] = strval( val ); }
					if( strcmp( key , "GiftTime" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pGiftTime] = strval( val ); }
					for(new s = 0; s < 12; s++)
					{
						format(string, 128, "Gun%d", s);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pGuns][s] = strval( val ); }
					}
					if( strcmp( key , "Acento" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pAccent] = strval( val ); }
					if( strcmp( key , "PTokens" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pPaintTokens] = strval( val ); }
					if( strcmp( key , "Undercover" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pUndercover] = strval( val ); }
                    if( strcmp( key , "Head" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pHead] = strval( val ); }
                    if( strcmp( key, "TaxiLicense" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pTaxiLicense] = strval( val ); }
                    if( strcmp( key , "Hospital" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pHospital] = strval( val ); }
					if( strcmp( key , "CHits" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pCHits] = strval( val ); }
					if( strcmp( key , "FHits" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pFHits] = strval( val ); }
                    if( strcmp( key , "Spraycan" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pSpraycan] = strval( val ); }
					if( strcmp( key , "Married" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pMarried] = strval( val ); }
					if( strcmp( key , "MarriedTo" , true ) == 0 ) { val = ini_GetValue( Data ); strmid(Info[playerid][pMarriedTo], val, 0, strlen(val)-1, 255); }
					if( strcmp( key , "ContractBy" , true ) == 0 ) { val = ini_GetValue( Data ); strmid(Info[playerid][pContractBy], val, 0, strlen(val)-1, 255); }
					if( strcmp( key , "ContractDetail" , true ) == 0 ) { val = ini_GetValue( Data ); strmid(Info[playerid][pContractDetail], val, 0, strlen(val)-1, 255); }
					if( strcmp( key , "pWExists" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pWExists] = strval( val ); }
					if( strcmp( key , "pWX" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pWX] = floatstr( val ); }
					if( strcmp( key , "pWY" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pWY] = floatstr( val ); }
					if( strcmp( key , "pWZ" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pWZ] = floatstr( val ); }
					if( strcmp( key , "pWVW" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pWVW] = strval( val ); }
					if( strcmp( key , "pWInt" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pWInt] = strval( val ); }
					if( strcmp( key , "pWValue" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pWValue] = strval( val ); }
					if( strcmp( key , "pWSeeds" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][pWSeeds] = strval( val ); }
					if( strcmp( key , "PayEx" , true ) == 0 ) { val = ini_GetValue( Data ); Info[playerid][YaCobre] = strval( val ); }
					for(new v = 0; v < MAX_PLAYERTOYS; v++)
	        		{
	        		    format(string, 128, "pt%dModelID",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[playerid][v][ptModelID] = strval( val ); }
						format(string, 128, "pt%dBone",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[playerid][v][ptBone] = strval( val ); }
						format(string, 128, "pt%dPosX",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[playerid][v][ptPosX] = floatstr( val ); }
						format(string, 128, "pt%dPosY",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[playerid][v][ptPosY] = floatstr( val ); }
						format(string, 128, "pt%dPosZ",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[playerid][v][ptPosZ] = floatstr( val ); }
						format(string, 128, "pt%dRotX",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[playerid][v][ptRotX] = floatstr( val ); }
						format(string, 128, "pt%dRotY",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[playerid][v][ptRotY] = floatstr( val ); }
						format(string, 128, "pt%dRotZ",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[playerid][v][ptRotZ] = floatstr( val ); }
						format(string, 128, "pt%dSizX",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[playerid][v][fScaleX] = floatstr( val ); }
						format(string, 128, "pt%dSizY",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[playerid][v][fScaleY] = floatstr( val ); }
						format(string, 128, "pt%dSizZ",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[playerid][v][fScaleZ] = floatstr( val ); }
					}
					for(new v = 0; v < MAX_PLAYERVEHICLES; v++)
	        		{
						format(string, 128, "pv%dPosX",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvPosX] = floatstr( val ); }
						format(string, 128, "pv%dPosY",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvPosY] = floatstr( val ); }
						format(string, 128, "pv%dPosZ",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvPosZ] = floatstr( val ); }
						format(string, 128, "pv%dPosAngle",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvPosAngle] = floatstr( val ); }
						format(string, 128, "pv%dModelId",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvModelId] = strval( val ); }
						format(string, 128, "pv%dLock",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvLock] = strval( val ); }
						format(string, 128, "pv%dLocked",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvLocked] = strval( val ); }
						format(string, 128, "pv%dPaintJob",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvPaintJob] = strval( val ); }
						format(string, 128, "pv%dColor1",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvColor1] = strval( val ); }
						format(string, 128, "pv%dColor2",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvColor2] = strval( val ); }
						format(string, 128, "pv%dPrice",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvPrice] = strval( val ); }
						format(string, 128, "pv%dTicket",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvTicket] = strval( val ); }
						format(string, 128, "pv%dWeapon0",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvWeapons][0] = strval( val ); }
						format(string, 128, "pv%dWeapon1",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvWeapons][1] = strval( val ); }
						format(string, 128, "pv%dWeapon2",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvWeapons][2] = strval( val ); }
						format(string, 128, "pv%dWepUpgrade",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvWepUpgrade] = strval( val ); }
						format(string, 128, "pv%dFuel",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvFuel] = strval( val ); }
						format(string, 128, "pv%dImpound",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvImpounded] = strval( val ); }
						format(string, 128, "pv%dHealth",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvHealth] = floatstr( val ); }
						/*format(string, 128, "pv%dNumPlate",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); strcpy(PlayerVehicleInfo[playerid][v][pvNumberPlate], Data, 32); }*/ //PlayerVehicleInfo[playerid][v][pvNumberPlate] = floatstr( val ); }
						for(new m = 0; m < MAX_MODS; m++)
	            		{
                		    format(string, 128, "pv%dMod%d", v, m);
            		        if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[playerid][v][pvMods][m] = strval( val ); }
	        		    }
	        		    //format(string, 128, "pv%dAllowedPlayer",v);
	        		    //if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); strmid(PlayerVehicleInfo[playerid][v][pvAllowPlayer], val, 0, strlen(val)-1, 255); }
            		}
				}//end while
                fclose(UserFile);//close the file after everything has been read in the while
		}
		else
		{
		    new titlestring[64];
		    format(titlestring, sizeof(titlestring), "{FF8000}Error - {FFFFFF}%s", GetPlayerNameEx(playerid));
		    format(string, sizeof(string), "{FFFFFF}Contraseña Incorrecta.\nSi no recuerdas tu contraseña selecciona SALIR y acude al foro.\nDe lo contrario ingresa correctamente tu contraseña:");
		    ShowPlayerDialog(playerid,DLOGIN,DIALOG_STYLE_PASSWORD ,titlestring,string,"Entrar","Salir");
			gPlayerLogTries[playerid] += 1;
			if(gPlayerLogTries[playerid] == 2) { SendClientMessageEx(playerid, COLOR_GENERAL, "SERVER: Contraseña incorrecta, fuiste expulsado automáticamente."); Kick(playerid); }
			return 1;
		}
		TotalLogin++;
		ResetPlayerMoney(playerid);
		CurrentMoney[playerid] = GetPVarInt(playerid, "Cash");
		if(Info[playerid][pDisabled] == 1)
		{
		    SendClientMessageEx(playerid, COLOR_GENERAL,"Error [#12]");
    	    SendClientMessageEx(playerid, COLOR_WHITE, "Esta cuenta está deshabilitada.");
    	    Kick(playerid);
		}
		if(Info[playerid][pBanned] >= 1)
    	{
    	    SendClientMessageEx(playerid, COLOR_GENERAL,"Error [#10]");
    	    SendClientMessageEx(playerid, COLOR_WHITE, "SERVER: Tú estás baneado del servidor.");
    	    Kick(playerid);
		}
		if(Info[playerid][pAdminNivel] > 0)
		{
			new tempip[32];
			GetPlayerIp(playerid, tempip, 32);
			if(strcmp(tempip, Info[playerid][pIP], true))
			{
				format(string, sizeof(string), "%s ha logueado con diferente [IP: %s] - IP original es: %s", GetPlayerNameEx(playerid), tempip, Info[playerid][pIP]);
				ABroadCast(COLOR_ORANGE, string, 4);
			}
		}
		if(Info[playerid][pWRestricted] == 1) ResetPlayerWeaponsEx(playerid);
		if(Info[playerid][pConnectTime] >= 3) Info[playerid][pWRestricted] = 0;
		GetPlayerIp(playerid, Info[playerid][pIP], 32);
		SetPlayerScore(playerid, Info[playerid][pLevel]);
		if(Info[playerid][pReg] == 0)
		{
			Info[playerid][pLevel] = 0;
			Info[playerid][pHealth] = 100.0;
			Info[playerid][pPos_x] = 1612.3240;
			Info[playerid][pPos_y] = -2330.1670;
			Info[playerid][pPos_z] = 13.5469;
			Info[playerid][pInt] = 0;
			Info[playerid][pTeam] = 3;
			Info[playerid][pChar] = 299;
			Info[playerid][pPnumber] = 0;
			Info[playerid][pPhousekey] = INVALID_HOUSE_ID;
			Info[playerid][pPhousekey2] = INVALID_HOUSE_ID;
			Info[playerid][pAccount] = 0;
		}
		if(Info[playerid][pHospital] == 1)
		{
		    Info[playerid][pHospital] = 0;
           	SetPVarInt(playerid, "Hospital", 1);
		}
		new ip[32], tmp2[128];
		GetPlayerIp(playerid, ip, 32);
        format(tmp2, sizeof(tmp2), "SERVER: Bienvenido a Zenon City Role Play, %s.", GetPlayerNameEx(playerid));
        SendClientMessageEx(playerid, COLOR_GENERAL, tmp2);
        SendClientMessageEx(playerid, COLOR_WHITE, GlobalMOTD);
		switch(Info[playerid][pAdminNivel])
		{
			case 1:
			{
		    	SendClientMessageEx(playerid, COLOR_WHITE, "Te has conectado como Moderador."); gOoc[playerid] = 0;
			}
			case 2, 3, 4, 5, 1338, 99999:
			{
		    	format(string2, sizeof(string2), "Te has conectado como Administrador nivel {FF8409}%d", Info[playerid][pAdminNivel]);
		    	SendClientMessageEx(playerid, COLOR_WHITE, string2); gOoc[playerid] = 0;
		    }
		}
		switch(Info[playerid][pHelper])
		{
			case 1:
			{
		    	SendClientMessageEx(playerid, COLOR_WHITE, "Te has conectado como ayudante.");
				gOoc[playerid] = 0;
			}
			case 2:
			{
		    	SendClientMessageEx(playerid, COLOR_WHITE, "* Te has conectado como Lider de Ayudantes.");
		    	gOoc[playerid] = 0;
		    }
		}
   		if(Info[playerid][pAdminNivel] == 1)
		{
  			format( string2, sizeof( string2 ), "SERVER: %s ha logeado como moderador.", GetPlayerNameEx( playerid ));
  			ABroadCast(COLOR_WHITE, string2, 1338);
		}
		else if(Info[playerid][pAdminNivel] >= 2)
		{
			format( string2, sizeof( string2 ), "SERVER: %s ha logeado como administrador nivel %d.", GetPlayerNameEx( playerid ), Info[playerid][pAdminNivel] );
            ABroadCast(COLOR_WHITE, string2, 1338);
		}
		if(Info[playerid][pTut] == 1) Info[playerid][pReg] = 1;
        MapsRemoveForPlayer(playerid);
	    SetSpawnInfo(playerid, Info[playerid][pTeam], Info[playerid][pChar], Info[playerid][pPos_x], Info[playerid][pPos_y], Info[playerid][pPos_z], 1.0, -1, -1, -1, -1, -1, -1);
     	SpawnPlayer(playerid);
        LoadPlayerVehicles(playerid);
        WeedLogin(playerid);
        gPlayerLogged[playerid] = 1;
		if(gTeam[playerid] == 0)
		{
			gTeam[playerid] = 3;
		}
		else
		{
			gTeam[playerid] = Info[playerid][pTeam];
		}
		if(Info[playerid][pAdminNivel] >= 1)
		{
			SendClientMessageEx(playerid, TEAM_AZTECAS_COLOR, AdminMOTD);
		}
		if(Info[playerid][pHelper] >= 1)
		{
		    SendClientMessageEx(playerid, TEAM_AZTECAS_COLOR, CAMOTD);
		}
		if(Info[playerid][pFMember] < 255)
		{
			format(tmp2, sizeof(tmp2), "Mensaje Familia: %s.", FamilyInfo[Info[playerid][pFMember]][FamilyMOTD]);
			SendClientMessageEx(playerid, COLOR_YELLOW, tmp2);
		}
 		if(Info[playerid][pMember] > 0)
		{
			format(tmp2, sizeof(tmp2), "Admin Msj: %s.", FACMOTD);
			SendClientMessageEx(playerid, COLOR_YELLOW, tmp2);
		}
		if(Info[playerid][pFMember] < 255)
		{
			format(tmp2, sizeof(tmp2), "Admin Msj: %s.", FAMMOTD);
			SendClientMessageEx(playerid, COLOR_YELLOW, tmp2);
		}
  		SetPlayerFightingStyle (playerid, Info[playerid][pFStyle]);
		HideMenuLogin(playerid);
	 	new hcheck, hcheck2, name[MAX_PLAYER_NAME];
 		hcheck = INVALID_HOUSE_ID;
		hcheck2 = INVALID_HOUSE_ID;
		GetPlayerName(playerid, name, sizeof(name));
		for(new i = 0; i < MAX_HOUSES; i++)
		{
	  		if(!strcmp(name, HouseInfo[i][hOwner], false))
	   		{
	   		    if(hcheck != INVALID_HOUSE_ID)
	   		    {
	   		        hcheck2 = i;
				}
				else
				{
					hcheck = i;
				}
    		}
		}
		if(hcheck != INVALID_HOUSE_ID)
	   	{
     		Info[playerid][pPhousekey] = hcheck;
		}
		if(hcheck2 != INVALID_HOUSE_ID)
	   	{
     		Info[playerid][pPhousekey2] = hcheck2;
		}
		if(hcheck == INVALID_HOUSE_ID)
		{
			Info[playerid][pPhousekey] = INVALID_HOUSE_ID;
			return 1;
		}
		if(hcheck2 == INVALID_HOUSE_ID)
		{
			Info[playerid][pPhousekey2] = INVALID_HOUSE_ID;
			return 1;
		}
 	}
	return 1;
}


function OnPlayerOfflineLogin(playername[])
{
	new string2[64], string[128];
	format(string2, sizeof(string2), "users/%s.ini", playername);
	new File: UserFile = fopen(string2, io_read);
	if ( UserFile )
	{
		new key[ 256 ] , val[ 256 ];
		new Data[ 256 ];
		while ( fread( UserFile , Data , sizeof( Data ) ) )
		{
					key = ini_GetKey( Data );
					if( strcmp( key , "Key" , true ) == 0 ) { val = ini_GetValue( Data ); strmid(Info[MAX_PLAYERS][pKey], val, 0, strlen(val)-1, 24); }
					if( strcmp( key , "Level" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pLevel] = strval( val ); }
					if( strcmp( key , "AdminNivel" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pAdminNivel] = strval( val ); }
					if( strcmp( key , "BanAppealer" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pBanAppealer] = strval( val ); }
					if( strcmp( key , "FactionModerator" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pFactionModerator] = strval( val ); }
                    if( strcmp( key , "GangModerator" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pGangModerator] = strval( val ); }
					if( strcmp( key , "Helper" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pHelper] = strval( val ); }
			        if( strcmp( key , "ConnectedTime" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pConnectTime] = strval( val ); }
			        if( strcmp( key , "Registered" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pReg] = strval( val ); }
			        if( strcmp( key , "Sex" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pSex] = strval( val ); }
			        if( strcmp( key , "Age" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pAge] = strval( val ); }
			        if( strcmp( key , "Origin" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pOrigin] = strval( val ); }
			        if( strcmp( key , "Walk" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pWalk] = strval( val ); }
			        if( strcmp( key , "Respect" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pExp] = strval( val ); }
			        if( strcmp( key , "Money" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pCash] = strval( val ); }
			        if( strcmp( key , "Bank" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pAccount] = strval( val ); }
					if( strcmp( key , "IP" , true ) == 0 ) { val = ini_GetValue( Data ); strmid(Info[MAX_PLAYERS][pIP], val, 0, strlen(val)-1, 255); }
					if( strcmp( key , "Kills" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pKills] = strval( val ); }
			        if( strcmp( key , "Deaths" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pDeaths] = strval( val ); }
           			if( strcmp( key , "Arrested" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pArrested] = strval( val ); }
           			if( strcmp( key , "JailAdmin" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pJailAdmin] = strval( val ); }
			        if( strcmp( key , "LottoNr" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pLottoNr] = strval( val ); }
			        if( strcmp( key , "Job" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pJob] = strval( val ); }
           			if( strcmp( key , "NewMuted" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pNMute] = strval( val ); }
           			if( strcmp( key , "NewMutedTotal" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pNMuteTotal] = strval( val ); }
           			if( strcmp( key , "Warn" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pWarn] = strval( val ); }
					if( strcmp( key , "WRestricted" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pWRestricted] = strval( val ); }
					if( strcmp( key , "Jailed" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pJailed] = strval( val ); }
			        if( strcmp( key , "JailTime" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pJailTime] = strval( val ); }
			        if( strcmp( key , "Materials" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pMats] = strval( val ); }
                    if( strcmp( key , "Packages" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pPackages] = strval( val ); }
					if( strcmp( key , "Drugs" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pDrugs] = strval( val ); }
                    if( strcmp( key , "Cosecha" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pCosecha] = strval( val ); }
					if( strcmp( key , "Crack" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pCrack] = strval( val ); }
                    if( strcmp( key , "Pot" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pPot] = strval( val ); }
                    if( strcmp( key , "Crates" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pCrates] = strval( val ); }
					if( strcmp( key , "Adic" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pAdiccion] = strval( val ); }
					if( strcmp( key , "Leader" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pLeader] = strval( val ); }
					if( strcmp( key , "Member" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pMember] = strval( val ); }
                    if( strcmp( key , "FMember" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pFMember] = strval( val ); }
					if( strcmp( key , "Division" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pDivision] = strval( val ); }
			        if( strcmp( key , "Rank" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pRank] = strval( val ); }
			        if( strcmp( key , "Char" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pChar] = strval( val ); }
			        if( strcmp( key , "pHealth" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pHealth] = floatstr( val ); }
			        if( strcmp( key , "pArmour" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pArmour] = floatstr( val ); }
			        if( strcmp( key , "Int" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pInt] = strval( val ); }
			        if( strcmp( key , "Team" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pTeam] = strval( val ); }
			        if( strcmp( key , "Model" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pModel] = strval( val ); }
			        if( strcmp( key , "PhoneNr" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pPnumber] = strval( val ); }
					if( strcmp( key , "Sprunk" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pSprunk] = strval( val ); }
					if( strcmp( key , "Phonebook" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pPhoneBook] = strval( val ); }
			        if( strcmp( key , "House" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pPhousekey] = strval( val ); }
			        if( strcmp( key , "House" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pPhousekey] = strval( val ); }
                    if( strcmp( key , "House2" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pPhousekey2] = strval( val ); }
					if( strcmp( key , "Pos_x" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pPos_x] = floatstr( val ); }
			        if( strcmp( key , "Pos_y" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pPos_y] = floatstr( val ); }
			        if( strcmp( key , "Pos_z" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pPos_z] = floatstr( val ); }
                    if( strcmp( key , "SPos_r" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pPos_r] = floatstr( val ); }
					if( strcmp( key , "CarLic" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pCarLic] = strval( val ); }
                    if( strcmp( key , "FlyLic" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pFlyLic] = strval( val ); }
					if( strcmp( key , "BoatLic" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pBoatLic] = strval( val ); }
			        if( strcmp( key , "GunLic" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pGunLic] = strval( val ); }
			        if( strcmp( key , "Gafas" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pGafas] = strval( val ); }
					if( strcmp( key , "Tutorial" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pTut] = strval( val ); }
                    if( strcmp( key , "Test" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pTestTut] = strval( val ); }
					if( strcmp( key , "VWorld" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pVW] = strval( val ); }
			        if( strcmp( key , "Lighter" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pLighter] = strval( val ); }
			        if( strcmp( key , "Cigarettes" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pCigarettes] = strval( val ); }
			        if( strcmp( key , "Hachis" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pHachis] = strval( val ); }
			        if( strcmp( key , "Papel" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pPapel] = strval( val ); }
			        if( strcmp( key , "Ban" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pBanned] = strval( val ); }
			        if( strcmp( key , "Disabled" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pDisabled] = strval( val ); }
					if( strcmp( key , "BlockBug" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pBlockBug] = strval( val ); }
					if( strcmp( key , "DNI" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pDNI] = strval( val ); }
            		for(new v = 0; v < MAX_PLAYERTOYS; v++)
	        		{
	        		    format(string, 128, "pt%dModelID",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[MAX_PLAYERS][v][ptModelID] = strval( val ); }
						format(string, 128, "pt%dBone",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[MAX_PLAYERS][v][ptBone] = strval( val ); }
						format(string, 128, "pt%dPosX",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[MAX_PLAYERS][v][ptPosX] = floatstr( val ); }
						format(string, 128, "pt%dPosY",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[MAX_PLAYERS][v][ptPosY] = floatstr( val ); }
						format(string, 128, "pt%dPosZ",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[MAX_PLAYERS][v][ptPosZ] = floatstr( val ); }
						format(string, 128, "pt%dRotX",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[MAX_PLAYERS][v][ptRotX] = floatstr( val ); }
						format(string, 128, "pt%dRotY",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[MAX_PLAYERS][v][ptRotY] = floatstr( val ); }
						format(string, 128, "pt%dRotZ",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[MAX_PLAYERS][v][ptRotZ] = floatstr( val ); }
						format(string, 128, "pt%dSizX",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[MAX_PLAYERS][v][fScaleX] = floatstr( val ); }
						format(string, 128, "pt%dSizY",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[MAX_PLAYERS][v][fScaleY] = floatstr( val ); }
						format(string, 128, "pt%dSizZ",v);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerToyInfo[MAX_PLAYERS][v][fScaleZ] = floatstr( val ); }
					}
					new v = 0;
					format(string, 128, "pv%dPosX",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPosX] = floatstr( val ); }
					format(string, 128, "pv%dPosY",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPosY] = floatstr( val ); }
					format(string, 128, "pv%dPosZ",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPosZ] = floatstr( val ); }
					format(string, 128, "pv%dPosAngle",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPosAngle] = floatstr( val ); }
					format(string, 128, "pv%dModelId",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvModelId] = strval( val ); }
					format(string, 128, "pv%dLock",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvLock] = strval( val ); }
					format(string, 128, "pv%dLocked",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvLocked] = strval( val ); }
					format(string, 128, "pv%dPaintJob",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPaintJob] = strval( val ); }
					format(string, 128, "pv%dColor1",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvColor1] = strval( val ); }
					format(string, 128, "pv%dColor2",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvColor2] = strval( val ); }
					format(string, 128, "pv%dPrice",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPrice] = strval( val ); }
					format(string, 128, "pv%dTicket",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvTicket] = strval( val ); }
					format(string, 128, "pv%dWeapon0",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][0] = strval( val ); }
					format(string, 128, "pv%dWeapon1",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][1] = strval( val ); }
					format(string, 128, "pv%dWeapon2",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][2] = strval( val ); }
					format(string, 128, "pv%dWepUpgrade",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvWepUpgrade] = strval( val ); }
					format(string, 128, "pv%dFuel",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvFuel] = strval( val ); }
					format(string, 128, "pv%dImpound",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvImpounded] = strval( val ); }
					format(string, 128, "pv%dHealth",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvHealth] = floatstr( val ); }
					//format(string, 128, "pv%dNumPlate",v);
					//if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); strcpy(PlayerVehicleInfo[MAX_PLAYERS][v][pvNumberPlate], Data, 32); }
					for(new m = 0; m < MAX_MODS; m++)
	            	{
                	    format(string, 128, "pv%dMod%d", v, m);
            		    if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvMods][m] = strval( val ); }
	        		}
	        		//format(string, 128, "pv%dAllowedPlayer",v);
		    	    //if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); strmid(PlayerVehicleInfo[MAX_PLAYERS][v][pvAllowPlayer], val, 0, strlen(val)-1, 255); }
					v = 1;
					format(string, 128, "pv%dPosX",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPosX] = floatstr( val ); }
					format(string, 128, "pv%dPosY",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPosY] = floatstr( val ); }
					format(string, 128, "pv%dPosZ",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPosZ] = floatstr( val ); }
					format(string, 128, "pv%dPosAngle",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPosAngle] = floatstr( val ); }
					format(string, 128, "pv%dModelId",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvModelId] = strval( val ); }
					format(string, 128, "pv%dLock",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvLock] = strval( val ); }
					format(string, 128, "pv%dLocked",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvLocked] = strval( val ); }
					format(string, 128, "pv%dPaintJob",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPaintJob] = strval( val ); }
					format(string, 128, "pv%dColor1",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvColor1] = strval( val ); }
					format(string, 128, "pv%dColor2",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvColor2] = strval( val ); }
					format(string, 128, "pv%dPrice",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPrice] = strval( val ); }
					format(string, 128, "pv%dTicket",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvTicket] = strval( val ); }
					format(string, 128, "pv%dWeapon0",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][0] = strval( val ); }
					format(string, 128, "pv%dWeapon1",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][1] = strval( val ); }
					format(string, 128, "pv%dWeapon2",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][2] = strval( val ); }
					format(string, 128, "pv%dWepUpgrade",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvWepUpgrade] = strval( val ); }
					format(string, 128, "pv%dFuel",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvFuel] = strval( val ); }
					format(string, 128, "pv%dImpound",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvImpounded] = strval( val ); }
					format(string, 128, "pv%dHealth",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvHealth] = floatstr( val ); }
					//format(string, 128, "pv%dNumPlate",v);
					//if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); strcpy(PlayerVehicleInfo[MAX_PLAYERS][v][pvNumberPlate], Data, 32); }
					for(new m = 0; m < MAX_MODS; m++)
	            	{
                	    format(string, 128, "pv%dMod%d", v, m);
            		    if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvMods][m] = strval( val ); }
	        		}
	        		//format(string, 128, "pv%dAllowedPlayer",v);
		    	    //if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); strmid(PlayerVehicleInfo[MAX_PLAYERS][v][pvAllowPlayer], val, 0, strlen(val)-1, 255); }+
					v = 2;
					format(string, 128, "pv%dPosX",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPosX] = floatstr( val ); }
					format(string, 128, "pv%dPosY",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPosY] = floatstr( val ); }
					format(string, 128, "pv%dPosZ",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPosZ] = floatstr( val ); }
					format(string, 128, "pv%dPosAngle",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPosAngle] = floatstr( val ); }
					format(string, 128, "pv%dModelId",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvModelId] = strval( val ); }
					format(string, 128, "pv%dLock",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvLock] = strval( val ); }
					format(string, 128, "pv%dLocked",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvLocked] = strval( val ); }
					format(string, 128, "pv%dPaintJob",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPaintJob] = strval( val ); }
					format(string, 128, "pv%dColor1",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvColor1] = strval( val ); }
					format(string, 128, "pv%dColor2",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvColor2] = strval( val ); }
					format(string, 128, "pv%dPrice",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvPrice] = strval( val ); }
					format(string, 128, "pv%dTicket",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvTicket] = strval( val ); }
					format(string, 128, "pv%dWeapon0",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][0] = strval( val ); }
					format(string, 128, "pv%dWeapon1",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][1] = strval( val ); }
					format(string, 128, "pv%dWeapon2",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][2] = strval( val ); }
					format(string, 128, "pv%dWepUpgrade",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvWepUpgrade] = strval( val ); }
					format(string, 128, "pv%dFuel",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvFuel] = strval( val ); }
					format(string, 128, "pv%dImpound",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvImpounded] = strval( val ); }
					format(string, 128, "pv%dHealth",v);
					if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvHealth] = floatstr( val ); }
					//format(string, 128, "pv%dNumPlate",v);
					//if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); strcpy(PlayerVehicleInfo[MAX_PLAYERS][v][pvNumberPlate], Data, 32); }
					for(new m = 0; m < MAX_MODS; m++)
	            	{
                	    format(string, 128, "pv%dMod%d", v, m);
            		    if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); PlayerVehicleInfo[MAX_PLAYERS][v][pvMods][m] = strval( val ); }
	        		}
			        if( strcmp( key , "TSkill" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pTruckSkill] = strval( val ); }
					if(strcmp( key , "VSkill" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pArmsSkill] = strval( val ); }
                    if( strcmp( key , "SmugglerSkill" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pSmugSkill] = strval( val ); }
                    if( strcmp( key , "DrugsSkill" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pDrugsSkill] = strval( val ); }
					if( strcmp( key , "SIDA" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pSIDA] = strval( val ); }
			        if( strcmp( key , "Cancer" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pCancer] = strval( val ); }
			        if( strcmp( key , "Epilepsia" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pEpilepsia] = strval( val ); }
			        if( strcmp( key , "Dengue" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pDengue] = strval( val ); }
			        if( strcmp( key , "FStyle" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pFStyle] = strval( val ); }
			        if( strcmp( key , "Busqueda" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pWantedLevel] = strval( val ); }
			        if( strcmp( key , "AntiSIDA" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pAntiSIDA] = strval( val ); }
			        if( strcmp( key , "AntiCancer" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pAntiCancer] = strval( val ); }
			        if( strcmp( key , "AntiEpilepsia" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pAntiEpilepsia] = strval( val ); }
			        if( strcmp( key , "Rent" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pRenting] = strval( val ); }
			        if( strcmp( key , "prMoney" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][p_Pr_Money] = strval( val ); }
			        if( strcmp( key , "prTime" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][p_Pr_Time] = strval( val ); }
			        if( strcmp( key , "Rob" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pRob] = strval( val ); }
                    if( strcmp( key , "Premium" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pPremium] = strval( val ); }
                    if( strcmp( key , "CarPremium" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pCarKey2] = strval( val ); }
                    if( strcmp( key , "BanDuda" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pBanDuda] = strval( val ); }
					if( strcmp( key , "ReportMuted" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pRMuted] = strval( val ); }
                    if( strcmp( key , "ReportMutedTotal" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pRMutedTotal] = strval( val ); }
					if( strcmp( key , "ReportMutedTime" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pRMutedTime] = strval( val ); }
				    if( strcmp( key , "Pasaporte" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pPasaporte] = strval( val ); }
                    if( strcmp( key , "RadioP" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pRadio] = strval( val ); }
					if( strcmp( key , "KHZ" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pRadioFreq] = strval( val ); }
					if( strcmp( key , "Ipad" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pIpadMusic] = strval( val ); }
					if( strcmp( key , "GiftTime" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pGiftTime] = strval( val ); }
					for(new s = 0; s < 12; s++)
					{
						format(string, 128, "Gun%d", s);
						if( strcmp( key , string , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pGuns][s] = strval( val ); }
					}
					if( strcmp( key , "Acento" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pAccent] = strval( val ); }
					if( strcmp( key , "PTokens" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pPaintTokens] = strval( val ); }
					if( strcmp( key , "Undercover" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pUndercover] = strval( val ); }
                    if( strcmp( key , "Head" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pHead] = strval( val ); }
                    if( strcmp( key, "TaxiLicense" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pTaxiLicense] = strval( val ); }
                    if( strcmp( key , "Hospital" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pHospital] = strval( val ); }
					if( strcmp( key , "CHits" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pCHits] = strval( val ); }
					if( strcmp( key , "FHits" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pFHits] = strval( val ); }
					if( strcmp( key , "Spraycan" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pSpraycan] = strval( val ); }
					if( strcmp( key , "Married" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pMarried] = strval( val ); }
					if( strcmp( key , "MarriedTo" , true ) == 0 ) { val = ini_GetValue( Data ); strmid(Info[MAX_PLAYERS][pMarriedTo], val, 0, strlen(val)-1, 255); }
					if( strcmp( key , "ContractBy" , true ) == 0 ) { val = ini_GetValue( Data ); strmid(Info[MAX_PLAYERS][pContractBy], val, 0, strlen(val)-1, 255); }
					if( strcmp( key , "ContractDetail" , true ) == 0 ) { val = ini_GetValue( Data ); strmid(Info[MAX_PLAYERS][pContractDetail], val, 0, strlen(val)-1, 255); }
					if( strcmp( key , "pWExists" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pWExists] = strval( val ); }
					if( strcmp( key , "pWX" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pWX] = floatstr( val ); }
					if( strcmp( key , "pWY" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pWY] = floatstr( val ); }
					if( strcmp( key , "pWZ" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pWZ] = floatstr( val ); }
					if( strcmp( key , "pWVW" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pWVW] = strval( val ); }
					if( strcmp( key , "pWInt" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pWInt] = strval( val ); }
					if( strcmp( key , "pWValue" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pWValue] = strval( val ); }
                    if( strcmp( key , "pWSeeds" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][pWSeeds] = strval( val ); }
                    if( strcmp( key , "PayEx" , true ) == 0 ) { val = ini_GetValue( Data ); Info[MAX_PLAYERS][YaCobre] = strval( val ); }
		}
		fclose(UserFile);
	}
}

function OnPlayerOfflineSave(playername[])
{
	new string3[32];
	//GetPlayerName(MAX_PLAYERS, playername, MAX_PLAYER_NAME);
	format(string3, sizeof(string3), "users/%s.ini", playername);
	new File: hFile = fopen(string3, io_write);
	if (hFile)
	{
				new var[156];
				format(var, 32, "Key=%s\n", Info[MAX_PLAYERS][pKey]);fwrite(hFile, var);
				format(var, 32, "Level=%d\n",Info[MAX_PLAYERS][pLevel]);fwrite(hFile, var);
				format(var, 32, "AdminNivel=%d\n",Info[MAX_PLAYERS][pAdminNivel]);fwrite(hFile, var);
				format(var, 32, "BanAppealer=%d\n",Info[MAX_PLAYERS][pBanAppealer]);fwrite(hFile, var);
				format(var, 32, "FactionModerator=%d\n",Info[MAX_PLAYERS][pFactionModerator]);fwrite(hFile, var);
				format(var, 32, "GangModerator=%d\n",Info[MAX_PLAYERS][pGangModerator]);fwrite(hFile, var);
				format(var, 32, "Helper=%d\n",Info[MAX_PLAYERS][pHelper]);fwrite(hFile, var);
				format(var, 32, "ConnectedTime=%d\n",Info[MAX_PLAYERS][pConnectTime]);fwrite(hFile, var);
				format(var, 32, "Registered=%d\n",Info[MAX_PLAYERS][pReg]);fwrite(hFile, var);
				format(var, 32, "Sex=%d\n",Info[MAX_PLAYERS][pSex]);fwrite(hFile, var);
				format(var, 32, "Age=%d\n",Info[MAX_PLAYERS][pAge]);fwrite(hFile, var);
				format(var, 32, "Origin=%d\n",Info[MAX_PLAYERS][pOrigin]);fwrite(hFile, var);
				format(var, 32, "Walk=%d\n",Info[MAX_PLAYERS][pWalk]);fwrite(hFile, var);
				format(var, 32, "Respect=%d\n",Info[MAX_PLAYERS][pExp]);fwrite(hFile, var);
				format(var, 32, "Money=%d\n",Info[MAX_PLAYERS][pCash]);fwrite(hFile, var);
				format(var, 32, "Bank=%d\n",Info[MAX_PLAYERS][pAccount]);fwrite(hFile, var);
				format(var, 32, "IP=%s\n",Info[MAX_PLAYERS][pIP]);fwrite(hFile, var);
				format(var, 32, "Kills=%d\n",Info[MAX_PLAYERS][pKills]);fwrite(hFile, var);
				format(var, 32, "Deaths=%d\n",Info[MAX_PLAYERS][pDeaths]);fwrite(hFile, var);
				format(var, 32, "Arrested=%d\n",Info[MAX_PLAYERS][pArrested]);fwrite(hFile, var);
				format(var, 32, "JailAdmin=%d\n",Info[MAX_PLAYERS][pJailAdmin]);fwrite(hFile, var);
				format(var, 32, "LottoNr=%d\n",Info[MAX_PLAYERS][pLottoNr]);fwrite(hFile, var);
				format(var, 32, "Job=%d\n",Info[MAX_PLAYERS][pJob]);fwrite(hFile, var);
				format(var, 32, "NewMuted=%d\n",Info[MAX_PLAYERS][pNMute]);fwrite(hFile, var);
				format(var, 32, "NewMutedTotal=%d\n",Info[MAX_PLAYERS][pNMuteTotal]);fwrite(hFile, var);
				format(var, 32, "Warns=%d\n",Info[MAX_PLAYERS][pWarn]);fwrite(hFile, var);
				format(var, 32, "WRestricted=%d\n",Info[MAX_PLAYERS][pWRestricted]);fwrite(hFile, var);
				format(var, 32, "Jailed=%d\n",Info[MAX_PLAYERS][pJailed]);fwrite(hFile, var);
				format(var, 32, "JailTime=%d\n",Info[MAX_PLAYERS][pJailTime]);fwrite(hFile, var);
				format(var, 32, "Materials=%d\n",Info[MAX_PLAYERS][pMats]);fwrite(hFile, var);
				format(var, 32, "Packages=%d\n",Info[MAX_PLAYERS][pPackages]);fwrite(hFile, var);
				format(var, 32, "Drugs=%d\n",Info[MAX_PLAYERS][pDrugs]);fwrite(hFile, var);
				format(var, 32, "Cosecha=%d\n",Info[MAX_PLAYERS][pCosecha]);fwrite(hFile, var);
				format(var, 32, "Crack=%d\n",Info[MAX_PLAYERS][pCrack]);fwrite(hFile, var);
				format(var, 32, "Pot=%d\n",Info[MAX_PLAYERS][pPot]);fwrite(hFile, var);
				format(var, 32, "Crates=%d\n",Info[MAX_PLAYERS][pCrates]);fwrite(hFile, var);
				format(var, 32, "Adic=%d\n",Info[MAX_PLAYERS][pAdiccion]);fwrite(hFile, var);
				format(var, 32, "Leader=%d\n",Info[MAX_PLAYERS][pLeader]);fwrite(hFile, var);
				format(var, 32, "Member=%d\n",Info[MAX_PLAYERS][pMember]);fwrite(hFile, var);
				format(var, 32, "FMember=%d\n",Info[MAX_PLAYERS][pFMember]);fwrite(hFile, var);
				format(var, 32, "Division=%d\n",Info[MAX_PLAYERS][pDivision]);fwrite(hFile, var);
				format(var, 32, "Rank=%d\n",Info[MAX_PLAYERS][pRank]);fwrite(hFile, var);
				format(var, 32, "Char=%d\n",Info[MAX_PLAYERS][pChar]);fwrite(hFile, var);
	            format(var, 32, "pHealth=%.1f\n",Info[MAX_PLAYERS][pHealth]);fwrite(hFile, var);
                format(var, 32, "pArmour=%.1f\n",Info[MAX_PLAYERS][pArmour]);fwrite(hFile, var);
				format(var, 32, "Int=%d\n",Info[MAX_PLAYERS][pInt]);fwrite(hFile, var);
				format(var, 32, "Team=%d\n",Info[MAX_PLAYERS][pTeam]);fwrite(hFile, var);
				format(var, 32, "Model=%d\n",Info[MAX_PLAYERS][pModel]);fwrite(hFile, var);
				format(var, 32, "PhoneNr=%d\n",Info[MAX_PLAYERS][pPnumber]);fwrite(hFile, var);
				format(var, 32, "Sprunk=%d\n",Info[MAX_PLAYERS][pSprunk]);fwrite(hFile, var);
				format(var, 32, "Phonebook=%d\n",Info[MAX_PLAYERS][pPhoneBook]);fwrite(hFile, var);
				format(var, 32, "House=%d\n",Info[MAX_PLAYERS][pPhousekey]);fwrite(hFile, var);
				format(var, 32, "House2=%d\n",Info[MAX_PLAYERS][pPhousekey2]);fwrite(hFile, var);
				format(var, 32, "Pos_x=%.1f\n",Info[MAX_PLAYERS][pPos_x]);fwrite(hFile, var);
				format(var, 32, "Pos_y=%.1f\n",Info[MAX_PLAYERS][pPos_y]);fwrite(hFile, var);
				format(var, 32, "Pos_z=%.1f\n",Info[MAX_PLAYERS][pPos_z]);fwrite(hFile, var);
				format(var, 32, "SPos_r=%.1f\n",Info[MAX_PLAYERS][pPos_r]);fwrite(hFile, var);
				format(var, 32, "CarLic=%d\n",Info[MAX_PLAYERS][pCarLic]);fwrite(hFile, var);
                format(var, 32, "FlyLic=%d\n",Info[MAX_PLAYERS][pFlyLic]);fwrite(hFile, var);
				format(var, 32, "BoatLic=%d\n",Info[MAX_PLAYERS][pBoatLic]);fwrite(hFile, var);
				format(var, 32, "GunLic=%d\n",Info[MAX_PLAYERS][pGunLic]);fwrite(hFile, var);
				format(var, 32, "Gafas=%d\n",Info[MAX_PLAYERS][pGafas]);fwrite(hFile, var);
				format(var, 32, "Tutorial=%d\n",Info[MAX_PLAYERS][pTut]);fwrite(hFile, var);
				format(var, 32, "Test=%d\n",Info[MAX_PLAYERS][pTestTut]);fwrite(hFile, var);
				format(var, 32, "VWorld=%d\n",Info[MAX_PLAYERS][pVW]);fwrite(hFile, var);
				format(var, 32, "Lighter=%d\n",Info[MAX_PLAYERS][pLighter]);fwrite(hFile, var);
				format(var, 32, "Cigarettes=%d\n",Info[MAX_PLAYERS][pCigarettes]);fwrite(hFile, var);
				format(var, 32, "Hachis=%d\n",Info[MAX_PLAYERS][pHachis]);fwrite(hFile, var);
				format(var, 32, "Papel=%d\n",Info[MAX_PLAYERS][pPapel]);fwrite(hFile, var);
				format(var, 32, "Ban=%d\n",Info[MAX_PLAYERS][pBanned]);fwrite(hFile, var);
				format(var, 32, "Disabled=%d\n",Info[MAX_PLAYERS][pDisabled]);fwrite(hFile, var);
				format(var, 32, "BlockBug=%d\n",Info[MAX_PLAYERS][pBlockBug]);fwrite(hFile, var);
				format(var, 32, "DNI=%d\n",Info[MAX_PLAYERS][pDNI]);fwrite(hFile, var);
				for(new v = 0; v < MAX_PLAYERTOYS; v++)
	    		{
					format(var, 32, "pt%dModelID=%d\n", v, PlayerToyInfo[MAX_PLAYERS][v][ptModelID]);fwrite(hFile, var);
					format(var, 32, "pt%dBone=%d\n", v, PlayerToyInfo[MAX_PLAYERS][v][ptBone]);fwrite(hFile, var);
	        		format(var, 32, "pt%dPosX=%.5f\n", v, PlayerToyInfo[MAX_PLAYERS][v][ptPosX]);fwrite(hFile, var);
	    			format(var, 32, "pt%dPosY=%.5f\n", v, PlayerToyInfo[MAX_PLAYERS][v][ptPosY]);fwrite(hFile, var);
	    			format(var, 32, "pt%dPosZ=%.5f\n", v, PlayerToyInfo[MAX_PLAYERS][v][ptPosZ]);fwrite(hFile, var);
	    			format(var, 32, "pt%dRotX=%.5f\n", v, PlayerToyInfo[MAX_PLAYERS][v][ptRotX]);fwrite(hFile, var);
	    			format(var, 32, "pt%dRotY=%.5f\n", v, PlayerToyInfo[MAX_PLAYERS][v][ptRotY]);fwrite(hFile, var);
	    			format(var, 32, "pt%dRotZ=%.5f\n", v, PlayerToyInfo[MAX_PLAYERS][v][ptRotZ]);fwrite(hFile, var);
	    			format(var, 32, "pt%dSizX=%.5f\n", v, PlayerToyInfo[MAX_PLAYERS][v][fScaleX]);fwrite(hFile, var);
	    			format(var, 32, "pt%dSizY=%.5f\n", v, PlayerToyInfo[MAX_PLAYERS][v][fScaleY]);fwrite(hFile, var);
	    			format(var, 32, "pt%dSizZ=%.5f\n", v, PlayerToyInfo[MAX_PLAYERS][v][fScaleZ]);fwrite(hFile, var);
	    		}
    			new v = 0;
     			format(var, 32, "pv%dPosX=%.1f\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPosX]);fwrite(hFile, var);
	    		format(var, 32, "pv%dPosY=%.1f\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPosY]);fwrite(hFile, var);
	    		format(var, 32, "pv%dPosZ=%.1f\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPosZ]);fwrite(hFile, var);
	    		format(var, 32, "pv%dPosAngle=%.1f\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPosAngle]);fwrite(hFile, var);
	    		format(var, 32, "pv%dModelId=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvModelId]);fwrite(hFile, var);
	    		format(var, 32, "pv%dLock=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvLock]);fwrite(hFile, var);
	    		format(var, 32, "pv%dLocked=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvLocked]);fwrite(hFile, var);
	    		format(var, 32, "pv%dPaintJob=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPaintJob]);fwrite(hFile, var);
	    		format(var, 32, "pv%dColor1=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvColor1]);fwrite(hFile, var);
	   			format(var, 32, "pv%dColor2=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvColor2]);fwrite(hFile, var);
	   			format(var, 32, "pv%dPrice=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPrice]);fwrite(hFile, var);
	   			format(var, 32, "pv%dTicket=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvTicket]);fwrite(hFile, var);
	   			format(var, 32, "pv%dWeapon0=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][0]);fwrite(hFile, var);
	   			format(var, 32, "pv%dWeapon1=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][1]);fwrite(hFile, var);
	   			format(var, 32, "pv%dWeapon2=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][2]);fwrite(hFile, var);
	   			format(var, 32, "pv%dWepUpgrade=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvWepUpgrade]);fwrite(hFile, var);
	   			format(var, 32, "pv%dFuel=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvFuel]);fwrite(hFile, var);
				format(var, 32, "pv%dImpound=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvImpounded]);fwrite(hFile, var);
				format(var, 32, "pv%dHealth=%.1f\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvHealth]);fwrite(hFile, var);
	   			//format(var, 32, "pv%dNumPlate=%s\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvNumberPlate]);fwrite(hFile, var);
	    		for(new m = 0; m < MAX_MODS; m++)
	     	   	{
                	format(var, 32, "pv%dMod%d=%d\n", v, m, PlayerVehicleInfo[MAX_PLAYERS][v][pvMods][m]);fwrite(hFile, var);
	        	}
	        	v = 1;
     			format(var, 32, "pv%dPosX=%.1f\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPosX]);fwrite(hFile, var);
	    		format(var, 32, "pv%dPosY=%.1f\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPosY]);fwrite(hFile, var);
	    		format(var, 32, "pv%dPosZ=%.1f\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPosZ]);fwrite(hFile, var);
	    		format(var, 32, "pv%dPosAngle=%.1f\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPosAngle]);fwrite(hFile, var);
	    		format(var, 32, "pv%dModelId=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvModelId]);fwrite(hFile, var);
	    		format(var, 32, "pv%dLock=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvLock]);fwrite(hFile, var);
	    		format(var, 32, "pv%dLocked=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvLocked]);fwrite(hFile, var);
	    		format(var, 32, "pv%dPaintJob=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPaintJob]);fwrite(hFile, var);
	    		format(var, 32, "pv%dColor1=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvColor1]);fwrite(hFile, var);
	   			format(var, 32, "pv%dColor2=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvColor2]);fwrite(hFile, var);
	   			format(var, 32, "pv%dPrice=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPrice]);fwrite(hFile, var);
	   			format(var, 32, "pv%dTicket=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvTicket]);fwrite(hFile, var);
	   			format(var, 32, "pv%dWeapon0=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][0]);fwrite(hFile, var);
	   			format(var, 32, "pv%dWeapon1=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][1]);fwrite(hFile, var);
	   			format(var, 32, "pv%dWeapon2=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][2]);fwrite(hFile, var);
	   			format(var, 32, "pv%dWepUpgrade=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvWepUpgrade]);fwrite(hFile, var);
	   			format(var, 32, "pv%dFuel=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvFuel]);fwrite(hFile, var);
				format(var, 32, "pv%dImpound=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvImpounded]);fwrite(hFile, var);
				format(var, 32, "pv%dHealth=%.1f\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvHealth]);fwrite(hFile, var);
	   			//format(var, 32, "pv%dNumPlate=%s\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvNumberPlate]);fwrite(hFile, var);
	    		for(new m = 0; m < MAX_MODS; m++)
	     	   	{
                	format(var, 32, "pv%dMod%d=%d\n", v, m, PlayerVehicleInfo[MAX_PLAYERS][v][pvMods][m]);fwrite(hFile, var);
	        	}
	        	//format(var, 32, "pv%dAllowedPlayer=%s\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvAllowPlayer]);fwrite(hFile, var);
	        	v = 2;
     			format(var, 32, "pv%dPosX=%.1f\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPosX]);fwrite(hFile, var);
	    		format(var, 32, "pv%dPosY=%.1f\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPosY]);fwrite(hFile, var);
	    		format(var, 32, "pv%dPosZ=%.1f\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPosZ]);fwrite(hFile, var);
	    		format(var, 32, "pv%dPosAngle=%.1f\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPosAngle]);fwrite(hFile, var);
	    		format(var, 32, "pv%dModelId=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvModelId]);fwrite(hFile, var);
	    		format(var, 32, "pv%dLock=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvLock]);fwrite(hFile, var);
	    		format(var, 32, "pv%dLocked=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvLocked]);fwrite(hFile, var);
	    		format(var, 32, "pv%dPaintJob=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPaintJob]);fwrite(hFile, var);
	    		format(var, 32, "pv%dColor1=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvColor1]);fwrite(hFile, var);
	   			format(var, 32, "pv%dColor2=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvColor2]);fwrite(hFile, var);
	   			format(var, 32, "pv%dPrice=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvPrice]);fwrite(hFile, var);
	   			format(var, 32, "pv%dTicket=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvTicket]);fwrite(hFile, var);
	   			format(var, 32, "pv%dWeapon0=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][0]);fwrite(hFile, var);
	   			format(var, 32, "pv%dWeapon1=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][1]);fwrite(hFile, var);
	   			format(var, 32, "pv%dWeapon2=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvWeapons][2]);fwrite(hFile, var);
	   			format(var, 32, "pv%dWepUpgrade=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvWepUpgrade]);fwrite(hFile, var);
	   			format(var, 32, "pv%dFuel=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvFuel]);fwrite(hFile, var);
				format(var, 32, "pv%dImpound=%d\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvImpounded]);fwrite(hFile, var);
				format(var, 32, "pv%dHealth=%.1f\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvHealth]);fwrite(hFile, var);
	   			//format(var, 32, "pv%dNumPlate=%s\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvNumberPlate]);fwrite(hFile, var);
	    		for(new m = 0; m < MAX_MODS; m++)
	     	   	{
                	format(var, 32, "pv%dMod%d=%d\n", v, m, PlayerVehicleInfo[MAX_PLAYERS][v][pvMods][m]);fwrite(hFile, var);
	        	}
	        	//format(var, 32, "pv%dAllowedPlayer=%s\n", v, PlayerVehicleInfo[MAX_PLAYERS][v][pvAllowPlayer]);fwrite(hFile, var);
	    		format(var, 32, "VSkill=%d\n",Info[MAX_PLAYERS][pArmsSkill]);fwrite(hFile, var);
	    		format(var, 32, "TSkill=%d\n",Info[MAX_PLAYERS][pTruckSkill]);fwrite(hFile, var);
	    		format(var, 32, "SmugglerSkill=%d\n",Info[MAX_PLAYERS][pSmugSkill]);fwrite(hFile, var);
	    		format(var, 32, "DrugsSkill=%d\n",Info[MAX_PLAYERS][pDrugsSkill]);fwrite(hFile, var);
				format(var, 32, "SIDA=%d\n",Info[MAX_PLAYERS][pSIDA]);fwrite(hFile, var);
				format(var, 32, "Cancer=%d\n",Info[MAX_PLAYERS][pCancer]);fwrite(hFile, var);
				format(var, 32, "Epilepsia=%d\n",Info[MAX_PLAYERS][pEpilepsia]);fwrite(hFile, var);
				format(var, 32, "Dengue=%d\n",Info[MAX_PLAYERS][pDengue]);fwrite(hFile, var);
				format(var, 32, "FStyle=%d\n",Info[MAX_PLAYERS][pFStyle]);fwrite(hFile, var);
				format(var, 32, "Busqueda=%d\n",Info[MAX_PLAYERS][pWantedLevel]);fwrite(hFile, var);
				format(var, 32, "AntiSIDA=%d\n",Info[MAX_PLAYERS][pAntiSIDA]);fwrite(hFile, var);
				format(var, 32, "AntiCancer=%d\n",Info[MAX_PLAYERS][pAntiCancer]);fwrite(hFile, var);
				format(var, 32, "AntiEpilepsia=%d\n",Info[MAX_PLAYERS][pAntiEpilepsia]);fwrite(hFile, var);
				format(var, 32, "Rent=%d\n",Info[MAX_PLAYERS][pRenting]);fwrite(hFile, var);
				format(var, 32, "prMoney=%d\n",Info[MAX_PLAYERS][p_Pr_Money]);fwrite(hFile, var);
				format(var, 32, "prTime=%d\n",Info[MAX_PLAYERS][p_Pr_Time]);fwrite(hFile, var);
				format(var, 32, "Rob=%d\n",Info[MAX_PLAYERS][pRob]);fwrite(hFile, var);
				format(var, 32, "Premium=%d\n",Info[MAX_PLAYERS][pPremium]);fwrite(hFile, var);
				format(var, 32, "CarPremium=%d\n",Info[MAX_PLAYERS][pCarKey2]);fwrite(hFile, var);
				format(var, 32, "BanDuda=%d\n",Info[MAX_PLAYERS][pBanDuda]);fwrite(hFile, var);
				format(var, 32, "ReportMuted=%d\n",Info[MAX_PLAYERS][pRMuted]);fwrite(hFile, var);
				format(var, 32, "ReportMutedTotal=%d\n",Info[MAX_PLAYERS][pRMutedTotal]);fwrite(hFile, var);
				format(var, 32, "ReportMutedTime=%d\n",Info[MAX_PLAYERS][pRMutedTime]);fwrite(hFile, var);
				format(var, 32, "Pasaporte=%d\n",Info[MAX_PLAYERS][pPasaporte]);fwrite(hFile, var);
				format(var, 32, "RadioP=%d\n",Info[MAX_PLAYERS][pRadio]);fwrite(hFile, var);
				format(var, 32, "KHZ=%d\n",Info[MAX_PLAYERS][pRadioFreq]);fwrite(hFile, var);
				format(var, 32, "Ipad=%d\n",Info[MAX_PLAYERS][pIpadMusic]);fwrite(hFile, var);
				format(var, 32, "GiftTime=%d\n",Info[MAX_PLAYERS][pGiftTime]);fwrite(hFile, var);
				for(new s = 0; s < 12; s++)
				{
					format(var, 32, "Gun%d=%d\n", s, Info[MAX_PLAYERS][pGuns][s]);fwrite(hFile, var);
				}
				format(var, 32, "Acento=%d\n",Info[MAX_PLAYERS][pAccent]);fwrite(hFile, var);
				format(var, 32, "PTokens=%d\n",Info[MAX_PLAYERS][pPaintTokens]);fwrite(hFile, var);
				format(var, 32, "Undercover=%d\n",Info[MAX_PLAYERS][pUndercover]);fwrite(hFile, var);
				format(var, 32, "Head=%d\n",Info[MAX_PLAYERS][pHead]);fwrite(hFile, var);
                format(var, 32, "TaxiLicense=%d\n",Info[MAX_PLAYERS][pTaxiLicense]);fwrite(hFile, var);
                format(var, 32, "Hospital=%d\n",Info[MAX_PLAYERS][pHospital]);fwrite(hFile, var);
				format(var, 32, "CHits=%d\n",Info[MAX_PLAYERS][pCHits]);fwrite(hFile, var);
				format(var, 32, "FHits=%d\n",Info[MAX_PLAYERS][pFHits]);fwrite(hFile, var);
                format(var, 32, "Spraycan=%d\n",Info[MAX_PLAYERS][pSpraycan]);fwrite(hFile, var);
				format(var, 32, "Married=%d\n",Info[MAX_PLAYERS][pMarried]);fwrite(hFile, var);
				format(var, 32, "MarriedTo=%s\n",Info[MAX_PLAYERS][pMarriedTo]);fwrite(hFile, var);
				format(var, 32, "ContractBy=%s\n",Info[MAX_PLAYERS][pContractBy]);fwrite(hFile, var);
				format(var, 64, "ContractDetail=%s\n",Info[MAX_PLAYERS][pContractDetail]);fwrite(hFile, var);
				format(var, 32, "pWExists=%d\n",Info[MAX_PLAYERS][pWExists]);fwrite(hFile, var);
				format(var, 32, "pWX=%f\n",Info[MAX_PLAYERS][pWX]);fwrite(hFile, var);
				format(var, 32, "pWY=%f\n",Info[MAX_PLAYERS][pWY]);fwrite(hFile, var);
				format(var, 32, "pWZ=%f\n",Info[MAX_PLAYERS][pWZ]);fwrite(hFile, var);
				format(var, 32, "pWVW=%d\n",Info[MAX_PLAYERS][pWVW]);fwrite(hFile, var);
				format(var, 32, "pWInt=%d\n",Info[MAX_PLAYERS][pWInt]);fwrite(hFile, var);
				format(var, 32, "pWValue=%d\n",Info[MAX_PLAYERS][pWValue]);fwrite(hFile, var);
                format(var, 32, "pWSeeds=%d\n",Info[MAX_PLAYERS][pWSeeds]);fwrite(hFile, var);
                format(var, 32, "PayEx=%d\n",Info[MAX_PLAYERS][YaCobre]);fwrite(hFile, var);
				//format(var, 34, "Accent=%d\n",Info[MAX_PLAYERS][pAccent]);fwrite(hFile, var);
				fclose(hFile);
	}
	return 1;
}

function OnPlayerRegister(playerid, password[])
{
	if(IsPlayerConnected(playerid))
	{
			new string3[64];
			new playername3[MAX_PLAYER_NAME];
			GetPlayerName(playerid, playername3, sizeof(playername3));
			format(string3, sizeof(string3), "users/%s.ini", playername3);
			new File: hFile = fopen(string3, io_write);
			if (hFile)
			{
			    strmid(Info[playerid][pKey], password, 0, strlen(password), 24);
			    new var[64];
				format(var, 32, "Key=%s\n", Info[playerid][pKey]);fwrite(hFile, var);
				format(var, 32, "Level=%d\n",Info[playerid][pLevel]);fwrite(hFile, var);
				format(var, 32, "AdminNivel=%d\n",Info[playerid][pAdminNivel]);fwrite(hFile, var);
				format(var, 32, "BanAppealer=%d\n",Info[playerid][pBanAppealer]);fwrite(hFile, var);
				format(var, 32, "FactionModerator=%d\n",Info[playerid][pFactionModerator]);fwrite(hFile, var);
				format(var, 32, "GangModerator=%d\n",Info[playerid][pGangModerator]);fwrite(hFile, var);
				format(var, 32, "Helper=%d\n",Info[playerid][pHelper]);fwrite(hFile, var);
				format(var, 32, "ConnectedTime=%d\n",Info[playerid][pConnectTime]);fwrite(hFile, var);
				format(var, 32, "Registered=%d\n",Info[playerid][pReg]);fwrite(hFile, var);
				format(var, 32, "Sex=%d\n",Info[playerid][pSex]);fwrite(hFile, var);
				format(var, 32, "Age=%d\n",Info[playerid][pAge]);fwrite(hFile, var);
				format(var, 32, "Origin=%d\n",Info[playerid][pOrigin]);fwrite(hFile, var);
				format(var, 32, "Walk=%d\n",Info[playerid][pWalk]);fwrite(hFile, var);
				format(var, 32, "Respect=%d\n",Info[playerid][pExp]);fwrite(hFile, var);
				format(var, 32, "Money=%d\n",GetPVarInt(playerid, "Cash"));fwrite(hFile, var);
				format(var, 32, "Bank=%d\n",Info[playerid][pAccount]);fwrite(hFile, var);
				format(var, 32, "IP=%s\n",Info[playerid][pIP]);fwrite(hFile, var);
				format(var, 32, "Kills=%d\n",Info[playerid][pKills]);fwrite(hFile, var);
				format(var, 32, "Deaths=%d\n",Info[playerid][pDeaths]);fwrite(hFile, var);
				format(var, 32, "Arrested=%d\n",Info[playerid][pArrested]);fwrite(hFile, var);
				format(var, 32, "JailAdmin=%d\n",Info[playerid][pJailAdmin]);fwrite(hFile, var);
				format(var, 32, "LottoNr=%d\n",Info[playerid][pLottoNr]);fwrite(hFile, var);
				format(var, 32, "Job=%d\n",Info[playerid][pJob]);fwrite(hFile, var);
				format(var, 32, "NewMuted=%d\n",Info[playerid][pNMute]);fwrite(hFile, var);
				format(var, 32, "NewMutedTotal=%d\n",Info[playerid][pNMuteTotal]);fwrite(hFile, var);
				format(var, 32, "Warns=%d\n",Info[playerid][pWarn]);fwrite(hFile, var);
				format(var, 32, "WRestricted=%d\n",Info[playerid][pWRestricted]);fwrite(hFile, var);
				format(var, 32, "Jailed=%d\n",Info[playerid][pJailed]);fwrite(hFile, var);
				format(var, 32, "JailTime=%d\n",Info[playerid][pJailTime]);fwrite(hFile, var);
				format(var, 32, "Materials=%d\n",Info[playerid][pMats]);fwrite(hFile, var);
				format(var, 32, "Packages=%d\n",GetPVarInt(playerid, "Packages"));fwrite(hFile, var);
				format(var, 32, "Drugs=%d\n",Info[playerid][pDrugs]);fwrite(hFile, var);
				format(var, 32, "Cosecha=%d\n",Info[playerid][pCosecha]);fwrite(hFile, var);
				format(var, 32, "Crack=%d\n",Info[playerid][pCrack]);fwrite(hFile, var);
				format(var, 32, "Pot=%d\n",Info[playerid][pPot]);fwrite(hFile, var);
				format(var, 32, "Crates=%d\n",Info[playerid][pCrates]);fwrite(hFile, var);
				format(var, 32, "Adic=%d\n",Info[playerid][pAdiccion]);fwrite(hFile, var);
				format(var, 32, "Leader=%d\n",Info[playerid][pLeader]);fwrite(hFile, var);
				format(var, 32, "Member=%d\n",Info[playerid][pMember]);fwrite(hFile, var);
				format(var, 32, "FMember=%d\n",Info[playerid][pFMember]);fwrite(hFile, var);
				format(var, 32, "Division=%d\n",Info[playerid][pDivision]);fwrite(hFile, var);
				format(var, 32, "Rank=%d\n",Info[playerid][pRank]);fwrite(hFile, var);
				format(var, 32, "Char=%d\n",Info[playerid][pChar]);fwrite(hFile, var);
	            format(var, 32, "pHealth=%.1f\n",Info[playerid][pHealth]);fwrite(hFile, var);
                format(var, 32, "pArmour=%.1f\n",Info[playerid][pArmour]);fwrite(hFile, var);
				format(var, 32, "Int=%d\n",Info[playerid][pInt]);fwrite(hFile, var);
				format(var, 32, "Team=%d\n",Info[playerid][pTeam]);fwrite(hFile, var);
				format(var, 32, "Model=%d\n",Info[playerid][pModel]);fwrite(hFile, var);
				format(var, 32, "PhoneNr=%d\n",Info[playerid][pPnumber]);fwrite(hFile, var);
				format(var, 32, "Sprunk=%d\n",Info[playerid][pSprunk]);fwrite(hFile, var);
				format(var, 32, "Phonebook=%d\n",Info[playerid][pPhoneBook]);fwrite(hFile, var);
				format(var, 32, "House=%d\n",Info[playerid][pPhousekey]);fwrite(hFile, var);
				format(var, 32, "House2=%d\n",Info[playerid][pPhousekey2]);fwrite(hFile, var);
				format(var, 32, "Pos_x=%.1f\n",Info[playerid][pPos_x]);fwrite(hFile, var);
				format(var, 32, "Pos_y=%.1f\n",Info[playerid][pPos_y]);fwrite(hFile, var);
				format(var, 32, "Pos_z=%.1f\n",Info[playerid][pPos_z]);fwrite(hFile, var);
				format(var, 32, "SPos_r=%.1f\n",Info[playerid][pPos_r]);fwrite(hFile, var);
				format(var, 32, "CarLic=%d\n",Info[playerid][pCarLic]);fwrite(hFile, var);
                format(var, 32, "FlyLic=%d\n",Info[playerid][pFlyLic]);fwrite(hFile, var);
				format(var, 32, "BoatLic=%d\n",Info[playerid][pBoatLic]);fwrite(hFile, var);
				format(var, 32, "GunLic=%d\n",Info[playerid][pGunLic]);fwrite(hFile, var);
				format(var, 32, "Gafas=%d\n",Info[playerid][pGafas]);fwrite(hFile, var);
				format(var, 32, "Tutorial=%d\n",Info[playerid][pTut]);fwrite(hFile, var);
				format(var, 32, "Test=%d\n",Info[playerid][pTestTut]);fwrite(hFile, var);
				format(var, 32, "VWorld=%d\n",Info[playerid][pVW]);fwrite(hFile, var);
				format(var, 32, "Lighter=%d\n",Info[playerid][pLighter]);fwrite(hFile, var);
				format(var, 32, "Cigarettes=%d\n",Info[playerid][pCigarettes]);fwrite(hFile, var);
				format(var, 32, "Hachis=%d\n",Info[playerid][pHachis]);fwrite(hFile, var);
				format(var, 32, "Papel=%d\n",Info[playerid][pPapel]);fwrite(hFile, var);
				format(var, 32, "Ban=%d\n",Info[playerid][pBanned]);fwrite(hFile, var);
				format(var, 32, "Disabled=%d\n",Info[playerid][pDisabled]);fwrite(hFile, var);
				format(var, 32, "BlockBug=%d\n",Info[playerid][pBlockBug]);fwrite(hFile, var);
				format(var, 32, "DNI=%d\n",Info[playerid][pDNI]);fwrite(hFile, var);
				format(var, 32, "VSkill=%d\n",Info[playerid][pArmsSkill]);fwrite(hFile, var);
				format(var, 32, "TSkill=%d\n",Info[playerid][pTruckSkill]);fwrite(hFile, var);
				format(var, 32, "SmugglerSkill=%d\n",Info[playerid][pSmugSkill]);fwrite(hFile, var);
				format(var, 32, "DrugsSkill=%d\n",Info[playerid][pDrugsSkill]);fwrite(hFile, var);
				format(var, 32, "SIDA=%d\n",Info[playerid][pSIDA]);fwrite(hFile, var);
				format(var, 32, "Cancer=%d\n",Info[playerid][pCancer]);fwrite(hFile, var);
				format(var, 32, "Epilepsia=%d\n",Info[playerid][pEpilepsia]);fwrite(hFile, var);
				format(var, 32, "Dengue=%d\n",Info[playerid][pDengue]);fwrite(hFile, var);
				format(var, 32, "FStyle=%d\n",Info[playerid][pFStyle]);fwrite(hFile, var);
				format(var, 32, "Busqueda=%d\n",Info[playerid][pWantedLevel]);fwrite(hFile, var);
				format(var, 32, "AntiSIDA=%d\n",Info[playerid][pAntiSIDA]);fwrite(hFile, var);
				format(var, 32, "AntiCancer=%d\n",Info[playerid][pAntiCancer]);fwrite(hFile, var);
				format(var, 32, "AntiEpilepsia=%d\n",Info[playerid][pAntiEpilepsia]);fwrite(hFile, var);
				format(var, 32, "Rent=%d\n",Info[playerid][pRenting]);fwrite(hFile, var);
				format(var, 32, "prMoney=%d\n",Info[playerid][p_Pr_Money]);fwrite(hFile, var);
				format(var, 32, "prTime=%d\n",Info[playerid][p_Pr_Time]);fwrite(hFile, var);
				format(var, 32, "Rob=%d\n",Info[playerid][pRob]);fwrite(hFile, var);
				format(var, 32, "Premium=%d\n",Info[playerid][pPremium]);fwrite(hFile, var);
				format(var, 32, "CarPremium=%d\n",Info[playerid][pCarKey2]);fwrite(hFile, var);
				format(var, 32, "BanDuda=%d\n",Info[playerid][pBanDuda]);fwrite(hFile, var);
    			format(var, 32, "ReportMuted=%d\n",Info[playerid][pRMuted]);fwrite(hFile, var);
    			format(var, 32, "ReportMutedTotal=%d\n",Info[playerid][pRMutedTotal]);fwrite(hFile, var);
    			format(var, 32, "ReportMutedTime=%d\n",Info[playerid][pRMutedTime]);fwrite(hFile, var);
				format(var, 32, "Pasaporte=%d\n",Info[playerid][pPasaporte]);fwrite(hFile, var);
			    format(var, 32, "RadioP=%d\n",Info[playerid][pRadio]);fwrite(hFile, var);
				format(var, 32, "KHZ=%d\n",Info[playerid][pRadioFreq]);fwrite(hFile, var);
			    format(var, 32, "Ipad=%d\n",Info[playerid][pIpadMusic]);fwrite(hFile, var);
				format(var, 32, "GiftTime=%d\n",Info[playerid][pGiftTime]);fwrite(hFile, var);
				for(new s = 0; s < 12; s++)
				{
					format(var, 32, "Gun%d=%d\n", s, Info[playerid][pGuns][s]);fwrite(hFile, var);
				}
				format(var, 32, "Acento=%d\n",Info[playerid][pAccent]);fwrite(hFile, var);
				format(var, 32, "PTokens=%d\n",Info[playerid][pPaintTokens]);fwrite(hFile, var);
				format(var, 32, "Undercover=%d\n",Info[playerid][pUndercover]);fwrite(hFile, var);
				format(var, 32, "Head=%d\n",Info[playerid][pHead]);fwrite(hFile, var);
				format(var, 32, "TaxiLicense=%d\n", Info[playerid][pTaxiLicense]);fwrite(hFile, var);
				format(var, 32, "Hospital=%d\n",Info[playerid][pHospital]);fwrite(hFile, var);
				format(var, 32, "CHits=%d\n",Info[playerid][pCHits]);fwrite(hFile, var);
				format(var, 32, "FHits=%d\n",Info[playerid][pFHits]);fwrite(hFile, var);
				format(var, 32, "Spraycan=%d\n",Info[playerid][pSpraycan]);fwrite(hFile, var);
				format(var, 32, "Married=%d\n",Info[playerid][pMarried]);fwrite(hFile, var);
				format(var, 32, "MarriedTo=%s\n",Info[playerid][pMarriedTo]);fwrite(hFile, var);
				format(var, 32, "ContractBy=%s\n",Info[playerid][pContractBy]);fwrite(hFile, var);
				format(var, 64, "ContractDetail=%s\n",Info[playerid][pContractDetail]);fwrite(hFile, var);
				format(var, 32, "pWExists=%d\n",Info[playerid][pWExists]);fwrite(hFile, var);
				format(var, 32, "pWX=%f\n",Info[playerid][pWX]);fwrite(hFile, var);
				format(var, 32, "pWY=%f\n",Info[playerid][pWY]);fwrite(hFile, var);
				format(var, 32, "pWZ=%f\n",Info[playerid][pWZ]);fwrite(hFile, var);
				format(var, 32, "pWVW=%d\n",Info[playerid][pWVW]);fwrite(hFile, var);
				format(var, 32, "pWInt=%d\n",Info[playerid][pWInt]);fwrite(hFile, var);
				format(var, 32, "pWValue=%d\n",Info[playerid][pWValue]);fwrite(hFile, var);
				format(var, 32, "pWSeeds=%d\n",Info[playerid][pWSeeds]);fwrite(hFile, var);
				format(var, 32, "PayEx=%d\n",Info[playerid][YaCobre]);fwrite(hFile, var);
				for(new v = 0; v < MAX_PLAYERTOYS; v++)
	    		{
					format(var, 32, "pt%dModelID=%d\n", v, PlayerToyInfo[playerid][v][ptModelID]);fwrite(hFile, var);
					format(var, 32, "pt%dBone=%d\n", v, PlayerToyInfo[playerid][v][ptBone]);fwrite(hFile, var);
	        		format(var, 32, "pt%dPosX=%.5f\n", v, PlayerToyInfo[playerid][v][ptPosX]);fwrite(hFile, var);
	    			format(var, 32, "pt%dPosY=%.5f\n", v, PlayerToyInfo[playerid][v][ptPosY]);fwrite(hFile, var);
	    			format(var, 32, "pt%dPosZ=%.5f\n", v, PlayerToyInfo[playerid][v][ptPosZ]);fwrite(hFile, var);
	    			format(var, 32, "pt%dRotX=%.5f\n", v, PlayerToyInfo[playerid][v][ptRotX]);fwrite(hFile, var);
	    			format(var, 32, "pt%dRotY=%.5f\n", v, PlayerToyInfo[playerid][v][ptRotY]);fwrite(hFile, var);
	    			format(var, 32, "pt%dRotZ=%.5f\n", v, PlayerToyInfo[playerid][v][ptRotZ]);fwrite(hFile, var);
	    			format(var, 32, "pt%dSizX=%.5f\n", v, PlayerToyInfo[playerid][v][fScaleX]);fwrite(hFile, var);
	    			format(var, 32, "pt%dSizY=%.5f\n", v, PlayerToyInfo[playerid][v][fScaleY]);fwrite(hFile, var);
	    			format(var, 32, "pt%dSizZ=%.5f\n", v, PlayerToyInfo[playerid][v][fScaleZ]);fwrite(hFile, var);
	    		}
    			for(new v = 0; v < MAX_PLAYERVEHICLES; v++)
	    		{
	        		format(var, 32, "pv%dPosX=%.1f\n", v, PlayerVehicleInfo[playerid][v][pvPosX]);fwrite(hFile, var);
	    			format(var, 32, "pv%dPosY=%.1f\n", v, PlayerVehicleInfo[playerid][v][pvPosY]);fwrite(hFile, var);
	    			format(var, 32, "pv%dPosZ=%.1f\n", v, PlayerVehicleInfo[playerid][v][pvPosZ]);fwrite(hFile, var);
	    			format(var, 32, "pv%dPosAngle=%.1f\n", v, PlayerVehicleInfo[playerid][v][pvPosAngle]);fwrite(hFile, var);
	    			format(var, 32, "pv%dModelId=%d\n", v, PlayerVehicleInfo[playerid][v][pvModelId]);fwrite(hFile, var);
	    			format(var, 32, "pv%dLock=%d\n", v, PlayerVehicleInfo[playerid][v][pvLock]);fwrite(hFile, var);
	    			format(var, 32, "pv%dLocked=%d\n", v, PlayerVehicleInfo[playerid][v][pvLocked]);fwrite(hFile, var);
	    			format(var, 32, "pv%dPaintJob=%d\n", v, PlayerVehicleInfo[playerid][v][pvPaintJob]);fwrite(hFile, var);
	    			format(var, 32, "pv%dColor1=%d\n", v, PlayerVehicleInfo[playerid][v][pvColor1]);fwrite(hFile, var);
	   			 	format(var, 32, "pv%dColor2=%d\n", v, PlayerVehicleInfo[playerid][v][pvColor2]);fwrite(hFile, var);
	   			 	format(var, 32, "pv%dPrice=%d\n", v, PlayerVehicleInfo[playerid][v][pvPrice]);fwrite(hFile, var);
	   			 	format(var, 32, "pv%dTicket=%d\n", v, PlayerVehicleInfo[playerid][v][pvTicket]);fwrite(hFile, var);
	   			 	format(var, 32, "pv%dWeapon0=%d\n", v, PlayerVehicleInfo[playerid][v][pvWeapons][0]);fwrite(hFile, var);
	   			 	format(var, 32, "pv%dWeapon1=%d\n", v, PlayerVehicleInfo[playerid][v][pvWeapons][1]);fwrite(hFile, var);
	   			 	format(var, 32, "pv%dWeapon2=%d\n", v, PlayerVehicleInfo[playerid][v][pvWeapons][2]);fwrite(hFile, var);
	   			 	format(var, 32, "pv%dWepUpgrade=%d\n", v, PlayerVehicleInfo[playerid][v][pvWepUpgrade]);fwrite(hFile, var);
	   			 	format(var, 32, "pv%dFuel=%d\n", v, PlayerVehicleInfo[playerid][v][pvFuel]);fwrite(hFile, var);
					format(var, 32, "pv%dImpound=%d\n", v, PlayerVehicleInfo[playerid][v][pvImpounded]);fwrite(hFile, var);
					format(var, 32, "pv%dHealth=%.1f\n", v, PlayerVehicleInfo[playerid][v][pvHealth]);fwrite(hFile, var);
	   			 	//format(var, 32, "pv%dNumPlate=%s\n", v, PlayerVehicleInfo[playerid][v][pvNumberPlate]);fwrite(hFile, var);
	    			for(new m = 0; m < MAX_MODS; m++)
	     	   		{
                		format(var, 32, "pv%dMod%d=%d\n", v, m, PlayerVehicleInfo[playerid][v][pvMods][m]);fwrite(hFile, var);
	        		}
	        		//format(var, 32, "pv%dAllowedPlayer=%s\n", v, PlayerVehicleInfo[playerid][v][pvAllowPlayer]);fwrite(hFile, var);
	    		}
				fclose(hFile);
				TotalRegister++;
				SendClientMessageEx(playerid, COLOR_YELLOW, "Cuenta registrada, se ha iniciado sesión automáticamente.");
				OnPlayerLogin(playerid, password);
			}
	}
	return 1;
}