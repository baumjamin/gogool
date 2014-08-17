
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

int main()
{
  // Die 2 bereits bekannten Surfaces deklarieren
  SDL_Surface *display;
  SDL_Surface *image;

  // Deklaration des destination-rect und des source-rect
  SDL_Rect drect;
  SDL_Rect srect;

  // init video stuff
  if ( SDL_Init( SDL_INIT_VIDEO) < 0 )
  {
     fprintf(stderr, "SDL konnte nicht initialisiert werden:  %s\n",
       SDL_GetError());
     exit(1);
   }

   atexit(SDL_Quit);

   // init screen
   display = SDL_SetVideoMode( 640,480, 8, SDL_SWSURFACE);
   if ( display == NULL )
   {
     fprintf(stderr, "Konnte kein Fenster 640x480 px oeffnen: %s\n",
       SDL_GetError());
     exit(1);
   }

  // Bild laden
  image = IMG_Load("tux.jpg");
  if (image == NULL)
  {
     fprintf(stderr, "Das Bild konnte nicht geladen werden: %s\n",
       SDL_GetError());
     exit(-1);
  }

  // Bildgroesse zu Debuggingzwecke ausgeben
  fprintf(stdout,"Debug: Bild-Surface-Groesse: %i x %i Pixel\n",
    image->w,image->h);

  // Setzen des Quellbereichs
  srect.x = 0;
  srect.y = 0;
  srect.w = (image->w)/2;  // das gesamte Bild
  srect.h = image->h;   // das gesamte Bild

  // Setzen des Zielbereichs
  drect.x = 200;
  drect.y = 100;
  drect.w = (image->w)/2;
  drect.h = image->h;

  // kopiere surface auf display-surface
  SDL_BlitSurface(image, &srect, display, &drect);

  // den veränderten Bildschirm-Bereich auffrischen
  SDL_UpdateRects(display,1,&drect);

  SDL_Delay(3000);

  // Das Bitmap-Surface löschen
  SDL_FreeSurface(image);
}