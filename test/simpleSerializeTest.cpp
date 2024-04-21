#include <gtest/gtest.h>
#include <networkingHelper/networkMessage.hpp>
#include <networkingHelper/subscription.hpp>

#define EXPECT_CALLBACK( type, name )                                                                                                      \
  std::function< void( NetworkingHelper::NetworkMessage const& ) > name = [myMessage]( NetworkingHelper::NetworkMessage const& message ) { \
    EXPECT_EQ( myMessage, message.to< type >( #type ) )                                                                                    \
        << #type << " was unable to be converted correctly from: '" << message.getTopic() << "'/'" << message.getContent() << "'";         \
  };

TEST( NetworkingHelper, Int8Conversion ) {
  int8_t myMessage = 8;

  EXPECT_CALLBACK( int8_t, myCallback );
  NetworkingHelper::Subscription sub( myCallback );

  sub( NetworkingHelper::NetworkMessage::from< int8_t >( "int8_t", myMessage ) );
}

TEST( NetworkingHelper, Int16Conversion ) {
  int16_t myMessage = 16;

  EXPECT_CALLBACK( int16_t, myCallback );
  NetworkingHelper::Subscription sub( myCallback );

  sub( NetworkingHelper::NetworkMessage::from< int16_t >( "int16_t", myMessage ) );
}

TEST( NetworkingHelper, Int32Conversion ) {
  int32_t myMessage = 32;

  EXPECT_CALLBACK( int32_t, myCallback );
  NetworkingHelper::Subscription sub( myCallback );

  sub( NetworkingHelper::NetworkMessage::from< int32_t >( "int32_t", myMessage ) );
}

TEST( NetworkingHelper, Int64Conversion ) {
  int64_t myMessage = 64;

  EXPECT_CALLBACK( int64_t, myCallback );
  NetworkingHelper::Subscription sub( myCallback );

  sub( NetworkingHelper::NetworkMessage::from< int64_t >( "int64_t", myMessage ) );
}

TEST( NetworkingHelper, Uint8Conversion ) {
  uint8_t myMessage = 8;

  EXPECT_CALLBACK( uint8_t, myCallback );
  NetworkingHelper::Subscription sub( myCallback );

  sub( NetworkingHelper::NetworkMessage::from< uint8_t >( "uint8_t", myMessage ) );
}

TEST( NetworkingHelper, Uint16Conversion ) {
  uint16_t myMessage = 16;

  EXPECT_CALLBACK( uint16_t, myCallback );
  NetworkingHelper::Subscription sub( myCallback );

  sub( NetworkingHelper::NetworkMessage::from< uint16_t >( "uint16_t", myMessage ) );
}

TEST( NetworkingHelper, Uint32Conversion ) {
  uint32_t myMessage = 32;

  EXPECT_CALLBACK( uint32_t, myCallback );
  NetworkingHelper::Subscription sub( myCallback );

  sub( NetworkingHelper::NetworkMessage::from< uint32_t >( "uint32_t", myMessage ) );
}

TEST( NetworkingHelper, Uint64Conversion ) {
  uint64_t myMessage = 64;

  EXPECT_CALLBACK( uint64_t, myCallback );
  NetworkingHelper::Subscription sub( myCallback );

  sub( NetworkingHelper::NetworkMessage::from< uint64_t >( "uint64_t", myMessage ) );
}

TEST( NetworkingHelper, FloatConversion ) {
  float myMessage = 3.14F;

  EXPECT_CALLBACK( float, myCallback );
  NetworkingHelper::Subscription sub( myCallback );

  sub( NetworkingHelper::NetworkMessage::from< float >( "float", myMessage ) );
}

TEST( NetworkingHelper, DoubleConversion ) {
  double myMessage = 3.1415;

  EXPECT_CALLBACK( double, myCallback );
  NetworkingHelper::Subscription sub( myCallback );

  sub( NetworkingHelper::NetworkMessage::from< double >( "double", myMessage ) );
}
/*
TEST( NetworkingHelper, LongDoubleConversion ) {
  long double myMessage = 3.141592L;

  EXPECT_CALLBACK( long double, myCallback );
  NetworkingHelper::Subscription sub( myCallback );

  sub( NetworkingHelper::NetworkMessage::from< long double >( "long double", myMessage ) );
}
*/
TEST( NetworkingHelper, StringConversion ) {
  std::string myMessage = "MyTestString";

  EXPECT_CALLBACK( std::string, myCallback );
  NetworkingHelper::Subscription sub( myCallback );

  sub( NetworkingHelper::NetworkMessage::from< std::string >( "std::string", myMessage ) );
}
