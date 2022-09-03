cmake_minimum_required(VERSION 3.0.0)
project(BlackJack VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(blackjack blackjack.cpp Game.cpp Deck.cpp Player.cpp House.cpp Hand.cpp Card.cpp GenericPlayer.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)