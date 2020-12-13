# Prerequisites:
* libx11
* libxft
* libxinerama
* ttf-hack

# Recommended, but not necessary:
* my builds of dmenu, st, and slstatus, which can be found on my github page
* arc-gtk-theme
* picom

# Patches applied:
* fullgaps - places gaps between windows
* systray - adds a systemtray (disabled by default)
* fancybar - shows all clients on the bar instead of a single, focused client
* bar-height - allows the user to adjust bar thiccness (set to 26px)
* center - centers new windows whilst in the floating layout
* fibonacci & dwindle layouts (bound to Mod+Y and Mod+Shift+Y)
* centeredmaster & centeredfloatingmaster layouts (bound to Mod+U & Mod+Shift+U)
* pertag - set layouts per tag (hence the name)
* activetagindicatorbar - uses a bar instead of a small square to indicate tag focus
* restartsig - allows the user to restart dwm without having to restart X (bound to Mod + Shift + R)
* cyclelayouts - easy cycling between layouts using Mod+Ctrl+, and Mod+Control+.
* alpha - translucent top panel when used w/ a compositor (i.e picom)
