// Copyright (c) 2013-2015 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Raven Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/test/unit_test.hpp>

#include "base58.h"
#include "key.h"
#include "uint256.h"
#include "util.h"
#include "utilstrencodings.h"
#include "test/test_raven.h"
#include "wallet/walletdb.h"
#include "streams.h"

#include <string>
#include <vector>

struct TestDerivation
{
    std::string pub;
    std::string prv;
    unsigned int nChild;
};

struct TestVector
{
    std::string strHexMaster;
    std::vector<TestDerivation> vDerive;

    explicit TestVector(std::string strHexMasterIn) : strHexMaster(strHexMasterIn)
    {}

    TestVector &operator()(std::string pub, std::string prv, unsigned int nChild)
    {
        vDerive.push_back(TestDerivation());
        TestDerivation &der = vDerive.back();
        der.pub = pub;
        der.prv = prv;
        der.nChild = nChild;
        return *this;
    }
};

TestVector test1 =
        TestVector("000102030405060708090a0b0c0d0e0f")
                ("xpub661MyMwAqRbcFtXgS5sYJABqqG9YLmC4Q1Rdap9gSE8NqtwybGhePY2gZ29ESFjqJoCu1Rupje8YtGqsefD265TMg7usUDFdp6W1EGMcet8",
                 "xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi",
                 0x80000000)
                ("xpub68Gmy5EdvgibQVfPdqkBBCHxA5htiqg55crXYuXoQRKfDBFA1WEjWgP6LHhwBZeNK1VTsfTFUHCdrfp1bgwQ9xv5ski8PX9rL2dZXvgGDnw",
                 "xprv9uHRZZhk6KAJC1avXpDAp4MDc3sQKNxDiPvvkX8Br5ngLNv1TxvUxt4cV1rGL5hj6KCesnDYUhd7oWgT11eZG7XnxHrnYeSvkzY7d2bhkJ7",
                 1)
                ("xpub6ASuArnXKPbfEwhqN6e3mwBcDTgzisQN1wXN9BJcM47sSikHjJf3UFHKkNAWbWMiGj7Wf5uMash7SyYq527Hqck2AxYysAA7xmALppuCkwQ",
                 "xprv9wTYmMFdV23N2TdNG573QoEsfRrWKQgWeibmLntzniatZvR9BmLnvSxqu53Kw1UmYPxLgboyZQaXwTCg8MSY3H2EU4pWcQDnRnrVA1xe8fs",
                 0x80000002)
                ("xpub6D4BDPcP2GT577Vvch3R8wDkScZWzQzMMUm3PWbmWvVJrZwQY4VUNgqFJPMM3No2dFDFGTsxxpG5uJh7n7epu4trkrX7x7DogT5Uv6fcLW5",
                 "xprv9z4pot5VBttmtdRTWfWQmoH1taj2axGVzFqSb8C9xaxKymcFzXBDptWmT7FwuEzG3ryjH4ktypQSAewRiNMjANTtpgP4mLTj34bhnZX7UiM",
                 2)
                ("xpub6FHa3pjLCk84BayeJxFW2SP4XRrFd1JYnxeLeU8EqN3vDfZmbqBqaGJAyiLjTAwm6ZLRQUMv1ZACTj37sR62cfN7fe5JnJ7dh8zL4fiyLHV",
                 "xprvA2JDeKCSNNZky6uBCviVfJSKyQ1mDYahRjijr5idH2WwLsEd4Hsb2Tyh8RfQMuPh7f7RtyzTtdrbdqqsunu5Mm3wDvUAKRHSC34sJ7in334",
                 1000000000)
                ("xpub6H1LXWLaKsWFhvm6RVpEL9P4KfRZSW7abD2ttkWP3SSQvnyA8FSVqNTEcYFgJS2UaFcxupHiYkro49S8yGasTvXEYBVPamhGW6cFJodrTHy",
                 "xprvA41z7zogVVwxVSgdKUHDy1SKmdb533PjDz7J6N6mV6uS3ze1ai8FHa8kmHScGpWmj4WggLyQjgPie1rFSruoUihUZREPSL39UNdE3BBDu76",
                 0);

