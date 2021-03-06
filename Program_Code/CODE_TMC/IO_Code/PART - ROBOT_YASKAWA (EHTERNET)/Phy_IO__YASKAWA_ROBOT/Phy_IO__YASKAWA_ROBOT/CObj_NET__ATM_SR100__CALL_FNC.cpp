#include "StdAfx.h"
#include "CObj_NET__ATM_SR100.h"
#include "CObj_NET__ATM_SR100__DEF.h"
#include "CObj_NET__ATM_SR100__ALID.h"

#include "Macro_Function.h"


//-------------------------------------------------------------------------	
int  CObj_NET__ATM_SR100
::Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	if(iSim_Flag > 0)
	{
		return Fnc__SIM_INIT(p_variable,p_alarm);
	}

	return Fnc__INIT(p_variable,p_alarm);;
}
int  CObj_NET__ATM_SR100
::Fnc__SIM_INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	Sleep(1500);

	return 1;
}
int  CObj_NET__ATM_SR100
::Fnc__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	int r_flag = doCH__COMMAND->Set__DATA(_CMMD__RBInit);

	if(r_flag > 0)
	{
		doCH__COMMAND->Set__DATA(_CMMD__RBErrClr);
	}

	if(r_flag > 0)
	{
		CString ch_data = diCH__RB_STS_MANUAL->Get__STRING();
		if(ch_data.CompareNoCase(STR__Error) == 0)			return r_flag;
	}

	// Wafer Check ...
	if(r_flag > 0)
	{
		// Arm_A ...
		{
			if(sCH__MON_SYS_STS__WAFER_PRESENCE_STS1->Check__DATA(STR__ON) > 0)
			{
				dCH__MON__ARM_A_MATERIAL_STATUS->Set__DATA(STR__EXIST);
			}
			else if(sCH__MON_SYS_STS__WAFER_PRESENCE_STS1->Check__DATA(STR__OFF) > 0)
			{
				dCH__MON__ARM_A_MATERIAL_STATUS->Set__DATA(STR__NONE);
			}
		}

		// Arm_B ...
		{
			if(sCH__MON_SYS_STS__WAFER_PRESENCE_STS2->Check__DATA(STR__ON) > 0)
			{
				dCH__MON__ARM_B_MATERIAL_STATUS->Set__DATA(STR__EXIST);
			}
			else if(sCH__MON_SYS_STS__WAFER_PRESENCE_STS2->Check__DATA(STR__OFF) > 0)
			{
				dCH__MON__ARM_B_MATERIAL_STATUS->Set__DATA(STR__NONE);
			}
		}
	}

	return r_flag;
}

int  CObj_NET__ATM_SR100
::Call__PICK(CII_OBJECT__VARIABLE* p_variable,
			 CII_OBJECT__ALARM* p_alarm,
			 const CString& arm_type,
			 const CString& stn_name,
			  const CString& stn_slot)
{
	int r_ret = Fnc__PICK(p_variable,p_alarm, arm_type,stn_name,stn_slot);

	if(iSim_Flag > 0)
	{
		if(r_ret > 0)	Fnc__SIM_PICK_TIME(p_variable,p_alarm, arm_type,stn_name,stn_slot);
	}
	return r_ret;
}
int  CObj_NET__ATM_SR100
::Fnc__SIM_PICK_TIME(CII_OBJECT__VARIABLE* p_variable,
					 CII_OBJECT__ALARM* p_alarm,
					 const CString& arm_type,
					 const CString& stn_name,
					 const CString& stn_slot)
{
	SCX__TIMER_CTRL x_timer_ctrl;
	x_timer_ctrl->REGISTER__ABORT_OBJECT(sObject_Name);

	// ...
	double  cfg__pick_time = 1.0;
	CString var_data;

	if(Macro__CHECK_LPx_INDEX(stn_name) >= 0)
	{
		aCH__SIM_CFG__LPx_PICK_TIME->Get__DATA(var_data);
	}
	else if((stn_name.CompareNoCase(STR__AL1) == 0)
		 || (stn_name.CompareNoCase(STR__AL2) == 0))
	{
		aCH__SIM_CFG__ALx_PICK_TIME->Get__DATA(var_data);
	}
	else if((stn_name.CompareNoCase(STR__LBA) == 0)
		 || (stn_name.CompareNoCase(STR__LBB) == 0))
	{
		aCH__SIM_CFG__LBx_PICK_TIME->Get__DATA(var_data);
	}
	else if(stn_name.CompareNoCase(STR__VIS1) == 0)
	{
		aCH__SIM_CFG__VISx_PICK_TIME->Get__DATA(var_data);
	}

	cfg__pick_time = atof(var_data);
	if(x_timer_ctrl->WAIT(cfg__pick_time) < 0)
	{
		return -1;
	}
	return 1;
}
int  CObj_NET__ATM_SR100
::Fnc__PICK(CII_OBJECT__VARIABLE* p_variable,
			CII_OBJECT__ALARM* p_alarm,
			const CString& arm_type,
			const CString& stn_name,
			const CString& stn_slot)
{

	return Seq__ROBOT_PICK(p_variable,p_alarm, arm_type,stn_name,stn_slot);
}

