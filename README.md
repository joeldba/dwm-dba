# About dwm
dwm is an extremely fast, small, and dynamic window manager for X.

# Prerequisites:
To build dwm, you will need:
* libx11
* libxft
* libxinerama
* libxcb

For the best possible experience with this build of dwm, you will need the following
* terminus-font
* ttf-font-awesome
* slock
* My builds of [st](https://github.com/joeldba/st), [dmenu](https://github.com/joeldba/dmenu), and [dwmblocks](https://github.com/joeldba/dwmblocks) (although you could use the stock builds if you really, really want to)
* My [dotfiles](https://github.com/joeldba/dotfiles)
* mpd + mpc
* scrot

# How do I install it?
To install dwm, run these commands:

* `git clone https://github.com/joeldba/dwm ~/.config/dwm`
* `cd ~/.config/dwm`
* `sudo make clean install`

If using xinit, put `exec dwm` in your .xinitrc and dwm will launch when `startx` is run.

# Extra tidbits
For the script bindings, you might need to replace $HOME with your full user path (/home/username) in order for the scripts to launch properly.
You may also need to make the scripts themselves executable by running:
`chmod +x ~/.config/dwm/scripts/*.sh`

# What features are there?
I've applied quite a few patches, some functional & some purely for aesthetic purposes. Here's a list:
* vanitygaps + layouts
  * Adds a gap inbetween windows, the value of which can be changed in config.h. (default value is 20px for all dimensions) Also comes with a bunch of nifty layouts, like spiral, dwindle, bstack, centeredmaster, etc. 
* swallow
  * Any window created by st (or any other terminal specified in config.h) will overlap the entirety of the terminal window to reduce on-screen clutter.
* hide-vacant-tags
  * The bar only shows tags with clients on them, a la i3
* center
  * Centers newly-created floating windows.
* scratchpad
  * Allows you to show/hide a small, floating terminal window for quick typing or running commands.
* restartsig
  * Adds the ability to restart dwm. Making changes is now a breeze, as you don't have to completely restart X11 after rebuilding dwm.
* movestack
  * Adds the ability to move windows through the master & stack.
* cfacts
  * Allows you to grow/shrink windows horizontally
* barpadding
  * Self-explanatory. Creates a gap around the bar, purely for cosmetic purposes.
* [dwm-border-bar](https://codemadness.org/paste/dwm-border-bar.patch)
  * Creates a border around the bar. Again, purely for cosmetic purposes.
* colorbar
  * Enables setting colors for each individual element of the bar.
* statuscolors
  * A patch that enables colors for each status module. Interfaces with dwmblocks.


# What are the keybindings?
While this information can be gathered from `config.h` I've gone the extra mile and made a table that outlines most of the keybindings for you. The default modkey is `Alt` as specified in `config.h`.
|Action|Key combo|
|:---:|:---:|
|Spawn a terminal|Mod+Shift+Enter|
|Close window|Mod+Shift+C|
|Open dmenu prompt|Mod+p|
|Move focus right|Mod+k|
|Move focus left|Mod+j|
|Move window right|Mod+Shift+K|
|Move window left|Mod+Shift+J|
|Switch between tags|Mod+1 thru 9 (0 shows all windows on all tags)|
|Go to last tag|Mod+Tab|
|Move focused window between tags|Mod+Shift+1 thru 9 (0 will show focused window on all taga)|
|Show another tag|Mod+Ctrl+1 thru 9|
|Increase master size|Mod+l|
|Decrease master size|Mod+h|
|Expand window|Mod+Shift+H|
|Shrink window|Mod+Shift+L|
|Make slave master|Mod+Enter|
|Increase amt of masters|Mod+i|
|Decrease amt of masters|Mod+d|
|Toggle float on focused window|Mod+Shift+Space|
|Resize window|Mod+Mouse2|
|Drag window|Mod+Mouse1|
|Toggle bar on/off|Mod+b|
|Default/tall tile layout|Mod+t|
|Short tile layout|Mod+Shift+T|
|Spiral layout|Mod+y|
|Dwindle layout|Mod+Shift+Y
|Deck layout|Mod+r|
|Centered master layout|Mod+u|
|Centered floating master layout|Mod+Shift+U|
|Grid layout|Mod+g|
|Nrowgrid layout|Mod+Shift+G|
|Monocole layout|Mod+m|
|Floating layout|Mod+f|
|Show/hide scratchpad|Mod+s|
|Show scrot options menu|Mod+Shift+S|
|Show mpd options menu|Mod+Shift+M|
|Show README file|Mod+Shift+R|
|Lock X session with slock|Mod+Shift+L|
|Show power options menu|Mod+Shift+X|
|Restart dwm|Mod+Shift+Q|
|Quit dwm|Mod+Shift+Ctrl+Q|

