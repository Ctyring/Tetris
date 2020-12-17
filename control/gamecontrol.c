//
// Created by Lenovo on 2020/11/17.
//

#include <stdbool.h>
#include "gamecontrol.h"
warehouse house[500][500] = {0,0};
Diamond* d_trailer = NULL;//指向下一个方块
Diamond* d_contril = NULL;//指向当前控制的方块
void cleardiamond(Diamond *diamond,Panel* panel);
Diamond *show_me_diamond() {
    if(d_trailer == NULL){
        d_trailer = diamond_init();
    }
    Panel* gamepanel = game_panel_init();
    d_contril = d_trailer;
    d_contril->x += 6;
    d_contril->y -= 3;
    d_contril->n1 += 6;
    d_contril->m1 -= 3;
    d_contril->n2 += 6;
    d_contril->m2 -= 3;
    d_contril->n3 += 6;
    d_contril->m3 -= 3;
    drawdiamond(d_contril,gamepanel,d_contril->color);
    d_trailer = diamond_init();
    return d_contril;
}
int k = 0;
Diamond *change_diamond_status(Diamond *d) {
    int id = finddiamond(d);
    if(id == 0){
        if(d->status == 1){
            d->n1 -= 2;
            d->m1++;
            d->n2 +=2;
            d->m2--;
            d->n3 += 4;
            d->m3 -= 2;
            d->status = 2;
        }
        else{
            d->n1 += 2;
            d->m1--;
            d->n2 -=2;
            d->m2++;
            d->n3 -= 4;
            d->m3 += 2;
            d->status = 1;
        }
    }
    else if(id == 1){
    }
    else if(id == 2){
        if(d->status == 1){
            d->n1 += 4;
            d->m1--;
            d->m3--;
            d->status = 2;
        }
        else{
            d->n1 -= 4;
            d->m1++;
            d->m3++;
            d->status = 1;
        }
    }
    else if(id == 3){
        if(d->status == 1){
            d->m1--;
            d->n3 -= 4;
            d->m3--;
            d->status = 2;
        }
        else{
            d->m1++;
            d->n3 += 4;
            d->m3++;
            d->status = 1;
        }
    }
    if(id == 4){
        if(d->status == 1){
            d->n1 -= 2;
            d->m1++;
            d->n2 -= 2;
            d->m3--;
            d->status = 2;
        }
        else if(d->status == 2){
            d->m1--;
            d->m3--;
            d->n3 -= 2;
            d->n2 += 2;
            d->status = 3;
        }
        else if(d->status == 3){
            d->m1++;
            d->n3 += 2;
            d->n2 += 2;
            d->m2--;
            d->status = 4;
        }
        else{
            d->n1 += 2;
            d->m1--;
            d->n2 -= 2;
            d->m2++;
            d->m3 += 2;
            d->status = 1;
        }
    }
    else if(id == 5){
        if(d->status == 1){
            d->n1 += 2;
            d->m1++;
            d->n2 -= 2;
            d->m2--;
            d->m3 -= 2;
            d->status = 2;
        }
        else if(d->status == 2){
            d->n1 -= 2;
            d->m1++;
            d->n2 += 2;
            d->m2--;
            d->n3 += 4;
            d->status = 3;
        }
        else if(d->status == 3){
            d->m3 += 2;
            d->n2 += 2;
            d->m2++;
            d->n1-=2;
            d->m1--;
            d->status = 4;
        }
        else{
            d->n1 += 2;
            d->m1--;
            d->n2 -= 2;
            d->m2++;
            d->n3 -= 4;
            d->status = 1;
        }
    }
    else if(id == 6){
        if(d->status == 1){
            d->n2 += 2;
            d->m2++;
            d->status = 2;
        }
        else if(d->status == 2){
            d->n1 -= 2;
            d->m1++;
            d->status = 3;
        }
        else if(d->status == 3){
            d->n3 -= 2;
            d->m3--;
            d->status = 4;
        }
        else{
            d->n1 += 2;
            d->m1--;
            d->n3 += 2;
            d->m3++;
            d->n2 -= 2;
            d->m2--;
            d->status = 1;
        }
    }
    Panel* gamepanel = NULL;
    gamepanel = game_panel_init();
    if(k == 0 && (d->x<0 || d->n1 < 0 || d->n2 < 0 || d->n3 < 0)){
        k = 1;
        change_diamond_status(d);
        change_diamond_status(d);
        change_diamond_status(d);
        k = 0;
    }
    if(k == 0 && (d->x > gamepanel->width - 2 || d->n1  > gamepanel->width || d->n2 > gamepanel->width || d->n3 > gamepanel->width)){
        k = 1;
        change_diamond_status(d);
        change_diamond_status(d);
        change_diamond_status(d);
        k = 0;
    }
    if(k == 0 && (house[d->n3][d->m3].c != 0 || house[d->n2][d->m2].c != 0 || house[d->n1][d->m1].c != 0 || house[d->x][d->y].c != 0)){
        k = 1;
        change_diamond_status(d);
        change_diamond_status(d);
        change_diamond_status(d);
        k = 0;
    }
        return d;
}

