#include <gtest/gtest.h>
#include <networkingHelper/bus.hpp>
#include <networkingHelper/pair.hpp>
#include <networkingHelper/pubSub.hpp>
#include <networkingHelper/pushPull.hpp>
#include <networkingHelper/reqRep.hpp>
#include <networkingHelper/survResp.hpp>

TEST( NetworkingHelper, ConstructorTest01 ) {
  NetworkingHelper::Bus* network = new NetworkingHelper::Bus( "tcp://127.0.0.1:50001", true );
  EXPECT_NE( network, nullptr );
  delete network;
}

TEST( NetworkingHelper, ConstructorTest02 ) {
  NetworkingHelper::Pair0* network = new NetworkingHelper::Pair0( "tcp://127.0.0.1:50002", true );
  EXPECT_NE( network, nullptr );
  delete network;
}

TEST( NetworkingHelper, ConstructorTest03 ) {
  NetworkingHelper::Pair1* network = new NetworkingHelper::Pair1( "tcp://127.0.0.1:50003", true );
  EXPECT_NE( network, nullptr );
  delete network;
}

TEST( NetworkingHelper, ConstructorTest04 ) {
  NetworkingHelper::PubSub* network = new NetworkingHelper::PubSub( "tcp://127.0.0.1:50004", true );
  EXPECT_NE( network, nullptr );
  delete network;
}

TEST( NetworkingHelper, ConstructorTest05 ) {
  NetworkingHelper::PushPull* network = new NetworkingHelper::PushPull( "tcp://127.0.0.1:50005", true );
  EXPECT_NE( network, nullptr );
  delete network;
}

TEST( NetworkingHelper, ConstructorTest06 ) {
  NetworkingHelper::ReqRep* network = new NetworkingHelper::ReqRep( "tcp://127.0.0.1:50006", true );
  EXPECT_NE( network, nullptr );
  delete network;
}

TEST( NetworkingHelper, ConstructorTest07 ) {
  NetworkingHelper::SurvResp* network = new NetworkingHelper::SurvResp( "tcp://127.0.0.1:50007", true );
  EXPECT_NE( network, nullptr );
  delete network;
}
