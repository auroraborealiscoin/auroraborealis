# Security Policy

## Reporting a Vulnerability

Security vulnerabilities affecting Aurora Borealis Core or official Aurora Borealis Coin infrastructure should be reported privately before public disclosure.

Do not publish private keys, wallet seed phrases, wallet files, RPC credentials, server credentials, API secrets, authentication tokens or unpatched exploit details.

For initial security contact, use the official project contact information published at:

https://auroraborealiscoin.com/

A useful security report should include:

- affected component and version;
- reproduction conditions;
- expected and observed behaviour;
- potential security impact;
- relevant logs with secrets removed;
- proposed mitigation, if known.

## Scope

Security-sensitive components include:

- Aurora Borealis Core;
- consensus and validation;
- wallet code;
- P2P networking;
- RPC interfaces;
- mining and block-template logic;
- official Pool;
- official Explorer;
- official Faucet;
- official release packaging and distribution.

## Source and Security Review

Aurora Borealis Coin is derived in part from the Ravencoin codebase.

Security-related findings are reviewed in source context. Heuristic scanner results are not treated as proof of either maliciousness or software safety.

The September 2026 ScanRepo source review is documented at:

`docs/security/scanrepo-review-2026-09.md`

## Release Verification

Users should obtain wallet software only from official Aurora Borealis Coin release channels and verify published checksums when available.

Release binary verification, source review and independent malware scanning are separate security controls.

## Responsible Disclosure

Please allow maintainers reasonable time to investigate and prepare a fix before publishing technical exploit details.

Never test vulnerabilities through unauthorized access to third-party systems, wallets or funds.
