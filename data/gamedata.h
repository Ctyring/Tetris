//
// Created by Lenovo on 2020/11/15.
//

#ifndef MAIN_C_GAMEDATA_H
#define MAIN_C_GAMEDATA_H
typedef struct diamond_type{
    char name[300]; //���������
    int x; //��ǰ����
    int y;//��ǰ����
    int n1;
    int m1;
    int n2;
    int m2;
    int n3;
    int m3;
    int status;//��ǰ״̬��һ��ʼΪ1����4��״̬
    int color;//�������ɫ
}Diamond;
typedef struct warehouse{
    int color;
    int c; //�Ƿ��з���
}warehouse;
typedef struct players{
    char name[300];
    char pattern[300];
    int  score;
}players;
#endif //MAIN_C_GAMEDATA_H
