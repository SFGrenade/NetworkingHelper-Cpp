#ifndef SUBSCRIPTION_HPP_
#define SUBSCRIPTION_HPP_

#include <functional>

#include "networkingHelper/_export.hpp"
#include "networkingHelper/networkMessage.hpp"

namespace NetworkingHelper {

class NETWORKINGHELPER_EXPORT Subscription {
  public:
  Subscription();
  Subscription( NetworkingHelper::Subscription const& other );
  Subscription( std::function< void( NetworkingHelper::NetworkMessage const& ) > callback );
  ~Subscription();

  void operator()( NetworkingHelper::NetworkMessage const& message ) const;

  private:
  class impl;
  impl* pimpl;
};

}  // namespace NetworkingHelper

#endif /* SUBSCRIPTION_HPP_ */
