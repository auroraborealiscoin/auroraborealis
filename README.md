<p align="center">
  <img src="assets/branding/logo-aurora.borealis-coin.png" width="220" alt="Aurora Borealis Coin">
</p>

# Aurora Borealis Core (ABRS)

**Aurora Borealis Coin** is an independent open-source peer-to-peer blockchain network.

**Ticker:** ABRS
**Core:** Aurora Borealis Core
**Official website:** https://auroraborealiscoin.com/
**Pool / Explorer:** https://auroraborealiscoin.org/

---

## Aurora Borealis Coin

Aurora Borealis Coin (ABRS) is a peer-to-peer digital asset with its own independent blockchain.

Aurora Borealis Core provides:

- full node support;
- peer-to-peer networking;
- blockchain validation;
- wallet functionality;
- transaction creation and verification;
- mining and consensus functionality;
- mainnet, testnet and regtest environments;
- graphical Qt wallet;
- command-line interface and daemon.

---

## Current Release

### Aurora Borealis Core v0.1.1

The current Linux x86-64 release includes:

- `auroraborealis-qt`
- `auroraborealisd`
- `auroraborealis-cli`

Official releases:

https://github.com/auroraborealiscoin/auroraborealis/releases

---

## Network

Aurora Borealis Core supports:

- Mainnet
- Testnet
- Regtest

Payment URI scheme:

`auroraborealis:`

---

## Premine

Aurora Borealis mainnet includes a consensus-enforced premine at block #1.

| Allocation | Amount |
|---|---:|
| Founder | 210,000,000 ABRS |
| Treasury | 210,000,000 ABRS |
| **Total** | **420,000,000 ABRS** |

Founder address:

`AeaBek4B389g2pkxdRgn3SGznQfwJgj9ns`

Treasury address:

`AeQqDnuyPc1dZt4HRLapm9Vv3zxuBj6pDx`

---

## Building

```bash
./autogen.sh
./configure
make
