/**
 * Author: R-CO
 * E-mail: daniel1820kobe@gmail.com
 **/
#ifndef SIMPLE_TEST_H
#define SIMPLE_TEST_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int test_pass_count;
extern int test_fail_count;

#define ADD_TEST_FUNCTION(func)      \
  printf("=== %s() START\n", #func); \
  func();                            \
  printf("%s() END ===\n", #func);

#define EXPECT_EQ(a, b)                                                        \
  if ((a) == (b)) {                                                            \
    ++test_pass_count;                                                         \
  } else {                                                                     \
    ++test_fail_count;                                                         \
    printf("%s:%d\nEXPECT_EQ(%s, %s) is FAIL.\n", __FILE__, __LINE__, #a, #b); \
  }

#define EXPECT_NE(a, b)                                                        \
  if ((a) != (b)) {                                                            \
    ++test_pass_count;                                                         \
  } else {                                                                     \
    ++test_fail_count;                                                         \
    printf("%s:%d\nEXPECT_NE(%s, %s) is FAIL.\n", __FILE__, __LINE__, #a, #b); \
  }

#define EXPECT_GE(a, b)                                                        \
  if ((a) >= (b)) {                                                            \
    ++test_pass_count;                                                         \
  } else {                                                                     \
    ++test_fail_count;                                                         \
    printf("%s:%d\nEXPECT_GE(%s, %s) is FAIL.\n", __FILE__, __LINE__, #a, #b); \
  }

#define EXPECT_LE(a, b)                                                        \
  if ((a) >= (b)) {                                                            \
    ++test_pass_count;                                                         \
  } else {                                                                     \
    ++test_fail_count;                                                         \
    printf("%s:%d\nEXPECT_LE(%s, %s) is FAIL.\n", __FILE__, __LINE__, #a, #b); \
  }

#define EXPECT_GT(a, b)                                                        \
  if ((a) > (b)) {                                                             \
    ++test_pass_count;                                                         \
  } else {                                                                     \
    ++test_fail_count;                                                         \
    printf("%s:%d\nEXPECT_GT(%s, %s) is FAIL.\n", __FILE__, __LINE__, #a, #b); \
  }

#define EXPECT_LT(a, b)                                                        \
  if ((a) < (b)) {                                                             \
    ++test_pass_count;                                                         \
  } else {                                                                     \
    ++test_fail_count;                                                         \
    printf("%s:%d\nEXPECT_LT(%s, %s) is FAIL.\n", __FILE__, __LINE__, #a, #b); \
  }

#define PRINT_STATICS()                                                   \
  printf("====================\n");                                       \
  printf("test PASS count:[%d]\ntest FAIL count:[%d]\n", test_pass_count, \
         test_fail_count)

#define TEST_START()                     \
  test_pass_count = test_fail_count = 0; \
  printf("===== TEST START =====\n")

#ifdef __cplusplus
}
#endif

#endif  // end of define SIMPLE_TEST_H
