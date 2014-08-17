#ifndef _GRAFIK_HH_
#define _GRAFIK_HH_
  
#include <iostream>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Board.hh"
#include "Move.hh"
  
  class Grafik {
  
    public:
      Grafik();
      ~Grafik();
      void setField(int arr[8][8]);
      void print(const int arr[8][8]);
      void print(const Move &move);
      void setKing(const Move &move);
      void bye();
      void light(int frX, int frY);
      void unlight(int frX, int frY);
     
      
      
   
    private:
      SDL_Surface *screen, *board, *master;
      SDL_Surface *pawn_black, *pawn_white, *skull;
      SDL_Surface *king_black, *king_white;
      
      SDL_Surface *klick;
      

      //initializes the rectangles[pawns - white/black-], src = source, dst = destination.
      SDL_Rect pawn_b_src, pawn_b_dst;
      SDL_Rect pawn_w_src, pawn_w_dst;
  
      //initializes the skull-image
      SDL_Rect skull_src, skull_dst;
  
      //initializes the rectangles[king - white/black-], src = source, dst = destination.
      SDL_Rect king_b_src, king_b_dst;
      SDL_Rect king_w_src, king_w_dst;
  
      //MasterBoard
      SDL_Rect master_src, master_dst;
      SDL_Rect copy_src, copy_dst;
      //klick
      SDL_Rect klick_src, klick_dst;
       
      //bye
      SDL_Rect bye_src, bye_dst;
    
      int beatX;
      int beatY;
      int field[8][8];
    
  };
  
#endif
