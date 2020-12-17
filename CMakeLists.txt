cmake_minimum_required(VERSION 3.17)
project(Tetris C)

set(CMAKE_C_STANDARD 11)
find_library(A Winmm.lib)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lwinmm")
add_executable(Tetris main.c common/base.c common/base.h view/panel.c view/panel.h view/controlpanel.c view/controlpanel.h view/Keyhander.c view/Keyhander.h view/settingpanel.c view/settingpanel.h view/ganmepanel.c view/ganmepanel.h data/gamedata.c data/gamedata.h view/trailerpanel.c view/trailerpanel.h control/gamecontrol.c control/gamecontrol.h control/setgame.c control/setgame.h view/rankpanel.c view/rankpanel.h)