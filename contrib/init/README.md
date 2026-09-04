Aurora Borealis Core init examples
==================================

Sample service definitions are provided for packagers and node operators:

    systemd: auroraborealisd.service
    Upstart: auroraborealisd.conf
    OpenRC:  auroraborealisd.openrc
             auroraborealisd.openrcconf
    CentOS:  auroraborealisd.init
    macOS:   com.auroraborealiscoin.auroraborealisd.plist

Default Linux packaging layout:

    daemon:  /usr/bin/auroraborealisd
    config:  /etc/auroraborealis/auroraborealis.conf
    data:    /var/lib/auroraborealis
    runtime: /run/auroraborealis

These files are packaging examples. See doc/init.md for additional
information about running Aurora Borealis Core.
