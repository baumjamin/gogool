#ifndef _MOVE_HH
#define _MOVE_HH

#include <iostream>
//using namespace std;

/** The Gogol Board
 * When starting the game, the basic layout of the board is as follows:
 *
 * Chess (Y) a   b   c   d   e   f   g   h  
 *     (X) ---------------------------------
 *      8  | b | b | b | b | b | b | b | b |  7
 *         --------------------------------- 
 *      7  |   |   |   |   |   |   |   |   |  6
 *         ---------------------------------
 *      6  |   |   |   |   |   |   |   |   |  5
 *         ---------------------------------
 *      5  |   |   |   |   |   |   |   |   |  4
 *         ---------------------------------
 *      4  |   |   |   |   |   |   |   |   |  3
 *         ---------------------------------
 *      3  |   |   |   |   |   |   |   |   |  2
 *         ---------------------------------
 *      2  |   |   |   |   |   |   |   |   |  1
 *         --------------------------------- 
 *      1  | w | w | w | w | w | w | w | w |  0
 *         --------------------------------- (X)
 *           0   1   2   3   4   5   6   7(Y)Array
 */

/** 
 * A Gogol move.
 */
class Move {
public:
  /** Constructor.
   * @param fromX Column of the start position, from 'a' (white ground line) to 'h' (black ground line).
   * @param fromY Row of the start position, from 1 to 8
   * @param toX Column of the target position, from 'a' (white ground line) to 'h' (black ground line)..
   * @param toY Row of the target position, from 1 to 8.
   * @param setKing Move sets the King, in this case fromX and fromY are irrelevant.
   */
  Move (char fromX = 'a', int fromY = 1, char toX = 'a', int toY = 1, bool setKing = false);

  /** Destructor.
   * Virtual destructor needed so that object can be used polymorphic.
   */
  virtual ~Move ();

  /** Compare two moves.
   * @param other Other move.
   * @return True, if moves are equal.
   */
  bool operator== (const Move &other) const;
  /* No operator "bool" for class Move, validity of move is responsibility of board */

  /** Move sets the King.
   * @return True, if Move sets the king.
   */
  bool moveSetsKing () const;

  /** Get row of start position 
   * @return Row of start position
   */
  int getFromX() const;
  /** Get column of start position 
   * @return Column of start position
   */
  int getFromY() const;
  /** Get row of target position 
   * @return Row of target position
   */
  int getToX() const;
  /** Get column of target position 
   * @return Column of target position
   */
  int getToY() const;

  /** Print Move.
   * @param out Output stream
   * @param move Move to print
   * @return Outstream for chain printing
   */
  friend std::ostream &operator<< (std::ostream &out, const Move &move);

  /** Input Move.
   * @param in instream
   * @param move Move to input
   * @return Instream for chain printing
   */
  friend std::istream &operator>> (std::istream &in, Move &move);

private:
  /** Row of the start position. */
  int fromX;
  /** Column of the start position */
  int fromY;
  /** Row of the target position */
  int toX;
  /** Column of the target position */
  int toY;
  /** Sets the King */
  bool setKing;

  /** Offset for X. Shift ascii value to int. */
  static const int xOffset;
  /** Offset for Y. */
  static const int yOffset;
};

#endif
