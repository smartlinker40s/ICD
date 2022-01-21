#include "stdafx.h"

#include "CObj__DURAPORT_SERIAL.h"
#include "CObj__DURAPORT_SERIAL__DEF.h"


// ...
int	CObj__DURAPORT_SERIAL
::Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	CString fnc_name = "Call__INIT()";

	if(Fnc__INIT(p_variable, p_alarm, fnc_name) < 0)
	{
		return -11;
	}
	if(Fnc__HOME(p_variable, p_alarm, fnc_name) < 0)
	{
		return -12;
	}

	xAPP__LOG_CTRL->WRITE__LOG("Initialized");
	return 1;
}

int	CObj__DURAPORT_SERIAL
::Call__HOME(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	CString fnc_name = "Call__HOME()";

	int state = Fnc__HOME(p_variable, p_alarm, fnc_name);

	if(state > 0)
	{
		if(dCH__LP_STATE->Check__DATA(STR_INITIALIZED) > 0)
		{
			xAPP__LOG_CTRL->WRITE__LOG("Homed");
			return OBJ_AVAILABLE;
		}
	}
	return state;
}

int	CObj__DURAPORT_SERIAL
:: Call__OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	CString fnc_name = "Call__OPEN()";

	if(sCH__MON_DOOR_STATUS->Check__DATA(STR__OPEN) > 0)
	{
		xAPP__LOG_CTRL->WRITE__LOG("Door opened");
		
		dCH__LP_STATE->Set__DATA(STR_OPENED);
		return OBJ_AVAILABLE;
	}

	sLastCommand = "OPEN";

	// ...
	int state = Fnc__OPEN(p_variable, p_alarm, fnc_name);

	if(state > 0)
	{
		if(dCH__LP_STATE->Check__DATA(STR_OPENED) > 0)
		{
			xAPP__LOG_CTRL->WRITE__LOG("Door opened");
			return OBJ_AVAILABLE;
		}
	}
	return state;
}

int	CObj__DURAPORT_SERIAL
::Call__CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	sLastCommand = "CLOSE";

	// ...
	CString fnc_name = "Call__CLOSE()";
	
	int state = Fnc__CLOSE(p_variable, p_alarm, fnc_name);

	if(state > 0)
	{
		if(dCH__LP_STATE->Check__DATA(STR_CLOSED) > 0)
		{
			xAPP__LOG_CTRL->WRITE__LOG("Door closed");
			return OBJ_AVAILABLE;
		}
	}
	return state;
}

int	CObj__DURAPORT_SERIAL
::Call__LOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	sLastCommand = "LOAD";

	// ...
	CString fnc_name = "Call__LOAD()";

	int state = Fnc__LOAD(p_variable, p_alarm, fnc_name);

	if(state > 0)
	{
		if(dCH__LP_STATE->Check__DATA(STR_LOADED) > 0)
		{
			xAPP__LOG_CTRL->WRITE__LOG("Loaded");
			return OBJ_AVAILABLE;
		}
	}
	return state;
}

int	CObj__DURAPORT_SERIAL
::Call__UNLOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	sLastCommand = "UNLOAD";

	// ...
	CString fnc_name = "Call__UNLOAD()";
	
	int state = Fnc__UNLOAD(p_variable, p_alarm, fnc_name);

	if(state > 0)
	{
		if(dCH__LP_STATE->Check__DATA(STR_UNLOADED) > 0)
		{
			xAPP__LOG_CTRL->WRITE__LOG("Unloaded");
			return OBJ_AVAILABLE;
		}
	}
	return state;
}

int	CObj__DURAPORT_SERIAL
::Call__DOCK(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	sLastCommand = "DOCK";

	// ...
	CString fnc_name = "Call__DOCK()";
	
	int state = Fnc__DOCK(p_variable, p_alarm, fnc_name);

	if(state > 0)
	{
		if(dCH__LP_STATE->Check__DATA(STR_DOCKED) > 0)
		{
			xAPP__LOG_CTRL->WRITE__LOG("Docked");
			return OBJ_AVAILABLE;
		}
	}
	return state;
}

int	CObj__DURAPORT_SERIAL::
Call__UNDOCK(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	sLastCommand = "UNDOCK";

	// ...
	CString fnc_name = "Call__UNDOCK()";
	
	int state = Fnc__UNDOCK(p_variable, p_alarm, fnc_name);

	if(state > 0)
	{
		if(dCH__LP_STATE->Check__DATA(STR_UNDOCKED) > 0)
		{
			xAPP__LOG_CTRL->WRITE__LOG("Undocked");
			return OBJ_AVAILABLE;
		}
	}
	return state;
}

int	CObj__DURAPORT_SERIAL
::Call__CLAMP(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	sLastCommand = "CLAMP";

	// ...
	CString fnc_name = "Call__CLAMP()";
	
	int state = Fnc__CLAMP(p_variable, p_alarm, fnc_name);

	if(state > 0)
	{
		if(dCH__LP_STATE->Check__DATA(STR_CLAMPED) > 0)
		{
			xAPP__LOG_CTRL->WRITE__LOG("Clamped");
			return OBJ_AVAILABLE;
		}
	}
	return state;
}

int	CObj__DURAPORT_SERIAL
::Call__UNCLAMP(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	sLastCommand = "UNCLAMP";

	// ...
	CString fnc_name = "Call__UNCLAMP()";
	
	int state = Fnc__UNCLAMP(p_variable, p_alarm, fnc_name);

	if(state > 0)
	{
		if(dCH__LP_STATE->Check__DATA(STR_UNCLAMPED) > 0)
		{
			xAPP__LOG_CTRL->WRITE__LOG("Unclamped");
			return OBJ_AVAILABLE;
		}
	}
	return state;
}

int	CObj__DURAPORT_SERIAL
::Call__MAP(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	// m_bRunning = TRUE;
	sLastCommand = "MAPPING";

	int state = Fnc__MAP(p_variable, p_alarm);

	// m_bRunning = FALSE;
	return state;
}
int	CObj__DURAPORT_SERIAL
::Fnc__MAP(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	_Update__LPx_INIT();

	return doCH__OPR_MAIN_SET->Set__DATA("SCAN");
}
