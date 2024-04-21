#ifndef PUBSUB_HPP_
#define PUBSUB_HPP_

#include "networkingHelper/_export.hpp"
#include "networkingHelper/nngWrap.hpp"

namespace NetworkingHelper {

class NETWORKINGHELPER_EXPORT PubSub : public NngWrap {
  public:
  PubSub( std::string const& host, bool isPublisher );
  ~PubSub() override;

  protected:
  virtual bool canSend() const override;
  virtual void didSend() override;
  virtual bool canRecv() const override;
  virtual void didRecv() override;
};

}  // namespace NetworkingHelper

#endif /* PUBSUB_HPP_ */
