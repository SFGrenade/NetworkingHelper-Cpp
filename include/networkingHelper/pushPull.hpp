#ifndef PUSHPULL_HPP_
#define PUSHPULL_HPP_

#include "networkingHelper/_export.hpp"
#include "networkingHelper/nngWrap.hpp"

namespace NetworkingHelper {

class NETWORKINGHELPER_API_CLASSES PushPull : public NngWrap {
  public:
  PushPull( std::string const& host, bool isPusher );
  ~PushPull() override;

  protected:
  virtual bool canSend() const override;
  virtual void didSend() override;
  virtual bool canRecv() const override;
  virtual void didRecv() override;
};

}  // namespace NetworkingHelper

#endif /* PUSHPULL_HPP_ */
