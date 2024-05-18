#ifndef PAIR_HPP_
#define PAIR_HPP_

#include "networkingHelper/_export.hpp"
#include "networkingHelper/nngWrap.hpp"

namespace NetworkingHelper {

class NETWORKINGHELPER_API_CLASSES Pair0 : public NngWrap {
  public:
  Pair0( std::string const& host, bool isServer );
  ~Pair0() override;

  protected:
  virtual bool canSend() const override;
  virtual void didSend() override;
  virtual bool canRecv() const override;
  virtual void didRecv() override;
};

class NETWORKINGHELPER_API_CLASSES Pair1 : public NngWrap {
  public:
  Pair1( std::string const& host, bool isServer );
  ~Pair1() override;

  protected:
  virtual bool canSend() const override;
  virtual void didSend() override;
  virtual bool canRecv() const override;
  virtual void didRecv() override;
};

}  // namespace NetworkingHelper

#endif /* PAIR_HPP_ */
