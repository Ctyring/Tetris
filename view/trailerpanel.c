//
// Created by Lenovo on 2020/11/15.
//

#include "trailerpanel.h"
Diamond diamonds[] = {
        {"A",9,4,9,3,9,5,9,6,1},
        {"B",9,4,11,4,9,5,11,5,1},
        {"C",9,4,7,4,9,5,11,5,1},
        {"D",9,4,7,5,9,5,11,4,1},
        {"E",9,4,9,3,9,5,11,5,1},
        {"F",9,4,9,3,9,5,7,5,1},
        {"G",9,5,9,4,7,5,11,5,1}
};
Panel* trailer_panel = NULL;
Panel* trailer_panel_init() {
    if(trailer_panel == NULL){
        trailer_panel = panelInit();
    }
    trailer_panel->x = 65;
    trailer_panel->y = 2;
    trailer_panel->color = 0xF;
    trailer_panel->bgcolor = 0xF;
    trailer_panel->width = 20;
    trailer_panel->height = 10;
    return trailer_panel;
}
void drawtrailerpanel() {
    trailer_panel = trailer_panel_init();
    drawpanel(trailer_panel);
}
int finddiamond(Diamond *diamond) {
    int l = sizeof (diamonds) / sizeof(Diamond);
    for(int i = 0 ; i < l; i++){
        if(strcmp(diamond->name,diamonds[i].name) == 0){
            return i;
        }
    }
    return -1;
}
void drawdiamond(Diamond *diamond,Panel* panel, int color) {
    int ID = finddiamond(diamond);
    setcolor(panel->bgcolor<<4|color);
    if(ID == 0){
        setconsoleposition(panel->x + diamond->n1, panel->y + diamond->m1 );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->x, panel->y + diamond->y );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->n2, panel->y + diamond->m2 );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->n3, panel->y + diamond->m3 );
        printftext("¡ö", 2);
    }
    if(ID == 1){
        setconsoleposition(panel->x + diamond->n1, panel->y + diamond->m1 );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->x, panel->y + diamond->y );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->n2, panel->y + diamond->m2 );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->n3, panel->y + diamond->m3 );
        printftext("¡ö", 2);
    }
    if(ID == 2) {
        setconsoleposition(panel->x + diamond->n1, panel->y + diamond->m1 );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->x, panel->y + diamond->y );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->n2, panel->y + diamond->m2 );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->n3, panel->y + diamond->m3 );
        printftext("¡ö", 2);
    }
    if(ID == 3){
        setconsoleposition(panel->x + diamond->n1, panel->y + diamond->m1 );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->x, panel->y + diamond->y );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->n2, panel->y + diamond->m2 );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->n3, panel->y + diamond->m3 );
        printftext("¡ö", 2);
    }
    if(ID == 4){
        setconsoleposition(panel->x + diamond->n1, panel->y + diamond->m1 );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->x, panel->y + diamond->y );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->n2, panel->y + diamond->m2 );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->n3, panel->y + diamond->m3 );
        printftext("¡ö", 2);
    }
    if(ID == 5){
        setconsoleposition(panel->x + diamond->n1, panel->y + diamond->m1 );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->x, panel->y + diamond->y );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->n2, panel->y + diamond->m2 );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->n3, panel->y + diamond->m3 );
        printftext("¡ö", 2);
    }
    if(ID == 6){
        setconsoleposition(panel->x + diamond->n1, panel->y + diamond->m1 );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->x, panel->y + diamond->y );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->n2, panel->y + diamond->m2 );
        printftext("¡ö", 2);
        setconsoleposition(panel->x + diamond->n3, panel->y + diamond->m3 );
        printftext("¡ö", 2);
    }
}

Diamond *diamond_init() {
    drawtrailerpanel();
    srand(time(NULL));
    int i = rand() % 7;
    int a = rand() % 0xF;
    Diamond* d = NULL;
    d = (Diamond*)malloc(sizeof(Diamond));
    *d = diamonds[i];
    d->color = a;
    drawdiamond(d,trailer_panel,d->color);
    return d;
}