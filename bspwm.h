#ifndef _BSPWM_H
#define _BSPWM_H

#include "types.h"

#define ROOT_EVENT_MASK    (XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT | XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY)
#define CLIENT_EVENT_MASK  (XCB_EVENT_MASK_PROPERTY_CHANGE | XCB_EVENT_MASK_ENTER_WINDOW)

xcb_connection_t *dpy;
int default_screen, screen_width, screen_height;
uint32_t num_clients;
uint32_t num_desktops;
unsigned int num_monitors;
unsigned int monitor_uid;
unsigned int desktop_uid;
unsigned int client_uid;
xcb_screen_t *screen;
uint8_t root_depth;

split_mode_t split_mode;
direction_t split_dir;
monitor_t *mon;
monitor_t *last_mon;
monitor_t *mon_head;
monitor_t *mon_tail;
rule_t *rule_head;
pointer_state_t *frozen_pointer;
xcb_point_t pointer_position;

bool running;

void register_events(void);
void grab_buttons(void);
void ungrab_buttons(void);
void setup(void);
void quit(void);

#endif
