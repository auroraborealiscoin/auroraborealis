# ScanRepo Security Review – September 2026

## Scope

This document records the review of findings reported by ScanRepo against the
Aurora Borealis Coin (ABRS) source repository.

The reviewed ScanRepo report analyzed only part of the repository and used
heuristic detection rules. Each reported finding was therefore reviewed in its
source-code context.

## Code execution findings

Two legacy asset utility scripts contained shell-based command execution:

- `assets/tools/issuebulk.py`
- `assets/tools/asset_audit.py`

The shell-based calls were replaced with argument-list based `subprocess`
execution.

This removes unnecessary shell interpretation while preserving the intended
utility behavior.

Security hardening commit:

`699fba43f security: replace shell-based asset tool execution`

After the change:

- repository Python `os.system()` occurrences: 0
- modified files pass `python3 -m py_compile`
- `git diff --check` reports no whitespace errors

## Upstream developer tooling

The following ScanRepo-related developer tools were compared against the
Ravencoin upstream repository:

- `contrib/devtools/check-doc.py`
- `contrib/devtools/github-merge.py`

Both files are identical to `Ravencoin upstream/master`.

These are developer/maintainer utilities and are not wallet runtime code.

The `github-merge.py` call reported around Git configuration uses an explicit
argument list:

`subprocess.check_output([GIT, 'config', '--get', option])`

The remaining `shell=True` use in the developer tooling is inherited unchanged
from Ravencoin upstream.

## Regex compile finding

`test/functional/feature_versionbits_warning.py` imports `compile` from Python's
`re` module.

Therefore:

`VB_PATTERN = compile("^Warning.*versionbit")`

is regular-expression compilation, not dynamic Python code execution.

The file is identical to `Ravencoin upstream/master`.

## Functional test vectors and hexadecimal data

The following files reported for high-entropy, hexadecimal or encoded test data
were verified as identical to `Ravencoin upstream/master`:

- `test/functional/test_framework/script.py`
- `test/functional/feature_segwit.py`
- `test/functional/rpc_decodescript.py`
- `test/functional/rpc_signmessage.py`
- `test/functional/rpc_signrawtransaction.py`

These files contain functional-test constants, transaction/script fixtures and
protocol test vectors.

## macOS DS_Store helper

`contrib/macdeploy/custom_dsstore.py` differs from Ravencoin upstream by one
branding-related line:

Ravencoin:

`ds['Raven-Qt.app']['Iloc'] = (128, 156)`

Aurora Borealis Coin:

`ds['AuroraBorealis-Qt.app']['Iloc'] = (128, 156)`

The byte/hex data reported by the scanner is inherited from the upstream file;
the ABRS-specific difference is the application name.

## wallet.dat findings

Every reviewed Python reference to `wallet.dat` is located under
`test/functional/`.

The affected files are:

- `test/functional/wallet_backup.py`
- `test/functional/wallet_bip44.py`
- `test/functional/wallet_bip44_multilanguage.py`
- `test/functional/wallet_hd.py`
- `test/functional/wallet_keypool_topup.py`
- `test/functional/wallet_reorgsrestore.py`

All six files are identical to `Ravencoin upstream/master`.

The wallet files accessed by these tests are temporary regtest wallets under
test directories such as:

`self.options.tmpdir/.../regtest/wallet.dat`

They are used for functional testing of wallet backup, restore, encryption,
BIP44/HD behavior and keypool restoration.

These references do not constitute code that searches for or accesses arbitrary
end-user wallet files.

## Review conclusion

The review identified legacy shell-based execution in two asset utility scripts,
which has been hardened.

Other reviewed findings described above correspond to:

- unchanged Ravencoin upstream developer tooling;
- regular-expression compilation;
- upstream functional-test vectors;
- temporary regtest wallet operations;
- or a macOS packaging helper whose ABRS modification is limited to application
  branding.

This review does not treat a scanner score alone as proof of software safety.
Source review, build provenance, release binary verification and independent
security scanning remain separate verification steps.
