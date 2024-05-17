#ifndef REQREP_HPP_
#define REQREP_HPP_

#include "networkingHelper/_export.hpp"
#include "networkingHelper/nngWrap.hpp"

namespace NetworkingHelper {

class NETWORKINGHELPER_API ReqRep : public NngWrap {
  public:
  enum class Status { Receiving, Sending };

  public:
  ReqRep( std::string const& host, bool isServer );
  ~ReqRep() override;

  protected:
  virtual bool canSend() const override;
  virtual void didSend() override;
  virtual bool canRecv() const override;
  virtual void didRecv() override;

  private:
  ReqRep::Status status_;
};

}  // namespace NetworkingHelper

#endif /* REQREP_HPP_ */
