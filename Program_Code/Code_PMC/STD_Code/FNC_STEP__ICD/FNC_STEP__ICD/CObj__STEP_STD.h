#pragma once

#include "Interface_Code.h"
#include "CCommon_Error.h"

#include "CObj__STEP_STD__ALID.h"
#include "CObj__STEP_STD__DEF.h"


class CObj__STEP_STD : public __IOBJ__STD_TYPE
{
private:
	//-------------------------------------------------------------------------
	CString sObject_Name;

	// ...
	CCommon_Error__USER_FNC mERROR__USER_FNC;

	SCX__USER_LOG_CTRL xLOG_CTRL;
	int iActive__SIM_MODE;
	//


	//-------------------------------------------------------------------------
	//  INTERNAL PROPERTY

	// OBJ ...
	CX__VAR_STRING_CTRL  sCH__OBJ_MSG;
	CX__VAR_STRING_CTRL  sCH__OBJ_SUB_MSG;

	// INFO ...
	CX__VAR_STRING_CTRL  sCH__INFO_STEP_CUR_NUM;
	CX__VAR_STRING_CTRL  sCH__INFO_STEP_PRE_TIME;

	// MON ...
	CX__VAR_STRING_CTRL  sCH__MON_STEP_EXCEPTION_ACT;

	// CFG ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_STEP_ALARM_TEST_ACTIVE;

	CX__VAR_ANALOG_CTRL  aCH__CFG_STEP_STABLE_MIN_SEC;
	CX__VAR_ANALOG_CTRL  aCH__CFG_STEP_OBJECT_OVER_TIME_ERRPR_REF_SEC;

	CX__VAR_ANALOG_CTRL  aCH__CFG_CHM_PRESSURE_HIGH_LIMIT;

	CX__VAR_ANALOG_CTRL  aCH__CFG_STEP_DELAY_RF_OFF;
	CX__VAR_ANALOG_CTRL  aCH__CFG_STEP_DELAY_MFC_CLOSE;

	//
	CX__VAR_DIGITAL_CTRL dCH__CFG_STEP_READY_HEATER_MODE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_STEP_READY_CHECK_TIME_MIN;
	CX__VAR_ANALOG_CTRL  aCH__CFG_STEP_READY_CHECK_TIME_MAX;

	CX__VAR_DIGITAL_CTRL dCH__CFG_STEP_CTRL_HEATER_MODE;
	CX__VAR_DIGITAL_CTRL dCH__CFG_STEP_CTRL_ERROR_CONTROL;

	// CFG.PARTx ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_RCP_PART_USE_RFx_RPS;	
	CX__VAR_DIGITAL_CTRL dCH__CFG_RCP_PART_USE_RFx_PULSE;	
	CX__VAR_DIGITAL_CTRL dCH__CFG_RCP_PART_USE_RFx_HF;	
	CX__VAR_DIGITAL_CTRL dCH__CFG_RCP_PART_USE_RFx_LF;	

	CX__VAR_DIGITAL_CTRL dCH__CFG_RCP_PART_USE_MATx_HF;	
	CX__VAR_DIGITAL_CTRL dCH__CFG_RCP_PART_USE_MATx_LF;	

	// RCP ...
	CX__VAR_STRING_CTRL  sCH__RCP_STEP_MESSAGE;		
	CX__VAR_DIGITAL_CTRL dCH__RCP_STEP_MODE;	
	CX__VAR_ANALOG_CTRL	 aCH__RCP_STEP_TIME;	
	CX__VAR_ANALOG_CTRL	 aCH__RCP_STEP_OVERETCH_PERCENT;

	//
	CX__VAR_DIGITAL_CTRL dCH__RCP_APC_MODE;		
	CX__VAR_ANALOG_CTRL  aCH__RCP_APC_PRESSURE_mTORR;		
	CX__VAR_ANALOG_CTRL  aCH__RCP_APC_POSITION;		
	CX__VAR_STRING_CTRL  sCH__RCP_APC_LEARNED_POS;
	CX__VAR_STRING_CTRL  sCH__RCP_APC_HOLD_DELAY;

	//
	CX__VAR_ANALOG_CTRL  aCH__RCP_DGF_CENTER_PERCENT;
	CX__VAR_STRING_CTRL  sCH__RCP_GAS_FLOW_X[_CFG__MFC_SIZE];

