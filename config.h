/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 20;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 20;       /* vert inner gap between windows */
static const unsigned int gappoh    = 20;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 20;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 28;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const int vertpad            = 20;       /* vertical padding of bar */
static const int sidepad            = 20;       /* horizontal padding of bar */
static const char *fonts[]          = { "Terminus:size=9" };
static const char dmenufont[]       = "Terminus:size=8";
/* colors */
static const char base[]       	    = "#282828";
static const char base2[]      	    = "#3c3836";
static const char base3[]           = "#504945";
static const char base4[]           = "#665c64";
static const char base5[]           = "#6c6f64";
static const char fg[]       	    = "#a89984";
static const char fg2[]             = "#bdae93";
static const char fg3[]             = "#d5c4a1";
static const char fg4[]             = "#ebdbb2";
static const char fg5[]             = "#fbf1c7";
static const char yellow[]          = "#fabd2f";
static const char red[]             = "#fb4934";
static const char blue[]            = "#83a598";
static const char purple[]          = "#d3869b";
static const char orange[]          = "#fe8019";
static const char col_borderbar[]   = "#3c3836";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] 	  = { fg,   base,      base },
	[SchemeSel]  	  = { fg2,  base2,     base2 },
	[SchemeRed] 	  = { red, base2, red },
	[SchemeBlue]	  = { blue, base2, red },
	[SchemePurple]	  = { purple, base2, red },
	[SchemeYellow]	  = { yellow, base2, red },
	[SchemeOrange]	  = { orange, base2, red },
	[SchemeStatus]    = { fg2,  base2,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]   = { yellow, base3,  "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
        [SchemeTagsNorm]  = { fg2, base2,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
        [SchemeInfoSel]   = { fg5, base,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
        [SchemeInfoNorm]  = { fg5, base,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/* tagging */
static const char *tags[] = { "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  " };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class              instance  title           tags mask  iscentered  isfloating  isterminal  noswallow  monitor */
	{ "st-256color",      NULL,     NULL,           0, 	   1,         0,          1,           0,        -1 },
	{ NULL,               NULL,     "Event Tester", 0,         0, 	      0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ " tile ",            tile },    /* first entry is default */
	{ " monocle ",         monocle },
	{ " spiral ",          spiral },
	{ " dwindle ",         dwindle },
	{ " deck ",            deck },
	{ " bstack ",          bstack },
	{ " bstackhoriz ",     bstackhoriz },
	{ " grid ",            grid },
	{ " nrowgrid ",        nrowgrid },
	{ " horizgrid ",       horizgrid },
	{ " gaplessgrid ",     gaplessgrid },
	{ " centermaster ",    centeredmaster },
	{ " centerfloat ",  centeredfloatingmaster },
	{ " float ",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "80x24", NULL };
static const char *pwrscript[] = { "/home/rwt/.config/dwm/scripts/power.sh", NULL };
static const char *scrotscript[] = { "/home/rwt/.config/dwm/scripts/scrot.sh", NULL };
static const char *musicscript[] = { "/home/rwt/.config/dwm/scripts/music.sh", NULL };
static const char *favscript[] = { "/home/rwt/.config/dwm/scripts/favorites.sh", NULL };
static const char *helpcmd[] = { "st", "-ig", "128x44", "vim", "-M", "/home/rwt/.config/dwm/README.md", NULL };
#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_s,  togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[13]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,		XK_t,	   setlayout,	   {.v = &layouts[5]} },
	{ MODKEY,			XK_y,	   setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,		XK_y,	   setlayout,	   {.v = &layouts[3]} },
	{ MODKEY,			XK_g,	   setlayout,	   {.v = &layouts[7]} },
	{ MODKEY|ShiftMask,		XK_g,	   setlayout,	   {.v = &layouts[8]} },	
	{ MODKEY,			XK_u,	   setlayout,	   {.v = &layouts[11]} },
	{ MODKEY|ShiftMask,		XK_u,	   setlayout,      {.v = &layouts[12]} },	
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,		XK_x,	   spawn,	   {.v = pwrscript } },	
	{ MODKEY|ShiftMask,		XK_s,      spawn,	   {.v = scrotscript } },
	{ MODKEY|ShiftMask,		XK_m,      spawn,	   {.v = musicscript } },
	{ MODKEY|ShiftMask,		XK_p,      spawn,	   {.v = favscript } },
	{ MODKEY|ShiftMask,		XK_r,      spawn,	   {.v = helpcmd } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {1} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {0} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

