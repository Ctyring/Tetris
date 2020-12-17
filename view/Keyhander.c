//
// Created by Lenovo on 2020/11/10.
//

#include "Keyhander.h"
void keyhandleroperator(defaulthandler *handler, keymapping *maps, int len) {
    char recivekey = 0;
    recivekey = readchar();
    if(recivekey!=0){
        //常规按键处理
        if(recivekey==0xffffffe0)
        {
            recivekey = readchar();
        }
        if(handler != NULL) {
            switch (recivekey) {
                case 'w'://上 0x48
                case 0x48:
                    if (handler->up != NULL) {
                        handler->up('w');
                    }
                    break;
                case 's'://下 0x50
                case 0x50:
                    if (handler->down != NULL) {
                        handler->down('s');
                    }
                    break;
                case 'a'://左 0x4b
                case 0x4b:
                    if (handler->left != NULL) {
                        handler->left('a');
                    }
                    break;
                case 'd'://右 0x4d
                case 0x4d:
                    if (handler->right != NULL) {
                        handler->right('d');
                    }
                    break;
            }
        }
        //特殊按键映射
        if(maps != NULL && len > 0){
            int i;
            for(i = 0;i < len;i++){
                keymapping* mapping = maps + i;
                if(mapping->key == recivekey){
                    if(mapping->keyhandler != NULL){
                        mapping->keyhandler(recivekey);
                    }
                }
            }
        }
    }
}