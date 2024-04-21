#include "networkingHelper/networkMessage.hpp"

namespace NetworkingHelper {

class NetworkMessage::impl {
  public:
  std::string topic_;
  std::string content_;
};

NetworkMessage::NetworkMessage() : pimpl( new impl ) {
  this->pimpl->topic_ = "";
  this->pimpl->content_ = "";
}

NetworkMessage::NetworkMessage( NetworkingHelper::NetworkMessage const& other ) : pimpl( new impl ) {
  this->pimpl->topic_ = other.pimpl->topic_;
  this->pimpl->content_ = other.pimpl->content_;
}

NetworkMessage::NetworkMessage( std::string const& topic, std::string const& content ) : pimpl( new impl ) {
  this->pimpl->topic_ = topic;
  this->pimpl->content_ = content;
}

NetworkMessage::~NetworkMessage() {
  delete this->pimpl;
  this->pimpl = nullptr;
}

std::string NetworkMessage::getTopic() const {
  return this->pimpl->topic_;
}

std::string NetworkMessage::getContent() const {
  return this->pimpl->content_;
}

void NetworkMessage::setTopic( std::string const& value ) {
  this->pimpl->topic_ = value;
}

void NetworkMessage::setContent( std::string const& value ) {
  this->pimpl->content_ = value;
}

}  // namespace NetworkingHelper
