# Aurora Borealis Coin (ABRS)

## Technical Whitepaper

**Version 1.0 - Pre-launch Edition**

**Official public launch: 16 September 2026**

Website: https://auroraborealiscoin.com/

Source: https://github.com/auroraborealiscoin/auroraborealis

---

## 1. Abstract

Aurora Borealis Coin (ABRS) is an independent open-source Proof-of-Work blockchain designed around transparent consensus rules, GPU-accessible KAWPOW mining, public network infrastructure and independently verifiable monetary parameters.

The network combines a 60-second target block interval, KAWPOW Proof of Work, Dark Gravity Wave difficulty adjustment and a fixed consensus-defined emission schedule.

Aurora Borealis Coin provides a full-node implementation, graphical wallet, command-line tools, public blockchain explorer, mining pool, faucet and official network telemetry.

This document describes the technical architecture, consensus parameters, monetary supply, premine structure, network infrastructure, mining model, security assumptions and development roadmap of Aurora Borealis Coin.

---

## 2. Project Principles

Aurora Borealis Coin is developed around the following principles:

- open-source and independently auditable software;
- deterministic consensus rules;
- Proof-of-Work network security;
- GPU-accessible mining through KAWPOW;
- transparent monetary issuance;
- explicit disclosure of premine allocations;
- publicly verifiable blockchain state;
- separation between consensus-critical systems and public infrastructure;
- conservative activation of production services through controlled operational procedures.

ABRS does not rely on promises of market value, price appreciation or guaranteed financial return.

---

## 3. Network Identity

| Parameter | Value |
|---|---|
| Project | Aurora Borealis Coin |
| Ticker | ABRS |
| Core software | Aurora Borealis Core |
| Consensus | Proof of Work |
| Mining algorithm | KAWPOW |
| Difficulty adjustment | Dark Gravity Wave |
| DGW window | 180 blocks |
| Target block time | 60 seconds |
| Initial block reward | 900 ABRS |
| Subsidy halving interval | 2,100,000 blocks |
| Mainnet P2P port | 17333 |
| Mainnet RPC port | 17332 |
| Payment URI | auroraborealis: |
| Core version | 4.6.3 |
| Protocol version | 70028 |

---
## 4. Core Architecture

Aurora Borealis Core is the reference full-node implementation of the ABRS network.

Its primary responsibilities include:

- validating blocks and transactions;
- maintaining the local blockchain state;
- participating in peer-to-peer networking;
- enforcing consensus rules;
- exposing local RPC functionality;
- supporting wallet operations;
- producing and validating Proof-of-Work block templates;
- providing command-line and graphical interfaces.

Consensus-critical behavior is implemented in the Core software and is intentionally separated from public web services such as the Explorer, Pool and Faucet.

---

## 5. Proof of Work and Mining

Aurora Borealis Coin uses KAWPOW Proof of Work.

KAWPOW is designed for GPU-oriented mining and requires miners to perform computational work before a block can be accepted by the network.

A valid block must satisfy the current network difficulty target and all other consensus validation rules.

The initial block subsidy is **900 ABRS**.

The subsidy is reduced according to the consensus-defined halving interval of **2,100,000 blocks**.

With a target block interval of approximately 60 seconds, miners compete continuously to extend the valid chain.

Mining participation is permissionless at the protocol level. Miners may connect through the official mining Pool or operate independently using compatible infrastructure.

---

## 6. Difficulty Adjustment

Aurora Borealis Coin uses Dark Gravity Wave with a 180-block adjustment window.

The purpose of difficulty adjustment is to adapt the Proof-of-Work target to observed network conditions so that block production remains close to the intended 60-second target over time.

Difficulty is derived from consensus state and is independently calculated by validating nodes.

No web service, pool operator or project administrator can override the consensus difficulty accepted by the network.

---

## 7. Block Validation and Chain Selection

Each full node independently validates received blocks before accepting them into its active chain.

Validation includes, among other checks:

- Proof-of-Work validity;
- block structure;
- transaction validity;
- monetary rules;
- consensus-defined subsidy rules;
- chain continuity;
- network-specific consensus parameters.

Nodes select the valid chain according to accumulated chain work.

This model allows participants to verify the network without relying on the official website, Explorer, Pool or Faucet.

---
## 8. Monetary Policy and Supply

Aurora Borealis Coin uses a deterministic consensus-defined issuance schedule.

The initial mining subsidy is **900 ABRS per block**.

The subsidy is halved every **2,100,000 blocks** according to the consensus rules.

Because issuance is calculated in atomic units, repeated halving eventually reaches the smallest representable non-zero reward.

Consensus-level emission analysis produced the following values:

| Supply component | Amount |
|---|---:|
| Mining emission | 3,779,999,999.727 ABRS |
| Founder premine | 210,000,000 ABRS |
| Treasury premine | 210,000,000 ABRS |
| Total premine | 420,000,000 ABRS |
| Total theoretical created supply | 4,199,999,999.727 ABRS |
| Unspendable genesis output | 900 ABRS |
| Maximum spendable supply | 4,199,999,099.727 ABRS |

The maximum spendable supply excludes the **900 ABRS genesis output**, which is not spendable.

The total premine represents approximately **10.000002%** of the maximum spendable supply.

---

## 9. Premine Structure

Aurora Borealis mainnet includes a consensus-enforced premine created at block 1.

The allocation is divided into two equal parts:

