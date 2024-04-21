#include "networkingHelper/pair.hpp"

namespace NetworkingHelper {

Pair0::Pair0( std::string const& host, bool isServer ) : NngWrap( host, isServer, NngWrap::SocketType::Pair0 ) {
  connectSocket();
}

Pair0::~Pair0() {}

bool Pair0::canSend() const {
  return true;
}

void Pair0::didSend() {}

bool Pair0::canRecv() const {
  return true;
}

void Pair0::didRecv() {}

Pair1::Pair1( std::string const& host, bool isServer ) : NngWrap( host, isServer, NngWrap::SocketType::Pair1 ) {
  connectSocket();
}

Pair1::~Pair1() {}

bool Pair1::canSend() const {
  return true;
}

void Pair1::didSend() {}

bool Pair1::canRecv() const {
  return true;
}

void Pair1::didRecv() {}

}  // namespace NetworkingHelper
