#!/bin/sh
cd /opt/ETAio/bin

if [ -f '/opt/ETAio/bin/data-dir/config.ini' ]; then
    echo
  else
    cp /config.ini /opt/ETAio/bin/data-dir
fi

if [ -d '/opt/ETAio/bin/data-dir/contracts' ]; then
    echo
  else
    cp -r /contracts /opt/ETAio/bin/data-dir
fi

while :; do
    case $1 in
        --config-dir=?*)
            CONFIG_DIR=${1#*=}
            ;;
        *)
            break
    esac
    shift
done

if [ ! "$CONFIG_DIR" ]; then
    CONFIG_DIR="--config-dir=/opt/ETAio/bin/data-dir"
else
    CONFIG_DIR=""
fi

exec /opt/ETAio/bin/nodETA $CONFIG_DIR "$@"
