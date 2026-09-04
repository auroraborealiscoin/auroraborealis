# Aurora Borealis Core Release Process

This document describes the release workflow for Aurora Borealis Core.

## Before a release candidate

- Confirm the intended version in `configure.ac`.
- Confirm `CLIENT_VERSION_IS_RELEASE` is set appropriately.
- Regenerate and verify manpages.
- Review translations.
- Review public documentation and release notes.
- Run `git diff --check`.
- Build the daemon, CLI and Qt wallet.
- Run the available automated test suites.
- Verify runtime version output from:
  - `auroraborealisd`
  - `auroraborealis-cli`
  - `auroraborealis-qt`
- Verify packaged files use Aurora Borealis public names.

## Consensus and chain parameters

A normal maintenance or packaging release must not silently modify consensus
rules or active network parameters.

Changes to the following require a separately reviewed network/consensus
upgrade process and must not be treated as routine release maintenance:

- Proof-of-Work rules
- reward schedule
- difficulty adjustment
- genesis parameters
- active network ports
- fixed consensus checkpoints
- `nMinimumChainWork`
- `defaultAssumeValid`
- `chainTxData`
- premine/founder/treasury allocation

For Aurora Borealis Core 4.6.3 these values are intentionally outside the
release-maintenance scope.

## Source checkout

    git clone https://github.com/auroraborealiscoin/auroraborealis.git
    cd auroraborealis

Use the exact release commit and verify the commit hash before producing
release artifacts.

## Build artifacts

Public artifact names should use the Aurora Borealis project identity.

Typical names include:

    auroraborealis-${VERSION}-x86_64-linux-gnu.tar.gz
    auroraborealis-${VERSION}-aarch64-linux-gnu.tar.gz
    auroraborealis-${VERSION}-osx64.tar.gz
    auroraborealis-${VERSION}-osx.dmg
    auroraborealis-${VERSION}-win64.zip
    auroraborealis-${VERSION}-win64-setup.exe

Artifact availability depends on which platforms were actually built and
verified for that release.

## Release verification

Before publishing:

- verify checksums;
- verify archive contents;
- verify executable names;
- verify version strings;
- verify no build-tree backup files are included;
- verify source and generated files are internally consistent;
- verify the Git tag points to the intended release commit.

Do not move or overwrite an existing public release tag without an explicit,
documented migration plan.

## GitHub release

Official repository:

https://github.com/auroraborealiscoin/auroraborealis

Official releases:

https://github.com/auroraborealiscoin/auroraborealis/releases

Publish only artifacts that were built and verified from the documented
release commit.
