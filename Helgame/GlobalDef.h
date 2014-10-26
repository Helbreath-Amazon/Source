/****************************************************************
*		 This client was writen by Diuuude & Snoopy81.			*
*					Based on Cleroth work.						*
*																*
*			V3.51 compatibility by Cleroth						*
*			V3.51 dialogs by Diuuude							*
*			Effects, mobs, Apocalypse, Heldenian				*
*			& finalizing by Snoopy81							*
*			V3.82 Crafting & Angels by Snoopy81					*
*****************************************************************/

/****************************************************************
*	Find here all compilation options							*
*	I removed useless ones and tryed to add some explanations	*
*	( Snoopy81 06/2005 )										*
*****************************************************************/

/*** Put here global data for your server ***/
#define NAME_WORLDNAME			"WS1" // Name for default (1st) server
#define MSG_WORLDNAME1			"Helbreath Sunrise" // Long name for 1st server...
#define MSG_HOMEPAGE			"http://www.hbsunrise.net"
#define MSG_HOMEPAGE2			"http://www.hbsunrise.net"
#define DEF_HBCBA_VER			"4.0"
#define DEF_UPPERVERSION		3
#define DEF_LOWERVERSION		82
#define DEF_SERVER_IP                   "31.31.77.84"//"" 190.224.163.126
#define DEF_SERVER_PORT			2849
#define DEF_STATS_LIMIT                 200
#define DEF_MAKE_ACCOUNT
//#define DEF_USE_DNS
//#define DEF_SERVER_DNS                ""
#define DEF_USE_LOGIN			// Login.cfg option

#ifndef _DEBUG
	#undef DEF_WINDOWED_MODE
#endif