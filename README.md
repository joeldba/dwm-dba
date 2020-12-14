# Prerequisites:
* libx11
* libxft
* libxinerama
* hack-ttf

# Recommended, but not necessary:
* my builds of dmenu, st, and slstatus, which can be found on my github page
* picom-tryone-git (AUR)
* arc-gtk-theme

# Patches applied:
* fullgaps - places gaps between windows
* ~~systray - adds a systemtray~~ CURRENTLY DISABLED, X will crash if the systray is enabled! might have something to do w/ the alpha patch, don't know of a fix.
* fancybar - shows all focused and unfocused clients on the bar
* bar-height - allows you to adjust bar thiccness (set to 24px by default)
* center - centers new windows in floating mode
* fibonacci & dwindle layouts
* centeredmaster & centeredfloatingmaster layouts
* pertag - set layouts per tag (hence the name)
* alpha - makes the bar translucent when dwm is used alongside a compositor
