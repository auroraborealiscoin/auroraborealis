# Aurora Borealis Core Release Checklist

## Source

- [ ] Confirm target version in `configure.ac`.
- [ ] Confirm generated version headers match the target version.
- [ ] Confirm release notes match the target release.
- [ ] Confirm `git diff --check` passes.
- [ ] Confirm no unintended consensus changes are present.
- [ ] Confirm no unintended premine/founder/treasury changes are present.

## Build

- [ ] Build `auroraborealisd`.
- [ ] Build `auroraborealis-cli`.
- [ ] Build `auroraborealis-qt`.
- [ ] Run available unit/integration tests.
- [ ] Verify runtime version output.
- [ ] Verify generated manpages.

## Packaging

- [ ] Verify Linux package names.
- [ ] Verify Windows installer names and URI handler.
- [ ] Verify macOS application identity and URI handler.
- [ ] Verify Debian metadata.
- [ ] Verify release archives contain no local backup files.

## Release

- [ ] Verify release commit.
- [ ] Verify tag target.
- [ ] Generate checksums.
- [ ] Publish only verified artifacts.
- [ ] Update official website download references after release publication.
