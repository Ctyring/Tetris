//
// Created by Lenovo on 2020/11/8.
//

#include "panel.h"
Panel* panelInit(){
    Panel* panel = (Panel*)malloc(sizeof(Panel));
    panel->x = 10;
    panel->y = 10;
    panel->color = 0x9;
    panel->bgcolor = 0xE;
    panel->width = 10;
    panel->height = 10;
    return panel;
}

void drawpanel(Panel *panel) {
    filltext(panel->x,panel->y,panel->height,panel->width,' ',panel->bgcolor<<4|panel->color);
}
