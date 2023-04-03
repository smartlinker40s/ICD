#pragma once

#include "Interface_Code.h"
#include "CCommon_Error.h"

#include "CObj__RTU_SERIAL__ALID.h"
#include "CObj__RTU_SERIAL__DEF.h"


class CObj__RTU_SERIAL : public __IOBJ__IO_TYPE
{
private:
	//-------------------------------------------------------------------------
	CString	sObject_Name;

	// ...
	int iActive__SIM_MODE;

	CUIntArray iLIST_ALID__PIN;

	// ...
	SCX__SERIAL_JG mX_Serial;

	unsigned char iPARA__SLAVE_ID;

	bool bActive__COMM_ONLINE;
	//


	//-------------------------------------------------------------------------
	SCX__USER_LOG_CTRL xI__APP_LOG_CTRL;
	SCX__USER_LOG_CTRL xI__DRV_LOG_CTRL;

	void Write__APP_LOG(const CString& log_msg);
	void Write__DRV_LOG(const CString& log_msg);


	//-------------------------------------------------------------------------
	//  INTERNAL PROPERTY

	// OBJ ...
	CX__VAR_STRING_CTRL  sCH__OBJ_MSG;
	CX__VAR_STRING_CTRL  sCH__OBJ_SUB_MSG;

	CX__VAR_STRING_CTRL  sCH__OBJ_TIME_COUNT;

	// MON.PART ... 
	CX__VAR_DIGITAL_CTRL dCH__MON_PIN_ERROR_ACTIVE;

	// Simulation ...
	CX__VAR_ANALOG_CTRL  aCH__SIM_HOME_TIME;
	CX__VAR_ANALOG_CTRL  aCH__SIM_MOVE_TIME;

	// Parameter ...
	CX__VAR_ANALOG_CTRL  aCH__PARA_GOTO_POS_DATA_PULSE;
	CX__VAR_ANALOG_CTRL  aCH__PARA_GOTO_POS_SPEED;
	CX__VAR_ANALOG_CTRL  aCH__PARA_GOTO_POS_ACCEL;
	CX__VAR_ANALOG_CTRL  aCH__PARA_GOTO_POS_DECEL;

	// Monitoring Channel ...
	CX__VAR_STRING_CTRL  sCH__MON_COMM_STS;

	CX__VAR_STRING_CTRL  sCH__MON_LIFT_PIN_STATE;
	CX__VAR_STRING_CTRL  sCH__MON_LIFT_PIN_INFO;

	CX__VAR_STRING_CTRL  sCH__MON_IO_WARNING_DATA_HEXA;
	CX__VAR_STRING_CTRL  sCH__MON_IO_WARNING_VIEW_REQ;

	CX__VAR_STRING_CTRL  sCH__MON_IO_ALARM_DATA_HEXA;
	CX__VAR_STRING_CTRL  sCH__MON_IO_ALARM_VIEW_REQ;

	CX__VAR_STRING_CTRL  sCH__MON_IO_LAST_ERROR_VIEW_REQ;

	CX__VAR_STRING_CTRL  sCH__MON_ALARM_SIZE;		

	// Command Request ...
	CX__VAR_STRING_CTRL  sCH__CMMD_REQ_SAVE;

	// Config Channel ..
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_VOLTAGE_PIN_UP_THRESHOLD;
	
	CX__VAR_ANALOG_CTRL  aCH__CFG_RANGE_POSITION_MIN;
	CX__VAR_ANALOG_CTRL  aCH__CFG_RANGE_POSITION_MAX;
	CX__VAR_ANALOG_CTRL  aCH__CFG_RANGE_POSITION_DEC;

	CX__VAR_ANALOG_CTRL  aCH__CFG_CONVERSION_UNIT_PULSE_TO_MM;

	CX__VAR_ANALOG_CTRL  aCH__CFG_HOME_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_MOVING_TIMEOUT;

