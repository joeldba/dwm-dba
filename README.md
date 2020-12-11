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
* systray - adds a systemtray (disabled by default)
* fancybar - shows all clients on the bar instead of a single, focused client
* bar-height - allows you to adjust bar thiccness (set to 26px by default)
* center - centers new windows whilst in the floating layout
* fibonacci & dwindle layouts (bound to Mod+Y and Mod+Shift+Y)
* centeredmaster & centeredfloatingmaster layouts (bound to Mod+U & Mod+Shift+U)
* pertag - allows you to set layouts per tag (hence the name)
* activetagindicatorbar - uses a bar instead of a small square to indicate tag focus
* restartsig - allows the user to restart dwm without having to restart X (bound to Mod + Shift + R)
