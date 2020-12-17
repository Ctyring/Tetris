//
// Created by Lenovo on 2020/11/11.
//

#ifndef MAIN_C_SETTINGPANEL_H
#define MAIN_C_SETTINGPANEL_H
#include "panel.h"
#include "controlpanel.h"
/**
 * 设置面板的初始化，进行设置面板绘制的相关设定
 */
Panel* Setting_panel_init();
/**
 * 设置面板的绘制
 */
void drawSettingpanel();
/**
 * 如果当前选中的是控制面板的设置组件，切换为设置面板
 * 如果当前选中的是设置面板，切换为选中控制面板的设置组件
 * @param set_con 查看选中的是哪个部位，是设置的话返回真
 */
void changpanel(_Bool set_con,View* vi,Panel*panel);
/**
 * 判断当前选中的面板函数
 * @param set x选中之后这个值会改变，1为控制面板，0为设置面板
 * @return
 */
int set_con();
/**
 * 设置面板的下方向操作
 */
void settingpanel_op_down();
/**
 * 设置面板的上方向操作
 */
void settingpanel_op_up();
/**
 * 改变游戏模式
 */
int Change_patterns();
#endif //MAIN_C_SETTINGPANEL_H
