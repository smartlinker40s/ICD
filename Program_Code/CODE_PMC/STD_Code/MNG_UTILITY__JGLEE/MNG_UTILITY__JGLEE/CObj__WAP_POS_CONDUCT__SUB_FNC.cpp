#include "StdAfx.h"
#include "CObj__WAP_POS_CONDUCT.h"



// ...
#define  DEF__LOAD_POS_PRESS(pos_data,press_data)				\
l_ref_pos.Add(pos_data);										\
l_ref_press.Add(press_data);


int CObj__WAP_POS_CONDUCT::
_Fnc__REF_POS_PRESS_DATA(CStringArray& l_ref_pos,
						 CStringArray& l_ref_press)
{
	// ...
	{
		l_ref_pos.RemoveAll();
		l_ref_press.RemoveAll();
	}

	// Ref. Data ...
	{
		// 0 ~ 90
		DEF__LOAD_POS_PRESS( "0", "9.8");
		DEF__LOAD_POS_PRESS("10", "9.8");
		DEF__LOAD_POS_PRESS("20", "9.8");
		DEF__LOAD_POS_PRESS("30", "9.8");
		DEF__LOAD_POS_PRESS("40", "10.0");
		DEF__LOAD_POS_PRESS("50", "10.1");
		DEF__LOAD_POS_PRESS("60", "10.2");
		DEF__LOAD_POS_PRESS("70", "10.3");
		DEF__LOAD_POS_PRESS("80", "10.5");
		DEF__LOAD_POS_PRESS("90", "10.5");

		// 100 ~ 190 
		DEF__LOAD_POS_PRESS("100", "10.6");
		DEF__LOAD_POS_PRESS("110", "10.7");
		DEF__LOAD_POS_PRESS("120", "10.8");
		DEF__LOAD_POS_PRESS("130", "10.9");
		DEF__LOAD_POS_PRESS("140", "11.0");
		DEF__LOAD_POS_PRESS("150", "11.1");
		DEF__LOAD_POS_PRESS("160", "11.3");
		DEF__LOAD_POS_PRESS("170", "11.4");
		DEF__LOAD_POS_PRESS("180", "11.6");
		DEF__LOAD_POS_PRESS("190", "11.8"); 

		// 200 ~ 290
		DEF__LOAD_POS_PRESS("200", "12.0");
		DEF__LOAD_POS_PRESS("210", "12.1");
		DEF__LOAD_POS_PRESS("220", "12.3");
		DEF__LOAD_POS_PRESS("230", "12.5");
		DEF__LOAD_POS_PRESS("240", "12.7");
		DEF__LOAD_POS_PRESS("250", "13.0");
		DEF__LOAD_POS_PRESS("260", "13.3");
		DEF__LOAD_POS_PRESS("270", "13.6");
		DEF__LOAD_POS_PRESS("280", "13.8");
		DEF__LOAD_POS_PRESS("290", "14.0");

		// 300 ~ 390
		DEF__LOAD_POS_PRESS("300", "14.3");
		DEF__LOAD_POS_PRESS("310", "14.6");
		DEF__LOAD_POS_PRESS("320", "15.0");
		DEF__LOAD_POS_PRESS("330", "15.3");
		DEF__LOAD_POS_PRESS("340", "15.6");
		DEF__LOAD_POS_PRESS("350", "16.0");
		DEF__LOAD_POS_PRESS("360", "16.5");
		DEF__LOAD_POS_PRESS("370", "16.6");
		DEF__LOAD_POS_PRESS("380", "17.5"); 
		DEF__LOAD_POS_PRESS("390", "18.1");

		// 400 ~ 490
		DEF__LOAD_POS_PRESS("400", "18.7");
		DEF__LOAD_POS_PRESS("410", "19.3");
		DEF__LOAD_POS_PRESS("420", "19.9");
		DEF__LOAD_POS_PRESS("430", "20.6");
		DEF__LOAD_POS_PRESS("440", "21.3");
		DEF__LOAD_POS_PRESS("450", "22.2");
		DEF__LOAD_POS_PRESS("460", "23.0");
		DEF__LOAD_POS_PRESS("470", "23.8");
		DEF__LOAD_POS_PRESS("480", "24.7");
		DEF__LOAD_POS_PRESS("490", "25.5"); 

		// 500 ~ 590
		DEF__LOAD_POS_PRESS("500", "26.2");
		DEF__LOAD_POS_PRESS("510", "27.1");
		DEF__LOAD_POS_PRESS("520", "27.9");
		DEF__LOAD_POS_PRESS("530", "28.5");
		DEF__LOAD_POS_PRESS("540", "29.1");
		DEF__LOAD_POS_PRESS("550", "30.0");
		DEF__LOAD_POS_PRESS("560", "31.1");
		DEF__LOAD_POS_PRESS("570", "31.8");
		DEF__LOAD_POS_PRESS("580", "32.8");
		DEF__LOAD_POS_PRESS("590", "33.6");

		// 600 ~ 690
		DEF__LOAD_POS_PRESS("600", "34.3");
		DEF__LOAD_POS_PRESS("610", "35.0");
		DEF__LOAD_POS_PRESS("620", "35.7");
		DEF__LOAD_POS_PRESS("630", "36.4");
		DEF__LOAD_POS_PRESS("640", "37.3");
		DEF__LOAD_POS_PRESS("650", "38.7");
		DEF__LOAD_POS_PRESS("660", "40.8");
		DEF__LOAD_POS_PRESS("670", "42.6");
		DEF__LOAD_POS_PRESS("680", "44.1");
		DEF__LOAD_POS_PRESS("690", "45.7");

		// 700 ~ 790
		DEF__LOAD_POS_PRESS("700", "47.1");
		DEF__LOAD_POS_PRESS("710", "48.4");
		DEF__LOAD_POS_PRESS("720", "50.1");
		DEF__LOAD_POS_PRESS("730", "52.2");
		DEF__LOAD_POS_PRESS("740", "54.9");
		DEF__LOAD_POS_PRESS("750", "57.1");
		DEF__LOAD_POS_PRESS("760", "59.3");
		DEF__LOAD_POS_PRESS("770", "62.0");
		DEF__LOAD_POS_PRESS("780", "64.4");
		DEF__LOAD_POS_PRESS("790", "68.5");

		// 800 ~ 890
		DEF__LOAD_POS_PRESS("800", "73.8");
		DEF__LOAD_POS_PRESS("805", "79.4");
		DEF__LOAD_POS_PRESS("810", "80.7");
		DEF__LOAD_POS_PRESS("815", "84.7");
		DEF__LOAD_POS_PRESS("820", "88.7");
		DEF__LOAD_POS_PRESS("825", "93.6");
		DEF__LOAD_POS_PRESS("830", "98.7");
		DEF__LOAD_POS_PRESS("835", "106.0");
		DEF__LOAD_POS_PRESS("840", "111.7");
		DEF__LOAD_POS_PRESS("845", "118.5");
		DEF__LOAD_POS_PRESS("850", "124.8");
		DEF__LOAD_POS_PRESS("855", "131.5");
		DEF__LOAD_POS_PRESS("860", "132.8");
		DEF__LOAD_POS_PRESS("870", "132.8");
		DEF__LOAD_POS_PRESS("880", "132.8");
		DEF__LOAD_POS_PRESS("890", "132.8");

		// 900 ~ 990
		DEF__LOAD_POS_PRESS("900", "132.8");
		DEF__LOAD_POS_PRESS("910", "132.8");
		DEF__LOAD_POS_PRESS("920", "132.8");
		DEF__LOAD_POS_PRESS("930", "132.8");
		DEF__LOAD_POS_PRESS("940", "132.8");
		DEF__LOAD_POS_PRESS("950", "132.8");
		DEF__LOAD_POS_PRESS("960", "132.8");
		DEF__LOAD_POS_PRESS("970", "132.8");
		DEF__LOAD_POS_PRESS("980", "132.8");
		DEF__LOAD_POS_PRESS("990", "132.8");

		// 1000
		DEF__LOAD_POS_PRESS("1000", "132.8");
	}

	return 1;
}