| Allocation | Amount |
|---|---:|
| Founder allocation | 210,000,000 ABRS |
| Treasury allocation | 210,000,000 ABRS |
| **Total premine** | **420,000,000 ABRS** |

Founder address:

`AeaBek4B389g2pkxdRgn3SGznQfwJgj9ns`

Treasury address:

`AeQqDnuyPc1dZt4HRLapm9Vv3zxuBj6pDx`

The premine is part of the public consensus rules and is not hidden from network participants.

Its existence, amount and allocation addresses are disclosed so that users, miners and independent analysts can verify the distribution directly from the blockchain.

---

## 10. Supply Verification

ABRS supply can be independently verified from consensus rules and blockchain state.

During the pre-launch certification at block height 114, the expected UTXO supply was:

**420,102,600.00000000 ABRS**

The observed UTXO supply at the same height was:

**420,102,600.00000000 ABRS**

The two values matched exactly.

This cross-check confirmed that observed chain issuance was consistent with the expected premine plus mined block rewards at that height.

---
## 11. Public Infrastructure

Aurora Borealis Coin operates a public infrastructure layer that is intentionally separated from consensus-critical Core functions.

The official infrastructure includes:

- public Core mainnet nodes;
- official website;
- blockchain Explorer;
- mining Pool;
- Faucet;
- live network telemetry.

The official website is available at:

https://auroraborealiscoin.com/

The official Explorer is available at:

https://explorer.auroraborealiscoin.com/

The official mining Pool is available at:

https://pool.auroraborealiscoin.com/

The official Faucet is available at:

https://faucet.auroraborealiscoin.com/

These services improve usability and observability but are not required for independent block validation.

---

## 12. Network and Service Security

Consensus-critical RPC interfaces are not intended for unrestricted public exposure.

Official Core deployments are configured so that RPC remains bound to localhost while P2P networking is exposed on the designated mainnet port.

Public web services are exposed through HTTPS and reverse-proxy infrastructure rather than by exposing internal application ports directly.

Operational safety controls are used for pre-launch services. In particular:

- Pool public Stratum remains intentionally locked until controlled go-live;
- Faucet real payouts remain intentionally disabled until controlled go-live;
- service activation is performed through staged checks rather than by removing multiple safety controls simultaneously.

Security controls do not eliminate all risk. Network operators, miners, users and service operators remain responsible for protecting their own systems, credentials, wallets and private keys.

---

## 13. Wallet and Key Responsibility

ABRS ownership is controlled through cryptographic private keys.

Loss or disclosure of a private key may result in irreversible loss of control over the associated funds.

Users should maintain secure backups and should never disclose:

- private keys;
- wallet seed phrases;
- wallet passwords;
- RPC credentials;
- server credentials.

No legitimate Aurora Borealis Coin administrator requires a user private key or seed phrase.

---

## 14. Open-Source Lineage

Aurora Borealis Core contains code derived from earlier open-source blockchain projects, including Ravencoin Core and Bitcoin Core.

Aurora Borealis Coin is an independent network with its own consensus parameters, chain history, network identity, branding, public infrastructure and economic parameters.

Upstream source-code structure, internal names, historical documentation and test identifiers may remain where technically appropriate.

Upstream copyright and license notices are preserved in accordance with their respective licenses.

The existence of upstream lineage does not imply that Aurora Borealis Coin shares the same network, monetary policy, consensus parameters or operational infrastructure as those upstream projects.

---

## 15. Decentralization and Independent Participation

Aurora Borealis Coin is designed so that independent participants can validate the blockchain using Aurora Borealis Core.

Participants may:

- operate independent full nodes;
- mine independently;
- operate independent mining pools;
- build independent explorers;
- develop compatible software and tooling;
- audit source code and consensus behavior.

The official infrastructure is intended as project-operated infrastructure, not as a replacement for independent network participation.

---

## 16. Development Roadmap

The project roadmap is maintained separately in ROADMAP.md.

The current development sequence includes:

1. Core mainnet and public infrastructure;
2. official public launch;
3. technical documentation and Whitepaper;
4. official social and community channels;
5. broader independent ecosystem participation.

Future work remains subject to technical review, security analysis and development resources.

---

## 17. Risks and Limitations

Blockchain systems involve technical, operational and economic risks.

Potential risks include:

- software defects;
- consensus implementation errors;
- wallet or key loss;
- mining centralization;
- infrastructure outages;
- network attacks;
- third-party service failures;
- regulatory or legal changes;
- limited liquidity or market availability;
- incompatibilities introduced by future software changes.

Users should independently evaluate the software and network before relying on it for material value.

---

## 18. No Financial Promise

ABRS is a technical blockchain project.

This Whitepaper does not constitute investment advice, a promise of exchange listing, a guarantee of liquidity, a guarantee of price appreciation or a guarantee of financial return.

Network participation, mining, holding or transferring ABRS involves risk and should be evaluated independently.

---

## 19. Official References

Website:
https://auroraborealiscoin.com/

Source repository:
https://github.com/auroraborealiscoin/auroraborealis

Releases:
https://github.com/auroraborealiscoin/auroraborealis/releases

Explorer:
https://explorer.auroraborealiscoin.com/

Mining Pool:
https://pool.auroraborealiscoin.com/

Faucet:
https://faucet.auroraborealiscoin.com/

---

## 20. Document Status

This document is the Aurora Borealis Coin Technical Whitepaper, Version 1.0, prepared for the public launch scheduled for 16 September 2026.

Technical parameters should always be verified against the current consensus source code and active network state.
