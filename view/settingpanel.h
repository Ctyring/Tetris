//
// Created by Lenovo on 2020/11/11.
//

#ifndef MAIN_C_SETTINGPANEL_H
#define MAIN_C_SETTINGPANEL_H
#include "panel.h"
#include "controlpanel.h"
/**
 * �������ĳ�ʼ�����������������Ƶ�����趨
 */
Panel* Setting_panel_init();
/**
 * �������Ļ���
 */
void drawSettingpanel();
/**
 * �����ǰѡ�е��ǿ�����������������л�Ϊ�������
 * �����ǰѡ�е���������壬�л�Ϊѡ�п��������������
 * @param set_con �鿴ѡ�е����ĸ���λ�������õĻ�������
 */
void changpanel(_Bool set_con,View* vi,Panel*panel);
/**
 * �жϵ�ǰѡ�е���庯��
 * @param set xѡ��֮�����ֵ��ı䣬1Ϊ������壬0Ϊ�������
 * @return
 */
int set_con();
/**
 * ���������·������
 */
void settingpanel_op_down();
/**
 * ���������Ϸ������
 */
void settingpanel_op_up();
/**
 * �ı���Ϸģʽ
 */
int Change_patterns();
#endif //MAIN_C_SETTINGPANEL_H
