//
// Created by Lenovo on 2020/11/9.
//

#ifndef MAIN_C_CONTROLPANEL_H
#define MAIN_C_CONTROLPANEL_H
#include "panel.h"
#include "Keyhander.h"
#include "settingpanel.h"
#include "ganmepanel.h"
#include "..\control\gamecontrol.h"
#include "..\control\setgame.h"
#include "rankpanel.h"
typedef  struct conpanel_operator{
    void (*view_game)();//展示游戏面板
    void (*view_setting_panel)();//展示设置面板
    void (*start_game)();//开始游戏
    void (*view_rangking)();//打开排行榜
}conpanel_operator;
/**
 * 控制面板绘制函数
 */
void drawcontrolpanel();
/**
 * 组件绘制函数
 * @param panel 面板
 * @param view 组件
 * @param len 组件个数
 */
void drawviews(Panel * panel , View * view, int len);
/**
 * 查找被选中的组件函数
 * @param view 组件
 * @param len 组件个数
 * @param color 被选中时的颜色
 * @return 返回组件的序号（从1开始，0为不存在）
 */
int selectview(View * views, int len, int color);
/**
 * 切换被选中的组件
 * @param views 组件集合
 * @param len 组件数量
 * @param color 颜色
 * @param bgcolor 背景色
 * @param up_or_down 向上或向下切换
 * @param set_con 目前选中的是设置面板还是控制面板
 * @return
 */
void changeselectview(View * views, int len ,int color ,int bgcolor, _Bool up_or_down);
/**
 * 上方向键操作函数
 * @param v 对应的字符
 * @return
 */
void* control_panel_up_handler(char v);
/**
 * 下方向键操作函数
 * @param v 对应字符
 * @return
 */
void* control_panel_down_handler(char v);
/**
 * 左方向键操作函数
 * @param v 对应字符
 * @return
 */
void* control_panel_left_handler(char v);
/**
 * 右方向键操作函数
 * @param v 对应字符
 * @return
 */
void* control_panel_right_handler(char v);
/**
 * 基础面板按键绑定
 */
void control_panel_key_bind();
/**
 * 查找备选中的组件并切换相应的功能
 * @param len
 */
void viewpanelByselected(int len);
/**
 * 判断当前选中的组件，执行相应的功能
 */
void enter_key_press(char v);
/**
 * 切换控制
 */
void stopgame();
/**
 * 得分，改变控制面板显示的分数
 */
void getscore();
/**
 * 调整游戏速度，用于控制难度
 */
DWORD setspeed();
/**
 * 获取玩家最终得分并清零得分
 * @return 玩家最终得分
 */
int gscore();
/**
 * 得知当前的模式
 * @return
 */
int getpattern();
Panel* Control_panel_init();
#endif //MAIN_C_CONTROLPANEL_H
