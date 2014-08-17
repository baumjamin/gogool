#ifndef TOURNAMENTPLAYER_HH_
#define TOURNAMENTPLAYER_HH_

#include "Move.hh"
#include "Observer.hh"
#include "Player.hh"
#include "IPv4TCPSocket.hh"
#include <iostream>

/** Socket information */
static const int BUFFERSIZE = 30;
static const int LASCA_PORT = 4242;

/** Packet types in communication */
static const char MOVE = '0';
static const char KINGMOVE = '1';
static const char INVALID_MOVE = '2';
static const char END_OF_GAME = '3';

/** Packet types in setup */
static const char COLOR_NEGOTIATION = '4';
static const char OBSERVER = '5';
static const char INVALID = '6';


/** The Tournament Player connects a game with a master using a TCP Socket
 */
class TournamentPlayer : public Observer, public Player {
	
public:
  /** Simplified constructor. 
   * TournamentPlayer generates its own socket. 
   * @pre Use only for clients.
   * @param myIdentity 'w' or 'b' for players, 'o' for observers.
   * @param masterIP The IP-adress of the master
   */
  TournamentPlayer(const char myIdentity, const char *masterIP);

  /** Constructor. 
   * @param socket Communication socket. 
   *               Will be deleted in TournamentPlayer's destructor.
   * @param myColor Color of this player 
   * @param isObserver Runs in observer mode.
   * @param isMaster Runs in master mode.
   */
  TournamentPlayer(IPv4TCPSocket* socket, 
		   const char myColor = 'w', 
		   const bool isObserver = false, 
		   const bool isMaster = false);

  /** Destructor.
   * Virtual destructor needed because of polymorphic use.
   */
  virtual ~TournamentPlayer();
	
  /** Sents move from second player to the master.
   * @pre The move MUST be valid.
   * @param move Move from other player (e.g. AI).
   */
  virtual void update(const Move &move);
	
  /** Waits for a move sent by the master. 
   * @return The move performed by the opponent network player.
   * When the network player performed an illegal move, the returned move will be 0.
   */
  virtual Move *getMove();


  /** Waits for a move sent by the master. 
   * @return The move performed by the opponent network player.
   * When the network player performed an illegal move, the returned move will be 0.
   */
  virtual Move *setKing();	

private:
  /** Clear the communication buffer */
  void clearBuffer();
  /** The communication buffer */
  char buffer[BUFFERSIZE];
  /** Move last received from master */
  Move lastMove;
  /** Socket for communication with the master */
  IPv4TCPSocket* socket;
  /** Runs in observer mode */
  bool isObserver;
  /** Runs in master mode */
  bool isMaster;
};

#endif /*TOURNAMENTPLAYER_HH_*/
