#include <gtest/gtest.h>
#include "src/encoder.hpp"

#include <iterator>
#include <algorithm>
#include <vector>

TEST(Encoder, ParserTest)
{
    const unsigned int SIZE = 128;
    const unsigned int ARRAYSIZE = SIZE/16;

    std::string mytext;
    std::vector<unsigned int> a(ARRAYSIZE, 0);
    std::vector<unsigned int> b(ARRAYSIZE, 0);

    mytext = encode::print(a);
    encode::parse(mytext, b);
    std::string parsed = encode::print(b);
    std::string parsedExpected("00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 \n");
    EXPECT_EQ(parsedExpected, parsed);
}

TEST(Encoder, EncodeTest1)
{
    const unsigned int SIZE = 128;
    const unsigned int ARRAYSIZE = SIZE/16;
    std::vector<unsigned int> a(ARRAYSIZE, 0);
    std::vector<unsigned int> b(ARRAYSIZE, 0);

    std::string cleartext("c58f4047 d73fe36a 24be2846 e2ebe432 a30d28bd bda19675 3f95d074 b6f69434");
    encode::parse(cleartext, a);

    encode::encode<SIZE>(a, b);
    const std::string cipher = encode::print(b);
    const std::string cipherExpected("d7bfe36f f7ffef7f ffffffff ffffffff ffffffff fffffeff bffffefd bff7d474 \n");

    EXPECT_EQ(cipherExpected, cipher);
}

TEST(Encoder, DecodeTest)
{
    const unsigned int SIZE = 128;
    const unsigned int ARRAYSIZE = SIZE/16;
    std::string mytext("a91db473 fcea8db4 f3bb434a 8dba2f16 51abc87e 92c44759 5c1a16d3 6111c6f4");

    std::vector<unsigned int> a(ARRAYSIZE, 0);
    std::vector<unsigned int> b(ARRAYSIZE, 0);

    encode::parse(mytext, a);
    //encode::decode(a, b);
    const std::string cleartext(encode::print(b));
    const std::string expectedCleartext("c58f4047 d73fe36a 24be2846 e2ebe432 a30d28bd bda19675 3f95d074 b6f69434");

    //EXPECT_EQ(expectedCleartext, cleartext);
}
