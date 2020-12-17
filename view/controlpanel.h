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
    void (*view_game)();//չʾ��Ϸ���
    void (*view_setting_panel)();//չʾ�������
    void (*start_game)();//��ʼ��Ϸ
    void (*view_rangking)();//�����а�
}conpanel_operator;
/**
 * ���������ƺ���
 */
void drawcontrolpanel();
/**
 * ������ƺ���
 * @param panel ���
 * @param view ���
 * @param len �������
 */
void drawviews(Panel * panel , View * view, int len);
/**
 * ���ұ�ѡ�е��������
 * @param view ���
 * @param len �������
 * @param color ��ѡ��ʱ����ɫ
 * @return �����������ţ���1��ʼ��0Ϊ�����ڣ�
 */
int selectview(View * views, int len, int color);
/**
 * �л���ѡ�е����
 * @param views �������
 * @param len �������
 * @param color ��ɫ
 * @param bgcolor ����ɫ
 * @param up_or_down ���ϻ������л�
 * @param set_con Ŀǰѡ�е���������廹�ǿ������
 * @return
 */
void changeselectview(View * views, int len ,int color ,int bgcolor, _Bool up_or_down);
/**
 * �Ϸ������������
 * @param v ��Ӧ���ַ�
 * @return
 */
void* control_panel_up_handler(char v);
/**
 * �·������������
 * @param v ��Ӧ�ַ�
 * @return
 */
void* control_panel_down_handler(char v);
/**
 * �������������
 * @param v ��Ӧ�ַ�
 * @return
 */
void* control_panel_left_handler(char v);
/**
 * �ҷ������������
 * @param v ��Ӧ�ַ�
 * @return
 */
void* control_panel_right_handler(char v);
/**
 * ������尴����
 */
void control_panel_key_bind();
/**
 * ���ұ�ѡ�е�������л���Ӧ�Ĺ���
 * @param len
 */
void viewpanelByselected(int len);
/**
 * �жϵ�ǰѡ�е������ִ����Ӧ�Ĺ���
 */
void enter_key_press(char v);
/**
 * �л�����
 */
void stopgame();
/**
 * �÷֣��ı���������ʾ�ķ���
 */
void getscore();
/**
 * ������Ϸ�ٶȣ����ڿ����Ѷ�
 */
DWORD setspeed();
/**
 * ��ȡ������յ÷ֲ�����÷�
 * @return ������յ÷�
 */
int gscore();
/**
 * ��֪��ǰ��ģʽ
 * @return
 */
int getpattern();
Panel* Control_panel_init();
#endif //MAIN_C_CONTROLPANEL_H
