/*******************************************************************************
 *  _ __   ___  _ __  _   _ _ __
 * | '_ \ / _ \| '_ \| | | | '_ \
 * | |_) | (_) | |_) | |_| | |_) |
 * | .__/ \___/| .__/ \__,_| .__/
 * |_|         |_|         |_|
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

void close_popup(int id, std::string label) {
    hide_popup_dialog_panel();
    repaint_ui();
}

void popup() {

    hide_popup_dialog_panel();
    repaint_ui();

    init_popup_dialog_panel();
    set_popup_readjust(true);

    create_popup_dialog_panel(60, 20, COLOR_BLACK_ON_CYAN);
    write_msg_row1_popup_dialog_panel("RUN");
    write_msg_row2_popup_dialog_panel(" ");
    write_msg_row3_popup_dialog_panel("Confirm run backups ?", wn::ALIGN_TYPE::CENTER);

    add_button_ok_popup_dialog_panel(&close_popup);
    add_button_cancel_popup_dialog_panel(&close_popup);

    show_popup_dialog_panel();
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void add_items() {

    int key = 5000, h = 5;
    std::vector<std::string> items = {"aaa","bbb","ccc", "ddd", "eee"};

    wn::Window *win = static_cast<wn::Window*> (get_component(3000));

    for(std::string &i : items) {
        auto ck = WN_CHECKBOX(key++, WN_ALIGN_CENTER, h++, WN_RATIO(80), 1, i, false);
        win->insert_item(ck);
    }
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {

    init_main_window(TRUE, "POPUP_DEMO");

    int id = 0;

    wn::Container *conf = WN_CONTAINER("demo")->ADD_WINDOWS(
    "1", {
        WN_WINDOW(1000, WN_ALIGN_CENTER, WN_ALIGN_TOP, WN_RATIO(80), WN_RATIO(30), "TOP", true, COLOR_WHITE_ON_BLACK, true,
        {
            WN_LABEL (++id, 4,  3,  30, 1, "Demo: "),
            WN_LABEL (++id, 4,  5,  WN_RATIO(90), 1, "------------------------------"),
            WN_TEXT  (++id, 4, 7, WN_RATIO(50) + 10, 1, "test"),
            WN_TEXT  (++id, 4, 9, WN_RATIO(50) + 10, 1, "test")

        }),
        WN_WINDOW(2000, WN_ALIGN_CENTER, WN_ALIGN_CENTER - 3, WN_RATIO(80), 10, "CENTER", true, COLOR_WHITE_ON_BLACK, true,
        {
            WN_LABEL (++id, 4,  2,  30, 1, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. trices tincidunt vitae id turpis."),
            WN_BUTTON(++id, 4, 6, 12, 1, "BUTTON 1", &action_btn),
            WN_BUTTON(++id, 4, 7, 12, 1, "BUTTON 2", &action_btn),
        }),
        WN_WINDOW(3000, WN_ALIGN_CENTER, WN_ALIGN_BOTTOM - 6, WN_RATIO(80), WN_RATIO(50) - 10, "BOTTOM", true, COLOR_WHITE_ON_BLACK, true,
        {

        })
    });

    set_colors(COLOR_YELLOW_ON_BLACK);

    add_action('0', "quit", &quit);
    add_action('1', "popup", &popup);

    load_main_ui_config_name("1");
    load_main_ui_config_data(conf);

    add_items();

    run_app();

    return 0;
}
