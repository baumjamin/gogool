#include "Move.hh"

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

/** Offset for X. Shift ascii value to int. */
const int Move::xOffset = 97; // 97: ascii value of 'a'
/** Offset for Y. */
const int Move::yOffset = 1; // 1: map to array

/** Constructor.
 * Maps Chess-style board coordinates to computer science-style array coordinates
 * @param fromX Row of the start position, from 'a' (white ground line) to 'h' (black ground line).
 * @param fromY Column of the start position, from 1 to 8
 * @param toX Row of the target position, from 'a' (white ground line) to 'h' (black ground line)..
 * @param toY Column of the target position, from 1 to 8.
 */
Move::Move (char fromX, int fromY, char toX, int toY, bool setKing) : setKing (setKing) {
  this->fromX = (int) fromX - xOffset; 
  this->fromY = fromY - yOffset; 
  this->toX = (int) toX - xOffset; 
  this->toY = toY - yOffset; 
}

/** Destructor.
 * Virtual destructor needed so that object can be used polymorphic.
 */
Move::~Move () { /* nothing to be done */ }


/** Move sets the King.
 * @return True, if Move sets the king.
 */
bool Move::moveSetsKing () const {
  return setKing;
}

/** Compare two moves.
 * @param other Other move.
 * @return True, if moves are equal.
 */
bool Move::operator== (const Move &other) const {
  return ((this->fromX == other.fromX) && (this->fromY == other.fromY) && 
	  (this->toX == other.toX) && (this->toY == other.toY));
}

/* No operator "bool" for class Move, validity of move is responsibility of board */

/** Get row of start position 
 * @return Row of start position
 */
int Move::getFromX() const {
  return fromX;
}
/** Get column of start position 
 * @return Column of start position
 */
int Move::getFromY() const {
  return fromY;
}
/** Get row of target position 
 * @return Row of target position
 */
int Move::getToX() const {
  return toX;
}
/** Get column of target position 
 * @return Column of target position
 */
int Move::getToY() const {
  return toY;
}

/** Print Move.
 * @param out Outstream
 * @param move Move to print
 * @return Outstream for chain printing
 */
std::ostream &operator<< (std::ostream &out, const Move &move) {
  out << (char) (move.fromX + move.xOffset) << move.fromY + move.yOffset
      << (char) (move.toX + move.xOffset) << move.toY + move.yOffset;
  return out;
}

/** Input Move.
 * @param in instream
 * @param move Move to input
 * @return Instream for chain printing
 */
std::istream &operator>> (std::istream &in, Move &move) {
  char fromX, toX;
  int fromY, toY;

  in >> fromX >> fromY >> toX >> toY;

  move.fromX = fromX - move.xOffset;
  move.fromY = fromY - move.yOffset;
  move.toX = toX - move.xOffset;
  move.toY = toY - move.yOffset;

  return in;
}

