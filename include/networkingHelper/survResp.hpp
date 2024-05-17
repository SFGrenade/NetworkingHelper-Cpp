#ifndef SURVRESP_HPP_
#define SURVRESP_HPP_

#include <vector>

#include "networkingHelper/_export.hpp"
#include "networkingHelper/nngWrap.hpp"

namespace NetworkingHelper {

class NETWORKINGHELPER_API SurvResp : public NngWrap {
  public:
  SurvResp( std::string const& host, bool isServer );
  ~SurvResp() override;

  protected:
  virtual bool canSend() const override;
  virtual void didSend() override;
  virtual bool canRecv() const override;
  virtual void didRecv() override;
};

}  // namespace NetworkingHelper

#endif /* SURVRESP_HPP_ */
