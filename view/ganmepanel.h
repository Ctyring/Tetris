//
// Created by Lenovo on 2020/11/13.
//

#ifndef MAIN_C_GANMEPANEL_H
#define MAIN_C_GANMEPANEL_H
#include "panel.h"
#include "..\common\base.h"
#include "..\data\gamedata.h"
#include "trailerpanel.h"
#include "rankpanel.h"
/**
 * 游戏面板的初始化
 */
Panel* game_panel_init();
/**
 * 游戏面板的绘制
 */
void drawgamepanel();
#endif //MAIN_C_GANMEPANEL_H
