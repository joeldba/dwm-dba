#!/bin/bash
#
# a simple dmenu session script 
#
###

DMENU='dmenu -i -p music'
choice=$(echo -e "song list\nplay\npause\nstop\nnext song\nprev song\ntoggle random\ntoggle single\nmute\nvol 35\nvol 50\nvol 100" | $DMENU | cut -f 1)

case "$choice" in
 "song list") $HOME/.config/dwm/scripts/mpdmenu.sh -p ;; 
 play) mpc play  ;;
 pause) mpc pause  ;;
 stop) mpc stop  ;;
 "next song") mpc next  ;;
 "prev song") mpc prev ;;
 "toggle random") mpc random ;;
 "toggle single") mpc single ;;
 mute) mpc vol 0 ;;
 "vol 35") mpc vol 20 ;;
 "vol 50") mpc vol 50 ;;
 "vol 100") mpc vol 100 ;;
esac
