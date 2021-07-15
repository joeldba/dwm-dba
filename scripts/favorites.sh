#!/bin/bash
#
# a simple dmenu session script 
#
###

DMENU='dmenu -i -p favs'
choice=$(echo -e "  firefox\n  discord\n  steam\n  minecraft\n  gzdoom\n  ncmpcpp\n  vim\n  gimp\n  audacity\n  obs-studio\n  virtualbox" | $DMENU | cut -f 1)

case "$choice" in
 "  firefox") firefox;;
 "  discord") discord;;
 "  steam") steam;;
 "  minecraft") minecraft-launcher;;
 "  gzdoom") gzdoom;;
 "  ncmpcpp") st -e ncmpcpp;; 
 "  vim") st -e vim;;
 "  gimp") gimp;;
 "  audacity") obs-studio;;
 "  obs-studio") obs;;
 "  virtualbox") virtualbox;;
esac
