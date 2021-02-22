/*******************************************************************/
//this app is write at 20170603, it is the first time coding at the plate of rh850 
/*******************************************************************/
#include "APP.h"
#include "APP_Cfg.h"
/***********INNER HAND FILE ***************/
#include "General.h"
#include "dr7f701035_0.h"

/***********OUTER HAND FILE ***************/

static uint8  TT_stau=0 ;

uint TT_Ctrl=0;

#define main_loop    main

(void) main_loop(void)

{
uint8 TT_Ctrl=0;
Bool press=0;



	while(1)


	{
		if(press==1)
	  	  {
	  		TT_Ctrl=1;
	  	  }
		   else
			{
			   TT_Ctrl=0;
			}


	}





}

