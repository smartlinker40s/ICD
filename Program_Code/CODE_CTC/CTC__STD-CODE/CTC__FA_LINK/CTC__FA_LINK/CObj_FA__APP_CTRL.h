#pragma once

#include "Interface_Code.h"

#include "CCommon_Error.h"
#include "CCommon_System.h"


// ...
#define CFG__TERMINAL_MSG_SIZE					10
#define CFG__TERMINAL_LOG_SIZE					10

// ...
#define STR__ENABLE			"ENABLE"
#define STR__DISABLE		"DISABLE"
#define STR__NOT_USE		"NOT_USE"
#define STR__NOT_CTRL		"NOT.CTRL"

#define STR__TRUE			"TRUE"
#define STR__OK				"OK"

#define STR__LOCAL			"LOCAL"
#define STR__REMOTE			"REMOTE"

#define STR__ONLINE			"ONLINE"
#define STR__OFFLINE		"OFFLINE"


class CObj_FA__APP_CTRL : public __IOBJ__STD_TYPE
{
private:
	//---------------------------------------------------------
	CString sObject_Name;

	CCommon_Error__DEF_VARIABLE mERROR__DEF_VAR;

	SCX__CTC__SCH_MATERIAL_CTRL xSCH_MATERIAL_CTRL;


	//---------------------------------------------------------
	//  INTERNAL PROPERTY

	int iINIT__COMM_STS_TYPE;
	int iFLAG__INITIAL_CONTROL_STATE;
	int iFLAG__DEVICE_ID_CONTROL;

	// ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_AUTO_REMOTE_CONNECTION;

	CX__VAR_STRING_CTRL  xCH__FA_USER_REQ;
	CX__VAR_STRING_CTRL  xCH__FA_REQ;

	CX__VAR_STRING_CTRL  xCH__FA_CONNECTION_STATUS;
	CX__VAR_STRING_CTRL  xCH__FA_STATUS;
	CX__VAR_STRING_CTRL  xCH__FA_PRE_STATUS;
	CX__VAR_STRING_CTRL  xCH__FA_STATUS_ID;
	CX__VAR_STRING_CTRL  xCH__FA_PRE_STATUS_ID;

	CX__VAR_STRING_CTRL  xCH__FA_COMM_STATUS;
	CX__VAR_STRING_CTRL  xCH__FA_CONTROL_STATE;

	CX__VAR_STRING_CTRL  xCH__TIME_FROM_HOST_REQ;

	CX__VAR_DIGITAL_CTRL xCH__FA_COMMUNICATION_FLAG;
	CX__VAR_ANALOG_CTRL  xCH__FA_COMMUNICATION_TIME;

	CX__VAR_DIGITAL_CTRL xCH__FA_COMMUNICATION_CTRL;

	CX__VAR_DIGITAL_CTRL xCH__DEFAULT_INITIAL_STATE;
	CX__VAR_DIGITAL_CTRL xCH__DEFAULT_CONTROL_OFFLINE_STATE;

	CX__VAR_DIGITAL_CTRL xCH__INITIAL_CONTROL_STATE;		// LOCAL  REMOTE

	CX__VAR_STRING_CTRL  xCH__TIME_FORMAT_TYPE;

	//.....
	CX__VAR_STRING_CTRL  xCH__EVENT_OFFLINE_ACTIVE_REQ;
	CX__VAR_STRING_CTRL  xCH__EVENT_LOCAL_ACTIVE_REQ;
	CX__VAR_STRING_CTRL  xCH__EVENT_REMOTE_ACTIVE_REQ;

	CX__VAR_STRING_CTRL  xCH__EVENT_OFFLINE_ACTIVE_STATUS;
	CX__VAR_STRING_CTRL  xCH__EVENT_LOCAL_ACTIVE_STATUS;
	CX__VAR_STRING_CTRL  xCH__EVENT_REMOTE_ACTIVE_STATUS;

	//.....
	CX__VAR_STRING_CTRL  xCH__DVID_ECID;
	CX__VAR_STRING_CTRL  xCH__DVID_ECVAL;

	//.....
	CX__VAR_ANALOG_CTRL  xCH__FA_HEARTBEAT_INTERVAL_SEC;

	//.....
	CX__VAR_STRING_CTRL  xCH__TERMINAL_WIN_NAME;
	CX__VAR_STRING_CTRL  xCH__TERMINAL_MSG[CFG__TERMINAL_MSG_SIZE];

	CX__VAR_STRING_CTRL  xCH__TERMINAL_LOG_COUNT;
	CX__VAR_STRING_CTRL  xCH__TERMINAL_LOG_TITLE[CFG__TERMINAL_LOG_SIZE];
	CX__VAR_STRING_CTRL  xCH__TERMINAL_LOG_MSG[CFG__TERMINAL_LOG_SIZE];

	//
	CX__VAR_STRING_CTRL  xCH__TERMINAL_SEND_REQ;
	CX__VAR_STRING_CTRL  xCH__TERMINAL_SEND_MSG;

