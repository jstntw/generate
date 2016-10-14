/* -*- C++ -*- */
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
/* If using gl3.h */
#include <GL/gl.h>

#include <SDL2/SDL.h>
#include "game_render.h"
#define PROGRAM_NAME "Tutorial1"



void checkSDLError(int line);
void begin_window(SDL_Window *mainwindow, SDL_GLContext maincontext);
void setup_context();
