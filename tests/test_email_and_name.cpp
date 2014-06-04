#include "test_email_and_name.h"


void TestEmailAndName::SetUp()
{
  pos = new  ParserOfString;
}

void TestEmailAndName::TearDown()
{
  delete pos;
}

TEST_F(TestEmailAndName, testEmail){
  QString str = "From: Burberry Kisses <kisses@emails.burberry.com>";
  EXPECT_EQ (pos->parseToEmail(str),"kisses@emails.burberry.com");

  str = "sdasda324324sda32432 sdsas <savchenko.inc@gmail.com>dsfasfd  s fdsdfdf";
  EXPECT_EQ (pos->parseToEmail(str),"savchenko.inc@gmail.com");
  }

TEST_F(TestEmailAndName, testName){
  QString str ="From: EaseUS <newsletter@easeus.com>";
  QString rts = pos->parseByAuthor(str);
  EXPECT_EQ(rts,"EaseUS");
  }

TEST_F(TestEmailAndName, testLogin){

  QString str = "savchenko.inc@gmail.com";
  ASSERT_EQ(pos->parseToLogin(str),"savchenko.inc");

  str = "antons@interlink-ua.com";
  ASSERT_EQ(pos->parseToLogin(str),"antons");

  str = "ua@hostinger.com";
  ASSERT_EQ(pos->parseToLogin(str),"ua");

  str = "eBay@reply1.ebay.com";
  ASSERT_EQ(pos->parseToLogin(str),"eBay");

  str = "bestd22ea.l@rozetka.com.ua";
  ASSERT_EQ(pos->parseToLogin(str), "bestd22ea.l");
}
