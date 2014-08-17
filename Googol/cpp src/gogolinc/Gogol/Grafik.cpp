#include "Grafik.hh"
  
  using namespace std;
  
  /**The gogol Graphik.
   */
  
  
  /**Standard Constructor.
 *Opens a windows with an empty board.
   */
  Grafik::Grafik()
{
  
    //Loading the images.
    pawn_black = IMG_Load("data/pawn_black.png");
    if (pawn_black == NULL) 
    {
      printf("Can't load pawn_black.png: %s\n", SDL_GetError());
      exit(1);
    }
  
    pawn_white = IMG_Load("data/pawn_white.png");
    if (pawn_white == NULL) {
      printf("Can't load pawn_white.png: %s\n", SDL_GetError());
      exit(1);
    }
  
    king_black = IMG_Load("data/king_black.png");
    if (king_black == NULL) 
    {
      printf("Can't load king_black.png: %s\n", SDL_GetError());
      exit(1);
    }
    king_white = IMG_Load("data/king_white.png");
    if (king_white == NULL) 
    {
      printf("Can't load king_white.png: %s\n", SDL_GetError());
      exit(1);
    }
    
    skull = IMG_Load("data/skull.png");
    if (skull == NULL) 
    {
      printf("Can't load skull.png: %s\n", SDL_GetError());
      exit(1);
    }
    
    klick = IMG_Load("data/klick.png");
    if (klick == NULL) 
    {
      printf("Can't load klick.png: %s\n", SDL_GetError());
      exit(1);
    }
  
  
    board = IMG_Load("data/board.png");
    master = IMG_Load("data/board.png");
    if (board == NULL) 
    {
      printf("Can't load board.png: %s\n", SDL_GetError());
      exit(1);
    } 
  

  
  //screen is the name of the window.
    screen = SDL_SetVideoMode(board->w, board->h, 16, SDL_HWSURFACE);
    if (screen == NULL) 
    {
      printf("Can't set video mode: %s\n", SDL_GetError());
      exit(1);
    }
  
  
  
    if (SDL_Init(SDL_INIT_VIDEO) == -1) 
    {
      printf("Can't init SDL:  %s\n", SDL_GetError());
      exit(1);
  
    }
  
    beatX = -1;
    beatY = -1;

  //buliding the window. Delay to give SDL some time... otherwise there might be a black window.
    SDL_Delay(100);
    SDL_BlitSurface(board, NULL, screen, NULL);
    SDL_Flip(screen);
    SDL_Delay(100);
  
  }
  
