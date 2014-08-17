#include "Graphicobserver.hh"
using namespace std;

Graphicobserver::Graphicobserver (string namePlayer1, string namePlayer2, const Board &setBoard)
  : Observer(namePlayer1, namePlayer2),  board(setBoard)
{
    
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      map[i][j] = board.get_Field(j,i);
    }
  }
  output.setField(map);

}

Graphicobserver::~Graphicobserver(){
}

void Graphicobserver::update(const Move &myMove){

  if(myMove.moveSetsKing()){
    output.setKing(myMove);
  }

  else{
    output.print(myMove);
      
    /*
    for(int i=0; i<8; i++) {		//AB hier alles nur fuer die Textausgabe
      for(int j=0; j<8; j++) {
        map[i][j] = board.get_Field(j,i);
      }
    }

    cout << endl << "  ";
    for(int l=0; l<8; l++)	{
      cout << "  " << (char)(l+97) << " ";
    }
    cout << endl;

    for(int i=0; i<8; i++)	{
      cout << "  ";
      for(int j=0; j<8; j++)	{
        cout << "+---";
      }
      cout << "+" << endl << (i+1) << " ";	
      for(int k=0; k<8; k++)	{
        cout << "| ";
        switch(map[i][k])	{
          case  -3: cout << "B";
          break;
          case   3: cout << "W"; 
          break;
          case  -2: cout << "b";
          break;
          case   2: cout << "w";
          break;
          default:  cout << " ";				
        }
        cout << " ";
      }
      cout << "|" << endl;	
    }
    cout << "  ";
    for(int j=0; j<8; j++)	{
      cout << "+---";
    }
    cout << "+" << endl << endl;*/	
  }
    
    
}

void Graphicobserver::bye()
{
  output.bye();
}

void Graphicobserver::light(int frX, int frY){
    output.light(frX,frY);
}

void Graphicobserver::unlight(int frX, int frY){
  output.unlight(frX,frY);
}
