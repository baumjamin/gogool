#include "Move.hh"
#include "Board.hh"
#include "Player.hh"
#include "Humanplayer.hh"
#include "KI.hh" 
#include "Grafik.hh"
#include "Graphicobserver.hh"
#include <iostream>
#include <string>
#include <fstream>
#include "TournamentPlayer.hh"

using namespace std;

int main(int argc, char *argv[])	{

  string ki_ = "ai";
  string human_ = "human";		//cause the bloody argv[] question dosnt work on normal way
  string tournament_ = "tournament";
  string man_ = "--help";			//Manual
  string observer_="observer";
  string p1st, p2nd;
  Player *player1, *player2;
  TournamentPlayer* tournament_player;
  int is_tournament=0;

  if(argc==2 && argv[1] == man_) {
    string elem;
    char c;
    ifstream myInputStream ("manual.txt"); 	// Open manual-file
    if (!myInputStream) {
      cout << "Cannot open file!" << endl; // No: abort
      return -1;
    }
    while (!myInputStream.eof()) { // read value from file
			// while return value of operator>> (the stream's state) is true
      myInputStream.get(c);
      cout << c;
    }
    return 0;
  }	else {
    if(argc<=2 || (argv[1]!=observer_ && argc!=3) && (argv[1]!=human_ && argv[1]!=ki_ && argv[1]!=tournament_ || argv[2]!=ki_ && argv[2]!=human_ && argv[2]!=tournament_)){
      cout << "Please do it like: <programname> <ai | human | tournament> <ai | human | tournament> [<MasterIP>]" << endl;
      if(argc==3 && (argv[1]==tournament_ || argv[2]==tournament_)){
        cout << "If yout want to play a networkgame, you have to type a MasterIP at last value" << endl;
      }
      return 1;
    }
  }


  /*Initialize the Board*/
  Board board;
  Graphicobserver output("Player1", "Player2", board);  //Warum hat der Graphicobserver 2 playernamen

    

  /*Initialisize the Players */
  cout << "\f\f\f\f\f\f\f";	//some space for the better overview

  if((argv[1] == human_)  && (argv[2]==human_))	{   //HUMAN VS  HUMAN
    cout << "Welcome to the  >>>>>   gogolinc!   <<<<<" << endl;
    cout << "Please give me 2 Playernames: " << endl;
    
    cout << "Player 1: ";			//read Playername 1
    cin >> p1st;
    if(p1st == "quit"){
      return 0;
    }	

    cout << "Player 2: ";			//read Playername 2
    cin >> p2nd;
    if(p2nd == "quit"){
      return 0;
    }	

    while(p2nd == p1st){
      cout << "Please choose different names!" << endl;
      cout << "Player 2: ";
      cin >> p2nd;
      if(p2nd == "quit"){
        return 0;
      }	
    }

    cout <<"White starts, who's white? " << p1st << " or " << p2nd << "?" <<  endl;
    	
    string begin;
    cin >> begin;
    if(begin == "quit"){
      return 0;
    }	
	
    while ((begin != p1st) && (begin != p2nd)){
      cout << "You have to type one of the names you've input:" << endl;
      cin >> begin;
      if(begin == "quit"){
        return 0;
      }	
    }

    if(begin == p1st){
    }	else    {
      string tmp = p1st;
      p1st = p2nd;
      p2nd = tmp;
    }

    player1 = new Humanplayer('w', board, output);			//Evtl noch namen einbinden
    player2 = new Humanplayer('b', board, output);
  }

  if(argv[1] == human_ && argv[2] == ki_ || argv[2] == human_  && argv[1] == ki_)	{  //KI VS HUMAN
    cout << "Welcome to the  >>>>>   gogolinc!   <<<<<" << endl;
    cout << "Please give me 2 Playernames: " << endl;

    cout << "AI's Name: ";
    cin >> p1st;
    if(p1st == "quit"){
      return 0;
    }	

    cout << "Human-Player's Name: ";
    cin >> p2nd;
    if(p2nd == "quit"){
      return 0;
    }	

    while(p2nd == p1st){
      cout << "Please choose different names!" << endl;
      cout << "Player 2: ";
      cin >> p2nd;
      if(p2nd == "quit"){
        return 0;
      }	
    }

    cout <<"White begins, who want's to be the beginner? " << p1st << " or " << p2nd << "?" <<  endl;
    	
    string begin;
    cin >> begin;
    if(begin == "quit"){
      return 0;
    }	
	
    while ((begin != p1st) && (begin != p2nd)){
      cout << "You have to type one of the names you've input:" << endl;
      cin >> begin;
      if(begin == "quit"){
        return 0;
      }	
    }

    if(begin == p1st){
      player1 = new KI('w', board);
      player2 = new Humanplayer('b', board, output);
    }	
    else	{
      string tmp = p1st;
      p1st = p2nd;
      p2nd = tmp;
      player1 = new Humanplayer('w', board, output);
      player2 = new KI('b', board);
    }
  }

  if(argv[1] == ki_ && argv[1+1] == ki_)	{
    cout << "Welcome the  >>>>>   gogolINC!   <<<<<" << endl;
    cout << "ai vs. ai" << endl;
    cout << "Please give me 2 Playernames: " << endl;

    cout << "Player 1: ";			//read Playername 1
    p1st = "AI1";
    cout << p1st << endl;

    cout << "Player 2: ";			//read Playername 2
    p2nd = "AI2";
    cout << p2nd << endl;
	
    string begin = p1st;
	
    if(begin == p1st)	{
    } 	else	{
      string tmp = p1st;
      p1st = p2nd;
      p2nd = tmp;
    }
    player1 = new KI('w', board);
    player2 = new KI('b', board);
  }
    
//IFCASES FOR THE TOURNAMENT GAMES

  if(argv[2] == tournament_ && argv[1] == ki_)	{

    is_tournament = 1;
    cout << "Welcome to the  >>>>>   gogolinc!   <<<<<" << endl;	
    cout << "Please give me 2 Playernames: " << endl;

    cout << "Player 1: ";			//read Playername 1
    cin >> p1st;
    if(p1st == "quit"){
      return 0;
    }	

    cout << "Player 2: ";			//read Playername 2
    cin >> p2nd;
    if(p2nd == "quit"){
      return 0;
    }	

    while(p2nd == p1st){
      cout << "Please choose different names!" << endl;
      cout << "Player 2: ";
      cin >> p2nd;
      if(p2nd == "quit"){
        return 0;
      }	
    }
    cout << p1st << "You begin!" << endl;

    player1 = new KI('w', board);
    tournament_player = new TournamentPlayer('b', argv[3]);
    player2=tournament_player;
		
  }


  if(argv[1] == tournament_ && argv[1+1] == ki_)	{

    is_tournament = 2;
    cout << "Welcome to the  >>>>>   gogolinc!   <<<<<" << endl;	
    cout << "Please give me 2 Playernames: " << endl;

    cout << "Player 1: ";			//read Playername 1
    cin >> p1st;
    if(p1st == "quit"){
      return 0;
    }	

    cout << "Player 2: ";			//read Playername 2
    cin >> p2nd;
    if(p2nd == "quit"){
      return 0;
    }	

    while(p2nd == p1st){
      cout << "Please choose different names!" << endl;
      cout << "Player 2: ";
      cin >> p2nd;
      if(p2nd == "quit"){
        return 0;
      }	
    }
    cout << p1st << "You begin!" << endl;

    tournament_player = new TournamentPlayer('w', argv[3]);
    player2 = new KI('b', board);
    player1=tournament_player;

  }

  if(argv[2] == tournament_ && argv[1] == human_)	{

    is_tournament =1;

    cout << "Welcome to the  >>>>>   gogolinc!   <<<<<" << endl;	
    cout << "Please give me 2 Playernames: " << endl;

    cout << "Player 1: ";			//read Playername 1
    cin >> p1st;
    if(p1st == "quit"){
      return 0;
    }	

    cout << "Player 2: ";			//read Playername 2
    cin >> p2nd;
    if(p2nd == "quit"){
      return 0;
    }	

    while(p2nd == p1st){
      cout << "Please choose different names!" << endl;
      cout << "Player 2: ";
      cin >> p2nd;
      if(p2nd == "quit"){
        return 0;
      }	
    }

    cout << p1st << "You begin!" << endl;
    player1 = new Humanplayer('w', board , output);
    tournament_player = new TournamentPlayer('b', argv[3]);
    player2 =tournament_player;

  }


  if(argv[1] == tournament_ && argv[1+1] == human_)	{
    is_tournament =2;

    cout << "Welcome to the  >>>>>   gogolinc!   <<<<<" << endl;	
    cout << "Please give me 2 Playernames: " << endl;

    cout << "Player 1: ";			//read Playername 1
    cin >> p1st;
    if(p1st == "quit"){
      return 0;
    }	

    cout << "Player 2: ";			//read Playername 2
    cin >> p2nd;
    if(p2nd == "quit"){
      return 0;
    }	

    while(p2nd == p1st){
      cout << "Please choose different names!" << endl;
      cout << "Player 2: ";
      cin >> p2nd;
      if(p2nd == "quit"){
        return 0;
      }	
    }

    cout << p1st << "You begin!" << endl;

    tournament_player = new TournamentPlayer('w', argv[3]);
    player2 = new Humanplayer('b', board, output);
    player1=tournament_player;

  }

  if(argv[1]==observer_ && argc==3){
    player1= new TournamentPlayer('o',argv[2]);
    player2= player1;


    p1st = "Player 1";
    p2nd = "Player 2";
    
	

  }

  // HIER PLAYERNAMEN SETZEN!
    //Let the Game begin:


  cout << endl;
  cout << endl;
 
  Move move_w, move_b, *move_ptr;
  int whosnext=0;
  SDL_WarpMouse(300,300);
  cout << p1st << " (white) please set your king:" << endl;	
  move_ptr=player1->setKing();
  if(move_ptr==0){

    cout << "byebye" << endl;
    delete player1;
    delete player2;
    delete move_ptr;
    move_ptr=0;
    player2=0;
    player1=0;
    return 0;
  }
  move_w=*move_ptr;
  board.setMove(move_w, 'w');
  output.update(move_w);
  if(is_tournament == 1){
    tournament_player->update(move_w);
  }
    
  delete move_ptr;
  move_ptr=0;
  whosnext++;

  cout << p2nd << " (black) please set your king:" << endl;		
  move_ptr=player2->setKing();
  if(move_ptr==0){

    cout << "byebye" << endl;
    delete player1;
    delete player2;
    delete move_ptr;
    move_ptr=0;
    player2=0;
    player1=0;
    return 0;
  }
  move_b = *move_ptr;		//SET the black KING
  board.setMove(move_b,'b');
  output.update(move_b);
  if(is_tournament == 2){
    tournament_player->update(move_b);
  }
  delete move_ptr;
  whosnext++;
    
		
    //LOOP LOOP LOOP!
  while(!board.win() && move_ptr!=0){		// true muss noch durch Benutzereingabe ersetzt werden, falls abgebrochen werden soll
	
    if(whosnext%2 == 0){			//whosnext % 2 cause just every 2nd move white have to make a move...
      cout << p1st << " (white) it's your turn:" << endl;					//GET  the white MOVE  if is white's turn

      move_ptr = (player1->getMove());	
      if(move_ptr != 0){
        move_w=*move_ptr;
        board.setMove(move_w);
        output.update(move_w);
        if(is_tournament == 1){
          tournament_player->update(move_w);
        }
        whosnext++;
      }

    }
    else	{
      cout << p2nd << " (black) it's your turn:" << endl;					//GET  the black MOVE if is black's turn
	
      move_ptr = (player2->getMove());	
      if(move_ptr != 0){
        move_b=*move_ptr;
        board.setMove(move_b);
        output.update(move_b);
        if(is_tournament == 2){
          tournament_player->update(move_b);
        }
        whosnext++;
      }
    }
    delete move_ptr;
  }

  if(move_ptr==0){
    cout << "byebye!" << endl;

    delete player1;
    delete player2;
    player1 =0;
    player2 =0;
    return 0;
  }
  else{

    whosnext--;    
    if(whosnext%2 == 0){
      cout << endl << "Player " << p1st << " wins!" << endl;
      

    } 
    else	{
      cout << endl << "Player " << p2nd << " wins!" << endl;
               
    }

  }

// now you can close the screen by clicking "X". (benny)

  output.bye();
  cout << "Leave the game by clicking \"X\"!" << endl;


  int done = 0;

  SDL_Event event;

  while (!done) {
    while (SDL_PollEvent(&event)) {
      switch(event.type) {
        case SDL_QUIT:
          done = 1;
          break;
      }
    }
  }

    
    //Abfrage ob ein neues spiel gemacht werden soll

  delete player1;
  delete player2;
  player1 =0;
  player2 =0;
  return 0;
}

