// vim: expandtab tabstop=4 shiftwidth=4
#include <pebble.h>

static Window *s_window;

static void window_load(Window *window) {
}

static void window_unload(Window *window) {
    window_destroy(s_window);
}

static void click_config_provider(Window *window) {
    window_single_click_subscribe(BUTTON_ID_BACK, NULL);
}

static void main_window_push() {
    if (!s_window) {
        s_window = window_create();
        window_set_window_handlers(s_window, (WindowHandlers) {
                .load = window_load,
                .unload = window_unload
                });
        window_set_click_config_provider(s_window,
                (ClickConfigProvider) click_config_provider);
    }
    window_stack_push(s_window, true);
}

static void init() {
    main_window_push();
}

static void deinit() {
}

int main(void) {
    init();
    app_event_loop();
    deinit();
}
