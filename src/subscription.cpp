#include "networkingHelper/subscription.hpp"

namespace NetworkingHelper {

class Subscription::impl {
  public:
  std::function< void( NetworkMessage const& ) > callback;
};

Subscription::Subscription() : pimpl( new impl ) {
  pimpl->callback = nullptr;
}

Subscription::Subscription( NetworkingHelper::Subscription const& other ) : pimpl( new impl ) {
  pimpl->callback = other.pimpl->callback;
}

Subscription::Subscription( std::function< void( NetworkingHelper::NetworkMessage const& ) > callback ) : pimpl( new impl ) {
  pimpl->callback = callback;
}

Subscription::~Subscription() {
  delete pimpl;
  pimpl = nullptr;
}

void Subscription::operator()( NetworkingHelper::NetworkMessage const& message ) const {
  pimpl->callback( message );
}

}  // namespace NetworkingHelper
