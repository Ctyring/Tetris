//
// Created by Lenovo on 2020/11/13.
//

#include "ganmepanel.h"
Panel* gamepanel = NULL;
Panel* game_panel_init() {
    if(gamepanel == NULL){
        gamepanel = panelInit();
    }
    gamepanel->x = 30;
    gamepanel->y = 2;
    gamepanel->color = 0xF;
    gamepanel->bgcolor = 0xF;
    gamepanel->width = 32;
    gamepanel->height = 27;
    return gamepanel;
}
void drawgamepanel() {
    Panel* panel = rankpanel_init();
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
    gamepanel = game_panel_init();
    drawtrailerpanel();
    drawpanel(gamepanel);
    drawHline(gamepanel->x,gamepanel->y+4,'-',gamepanel->bgcolor<<4|0x4,gamepanel->width);
}
