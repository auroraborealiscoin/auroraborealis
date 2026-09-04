# Aurora Borealis Core init/service configuration

Sample service configurations are available in `contrib/init/`.

Current ABRS service files include:

- `contrib/init/auroraborealisd.service` — systemd
- `contrib/init/auroraborealisd.openrc` — OpenRC
- `contrib/init/auroraborealisd.openrcconf` — OpenRC configuration
- `contrib/init/auroraborealisd.conf` — service configuration
- `contrib/init/auroraborealisd.init` — SysV-style init
- `contrib/init/com.auroraborealiscoin.auroraborealisd.plist` — macOS launchd

## Linux service identity

The packaged service uses:

- daemon: `auroraborealisd`
- CLI: `auroraborealis-cli`
- user/group: `auroraborealis`
- configuration: `/etc/auroraborealis/auroraborealis.conf`
- data directory: `/var/lib/auroraborealis`
- runtime directory: `/run/auroraborealis`
- PID file: `/run/auroraborealis/auroraborealisd.pid`

The exact configuration used by a distribution may differ. Review the
corresponding file in `contrib/init/` before installation.

## systemd

After installing the service file:

    sudo systemctl daemon-reload
    sudo systemctl start auroraborealisd

To enable it at boot:

    sudo systemctl enable auroraborealisd

Check status with:

    systemctl status auroraborealisd

## OpenRC

Install the OpenRC script using the service name `auroraborealisd`, then:

    rc-service auroraborealisd start
    rc-update add auroraborealisd

## macOS launchd

The example launchd file is:

    contrib/init/com.auroraborealiscoin.auroraborealisd.plist

Review paths and configuration before loading it for a local user.

## Security

Protect the configuration file and wallet data from unauthorized access.
RPC access should not be exposed publicly without appropriate authentication
and network controls.
