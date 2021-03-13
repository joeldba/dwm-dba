# Prerequisites:
* libx11
* libxft
* libxinerama
* terminus-font
* ttf-font-awesome
* freetype2
* dmenu
* st
* pulsemixer (for volume controls)
* slock (for display locking)

the first three packages will need '-dev' appended to them if you're on an apt-based distro.

# Recommended, but not necessary:
* my custom builds of dmenu, st, and slstatus, which can be found on my github page
* picom
* adapta-gtk-theme

# Patches applied:
* fullgaps - places gaps between windows. adjustable w/ Mod + +/-
* ~~systray - adds a systemtray~~ CURRENTLY DISABLED! X will crash if the systray is enabled! might have something to do w/ the alpha patch, don't know of a fix.
* fancybar - shows all focused and unfocused clients on the bar
* bar-height - adjustable bar thiccness (set to 24px by default) 
* center - centers new windows in floating mode
* fibonacci & dwindle layouts. bound to Mod + Y & Mod + Shift + Y respectively
* centeredmaster & centeredfloatingmaster layouts. bound to Mod + U & Mod + Shift + U respectively 
* gaplessgrid layout. bound to  Mod + G
* pertag - use different layouts & master sizes between tags
* alpha - makes the bar transparent when dwm is used alongside a compositor
* actualfullscreen. Mod+Shift+F toggles fullscreen mode for the focused window
* scratchpad - allows for spawning & restoring a floating terminal window, for quick typing. bound to Mod + S
* hide vacant tags - hides tags that are not occupied by a client/clients