	//
	CX__VAR_DIGITAL_CTRL dCH__CFG_HOME_METHOD;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HOME_SPEED;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HOME_OFFSET_POS;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HOME_APPROACH;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HOME_CREEP;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HOME_ACCEL;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HOME_DECEL;
	CX__VAR_DIGITAL_CTRL dCH__CFG_HOME_DIRECTION;
	CX__VAR_DIGITAL_CTRL dCH__CFG_HOME_OBxx05B;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HOME_ZERO_BASE_OFFSET;

	// Teaching Config ...
	CX__VAR_STRING_CTRL  sCH__ACTIVE_MOVE_DOWN_UP;
	CX__VAR_STRING_CTRL  sCH__ACTIVE_PROC_DOWN_UP;

	CX__VAR_STRING_CTRL  sCH__TEACH_ACTIVE_JOG_UP;
	CX__VAR_STRING_CTRL  sCH__TEACH_ACTIVE_JOG_DOWN;

	CX__VAR_STRING_CTRL  sCH__TEACH_ACTIVE_ABS_UP;
	CX__VAR_STRING_CTRL  sCH__TEACH_ACTIVE_ABS_DOWN;

	CX__VAR_ANALOG_CTRL  aCH__CFG_GOTO_POS_UP_ABS_POS;
	CX__VAR_ANALOG_CTRL  aCH__CFG_GOTO_POS_DOWN_ABS_POS;

	CX__VAR_ANALOG_CTRL  aCH__CFG_TEACH_JOG_SPEED;
	CX__VAR_ANALOG_CTRL  aCH__CFG_TEACH_JOG_ACCEL;
	CX__VAR_ANALOG_CTRL  aCH__CFG_TEACH_JOG_DECEL;

	CX__VAR_ANALOG_CTRL  aCH__CFG_TEACH_ABS_SPEED;
	CX__VAR_ANALOG_CTRL  aCH__CFG_TEACH_ABS_ACCEL;
	CX__VAR_ANALOG_CTRL  aCH__CFG_TEACH_ABS_DECEL;

	// 
	CX__VAR_STRING_CTRL  sCH__APP_PROC_POS_X_SNS[CFG_SIZE__PROC_POS];	
	CX__VAR_ANALOG_CTRL  aCH__CFG_PROC_POS_X_DATA_POS[CFG_SIZE__PROC_POS];	
	CX__VAR_ANALOG_CTRL  aCH__CFG_PROC_POS_X_SPEED[CFG_SIZE__PROC_POS];	
	CX__VAR_ANALOG_CTRL  aCH__CFG_PROC_POS_X_ACCEL[CFG_SIZE__PROC_POS];	
	CX__VAR_ANALOG_CTRL  aCH__CFG_PROC_POS_X_DECEL[CFG_SIZE__PROC_POS];	

	CX__VAR_STRING_CTRL  sCH__APP_TRANSFER_POS_X_SNS[CFG_SIZE__TRANSFER_POS];
	CX__VAR_ANALOG_CTRL  aCH__CFG_TRANSFER_POS_X_DATA_POS[CFG_SIZE__TRANSFER_POS];
	CX__VAR_ANALOG_CTRL  aCH__CFG_TRANSFER_POS_X_SPEED[CFG_SIZE__TRANSFER_POS];	
	CX__VAR_ANALOG_CTRL  aCH__CFG_TRANSFER_POS_X_ACCEL[CFG_SIZE__TRANSFER_POS];	
	CX__VAR_ANALOG_CTRL  aCH__CFG_TRANSFER_POS_X_DECEL[CFG_SIZE__TRANSFER_POS];	

	// CYCLE TEST : TRANSFER POS ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_MOVE_DOWN_UP_CYCLE;
	CX__VAR_STRING_CTRL  sCH__RESULT_MOVE_DOWN_UP_CYCLE;
	CX__VAR_STRING_CTRL  sCH__RESULT_MOVE_DOWN_UP_AVG_UP;
	CX__VAR_STRING_CTRL  sCH__RESULT_MOVE_DOWN_UP_MIN_UP;
	CX__VAR_STRING_CTRL  sCH__RESULT_MOVE_DOWN_UP_MAX_UP;
	CX__VAR_STRING_CTRL  sCH__RESULT_MOVE_DOWN_UP_AVG_DOWN;
	CX__VAR_STRING_CTRL  sCH__RESULT_MOVE_DOWN_UP_MIN_DOWN;
	CX__VAR_STRING_CTRL  sCH__RESULT_MOVE_DOWN_UP_MAX_DOWN;