	//
	CX__VAR_STRING_CTRL  sCH__RCP_RF_RPS_POWER;

	CX__VAR_STRING_CTRL  sCH__RCP_RF_LF_POWER;
	CX__VAR_STRING_CTRL  sCH__RCP_RF_HF_POWER;

	// 
	CX__VAR_ANALOG_CTRL  aCH__RCP_RF_PULSE_FREQUENCY;
	CX__VAR_ANALOG_CTRL  aCH__RCP_RF_PULSE_DUTY;
	CX__VAR_DIGITAL_CTRL dCH__RCP_RF_PULSE_EXEC;
	CX__VAR_ANALOG_CTRL  aCH__RCP_RF_PULSE_ON_TIME;
	CX__VAR_ANALOG_CTRL  aCH__RCP_RF_PULSE_OFF_TIME;
	CX__VAR_ANALOG_CTRL  aCH__RCP_RF_PULSE_ON_SHIFT_TIME;
	CX__VAR_ANALOG_CTRL  aCH__RCP_RF_PULSE_OFF_SHIFT_TIME;

	//
	CX__VAR_STRING_CTRL  sCH__RCP_MAT_LF_SHUNT;
	CX__VAR_STRING_CTRL  sCH__RCP_MAT_LF_SERIES;

	CX__VAR_STRING_CTRL  sCH__RCP_MAT_LF_LEARNED_SHUNT;
	CX__VAR_STRING_CTRL  sCH__RCP_MAT_LF_LEARNED_SERIES;

	//
	CX__VAR_STRING_CTRL  sCH__RCP_MAT_HF_SHUNT;
	CX__VAR_STRING_CTRL  sCH__RCP_MAT_HF_SERIES;

	CX__VAR_STRING_CTRL  sCH__RCP_MAT_HF_LEARNED_SHUNT;
	CX__VAR_STRING_CTRL  sCH__RCP_MAT_HF_LEARNED_SERIES;

	//
	CX__VAR_DIGITAL_CTRL dCH__RCP_ESC_CTRL_MODE;
	CX__VAR_STRING_CTRL  sCH__RCP_DPC_CENTER_PRESSURE;	
	CX__VAR_STRING_CTRL  sCH__RCP_DPC_EDGE_PRESSURE;

	//
	CX__VAR_DIGITAL_CTRL dCH__RCP_LIFT_PIN_MODE;

	//
	CX__VAR_DIGITAL_CTRL dCH__RCP_EPD_EPD_MODE;
	CX__VAR_ANALOG_CTRL  aCH__RCP_EPD_VALUE_TO_CHANGE;
	CX__VAR_ANALOG_CTRL  aCH__RCP_EPD_PERCENT_TO_CHANGE;

	CX__VAR_ANALOG_CTRL  aCH__RCP_EPD_DELAY_TIME;
	CX__VAR_ANALOG_CTRL  aCH__RCP_EPD_NORMALIZE_TIME;

	CX__VAR_ANALOG_CTRL  aCH__RCP_EPD_MIN_TIME;
	CX__VAR_ANALOG_CTRL  aCH__RCP_EPD_MAX_TIME;

	CX__VAR_ANALOG_CTRL  aCH__RCP_EPD_MIN_THRESHOLD;
	CX__VAR_ANALOG_CTRL  aCH__RCP_EPD_MAX_THRESHOLD;

	CX__VAR_ANALOG_CTRL  aCH__RCP_EPD_SLOPE_VALUE;
	CX__VAR_DIGITAL_CTRL dCH__RCP_EPD_SLOPE_TYPE;
	CX__VAR_ANALOG_CTRL  aCH__RCP_EPD_SLOPE_VALID_TIME;
	//


	//-------------------------------------------------------------------------
	//  EXTERNAL PROPERTY

	// DB INF ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__SLOT01_STATUS;
	CX__VAR_STRING_CTRL  sEXT_CH__CUR_LOTID;

	// OBJ APC ...
	int APC_OBJ__Start_MODE(const CString& obj_mode,const CString& para_data, const double para_hold_sec,const double para_hold_pos);
	int APC_OBJ__Start_OPEN();	
	int APC_OBJ__Check_ERROR();
	int APC_OBJ__Check_ABORTED();
	int APC_OBJ__Check_STABLE();

