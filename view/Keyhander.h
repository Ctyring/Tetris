//
// Created by Lenovo on 2020/11/10.
//

#ifndef MAIN_C_KEYHANDER_H
#define MAIN_C_KEYHANDER_H
#include "..\common\base.h"
/**
 * 定义结构处理默认的方向量
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
 * 按键映射处理
 * @param handler 方向键
 * @param maps 其他键
 * @param len 处理的长度
 */
void keyhandleroperator(defaulthandler *handler, keymapping *maps, int len);
#endif //MAIN_C_KEYHANDER_H
