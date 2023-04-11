#include "../src/include/base64.h"
#include <string.h>
#include <gtest/gtest.h>

TEST(fool_algorithm_base64, CppBase) {
for (int i = 0; i < 9999990; i++) {
const char *str = "1232sadasdasdasd"
                  "sdfasdasdasdasdaswd2dasdxasdasdasdasdsa"
                  "sdfasdasdasdasdaswd2dasdxasdasdasdasdsa"
                  "sdfasdasdasdasdaswd2dasdxasdasdasdasdsa"
                  "sdfasdasdasdasdaswd2dasdxasdasdasdasdsa"
                  "sdfasdasdasdasdaswd2dasdxasdasdasdasdsa"
                  "sdfasdasdasdasdaswd2dasdxasdasdasdasdsa"
                  "sdfasdasdasdasdaswd2dasdxasdasdasdasdsa"
                  "sdfasdasdasdasdaswd2dasdxasdasdasdasdsa"
                  "sdfasdasdasdasdaswd2dasdxasdasdasdasdsa"
                  "sdfasdasdasdasdaswd2dasdxasdasdasdasdsa"
                  "sdfasdasdasdasdaswd2dasdxasdasdasdasdsa";
int len = strlen(str);
unsigned char *ret = base64Encode(str, len);
//            printf("%s", ret);
}

}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();


}