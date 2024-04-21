#ifndef BUS_HPP_
#define BUS_HPP_

#include "networkingHelper/_export.hpp"
#include "networkingHelper/nngWrap.hpp"

namespace NetworkingHelper {

class NETWORKINGHELPER_EXPORT Bus : public NngWrap {
  public:
  Bus( std::string const& host, bool isServer );
  ~Bus() override;

  protected:
  virtual bool canSend() const override;
  virtual void didSend() override;
  virtual bool canRecv() const override;
  virtual void didRecv() override;
};

}  // namespace NetworkingHelper

#endif /* BUS_HPP_ */
