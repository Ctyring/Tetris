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
 * ��ʼ�����а����
 */
Panel* rankpanel_init();
/**
 * ��ȡ���а�ǰʮ������Ϣ
 */
void readrank();
void drawrankpanel();
#endif //MAIN_C_RANKPANEL_H
