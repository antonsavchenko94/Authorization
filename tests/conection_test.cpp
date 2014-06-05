#include "conection_test.h"



void ConnectionTest::SetUp()
{
  str = "From: 'Anton Savchenko' <antons@interlink-ua.com>";
  user.insert("login","savchenko.inc");
  user.insert("password", "BanderaMozli");
  ms = new MailServer(user);

}

void ConnectionTest::TearDown()
{
 delete ms;
}

TEST_F(ConnectionTest, testConnection){

  ASSERT_TRUE(ms->imapConnection());
}

TEST_F(ConnectionTest, testConnectionUrl){

  EXPECT_TRUE(RE::FullMatch(ms->getImap(),RE("imaps://savchenko.inc:BanderaMozli@imap.gmail.com:993")));
}

//TEST_F(ConnectionTest, testParsing){
//  std::string std = ms->parsing(str).toStdString();
//  EXPECT_TRUE(RE::FullMatch(std, RE("^[a-zA-Z0-9_-]\x20\x20::\x20\x20([a-z0-9_\.-]+)@([a-z0-9_\.-]+)\.([a-z\.]{2,6})")));
//}