	//.....
	CX__VAR_STRING_CTRL  xCH__LOOPBACK_TEST_REQ;
	CX__VAR_STRING_CTRL  xCH__LOOPBACK_TEST_MSG;

	CX__VAR_STRING_CTRL  xCH__RECV_SxFy;
	CX__VAR_STRING_CTRL  xCH__SEND_SxFy;

	CX__VAR_DIGITAL_CTRL xCH__ALL_ALARM_REPORT_FLAG;

	//.....
	CX__VAR_DIGITAL_CTRL xCH__LOG_CTRL__FLAG;
	CX__VAR_DIGITAL_CTRL xCH__LOG_CTRL__CTRL_MSG_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__LOG_CTRL__SECSI_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__LOG_CTRL__SECSII_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__LOG_CTRL__S6F1_LOG_FLAG;
	CX__VAR_ANALOG_CTRL  xCH__LOG_CTRL__DATE_SIZE;
	CX__VAR_DIGITAL_CTRL xCH__LOG_CTRL__INTERVAL_MIN_TIME;
	CX__VAR_STRING_CTRL  xCH__LOG_CTRL__PROPERTY_INFO;

	//.....
	CX__VAR_STRING_CTRL  xCH__ENG_CALL__WIN_NAME;
	CX__VAR_STRING_CTRL  xCH__ENG_CALL__TEXT_MSG;
	CX__VAR_STRING_CTRL  xCH__ENG_CALL__EQP_CALL;
	CX__VAR_STRING_CTRL  xCH__ENG_CALL__PRC_CALL;

	//.....
	CX__VAR_ANALOG_CTRL  xCH_CFG__DEVICEID;			// No.   0     32767
	CX__VAR_ANALOG_CTRL  xCH_CFG__T1;				// sec   1.0   60.0	
	CX__VAR_ANALOG_CTRL  xCH_CFG__T2;				// sec   1.0   60.0	
	CX__VAR_ANALOG_CTRL  xCH_CFG__T3;				// sec   1.0   60.0
	CX__VAR_ANALOG_CTRL  xCH_CFG__T4;				// sec   1.0   60.0
	CX__VAR_ANALOG_CTRL  xCH_CFG__T5;				// sec   1.0   60.0
	CX__VAR_ANALOG_CTRL  xCH_CFG__T6;				// sec   1.0   60.0	
	CX__VAR_ANALOG_CTRL  xCH_CFG__T7;				// sec   1.0   60.0
	CX__VAR_ANALOG_CTRL  xCH_CFG__T8;				// sec   1.0   60.0
	CX__VAR_ANALOG_CTRL  xCH_CFG__RETRY_LIMIT;		// num   1.0   10 
	CX__VAR_ANALOG_CTRL  xCH_CFG__LINK_TEST;		// sec   1.0   30

	CX__VAR_DIGITAL_CTRL xCH_CFG__S5Fy_REPLY_CTRL;		// NOT.CTRL  DISABLE  ENABLE 
	CX__VAR_DIGITAL_CTRL xCH_CFG__S6Fy_REPLY_CTRL;		//   "
	CX__VAR_DIGITAL_CTRL xCH_CFG__S10Fy_REPLY_CTRL;		//   "

	//
	CX__VAR_ANALOG_CTRL  xCH_CFG__PMC_SIZE;			// num   1 ~ 10

	//.....
	CX__VAR_STRING_CTRL  xCH__FA_CONNECTION_INFO;
	CX__VAR_STRING_CTRL  xCH__FA_PROPERTY_INFO;
	CX__VAR_STRING_CTRL  xCH__FA_CONNECTION_CHANGE_REQ;

	//
	CX__VAR_DIGITAL_CTRL xCH__RCMD_SYSTEM_PAUSE_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__RCMD_SYSTEM_RESUME_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__RCMD_SYSTEM_END_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__RCMD_SYSTEM_STOP_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__RCMD_SYSTEM_ABORT_FLAG;

	CX__VAR_DIGITAL_CTRL xCH__RCMD_SYSTEM_REMOTE_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__RCMD_SYSTEM_LOCAL_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__RCMD_SYSTEM_OFFLINE_FLAG;

	CX__VAR_DIGITAL_CTRL xCH__RCMD_PTN_CANCEL_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__RCMD_PTN_PAUSE_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__RCMD_PTN_RESUME_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__RCMD_PTN_ABORT_FLAG;

	CX__VAR_DIGITAL_CTRL xCH__RCMD_PM_ENABLE_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__RCMD_PM_DISABLE_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__RCMD_PM_CONTROL_FLAG;

	CX__VAR_DIGITAL_CTRL xCH__RCMD_PMx_LIST[CFG_PM_LIMIT];

	CX__VAR_DIGITAL_CTRL xCH__RCMD_ALARM_BUZZER_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__RCMD_SIGNAL_TOWER_RED_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__RCMD_SIGNAL_TOWER_YELLOW_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__RCMD_SIGNAL_TOWER_GREEN_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__RCMD_SIGNAL_TOWER_BLUE_FLAG;

