#include "networkingHelper/reqRep.hpp"

namespace NetworkingHelper {

ReqRep::ReqRep( std::string const& host, bool isServer )
    : NngWrap( host, isServer, isServer ? NngWrap::SocketType::Rep0 : NngWrap::SocketType::Req0 ),
      status_( isServer ? ReqRep::Status::Receiving : ReqRep::Status::Sending ) {
  connectSocket();
}

ReqRep::~ReqRep() {}

bool ReqRep::canSend() const {
  return status_ == ReqRep::Status::Sending;
}

void ReqRep::didSend() {
  status_ = ReqRep::Status::Receiving;
}

bool ReqRep::canRecv() const {
  return status_ == ReqRep::Status::Receiving;
}

void ReqRep::didRecv() {
  status_ = ReqRep::Status::Sending;
}

}  // namespace NetworkingHelper