void cleardiamond(Diamond *diamond,Panel* panel) {
    setcolor(panel->bgcolor<<4|panel->color);
    setconsoleposition(panel->x + diamond->n1, panel->y + diamond->m1 );
    printftext("  ", 2);
    setconsoleposition(panel->x + diamond->x, panel->y + diamond->y );
    printftext("  ", 2);
    setconsoleposition(panel->x + diamond->n2, panel->y + diamond->m2 );
    printftext("  ", 2);
    setconsoleposition(panel->x + diamond->n3, panel->y + diamond->m3 );
    printftext("  ", 2);
}

void change_diamond() {
    struct Panel* panel = game_panel_init();
    cleardiamond(d_contril,panel);
    change_diamond_status(d_contril);
    drawdiamond(d_contril,panel,d_contril->color);
}

void movediamond(_Bool b) {
    Diamond* d = d_contril;
    Panel* gamepanel = NULL;
    gamepanel = game_panel_init();
    if(b){
        if(d->x - 2 > 0 && d->n1 - 2 > 0 && d->n2 - 2 > 0 && d->n3 - 2> 0){
                if(house[d_contril->n3 - 2][d_contril->m3].c == 0 && house[d_contril->n2 - 2][d_contril->m2].c == 0 && house[d_contril->n1 - 2][d_contril->m1].c == 0 && house[d_contril->x - 2][d_contril->y].c == 0){
                cleardiamond(d_contril,gamepanel);
                d->x  -= 2;
                d->n1 -= 2;
                d->n2 -= 2;
                d->n3 -= 2;
                drawdiamond(d,gamepanel,d->color);
            }
        }
    }
    else{
        if(d->x + 4<gamepanel->width && d->n1 + 4 < gamepanel->width && d->n2 + 4 < gamepanel->width && d->n3 + 4 < gamepanel->width){
            if(house[d_contril->n3 + 2][d_contril->m3].c == 0 && house[d_contril->n2 + 2][d_contril->m2].c == 0 && house[d_contril->n1 + 2][d_contril->m1].c == 0 && house[d_contril->x + 2][d_contril->y].c == 0){
                cleardiamond(d_contril,gamepanel);
                d->x  +=2;
                d->n1 +=2;
                d->n2 +=2;
                d->n3 +=2;
                drawdiamond(d,gamepanel,d->color);
            }
        }
    }
}

void diamond_down() {
    Panel* gamepanel = NULL;
    gamepanel = game_panel_init();
    if(d_contril->y  >= gamepanel->height - 1  || house[d_contril->x][d_contril->y + 1].c == 1){
        return;
    }
    else if(d_contril->m1  >= gamepanel->height - 1  || house[d_contril->n1][d_contril->m1 + 1].c == 1){
        return;
    }
    else if(d_contril->m2  >= gamepanel->height - 1  || house[d_contril->n2][d_contril->m2 + 1].c == 1){
        return;
    }
    else if(d_contril->m3  >= gamepanel->height - 1  || house[d_contril->n3][d_contril->m3 + 1].c == 1){
        return;
    }
    cleardiamond(d_contril,gamepanel);
    d_contril->y++;
    d_contril->m1++;
    d_contril->m2++;
    d_contril->m3++;
    drawdiamond(d_contril,gamepanel,d_contril->color);
}

