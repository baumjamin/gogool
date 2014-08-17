#ifndef _OBSERVER_H
#define _OBSERVER_H

#include "Move.hh"
#include <string>

using std::string;
/** 
 * An Observer of the game.
 * Observers are all entities that want to keep track of the moves
 * (e.g. output classes or computer player).
 * In particular, the graphical user interfaces must be derived from the 
 * abstract class observer, so that the tournament observer can access them.
 */
class Observer {
public:
  /** The constructor of an observer can be used to name the players.
   * \param namePlayer1 Name of the first player, playing the white tokens
   * \param namePlayer2 Name of the second player, playing the black tokens
   */
  Observer (string namePlayer1 = "White", string namePlayer2 = "Black") 
    : player1 (namePlayer1), player2 (namePlayer2) {}

  /** virtual destructor needed because of abstract class */
  virtual ~Observer () {/* nothing to be done */} 

  /** Notify the observer of a move. 
   * The observer has to be notified of every move of either player.
   *
   * \param myMove The last move in the game
   */
  virtual void update (const Move &myMove) =0;

protected:
  string player1; /// Name of the first player, playing the white tokens
  string player2; /// Name of the second player, playing the black tokens
};

#endif
