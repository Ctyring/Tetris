//
// Created by CTY on 2020/11/4 22:04.
// QQ ：173479693
// 描述：
//

#include "base.h"
HANDLE std_output_win = 0;
/**
 * 获取输出句柄
 */
void gethandle(){
    if(std_output_win == 0){
        std_output_win = GetStdHandle(STD_OUTPUT_HANDLE);
    }
}
void setTitle(char* Title){
    SetConsoleTitle(Title);
}

void setwindowsize(int width, int height) {
    SMALL_RECT rect = {0 , 0, width - 1,height - 1};//窗口大小区域
    COORD coord = {width,height};//设置缓冲区大小
    gethandle();
    SetConsoleScreenBufferSize(std_output_win,coord);
    SetConsoleWindowInfo(std_output_win,TRUE,&rect);
}
void setconsoleposition(int x, int y){
    COORD coord = {x , y};
    gethandle();
    SetConsoleCursorPosition(std_output_win,coord);
}
void setcolor(int color) {
    gethandle();
    SetConsoleTextAttribute(std_output_win,color);
}

void drawHline(int x, int y, char letter, int color, int length) {
    setconsoleposition(x , y);//定位
    setcolor(color);
    for(int i = 0 ; i < length; i++){
        printf("%c",letter);
    }
}

void drawVline(int x, int y, int letter, int color, int height) {
    setconsoleposition(x,y);
    setcolor(color);
    for(int i = 0 ; i < height; i++){
        printf("%c",letter);
        setconsoleposition(x,++y);
    }
}

void filltext(int x, int y, int height, int width, int letter, int color) {
    DWORD relen;
    gethandle();
    for(int i = 0 ; i < height; i++){
        COORD coord = {x,y++};//每次打印一行
        FillConsoleOutputAttribute(std_output_win,color,width,coord,&relen);
        FillConsoleOutputCharacterA(std_output_win,letter,width,coord,&relen);
    }
}

void printftext(char *text, int size) {
    char format[30] = "%-";
    char sizebuf[100];
    itoa(size,sizebuf,100);
    strcat(format,sizebuf);
    strcat(format,"s");
    printf(format,text);
}

char readchar() {
    char rech; //返回的字符
    if(kbhit())
    {
        rech = getch();
    }
    return rech;
}
/**
 * 隐藏光标
 */
void disableCurrsor() {
    CONSOLE_CURSOR_INFO cursor_info;
    cursor_info.bVisible = FALSE;
    cursor_info.dwSize = 1;
    SetConsoleCursorInfo(std_output_win,&cursor_info);
}