BOOL diamond_stop() {
    Panel* gamepanel = NULL;
    gamepanel = game_panel_init();
    int temp = 0;
    if(d_contril->y  >= gamepanel->height - 1  || house[d_contril->x][d_contril->y + 1].c == 1){
       temp = 1;
    }
    else if(d_contril->m1  >= gamepanel->height - 1  || house[d_contril->n1][d_contril->m1 + 1].c == 1){
        temp = 1;
    }
    else if(d_contril->m2  >= gamepanel->height - 1  || house[d_contril->n2][d_contril->m2 + 1].c == 1){
        temp = 1;
    }
    else if(d_contril->m3  >= gamepanel->height - 1  || house[d_contril->n3][d_contril->m3 + 1].c == 1){
        temp = 1;
    }
    if(temp == 1){
        house[d_contril->x][d_contril->y].c ++;
        //house[d_contril->x + 1][d_contril->y].c ++;
        house[d_contril->x][d_contril->y].color = d_contril->color;
        house[d_contril->n1][d_contril->m1].c  ++;
        //house[d_contril->n1 + 1][d_contril->m2].c  ++;
        house[d_contril->n1][d_contril->m1].color = d_contril->color;
        house[d_contril->n2][d_contril->m2].c  ++;
        //house[d_contril->n2][d_contril->m2].c  ++;
        house[d_contril->n2][d_contril->m2].color = d_contril->color;
        house[d_contril->n3][d_contril->m3].c ++ ;
        //house[d_contril->n3 + 1][d_contril->m3].c ++;
        house[d_contril->n3][d_contril->m3].color = d_contril->color;
        for(int i = 0; i< gamepanel->height; i++){
            getit(i);
        }
        stopgame();
        show_me_diamond();
        return true;
    }
    return false;
}
void drawhouse() {
    Panel* panel = game_panel_init();
    for(int i = 0 ; i <= panel->width - 2; i++){
        for(int j = 0 ; j < panel->height; j++){
            if(house[i][j].c == 1){
                setcolor(panel->bgcolor<<4|house[i][j].color);
                setconsoleposition(panel->x+i,panel->y+j);
                printftext("■",2);
            }
        }
    }
}
void getit(int p) {
    Panel* panel = game_panel_init();
    int i;
    for(i = 1 ; i <= panel->width - 2; i+= 2){
        if(house[i][p].c != 1){
            break;
        }
    }
    if(i > panel->width - 2){
        getscore();
        for( i = 0; i < panel->width; i++){
            house[i][p].c = 0;
        }
        for (i = 0 ; i < panel->width ; i++){
            for(int j = p - 1 ; j > 0; j--){
                if(house[i][j].c == 1){
                    house[i][j+1].color = house[i][j].color;
                    house[i][j+1].c = house[i][j].c;
                    house[i][j].c = 0;
                }
            }
        }
        drawcontrolpanel();
        drawgamepanel();
        drawhouse();
    }
}

BOOL dead_check() {
    Panel* panel = game_panel_init();
    for(int i = 0 ; i < panel->width; i++){
        if(house[i][panel->y + 3].c == 1){
            setconsoleposition((panel->x+panel->width)/2+9,(panel->y+panel->height)/2);
            setcolor(panel->bgcolor<<4 | 0x4);
            printf("GAME OVER");
            return true;
        }
    }
    return false;
}

void cleardiamondhouse() {
    Panel* panel = game_panel_init();
    for(int i = 0 ; i <= panel->width - 2; i++){
        for(int j = 0 ; j < panel->height; j++){
            house[i][j].c = 0;
        }
    }
}

