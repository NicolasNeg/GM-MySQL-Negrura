#include <a_samp>
#include <zcmd>
#include <sscanf2>
#include <a_mysql>

#define MySQL_HOST "localhost"
#define MySQL_USER "root"
#define MySQL_Password ""
#define MySQL_DB "bd_test"

#define Mensaje SendClientMessage
#define EstaEn IsPlayerInRangeOfPoint
#define TP SetPlayerPos

enum 
{
	Dialog_None = 0,
	DIALOG_VERIFY_PASSWORD,
	DIALOG_PASSWORD,
	DIALOG_GMAIL,
}

enum DatosPlayer
{
	pID,
	pContra[30],
	pNombre,
	pEdad,
	pGenero,
	pGmail[40],
	bool:SeLogueo,
	pSkin,
	pDinero,
	Float:pX,
	Float:pY,
	Float:pZ,
	pAdmin,
	Float:pVida,
	Float:pChaleco,
	pInt,
};
new PlayerInfo[MAX_PLAYERS][DatosPlayer];

new MySQL:MySQL;
/* Login */
new PlayerText:back[MAX_PLAYERS];
new PlayerText:Title[MAX_PLAYERS];
new PlayerText:log_pass_txt[MAX_PLAYERS];
new PlayerText:pass_verify[MAX_PLAYERS];
new PlayerText:Loguear[MAX_PLAYERS];
new PlayerText:cerrar_[MAX_PLAYERS];
/* Registro */
new PlayerText:Gender_txt[MAX_PLAYERS];
new PlayerText:Man[MAX_PLAYERS];
new PlayerText:Woman[MAX_PLAYERS];
new PlayerText:background[MAX_PLAYERS];
new PlayerText:Titulo[MAX_PLAYERS];
new PlayerText:Gmail_Text[MAX_PLAYERS];
new PlayerText:gmail_[MAX_PLAYERS];
new PlayerText:age_txt[MAX_PLAYERS];
new PlayerText:more_age[MAX_PLAYERS];
new PlayerText:menosage_[MAX_PLAYERS];
new PlayerText:result_age[MAX_PLAYERS];
new PlayerText:confirm[MAX_PLAYERS];
new PlayerText:close_[MAX_PLAYERS];
new PlayerText:pass_text[MAX_PLAYERS];
new PlayerText:password_entry[MAX_PLAYERS];
/* Notifi */
new PlayerText:Background_Box[MAX_PLAYERS];
new PlayerText:Text[MAX_PLAYERS];
/* Timer */
new TimerNotify[MAX_PLAYERS];
/* bool */
new bool:Correo_ll[MAX_PLAYERS] = false;
new bool:Password_[MAX_PLAYERS] = false;
new bool:Selec_Gen[MAX_PLAYERS] = false;
/* Verificacion contraseña */
new password_ve[30];

stock NombreJugador(playerid)
{
    new name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, sizeof(name));
    return name;
}
stock Connect_db()
{
    printf("Iniciando conexion MySQL: (Host: '%s', Usuario: '%s', Clave: '%s', Base de Datos: '%s')", MySQL_HOST, MySQL_USER, MySQL_Password, MySQL_DB);
    new MySQLOpt: option_id = mysql_init_options();
    mysql_set_option(option_id, AUTO_RECONNECT, true);
	MySQL = mysql_connect(MySQL_HOST, MySQL_USER,  MySQL_Password, MySQL_DB,option_id);
	if(MySQL == MYSQL_INVALID_HANDLE)
    {
        print("--------------------------------");
        print("[MySQL]: Error en la syntaxis de conexion.");
        print("--------------------------------");
    }
    if(mysql_errno(MySQL) == 0)
    {
        print("--------------------------------");
        print("[MySQL]: Conexion correcta con la base de datos.");
        print("--------------------------------");
    }
    else
    {
        print("--------------------------------");
        print("[MySQL]: Conexion fallida con la base de datos.");
        print("--------------------------------");
    }
    mysql_log(ALL);
	return 1;
}

stock strfindex(string[], find)
{
    for(new i=0; string[i]; i++)
    {
        if(string[i] == find)
        {
            return 1;
        }
    }
    return 0;
}
stock ShowLoginTD(playerid)
{
	SelectTextDraw(playerid, 0x966400FF);
	PlayerTextDrawShow(playerid, back[playerid]);
	PlayerTextDrawShow(playerid, Title[playerid]);
	PlayerTextDrawShow(playerid, log_pass_txt[playerid]);
	PlayerTextDrawShow(playerid, pass_verify[playerid]);
	PlayerTextDrawShow(playerid, Loguear[playerid]);
	PlayerTextDrawShow(playerid, cerrar_[playerid]);
	return 1;
}
stock HideLoginTD(playerid)
{
	CancelSelectTextDraw(playerid);
	PlayerTextDrawHide(playerid, back[playerid]);
	PlayerTextDrawHide(playerid, Title[playerid]);
	PlayerTextDrawHide(playerid, log_pass_txt[playerid]);
	PlayerTextDrawHide(playerid, pass_verify[playerid]);
	PlayerTextDrawHide(playerid, Loguear[playerid]);
	PlayerTextDrawHide(playerid, cerrar_[playerid]);
	return 1;
}
stock ShowRegisterTD(playerid)
{
	SelectTextDraw(playerid, 0x966400FF);
	PlayerTextDrawSetString(playerid, result_age[playerid], "18");
	PlayerTextDrawShow(playerid, Woman[playerid]);
	PlayerTextDrawShow(playerid, Man[playerid]);
	PlayerTextDrawShow(playerid, Gender_txt[playerid]);
	PlayerTextDrawShow(playerid, background[playerid]);
	PlayerTextDrawShow(playerid, Titulo[playerid]);
	PlayerTextDrawShow(playerid, Gmail_Text[playerid]);
	PlayerTextDrawShow(playerid, gmail_[playerid]);
	PlayerTextDrawShow(playerid, age_txt[playerid]);
	PlayerTextDrawShow(playerid, more_age[playerid]);
	PlayerTextDrawShow(playerid, menosage_[playerid]);
	PlayerTextDrawShow(playerid, result_age[playerid]);
	PlayerTextDrawShow(playerid, confirm[playerid]);
	PlayerTextDrawShow(playerid, close_[playerid]);
	PlayerTextDrawShow(playerid, pass_text[playerid]);
	PlayerTextDrawShow(playerid, password_entry[playerid]);
	PlayerInfo[playerid][pEdad] = 18;
	return 1;
}

