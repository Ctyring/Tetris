//
// Created by Lenovo on 2020/11/17.
//

#ifndef MAIN_C_GAMECONTROL_H
#define MAIN_C_GAMECONTROL_H
#include "..\data\gamedata.h"
#include "..\view\trailerpanel.h"
#include "..\view\settingpanel.h"
/**
 * ��trailerpanel�е�diamond���Ƶ���Ϸ����У�������Ҫ���Ƶ�diamond��ָ��
 * @return
 */
Diamond* show_me_diamond();
/**
 * �ı䷽���Ϳɫ���겢����
 * @param d
 * @return
 */
Diamond* change_diamond_status(Diamond* d);
/**
 * �������ۼ��������ƶ�����
 * @param diamond
 */
void cleardiamond(Diamond* diamond, Panel* gamepanel);
/**
 * �ı䷽�����̬
 * @param d
 */
void change_diamond();
/**
 * �ƶ�����
 * @param d Ҫ�ƶ��ķ���
 * @param b �ƶ��ķ��� ��Ϊ��
 */
void movediamond(_Bool b);
/**
 * ������½�
 */
void diamond_down();
/**
 * ���Ʒ����ֹͣ
 * �ѷ���װ���
 */
BOOL diamond_stop();
/**
 * ���������ڿ⵱�еķ��飬����ˢ��
 */
void drawhouse();
/**
 * �жϵ÷֣����У�������
 * @param k Ҫ�жϵ���
 */
void getit(int k);
/**
 * �������
 */
BOOL dead_check();
/**
 * ����֮����շ����
 */
void cleardiamondhouse();
#endif //MAIN_C_GAMECONTROL_H
