# Contributing to Aurora Borealis Core

Thank you for your interest in contributing to Aurora Borealis Core.

Aurora Borealis Core is an open-source project. Contributions involving code, testing, documentation, bug fixes and technical improvements are welcome.

## Contributor Workflow

Recommended workflow:

1. Fork the repository.
2. Create a dedicated topic branch.
3. Make and test your changes.
4. Commit the changes with a clear message.
5. Push the branch to your fork.
6. Open a pull request.

Official repository:
https://github.com/auroraborealiscoin/auroraborealis

## Pull Requests

Pull requests should focus on one specific change.

Avoid mixing unrelated formatting, refactoring and functional changes in the same pull request.

Common areas include:
- Build
- Consensus
- Documentation
- GUI
- Mining
- Network / P2P
- RPC / REST / ZMQ
- Scripts and tools
- Tests
- Wallet
- Assets

The pull request description should explain what changed, why it is needed and how it was tested.

## Consensus Changes

Consensus-related changes require additional care because they can affect compatibility across the entire Aurora Borealis network.

Consensus pull requests should include appropriate tests and document activation, compatibility and expected mainnet, testnet and regtest behaviour.

## Testing

Changes should not break the existing test suite.

Typical unit-test command:

```bash
make check
```

Functional tests are located under:

```text
test/functional/
```

## Commit Messages

Commit messages should clearly describe the purpose of the change.

For non-trivial changes, include enough context for future contributors to understand why the change was made.

## Code Review

Pull requests may be reviewed for correctness, security implications, consensus compatibility, maintainability, test coverage and code quality.

## Security Issues

Potential security vulnerabilities should not be publicly disclosed before maintainers have had an opportunity to investigate them.

Never publish private keys, seed phrases, wallet credentials or RPC passwords.

## License and Upstream Attribution

Aurora Borealis Core is distributed under the license terms described in COPYING.

Aurora Borealis Core contains code derived from earlier open-source blockchain projects, including Ravencoin Core and Bitcoin Core.

Existing upstream copyright and license notices must be preserved where required.

New contributions must be compatible with the project open-source licensing requirements.

## Project Information

Aurora Borealis Core
Ticker: ABRS

Website:
https://auroraborealiscoin.com/

Pool / Explorer:
https://auroraborealiscoin.org/