int  CObj_NET__ATM_SR100
::Call__PLACE(CII_OBJECT__VARIABLE* p_variable,
			  CII_OBJECT__ALARM* p_alarm,
			  const CString& arm_type,
			  const CString& stn_name,
			  const CString& stn_slot)
{
	// ...
	{
		CString act_name;
		act_name.Format("place from Arm-%s to %s-%s", arm_type,stn_name,stn_slot);

		Fnc__APP_LOG(act_name);
	}

	int r_ret = Fnc__PLACE(p_variable,p_alarm,arm_type,stn_name,stn_slot);
	
	if(iSim_Flag > 0)
	{
		if(r_ret > 0)		Fnc__SIM_PLACE_TIME(p_variable,p_alarm,arm_type,stn_name,stn_slot);
	}
	return r_ret;
}
int  CObj_NET__ATM_SR100
::Fnc__SIM_PLACE_TIME(CII_OBJECT__VARIABLE* p_variable,
					  CII_OBJECT__ALARM* p_alarm,
					  const CString& arm_type,
					  const CString& stn_name,
					  const CString& stn_slot)
{
	SCX__TIMER_CTRL x_timer_ctrl;
	x_timer_ctrl->REGISTER__ABORT_OBJECT(sObject_Name);

	// ...
	double  cfg__place_time = 1.0;
	CString var_data;

	if(Macro__CHECK_LPx_INDEX(stn_name) >= 0)
	{
		aCH__SIM_CFG__LPx_PLACE_TIME->Get__DATA(var_data);
	}
	else if((stn_name.CompareNoCase(STR__AL1) == 0)
		 || (stn_name.CompareNoCase(STR__AL2) == 0))
	{
		aCH__SIM_CFG__ALx_PLACE_TIME->Get__DATA(var_data);
	}
	else if((stn_name.CompareNoCase(STR__LBA) == 0)
		 || (stn_name.CompareNoCase(STR__LBB) == 0))
	{
		aCH__SIM_CFG__LBx_PLACE_TIME->Get__DATA(var_data);
	}
	else if(stn_name.CompareNoCase(STR__VIS1) == 0)
	{
		aCH__SIM_CFG__VISx_PLACE_TIME->Get__DATA(var_data);
	}

	cfg__place_time = atof(var_data);
	if(x_timer_ctrl->WAIT(cfg__place_time) < 0)	
	{
		return -1;
	}
	return 1;
}
int  CObj_NET__ATM_SR100
::Fnc__PLACE(CII_OBJECT__VARIABLE* p_variable,
		     CII_OBJECT__ALARM* p_alarm,
		     const CString& arm_type,
		     const CString& stn_name,
		     const CString& stn_slot)
{
	return Seq__ROBOT_PLACE(p_variable,p_alarm, arm_type,stn_name,stn_slot);
}

int  CObj_NET__ATM_SR100
::Call__ROTATE(CII_OBJECT__VARIABLE* p_variable,
			   CII_OBJECT__ALARM* p_alarm,
			   const CString& arm_type,
			   const CString& stn_name,
			   const CString& stn_slot)
{
	if(iSim_Flag > 0)
	{
		return Fnc__SIM_ROTATE(p_variable,p_alarm,arm_type,stn_name,stn_slot);
	}
	return Fnc__ROTATE(p_variable,p_alarm,arm_type,stn_name,stn_slot);
}
int  CObj_NET__ATM_SR100
::Fnc__SIM_ROTATE(CII_OBJECT__VARIABLE* p_variable,
				  CII_OBJECT__ALARM* p_alarm,
				  const CString& arm_type,
				  const CString& stn_name,
				  const CString& stn_slot)
{
	SCX__TIMER_CTRL x_timer_ctrl;
	x_timer_ctrl->REGISTER__ABORT_OBJECT(sObject_Name);

	double  cfg__rotate_time = 1.0;
	CString var_data;

	aCH__SIM_CFG__ROTATE_TIME->Get__DATA(var_data);
	cfg__rotate_time = atof(var_data);

	if(x_timer_ctrl->WAIT(cfg__rotate_time) < 0)
	{
		return -1; 
	}
	return 1;
}
int  CObj_NET__ATM_SR100
::Fnc__ROTATE(CII_OBJECT__VARIABLE* p_variable,
			  CII_OBJECT__ALARM* p_alarm,
			  const CString& arm_type,
			  const CString& stn_name,
			  const CString& stn_slot)
{

	return Seq__ROBOT_ROTATE(p_variable,p_alarm, arm_type,stn_name,stn_slot);
}


