//
// Created by Lenovo on 2020/11/9.
//

#include "controlpanel.h"
//初始化控制面板
Panel *controlpanel = NULL;
//定义组件相关属性
int score = 0;
int readygame = 0;
int n = 0;
View views[] = {
        {3,3,0xF,0x9,"分数：",100,0},
        {3,8,0xF,0x9,"排行榜",100,1},
        {3,13,0x9,0xF,"游戏",100,1},
        {3,18,0xF,0x9,"设置",100,1}
};
//conpanel_operator *conpanel_op = NULL;
void viewpanelByselected(int len);
void drawviews(Panel *panel, View *view, int len) {
    for(int i = 0 ; i < len; i++){
        View* t = view + i;
        int x = panel->x + t->x;
        int y = panel->y + t->y;
        setconsoleposition(x,y);
        setcolor(t->bgcolor << 4 | t->color);
        if(i == 0 && strcmp((t+1)->name,"排行榜") == 0){
            printf("分数: %d",score);
        }
        else {
            printftext(t->name, t->size);
        }
    }
}
void drawcontrolpanel() {
    if(controlpanel == NULL){
        controlpanel =panelInit();
        controlpanel->x = 10;
        controlpanel->y = 2;
        controlpanel->color = 0xF;
        controlpanel->bgcolor = 0x9;
        controlpanel->width = 15;
        controlpanel->height = 23;
    }
    drawpanel(controlpanel);
    int l = sizeof(views)/sizeof(View);
    drawviews(controlpanel,views,l);
}

int selectview(View *view, int len, int color) {
    for(int i = 0 ; i < len; i++){
        View * t = view + i;
        if(t->color == color){
            return i;
        }
    }
    return -1;
}

void changeselectview(View *views, int len, int color, int bgcolor, _Bool up_or_down) {
    int selectid = selectview(views,len,color);
    View *selectview = views + selectid;
    selectview->color = bgcolor;
    selectview->bgcolor = color;
    View *nextSelected = NULL;
    if (up_or_down) {
        for (int i = selectid + 1; i < len + selectid; i++) {
            View * v = views + (i % len);
            if (v->selectable == 1) {
                nextSelected = v;
                break;
            }
        }
    } else {
        for (int i = selectid + len - 1; i > 0; i--) {
            View *v = views + (i % len) ;
            if (v->selectable == 1) {
                nextSelected = v;
                break;
            }
        }
    }

    if (nextSelected != NULL) {
        //修改下一个被选中组件的颜色
        nextSelected->color = color;
        nextSelected->bgcolor = bgcolor;
    }
}
void* control_panel_up_handler(char v){
    if(readygame == 0){
        if(set_con()) {
            int len = sizeof(views) / sizeof(View);
            changeselectview(views, len, controlpanel->bgcolor, controlpanel->color, 0);
            drawviews(controlpanel, views, len);
            viewpanelByselected(len);
        }
        else{
            settingpanel_op_up();
        }
    }
    else{
        change_diamond();
    }
}
void* control_panel_down_handler(char v){
    if(!readygame){
        if(set_con()) {
            int len = sizeof(views) / sizeof(View);
            changeselectview(views, len, controlpanel->bgcolor, controlpanel->color, 1);
            drawviews(controlpanel, views, len);
            viewpanelByselected(len);
        }

    else{
        settingpanel_op_down();
    }
}}
void *control_panel_right_handler(char v) {
    if(readygame == 1){
        movediamond(0);
    }
    else {
        int len = sizeof(views) / sizeof(View);
        int id = selectview(views, len, controlpanel->bgcolor);
        View *vi = &views[id];
        if (strcmp(vi->name, "设置") == 0) {
            changpanel(1, vi, controlpanel);
        }
        drawviews(controlpanel, views, len);
    }
}
void *control_panel_left_handler(char v) {
    if(readygame == 1){
        movediamond(1);
    }
    else{
        if(set_con()){
            return NULL;
        }
            View* vi = NULL;
        changpanel(0,vi,controlpanel);
        int len = sizeof(views)/sizeof(View);
        vi = &views[3];
        vi->color = controlpanel->bgcolor;
        vi->bgcolor = controlpanel->color;
        drawviews(controlpanel,views,len);
    }
    return NULL;
}
void enter_key_press(char v) {
    int len = sizeof(views)/sizeof(View);
    int id = selectview(views,len,controlpanel->bgcolor);
    if(id == 2){
        if(readygame == 0){
            readygame = 1;
            startgame();
        }
    }
    if(id == -1){
        n = Change_patterns();
    }
}
void control_panel_key_bind() {
    defaulthandler hander = {control_panel_up_handler,control_panel_down_handler,control_panel_left_handler,control_panel_right_handler};
    keymapping mappings [] = {
            {13,enter_key_press}
    };
    int len = sizeof(mappings)/sizeof(keymapping);
    keyhandleroperator(&hander,mappings,len);
}

void viewpanelByselected(int len) {
        int queryID = selectview(views, len, controlpanel->bgcolor);
        View* v = &views[queryID];
        if (strcmp(v->name, "游戏") == 0) {
            drawgamepanel();
        }
        else if (strcmp(v->name, "设置") == 0) {
            drawSettingpanel();
        }
        else if(strcmp(v->name,"排行榜") == 0){
            drawrankpanel();
        }
}

void stopgame() {
    if(dead_check()){
        readygame = 0;
    }
}

void getscore() {
    score += 5;
    drawcontrolpanel();
}

DWORD setspeed() {
    if(n == 0){
    if(400 - score * 2 >= 120){
        return 400 - score * 2;
    }
    else{
        return 120;
    }
    }
    else{
        if(300 - score * 2 >= 80){
            return 300 - score * 2;
        }
        else{
            return 80;
        }
    }
}

int gscore() {
    int t = score;
    score = 0;
    return t;
}

int getpattern() {
    return n;
}
