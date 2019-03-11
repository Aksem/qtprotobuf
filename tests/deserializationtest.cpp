/*
 * MIT License
 *
 * Copyright (c) 2019 Alexey Edelev <semlanik@gmail.com>
 *
 * This file is part of qtprotobuf project https://git.semlanik.org/semlanik/qtprotobuf
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and
 * to permit persons to whom the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "deserializationtest.h"
#include "qtprotobuf.h"
#include "simplefixedint32message.h"
#include "simplefixedint64message.h"

using namespace qtprotobufnamespace::tests;
using namespace qtprotobuf::tests;
using namespace qtprotobuf;

DeserializationTest::DeserializationTest()
{
    QtProtobuf::init();
}

TEST_F(DeserializationTest, FixedInt32MessageDeserializeTest)
{
    SimpleFixedInt32Message test;
    test.deserialize(QByteArray::fromHex("0d0f000000"));
    ASSERT_EQ(test.testFieldFixedInt32(), 15);

    test.deserialize(QByteArray::fromHex("0d2c010000"));
    ASSERT_EQ(test.testFieldFixedInt32(), 300);

    test.deserialize(QByteArray::fromHex("0d09000100"));
    ASSERT_EQ(test.testFieldFixedInt32(), 65545);

    test.deserialize(QByteArray::fromHex("0d00000000"));
    ASSERT_EQ(test.testFieldFixedInt32(), 0);

    test.deserialize(QByteArray::fromHex("0d2c010000"));
    ASSERT_EQ(test.testFieldFixedInt32(), 300);

    test.deserialize(QByteArray::fromHex("0d00010000"));
    ASSERT_EQ(test.testFieldFixedInt32(), UINT8_MAX + 1);

    test.deserialize(QByteArray::fromHex("0d00000100"));
    ASSERT_EQ(test.testFieldFixedInt32(), UINT16_MAX + 1);

    test.deserialize(QByteArray::fromHex("0dff000000"));
    ASSERT_EQ(test.testFieldFixedInt32(), UINT8_MAX);

    test.deserialize(QByteArray::fromHex("0dffff0000"));
    ASSERT_EQ(test.testFieldFixedInt32(), UINT16_MAX);

    test.deserialize(QByteArray::fromHex("0dffffffff"));
    ASSERT_EQ(test.testFieldFixedInt32(), UINT32_MAX);
}

TEST_F(DeserializationTest, FixedInt64MessageDeserializeTest)
{
    SimpleFixedInt64Message test;
    test.deserialize(QByteArray::fromHex("090f00000000000000"));
    ASSERT_EQ(test.testFieldFixedInt64(), 15);


    test.deserialize(QByteArray::fromHex("092c01000000000000"));
    ASSERT_EQ(test.testFieldFixedInt64(), 300);

    test.deserialize(QByteArray::fromHex("090900010000000000"));
    ASSERT_EQ(test.testFieldFixedInt64(), 65545);

    test.deserialize(QByteArray::fromHex("090000000000000000"));
    ASSERT_EQ(test.testFieldFixedInt64(), 0);

    test.deserialize(QByteArray::fromHex("090001000000000000"));
    ASSERT_EQ(test.testFieldFixedInt64(), UINT8_MAX + 1);

    test.deserialize(QByteArray::fromHex("090000010000000000"));
    ASSERT_EQ(test.testFieldFixedInt64(), UINT16_MAX + 1);

    test.deserialize(QByteArray::fromHex("090000000001000000"));
    ASSERT_EQ(test.testFieldFixedInt64(), (unsigned long long)(UINT32_MAX) + 1);

    test.deserialize(QByteArray::fromHex("09ff00000000000000"));
    ASSERT_EQ(test.testFieldFixedInt64(), UINT8_MAX);

    test.deserialize(QByteArray::fromHex("09ffff000000000000"));
    ASSERT_EQ(test.testFieldFixedInt64(), UINT16_MAX);

    test.deserialize(QByteArray::fromHex("09ffffffff00000000"));
    ASSERT_EQ(test.testFieldFixedInt64(), UINT32_MAX);

    test.deserialize(QByteArray::fromHex("09ffffffffffffffff"));
    ASSERT_EQ(test.testFieldFixedInt64(), UINT64_MAX);
}
