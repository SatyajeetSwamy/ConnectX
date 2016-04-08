/**
 * Unit Tests for ConnectX class
 **/

#include <gtest/gtest.h>
#include <iostream>
#include <assert.h>
#include "ConnectX.h"

using namespace std;

class ConnectXTest : public ::testing::Test
{
  protected:
    ConnectXTest(){}
    virtual ~ConnectXTest(){}
    virtual void SetUp(){}
    virtual void TearDown(){}
};
/*
TEST(ConnectXTest, sanityCheck)
{
  ASSERT_TRUE(true);
}
*/
TEST(ConnectXTest, checkingToggle)
{
  ConnectX ctest(7,6,7);
  ctest.placePiece(5);
  ASSERT_EQ(1, ctest.whoseTurn()); 
  ctest.placePiece(1);
  ASSERT_EQ(2, ctest.whoseTurn());
}

TEST(ConnectXTest, isSafe)
{
  ConnectX ctest;

  ASSERT_EQ(2, ctest.whoseTurn());
  ctest.placePiece(2);
  ASSERT_EQ(1, ctest.whoseTurn());
  ctest.placePiece(2);
  ASSERT_EQ(2, ctest.whoseTurn());
  ctest.placePiece(2);
  ASSERT_EQ(1, ctest.whoseTurn());
  ctest.placePiece(2);
  ASSERT_EQ(2, ctest.whoseTurn());

  ctest.showBoard();
}

/*
   TEST(ConnectXTest, isUnSafeOutofBounds)
   {
   ConnectX ctest;

   ASSERT_EQ(-1, ctest.at(500, 3));
   }
   */

//I think the bug is here
TEST(ConnectXTest, Errorwithwidth)
{
  ConnectX ctest(5,4,5);
  ASSERT_EQ(-1, ctest.at(-2,2));
}


TEST(ConnectXTest, Errorwithsecheight)
{
  ConnectX ctest(4,3,4);
  ASSERT_EQ(-1, ctest.at(1,6));
}

//I think the other bug is here!
TEST(ConnectXTest, ErrorwithHeight2)
{
  ConnectX ctest(3,2,3);
  ASSERT_EQ(-1, ctest.at(4,1));
}


TEST(ConnectXTest, InvalidWidthHt)
{
  ConnectX ctest(5,4,5);
  ASSERT_EQ(-1, ctest.at(-2,-2));
}


TEST(ConnectXTest, ErrorwithHT)
{
  ConnectX ctest(3,2,3);
  ASSERT_EQ(-1, ctest.at(6,6));
}

TEST(ConnectXTest, Errorwithwidth2)
{
  ConnectX ctest(-4,3,4);
  ASSERT_EQ(2, ctest.whoseTurn());
}


TEST(ConnectXTest, WrongX)
{
  ConnectX ctest(5,3,0);
  ASSERT_EQ(2, ctest.whoseTurn());
}
TEST(ConnectXTest, ErrorwithHeigt)
{
  ConnectX ctest(5,-4,5);
  ASSERT_EQ(2, ctest.whoseTurn());
}

TEST(ConnectXTest, ErrorwithHeight)
{
  ConnectX ctest(5,4,5);
  ASSERT_EQ(-1, ctest.at(2,-2));
}
TEST(ConnectXTest, ErrorwithX)
{
  ConnectX ctest(5,3,-5);
  ASSERT_EQ(2, ctest.whoseTurn());
}

TEST(ConnectXTest, ShowBoard)
{
  ConnectX ctest(5,4,5);
  ctest.placePiece(2);
  ctest.placePiece(1);
  ctest.showBoard();
  ASSERT_EQ(2, ctest.whoseTurn());
}

TEST(ConnectXTest, invalidheight1)
{
  ConnectX ctest(4,0,4);
  ASSERT_EQ(2, ctest.whoseTurn());
}

TEST(ConnectXTest, unidentifiedwidth)
{
  ConnectX ctest(0,3,5);
  ASSERT_EQ(2, ctest.whoseTurn());
}



