# Prerequisites:
* libx11
* libxft
* libxinerama
* terminus-font-otb

# Recommended, but not necessary:
* my builds of dmenu, st, and slstatus, which can be found on my github page
* gtk-theme-arc-gruvbox-git (AUR)

# Patches applied:
* fullgaps - places gaps between windows
* systray - adds a systemtray (currently disabled by default bc X will crash if it's enabled- don't know of a fix)
* fancybar - shows all clients on the bar instead of a single, active client
* bar-height - allows you to adjust bar thiccness (set to 26px by default)
* center - centers windows in floating mode
* fibonacci/dwindle + centeredmaster layouts
* pertag - allows you to set layouts per tag (hence the name)
* alpha - top bar is translucent if a compositor is used
