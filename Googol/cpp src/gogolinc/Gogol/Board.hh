/** @brief class Board implements Gameboard of Gogol
  * @author Fabian Glaser
  * @date 20.06.2007
  */

#ifndef _Board_h
#define _Board_h

#include "Move.hh"
#include "Position.hh"

class Board{
    public:
	/** Konstruktor. */
	Board();
	
	Board(const Board &other);
	
	/** Function to test if an instance of Move ist valid
	  * @param[in] Move-Object
	  * @return boolean: return true, if move is valid, else false  
	  */
	bool is_move_valid(Move& move,char color) const;
	
	/** Function to test if an init Move of king ist valid
		* @param[in] reference to Move-object
		* @return boolean: return true, if move is valid, else false  
		*/
	bool is_king_move_valid(Move& move, char color) const;
	
	/** Get-Function, which returns the value of Field[x][y];
	  * @param[in] int x, int y
	  * @return int
	  */  
	int get_Field(int x, int y) const;
	
	/** Function, which sets Move
	  * @param[in] reference to Move-object
	  * @return boolean: return true, if move has been set, else false
	  */
	
	bool setMove(const Move& move, char color = 'w');
	
	/** Function, which prooves if the setting of stones in field is a winning-setting
	  * @return boolean: true, if setting is a winning-setting, else false
	  */
	bool win();
	
	/** Function, which returns const Pointer to Position of King
	  * @param[in]: color of King as char
	  * &return const Position*
	  */
	const Position* getKingsPos(char color) const;
		
    private:
	//** copy Board */
	void copy(const Board &other);
	/** array to store positions of stones */
	int field[8][8];
	/** Position of white King */
	Position kingw;
	/** Position of black King */
	Position kingb;
	
	/** enumeration to simplify management of stones */
	enum stones {kb=-3,pb=-2,free=0,pw=2,kw=3};
	
};

#endif
