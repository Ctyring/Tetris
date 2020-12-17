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
 * ���ҵ�ǰҪ�����ķ�������͵��±�
 * @param diamonds ����ķ���
 * @return
 */
 int finddiamond(Diamond* diamond);
/**
 * ���ƴ���ķ���
 * @param diamonds ����ķ���
 */
void drawdiamond(Diamond* diamond, Panel* panel, int color);
/**
 * ��ʼ��һ��������飬���л��ƣ�������
 */
Diamond* diamond_init();
#endif //MAIN_C_TRAILERPANEL_H
