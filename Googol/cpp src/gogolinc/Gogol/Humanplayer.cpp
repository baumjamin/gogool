  /**
 * Implementation of the class Humanplayer. 
 * @see Humanplayer
 * @file Humanplayer.cpp
 * @author GogolINC
 * @date 17.05.2007
   */
  
#include "Humanplayer.hh"
#include <SDL/SDL.h>

  
  using namespace std;
  
  Humanplayer::Humanplayer(char myColor, const Board &setBoard, Graphicobserver &setOutput) : board(setBoard), output(setOutput)	{
          // TODO Exception werfen, wenn myColor != b,w
    if(myColor != 'b' || myColor != 'w') color = myColor;
  }
          
  Move *Humanplayer::setKing()	{
    
  
    Move *move = new Move();
    do{
     
      
      // golbal event for SDL
      SDL_Event event;
      done = false;
  
      
      cout << "King to: ";
      
      while (!done)
      {
        while(SDL_PollEvent(&event))
        {
          
          if (event.type == SDL_QUIT)
            return 0;
          
          
          //mousebutton pressed?
          if( event.type == SDL_MOUSEBUTTONDOWN)
          {
        //save mouse position in "mouseX/Y"
            SDL_GetMouseState(&mouseX, &mouseY);
    
            switch ((int)((mouseX+40)/75+0.5))
            {
              case 1:
                tX = 'a';
                break;
              case 2:
                tX = 'b';
                break;
              case 3:
                tX = 'c';
                break;
              case 4:
                tX = 'd';
                break;
              case 5:
                tX = 'e';
                break;
              case 6:
                tX = 'f';
                break;
              case 7:
                tX = 'g';
                break;
              case 8:
                tX = 'h';
                break;
            }
    
        
            tY = (int)((mouseY+40)/75+0.5); 
            done = true;
          }
        }
      }
  
      
      fromX = (color == 'w') ? 'b' : 'g';
      fromY = (color == 'w') ?  2  :  7 ;
    
      //generate new move
      *move = Move(fromX,fromY,tX,tY,true);
    }	while(!board.is_king_move_valid(*move, color));
    return move;
  }
          
  Move *Humanplayer::getMove()	{
    cout << "Please insert your move by using your Mouse!" << endl;
   //global SDL Event     
    SDL_Event event;
    Move *move = new Move();
    
    done = false; 
    
    do {
      cout << "from: " << endl;
     
      while (!done)
      {
   
        while(SDL_PollEvent(&event))
        {
          if (event.type == SDL_QUIT)
          {
            done = true;
            return 0;
          }
          if( event.type == SDL_MOUSEBUTTONDOWN)
          { 
            //see setKing() ...
            SDL_GetMouseState(&mouseX, &mouseY);
           
            switch ((int)((mouseX+40)/75+0.5))
            {
              case 1:
                fX = 'a';
                break;
              case 2:
                fX = 'b';
                break;
              case 3:
                fX = 'c';
                break;
              case 4:
                fX = 'd';
                break;
              case 5:
                fX = 'e';
                break;
              case 6:
                fX = 'f';
                break;
              case 7:
                fX = 'g';
                break;
              case 8:
                fX = 'h';
                break;
            }
            foX = (int)((mouseX+40)/75+0.5);
            fY = (int)((mouseY+40)/75+0.5); 
            done = true;
            output.light((foX-1), fY-1);
                  
            
                    
          }
            
        }
      }
      done = false;
      
      cout << "to: " << endl;
      while (!done)
      {
        
        while(SDL_PollEvent(&event))
        {
          if (event.type == SDL_QUIT)
            return 0;
        
          if( event.type == SDL_MOUSEBUTTONDOWN)
          { 
            SDL_GetMouseState(&mouseX, &mouseY);
            
            switch ((int)((mouseX+40)/75+0.5) )
            {
              case 1:
                tX = 'a';
                break;
              case 2:
                tX = 'b';
                break;
              case 3:
                tX = 'c';
                break;
              case 4:
                tX = 'd';
                break;
              case 5:
                tX = 'e';
                break;
              case 6:
                tX = 'f';
                break;
              case 7:
                tX = 'g';
                break;
              case 8:
                tX = 'h';
                break;
            }
              
            tY = (int)((mouseY+40)/75+0.5); 
            done = true;
                          
            output.unlight(foX-1, fY-1);
          }
              
          
        
        }
      }
      
      *move = Move(fX,fY,tX,tY, false);
      done = false;
    
    }	while(!board.is_move_valid(*move, color));
    return move;
  }