	// CYCLE TEST : PROCESS POS ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_PROC_DOWN_UP_CYCLE;
	CX__VAR_STRING_CTRL  sCH__RESULT_PROC_DOWN_UP_CYCLE;
	CX__VAR_STRING_CTRL  sCH__RESULT_PROC_DOWN_UP_AVG_UP;
	CX__VAR_STRING_CTRL  sCH__RESULT_PROC_DOWN_UP_MIN_UP;
	CX__VAR_STRING_CTRL  sCH__RESULT_PROC_DOWN_UP_MAX_UP;
	CX__VAR_STRING_CTRL  sCH__RESULT_PROC_DOWN_UP_AVG_DOWN;
	CX__VAR_STRING_CTRL  sCH__RESULT_PROC_DOWN_UP_MIN_DOWN;
	CX__VAR_STRING_CTRL  sCH__RESULT_PROC_DOWN_UP_MAX_DOWN;

	// Stable Channel ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_WARNING_LIMIT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_FAULT_LIMIT;

	CX__VAR_ANALOG_CTRL  aCH__CFG_CHECKING_TIME_FOR_STABLE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_CHECK_TIMEOUT_FOR_ERROR;
	CX__VAR_ANALOG_CTRL  aCH__CFG_STABLE_TIME_FOR_SETPINT_CHANGE;