TestVector test2 =
        TestVector("fffcf9f6f3f0edeae7e4e1dedbd8d5d2cfccc9c6c3c0bdbab7b4b1aeaba8a5a29f9c999693908d8a8784817e7b7875726f6c696663605d5a5754514e4b484542")
                ("xpub661MyMwAqRbcFW31YEwpkMuc5THy2PSt5bDMsktWQcFF8syAmRUapSCGu8ED9W6oDMSgv6Zz8idoc4a6mr8BDzTJY47LJhkJ8UB7WEGuduB",
                 "xprv9s21ZrQH143K31xYSDQpPDxsXRTUcvj2iNHm5NUtrGiGG5e2DtALGdso3pGz6ssrdK4PFmM8NSpSBHNqPqm55Qn3LqFtT2emdEXVYsCzC2U",
                 0)
                ("xpub69H7F5d8KSRgmmdJg2KhpAK8SR3DjMwAdkxj3ZuxV27CprR9LgpeyGmXUbC6wb7ERfvrnKZjXoUmmDznezpbZb7ap6r1D3tgFxHmwMkQTPH",
                 "xprv9vHkqa6EV4sPZHYqZznhT2NPtPCjKuDKGY38FBWLvgaDx45zo9WQRUT3dKYnjwih2yJD9mkrocEZXo1ex8G81dwSM1fwqWpWkeS3v86pgKt",
                 0xFFFFFFFF)
                ("xpub6ASAVgeehLbnwdqV6UKMHVzgqAG8Gr6riv3Fxxpj8ksbH9ebxaEyBLZ85ySDhKiLDBrQSARLq1uNRts8RuJiHjaDMBU4Zn9h8LZNnBC5y4a",
                 "xprv9wSp6B7kry3Vj9m1zSnLvN3xH8RdsPP1Mh7fAaR7aRLcQMKTR2vidYEeEg2mUCTAwCd6vnxVrcjfy2kRgVsFawNzmjuHc2YmYRmagcEPdU9",
                 1)
                ("xpub6DF8uhdarytz3FWdA8TvFSvvAh8dP3283MY7p2V4SeE2wyWmG5mg5EwVvmdMVCQcoNJxGoWaU9DCWh89LojfZ537wTfunKau47EL2dhHKon",
                 "xprv9zFnWC6h2cLgpmSA46vutJzBcfJ8yaJGg8cX1e5StJh45BBciYTRXSd25UEPVuesF9yog62tGAQtHjXajPPdbRCHuWS6T8XA2ECKADdw4Ef",
                 0xFFFFFFFE)
                ("xpub6ERApfZwUNrhLCkDtcHTcxd75RbzS1ed54G1LkBUHQVHQKqhMkhgbmJbZRkrgZw4koxb5JaHWkY4ALHY2grBGRjaDMzQLcgJvLJuZZvRcEL",
                 "xprvA1RpRA33e1JQ7ifknakTFpgNXPmW2YvmhqLQYMmrj4xJXXWYpDPS3xz7iAxn8L39njGVyuoseXzU6rcxFLJ8HFsTjSyQbLYnMpCqE2VbFWc",
                 2)
                ("xpub6FnCn6nSzZAw5Tw7cgR9bi15UV96gLZhjDstkXXxvCLsUXBGXPdSnLFbdpq8p9HmGsApME5hQTZ3emM2rnY5agb9rXpVGyy3bdW6EEgAtqt",
                 "xprvA2nrNbFZABcdryreWet9Ea4LvTJcGsqrMzxHx98MMrotbir7yrKCEXw7nadnHM8Dq38EGfSh6dqA9QWTyefMLEcBYJUuekgW4BYPJcr9E7j",
                 0);