// ...
int  CObj_NET__ATM_SR100
::Call__CHECK_ERROR_CODE(CII_OBJECT__VARIABLE* p_variable,
						 CII_OBJECT__ALARM* p_alarm)
{
LOOP_RETRY:

	mMNG__ERR_CODE.Clear__Error_Code();

	CString err_code = sCH__ERROR_TEST__ERROR_CODE->Get__STRING();
	_Check__ERROR_CODE(err_code);

	// ...
	CString err_msg;

	while(mMNG__ERR_CODE.Get__Error_Code(err_code,err_msg) > 0)
	{
		int i_error = atoi(err_code);
		if(i_error == 0)		continue;

		// ...
		int alm_id = ALID__ERROR_CODE;
		CString alm_msg;
		CString alm_bff;
		CString r_act;

		alm_msg.Format("Control_Mode : %s \n", "Call__CHECK_ERROR_CODE()");

		alm_bff.Format("Error_Code : %s \n", err_code);
		alm_msg += alm_bff;
		alm_bff.Format("Error_Message \n");
		alm_msg += alm_bff;
		alm_msg += "  * ";
		alm_msg += err_msg;

		// ...
		{
			CString log_msg;

			log_msg.Format("Alarm Post : %1d \n", alm_id);
			log_msg += alm_msg;

			Fnc__APP_LOG(log_msg);
		}

		p_alarm->Popup__ALARM_With_MESSAGE(alm_id,alm_msg,r_act);			

		if(r_act.CompareNoCase(ACT__RETRY) == 0)
		{
			CString log_msg = "Alarm Selection <- Retry";
			Fnc__APP_LOG(log_msg);

			goto LOOP_RETRY;
		}
		if(r_act.CompareNoCase(ACT__ABORT) == 0)
		{
			return -1;
		}

		if(r_act.CompareNoCase(ACT__IGNORE) == 0)
		{
			// ...
		}
	}

	return 1;
}

int  CObj_NET__ATM_SR100
::Call__CHECK_STN_INFO(CII_OBJECT__VARIABLE* p_variable,
					   CII_OBJECT__ALARM* p_alarm)
{
	CString stn_name;
	CString stn_slot;
	CString stn_id;
	int i;

	// ALx ...
	{
		stn_name = STR__AL1;
		stn_slot = "1";

		stn_id = _Get__TRG_STN(stn_name, stn_slot);

		sCH__CUR_AL1_STN_NUM->Set__DATA(stn_id);
	}
	// STx ...
	{
		stn_name = STR__BUFF1;
		stn_slot = "1";

		stn_id = _Get__TRG_STN(stn_name, stn_slot);

		sCH__CUR_ST1_STN_NUM->Set__DATA(stn_id);
	}
	// LLx ...
	for(i=0; i<CFG_LLx__SIZE; i++)
	{
		stn_name = Macro__Get_LLx_NAME(i);

		if(bActive__LLx_MULTI_DOOR_VALVE)
		{
			CString stn_slot;

			for(int k=0; k<2; k++)
			{
				int slot_id = k + 1;

				stn_slot.Format("%1d", slot_id);
				stn_id = _Get__TRG_STN(stn_name, stn_slot);

				     if(slot_id == 1)		sCH__CUR_LLx_1_STN_NUM[i]->Set__DATA(stn_id);
				else if(slot_id == 2)		sCH__CUR_LLx_2_STN_NUM[i]->Set__DATA(stn_id);
			}
		}
		else
		{
			stn_id = _Get__TRG_STN(stn_name, "1");

			sCH__CUR_LLx_STN_NUM[i]->Set__DATA(stn_id);
		}
	}
	// LPx ...
	for(i=0; i<CFG_LPx__SIZE; i++)
	{
		stn_name = Macro__Get_LPx_NAME(i);
		stn_slot = "1";

		stn_id = _Get__TRG_STN(stn_name, stn_slot);

		sCH__CUR_LPx_STN_NUM[i]->Set__DATA(stn_id);
	}

	return 1;
}
