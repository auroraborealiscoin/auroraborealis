#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

RAVEND=${RAVEND:-$SRCDIR/auroraborealisd}
RAVENCLI=${RAVENCLI:-$SRCDIR/auroraborealis-cli}
RAVENQT=${RAVENQT:-$SRCDIR/qt/auroraborealis-qt}

[ ! -x $RAVEND ] && echo "$RAVEND not found or not executable." && exit 1

# Extract the canonical release version from the ABRS CLI.
# Example:
# Aurora Borealis Core RPC client version v4.6.3.0-<git>-dirty
RAWVER="$($RAVENCLI --version | head -n1)"
RVNVER="$(printf '%s\n' "$RAWVER" | grep -oE 'v[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+' | head -n1)"

[ -z "$RVNVER" ] && {
  echo "Unable to determine ABRS version from: $RAWVER"
  exit 1
}

# Create a footer file with copyright content.
# This gets autodetected fine for auroraborealisd if --version-string is not set,
# but has different outcomes for auroraborealis-qt and auroraborealis-cli.
echo "[COPYRIGHT]" > footer.h2m
$RAVEND --version | sed -n '1!p' >> footer.h2m

for cmd in $RAVEND $RAVENCLI $RAVENQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string="${RVNVER}" --include=footer.h2m -o "${MANDIR}/${cmdname}.1" "${cmd}"

  # Remove local git/build suffixes from generated release documentation.
  sed -E -i 's/\\-[0-9a-f]{7,}\\-dirty//g' "${MANDIR}/${cmdname}.1"
  sed -E -i 's/\\-[0-9a-f]{7,}//g' "${MANDIR}/${cmdname}.1"
done

rm -f footer.h2m