TestVector test3 =
        TestVector("4b381541583be4423346c643850da4b320e46a87ae3d2a4e6da11eba819cd4acba45d239319ac14f863b8d5ab5a0d0c64d2e8a1e7d1457df2e5a3c51c73235be")
                ("xpub661MyMwAqRbcEZVB4dScxMAdx6d4nFc9nvyvH3v4gJL378CSRZiYmhRoP7mBy6gSPSCYk6SzXPTf3ND1cZAceL7SfJ1Z3GC8vBgp2epUt13",
                 "xprv9s21ZrQH143K25QhxbucbDDuQ4naNntJRi4KUfWT7xo4EKsHt2QJDu7KXp1A3u7Bi1j8ph3EGsZ9Xvz9dGuVrtHHs7pXeTzjuxBrCmmhgC6",
                 0x80000000)
                ("xpub68NZiKmJWnxxS6aaHmn81bvJeTESw724CRDs6HbuccFQN9Ku14VQrADWgqbhhTHBaohPX4CjNLf9fq9MYo6oDaPPLPxSb7gwQN3ih19Zm4Y",
                 "xprv9uPDJpEQgRQfDcW7BkF7eTya6RPxXeJCqCJGHuCJ4GiRVLzkTXBAJMu2qaMWPrS7AANYqdq6vcBcBUdJCVVFceUvJFjaPdGZ2y9WACViL4L",
                 0);

void RunTest(const TestVector &test)
{
    std::vector<unsigned char> seed = ParseHex(test.strHexMaster);
    CExtKey key;
    CExtPubKey pubkey;
    key.SetSeed(seed.data(), seed.size());
    pubkey = key.Neuter();
    for (const TestDerivation &derive : test.vDerive)
    {
        unsigned char data[74];
        key.Encode(data);
        pubkey.Encode(data);

        // Test private key
        CRavenExtKey b58key;
        b58key.SetKey(key);
        BOOST_CHECK(b58key.ToString() == derive.prv);

        CRavenExtKey b58keyDecodeCheck(derive.prv);
        CExtKey checkKey = b58keyDecodeCheck.GetKey();
        assert(checkKey == key); //ensure a base58 decoded key also matches

        // Test public key
        CRavenExtPubKey b58pubkey;
        b58pubkey.SetKey(pubkey);
        BOOST_CHECK(b58pubkey.ToString() == derive.pub);

        CRavenExtPubKey b58PubkeyDecodeCheck(derive.pub);
        CExtPubKey checkPubKey = b58PubkeyDecodeCheck.GetKey();
        assert(checkPubKey == pubkey); //ensure a base58 decoded pubkey also matches

        // Derive new keys
        CExtKey keyNew;
        BOOST_CHECK(key.Derive(keyNew, derive.nChild));
        CExtPubKey pubkeyNew = keyNew.Neuter();
        if (!(derive.nChild & 0x80000000))
        {
            // Compare with public derivation
            CExtPubKey pubkeyNew2;
            BOOST_CHECK(pubkey.Derive(pubkeyNew2, derive.nChild));
            BOOST_CHECK(pubkeyNew == pubkeyNew2);
        }
        key = keyNew;
        pubkey = pubkeyNew;

        CDataStream ssPub(SER_DISK, CLIENT_VERSION);
        ssPub << pubkeyNew;
        BOOST_CHECK(ssPub.size() == 75);

        CDataStream ssPriv(SER_DISK, CLIENT_VERSION);
        ssPriv << keyNew;
        BOOST_CHECK(ssPriv.size() == 75);

        CExtPubKey pubCheck;
        CExtKey privCheck;
        ssPub >> pubCheck;
        ssPriv >> privCheck;

        BOOST_CHECK(pubCheck == pubkeyNew);
        BOOST_CHECK(privCheck == keyNew);
    }
}

