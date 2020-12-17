//
// Created by Lenovo on 2020/11/15.
//

#ifndef MAIN_C_TRAILERPANEL_H
#define MAIN_C_TRAILERPANEL_H
#include "..\data\gamedata.h"
#include "panel.h"
#include <time.h>
Panel* trailer_panel_init();
void drawtrailerpanel();
/**
 * 查找当前要操作的方块的类型的下标
 * @param diamonds 传入的方块
 * @return
 */
 int finddiamond(Diamond* diamond);
/**
 * 绘制传入的方块
 * @param diamonds 传入的方块
 */
void drawdiamond(Diamond* diamond, Panel* panel, int color);
/**
 * 初始化一个随机方块，进行绘制，并返回
 */
Diamond* diamond_init();
#endif //MAIN_C_TRAILERPANEL_H
