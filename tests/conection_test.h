#ifndef CONECTION_TEST_H
#define CONECTION_TEST_H

#include <gtest/gtest.h>
#include "mail_server.h"

using namespace ::testing::internal;

class ConnectionTest: public::testing::Test
{
protected:
 virtual void SetUp();
 virtual void TearDown();
 MailServer* ms;
 QMap<QString, QString>  user;
 QString str;
};

#endif // CONECTION_TEST_H
