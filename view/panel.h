//
// Created by Lenovo on 2020/11/8.
//

#ifndef MAIN_C_PANEL_H
#define MAIN_C_PANEL_H
#include <stddef.h>
#include "..\common\base.h"
/**
 * 面板的属性
 */
typedef struct Panel{
    int x;//起始横坐标
    int y;//起始纵坐标
    int bgcolor;//背景色
    int color;//颜色
    int width;//宽度
    int height;//高度
}Panel;
/**
 * 组件属性
 */
typedef struct View{
    int x;//横坐标
    int y;//纵坐标
    int color;//颜色
    int bgcolor;//背景色
    char name[100];//名字
    int size;//宽度
    _Bool selectable;//是否可选中
}View;
/**
 * 面板初始化函数
 */
Panel* panelInit();
/**
 * 面板绘制函数
 */
void drawpanel(Panel * panel);

#endif //MAIN_C_PANEL_H
