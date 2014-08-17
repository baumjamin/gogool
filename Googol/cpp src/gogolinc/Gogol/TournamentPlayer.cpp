#include "TournamentPlayer.hh"
#include <sstream>
#include <string>

using namespace std;


/** Simplified constructor. */
TournamentPlayer::TournamentPlayer(const char myIdentity, const char *masterIP) 
  : Player (myIdentity) {
	
  // Init fields
  clearBuffer();
  this->isMaster = false;

  try {
    switch (myIdentity) {
    case 'o':
      // Observer
      this->isObserver = true;
      this->socket = new IPv4TCPSocket("any", LASCA_PORT+1, masterIP, LASCA_PORT);
      break;
    case 'w':
      // TP is white player to client, black player to master
      this->isObserver = false;
      this->socket = new IPv4TCPSocket("any", LASCA_PORT+2, masterIP, LASCA_PORT);
      break;
    case 'b':
      // TP is black player to client, white player to master
      this->isObserver = false;
      this->socket = new IPv4TCPSocket("any", LASCA_PORT+3, masterIP, LASCA_PORT);
      break;
    }
    
    // Connect to master
    socket->connectToServer();
    cout << "Connection with Master established." << endl;
    
    // Negotiate color / mode
    buffer[0] = COLOR_NEGOTIATION;
    if (isObserver) {
      buffer[1] = OBSERVER;
    } else {
      buffer[1] = color;	
    }
    
    cout << "Requested color / mode: " << buffer[1] << endl;
    
    // send and wait for answer
    socket->send(&buffer,2);
    clearBuffer();
    socket->receive(&buffer,BUFFERSIZE);

    // error handling - catch exceptions from socket
  } catch (exception &e) {
    cout  << e.what() << endl;
    exit(1);
  }	
    
  cout << "Returned color: " << buffer[1] << endl;
  
  // error handling
  if (buffer[1] == color || (int) buffer[1] == OBSERVER) {
    cout << "Color / mode negotiation successful." << endl;
  } else {
    throw runtime_error("ERROR: Color negotiation failed! "
			"Clients must connect in the following order:\n"
			"1. observer\n"
			"2. tournament ai\n"
			"3. ai tournament");
  }
}

TournamentPlayer::TournamentPlayer(IPv4TCPSocket* socket, const char myColor, 
				   const bool isObserver, const bool isMaster) 
  : Player (myColor) {
	
  // Init fields
  clearBuffer();

  this->isObserver = isObserver;
  this->isMaster = isMaster;
  this->socket = socket;
		
  // running in master mode
  if(isMaster) {
    // negotiate color / mode
    bool negotiate = true;
    while(negotiate) {
      socket->waitForConnection();
      cout << "Client connected." << endl;
		
      clearBuffer();
      socket->receive(&buffer,BUFFERSIZE);
			
      if(buffer[0] == COLOR_NEGOTIATION) {
	if(buffer[1] == color || buffer[1] == OBSERVER) {
	  negotiate = false;
	  socket->send(&buffer,2);
	} else {
	  buffer[1] = INVALID;
	  socket->send(&buffer,2);
	}
      } else {
	socket->close();
	cout << "ERROR: Wrong type while waiting for color negotiation!" << endl;
	cout << "Type: " << (int) buffer[0] << endl;
      }
    }
  } else { // running in client mode
    // Connect to master
    socket->connectToServer();
    cout << "Connection with Master established." << endl;

    // Negotiate color / mode
    buffer[0] = COLOR_NEGOTIATION;
    if (isObserver) {
      buffer[1] = OBSERVER;
    } else {
      buffer[1] = color;	
    }
		
    cout << "Requested color / mode: " << buffer[1] << endl;
		
    // send and wait for answer
    socket->send(&buffer,2);
    clearBuffer();
    socket->receive(&buffer,BUFFERSIZE);
		
    cout << "Returned color: " << buffer[1] << endl;
		
    // error handling
    if (buffer[1] == color || (int) buffer[1] == OBSERVER) {
      cout << "Color / mode negotiation successful." << endl;
    } else {
      throw runtime_error("ERROR: Color negotiation failed! "
			  "Clients must connect in the following order:\n"
			  "1. observer\n"
			  "2. tournament ai\n"
			  "3. ai tournament");
    }
  }
}

TournamentPlayer::~TournamentPlayer() { 
  delete socket;
}

void TournamentPlayer::clearBuffer() {
  for (int i = 0; i < BUFFERSIZE; ++i) {
    buffer[i]=0;
  }
}

// Send move to master
void TournamentPlayer::update(const Move &move) {
  // Just spectating
  if(isObserver) { return; }

  // compare move with our last move and skip
  // => send only moves from opponent
  if (lastMove == move) { return; }

  if(isMaster) {
    cout << "Sending move to Clients (" << socket->getRemoteIP() << "): ";
  } else {
    cout << "Sending move to Master: ";
  }

  clearBuffer();
	
  // Header
  if (move.moveSetsKing()) {
    buffer[0] = KINGMOVE;
  } else {
    buffer[0] = MOVE;
  }

  // code players color in buffer[1]?
	
  // Encode moves
  ostringstream oss;
  oss << move;
  string sMove = oss.str();
  strcpy (&buffer[1], sMove.c_str());
  cout << move << endl;

  // Send
  socket->send(&buffer,6);
  // buffer has 6 bytes: message header, 4 characters in move, terminating \0.
}

// Wait for move from Master
Move *TournamentPlayer::getMove() {
  clearBuffer();
  socket->receive(&buffer,BUFFERSIZE);
	
  cout << "Move received: ";
	
  switch (buffer[0]) {		
  case MOVE:
    // Decode move
    lastMove = Move (buffer[1], atoi (&buffer[2]), buffer[3], atoi (&buffer[4]), false);
    cout << lastMove << endl;
    break;
	
  case KINGMOVE: // kingmove cannot be expected using getMove		
  case INVALID_MOVE:
    cerr << "INVALID MOVE" << endl;
    cerr << "Player " /* << (int) buffer[1] */ 
	 << " has tried to perform an invalid move." << endl;
    break;
			
  case END_OF_GAME:
    cout << "GAME OVER" << endl;
    cout << "Player " /* << (int) buffer[1]*/ << " wins." << endl;
    break;
		
  default:
    throw runtime_error("ERROR: Unexpected packet type received! "
			"Type: " + (int) buffer[0] );
    break;
  }
	
  return new Move (lastMove); // return copy of move that has own memory
}

// Wait for move from Master
Move *TournamentPlayer::setKing() {
  clearBuffer();
  socket->receive(&buffer,BUFFERSIZE);
	
  cout << "Move received: ";
	
  switch (buffer[0]) {		
  case KINGMOVE:
    // Decode move
    lastMove = Move (buffer[1], atoi (&buffer[2]), buffer[3], atoi (&buffer[4]), true);
    cout << lastMove;
    break;

  case MOVE: // move cannot be expected using setKing	
  case INVALID_MOVE:
    cerr << "INVALID MOVE" << endl;
    cerr << "Player " /* << (int) buffer[1] */ 
	 << " has tried to perform an invalid move." << endl;
    break;
			
  case END_OF_GAME:
    cout << "GAME OVER" << endl;
    cout << "Player " /* << (int) buffer[1]*/ << " wins." << endl;
    break;
		
  default:
    throw runtime_error("ERROR: Unexpected packet type received! "
			"Type: " + (int) buffer[0] );
    break;
  }
	
  return new Move (lastMove); // return copy of move that has own memory
}