	CX__VAR_STRING_CTRL  sCH__MON_AXIS_STABLE_STATE[CFG__AXIS_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_AXIS_STABLE_TIME[CFG__AXIS_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_AXIS_FAULT_STATE[CFG__AXIS_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_AXIS_FAULT_TIME[CFG__AXIS_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_AXIS_CHANGE_STATE[CFG__AXIS_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_AXIS_CHANGE_TIME[CFG__AXIS_SIZE];

	CX__VAR_STRING_CTRL  sCH__MON_STABLE_FLAG;
	CX__VAR_STRING_CTRL  sCH__MON_FAULT_FLAG;


	//-------------------------------------------------------------------------
	// DRIVER.INFO ...

	// CFG.DRV ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_DRV_PARITY_BIT;
	CX__VAR_DIGITAL_CTRL dCH__CFG_DRV_DATA_BIT;

	// INFO ...
	CX__VAR_STRING_CTRL  sCH__INFO_MOTOR_IDLE;

	CX__VAR_STRING_CTRL  sCH__INFO_SET_POS_MM;
	CX__VAR_STRING_CTRL  sCH__INFO_CUR_POS_MM;

	CX__VAR_STRING_CTRL  sCH__INFO_SET_POS_STEP;
	CX__VAR_STRING_CTRL  sCH__INFO_CUR_POS_STEP;

	CX__VAR_STRING_CTRL  sCH__INFO_SET_VEL;
	CX__VAR_STRING_CTRL  sCH__INFO_CUR_VEL;

	CX__VAR_STRING_CTRL  sCH__INFO_SET_ACCEL;
	CX__VAR_STRING_CTRL  sCH__INFO_SET_DECEL;

	// INFO.MON ...
	CX__VAR_STRING_CTRL  sCH__INFO_MON_DATA_NO;
	CX__VAR_STRING_CTRL  sCH__INFO_MON_POS_STEP_SET;
	CX__VAR_STRING_CTRL  sCH__INFO_MON_VEL_RPM_SET;
	CX__VAR_STRING_CTRL  sCH__INFO_MON_VEL_HZ_SET;
	CX__VAR_STRING_CTRL  sCH__INFO_MON_POS_STEP_CUR;
	CX__VAR_STRING_CTRL  sCH__INFO_MON_VEL_RPM_CUR;
	CX__VAR_STRING_CTRL  sCH__INFO_MON_VEL_HZ_CUR;
	CX__VAR_STRING_CTRL  sCH__INFO_MON_DWELL_MSEC_CUR;
	CX__VAR_STRING_CTRL  sCH__INFO_MON_DIRECT_IO_CUR;
	CX__VAR_STRING_CTRL  sCH__INFO_MON_TORQUE_CUR;
	CX__VAR_STRING_CTRL  sCH__INFO_MON_MOTOR_LOAD_CUR;

	// INFO.DRV ...
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_COM_PORT;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_PARAMETER;

	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BYTE_0_HEXA;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT00_M0;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT01_M1;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT02_M2;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT03_START;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT04_HOME;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT05_READY;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT06_INFO;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT07_ALARM;

	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BYTE_1_HEXA;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT08_BUSY;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT09_AREA0;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT10_AREA1;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT11_AREA2;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT12_TIM;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT13_MOVE;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT14_IN_POS;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_BIT15_TLC;

	// SET.DRV ...
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BYTE_0_HEXA;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT00_M0;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT01_M1;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT02_M2;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT03_START;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT04_HOME;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT05_STOP;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT06_FREE;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT07_ALARM_RESET;

	CX__VAR_STRING_CTRL  sCH__SET_DRV_BYTE_1_HEXA;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT08_D_SEL0;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT09_D_SEL1;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT10_D_SEL2;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT11_SSTART;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT12_FW_JOG;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT13_RV_JOG;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT14_FW_POS;
	CX__VAR_STRING_CTRL  sCH__SET_DRV_BIT15_RV_POS;


	// DO ...
	CX__VAR_DIGITAL_CTRL doCH__CTRL_SET;
	CX__VAR_DIGITAL_CTRL doCH__PARA_GOTO_SET;

	// SI ...
	CX__VAR_STRING_CTRL  siCH__DRIVER_STS__AUTO;
	CX__VAR_STRING_CTRL  siCH__DRIVER_STS__MANUAL;
	CX__VAR_STRING_CTRL  siCH__MONITOR_ALL;
	//	


	//-------------------------------------------------------------------------
	//  EXTERNAL PROPERTY

	// LINK IO ...
	CX__VAR_STRING_CTRL  sEXT_CH__LIFT_PIN_STATE;

	//
	bool bActive__ESC_CHUCK_STATE;
	CX__VAR_STRING_CTRL  sEXT_CH__ESC_CHUCK_STATE;

	int iDATA__ESC_CH_SIZE;
	CX__VAR_ANALOG_CTRL  aEXT_CH__ESC_AI_VOLTAGE_X[_CFG__ESC_CH_SIZE];
	//


	//-------------------------------------------------------------------------
	CString sMODE__INIT;
	int  Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__INIT(CII_OBJECT__ALARM* p_alarm);

	CString sMODE__HOME;
	int  Call__HOME(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  _Fnc__HOME(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// TRANSFER ...
	CString sMODE__DOWN;
	int Call__DOWN(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__UP;
	int Call__UP(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__MIDDLE_DOWN;
	int Call__MIDDLE_DOWN(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__MIODLE_UP;
	int Call__MIDDLE_UP(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	// PROCESS ...
	CString sMODE__PROC_DOWN;
	int Call__PROC_DOWN(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__PROC_MIDDLE;
	int Call__PROC_MIDDLE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__PROC_UP;
	int Call__PROC_UP(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	// CYCLE ...
	CString sMODE__CYCLE_DOWN_UP;
	int  Call__CYCLE_DOWN_UP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__CYCLE_PROC_DOWN_UP;
	int  Call__CYCLE_PROC_DOWN_UP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// TEACH ...
	CString sMODE__TEACH_ABS_UP;
	CString sMODE__TEACH_ABS_DOWN;
	int  Call__TEACH_ABS_START(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int up_mode);

	int  Update__JOG_OF_TEACHING_PROPERTY();
	int  Update__ABS_OF_TEACHING_PROPERTY(const int up_mode);

	int  Update__GOTO_POS_OF_PROC_POS(const int pos_index);
	int  Update__GOTO_POS_OF_PROC_SPEED(const int pos_index);

	int  Update__GOTO_POS_OF_MOVE_POS(const int pos_index);
	int  Update__GOTO_POS_OF_MOVE_SPEED(const int pos_index);

	int  Fnc__GOTO_POS_START(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Sub__GOTO_POS_START(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__GOTO_POS_STOP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__TEACH_JOG_PLUS;
	CString sMODE__TEACH_JOG_MINUS;
	int  Call__TEACH_JOG_START(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int plus_mode);

	int  Fnc__TEACH_JOG_START(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int plus_mode);
	int  Fnc__TEACH_JOG_STOP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// ...
	CString sMODE__MOVE_STOP;
	int  Call__MOVE_STOP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__RETURN;
	int Call__RETURN(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__CHECK_ALARM;
	int Call__CHECK_ALARM(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__CLEAR_ALARM;
	int Call__CLEAR_ALARM(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__CLEAR_SERVO_ALARM;
	int Call__CLEAR_SERVO_ALARM(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__SERVO_ON;
	int Call__SERVO_ON(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__SERVO_OFF;
	int Call__SERVO_OFF(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	// ...
	CString Get__ERROR_CODE_AND_TROUBLE_SHOOTING(DWORD err_code);
	CString Get__WARNING_OF_MONITORING_PARAMETER(DWORD code_value);
	CString Get__ALARM_OF_MONITORING_PARAMETER(DWORD code_value);

	// ...
	int _Send__Command(const unsigned short reg_addr, 
					   const unsigned short reg_count,
					   const CUIntArray& l_reg_data);

	int _Read__Command(const unsigned short reg_addr,
					   const unsigned short reg_count,
					   unsigned char* r_data,
					   int& r_len);

	unsigned short _Get__CRC16(unsigned char* s_data, 
		                       const int data_len);

	int _Set__Driver_Command_Of_Byte(unsigned char byte_0, 
									 unsigned char byte_1);


	// ...
	int  Mon__MONITOR(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	void Update__PIN_STATE();

	// TRANSFER : XXX_POS -> DOWN
	int  Check__TRANSFER_POS__MORE_THAN__MIDDLE_UP();
	int  Check__TRANSFER_POS__MORE_THAN__MIDDLE_DOWN();

	// TRANSFER : XXX_POS -> UP
	int  Check__TRANSFER_POS__LESS_THAN__MIDDLE_DOWN();
	int  Check__TRANSFER_POS__LESS_THAN__MIDDLE_UP();

	// PROCESS : XXX_POS -> DOWN
	int  Check__PROCESS_POS__MORE_THAN__MIDDLE();

	// PROCESS : XXX_POS -> UP
	int  Check__PROCESS_POS__LESS_THAN__MIDDLE();

	// ...
	int	 Mon__VIEW_REQ(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	// ...
	int  Fnc__CHECK_CHUCKING(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	int	 Alarm__CHECK_RETRY_ABORT(CII_OBJECT__ALARM* p_alarm, CString msg, const int alarm_id);
	int	 Alarm__POST_CHECK(CII_OBJECT__ALARM *p_alarm, CString msg, const int alarm_id);
	//


public:
	CObj__RTU_SERIAL();
	~CObj__RTU_SERIAL();

	//-------------------------------------------------------------------------
	int __DEFINE__CONTROL_MODE(obj, l_mode);
	int __DEFINE__VERSION_HISTORY(version);

	int __DEFINE__VARIABLE_STD(p_variable);
	int __DEFINE__VARIABLE_IO(p_io_variable);

	int __DEFINE__ALARM(p_alarm);

	//-------------------------------------------------------------------------
	int __INITIALIZE__OBJECT(p_variable,p_ext_obj_create);
	int __INITIALIZE__IO(p_io_para);

	//-------------------------------------------------------------------------
	int __CALL__CONTROL_MODE(mode, p_debug, p_variable, p_alarm);
	int __CALL__MONITORING(id, p_variable, p_alarm);

	//-------------------------------------------------------------------------
	int __Read__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, double& read_data);
	int __Read__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, CString& read_data,int& item_index);
	int __Read__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, CString& read_data);

	int __Write__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const double set_data);
	int __Write__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data,const int item_index);
	int __Write__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data);
};
