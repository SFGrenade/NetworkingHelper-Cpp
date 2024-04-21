#include "networkingHelper/bus.hpp"

namespace NetworkingHelper {

Bus::Bus( std::string const& host, bool isServer ) : NngWrap( host, isServer, NngWrap::SocketType::Bus0 ) {
  connectSocket();
}

Bus::~Bus() {}

bool Bus::canSend() const {
  return true;
}

void Bus::didSend() {}

bool Bus::canRecv() const {
  return true;
}

void Bus::didRecv() {}

}  // namespace NetworkingHelper
