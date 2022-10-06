/******************************************************************************
* File:     XtzkxDefines.h
* Author:   liziqiang
* Company:  xinchuanhui
* Time      2021-07-01
******************************************************************************/
#pragma once

#include <QtGlobal>


namespace XtzkxDefines {

//!************************************************************************
//!* xtzkx view kind                                                        *
//!************************************************************************

typedef enum {
    XTZKX_VIEW_KIND_NONE = 0,
    XTZKX_VIEW_KIND_COMMAND_CONTROL_TASK_INFO,
    XTZKX_VIEW_KIND_COMMAND_CONTROL_TARGET_INFO,
    XTZKX_VIEW_KIND_COMMAND_CONTROL_TASK_EXECUTE_INFO,
    XTZKX_VIEW_KIND_COMMAND_CONTROL_INVESTIGATION_INFO,
    XTZKX_VIEW_KIND_COMMAND_CONTROL_SITUATION_INFO,
    XTZKX_VIEW_KIND_COMMAND_CONTROL_PERMISSION,
} XtzkxViewKind;


}

