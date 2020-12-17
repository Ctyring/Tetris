//
// Created by Lenovo on 2020/11/8.
//

#ifndef MAIN_C_PANEL_H
#define MAIN_C_PANEL_H
#include <stddef.h>
#include "..\common\base.h"
/**
 * ��������
 */
typedef struct Panel{
    int x;//��ʼ������
    int y;//��ʼ������
    int bgcolor;//����ɫ
    int color;//��ɫ
    int width;//���
    int height;//�߶�
}Panel;
/**
 * �������
 */
typedef struct View{
    int x;//������
    int y;//������
    int color;//��ɫ
    int bgcolor;//����ɫ
    char name[100];//����
    int size;//���
    _Bool selectable;//�Ƿ��ѡ��
}View;
/**
 * ����ʼ������
 */
Panel* panelInit();
/**
 * �����ƺ���
 */
void drawpanel(Panel * panel);

#endif //MAIN_C_PANEL_H
