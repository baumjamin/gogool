/** Graphicobserver-class 
 * 4 the graphical output of the game gogolinc
 * @file Graphicobserver.hh
 * @author gogolinc (Malte)
 * @date 22.06.2007
 */

#ifndef _Graphicobserver_hh_
#define _Graphicobserver_hh_


#include "Grafik.hh"
#include "Move.hh"
#include "Observer.hh"
#include "Board.hh"
#include <iostream>

using namespace std;

/** Class Graphicobserver:
 * direved from class Observer
 */

class Graphicobserver : public Observer{
  public:

	/** Constructor of Graphicobserver-class
   * @param namePlayer1 for initialize the playername 1
   * @param namePlayer2 fpr initialize the playername 2
         */
    Graphicobserver (string namePlayer1, string namePlayer2, const Board &setBoard);		
	/** Destructor of Graphicobserver-class
         */
    virtual ~Graphicobserver();
	/** updatefunction to set the graphicaloutput on the newst gameinformations
     * @param const &myMove
         */
    virtual void update(const Move &myMove);
    /**  function to print the gameover cover on display
      */
    void bye();
    /** function to make light behind the figurs when them clicked on
      */
    void light(int frX, int frY);
    /** function to remove the light 
      */
    void unlight(int frX, int frY);
  private:
    
    int map[8][8];
    Grafik output;
    const Board &board;
};

#endif


