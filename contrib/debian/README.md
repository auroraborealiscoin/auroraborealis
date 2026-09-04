Debian
====================

This directory contains files used to package Aurora Borealis Core
for Debian-based Linux systems.

The primary executables are:

- auroraborealisd
- auroraborealis-cli
- auroraborealis-qt

## auroraborealis: URI support

auroraborealis-qt.desktop provides desktop integration for the
auroraborealis: URI scheme.

To install the desktop entry manually:

    sudo desktop-file-install auroraborealis-qt.desktop
    sudo update-desktop-database

If building manually, ensure auroraborealis-qt is available in
/usr/bin or adjust the Exec path in the desktop file accordingly.

The current packaging retains the existing Raven-derived icon
filenames used internally by the build system. These filenames do
not affect the Aurora Borealis application or URI identity.

auroraborealis-qt.protocol provides KDE integration for the
auroraborealis: URI scheme.
