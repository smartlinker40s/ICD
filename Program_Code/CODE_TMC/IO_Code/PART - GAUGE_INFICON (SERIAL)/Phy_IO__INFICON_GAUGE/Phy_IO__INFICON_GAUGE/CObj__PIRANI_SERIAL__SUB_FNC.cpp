#include "StdAfx.h"
#include "CObj__PIRANI_SERIAL.h"

#include "math.h"


// ...
void CObj__PIRANI_SERIAL::
Fnc__DRV_LOG_OF_MSG(const CString& log_msg)
{
	xDRV_LOG_CTRL->WRITE__LOG(log_msg);
}
void CObj__PIRANI_SERIAL::
Fnc__DRV_LOG_OF_DATA_ERROR()
{
	CString log_msg = " * Data Size Error !";

	xDRV_LOG_CTRL->WRITE__LOG(log_msg);
}
