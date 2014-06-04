#ifndef TESTEMAIL_H
#define TESTEMAIL_H

#include <gtest/gtest.h>
#include "parser_of_string.h"

class TestEmailAndName : public::testing::Test
{
protected:
 virtual void SetUp();
 virtual void TearDown();

  ParserOfString* pos;
};

#endif // TESTEMAIL_H
