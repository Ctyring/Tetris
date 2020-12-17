//
// Created by CTY on 2020/11/4 22:04.
// QQ ��173479693
// ������
//
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#ifndef TETRIS_BASE_H
#define TETRIS_BASE_H
/**
 * ���ô��ڱ���
 */
void setTitle(char* Title);
/**
 * ���ô��ڴ�С
 * @param width ���
 * @param height �߶�
 */
void setwindowsize(int width, int height);
void setconsoleposition(int x, int y);
/**
 * ��ɫ���ƺ���
 * @param color ��ɫ
 *��ɫ����������ʮ����������ָ�� -- ��һ��
��Ӧ�ڱ������ڶ�����Ӧ��ǰ����ÿ������
����Ϊ�����κ�ֵ:

    0 = ��ɫ       8 = ��ɫ
    1 = ��ɫ       9 = ����ɫ
    2 = ��ɫ       A = ����ɫ
    3 = ǳ��ɫ     B = ��ǳ��ɫ
    4 = ��ɫ       C = ����ɫ
    5 = ��ɫ       D = ����ɫ
    6 = ��ɫ       E = ����ɫ
    7 = ��ɫ       F = ����ɫ
 */
void setcolor(int color);
/**
 * ���ƺ���
 * @param x ��ʼ������
 * @param y ��ʼ������
 * @param letter �ߵ�����
 * @param color ��ɫ
 * @param length ����
 */
void drawHline(int x, int y, char letter, int color, int length);
/**
 * ��������
 * @param x ��ʼ������
 * @param y ��ʼ������
 * @param letter �ߵ�����
 * @param color ��ɫ
 * @param length ����
 */
void drawVline(int x, int y, int letter, int color, int height);
/**
 * �ı����
 * @param x ��ʼ������
 * @param y ��ʼ������
 * @param height ��ʼ�߶�
 * @param width ��ʼ���
 * @param letter �������
 * @param color �����ɫ
 */
void filltext(int x,int y, int height, int width, int letter, int color);
/**
 * ��ӡ�ı�
 * @param text �ı�����
 * @param size ���ݿ��
 */
void printftext(char*text,int size);
/**
 * ��ȡ�ַ�
 * @return
 */
char readchar();
void disableCurrsor();
#endif //TETRIS_BASE_H