	//.....
	CX__VAR_STRING_CTRL  sCH__SPOOLING_STATE;

	//
	CX__VAR_DIGITAL_CTRL dCH_ECID__SPOOL_CONTROL;
	CX__VAR_ANALOG_CTRL  aCH_ECID__MAX_SPOOL_TRANSMIT;
	CX__VAR_DIGITAL_CTRL dCH_ECID__OVERWRITE_SPOOL;
	CX__VAR_ANALOG_CTRL  aCH_ECID__MAX_SPOOL_SAVE;

	//
	CX__VAR_STRING_CTRL  sCH_SVID__SPOOL_START_TIME;		// Spool Start Time  :  yyyymmddhhmmss
	CX__VAR_ANALOG_CTRL  aCH_SVID__SPOOL_COUNT_TOTAL;		// Max Spool Transmit
	CX__VAR_STRING_CTRL  sCH_SVID__SPOOL_FULL_TIME;			// Spool Full Time   :  yyyymmddhhmmss
	CX__VAR_ANALOG_CTRL  aCH_SVID__SPOOL_COUNT_ACTUAL;		// Spool Count Actual

	CX__VAR_DIGITAL_CTRL dCH_CFG__S10Fy_TID_CHECK_FLAG;


	// PJOB ...
	CX__VAR_STRING_CTRL  xCH__PJOB_ACTION;
	CX__VAR_STRING_CTRL  xCH__PJOB_NAME;
	CX__VAR_STRING_CTRL  xCH__PJOB_UPDATE_FLAG;

	CX__VAR_DIGITAL_CTRL xCH__AFTER_CST_LOAD_FLAG;

	// CJOB ...
	CX__VAR_STRING_CTRL  xCH__CJOB_ACTION;
	CX__VAR_STRING_CTRL  xCH__CJOB_NAME;
	CX__VAR_STRING_CTRL  xCH__CJOB_UPDATE_FLAG;

	CX__VAR_STRING_CTRL  xCH_SCR__CJOB_START__WIN_NAME[CFG_LP_LIMIT];
	CX__VAR_STRING_CTRL  xCH_SCR__CJOB_START__CJOB_NAME[CFG_LP_LIMIT];

	// CMS ...
	CX__VAR_STRING_CTRL  sCH__CMS_UPDATE_FLAG__LPx[CFG_LP_LIMIT];

	// PMx CEID ...
	int iPMx_SIZE;	
	CString sPMx_OBJ_NAME[CFG_PM_LIMIT];
	//


	//---------------------------------------------------------
	//  EXTERNAL PROPERTY

	CX__VAR_DIGITAL_CTRL xEXT_CH__PMx_CFG_USE[CFG_PM_LIMIT];
	CX__VAR_DIGITAL_CTRL xEXT_CH__PMx_OBJ_STATUS[CFG_PM_LIMIT];
	CX__VAR_DIGITAL_CTRL xEXT_CH__PMx_DOOR_STS[CFG_PM_LIMIT];
	CX__VAR_STRING_CTRL  xEXT_CH__PMx_LIFT_PIN_STS[CFG_PM_LIMIT];
	//


	//---------------------------------------------------------
	void Mon__E30_CTRL(CII_OBJECT__VARIABLE* p_variable);
	void Fnc__TERMINAL_LOG_CTRL(CII_OBJECT__VARIABLE* p_variable, CString& pre_msg, int& log_count);
	void Fnc__HEARTBEAT_CTRL(CII_OBJECT__VARIABLE* p_variable, int& sec_count);

	void Mon__CONTROL_STATE_CTRL(CII_OBJECT__VARIABLE* p_variable);
	void Fnc__SPOOLING_CTRL(CII_OBJECT__VARIABLE* p_variable, int& spool_count);

	void Mon__USER_JOB(CII_OBJECT__VARIABLE* p_variable);
	void Fnc__PJOB_CHECK();
	void Fnc__CJOB_CHECK();

	void Mon__PMx_CEID(CII_OBJECT__VARIABLE* p_variable);
	//


public:
	CObj_FA__APP_CTRL();
	~CObj_FA__APP_CTRL();

	//-------------------------------------------------------------------------
	int __DEFINE__CONTROL_MODE(obj,l_mode);
	int __DEFINE__VERSION_HISTORY(version);

	int __DEFINE__VARIABLE_STD(p_variable);
	int __DEFINE__ALARM(p_alarm);

	int __Define__USER_FUNCTION(CII_DEFINE__FUNCTION *p_fnc_ctrl);

	//-------------------------------------------------------------------------
	int __INITIALIZE__OBJECT(p_variable,p_ext_obj_create);
	int __START__OBJECT();

	//-------------------------------------------------------------------------
	int __CALL__CONTROL_MODE(mode,p_debug,p_variable,p_alarm);
	int __CALL__MONITORING(id,p_variable,p_alarm);

	//-------------------------------------------------------------------------
	int __CLOSE__OBJECT();
};
