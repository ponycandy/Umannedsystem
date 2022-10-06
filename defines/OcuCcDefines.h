#pragma once

#include <QtGlobal>
#include <QMetaType>
#include <QByteArray>

namespace OcuCcDefines {

//!********************************************************************************
//!* ucs view kind                                                                *
//!********************************************************************************

typedef enum {
    OCU_VIEW_KIND_CC_NONE = 0,
    OCU_VIEW_KIND_CC_MAINVIEW_TASK,           //! 指控主界面(暂时用不到)
    OCU_VIEW_KIND_CC_QXXLC_TASK,              //! 轻型巡逻车
    OCU_VIEW_KIND_CC_XXDZZ_TASK,              //! 信息电子战车
    OCU_VIEW_KIND_CC_ZXLDC_TASK,              //! 中型履带车
    OCU_VIEW_KIND_CC_ZXLSC_TASK,              //! 中型轮式车
    OCU_VIEW_KIND_FC_QXXLC_TASK,              //! 轻型巡逻车火控
    OCU_VIEW_KIND_FC_XXDZZ_TASK,              //! 信息电子战车火控
    OCU_VIEW_KIND_FC_ZXLDC_TASK,              //! 中型履带车火控
    OCU_VIEW_KIND_FC_ZXLSC_TASK,              //! 中型轮式车火控
    OCU_VIEW_KIND_CC_LIST_TASK,               //! 任务列表界面（暂时用不到）
    OCU_VIEW_KIND_CC_DETALED_INFO_TASK,       //! 详细信息界面
    OCU_VIEW_KIND_CC_ACTION_INFO_TASK,        //! 行动信息

} OcuCcViewKind;
}

