//
// Created by CTY on 2020/11/4 22:04.
// QQ ：173479693
// 描述：
//
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#ifndef TETRIS_BASE_H
#define TETRIS_BASE_H
/**
 * 设置窗口标题
 */
void setTitle(char* Title);
/**
 * 设置窗口大小
 * @param width 宽度
 * @param height 高度
 */
void setwindowsize(int width, int height);
void setconsoleposition(int x, int y);
/**
 * 颜色绘制函数
 * @param color 颜色
 *颜色属性由两个十六进制数字指定 -- 第一个
对应于背景，第二个对应于前景。每个数字
可以为以下任何值:

    0 = 黑色       8 = 灰色
    1 = 蓝色       9 = 淡蓝色
    2 = 绿色       A = 淡绿色
    3 = 浅绿色     B = 淡浅绿色
    4 = 红色       C = 淡红色
    5 = 紫色       D = 淡紫色
    6 = 黄色       E = 淡黄色
    7 = 白色       F = 亮白色
 */
void setcolor(int color);
/**
 * 绘制横线
 * @param x 起始横坐标
 * @param y 起始纵坐标
 * @param letter 线的类型
 * @param color 颜色
 * @param length 长度
 */
void drawHline(int x, int y, char letter, int color, int length);
/**
 * 绘制竖线
 * @param x 起始横坐标
 * @param y 起始纵坐标
 * @param letter 线的类型
 * @param color 颜色
 * @param length 长度
 */
void drawVline(int x, int y, int letter, int color, int height);
/**
 * 文本填充
 * @param x 起始横坐标
 * @param y 起始纵坐标
 * @param height 起始高度
 * @param width 起始宽度
 * @param letter 填充类型
 * @param color 填充颜色
 */
void filltext(int x,int y, int height, int width, int letter, int color);
/**
 * 打印文本
 * @param text 文本内容
 * @param size 内容宽度
 */
void printftext(char*text,int size);
/**
 * 读取字符
 * @return
 */
char readchar();
void disableCurrsor();
#endif //TETRIS_BASE_H