	bool bActive__OBJ_CTRL__APC;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__APC;

	CX__VAR_ANALOG_CTRL	 aEXT_CH__APC_OBJ__PARA_PRESSURE;
	CX__VAR_ANALOG_CTRL	 aEXT_CH__APC_OBJ__PARA_POSITION;
	CX__VAR_ANALOG_CTRL	 aEXT_CH__APC_OBJ__PARA_HOLD_SEC;

	CX__VAR_STRING_CTRL  sEXT_CH__APC_OBJ__MON_PRESSURE_TORR;

	CX__VAR_DIGITAL_CTRL dEXT_CH__APC_OBJ__MON_PROC_PRESSURE_ABORT_ACTIVE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__APC_OBJ__MON_PROC_PRESSURE_STABLE_ACTIVE;

	CX__VAR_DIGITAL_CTRL dEXT_CH__APC_OBJ__MON_IDLE_PRESSURE_ABORT_ACTIVE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__APC_OBJ__MON_IDLE_PRESSURE_STABLE_ACTIVE;

	// OBJ PT_X ...
	int PT_OBJ__Check_ERROR();

	int iDATA__PT_SIZE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__PT_X__MON_ABORT_ACTIVE[_CFG__PT_SIZE];

	// OBJ DGF ...
	int DGF_OBJ__Start_CONTROL(const CString& para_center);

	bool bActive__OBJ_CTRL__DGF;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__DGF;

	CX__VAR_ANALOG_CTRL	 aEXT_CH__DGF_OBJ__CENTER_Wt_SETPOINT;

	// OBJ MFC_X ...
	int MFC_OBJ__Start_CONTROL(const int mfc_index, const CString& para_flow,const CString& para_ramp_sec);
	int MFC_OBJ__Start_CLOSE(const int mfc_index);
	int MFC_OBJ__Check_ERROR();
	int MFC_OBJ__Check_ABORTED();

	int iDATA__MFC_SIZE;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__MFC_X[_CFG__MFC_SIZE];

	CX__VAR_STRING_CTRL  sEXT_CH__MFC_X__PARA_SET_FLOW[_CFG__MFC_SIZE];
	CX__VAR_STRING_CTRL  sEXT_CH__MFC_X__PARA_RAMP_SEC[_CFG__MFC_SIZE];

	CX__VAR_DIGITAL_CTRL dEXT_CH__MFC_X__MON_MFC_ABORT_ACTIVE[_CFG__MFC_SIZE];

	// OBJ RF.RPS ...
	int RF_RPS_OBJ__Start_MODE(const CString& obj_mode, const CString& para_data);
	int RF_RPS_OBJ__Start_OFF();
	int RF_RPS_OBJ__Check_ERROR();
	int RF_RPS_OBJ__Check_ABORTED();

	bool bActive__OBJ_CTRL__RF_RPS;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__RF_RPS;

	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_RPS__PARA_SET_POWER;
	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_RPS__PARA_HOLD_TIME;

	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_RPS__MON_IDLE_POWER_ABORT_ACTIVE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_RPS__MON_PROC_POWER_ABORT_ACTIVE;

	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_RPS__MON_REFLECT_HIGH_LIMIT_ACTIVE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_RPS__MON_REFLECT_MAX_COEFFICIENT_ACTIVE;

	// OBJ RF.LF ...
	int RF_LF_OBJ__Start_MODE(const CString& obj_mode, const CString& para_data);
	int RF_LF_OBJ__Start_OFF();
	int RF_LF_OBJ__Check_ERROR();
	int RF_LF_OBJ__Check_ABORTED();

	bool bActive__OBJ_CTRL__RF_LF;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__RF_LF;

	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_LF__PARA_SET_POWER;
	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_LF__PARA_HOLD_TIME;

	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_LF__MON_IDLE_POWER_ABORT_ACTIVE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_LF__MON_PROC_POWER_ABORT_ACTIVE;

	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_LF__MON_REFLECT_HIGH_LIMIT_ACTIVE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_LF__MON_REFLECT_MAX_COEFFICIENT_ACTIVE;

	// OBJ RF.HF ...
	int RF_HF_OBJ__Start_MODE(const CString& obj_mode, const CString& para_data);
	int RF_HF_OBJ__Start_OFF();
	int RF_HF_OBJ__Check_ERROR();
	int RF_HF_OBJ__Check_ABORTED();

