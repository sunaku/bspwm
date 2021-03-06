#ifndef _TREE_H
#define _TREE_H

#define INC_EXP 0.9
#define DEC_EXP 1.1

bool is_leaf(node_t *);
bool is_tiled(client_t *);
bool is_floating(client_t *);
bool is_first_child(node_t *);
bool is_second_child(node_t *);
void change_split_ratio(node_t *, value_change_t);
node_t *first_extrema(node_t *);
node_t *second_extrema(node_t *);
node_t *next_leaf(node_t *);
node_t *prev_leaf(node_t *);
node_t *find_fence(node_t *, direction_t);
node_t *find_neighbor(node_t *, direction_t);
void move_fence(node_t *, direction_t, fence_move_t);
void rotate_tree(node_t *, rotate_t);
void magnetise_tree(node_t *, corner_t);
void arrange(monitor_t *, desktop_t *);
void apply_layout(monitor_t *, desktop_t *, node_t *, xcb_rectangle_t, xcb_rectangle_t);
void insert_node(desktop_t *, node_t *);
void dump_tree(desktop_t *, node_t *, char *, unsigned int);
void list_desktops(monitor_t *, list_option_t, unsigned int, char *);
void list_monitors(list_option_t, char *);
void focus_node(monitor_t *, desktop_t *, node_t *, bool);
void update_current(void);
void unlink_node(desktop_t *, node_t *);
void remove_node(desktop_t *, node_t *);
void swap_nodes(node_t *, node_t *);
void fit_monitor(monitor_t *, client_t *);
void translate_coordinates(monitor_t *, monitor_t *, client_t *);
void transfer_node(monitor_t *, desktop_t *, monitor_t *, desktop_t *, node_t *);
void select_monitor(monitor_t *);
void select_desktop(desktop_t *);
void cycle_monitor(cycle_dir_t);
void cycle_desktop(monitor_t *, desktop_t *, cycle_dir_t, skip_desktop_t);
void cycle_leaf(monitor_t *, desktop_t *, node_t *, cycle_dir_t, skip_client_t);
void nearest_leaf(monitor_t *, desktop_t *, node_t *, nearest_arg_t, skip_client_t);
void update_vacant_state(node_t *);
void add_desktop(monitor_t *, char *);
void add_monitor(xcb_rectangle_t *);
monitor_t *find_monitor(char *);

#endif
