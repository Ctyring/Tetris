//
// Created by Lenovo on 2020/11/10.
//

#ifndef MAIN_C_KEYHANDER_H
#define MAIN_C_KEYHANDER_H
#include "..\common\base.h"
/**
 * ����ṹ����Ĭ�ϵķ�����
 */
typedef struct defaulthandle{
    void( *up)(char);
    void( *down)(char);
    void( *left)(char);
    void( *right)(char);
}defaulthandler;
typedef  struct keymapping{
    char key;
    void(*keyhandler)(char);
}keymapping;
/**
 * ����ӳ�䴦��
 * @param handler �����
 * @param maps ������
 * @param len ����ĳ���
 */
void keyhandleroperator(defaulthandler *handler, keymapping *maps, int len);
#endif //MAIN_C_KEYHANDER_H
