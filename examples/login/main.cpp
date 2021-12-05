/*******************************************************************************
 *  _     ___   ____ ___ _   _   ____  _____ __  __  ___
 * | |   / _ \ / ___|_ _| \ | | |  _ \| ____|  \/  |/ _ \
 * | |  | | | | |  _ | ||  \| | | | | |  _| | |\/| | | | |
 * | |__| |_| | |_| || || |\  | | |_| | |___| |  | | |_| |
 * |_____\___/ \____|___|_| \_| |____/|_____|_|  |_|\___/
 *
 ******************************************************************************/

#include "../../wrap_ncurses.hpp"

using namespace wn;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void action_btn(int id, std::string label) {
    __wn_dd("action_button: ", id);
    __wn_dd("action_button: ", label);
}

void quit() {
    hide_popup_dialog_panel();
    quit_app();
    exit(0);
}

int main(int argc, char** argv) {

    init_main_window(TRUE, "LOGIN_DEMO");

    wn::Container *conf = WN_CONTAINER("demo")->ADD_WINDOWS(
    "1", {
        WN_WINDOW(1000, 3, 3, 60, 20, "Login", true, 1, true,
        {
            WN_LABEL	 (1, 4,  3,  30, 1, "User: "),
            WN_TEXT	 (2, 4,  5,  30, 1, "example"),
            WN_LABEL	 (3, 4,  7,  30, 1, "Password: "),
            WN_TEXT	 (4, 4,  9,  30, 1, "**********", COLOR_WHITE_ON_RED),
            WN_LABEL	 (5, 4,  11, 30, 1, "------------------------------"),
            WN_CHECKBOX (7, 4,  13, 12, 1, ": remember", true),
            WN_BUTTON	 (8, 4,  15, 12, 1, "OK", &action_btn),
            WN_BUTTON	 (9, 22, 15, 12, 1, "CANCEL", &action_btn)
        })
    });

    set_colors(COLOR_WHITE_ON_BLUE);

    add_action('0', "quit", &quit);

    load_main_ui_config_name("1");
    load_main_ui_config_data(conf);

    run_app();

    return 0;
}
