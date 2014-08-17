#ifndef _PLAYER_H
#define _PLAYER_H

#include "Move.hh"

/** This interface must be implemented by every entity that will function as
 * a player, e.g. computer player, human player.
 * This means that every player has to be derived from the Player Interface.
 *
 * The tournament player will also implement this interface.
 */
class Player {
public:
  /** When constructing a player, 
   * it must be notified of the color it is playing.
   *
   * \param initColor Color of the player's tokens. Default is white.
   */
  Player (const char initColor = 'w') : color (initColor) {}
  /** virtual destructor needed because of abstract class */
  virtual ~Player() { /* nothing to be done */}
  /** Returns the move made by the player. 
   * \pre The move should be correct!
   * \return Move. Hast to be deleted by caller.
   */
  virtual Move *getMove() =0;
  /** Initialization of the game: Place the king to a valid position.
   * \pre The move should be correct.
   * @return Move. Position of the King must be in target position.
   * Move has to be deleted by caller.
   */
  virtual Move *setKing() =0;
protected:
  char color;
};

#endif