	bool bActive__OBJ_CTRL__RF_HF;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__RF_HF;

	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_HF__PARA_SET_POWER;
	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_HF__PARA_HOLD_TIME;

	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_HF__MON_IDLE_POWER_ABORT_ACTIVE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_HF__MON_PROC_POWER_ABORT_ACTIVE;

	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_HF__MON_REFLECT_HIGH_LIMIT_ACTIVE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_HF__MON_REFLECT_MAX_COEFFICIENT_ACTIVE;

	// OBJ RF.PULSE ...
	int RF_PULSE_OBJ__Start_ON();
	int RF_PULSE_OBJ__Start_OFF();
	int RF_PULSE_OBJ__Check_ERROR();
	int RF_PULSE_OBJ__Check_ABORTED();

	bool bActive__OBJ_CTRL__RF_PULSE;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__RF_PULSE;

	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_PULSE__PARA_RCP_FREQUENCY;
	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_PULSE__PARA_RCP_DUTY;
	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_PULSE__PARA_RCP_EXEC;
	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_PULSE__PARA_RCP_ON_TIME;
	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_PULSE__PARA_RCP_OFF_TIME;
	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_PULSE__PARA_RCP_ON_SHIFT_TIME;
	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_PULSE__PARA_RCP_OFF_SHIFT_TIME;

	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_PULSE__MON_POWER_ABORT_ACTIVE;

	// OBJ MAT_LF ...
	int MAT_LF_OBJ__Start_MODE(const CString& obj_mode);
	int MAT_LF_OBJ__Check_ABORTED();

	bool bActive__OBJ_CTRL__MAT_LF;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__MAT_LF;

	CX__VAR_ANALOG_CTRL aEXT_CH__MAT_LF__PARA_LOAD_POS;
	CX__VAR_ANALOG_CTRL aEXT_CH__MAT_LF__PARA_TUNE_POS;

	// OBJ MAT_HF ...
	int MAT_HF_OBJ__Start_MODE(const CString& obj_mode);
	int MAT_HF_OBJ__Check_ABORTED();

	bool bActive__OBJ_CTRL__MAT_HF;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__MAT_HF;

	CX__VAR_ANALOG_CTRL aEXT_CH__MAT_HF__PARA_LOAD_POS;
	CX__VAR_ANALOG_CTRL aEXT_CH__MAT_HF__PARA_TUNE_POS;

	// OBJ ESC ...
	int ESC_OBJ__Init_DATA();
	int ESC_OBJ__Start_MODE(const CString& obj_mode);
	int ESC_OBJ__Start_HE_CLOSE();
	int ESC_OBJ__Check_ERROR();
	int ESC_OBJ__Check_ABORTED();
	int ESC_OBJ__Is_BUSY();

	bool bActive__OBJ_CTRL__ESC;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__ESC;

	CX__VAR_DIGITAL_CTRL dEXT_CH__ESC__MON_FAULT_ACTIVE;

	CX__VAR_STRING_CTRL  sEXT_CH__ESC__RCP_He_CENTER_PRESSURE_SETPOINT_TORR;
	CX__VAR_STRING_CTRL  sEXT_CH__ESC__RCP_He_CENTER_FLOW_MAX_THRESHOLD;
	CX__VAR_STRING_CTRL  sEXT_CH__ESC__RCP_He_CENTER_FLOW_MIN_THRESHOLD;

	CX__VAR_STRING_CTRL  sEXT_CH__ESC__RCP_He_EDGE_PRESSURE_SETPOINT_TORR;
	CX__VAR_STRING_CTRL  sEXT_CH__ESC__RCP_He_EDGE_FLOW_MAX_THRESHOLD;
	CX__VAR_STRING_CTRL  sEXT_CH__ESC__RCP_He_EDGE_FLOW_MIN_THRESHOLD;

	// OBJ LIFT_PIN ...
	int LIFT_PIN_OBJ__Start_MODE(const CString& obj_mode);
	int LIFT_PIN_OBJ__Check_ABORTED();
	int LIFT_PIN_OBJ__Is_BUSY();

	bool bActive__OBJ_CTRL__LIFT_PIN;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__LIFT_PIN;

