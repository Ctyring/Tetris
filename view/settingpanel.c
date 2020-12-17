//
// Created by Lenovo on 2020/11/11.
//

#include "settingpanel.h"
#include "controlpanel.h"
Panel * Settingpanel = NULL;
int set = 1;
View Settingpanel_views[] = {
        {5,8,0x5,0xB,"模式：简单",100,1},
        {5,2,0x5,0xB,"背景音乐（开/关）：开",100,0},
        {5,5,0x5,0xB,"音   效（开/关）：开",100,0},
        {5,11,0x5,0xB,"背景：0xF",100,0},
};
Panel* Setting_panel_init() {
    if(Settingpanel == NULL){
        Settingpanel = panelInit();
    }
    Settingpanel->x = 30;
    Settingpanel->y = 2;
    Settingpanel->width = 36;
    Settingpanel->height = 18;
    Settingpanel->bgcolor = 0xB;
    Settingpanel->color = 0x5;
    return Settingpanel;
}
void drawSettingpanel() {
    Panel* panel = rankpanel_init();
    panel->color = 0x0;
    panel->bgcolor = 0x0;
    drawpanel(panel);
    panel = trailer_panel_init();
    panel->color = 0x0;
    panel->bgcolor = 0x0;
    drawpanel(panel);
    panel = game_panel_init();
    panel->color = 0x0;
    panel->bgcolor = 0x0;
    drawpanel(panel);
    Setting_panel_init();
    if(NULL == Settingpanel){
        Settingpanel = Setting_panel_init();
    }
    if(NULL != Settingpanel){
        drawpanel(Settingpanel);
        int len = sizeof(Settingpanel_views)/sizeof(View);
        drawviews(Settingpanel,Settingpanel_views,len);
    }
}

void changpanel(_Bool set_con,View* vi,Panel*panel) {
    int len = sizeof(Settingpanel_views)/sizeof(View);
    if(set_con){
        vi->color = panel->color;
        vi->bgcolor = panel->bgcolor;
        Settingpanel_views[0].color = Settingpanel->bgcolor;
        Settingpanel_views[0].bgcolor = Settingpanel->color;
    }
    else{
        int id = selectview(Settingpanel_views,len,Settingpanel->bgcolor);
        vi = &Settingpanel_views[id];
        vi->color = Settingpanel->color;
        vi->bgcolor = Settingpanel->bgcolor;
    }
    drawviews(Settingpanel,Settingpanel_views,len);
    if(set == 1){
        set = 0;
    }
    else{
        set = 1;
    }
}

int set_con() {
    if(set == 1)return 1;
    else return 0;
}

void settingpanel_op_down() {
    int len = sizeof(Settingpanel_views)/sizeof(View);
    //changeselectview(Settingpanel_views,len,Settingpanel->bgcolor,Settingpanel->color,1);
    drawviews(Settingpanel,Settingpanel_views,len);
    viewpanelByselected(len);
}

void settingpanel_op_up() {
    int len = sizeof(Settingpanel_views)/sizeof(View);
    //changeselectview(Settingpanel_views,len,Settingpanel->bgcolor,Settingpanel->color,0);
    drawviews(Settingpanel,Settingpanel_views,len);
    viewpanelByselected(len);
}

int Change_patterns() {
    int len = sizeof(Settingpanel_views)/sizeof(View);
    int id = selectview(Settingpanel_views,len,Settingpanel->bgcolor);
    if(id == 0){
        if(strcmp(Settingpanel_views[id].name,"模式：困难") == 0){
            strcpy(Settingpanel_views[id].name,"模式：简单");
            drawSettingpanel();
            return 0;
        }
        strcpy(Settingpanel_views[id].name,"模式：困难");
        drawSettingpanel();
        return 1;
    }
    return 0;
}