stock HideRegisterTD(playerid)
{
	CancelSelectTextDraw(playerid);
	PlayerTextDrawHide(playerid, Woman[playerid]);
	PlayerTextDrawHide(playerid, Man[playerid]);
	PlayerTextDrawHide(playerid, Gender_txt[playerid]);
	PlayerTextDrawHide(playerid, background[playerid]);
	PlayerTextDrawHide(playerid, Titulo[playerid]);
	PlayerTextDrawHide(playerid, Gmail_Text[playerid]);
	PlayerTextDrawHide(playerid, gmail_[playerid]);
	PlayerTextDrawHide(playerid, age_txt[playerid]);
	PlayerTextDrawHide(playerid, more_age[playerid]);
	PlayerTextDrawHide(playerid, menosage_[playerid]);
	PlayerTextDrawHide(playerid, result_age[playerid]);
	PlayerTextDrawHide(playerid, confirm[playerid]);
	PlayerTextDrawHide(playerid, close_[playerid]);
	PlayerTextDrawHide(playerid, pass_text[playerid]);
	PlayerTextDrawHide(playerid, password_entry[playerid]);
	return 1;
}
stock LoadPlayerTextdraws(playerid)
{
/*Notify*/
Background_Box[playerid] = CreatePlayerTextDraw(playerid, 550.000000, 129.000000, "_");
PlayerTextDrawFont(playerid, Background_Box[playerid], 1);
PlayerTextDrawLetterSize(playerid, Background_Box[playerid], 0.695833, 7.049990);
PlayerTextDrawTextSize(playerid, Background_Box[playerid], 296.000000, 158.500000);
PlayerTextDrawSetOutline(playerid, Background_Box[playerid], 1);
PlayerTextDrawSetShadow(playerid, Background_Box[playerid], 0);
PlayerTextDrawAlignment(playerid, Background_Box[playerid], 2);
PlayerTextDrawColor(playerid, Background_Box[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, Background_Box[playerid], 255);
PlayerTextDrawBoxColor(playerid, Background_Box[playerid], 135);
PlayerTextDrawUseBox(playerid, Background_Box[playerid], 1);
PlayerTextDrawSetProportional(playerid, Background_Box[playerid], 1);
PlayerTextDrawSetSelectable(playerid, Background_Box[playerid], 0);

Text[playerid] = CreatePlayerTextDraw(playerid, 473.000000, 130.000000, "Insert Text");
PlayerTextDrawFont(playerid, Text[playerid], 1);
PlayerTextDrawLetterSize(playerid, Text[playerid], 0.600000, 1.250000);
PlayerTextDrawTextSize(playerid, Text[playerid], 400.000000, 17.000000);
PlayerTextDrawSetOutline(playerid, Text[playerid], 1);
PlayerTextDrawSetShadow(playerid, Text[playerid], 0);
PlayerTextDrawColor(playerid, Text[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, Text[playerid], 255);
PlayerTextDrawBoxColor(playerid, Text[playerid], 50);
PlayerTextDrawUseBox(playerid, Text[playerid], 0);
PlayerTextDrawSetProportional(playerid, Text[playerid], 0);
PlayerTextDrawSetSelectable(playerid, Text[playerid], 0);

/* Login */
back[playerid] = CreatePlayerTextDraw(playerid, 321.000000, 108.000000, "_");
PlayerTextDrawFont(playerid, back[playerid], 1);
PlayerTextDrawLetterSize(playerid, back[playerid], 0.354166, 24.049900);
PlayerTextDrawTextSize(playerid, back[playerid], 298.500000, 191.500000);
PlayerTextDrawSetOutline(playerid, back[playerid], 0);
PlayerTextDrawSetShadow(playerid, back[playerid], 2);
PlayerTextDrawAlignment(playerid, back[playerid], 2);
PlayerTextDrawColor(playerid, back[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, back[playerid], -1962934017);
PlayerTextDrawBoxColor(playerid, back[playerid], 35721);
PlayerTextDrawUseBox(playerid, back[playerid], 1);
PlayerTextDrawSetProportional(playerid, back[playerid], 1);
PlayerTextDrawSetSelectable(playerid, back[playerid], 0);

Title[playerid] = CreatePlayerTextDraw(playerid, 226.000000, 106.000000, "Login - Tu server");
PlayerTextDrawFont(playerid, Title[playerid], 1);
PlayerTextDrawLetterSize(playerid, Title[playerid], 0.550000, 2.000000);
PlayerTextDrawTextSize(playerid, Title[playerid], 408.500000, 17.000000);
PlayerTextDrawSetOutline(playerid, Title[playerid], 0);
PlayerTextDrawSetShadow(playerid, Title[playerid], 3);
PlayerTextDrawAlignment(playerid, Title[playerid], 1);
PlayerTextDrawColor(playerid, Title[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, Title[playerid], 255);
PlayerTextDrawBoxColor(playerid, Title[playerid], 50);
PlayerTextDrawUseBox(playerid, Title[playerid], 0);
PlayerTextDrawSetProportional(playerid, Title[playerid], 1);
PlayerTextDrawSetSelectable(playerid, Title[playerid], 0);

log_pass_txt[playerid] = CreatePlayerTextDraw(playerid, 229.000000, 177.000000, "Password:");
PlayerTextDrawFont(playerid, log_pass_txt[playerid], 1);
PlayerTextDrawLetterSize(playerid, log_pass_txt[playerid], 0.366665, 2.199999);
PlayerTextDrawTextSize(playerid, log_pass_txt[playerid], 296.000000, 17.000000);
PlayerTextDrawSetOutline(playerid, log_pass_txt[playerid], 0);
PlayerTextDrawSetShadow(playerid, log_pass_txt[playerid], 3);
PlayerTextDrawAlignment(playerid, log_pass_txt[playerid], 1);
PlayerTextDrawColor(playerid, log_pass_txt[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, log_pass_txt[playerid], 255);
PlayerTextDrawBoxColor(playerid, log_pass_txt[playerid], 50);
PlayerTextDrawUseBox(playerid, log_pass_txt[playerid], 0);
PlayerTextDrawSetProportional(playerid, log_pass_txt[playerid], 1);
PlayerTextDrawSetSelectable(playerid, log_pass_txt[playerid], 0);

pass_verify[playerid] = CreatePlayerTextDraw(playerid, 302.000000, 182.000000, "Click aqui");
PlayerTextDrawFont(playerid, pass_verify[playerid], 1);
PlayerTextDrawLetterSize(playerid, pass_verify[playerid], 0.220833, 1.750000);
PlayerTextDrawTextSize(playerid, pass_verify[playerid], 411.500000, 17.000000);
PlayerTextDrawSetOutline(playerid, pass_verify[playerid], 0);
PlayerTextDrawSetShadow(playerid, pass_verify[playerid], 3);
PlayerTextDrawAlignment(playerid, pass_verify[playerid], 1);
PlayerTextDrawColor(playerid, pass_verify[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, pass_verify[playerid], 255);
PlayerTextDrawBoxColor(playerid, pass_verify[playerid], 1687547186);
PlayerTextDrawUseBox(playerid, pass_verify[playerid], 1);
PlayerTextDrawSetProportional(playerid, pass_verify[playerid], 1);
PlayerTextDrawSetSelectable(playerid, pass_verify[playerid], 1);

Loguear[playerid] = CreatePlayerTextDraw(playerid, 317.000000, 305.000000, "Login");
PlayerTextDrawFont(playerid, Loguear[playerid], 1);
PlayerTextDrawLetterSize(playerid, Loguear[playerid], 0.600000, 2.000000);
PlayerTextDrawTextSize(playerid, Loguear[playerid], 358.000000, 61.500000);
PlayerTextDrawSetOutline(playerid, Loguear[playerid], 1);
PlayerTextDrawSetShadow(playerid, Loguear[playerid], 0);
PlayerTextDrawAlignment(playerid, Loguear[playerid], 2);
PlayerTextDrawColor(playerid, Loguear[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, Loguear[playerid], 255);
PlayerTextDrawBoxColor(playerid, Loguear[playerid], -2016478652);
PlayerTextDrawUseBox(playerid, Loguear[playerid], 0);
PlayerTextDrawSetProportional(playerid, Loguear[playerid], 1);
PlayerTextDrawSetSelectable(playerid, Loguear[playerid], 1);

cerrar_[playerid] = CreatePlayerTextDraw(playerid, 408.000000, 100.000000, "x");
PlayerTextDrawFont(playerid, cerrar_[playerid], 1);
PlayerTextDrawLetterSize(playerid, cerrar_[playerid], 0.470833, 1.799999);
PlayerTextDrawTextSize(playerid, cerrar_[playerid], 418.000000, 17.000000);
PlayerTextDrawSetOutline(playerid, cerrar_[playerid], 0);
PlayerTextDrawSetShadow(playerid, cerrar_[playerid], 2);
PlayerTextDrawAlignment(playerid, cerrar_[playerid], 1);
PlayerTextDrawColor(playerid, cerrar_[playerid], -16776961);
PlayerTextDrawBackgroundColor(playerid, cerrar_[playerid], 255);
PlayerTextDrawBoxColor(playerid, cerrar_[playerid], 50);
PlayerTextDrawUseBox(playerid, cerrar_[playerid], 0);
PlayerTextDrawSetProportional(playerid, cerrar_[playerid], 1);
PlayerTextDrawSetSelectable(playerid, cerrar_[playerid], 1);
/* Registro */
background[playerid] = CreatePlayerTextDraw(playerid, 317.000000, 78.000000, "_");
PlayerTextDrawFont(playerid, background[playerid], 1);
PlayerTextDrawLetterSize(playerid, background[playerid], 0.604165, 31.999782);
PlayerTextDrawTextSize(playerid, background[playerid], 304.000000, 214.500000);
PlayerTextDrawSetOutline(playerid, background[playerid], 3);
PlayerTextDrawSetShadow(playerid, background[playerid], 4);
PlayerTextDrawAlignment(playerid, background[playerid], 2);
PlayerTextDrawColor(playerid, background[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, background[playerid], -294256385);
PlayerTextDrawBoxColor(playerid, background[playerid], -764862861);
PlayerTextDrawUseBox(playerid, background[playerid], 1);
PlayerTextDrawSetProportional(playerid, background[playerid], 1);
PlayerTextDrawSetSelectable(playerid, background[playerid], 0);

Titulo[playerid] = CreatePlayerTextDraw(playerid, 218.000000, 77.000000, "Registro - Tu server");
PlayerTextDrawFont(playerid, Titulo[playerid], 1);
PlayerTextDrawLetterSize(playerid, Titulo[playerid], 0.550000, 2.049998);
PlayerTextDrawTextSize(playerid, Titulo[playerid], 427.500000, 17.000000);
PlayerTextDrawSetOutline(playerid, Titulo[playerid], 1);
PlayerTextDrawSetShadow(playerid, Titulo[playerid], 4);
PlayerTextDrawAlignment(playerid, Titulo[playerid], 1);
PlayerTextDrawColor(playerid, Titulo[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, Titulo[playerid], 255);
PlayerTextDrawBoxColor(playerid, Titulo[playerid], 50);
PlayerTextDrawUseBox(playerid, Titulo[playerid], 0);
PlayerTextDrawSetProportional(playerid, Titulo[playerid], 1);
PlayerTextDrawSetSelectable(playerid, Titulo[playerid], 0);

Gmail_Text[playerid] = CreatePlayerTextDraw(playerid, 213.000000, 136.000000, "Correo:");
PlayerTextDrawFont(playerid, Gmail_Text[playerid], 1);
PlayerTextDrawLetterSize(playerid, Gmail_Text[playerid], 0.437500, 1.799998);
PlayerTextDrawTextSize(playerid, Gmail_Text[playerid], 267.500000, 17.000000);
PlayerTextDrawSetOutline(playerid, Gmail_Text[playerid], 1);
PlayerTextDrawSetShadow(playerid, Gmail_Text[playerid], 0);
PlayerTextDrawAlignment(playerid, Gmail_Text[playerid], 1);
PlayerTextDrawColor(playerid, Gmail_Text[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, Gmail_Text[playerid], 255);
PlayerTextDrawBoxColor(playerid, Gmail_Text[playerid], 50);
PlayerTextDrawUseBox(playerid, Gmail_Text[playerid], 0);
PlayerTextDrawSetProportional(playerid, Gmail_Text[playerid], 1);
PlayerTextDrawSetSelectable(playerid, Gmail_Text[playerid], 0);

gmail_[playerid] = CreatePlayerTextDraw(playerid, 277.000000, 139.000000, "Click aqui.");
PlayerTextDrawFont(playerid, gmail_[playerid], 1);
PlayerTextDrawLetterSize(playerid, gmail_[playerid], 0.195831, 1.450000);
PlayerTextDrawTextSize(playerid, gmail_[playerid], 418.000000, 21.500000);
PlayerTextDrawSetOutline(playerid, gmail_[playerid], 1);
PlayerTextDrawSetShadow(playerid, gmail_[playerid], 0);
PlayerTextDrawAlignment(playerid, gmail_[playerid], 1);
PlayerTextDrawColor(playerid, gmail_[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, gmail_[playerid], 255);
PlayerTextDrawBoxColor(playerid, gmail_[playerid], -206);
PlayerTextDrawUseBox(playerid, gmail_[playerid], 1);
PlayerTextDrawSetProportional(playerid, gmail_[playerid], 1);
PlayerTextDrawSetSelectable(playerid, gmail_[playerid], 1);

age_txt[playerid] = CreatePlayerTextDraw(playerid, 214.000000, 190.000000, "Edad:");
PlayerTextDrawFont(playerid, age_txt[playerid], 1);
PlayerTextDrawLetterSize(playerid, age_txt[playerid], 0.304165, 1.850000);
PlayerTextDrawTextSize(playerid, age_txt[playerid], 240.000000, 17.000000);
PlayerTextDrawSetOutline(playerid, age_txt[playerid], 1);
PlayerTextDrawSetShadow(playerid, age_txt[playerid], 0);
PlayerTextDrawAlignment(playerid, age_txt[playerid], 1);
PlayerTextDrawColor(playerid, age_txt[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, age_txt[playerid], 255);
PlayerTextDrawBoxColor(playerid, age_txt[playerid], 50);
PlayerTextDrawUseBox(playerid, age_txt[playerid], 0);
PlayerTextDrawSetProportional(playerid, age_txt[playerid], 1);
PlayerTextDrawSetSelectable(playerid, age_txt[playerid], 0);

more_age[playerid] = CreatePlayerTextDraw(playerid, 311.000000, 189.000000, "+");
PlayerTextDrawFont(playerid, more_age[playerid], 1);
PlayerTextDrawLetterSize(playerid, more_age[playerid], 0.600000, 2.000000);
PlayerTextDrawTextSize(playerid, more_age[playerid], 322.500000, 17.000000);
PlayerTextDrawSetOutline(playerid, more_age[playerid], 1);
PlayerTextDrawSetShadow(playerid, more_age[playerid], 0);
PlayerTextDrawAlignment(playerid, more_age[playerid], 1);
PlayerTextDrawColor(playerid, more_age[playerid], 16711935);
PlayerTextDrawBackgroundColor(playerid, more_age[playerid], 255);
PlayerTextDrawBoxColor(playerid, more_age[playerid], 50);
PlayerTextDrawUseBox(playerid, more_age[playerid], 0);
PlayerTextDrawSetProportional(playerid, more_age[playerid], 1);
PlayerTextDrawSetSelectable(playerid, more_age[playerid], 1);

menosage_[playerid] = CreatePlayerTextDraw(playerid, 339.000000, 188.000000, "-");
PlayerTextDrawFont(playerid, menosage_[playerid], 1);
PlayerTextDrawLetterSize(playerid, menosage_[playerid], 0.600000, 2.000000);
PlayerTextDrawTextSize(playerid, menosage_[playerid], 346.500000, 17.000000);
PlayerTextDrawSetOutline(playerid, menosage_[playerid], 1);
PlayerTextDrawSetShadow(playerid, menosage_[playerid], 0);
PlayerTextDrawAlignment(playerid, menosage_[playerid], 1);
PlayerTextDrawColor(playerid, menosage_[playerid], -16776961);
PlayerTextDrawBackgroundColor(playerid, menosage_[playerid], 255);
PlayerTextDrawBoxColor(playerid, menosage_[playerid], 50);
PlayerTextDrawUseBox(playerid, menosage_[playerid], 0);
PlayerTextDrawSetProportional(playerid, menosage_[playerid], 1);
PlayerTextDrawSetSelectable(playerid, menosage_[playerid], 1);

result_age[playerid] = CreatePlayerTextDraw(playerid, 253.000000, 191.000000, "18-99");
PlayerTextDrawFont(playerid, result_age[playerid], 1);
PlayerTextDrawLetterSize(playerid, result_age[playerid], 0.379166, 1.799998);
PlayerTextDrawTextSize(playerid, result_age[playerid], 312.000000, 17.000000);
PlayerTextDrawSetOutline(playerid, result_age[playerid], 1);
PlayerTextDrawSetShadow(playerid, result_age[playerid], 0);
PlayerTextDrawAlignment(playerid, result_age[playerid], 1);
PlayerTextDrawColor(playerid, result_age[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, result_age[playerid], 255);
PlayerTextDrawBoxColor(playerid, result_age[playerid], 50);
PlayerTextDrawUseBox(playerid, result_age[playerid], 0);
PlayerTextDrawSetProportional(playerid, result_age[playerid], 1);
PlayerTextDrawSetSelectable(playerid, result_age[playerid], 0);

confirm[playerid] = CreatePlayerTextDraw(playerid, 256.000000, 348.000000, "Registrarme");
PlayerTextDrawFont(playerid, confirm[playerid], 1);
PlayerTextDrawLetterSize(playerid, confirm[playerid], 0.600000, 2.000000);
PlayerTextDrawTextSize(playerid, confirm[playerid], 381.000000, 17.000000);
PlayerTextDrawSetOutline(playerid, confirm[playerid], 1);
PlayerTextDrawSetShadow(playerid, confirm[playerid], 0);
PlayerTextDrawAlignment(playerid, confirm[playerid], 1);
PlayerTextDrawColor(playerid, confirm[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, confirm[playerid], 255);
PlayerTextDrawBoxColor(playerid, confirm[playerid], -8388413);
PlayerTextDrawUseBox(playerid, confirm[playerid], 1);
PlayerTextDrawSetProportional(playerid, confirm[playerid], 1);
PlayerTextDrawSetSelectable(playerid, confirm[playerid], 1);

close_[playerid] = CreatePlayerTextDraw(playerid, 416.000000, 70.000000, "x");
PlayerTextDrawFont(playerid, close_[playerid], 1);
PlayerTextDrawLetterSize(playerid, close_[playerid], 0.445832, 1.750000);
PlayerTextDrawTextSize(playerid, close_[playerid], 424.500000, 17.000000);
PlayerTextDrawSetOutline(playerid, close_[playerid], 1);
PlayerTextDrawSetShadow(playerid, close_[playerid], 0);
PlayerTextDrawAlignment(playerid, close_[playerid], 1);
PlayerTextDrawColor(playerid, close_[playerid], -16776961);
PlayerTextDrawBackgroundColor(playerid, close_[playerid], 255);
PlayerTextDrawBoxColor(playerid, close_[playerid], 50);
PlayerTextDrawUseBox(playerid, close_[playerid], 0);
PlayerTextDrawSetProportional(playerid, close_[playerid], 1);
PlayerTextDrawSetSelectable(playerid, close_[playerid], 1);

pass_text[playerid] = CreatePlayerTextDraw(playerid, 213.000000, 288.000000, "Password:");
PlayerTextDrawFont(playerid, pass_text[playerid], 1);
PlayerTextDrawLetterSize(playerid, pass_text[playerid], 0.341666, 1.899999);
PlayerTextDrawTextSize(playerid, pass_text[playerid], 272.500000, 17.000000);
PlayerTextDrawSetOutline(playerid, pass_text[playerid], 1);
PlayerTextDrawSetShadow(playerid, pass_text[playerid], 0);
PlayerTextDrawAlignment(playerid, pass_text[playerid], 1);
PlayerTextDrawColor(playerid, pass_text[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, pass_text[playerid], 255);
PlayerTextDrawBoxColor(playerid, pass_text[playerid], 50);
PlayerTextDrawUseBox(playerid, pass_text[playerid], 0);
PlayerTextDrawSetProportional(playerid, pass_text[playerid], 1);
PlayerTextDrawSetSelectable(playerid, pass_text[playerid], 0);

password_entry[playerid] = CreatePlayerTextDraw(playerid, 279.000000, 290.000000, "Click aqui");
PlayerTextDrawFont(playerid, password_entry[playerid], 1);
PlayerTextDrawLetterSize(playerid, password_entry[playerid], 0.220833, 1.700000);
PlayerTextDrawTextSize(playerid, password_entry[playerid], 418.500000, 12.000000);
PlayerTextDrawSetOutline(playerid, password_entry[playerid], 1);
PlayerTextDrawSetShadow(playerid, password_entry[playerid], 0);
PlayerTextDrawAlignment(playerid, password_entry[playerid], 1);
PlayerTextDrawColor(playerid, password_entry[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, password_entry[playerid], 255);
PlayerTextDrawBoxColor(playerid, password_entry[playerid], -206);
PlayerTextDrawUseBox(playerid, password_entry[playerid], 1);
PlayerTextDrawSetProportional(playerid, password_entry[playerid], 1);
PlayerTextDrawSetSelectable(playerid, password_entry[playerid], 1);

Gender_txt[playerid] = CreatePlayerTextDraw(playerid, 215.000000, 236.000000, "Genero:");
PlayerTextDrawFont(playerid, Gender_txt[playerid], 1);
PlayerTextDrawLetterSize(playerid, Gender_txt[playerid], 0.404166, 1.899999);
PlayerTextDrawTextSize(playerid, Gender_txt[playerid], 272.000000, 17.000000);
PlayerTextDrawSetOutline(playerid, Gender_txt[playerid], 1);
PlayerTextDrawSetShadow(playerid, Gender_txt[playerid], 0);
PlayerTextDrawAlignment(playerid, Gender_txt[playerid], 1);
PlayerTextDrawColor(playerid, Gender_txt[playerid], -1);
PlayerTextDrawBackgroundColor(playerid, Gender_txt[playerid], 255);
PlayerTextDrawBoxColor(playerid, Gender_txt[playerid], 50);
PlayerTextDrawUseBox(playerid, Gender_txt[playerid], 0);
PlayerTextDrawSetProportional(playerid, Gender_txt[playerid], 1);
PlayerTextDrawSetSelectable(playerid, Gender_txt[playerid], 0);

Man[playerid] = CreatePlayerTextDraw(playerid, 289.000000, 239.000000, "Hombre");
PlayerTextDrawFont(playerid, Man[playerid], 1);
PlayerTextDrawLetterSize(playerid, Man[playerid], 0.379166, 1.600000);
PlayerTextDrawTextSize(playerid, Man[playerid], 341.500000, 17.000000);
PlayerTextDrawSetOutline(playerid, Man[playerid], 1);
PlayerTextDrawSetShadow(playerid, Man[playerid], 0);
PlayerTextDrawAlignment(playerid, Man[playerid], 1);
PlayerTextDrawColor(playerid, Man[playerid], 65535);
PlayerTextDrawBackgroundColor(playerid, Man[playerid], 255);
PlayerTextDrawBoxColor(playerid, Man[playerid], 195);
PlayerTextDrawUseBox(playerid, Man[playerid], 1);
PlayerTextDrawSetProportional(playerid, Man[playerid], 1);
PlayerTextDrawSetSelectable(playerid, Man[playerid], 1);

Woman[playerid] = CreatePlayerTextDraw(playerid, 355.000000, 239.000000, "Mujer");
PlayerTextDrawFont(playerid, Woman[playerid], 1);
PlayerTextDrawLetterSize(playerid, Woman[playerid], 0.525000, 1.550000);
PlayerTextDrawTextSize(playerid, Woman[playerid], 405.000000, 17.000000);
PlayerTextDrawSetOutline(playerid, Woman[playerid], 1);
PlayerTextDrawSetShadow(playerid, Woman[playerid], 0);
PlayerTextDrawAlignment(playerid, Woman[playerid], 1);
PlayerTextDrawColor(playerid, Woman[playerid], -16711681);
PlayerTextDrawBackgroundColor(playerid, Woman[playerid], 255);
PlayerTextDrawBoxColor(playerid, Woman[playerid], 194);
PlayerTextDrawUseBox(playerid, Woman[playerid], 1);
PlayerTextDrawSetProportional(playerid, Woman[playerid], 1);
PlayerTextDrawSetSelectable(playerid, Woman[playerid], 1);
return 1;
}
forward SaveAccount(playerid);
public SaveAccount(playerid)
{
	new query[520];
	GetPlayerHealth(playerid, PlayerInfo[playerid][pVida]);
	GetPlayerArmour(playerid, PlayerInfo[playerid][pChaleco]);
    GetPlayerPos(playerid, PlayerInfo[playerid][pX], PlayerInfo[playerid][pY], PlayerInfo[playerid][pZ]);
    mysql_format(MySQL, query, sizeof(query), "UPDATE `usuarios` SET `Skin`='%i', `Dinero`='%i', `X`='%f',`Y`='%f',`Z`='%f',`Admin`='%i', `Vida`='%f', `Chaleco`='%f', `Interior`='%f' WHERE `Nombre`='%s'",
    PlayerInfo[playerid][pSkin] = GetPlayerSkin(playerid),
    PlayerInfo[playerid][pDinero] = GetPlayerMoney(playerid),
    PlayerInfo[playerid][pX],
    PlayerInfo[playerid][pY],
    PlayerInfo[playerid][pZ],
    PlayerInfo[playerid][pAdmin],
    PlayerInfo[playerid][pVida],
    PlayerInfo[playerid][pChaleco],
    PlayerInfo[playerid][pInt] = GetPlayerInterior(playerid),
    NombreJugador(playerid));
    mysql_query(MySQL, query);
	return 1;
}
forward Revisar(playerid);
public Revisar(playerid)
{
	new query[520], name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, sizeof(name));
    format(query, sizeof(query), "SELECT * FROM `usuarios` WHERE `Nombre`='%s'", name);
    mysql_tquery(MySQL, query, "VerificarUsuario", "d", playerid);
	return 1;
}
forward VerificarUsuario(playerid);
public VerificarUsuario(playerid)
{
    new rows;
    cache_get_row_count(rows);
    if(rows)
    {
    	cache_get_value_name(0, "Contra", PlayerInfo[playerid][pContra], 30);
    	ShowLoginTD(playerid);
    }
    else
    {
    	Mensaje(playerid,-1,"Tu cuenta no esta registrada...");
		ShowRegisterTD(playerid);
    }
    return 1;
}

forward IngresoJugador(playerid);
public IngresoJugador(playerid)
{
    cache_get_value_name_int(0, "ID", PlayerInfo[playerid][pID]);
    cache_get_value_name_int(0, "Correo", PlayerInfo[playerid][pGmail]);
    cache_get_value_name_int(0, "Genero", PlayerInfo[playerid][pGenero]);
    cache_get_value_name_int(0, "Edad", PlayerInfo[playerid][pEdad]);
    cache_get_value_name_int(0, "Skin", PlayerInfo[playerid][pSkin]);
    cache_get_value_name_int(0, "Dinero", PlayerInfo[playerid][pDinero]);
    cache_get_value_name_float(0, "X", PlayerInfo[playerid][pX]);
    cache_get_value_name_float(0, "Y", PlayerInfo[playerid][pY]);
    cache_get_value_name_float(0, "Z", PlayerInfo[playerid][pZ]);
    cache_get_value_name_int(0, "Admin", PlayerInfo[playerid][pAdmin]);
    cache_get_value_name_float(0, "Vida", PlayerInfo[playerid][pVida]);
    cache_get_value_name_float(0, "Chaleco", PlayerInfo[playerid][pChaleco]);
    cache_get_value_name_int(0, "Interior", PlayerInfo[playerid][pInt]);
    IngresarJugador(playerid);
    return 1;
}
forward IngresarJugador(playerid);
public IngresarJugador(playerid)
{
	HideLoginTD(playerid);
    SetSpawnInfo(playerid, 0, PlayerInfo[playerid][pSkin], PlayerInfo[playerid][pX], PlayerInfo[playerid][pY], PlayerInfo[playerid][pZ], 0.0, 0, 0, 0, 0, 0, 0);
    SpawnPlayer(playerid);
    GivePlayerMoney(playerid,PlayerInfo[playerid][pDinero]);
    SetPlayerSkin(playerid,PlayerInfo[playerid][pSkin]);
    SetPlayerHealth(playerid, PlayerInfo[playerid][pVida]);
    SetPlayerArmour(playerid, PlayerInfo[playerid][pChaleco]);
    SetPlayerInterior(playerid, PlayerInfo[playerid][pInt]);
	return 1;
}
main()
{
	print("\n----------------------------------");
	print(" GM Cargada");
	print("----------------------------------\n");
}
public OnGameModeInit()
{
	Connect_db();
	SetGameModeText("GM test");
	return 1;
}

public OnGameModeExit()
{
	return 1;
}

public OnPlayerConnect(playerid)
{
	LoadPlayerTextdraws(playerid);
	Revisar(playerid);
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	if(PlayerInfo[playerid][SeLogueo] != false)
	{
		SaveAccount(playerid);
	}
	return 1;
}

public OnPlayerSpawn(playerid)
{
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	return 1;
}

public OnVehicleSpawn(vehicleid)
{
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}

public OnPlayerText(playerid, text[])
{
	return 1;
}


public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveCheckpoint(playerid)
{
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveRaceCheckpoint(playerid)
{
	return 1;
}

public OnRconCommand(cmd[])
{
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	if(PlayerInfo[playerid][SeLogueo] != true)
	{
		Kick(playerid);
	}
	return 1;
}

public OnObjectMoved(objectid)
{
	return 1;
}

public OnPlayerObjectMoved(playerid, objectid)
{
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
	return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
	return 1;
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	return 1;
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	return 1;
}

public OnPlayerSelectedMenuRow(playerid, row)
{
	return 1;
}

public OnPlayerExitedMenu(playerid)
{
	return 1;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	return 1;
}
public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	return 1;
}
forward Registrar_DB(playerid);
public Registrar_DB(playerid)
{
	HideRegisterTD(playerid);
	new query[520];
	mysql_format(MySQL, query, sizeof(query),"INSERT INTO `usuarios`(`Nombre`, `Contra`, `Correo`, `Genero`, `Edad`, `Skin`, `Dinero`, `X`, `Y`, `Z`, `Vida`, `Chaleco`) VALUES ('%s','%s','%s','%i','%i','%i','1500','2918.61','-1495.36','14.9159','100','0')", 
	NombreJugador(playerid),
	PlayerInfo[playerid][pContra],
	PlayerInfo[playerid][pGmail],
	PlayerInfo[playerid][pGenero],
	PlayerInfo[playerid][pEdad],
	PlayerInfo[playerid][pSkin],
	PlayerInfo[playerid][pDinero],
	PlayerInfo[playerid][pX],
	PlayerInfo[playerid][pY],
	PlayerInfo[playerid][pZ],
	PlayerInfo[playerid][pVida],
	PlayerInfo[playerid][pChaleco]);
	mysql_query(MySQL, query);
	// 
	SpawnPlayer(playerid);
	GameTextForPlayer(playerid, "Registrado correctamente", 5000, 6);
	PlayerInfo[playerid][SeLogueo] = true;
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_VERIFY_PASSWORD:
		{
			if(response)
			{
				format(password_ve,sizeof(password_ve),"%s",inputtext);
				PlayerTextDrawSetString(playerid, pass_verify[playerid], "......");
			}
			else return Kick(playerid);
		}
		case DIALOG_PASSWORD:
		{
			if(response)
			{
					Password_[playerid] = true;
					format(PlayerInfo[playerid][pContra],30,"%s",inputtext);
					PlayerTextDrawSetString(playerid, password_entry[playerid], "..........");
			}
		}
		case DIALOG_GMAIL:
		{
			if(response)
			{
				Correo_ll[playerid] = true;
				format(PlayerInfo[playerid][pGmail],40,"%s",inputtext);
				PlayerTextDrawSetString(playerid, gmail_[playerid], PlayerInfo[playerid][pGmail]);
			}
		}
	}
	return 1;
}

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	return 1;
}
public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
	if(PlayerInfo[playerid][pAdmin] != 0)
	{
		SetPlayerPos(playerid, fX, fY, fZ);
	}
	return 1;
}
public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	if(_:playertextid != INVALID_TEXT_DRAW)
	{
		if(playertextid == gmail_[playerid])
		{
			ShowPlayerDialog(playerid, DIALOG_GMAIL, DIALOG_STYLE_INPUT, "Registro | Correo Electronico", "Ingresa tu correo electronico:\n", "Aceptar", "Cerrar");
		}
		else if(playertextid == more_age[playerid])
		{
			if(PlayerInfo[playerid][pEdad] > 99)
			{
				return Notify(playerid, "No puedes ser \n mayor de 99");
			}
			else
			{
				PlayerInfo[playerid][pEdad] ++;
				new string[5];
				format(string,sizeof(string),"%d",PlayerInfo[playerid][pEdad]);
				PlayerTextDrawSetString(playerid, result_age[playerid], string);
			}
		}
		else if(playertextid == pass_verify[playerid])
		{
			ShowPlayerDialog(playerid, DIALOG_VERIFY_PASSWORD, DIALOG_STYLE_PASSWORD, "Login | Password", "Ingrese su contraseña:", "Aceptar", "Cancelar");
		}
		else if(playertextid == Loguear[playerid])
		{
			if(!strcmp(password_ve[playerid],PlayerInfo[playerid][pContra],true))
			{
				new query[656];
				mysql_format(MySQL,query,sizeof(query),"SELECT * FROM `usuarios` WHERE `Nombre`='%s'", NombreJugador(playerid));
				mysql_pquery(MySQL, query, "IngresoJugador","d", playerid);
			}
			else
			{
				ShowLoginTD(playerid);
				Notify(playerid, "Hubo un Error:\n Contraseña incorrecta.");
			}
		}
		else if(playertextid == cerrar_[playerid])
		{
			HideLoginTD(playerid);
			Kick(playerid);
		}
		else if(playertextid == menosage_[playerid])
		{
			if(PlayerInfo[playerid][pEdad] <= 18)
			{
				return Notify(playerid, "No puedes ser menor \n de edad (18)");
			}
			else
			{
				PlayerInfo[playerid][pEdad] --;
				new string[5];
				format(string,sizeof(string),"%d",PlayerInfo[playerid][pEdad]);
				PlayerTextDrawSetString(playerid, result_age[playerid], string);
			}
		}
		else if(playertextid == Man[playerid])
		{
			PlayerTextDrawBoxColor(playerid, Man[playerid], 0x966400FF);
			Notify(playerid, "Genero: Hombre");
			PlayerInfo[playerid][pGenero] = 1;
			Selec_Gen[playerid] = true;
		}
		else if(playertextid == Woman[playerid])
		{
			PlayerTextDrawBoxColor(playerid, Woman[playerid], 0x966400FF);
			Notify(playerid, "Genero: Mujer");
			PlayerInfo[playerid][pGenero] = 2;
			Selec_Gen[playerid] = true;
		}
		else if(playertextid == confirm[playerid])
		{
			Chequeo(playerid);
		}
		else if(playertextid == close_[playerid])
		{
			HideRegisterTD(playerid);
			Kick(playerid);
		}
		else if(playertextid == password_entry[playerid])
		{
			ShowPlayerDialog(playerid, DIALOG_PASSWORD, DIALOG_STYLE_PASSWORD, "Registro | Password", "Ingrese su contraseña:\n", "Aceptar", "Cancelar");
		}
	}
	return 1;
}
stock Chequeo(playerid)
{
	if(Password_[playerid] != true)
	{
		new error[64];
		format(error,64,"Ingresa un password.");
		return Notify(playerid, error);
	}
	if(Selec_Gen[playerid] != true)
	{
		new error[64];
		format(error,64,"Selecciona un genero");
		return Notify(playerid, error);
	}
	if(Correo_ll[playerid] != true)
	{
		new error[64];
		format(error,64,"Ingresa un correo electronico");
		return Notify(playerid, error);
	}
	if(strfindex(PlayerInfo[playerid][pGmail], '@') == 0)
	{
		new error[64];
		format(error,64,"Correo electronico invalido");
		return Notify(playerid, error);
	}
	if(strfindex(PlayerInfo[playerid][pContra], '%') == 1)
	{
		new error[64];
		format(error,64,"Contraseña invalida.");
		return Notify(playerid, error);
	}
	else
	{
		PlayerInfo[playerid][pSkin] = 250;
		SetSpawnInfo(playerid, 0, PlayerInfo[playerid][pSkin], 1296.033935,-1866.021850,13.549837, 0.0, 0, 0, 0, 0, 0, 0);			
		SpawnPlayer(playerid);
		Registrar_DB(playerid);
	}
	return true;
}

stock Notify(playerid, string[])
{
	PlayerTextDrawSetString(playerid, Text[playerid], string);
	PlayerTextDrawShow(playerid, Text[playerid]);
	PlayerTextDrawShow(playerid, Background_Box[playerid]);
	TimerNotify[playerid] = SetTimerEx("QuitNotify", 5000, false, "i", playerid);
	return 1;
}

forward QuitNotify(playerid);
public QuitNotify(playerid)
{
	PlayerTextDrawHide(playerid, Text[playerid]);
	PlayerTextDrawHide(playerid, Background_Box[playerid]);
	return 1;
}