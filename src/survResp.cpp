#include "networkingHelper/survResp.hpp"

namespace NetworkingHelper {

SurvResp::SurvResp( std::string const& host, bool isServer )
    : NngWrap( host, isServer, isServer ? NngWrap::SocketType::Surveyor0 : NngWrap::SocketType::Respondent0 ) {
  connectSocket();
}

SurvResp::~SurvResp() {}

bool SurvResp::canSend() const {
  return true;
}

void SurvResp::didSend() {}

bool SurvResp::canRecv() const {
  return true;
}

void SurvResp::didRecv() {}

}  // namespace NetworkingHelper
