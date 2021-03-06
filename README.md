![logo](https://github.com/baskerville/bspwm/raw/master/resources/bspwm_logo.png)

## Description

`bspwm` is a tiling window manager based on binary space partitioning.

The windows are represented as the leaves of a binary tree.

## Configuration

`bspwm` have only two sources of informations: the X events it receives and the messages it reads on a dedicated socket.

Those messages are sent via `bspc`.

If the `BSPWM_SOCKET` environment variable is defined, it will be used as the socket path, otherwise `/tmp/bspwm-socket` is used.

The recommended way of defining keyboard shortcuts is to use `xbindkeys`.

The only way to configure `bspwm` is by sending *set* messages via the client, hence `bspwm`'s configuration file is an executable called `autostart` which lives in `$XDG_CONFIG_HOME/bspwm/`.

Example configurations: [autostart](https://github.com/baskerville/bin/blob/master/bspwm_autostart) and [xbindkeysrc](https://github.com/baskerville/dotfiles/blob/master/xbindkeysrc).

## Splitting Modes

There is only two splitting modes: *automatic* and *manual*.

The default mode is *automatic*. The *manual* mode is entered by sending a *presel* message.

Example: insertion of a new node (number 4) into the given tree in
*automatic* mode:

                     b                                   c
                    / \                                 / \
                   3   a              -->              4   b
                   ^  / \                              ^  / \
                     2   1                               3   a
                                                            / \
                                                           2   1
        +-------------------------+         +-------------------------+
        |            |            |         |            |            |
        |            |     2      |         |            |     3      |
        |            |            |         |            |            |
        |     3      |------------|   -->   |     4      |------------|
        |     ^      |            |         |     ^      |     |      |
        |            |     1      |         |            |  1  |  2   |
        |            |            |         |            |     |      |
        +-------------------------+         +-------------------------+

Same departure, but the mode is *manual*, and a `presel up` message
was sent beforehand:

                     b                                   b
                    / \                                 / \
                   3   a              -->              c   a
                   ^  / \                             / \ / \
                     2   1                           4  3 2  1
                                                     ^
        +-------------------------+         +-------------------------+
        |            |            |         |            |            |
        |            |     2      |         |     4      |     2      |
        |            |            |         |     ^      |            |
        |     3      |------------|   -->   |------------|------------|
        |     ^      |            |         |            |            |
        |            |     1      |         |     3      |     1      |
        |            |            |         |            |            |
        +-------------------------+         +-------------------------+

## Messages

The syntax for the client is `bspc MESSAGE [ARGUMENTS ...]`.

The following messages are handled:

    get SETTING
        Return the value of the given setting.

    set SETTING VALUE
        Set the value of the given setting.

    list
        Output the internal representation of the window tree.

    list_desktops [--quiet]
        Perform a dump of each desktop for the current monitor.

    list_monitors [--quiet]
        Perform a dump of each monitor.

    list_windows
        Return the list of managed windows (i.e. their identifiers).

    presel left|right|up|down
        Switch to manual mode and select the splitting direction.

    cancel
        Switch to automatic mode.

    ratio VALUE
        Set the splitting ratio of the focused window.

    focus left|right|up|down
        Focus the neighbor window situated in the given direction.

    shift left|right|up|down
        Exchange the current window with the given neighbor.

    push left|right|up|down
        Push the fence located in the given direction.

    pull left|right|up|down
        Pull the fence located in the given direction.

    cycle next|prev [--skip-floating|--skip-tiled|--skip-class-equal|--skip-class-differ]
        Focus the next or previous window matching the given constraints.

    nearest older|newer [--skip-floating|--skip-tiled|--skip-class-equal|--skip-class-differ]
        Focus the nearest window matching the given constraints.

    toggle_fullscreen
        Toggle the fullscreen state of the current window.

    toggle_floating
        Toggle the floating state of the current window.

    toggle_locked
        Toggle the locked state of the current window (locked windows will not respond to the 'close' message).

    close
        Close the focused window.

    kill
        Kill the focused window.

    send_to DESKTOP_NAME
        Send the focused window to the given desktop.

    send_to_monitor MONITOR_NAME
        Send the focused window to the given monitor.

    use DESKTOP_NAME
        Select the given desktop.

    use_monitor MONITOR_NAME
        Select the given monitor.

    alternate
        Alternate between the current and the last focused window.

    alternate_desktop
        Alternate between the current and the last focused desktop.

    alternate_monitor
        Alternate between the current and the last focused monitor.

    add DESKTOP_NAME ...
        Make new desktops with the given names.

    add_in MONITOR_NAME DESKTOP_NAME ...
        Make new desktops with the given names in the given monitor.

    rename_monitor CURRENT_NAME NEW_NAME
        Rename the monitor named CURRENT_NAME to NEW_NAME.

    rename CURRENT_NAME NEW_NAME
        Rename the desktop named CURRENT_NAME to NEW_NAME.

    cycle_monitor next|prev
        Select the next or previous monitor.

    cycle_desktop next|prev [--skip-free|--skip-occupied]
        Select the next or previous desktop.

    layout monocle|tiled
        Set the layout of the current desktop.

    cycle_layout
        Cycle the layout of the current desktop.

    rotate clockwise|counter_clockwise|full_cycle
        Rotate the tree of the current desktop.

    magnetise top_left|top_right|bottom_left|bottom_right
        Move all the fences toward the given corner.

    rule PATTERN floating
        Make a new rule that will float the windows whose class name or instance name equals PATTERN.

    reload_autostart
        Reload the autostart file.

    reload_settings
        Reload the default settings.

    reload
        Reload the autostart file and the default settings.

    quit
        Quit.

## Settings

Colors are either [X color names](http://en.wikipedia.org/wiki/X11_color_names) or *#RRGGBB*, booleans are *true* or *false*.

    focused_border_color
        Color of the main border of a focused window of a focused monitor.

    active_border_color
        Color of the main border of a focused window of an unfocused monitor.

    normal_border_color
        Color of the main border of an unfocused window.

    inner_border_color
        Color of the inner border of a window.

    outer_border_color
        Color of the outer border of a window.

    presel_border_color
        Color of the *presel* message feedback.

    focused_locked_border_color
        Color of the main border of a focused locked window of a focused monitor.

    active_locked_border_color
        Color of the main border of a focused locked window of an unfocused monitor.

    normal_locked_border_color
        Color of the main border of an unfocused locked window.

    urgent_border_color
        Color of the border of an urgent window.

    inner_border_width
    main_border_width
    outer_border_width
        Width of the inner, main and outer borders.

    window_gap
        Value of the gap that separates windows.

    top_padding
    bottom_padding
    left_padding
    right_padding
        Padding space added at the sides of the screen.

    wm_name
        The value that shall be used for the _NET_WM_NAME property of the root window.

    button_modifier
        The modifier mask used for mouse bindings (possible values: 'mod1' ... 'mod5').

    borderless_monocle
        Whether to remove borders for tiled windows in monocle mode.

    focus_follows_mouse
        Wether to focus the window under the mouse pointer.

## Mouse Bindings

    button_modifier + left mouse button
        Move the window under the pointer.

    button_modifier + middle mouse button
        Focus the window under the pointer.

    button_modifier + right mouse button
        Resize the window under the pointer (by moving one of its four corners).

## Key Features

- Configured and controlled through messages
- Multiple monitors support (via *Xinerama*)
- EWMH support (`tint2` works)
- Automatic and manual modes
- Triple window borders

## Panel

`dzen2` fed with the output of `ewmhstatus`. Example: [launchpanel](https://github.com/baskerville/bin/blob/master/launchpanel).

Or any EWMH compliant panel.

## Required Libraries:

- libxcb
- xcb-util
- xcb-util-wm

## Installation

    make
    make install

## Contributors

- [Ivan Kanakarakis](https://github.com/c00kiemon5ter)