/*
  
  Sounds ... don't work in the pool
   //-------------------------------------------------------
  SDL_AudioSpec spec;
  Uint32 sound_len;
  Uint8 *sound_buffer;
  int sound_pos = 0;
  
  void Callback (void *userdata, Uint8 *stream, int len)
  {
  Uint8 *waveptr;
  waveptr = sound_buffer + sound_pos;
  SDL_MixAudio(stream, waveptr, len, SDL_MIX_MAXVOLUME);
  sound_pos += len;
}

  
  void play (void)
  {
  if (SDL_LoadWAV ("fight.wav", &spec, &sound_buffer, &sound_len) == NULL)
  cout << "fight.wav not found!";
  	
  spec.callback = Callback;
  if (SDL_OpenAudio (&spec, NULL) < 0)
  {
  printf ("Can't open Audio: %s\n", SDL_GetError ());
  exit (-1);
}
  SDL_PauseAudio (0);
}
 //------------------------------------------------------- 
  */
  
  /**Destructor
   */
  Grafik::~Grafik()
  {
  
  //shuts down all SDL subsystems and frees the resources allocated to them.
    SDL_Quit();
  
  }
  
  
  /**copies the field form "Board" to the graphic-system.
   */
  void Grafik::setField(int arr[8][8])
  {
    SDL_Surface *image = IMG_Load("data/king_black.png");
    SDL_WM_SetIcon(image,0);
    SDL_WM_SetCaption(" gogol                                                                                    (c) gogolINC", "data/king_black.png");
    //SDL_WM_SetCaption(" gogol                                                                                           (c) gogolINC", "koenig_s.png");
    // copy field for later use.
    for (int i = 0; i < 8 ; i++)
    {
      for (int j = 0; j < 8; j++)
      {
        field[i][j] = arr[i][j];
      }
    }
  
  
  //setting up the board. (copies all pawns and kings to the SDL-Surface.
    for (int counter1 = 0; counter1 < 8; counter1++)
    {
      for (int counter2 = 0; counter2 < 8; counter2++)
      {
        if (field[counter2][counter1] == -2)
        {
          pawn_b_src.x = 0;
          pawn_b_src.y = 0;
          pawn_b_src.w = pawn_black->w;
          pawn_b_src.h = pawn_black->h;
                  
          pawn_b_dst.x = 40 + counter1*75;
          pawn_b_dst.y = 42 + counter2*75;
                  
  
          SDL_BlitSurface(pawn_black, &pawn_b_src, screen, &pawn_b_dst);
        }
  
        //pawn white
        if (field[counter2][counter1] == 2)
        {
          pawn_w_src.x = 0;
          pawn_w_src.y = 0;
          pawn_w_src.w = pawn_white->w;
          pawn_w_src.h = pawn_white->h;
                  
          pawn_w_dst.x = 40 + counter1*75;
          pawn_w_dst.y = 42 + counter2*75;
          
  
          SDL_BlitSurface(pawn_white, &pawn_w_src, screen, &pawn_w_dst);
        }
  
  
        //king black
        if (field[counter2][counter1] == -3)
        {
          king_b_src.x = 0;
          king_b_src.y = 0;
          king_b_src.w = king_black->w;
          king_b_src.h = king_black->h;
                  
          king_b_dst.x = 40 + counter1*75;
          king_b_dst.y = 42 + counter2*75;
                  
  
          SDL_BlitSurface(king_black, &king_b_src, screen, &king_b_dst);
        }
  
  
        //king white
        if (field[counter2][counter1] == 3)
        {
          king_w_src.x = 0;
          king_w_src.y = 0;
          king_w_src.w = king_white->w;
          king_w_src.h = king_white->h;
                  
          king_w_dst.x = 40 + counter1*75;
          king_w_dst.y = 42 + counter2*75;
                  
  
          SDL_BlitSurface(king_white, &king_w_src, screen, &king_w_dst);
        }
  
        //skull
        if (field[counter2][counter1] == -1 || field[counter2][counter1] == 1)
        {
          skull_src.x = 0;
          skull_src.y = 0;
          skull_src.w = skull->w;
          skull_src.h = skull->h;
                  
          skull_dst.x = 40 + counter1*75;
          skull_dst.y = 42 + counter2*75;
                  
  
          SDL_BlitSurface(skull, &skull_src, screen, &skull_dst);
        }
  
      }
    }
    SDL_Flip(screen);
  }
  
  
  /**print-function with the new move.
   */
  void Grafik::print(const Move &move)
  {
    
    //clear the skull image from board
    if (field[beatY][beatX] == -1)
    {
      master_src.x = 40 + beatX*75;
      master_src.y = 42 + beatY*75 ;
      master_src.w = 75;
      master_src.h = 75;
    
      master_dst.x = 40 + beatX*75;
      master_dst.y = 42 + beatY*75;
      master_dst.w = 75;
      master_dst.h = 75;
    
      field[beatY][beatX] = 0;
      SDL_BlitSurface(master, &master_src, screen, &master_dst);
    
    }
      
  
    //getting values from move.
    int frX = move.getFromX();
    int frY = move.getFromY();
    int toX = move.getToX();
    int toY = move.getToY();
  
    //stone_from = value of the stone.
    int stone_from = field[frY][frX];
  
  
    int deltaX = frX-toX;
    int deltaY = frY-toY;
    int absdX = abs(deltaX);
    int absdY = abs(deltaY);
    
    
    //if this is true, the skull image is copied to the screen
    bool isbeatmove = ((absdX == 2 && absdY == 2) || (absdX == 0 && absdY == 2) || (absdX == 2 && absdY == 0));
    if (isbeatmove && field[frY][frX]*field[frY-deltaY/2][frX-deltaX/2] < 0)
    {

     
      /* doesn't work in the pool :/ soundcard is missing... otherwise sound if you kill a stone
      play();
      SDL_Delay(250);
      SDL_CloseAudio();
      */      

        
      beatY = frY-deltaY/2;
      beatX = frX-deltaX/2; 

      master_src.x = 40 + beatX*75;
      master_src.y = 42 + beatY*75;
      master_src.w = 75;
      master_src.h = 75;
    
      master_dst.x = 40 + beatX*75;
      master_dst.y = 42 + beatY*75;
      master_dst.w = 75;
      master_dst.h = 75;
      SDL_BlitSurface(master, &master_src, screen, &master_dst);
    
      
      field[frY-deltaY/2][frX-deltaX/2] = -1;
  
      skull_src.x = 0;
      skull_src.y = 0;
      skull_src.w = skull->w;
      skull_src.h = skull->h;
  
      skull_dst.x = 40 + beatX*75;
      skull_dst.y = 42 + beatY*75;
      skull_dst.w = skull->w;
      skull_dst.h = skull->h;
      SDL_BlitSurface(skull, &skull_src, screen, &skull_dst);
  
    }
  
    //change the values of the board
    field[toY][toX] = stone_from;
    field[frY][frX] = 0;
  
    
    //pawn black
    
    if (stone_from == -2)
    {
      pawn_b_src.x = 0;
      pawn_b_src.y = 0;
      pawn_b_src.w = pawn_black->w;
      pawn_b_src.h = pawn_black->h;
                  
      pawn_b_dst.x = 40 + toX*75;
      pawn_b_dst.y = 42 + toY*75;
  
      SDL_BlitSurface(pawn_black, &pawn_b_src, screen, &pawn_b_dst);
    }
  
  
    //pawn white
    if (stone_from == 2)
    {
      pawn_w_src.x = 0;
      pawn_w_src.y = 0;
      pawn_w_src.w = pawn_white->w;
      pawn_w_src.h = pawn_white->h;
                  
      pawn_w_dst.x = 40 + toX*75;
      pawn_w_dst.y = 42 + toY*75;
          
  
      SDL_BlitSurface(pawn_white, &pawn_w_src, screen, &pawn_w_dst);
    }
  
    //king black
    if (stone_from == -3)
    {
      king_b_src.x = 0;
      king_b_src.y = 0;
      king_b_src.w = king_black->w;
      king_b_src.h = king_black->h;
                  
      king_b_dst.x = 40 + toX*75;
      king_b_dst.y = 42 + toY*75;
  
      SDL_BlitSurface(king_black, &king_b_src, screen, &king_b_dst);
    }
  
    //king white
    if (stone_from == 3)
    {
      king_w_src.x = 0;
      king_w_src.y = 0;
      king_w_src.w = king_white->w;
      king_w_src.h = king_white->h;
                  
      king_w_dst.x = 40 + toX*75;
      king_w_dst.y = 42 + toY*75;
                  
  
      SDL_BlitSurface(king_white, &king_w_src, screen, &king_w_dst);
    }
  
    //filling the empty rectangle
    master_src.x = 40 + frX*75;
    master_src.y = 42 + frY*75 ;
    master_src.w = 75;
    master_src.h = 75;
  
    master_dst.x = 40 + frX*75;
    master_dst.y = 42 + frY*75;
    master_dst.w = 75;
    master_dst.h = 75;
  
  
    SDL_BlitSurface(master, &master_src, screen, &master_dst);
 
    //updates the screen
    SDL_Flip(screen);
  
  }
  
  
  /** setKing function.
   * sets the king
   */
  void Grafik::setKing(const Move &move)
  {
    int toX = move.getToX();
    int toY = move.getToY();
  
    //first, it's whites turn, so color = 0
    static int color = 0;
    if (color == 0)
    {
      field[toY][toX] = 3;
      
      king_w_src.x = 0;
      king_w_src.y = 0;
      king_w_src.w = king_white->w;
      king_w_src.h = king_white->h;
      
      king_w_dst.x = 40 + toX*75;
      king_w_dst.y = 42 + toY*75;
      
  
      SDL_BlitSurface(king_white, &king_w_src, screen, &king_w_dst);
    }
    
    if (color == 1)
    {
      field[toY][toX] = -3;
      king_b_src.x = 0;
      king_b_src.y = 0;
      king_b_src.w = king_black->w;
      king_b_src.h = king_black->h;
       
      king_b_dst.x = 40 + toX*75;
      king_b_dst.y = 42 + toY*75;
       
      SDL_BlitSurface(king_black, &king_b_src, screen, &king_b_dst);
      
    }
    //the next call of the function, it's blacksturn => farbe = 1
    color++;
    
    //updates the screen
    SDL_Flip(screen);
  }
  
  
  /**bye function
   * displays "game over!" at the end of the game
   */
  void Grafik::bye()
  {
    
    //loading the bye.png
    SDL_Surface *bye;
    bye = IMG_Load("data/bye.png");
    if (bye == NULL) 
    {
      printf("Can't load bye.png: %s\n", SDL_GetError());
      exit(1);
    }
    
    bye_src.x = 0;
    bye_src.y = 0;
    bye_src.w = bye->w;
    bye_src.h = bye->h;
    
    bye_dst.x = 60;
    bye_dst.y = 220;
    
    //copies the surface bye to the screen
    SDL_BlitSurface(bye, &bye_src, screen, &bye_dst);
    
    //updates the screen
    SDL_Flip(screen);
  }
  
  
  /**light function: 
   * highlights the klicked field
   */
  void Grafik::light(int frX, int frY)
  {  
    
    //empty field?
    if (field[frY][frX] == 0)
    {
      klick_src.x = 0;
      klick_src.y = 0;
      klick_src.w = klick->w;
      klick_src.h = klick->h;
      
      klick_dst.x = 40 + frX*75;
      klick_dst.y = 42 + frY*75;
      SDL_BlitSurface(klick, &klick_src, screen, &klick_dst);
    }
    //pawn black
    if (field[frY][frX] == -2)
    {
      klick_src.x = 0;
      klick_src.y = 0;
      klick_src.w = klick->w-2;
      klick_src.h = klick->h-2;
      
      klick_dst.x = 40 + frX*75;
      klick_dst.y = 42 + frY*75;
      
      
      pawn_b_src.x = 0;
      pawn_b_src.y = 0;
      pawn_b_src.w = pawn_black->w;
      pawn_b_src.h = pawn_black->h;
                  
      pawn_b_dst.x = 40 + frX*75;
      pawn_b_dst.y = 42 + frY*75;
      SDL_BlitSurface(klick, &klick_src, screen, &klick_dst);
      SDL_BlitSurface(pawn_black, &pawn_b_src, screen, &pawn_b_dst);
  

    }
    //king black
    if (field[frY][frX] == -3)
    {
      klick_src.x = 0;
      klick_src.y = 0;
      klick_src.w = klick->w;
      klick_src.h = klick->h;
      
      klick_dst.x = 40 + frX*75;
      klick_dst.y = 42 + frY*75;
      
      
      king_b_src.x = 0;
      king_b_src.y = 0;
      king_b_src.w = king_black->w;
      king_b_src.h = king_black->h;
                  
      king_b_dst.x = 40 + frX*75;
      king_b_dst.y = 42 + frY*75;
      SDL_BlitSurface(klick, &klick_src, screen, &klick_dst);
      SDL_BlitSurface(king_black, &king_b_src, screen, &king_b_dst);
    
    }
    //pawn white
    if (field[frY][frX] == 2)
    {
      klick_src.x = 0;
      klick_src.y = 0;
      klick_src.w = klick->w;
      klick_src.h = klick->h;
      
      klick_dst.x = 40 + frX*75;
      klick_dst.y = 42 + frY*75;
      
      
      pawn_w_src.x = 0;
      pawn_w_src.y = 0;
      pawn_w_src.w = pawn_white->w;
      pawn_w_src.h = pawn_white->h;
                  
      pawn_w_dst.x = 40 + frX*75;
      pawn_w_dst.y = 42 + frY*75;
      SDL_BlitSurface(klick, &klick_src, screen, &klick_dst);
      SDL_BlitSurface(pawn_white, &pawn_w_src, screen, &pawn_w_dst);
      

    }
    //king white
    if (field[frY][frX] == 3)
    {
      klick_src.x = 0;
      klick_src.y = 0;
      klick_src.w = klick->w;
      klick_src.h = klick->h;
      
      klick_dst.x = 40 + frX*75;
      klick_dst.y = 42 + frY*75;
     
      
      king_w_src.x = 0;
      king_w_src.y = 0;
      king_w_src.w = king_white->w;
      king_w_src.h = king_white->h;
                  
      king_w_dst.x = 40 + frX*75;
      king_w_dst.y = 42 + frY*75;
      SDL_BlitSurface(klick, &klick_src, screen, &klick_dst);
      SDL_BlitSurface(king_white, &king_w_src, screen, &king_w_dst);
      
    }
    SDL_Flip(screen);
  }
  
  
  /**unlight function
   * de-highlights the klicked field
   */
  void Grafik::unlight(int frX, int frY)
  {
    //empty flied?
    if (field[frY][frX] == 0)
    {
      master_src.x = 40 + frX*75;
      master_src.y = 42 + frY*75 ;
      master_src.w = 75;
      master_src.h = 75;
  
      master_dst.x = 40 + frX*75;
      master_dst.y = 42 + frY*75;
      master_dst.w = 75;
      master_dst.h = 75;
      SDL_BlitSurface(master, &master_src, screen, &master_dst);
    }
    
    //pawn black
    if (field[frY][frX] == -2)
    {      
      master_src.x = 40 + frX*75;
      master_src.y = 42 + frY*75 ;
      master_src.w = 75;
      master_src.h = 75;
  
      master_dst.x = 40 + frX*75;
      master_dst.y = 42 + frY*75;
      master_dst.w = 75;
      master_dst.h = 75;
      
      pawn_b_dst.x = 40 + frX*75;
      pawn_b_dst.y = 42 + frY*75;
      SDL_BlitSurface(master, &master_src, screen, &master_dst);
      SDL_BlitSurface(pawn_black, &pawn_b_src, screen, &pawn_b_dst);
    }
    
       //king white
    if (field[frY][frX] == -3)
    {
      master_src.x = 40 + frX*75;
      master_src.y = 42 + frY*75 ;
      master_src.w = 75;
      master_src.h = 75;
  
      master_dst.x = 40 + frX*75;
      master_dst.y = 42 + frY*75;
      master_dst.w = 75;
      master_dst.h = 75;
  
      king_b_dst.x = 40 + frX*75;
      king_b_dst.y = 42 + frY*75;
      SDL_BlitSurface(master, &master_src, screen, &master_dst);
      SDL_BlitSurface(king_black, &king_b_src, screen, &king_b_dst);
    }
    
    
    //pawn white
    if (field[frY][frX] == 2)
    {
      master_src.x = 40 + frX*75;
      master_src.y = 42 + frY*75 ;
      master_src.w = 75;
      master_src.h = 75;
  
      master_dst.x = 40 + frX*75;
      master_dst.y = 42 + frY*75;
      master_dst.w = 75;
      master_dst.h = 75;
      
      pawn_w_src.x = 0;
      pawn_w_src.y = 0;
      pawn_w_src.w = pawn_white->w;
      pawn_w_src.h = pawn_white->h;
                  
      pawn_w_dst.x = 40 + frX*75;
      pawn_w_dst.y = 42 + frY*75;
      SDL_BlitSurface(master, &master_src, screen, &master_dst);
      SDL_BlitSurface(pawn_white, &pawn_w_src, screen, &pawn_w_dst);
    }
       
    //king white
    if (field[frY][frX] == 3)
    {
      master_src.x = 40 + frX*75;
      master_src.y = 42 + frY*75 ;
      master_src.w = 75;
      master_src.h = 75;
  
      master_dst.x = 40 + frX*75;
      master_dst.y = 42 + frY*75;
      master_dst.w = 75;
      master_dst.h = 75;
                 
      king_w_dst.x = 40 + frX*75;
      king_w_dst.y = 42 + frY*75;
      
      
      SDL_BlitSurface(master, &master_src, screen, &master_dst);
      SDL_BlitSurface(king_white, &king_w_src, screen, &king_w_dst);
     
    }
    //updates the screen
    SDL_Flip(screen);
  }
    
    

