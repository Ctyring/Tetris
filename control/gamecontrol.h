//
// Created by Lenovo on 2020/11/17.
//

#ifndef MAIN_C_GAMECONTROL_H
#define MAIN_C_GAMECONTROL_H
#include "..\data\gamedata.h"
#include "..\view\trailerpanel.h"
#include "..\view\settingpanel.h"
/**
 * 将trailerpanel中的diamond绘制到游戏面板中，并返回要控制的diamond的指针
 * @return
 */
Diamond* show_me_diamond();
/**
 * 改变方块的涂色坐标并返回
 * @param d
 * @return
 */
Diamond* change_diamond_status(Diamond* d);
/**
 * 清除方块痕迹，用于移动过程
 * @param diamond
 */
void cleardiamond(Diamond* diamond, Panel* gamepanel);
/**
 * 改变方块的形态
 * @param d
 */
void change_diamond();
/**
 * 移动方块
 * @param d 要移动的方块
 * @param b 移动的方向 真为左
 */
void movediamond(_Bool b);
/**
 * 方块的下降
 */
void diamond_down();
/**
 * 控制方块的停止
 * 把方块装入库
 */
BOOL diamond_stop();
/**
 * 绘制所有在库当中的方块，用于刷新
 */
void drawhouse();
/**
 * 判断得分，消行，并下落
 * @param k 要判断的行
 */
void getit(int k);
/**
 * 死亡检查
 */
BOOL dead_check();
/**
 * 死亡之后清空方块库
 */
void cleardiamondhouse();
#endif //MAIN_C_GAMECONTROL_H
