 #!/usr/bin/env bash

 # Execute this file to install the raven cli tools into your path on OS X

 CURRENT_LOC="$( cd "$(dirname "$0")" ; pwd -P )"
 LOCATION=${CURRENT_LOC%AuroraBorealis-Qt.app*}

 # Ensure that the directory to symlink to exists
 sudo mkdir -p /usr/local/bin

 # Create symlinks to the cli tools
 sudo ln -s ${LOCATION}/AuroraBorealis-Qt.app/Contents/MacOS/auroraborealisd /usr/local/bin/auroraborealisd
 sudo ln -s ${LOCATION}/AuroraBorealis-Qt.app/Contents/MacOS/auroraborealis-cli /usr/local/bin/auroraborealis-cli
