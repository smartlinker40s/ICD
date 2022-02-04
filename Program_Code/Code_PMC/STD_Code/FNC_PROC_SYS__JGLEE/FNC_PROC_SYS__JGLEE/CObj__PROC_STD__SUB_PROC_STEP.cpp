#include "StdAfx.h"
#include "CObj__PROC_STD.h"


// ...
int CObj__PROC_STD
::Sub__PROC_CTRL(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	CString obj_msg;

	obj_msg = "Process Control - Start ...";
	sCH__OBJ_MSG->Set__DATA(obj_msg);

	// ...
	CString ch_data;

	// Loop Parameter ...
	{
		bACTIVE__LOOP_STEP = false;

		iLOOP__STEP_START = 0;
		iLOOP__STEP_END   = 0;

		iLOOP__STEP_REPEAT = 0;
		iLOOP__STEP_COUNT  = 0;
	}

	// Process.Timer ...
	SCX__ASYNC_TIMER_CTRL x_timer__proc;

	x_timer__proc->REGISTER__COUNT_CHANNEL_NAME(sCH__PRC_CUR_TIME->Get__CHANNEL_NAME());
	x_timer__proc->START__COUNT_UP(99999);

	// Step.Timer ...
	SCX__ASYNC_TIMER_CTRL x_timer__step;

	x_timer__step->REGISTER__COUNT_CHANNEL_NAME(sCH__STEP_CUR_TIME->Get__CHANNEL_NAME());
	x_timer__step->STOP_ZERO();

	// ...
	bool active__start_step = true;

	int rcp__step_max = xRCP__FILE_CTRL->Get__TOTAL_STEP_SIZE();
	int cur__step_id  = 1;

	while(1)
	{
		int r_flag = xRCP__FILE_CTRL->Read__MEM();
		if(r_flag < 0)			return 1;

		aCH__STEP_CUR_NUM->Set__VALUE(cur__step_id);
		sEXT_CH__MON_STEP_EXCEPTION_ACT->Set__DATA("");

		if(active__start_step)
		{
			active__start_step = false;

			Fnc__PRC_LOG__ENABLE(p_variable);

			sEXT_CH__PMC_PROCESS_STATUS->Set__DATA(STR__Processing);
		}

		// Step.Start ...
		{
			x_timer__step->START__COUNT_UP(99999);

			int r_step = Sub__STEP_CTRL(p_variable,p_alarm, cur__step_id,rcp__step_max);

			// Process Recovery Check ...
			if(r_step <  0)		
			{
				if(Check__ALARM_RECOVERY(p_variable, p_alarm) < 0)				return r_step;
			}
			
			// Check : Exception.Act ...
			while(1)
			{
				CString cur__act_cmd = dCH__MON_EXCEPTION_ACT->Get__STRING();
			
				if(cur__act_cmd.CompareNoCase(_ACT_CMD__START) == 0)			break;

				if(cur__act_cmd.CompareNoCase(_ACT_CMD__SKIP)  == 0)
				{
					dCH__MON_EXCEPTION_ACT->Set__DATA(_ACT_CMD__START);
					break;
				}

				if(p_variable->Check__CTRL_ABORT() > 0)							return -1;
				if(cur__act_cmd.CompareNoCase(_ACT_CMD__ABORT) == 0)			return -2;

				if(cur__act_cmd.CompareNoCase(_ACT_CMD__END)   == 0)			return 11;

				Sleep(10);
			}

			// Manual Next.Ctrl ...
			if(dCH__CUR_PROCESS_TYPE->Check__DATA(STR__MANUAL) > 0)
			{
				if(dCH__PARA_MANUAL_STEP_CTRL_ACTIVE->Check__DATA(STR__ON) > 0)
				{
					sCH__PARA_MANUAL_STEP_CTRL_REQ->Set__DATA(STR__READY);

					while(1)
					{
						Sleep(10);

						if(p_variable->Check__CTRL_ABORT() > 0)					return -1;

						// ...
						CString cur__step_ctrl = sCH__PARA_MANUAL_STEP_CTRL_REQ->Get__STRING();

						if(cur__step_ctrl.CompareNoCase(STR__NEXT_STEP) == 0)		
						{
							break;
						}
						if(cur__step_ctrl.CompareNoCase(STR__CUR_STEP) == 0)		
						{
							break;
						}
						if(cur__step_ctrl.CompareNoCase(STR__PRE_STEP) == 0)		
						{
							break;
						}
					}

					// ...
				}
			}
		}

		Check__STEP_LOOP(cur__step_id);

		cur__step_id = (int) aCH__STEP_CUR_NUM->Get__VALUE();
		cur__step_id++;
	}

	return 1;
}

