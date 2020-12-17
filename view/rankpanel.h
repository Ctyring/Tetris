//
// Created by Lenovo on 2020/11/30.
//

#ifndef MAIN_C_RANKPANEL_H
#define MAIN_C_RANKPANEL_H
#include "panel.h"
#include "..\data\gamedata.h"
#include "ganmepanel.h"
#include "controlpanel.h"
/**
 * 初始化排行榜面板
 */
Panel* rankpanel_init();
/**
 * 读取排行榜前十名的信息
 */
void readrank();
void drawrankpanel();
#endif //MAIN_C_RANKPANEL_H
