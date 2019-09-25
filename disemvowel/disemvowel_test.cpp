#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char *r = disemvowel((char*) "");
  ASSERT_STREQ("",r );
  free(r);
}

TEST(Disemvowel, HandleNoVowels) {
  char *r = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", r);
  free(r);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char *r = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", r);
  free(r);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char *r =  disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", r);
  free(r);
}

TEST(Disemvowel, HandlePunctuation) {
  char *r = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", r);
  free(r);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  char *r = disemvowel(str);
  ASSERT_STREQ("xyz", r);
  free(r);
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
