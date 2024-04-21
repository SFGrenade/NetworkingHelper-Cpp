#include <cstdlib>
#include <gtest/gtest.h>
#include <limits>
#include <networkingHelper/networkMessage.hpp>
#include <networkingHelper/subscription.hpp>
#include <string>

class MyClass {
  public:
  bool operator==( MyClass const& other ) const {
    bool ret = true;
    ret = ret && ( this->my_int8_t == other.my_int8_t );
    ret = ret && ( this->my_int16_t == other.my_int16_t );
    ret = ret && ( this->my_int32_t == other.my_int32_t );
    ret = ret && ( this->my_int64_t == other.my_int64_t );
    ret = ret && ( this->my_uint8_t == other.my_uint8_t );
    ret = ret && ( this->my_uint16_t == other.my_uint16_t );
    ret = ret && ( this->my_uint32_t == other.my_uint32_t );
    ret = ret && ( this->my_uint64_t == other.my_uint64_t );
    ret = ret && ( std::abs( this->my_float - other.my_float ) <= std::numeric_limits< float >::epsilon() );
    ret = ret && ( std::abs( this->my_double - other.my_double ) <= std::numeric_limits< double >::epsilon() );
    ret = ret && ( std::abs( this->my_long_double - other.my_long_double ) <= std::numeric_limits< long double >::epsilon() );
    ret = ret && ( this->my_std_string == other.my_std_string );
    return ret;
  }

  private:
  int8_t my_int8_t = 8;
  int16_t my_int16_t = 16;
  int32_t my_int32_t = 32;
  int64_t my_int64_t = 64;
  uint8_t my_uint8_t = 8;
  uint16_t my_uint16_t = 16;
  uint32_t my_uint32_t = 32;
  uint64_t my_uint64_t = 64;
  float my_float = 3.14F;
  double my_double = 3.1415;
  long double my_long_double = 3.141592L;
  std::string my_std_string = "MyTestString";

  private:
  friend class bitsery::Access;
  template < typename S >
  void serialize( S& s ) {
    s.value< sizeof( decltype( my_int8_t ) ) >( my_int8_t );
    s.value< sizeof( decltype( my_int16_t ) ) >( my_int16_t );
    s.value< sizeof( decltype( my_int32_t ) ) >( my_int32_t );
    s.value< sizeof( decltype( my_int64_t ) ) >( my_int64_t );
    s.value< sizeof( decltype( my_uint8_t ) ) >( my_uint8_t );
    s.value< sizeof( decltype( my_uint16_t ) ) >( my_uint16_t );
    s.value< sizeof( decltype( my_uint32_t ) ) >( my_uint32_t );
    s.value< sizeof( decltype( my_uint64_t ) ) >( my_uint64_t );
    s.value< sizeof( decltype( my_float ) ) >( my_float );
    s.value< sizeof( decltype( my_double ) ) >( my_double );
    s.value< sizeof( decltype( my_long_double ) ) >( my_long_double );
    s.text1b( my_std_string, 1024 );
  }
  template < typename S >
  void deserialize( S& s ) {
    s.value< sizeof( decltype( my_int8_t ) ) >( my_int8_t );
    s.value< sizeof( decltype( my_int16_t ) ) >( my_int16_t );
    s.value< sizeof( decltype( my_int32_t ) ) >( my_int32_t );
    s.value< sizeof( decltype( my_int64_t ) ) >( my_int64_t );
    s.value< sizeof( decltype( my_uint8_t ) ) >( my_uint8_t );
    s.value< sizeof( decltype( my_uint16_t ) ) >( my_uint16_t );
    s.value< sizeof( decltype( my_uint32_t ) ) >( my_uint32_t );
    s.value< sizeof( decltype( my_uint64_t ) ) >( my_uint64_t );
    s.value< sizeof( decltype( my_float ) ) >( my_float );
    s.value< sizeof( decltype( my_double ) ) >( my_double );
    s.value< sizeof( decltype( my_long_double ) ) >( my_long_double );
    s.text1b( my_std_string, 1024 );
  }
};

TEST( NetworkingHelper, ClassConversion ) {
  MyClass myMessage;

  std::function< void( NetworkingHelper::NetworkMessage const& ) > myCallback = [myMessage]( NetworkingHelper::NetworkMessage const& message ) {
    EXPECT_EQ( myMessage, message.to< MyClass >( "MyClass" ) ) << "message:\n" + message.getTopic() + "\n" + message.getContent();
  };
  NetworkingHelper::Subscription sub( myCallback );

  sub( NetworkingHelper::NetworkMessage::from< MyClass >( "MyClass", myMessage ) );
}
