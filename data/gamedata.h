//
// Created by Lenovo on 2020/11/15.
//

#ifndef MAIN_C_GAMEDATA_H
#define MAIN_C_GAMEDATA_H
typedef struct diamond_type{
    char name[300]; //方块的名字
    int x; //当前坐标
    int y;//当前坐标
    int n1;
    int m1;
    int n2;
    int m2;
    int n3;
    int m3;
    int status;//当前状态，一开始为1，共4个状态
    int color;//方块的颜色
}Diamond;
typedef struct warehouse{
    int color;
    int c; //是否有方块
}warehouse;
typedef struct players{
    char name[300];
    char pattern[300];
    int  score;
}players;
#endif //MAIN_C_GAMEDATA_H
