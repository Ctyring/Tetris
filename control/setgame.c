//
// Created by Lenovo on 2020/11/30.
//

#include "setgame.h"
int rank(players player){
    FILE *fp;
    fp = fopen("rank.txt","a");
    fprintf(fp,"%s %s %d\n",player.pattern,player.name,player.score);
    fclose(fp);
}
void startgame() {
    cleardiamondhouse();
    drawgamepanel();
    players player;
    int n = getpattern();
    if(n == 1){
        strcpy(player.pattern,"困难");
    }
    else{
        strcpy(player.pattern,"简单");
    }
    Panel* panel = game_panel_init();
    setconsoleposition((panel->x+panel->width)/2+9,(panel->y+panel->height)/2);
    printf("请输入玩家姓名：");
    scanf("%s",player.name);
    drawgamepanel();
    show_me_diamond();
    DWORD speed;
    for(;;){
        control_panel_key_bind();
        diamond_stop();
        readchar();
        diamond_down();
        speed = setspeed();
        Sleep(speed);
        if(dead_check()){
            player.score = gscore();
            rank(player);
            break;
        }
    }
}

void gameready() {
    setTitle("俄罗斯方块");
    setwindowsize(89,33);
    disableCurrsor();
    drawcontrolpanel();
    drawgamepanel();
    for(;;){
        control_panel_key_bind();
        readchar();
        Sleep(20);
    }
    getchar();
}