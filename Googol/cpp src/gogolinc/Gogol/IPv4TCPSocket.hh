#ifndef IPV4TCPSOCKET_H_
#define IPV4TCPSOCKET_H_

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdexcept>

using namespace std;

/** Wrapper Class for an IPv4 based TCP Socket.
 */
class IPv4TCPSocket {
	
public:
	
  IPv4TCPSocket();
  ~IPv4TCPSocket();
	
  IPv4TCPSocket(const string& localIP, int localPort,
		const string& remoteIP, int remotePort);
	
  IPv4TCPSocket(int localSocketFD);
	
  int getLocalSocketFD();
	
  int send(void* msg, unsigned length);
  int receive(void* msg, unsigned length);
	
  void setLocalIP(int ip);
  void setLocalIP(const string& ip);
	
  void setRemoteIP(int ip);
  void setRemoteIP(const string& ip);
	
  void setLocalPort(int port);
  void setRemotePort(int port);
  string getRemoteIP();
	
  void waitForConnection();
  void connectToServer();
  void close();
	
private:
		
  struct sockaddr_in local;
  struct sockaddr_in remote;
  struct sockaddr_in currentClient;
	
  socklen_t currentClientLen;
  socklen_t remoteLen;
	
  int localSocketFD;
  int remoteSocketFD;
  int socketFD;
  int numberOfBytesReceived;
  int numberOfBytesSent;
	
  void init();
  void bind();
  void allowBroadcast();
  void allowReuse();		
};

#endif /*IPV4TCPSOCKET_H_*/
