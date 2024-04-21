#include "networkingHelper/pubSub.hpp"

#include <nng/protocol/pubsub0/sub.h>

namespace NetworkingHelper {

PubSub::PubSub( std::string const &host, bool isPublisher )
    : NngWrap( host, isPublisher, isPublisher ? NngWrap::SocketType::Pub0 : NngWrap::SocketType::Sub0 ) {
  if( !isPublisher ) {
    callNngSockFunc< int, const char *, const void *, size_t >( nng_socket_set, NNG_OPT_SUB_SUBSCRIBE, nullptr, 0 );
  }
  connectSocket();
}

PubSub::~PubSub() {}

bool PubSub::canSend() const {
  return getIsServer();  // isPublisher
}

void PubSub::didSend() {}

bool PubSub::canRecv() const {
  return !getIsServer();  // isPublisher
}

void PubSub::didRecv() {}

}  // namespace NetworkingHelper
