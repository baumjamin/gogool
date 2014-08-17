#include "IPv4TCPSocket.hh"
#include <iostream>

IPv4TCPSocket::IPv4TCPSocket(const string& localIP, int localPort,
			     const string& remoteIP, int remotePort) {

  init();
	
  setLocalIP(localIP);
  setLocalPort(localPort);
  setRemoteIP(remoteIP);
  setRemotePort(remotePort);
  allowReuse();
  bind();
}

IPv4TCPSocket::IPv4TCPSocket(int localSocketFD) {
  this->localSocketFD=localSocketFD;
}

IPv4TCPSocket::~IPv4TCPSocket() {
  close();
}

void IPv4TCPSocket::init() {
	
  if ((localSocketFD = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    throw runtime_error("Socket error: "+string(strerror(errno)));
  }
	
  remote.sin_family=AF_INET;
  memset(&remote.sin_zero, 0, sizeof(remote.sin_zero));
	
  local.sin_family=AF_INET;
  memset(&local.sin_zero, 0, sizeof(local.sin_zero));
}

void IPv4TCPSocket::setLocalIP(int ip) {
  local.sin_addr.s_addr = ip;
}

void IPv4TCPSocket::setLocalIP(const string& ip) {
	
  if(ip=="any")
    local.sin_addr.s_addr = INADDR_ANY;
  else
    local.sin_addr.s_addr = inet_addr(ip.c_str());
}
	
void IPv4TCPSocket::setRemoteIP(int ip) {
  remote.sin_addr.s_addr = ip;
}

void IPv4TCPSocket::setRemoteIP(const string& ip) {
	
  if(ip=="255.255.255.255")
    allowBroadcast();
		
  remote.sin_addr.s_addr = inet_addr(ip.c_str());
}

string IPv4TCPSocket::getRemoteIP() {
	
  in_addr tmp;      
  tmp.s_addr = remote.sin_addr.s_addr;
  return inet_ntoa(tmp);
}
	
void IPv4TCPSocket::setLocalPort(int port) {
  local.sin_port = htons(port);
}

void IPv4TCPSocket::setRemotePort(int port) {
  remote.sin_port = htons(port);
}

void IPv4TCPSocket::bind() {
		
  if ( ::bind(localSocketFD, (struct sockaddr*) &local, sizeof(local)) < 0) {
    throw runtime_error("Binding error: "+string(strerror(errno)));
  }
}

void IPv4TCPSocket::allowBroadcast() {
	
  int a = 1;
  if( setsockopt(localSocketFD, SOL_SOCKET, SO_BROADCAST, &a, sizeof(a)) < 0) {
    throw runtime_error("Option Error: " + string(strerror(errno)));
  }
}

void IPv4TCPSocket::allowReuse() {
	
  int a = 1;
  if( setsockopt(localSocketFD, SOL_SOCKET, SO_REUSEADDR, &a, sizeof(a)) < 0) {
    throw runtime_error("Option Error: " + string(strerror(errno)));
  }
}

void IPv4TCPSocket::waitForConnection() {
	
  listen (localSocketFD, 15);
	
  remoteLen=sizeof(remote);
  if ((remoteSocketFD=accept(localSocketFD, (struct sockaddr*)&remote, &remoteLen)) < 0) {
    throw runtime_error("Accept error: "+string(strerror(errno)));
  }

  socketFD = remoteSocketFD;
}

void IPv4TCPSocket::connectToServer() {

  if (connect(localSocketFD, (struct sockaddr*)&remote, sizeof(remote)) < 0) {
    throw runtime_error("Connect error: "+string(strerror(errno)));
  }
	
  socketFD = localSocketFD;
}

void IPv4TCPSocket::close() {
  ::close(remoteSocketFD);
  ::close(localSocketFD);
}

int IPv4TCPSocket::send(void* msg, unsigned length) {

  numberOfBytesSent = write(socketFD, msg, length);
	
  if( numberOfBytesSent < 0) {
    throw runtime_error("Send Error: " + string(strerror(errno)));
  } else {
    return numberOfBytesSent;
  }
}

int IPv4TCPSocket::receive(void* msg, unsigned length) {
	
  numberOfBytesReceived = read(socketFD,msg, length);
	
  if (numberOfBytesReceived < 0) {
    throw runtime_error("Receive Error: " + string(strerror(errno)));
  } else  {
    return numberOfBytesReceived;
  }
}

int IPv4TCPSocket::getLocalSocketFD() {
  return localSocketFD;
}