	// OBJ.SHOWER_HEAD ...
	int HTR_SH_OBJ__Check_ERROR();

	bool bActive__OBJ_CTRL__HTR_SH;

	CX__VAR_DIGITAL_CTRL dEXT_CH__HTR_SH__MON_IDLE_STABLE_ACTIVE_X[_CFG__SH_SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__HTR_SH__MON_IDLE_ABORT_ACTIVE_X[_CFG__SH_SIZE];

	// OBJ.WALL ...
	int HTR_WALL_OBJ__Check_ERROR();

	bool bActive__OBJ_CTRL__HTR_WALL;

	CX__VAR_DIGITAL_CTRL dEXT_CH__HTR_WALL__MON_IDLE_STABLE_ACTIVE_X[_CFG__WALL_SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__HTR_WALL__MON_IDLE_ABORT_ACTIVE_X[_CFG__WALL_SIZE];

	// OBJ.EPD ...
	int EPD_OBJ__Call_INIT();
	int EPD_OBJ__Start_IDLE();
	int EPD_OBJ__Start_CHECK();
	int EPD_OBJ__Start_DETECT();
	int EPD_OBJ__Check_ABORTED();
	int EPD_OBJ__Is_BUSY();
	int EPD_OBJ__Check_ERROR();

	bool bActive__OBJ_CTRL__EPD;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__EPD;

	//
	CX__VAR_DIGITAL_CTRL dEXT_CH__EPD__PARA_EPD_MODE;

	CX__VAR_STRING_CTRL  sEXT_CH__EPD__PARA_VALUE_TO_CHANGE;
	CX__VAR_STRING_CTRL  sEXT_CH__EPD__PARA_PERCENT_TO_CHANGE;

	CX__VAR_ANALOG_CTRL  aEXT_CH__EPD__PARA_DELAY_TIME;
	CX__VAR_STRING_CTRL  sEXT_CH__EPD__PARA_NORMALIZE_TIME;

	CX__VAR_ANALOG_CTRL  aEXT_CH__EPD__PARA_EPD_TIMEOUT_MINIMUM;
	CX__VAR_ANALOG_CTRL  aEXT_CH__EPD__PARA_EPD_TIMEOUT_MAXIMUM;

	CX__VAR_STRING_CTRL  sEXT_CH__EPD__PARA_EPD_THRESHOLD_MIN;
	CX__VAR_STRING_CTRL  sEXT_CH__EPD__PARA_EPD_THRESHOLD_MAX;

	CX__VAR_STRING_CTRL  sEXT_CH__EPD__PARA_SLOPE_COUNT;
	CX__VAR_STRING_CTRL  sEXT_CH__EPD__PARA_SLOPE_DIRECTION;
	CX__VAR_STRING_CTRL  sEXT_CH__EPD__PARA_VALID_TIME;

	//
	CX__VAR_DIGITAL_CTRL dEXT_CH__EPD__MON_ERROR_ACTIVE;
	//


	//-------------------------------------------------------------------------
	// OBJ.MODE ...

	CString sMODE__INIT;
	int Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__READY;
	int Call__READY(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__START;
	int Call__START(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__PROC;
	int Call__PROC(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int _Fnc__PROC_LOG();

	CString sMODE__ABORT;
	int Call__ABORT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__END;
	int Call__END(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM* p_alarm);
	int _Fnc__END();

	// ...
	double Fnc__OBJ_OVERTIME_CHECK(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM* p_alarm);

	int Get__STEP_CTRL();
	//

public:
	CObj__STEP_STD();
	~CObj__STEP_STD();

	//-------------------------------------------------------------------------
	int __DEFINE__CONTROL_MODE(obj,l_mode);
	int __DEFINE__VERSION_HISTORY(version);

	int __DEFINE__VARIABLE_STD(p_variable);
	int __DEFINE__ALARM(p_alarm);

	int __Define__USER_FUNCTION(CII_DEFINE__FUNCTION *p_fnc_ctrl);

	//-------------------------------------------------------------------------
	int __INITIALIZE__OBJECT(p_variable,p_ext_obj_create);

	//-------------------------------------------------------------------------
	int __CALL__CONTROL_MODE(mode,p_debug,p_variable,p_alarm);
	int __CALL__MONITORING(id,p_variable,p_alarm);
};
