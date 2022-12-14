/*
 * Copyright (C) 2016 Fundación Inria Chile
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     unittests
 * @{
 *
 * @file
 * @brief       Test cases for the AES128-CMAC hash implementation
 *
 * @author      José Ignacio Alamos <jose.alamos@inria.cl>
 *
 * @}
 */

#include <inttypes.h>
#include <string.h>

#include "tests-hashes.h"
#include "embUnit/embUnit.h"
#include "hashes/aes128_cmac.h"
#include "crypto/ciphers.h"

static const uint8_t AES128_CMAC_KEY[16] = {
    0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
    0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
};

static const uint8_t TEST_EMPTY_EXP[16] = {
    0xbb, 0x1d, 0x69, 0x29, 0xe9, 0x59, 0x37, 0x28,
    0x7f, 0xa3, 0x7d, 0x12, 0x9b, 0x75, 0x67, 0x46
};

static const uint8_t TEST_1_INP[16] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96,
    0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a
};

static const uint8_t TEST_1_EXP[16] = {
    0x07, 0x0a, 0x16, 0xb4, 0x6b, 0x4d, 0x41, 0x44,
    0xf7, 0x9b, 0xdd, 0x9d, 0xd0, 0x4a, 0x28, 0x7c
};

static const uint8_t TEST_2_INP[40] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96,
    0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
    0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c,
    0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
    0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11
};

static const uint8_t TEST_2_EXP[16] = {
    0xdf, 0xa6, 0x67, 0x47, 0xde, 0x9a, 0xe6, 0x30,
    0x30, 0xca, 0x32, 0x61, 0x14, 0x97, 0xc8, 0x27
};

static const uint8_t TEST_3_INP[64] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96,
    0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
    0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c,
    0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
    0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11,
    0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17,
    0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
};

static const uint8_t TEST_3_EXP[16] = {
    0x51, 0xf0, 0xbe, 0xbf, 0x7e, 0x3b, 0x9d, 0x92,
    0xfc, 0x49, 0x74, 0x17, 0x79, 0x36, 0x3c, 0xfe
};

static int calc_and_compare_hash(const uint8_t *hash, size_t size, const uint8_t *expected)
{
    uint8_t digest[16];
    aes128_cmac_context_t ctx;

    aes128_cmac_init(&ctx, AES128_CMAC_KEY, 16);
    aes128_cmac_update(&ctx, hash, size);
    aes128_cmac_final(&ctx, digest);
    return memcmp(digest, expected, 16);
}

static void test_hashes_cmac(void)
{
    TEST_ASSERT_EQUAL_INT(calc_and_compare_hash(NULL, 0, TEST_EMPTY_EXP), 0);
    TEST_ASSERT_EQUAL_INT(calc_and_compare_hash(TEST_1_INP, 16, TEST_1_EXP), 0);
    TEST_ASSERT_EQUAL_INT(calc_and_compare_hash(TEST_2_INP, 40, TEST_2_EXP), 0);
    TEST_ASSERT_EQUAL_INT(calc_and_compare_hash(TEST_3_INP, 64, TEST_3_EXP), 0);
}

static void test_hashes_cmac_keysize(void)
{
    aes128_cmac_context_t ctx;

    TEST_ASSERT_EQUAL_INT(aes128_cmac_init(&ctx, AES128_CMAC_KEY, 15),
                          CIPHER_ERR_INVALID_KEY_SIZE);
    TEST_ASSERT_EQUAL_INT(aes128_cmac_init(&ctx, AES128_CMAC_KEY, 16),
                          CIPHER_INIT_SUCCESS);
}

Test *tests_hashes_cmac_tests(void)
{
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture(test_hashes_cmac),
        new_TestFixture(test_hashes_cmac_keysize),
    };

    EMB_UNIT_TESTCALLER(test_hashes_cmac, NULL, NULL, fixtures);

    return (Test *)&test_hashes_cmac;
}