BOOST_FIXTURE_TEST_SUITE(bip32_tests, BasicTestingSetup)

    BOOST_AUTO_TEST_CASE(bip32_test_1)
    {
        BOOST_TEST_MESSAGE("Running BIP32 Test 1");
        RunTest(test1);
    }

    BOOST_AUTO_TEST_CASE(bip32_test_2)
    {
        BOOST_TEST_MESSAGE("Running BIP32 Test 2");
        RunTest(test2);
    }

    BOOST_AUTO_TEST_CASE(bip32_test_3)
    {
        BOOST_TEST_MESSAGE("Running BIP32 Test 3");
        RunTest(test3);
    }


    BOOST_AUTO_TEST_CASE(abrs_bip39_master_pubkey_seed_id_regression)
    {
        BOOST_TEST_MESSAGE("ABRS BIP39 seed_id regression: Hash160(BIP32 master pubkey)");

        // Synthetic 64-byte inputs only. These are not real wallet seeds.
        const std::vector<unsigned char> seedA = ParseHex(
            "000102030405060708090a0b0c0d0e0f"
            "101112131415161718191a1b1c1d1e1f"
            "202122232425262728292a2b2c2d2e2f"
            "303132333435363738393a3b3c3d3e3f");

        const std::vector<unsigned char> seedB = ParseHex(
            "fffefdfcfbfaf9f8f7f6f5f4f3f2f1f0"
            "efeeedecebeae9e8e7e6e5e4e3e2e1e0"
            "dfdedddcdbdad9d8d7d6d5d4d3d2d1d0"
            "cfcecdcccbcac9c8c7c6c5c4c3c2c1c0");

        BOOST_REQUIRE_EQUAL(seedA.size(), 64U);
        BOOST_REQUIRE_EQUAL(seedB.size(), 64U);
        BOOST_REQUIRE(seedA != seedB);

        CExtKey masterA;
        CExtKey masterB;

        masterA.SetSeed(seedA.data(), seedA.size());
        masterB.SetSeed(seedB.data(), seedB.size());

        const CPubKey pubA = masterA.Neuter().pubkey;
        const CPubKey pubB = masterB.Neuter().pubkey;

        BOOST_REQUIRE(pubA.IsFullyValid());
        BOOST_REQUIRE(pubB.IsFullyValid());

        const CKeyID idA = pubA.GetID();
        const CKeyID idB = pubB.GetID();

        BOOST_CHECK(idA != idB);

        const std::string brokenConstant =
            "cb9f3b7c6fb1cf2c13a40637c189bdd066a272b4";

        BOOST_CHECK(idA.GetHex() != brokenConstant);
        BOOST_CHECK(idB.GetHex() != brokenConstant);
    }


    BOOST_AUTO_TEST_CASE(abrs_chdchain_v3_legacy_coin_type_deserialize)
    {
        BOOST_TEST_MESSAGE("ABRS CHDChain v3 compatibility: implicit legacy coin type 10000");

        CHDChain legacy(nullptr);
        legacy.nVersion = CHDChain::VERSION_HD_BIP44_BIP39;
        legacy.nExternalChainCounter = 17;
        legacy.nInternalChainCounter = 9;
        legacy.UseBip44(true);

        CDataStream encoded(SER_DISK, CLIENT_VERSION);
        encoded << legacy;

        // Build the exact historical v3 byte representation manually.
        CDataStream expected(SER_DISK, CLIENT_VERSION);
        expected << legacy.nVersion;
        expected << legacy.nExternalChainCounter;
        expected << legacy.seed_id;
        expected << legacy.nInternalChainCounter;
        expected << legacy.bUse_bip44;

        BOOST_CHECK_EQUAL_COLLECTIONS(
            encoded.begin(), encoded.end(),
            expected.begin(), expected.end());

        CHDChain decoded(nullptr);
        decoded.nCoinType = 0xA5A5A5A5U;

        encoded >> decoded;

        BOOST_CHECK_EQUAL(decoded.nVersion, CHDChain::VERSION_HD_BIP44_BIP39);
        BOOST_CHECK_EQUAL(decoded.nExternalChainCounter, 17U);
        BOOST_CHECK_EQUAL(decoded.nInternalChainCounter, 9U);
        BOOST_CHECK(decoded.IsBip44());

        // v3 has no serialized coin-type field. Compatibility logic must
        // resolve every historical ABRS BIP44 v3 wallet to legacy 10000.
        BOOST_CHECK_EQUAL(
            decoded.GetCoinType(),
            CHDChain::LEGACY_ABRS_COIN_TYPE);

        // Deserializing v3 must not consume or invent a v4 coin-type field.
        BOOST_CHECK_EQUAL(decoded.nCoinType, 0xA5A5A5A5U);
        BOOST_CHECK(encoded.empty());
    }

    BOOST_AUTO_TEST_CASE(abrs_chdchain_v4_coin_type_roundtrip)
    {
        BOOST_TEST_MESSAGE("ABRS CHDChain v4 compatibility: persistent BIP44 coin type");

        CHDChain original(nullptr);
        original.nVersion = CHDChain::VERSION_HD_BIP44_COIN_TYPE;
        original.nExternalChainCounter = 23;
        original.nInternalChainCounter = 11;
        original.UseBip44(true);
        original.nCoinType = 424242U;

        CDataStream v4(SER_DISK, CLIENT_VERSION);
        v4 << original;

        // Serialize the same logical state as historical v3.
        CHDChain legacy(nullptr);
        legacy.nVersion = CHDChain::VERSION_HD_BIP44_BIP39;
        legacy.nExternalChainCounter = original.nExternalChainCounter;
        legacy.nInternalChainCounter = original.nInternalChainCounter;
        legacy.seed_id = original.seed_id;
        legacy.UseBip44(true);

        CDataStream v3(SER_DISK, CLIENT_VERSION);
        v3 << legacy;

        // v4 adds exactly one uint32_t coin-type field.
        BOOST_CHECK_EQUAL(v4.size(), v3.size() + sizeof(uint32_t));

        CHDChain decoded(nullptr);
        v4 >> decoded;

        BOOST_CHECK_EQUAL(decoded.nVersion, CHDChain::VERSION_HD_BIP44_COIN_TYPE);
        BOOST_CHECK_EQUAL(decoded.nExternalChainCounter, 23U);
        BOOST_CHECK_EQUAL(decoded.nInternalChainCounter, 11U);
        BOOST_CHECK(decoded.IsBip44());
        BOOST_CHECK_EQUAL(decoded.nCoinType, 424242U);
        BOOST_CHECK_EQUAL(decoded.GetCoinType(), 424242U);
        BOOST_CHECK(v4.empty());
    }


    BOOST_AUTO_TEST_CASE(abrs_chdchain_coin_type_fail_closed_boundaries)
    {
        BOOST_TEST_MESSAGE("ABRS CHDChain coin type fail-closed sentinel and boundaries");

        CHDChain unset(nullptr);
        unset.nVersion = CHDChain::VERSION_HD_BIP44_COIN_TYPE;
        unset.UseBip44(true);

        // A fresh v4 CHDChain must never silently resolve to coin type 0.
        BOOST_CHECK_EQUAL(
            unset.nCoinType,
            CHDChain::BIP44_COIN_TYPE_UNSET);

        BOOST_CHECK_EQUAL(
            unset.GetCoinType(),
            CHDChain::BIP44_COIN_TYPE_UNSET);

        BOOST_CHECK(
            !CHDChain::IsValidCoinType(
                CHDChain::BIP44_COIN_TYPE_UNSET));

        // BIP44 child-number space is valid only below the hardened bit.
        BOOST_CHECK(CHDChain::IsValidCoinType(0U));
        BOOST_CHECK(
            CHDChain::IsValidCoinType(
                CHDChain::BIP44_HARDENED_LIMIT - 1U));

        BOOST_CHECK(
            !CHDChain::IsValidCoinType(
                CHDChain::BIP44_HARDENED_LIMIT));

        BOOST_CHECK(
            !CHDChain::IsValidCoinType(0xffffffffU));

        // Historical v3 BIP44 wallets remain explicitly mapped to
        // the ABRS legacy coin type, despite having no persisted field.
        CHDChain legacy(nullptr);
        legacy.nVersion = CHDChain::VERSION_HD_BIP44_BIP39;
        legacy.UseBip44(true);

        BOOST_CHECK_EQUAL(
            legacy.GetCoinType(),
            CHDChain::LEGACY_ABRS_COIN_TYPE);

        BOOST_CHECK(
            CHDChain::IsValidCoinType(
                legacy.GetCoinType()));
    }

BOOST_AUTO_TEST_SUITE_END()