int CObj__PROC_STD
::Sub__STEP_CTRL(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int cur__step_id,const int rcp__step_max)
{
	printf(" * Sub__STEP_CTRL() ... \n");
	printf("  ** cur__step_id <- [%1d] \n", cur__step_id);
	printf("  ** cur__step_id <- [%1d] \n", rcp__step_max);

	Fnc__PRC_LOG__STEP_START();

	if(pOBJ_CTRL__STEP->Call__OBJECT(_STEP_CMD__PROC) < 0)		
	{
		if(p_variable->Check__CTRL_ABORT() > 0)			Fnc__PRC_LOG__STEP_ABORT();

		return -1;
	}

	if(cur__step_id < rcp__step_max)			Fnc__PRC_LOG__STEP_END_START();
	else										Fnc__PRC_LOG__STEP_END();

	return 1;
}

int CObj__PROC_STD
::Check__ALARM_RECOVERY(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	if(p_variable->Check__CTRL_ABORT() > 0)
	{
		return -1;
	}

	if(dCH__MON_EXCEPTION_ACT->Check__DATA(_ACT_CMD__START) < 0)
	{
		return -2;
	}
	dCH__MON_EXCEPTION_ACT->Set__DATA(_ACT_CMD__ALARM);

	// CHM.PUMP ...
	{
		pOBJ_CTRL__CHM->Run__OBJECT(_CHM_CMD__HIGH_VAC_PUMP);
	}

	// LOG.PAUSE ...
	{
		Fnc__PRC_LOG__PAUSE(p_variable);
		// xTIMER_ASYNC->PAUSE();
	}

	int r_flag = _Check__ALARM_RECOVERY(p_variable, p_alarm);

	// LOG.RESUME ...
	if(r_flag > 0)
	{
		Fnc__PRC_LOG__RESUME(p_variable);
		// xTIMER_ASYNC->RESUME();
	}

	return r_flag;
}
int CObj__PROC_STD
::_Check__ALARM_RECOVERY(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	// Step.Abort ...
	{
		pOBJ_CTRL__STEP->Dislink__UPPER_OBJECT();

		pOBJ_CTRL__STEP->Call__OBJECT(_STEP_CMD__ABORT);

		pOBJ_CTRL__STEP->Link__UPPER_OBJECT();
	}

	// ...
	{
		int alarm_id = ALID__PROCESS_RECOVERY_CHECK;
		CString r_act;

		p_alarm->Post__ALARM_WITH_BLOCKING(alarm_id,r_act);

		//
		if(r_act.CompareNoCase(ACT__ABORT) == 0)
		{
			dCH__MON_EXCEPTION_ACT->Set__DATA(_ACT_CMD__ABORT);
			return -1;
		}

		if(r_act.CompareNoCase(ACT__RESTART) == 0)
		{
			dCH__MON_EXCEPTION_ACT->Set__DATA(_ACT_CMD__START);
			return 1;
		}		
		if(r_act.CompareNoCase(ACT__JUMP) == 0)
		{
			sCH__WIN_CTRL_MSG->Set__DATA("Input Step Number or Time.");

			dCH__WIN_CTRL_LOCK_ACTIVE_JUMP->Set__DATA(STR__OFF);
			dCH__WIN_CTRL_LOCK_ACTIVE_CONTINUE->Set__DATA(STR__OFF);
			dCH__WIN_CTRL_LOCK_ACTIVE_ABORT->Set__DATA(STR__OFF);

			int r_flag = Check__STEP_JUMP(p_variable, p_alarm);

			dCH__WIN_CTRL_LOCK_ACTIVE_JUMP->Set__DATA(STR__ON);
			dCH__WIN_CTRL_LOCK_ACTIVE_CONTINUE->Set__DATA(STR__ON);
			dCH__WIN_CTRL_LOCK_ACTIVE_ABORT->Set__DATA(STR__ON);
			return r_flag;
		}
		
		if(r_act.CompareNoCase(ACT__END) == 0)
		{
			dCH__MON_EXCEPTION_ACT->Set__DATA(_ACT_CMD__END);
			return 1;
		}
		if(r_act.CompareNoCase(ACT__END_WITH_PLASMA_DECHUCK) == 0)
		{
			dCH__MON_EXCEPTION_ACT->Set__DATA(_ACT_CMD__END);
			return 1;
		}
	}

	return -11;
}