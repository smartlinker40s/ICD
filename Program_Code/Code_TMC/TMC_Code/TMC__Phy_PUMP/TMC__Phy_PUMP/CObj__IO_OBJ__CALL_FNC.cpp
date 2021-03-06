#include "StdAfx.h"
#include "CObj__IO_OBJ.h"
#include "CObj__IO_OBJ__DEF.h"
#include "CObj__IO_OBJ__ALID.h"


int  CObj__IO_OBJ
::Call__INIT(CII_OBJECT__VARIABLE* p_variable,
			 CII_OBJECT__ALARM* p_alarm)
{
LOOP_RETRY:

	// DI CHECK ...
{
	CII__VAR_DIGITAL_CTRL *p_ch;
	CString ch_sts;

	int active_err = -1;
	CString err_msg;
	CString err_bff;

	int i_limit = 10;
	int i;

	for(i=0; i<i_limit; i++)
	{
		if(i == 0)
		{
			p_ch = diEXT_CH__PUMP_STATE_RUNNING.Get__PTR();
			ch_sts = STR__ON;
		}
		else if(i == 1)
		{
			p_ch = diEXT_CH__PUMP_BLOWER_RUNNING.Get__PTR();
			ch_sts = STR__ON;
		}
		else if(i == 2)
		{
			p_ch = diEXT_CH__PUMP_WARNING_NORMAL.Get__PTR();
			ch_sts = STR__ON;
		}
		else if(i == 3)
		{
			p_ch = diEXT_CH__PUMP_ALARM_NORMAL.Get__PTR();
			ch_sts = STR__ON;
		}
		else if(i == 4)
		{
			p_ch = diEXT_CH__PUMP_OPERATION_READY.Get__PTR();
			ch_sts = STR__ON;
		}
		else if(i == 5)
		{
			p_ch = diEXT_CH__PUMP_ALARM_ERROR.Get__PTR();
			ch_sts = STR__OFF;
		}
		else
		{
			continue;
		}

		// ...
		{
			active_err = 1;

			err_bff.Format(" * %s <- %s \n", 
				p_ch->Get__CHANNEL_NAME(),
				p_ch->Get__STRING());
			err_msg += err_bff;
		}
	}

	if(active_err > 0)
	{
		int alm_id = ALID__INIT_ERROR;
		CString r_act;

		p_alarm->Popup__ALARM_With_MESSAGE(alm_id,err_msg,r_act);

		if(r_act.CompareNoCase(ACT__RETRY) == 0)		
			goto LOOP_RETRY;

		return -1;
	}
}

dCH__OBJ_STATUS->Set__DATA(STR__STANDBY);
return 1;
}
int  CObj__IO_OBJ
::Call__MAINT(CII_OBJECT__VARIABLE* p_variable,
			  CII_OBJECT__ALARM* p_alarm)
{
	dCH__OBJ_STATUS->Set__DATA(STR__MAINTMODE);
	return 1;
}

int  CObj__IO_OBJ
::Call__PUMP_ON(CII_OBJECT__VARIABLE* p_variable,
				CII_OBJECT__ALARM* p_alarm)
{
	if(_Check__INTERLOCK__PUMP_VLV(p_alarm) < 0)
	{
		return -1;
	}

	// PUMP : ON ...
	if(pOBJ_CTRL__PUMP->Call__OBJECT(_CMMD_PMP__ON) < 0)
	{
		return -1;
	}

	// ...
	{
		SCX__TIMER_CTRL x_timer;
		x_timer->REGISTER__ABORT_OBJECT(sObject_Name);
		x_timer->REGISTER__COUNT_CHANNEL(sCH__APP_DELAY_COUNT->Get__CHANNEL_NAME());

		double cfg_sec = aCH__CFG_ON_DELAY->Get__VALUE();
		if(x_timer->WAIT(cfg_sec) < 0)		return -11;
	}
	return 1;
}
int  CObj__IO_OBJ
::Call__PUMP_OFF(CII_OBJECT__VARIABLE* p_variable,
				 CII_OBJECT__ALARM* p_alarm)
{
	if(_Check__INTERLOCK__PUMP_VLV(p_alarm) < 0)
	{
		return -1;
	}

	// PUMP : OFF ...
	return pOBJ_CTRL__PUMP->Call__OBJECT(_CMMD_PMP__AUTO_SHUTDOWN);
}

int  CObj__IO_OBJ
::_Check__INTERLOCK__PUMP_VLV(CII_OBJECT__ALARM* p_alarm)
{
LOOP_RETRY:

	// ...
	int active_err = -1;

	CString err_msg = "";
	CString err_bff;

	if(bActive__VLV_LEFT)
	{
		if(diEXT_CH__PUMP_SLOW_VLV_LEFT->Check__DATA(STR__CLOSE) < 0)
		{
			active_err = 1;

			err_bff.Format(" * %s <- %s \n",
							diEXT_CH__PUMP_SLOW_VLV_LEFT->Get__CHANNEL_NAME(),
							diEXT_CH__PUMP_SLOW_VLV_LEFT->Get__STRING());
			err_msg += err_bff;
		}
		if(diEXT_CH__PUMP_FAST_VLV_LEFT->Check__DATA(STR__CLOSE) < 0)
		{
			active_err = 1;

			err_bff.Format(" * %s <- %s \n",
							diEXT_CH__PUMP_FAST_VLV_LEFT->Get__CHANNEL_NAME(),
							diEXT_CH__PUMP_FAST_VLV_LEFT->Get__STRING());
			err_msg += err_bff;
		}
	}
	if(bActive__VLV_RIGHT)
	{
		if(diEXT_CH__PUMP_SLOW_VLV_RIGHT->Check__DATA(STR__CLOSE) < 0)
		{
			active_err = 1;

			err_bff.Format(" * %s <- %s \n",
							diEXT_CH__PUMP_SLOW_VLV_RIGHT->Get__CHANNEL_NAME(),
							diEXT_CH__PUMP_SLOW_VLV_RIGHT->Get__STRING());
			err_msg += err_bff;
		}
		if(diEXT_CH__PUMP_FAST_VLV_RIGHT->Check__DATA(STR__CLOSE) < 0)
		{
			active_err = 1;

			err_bff.Format(" * %s <- %s \n",
							diEXT_CH__PUMP_FAST_VLV_RIGHT->Get__CHANNEL_NAME(),
							diEXT_CH__PUMP_FAST_VLV_RIGHT->Get__STRING());
			err_msg += err_bff;
		}
	}

	if(active_err < 0)
	{
		return 1;
	}

	// ...
	{
		int alm_id = ALID__PUMP_VLV_NOT_CLOSE;
		CString r_act;


		p_alarm->Popup__ALARM_With_MESSAGE(alm_id, err_msg, r_act);

		if(r_act.CompareNoCase(ACT__RETRY) == 0)
			goto LOOP_RETRY;
	}
	return -1;
}
