#ifndef NETWORKMESSAGE_HPP_
#define NETWORKMESSAGE_HPP_

#include <cstdlib>
#include <string>

#define MAKE_DE_SERIALIZE_METHODS_BYTE( type, bytes ) \
  template < typename S >                             \
  void serialize( S& s, type& o ) {                   \
    s.value##bytes##b( o );                           \
  }                                                   \
  template < typename S >                             \
  void deserialize( S& s, type& o ) {                 \
    s.value##bytes##b( o );                           \
  }

MAKE_DE_SERIALIZE_METHODS_BYTE( int8_t, 1 );
MAKE_DE_SERIALIZE_METHODS_BYTE( int16_t, 2 );
MAKE_DE_SERIALIZE_METHODS_BYTE( int32_t, 4 );
MAKE_DE_SERIALIZE_METHODS_BYTE( int64_t, 8 );
MAKE_DE_SERIALIZE_METHODS_BYTE( uint8_t, 1 );
MAKE_DE_SERIALIZE_METHODS_BYTE( uint16_t, 2 );
MAKE_DE_SERIALIZE_METHODS_BYTE( uint32_t, 4 );
MAKE_DE_SERIALIZE_METHODS_BYTE( uint64_t, 8 );
MAKE_DE_SERIALIZE_METHODS_BYTE( float, 4 );
MAKE_DE_SERIALIZE_METHODS_BYTE( double, 8 );
#if defined( NETWORKINGHELPER_WINDOWS_LONGDOUBLE_8_BYTES )
MAKE_DE_SERIALIZE_METHODS_BYTE( long double, 8 );
#else
MAKE_DE_SERIALIZE_METHODS_BYTE( long double, 16 );
#endif

template < typename S >
void serialize( S& s, std::string& o ) {
  s.text1b( o, 1024 );
}
template < typename S >
void deserialize( S& s, std::string& o ) {
  s.text1b( o, 1024 );
}

#include <bitsery/adapter/buffer.h>
#include <bitsery/bitsery.h>
#include <bitsery/traits/array.h>
#include <bitsery/traits/deque.h>
#include <bitsery/traits/forward_list.h>
#include <bitsery/traits/list.h>
#include <bitsery/traits/string.h>
#include <bitsery/traits/vector.h>
#include <sstream>
#include <vector>

#include "networkingHelper/_export.hpp"

namespace NetworkingHelper {

using BitseryBuffer = std::vector< uint8_t >;
using OutputAdapter = bitsery::OutputBufferAdapter< BitseryBuffer >;
using InputAdapter = bitsery::InputBufferAdapter< BitseryBuffer >;

class NETWORKINGHELPER_EXPORT NetworkMessage {
  public:
  NetworkMessage();
  NetworkMessage( NetworkingHelper::NetworkMessage const& other );
  NetworkMessage( std::string const& topic, std::string const& content );
  virtual ~NetworkMessage();

  template < typename T >
  static NetworkingHelper::NetworkMessage from( std::string const& topic, T const& value ) {
    NetworkingHelper::NetworkMessage ret;

    ret.setTopic( topic );
    std::stringstream contentString;

    BitseryBuffer buffer;
    size_t writtenSize = bitsery::quickSerialization( OutputAdapter{ buffer }, value );
    for( int i = 0; i < writtenSize; i++ ) {
      contentString << buffer[i];
    }

    ret.setContent( contentString.str() );

    return ret;
  }

  template < typename T >
  T to( std::string const& topic ) const {
    if( this->getTopic() != topic ) {
      throw std::invalid_argument( "wrong type for topic '" + this->getTopic() + "'!" );
    }
    std::stringstream contentString;
    contentString << this->getContent();
    contentString.seekg( 0, std::ios_base::beg );
    T ret{};

    BitseryBuffer buffer;
    for( int i = 0; i < this->getContent().size(); i++ ) {
      buffer.push_back( this->getContent().at( i ) );
    }
    std::pair< bitsery::ReaderError, bool > state = bitsery::quickDeserialization( InputAdapter{ buffer.begin(), buffer.size() }, ret );

    return ret;
  }

  std::string getTopic() const;
  std::string getContent() const;

  private:
  void setTopic( std::string const& value );
  void setContent( std::string const& value );

  private:
  class impl;
  impl* pimpl;

  private:
  friend class bitsery::Access;
  template < typename S >
  void serialize( S& s ) {
    s.text1b( this->getTopic(), 1024 );
    s.text1b( this->getContent(), 1024 );
  }
  template < typename S >
  void deserialize( S& s ) {
    std::string tmp;
    s.text1b( tmp, 1024 );
    this->setTopic( tmp );
    s.text1b( tmp, 1024 );
    this->setContent( tmp );
  }
};

}  // namespace NetworkingHelper

#endif  // NETWORKMESSAGE_HPP_