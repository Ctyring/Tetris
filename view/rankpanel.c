//
// Created by Lenovo on 2020/11/30.
//

#include "rankpanel.h"
Panel* rankpanel_init(){
    Panel* Rankpanel = NULL;
    if(Rankpanel == NULL){
        Rankpanel = panelInit();
    }
    Rankpanel->x = 30;
    Rankpanel->y = 2;
    Rankpanel->width = 49;
    Rankpanel->height = 22;
    Rankpanel->bgcolor = 0xB;
    Rankpanel->color = 0x5;
    return Rankpanel;
}
void readrank(){
    players player[3000];
    players temp;
    int j = 0, i = 0, k = 0;
    FILE* fp;
    fp = fopen("rank.txt","rb");
    while(fscanf(fp,"%s %s %d\n",player[i].pattern,player[i].name,&player[i].score) != EOF) {
        i++;
    }
    int n = i;
    for(i = 0;i<n;i++){
        for(j = i + 1;j<n;j++){
            if(player[i].score < player[j].score){
                temp = player[j];
                player[j] = player[i];
                player[i] = temp;
            }
        }
    }
    i = 0;
    Panel* Rankpanel = NULL;
    Rankpanel = rankpanel_init();
    while(i <= 10 && player[i].score>=0 && player[i].name[0] != '\0'){
        setconsoleposition(Rankpanel->x+1,Rankpanel->y+4+i);
        printf(" %d    %s\t%s",i+1,player[i].pattern,player[i].name);
        setconsoleposition(Rankpanel->x+34,Rankpanel->y+4+i);
        printf("%d",player[i].score);
        i++;
    }
    fclose(fp);
}
void drawrankpanel(){
    Panel* Rankpanel = NULL;
    Rankpanel = rankpanel_init();
    Panel* panel = game_panel_init();
    panel->color = 0x0;
    panel->bgcolor = 0x0;
    drawpanel(panel);
    panel = trailer_panel_init();
    panel->color = 0x0;
    panel->bgcolor = 0x0;
    drawpanel(panel);
    panel = Setting_panel_init();
    panel->color = 0x0;
    panel->bgcolor = 0x0;
    drawpanel(panel);
    if(NULL == Rankpanel){
        Rankpanel = rankpanel_init();
    }
    if(NULL != Rankpanel){
        drawpanel(Rankpanel);
        setconsoleposition(Rankpanel->x+1,Rankpanel->y+1);
        setcolor(Rankpanel->bgcolor<<4|Rankpanel->color);
        printf("排名  模式  \t姓名\t\t分数");
        setconsoleposition(Rankpanel->x+1,Rankpanel->y+4);
        setcolor(Rankpanel->bgcolor << 4 | Rankpanel->color);
        readrank();
    }
}
