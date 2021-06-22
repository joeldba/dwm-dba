#!/bin/bash
#
# a simple dmenu session script 
#
###

DMENU='dmenu -i -p power'
choice=$(echo -e "lock\nlogout\nshutdown\nreboot" | $DMENU | cut -f 1)

case "$choice" in
 lock) slock  ;;
 logout) killall X  ;;
 shutdown) doas poweroff  ;;
 reboot) doas reboot  ;;
esac
