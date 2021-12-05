/*******************************************************************************
 *  _     _
 * | |__ (_) __ _
 * | '_ \| |/ _` |
 * | |_) | | (_| |
 * |_.__/|_|\__, |
 *          |___/
 ******************************************************************************/

#include "../../wrap_ncurses.hpp"

using namespace wn;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void action_pop(int id, std::string label) {
    __wn_dd("action_pop: ", id);
    __wn_dd("action_pop: ", label);
    print_status_msg("POP ACTION");
}

void action1() {
    hide_popup_dialog_panel();
    init_popup_dialog_panel();
    set_popup_readjust(false);
    create_popup_dialog_panel(80, 30, COLOR_WHITE_ON_RED);
    write_msg_row1_popup_dialog_panel("CENTER");
    write_msg_row2_popup_dialog_panel("LEFT LEFT LEFT LEFT", wn::ALIGN_TYPE::LEFT);
    write_msg_row3_popup_dialog_panel("RIGHT RIGHT RIGHT RIGHT", wn::ALIGN_TYPE::RIGHT);
    add_button_ok_popup_dialog_panel(&action_pop);
    add_button_cancel_popup_dialog_panel(&action_pop);
    add_button_popup_dialog_panel('x', "test", &action_pop);
    show_popup_dialog_panel();
}

void action2() {
    hide_popup_dialog_panel();
    print_status_msg("Demo xxx xxx xxx xxx xxx xxx xxx xxx");
    hide_popup_dialog_panel();
    init_popup_dialog_panel();
    set_popup_readjust(false);
    create_popup_dialog_panel(80, 30, COLOR_BLACK_ON_GREEN);
    write_msg_row1_popup_dialog_panel("CENTER");
    write_msg_row2_popup_dialog_panel("LEFT LEFT LEFT LEFT", wn::ALIGN_TYPE::LEFT);
    write_msg_row3_popup_dialog_panel("RIGHT RIGHT RIGHT RIGHT", wn::ALIGN_TYPE::LEFT);
    add_button_ok_popup_dialog_panel(&action_pop);
    add_button_cancel_popup_dialog_panel(&action_pop);
    show_popup_dialog_panel();
}

void action_btn(int id, std::string label) {
    action2();
    update_ui();
}

void action3() {
    hide_popup_dialog_panel();
    load_main_ui_config_name("1");
}

void action4() {
    hide_popup_dialog_panel();
    load_main_ui_config_name("2");
}

void action5() {
    hide_popup_dialog_panel();
    load_main_ui_config_name("3");
}

void action6() {
    hide_popup_dialog_panel();
    load_main_ui_config_name("4");
}

void action7() {
    hide_popup_dialog_panel();
    load_main_ui_config_name("5");
}

void action8() {
    hide_popup_dialog_panel();
    load_main_ui_config_name("6");
}

void action9() {
    hide_popup_dialog_panel();
    wn::Component *comp = get_component(2);
    __wn_dd("COMPONENT READ VALUE: ", comp->get_text());
}

void action_button(int id, std::string label) {

    __wn_dd("action_button: ", id);
    __wn_dd("action_button: ", label);

    std::vector<wn::Component*> *v = get_components_by_type("1", {UI_TYPE::BUTTON_TYPE, UI_TYPE::CHECKBOX_TYPE});
    for (auto i: *v) {
        __wn_dd("-------> : ", i->get_id());
    }
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {

    init_main_window(TRUE, "DEMO");

    int id_win = 999;
    int i = 0;

    wn::Container *conf = WN_CONTAINER("demo")->
                          ADD_WINDOWS(
    "1", {
        WN_WINDOW(888, 1, 1, 60, 10, "1", true, 1, true,
        {
            WN_LABEL(77888, 2, 3, 5, 1, "111: "),
            WN_TEXT(77889, 6, 3, 5, 1, ""),
            WN_LABEL(++i, 25, 3, 5, 1, "222: "),
            WN_TEXT(++i, 29, 3, 15, 1, "val"),
            WN_LABEL(++i, 2, 5, 5, 1, "xxx: "),
            WN_TEXT(++i, 6, 5, WN_RATIO(50) + 10, 1, "test"),
            WN_CHECKBOX(66445, 2, 8, 12, 1, ": checkbox", true)
        }),
        WN_WINDOW(++id_win, 1, 12, 60, 10, "2", true, 1, true,
        {
            WN_LABEL(++i, 2, 3, 5, 1, "name: "),
            WN_TEXT(++i, 8, 3, 5, 1, "xxx yyy zzz", 3),
        }),
        WN_WINDOW(++id_win, 62, 1, 20, 21, "3", true, 4, true,
        {
            WN_CHECKBOX(++i, 2, 3, 12, 1, "AAA", true),
            WN_CHECKBOX(++i, 2, 4, 12, 1, "BBB", false),
            WN_CHECKBOX(++i, 2, 5, 12, 1, "CCC", false),
            WN_CHECKBOX(++i, 2, 6, 12, 1, "DDD", true),
            WN_BUTTON(++i, 2, 10, 12, 1, 'h', "BUTTON", &action_button),
            WN_BUTTON(++i, 2, 12, 12, 1, 'j', "BUTTON", &action_button),
            WN_BUTTON(++i, 2, 14, 12, 1, 'k', "BUTTON", &action_button)
        }),
        WN_WINDOW(++id_win, 92, 1, 20, 21, "4", false, 9, true,
        {}),
        WN_WINDOW(++id_win, 62, 25, 50, 24, "5", true, 6, true,
        {}),
        WN_WINDOW(++id_win, 1, 25, 60, 4, "6", true, 3, true,
        {}),
        WN_WINDOW(++id_win, 1, 35, 60, 4, "7", true, 3, true,
        {}),
        WN_WINDOW(++id_win, 1, 45, 60, 4, "8", true, 3, true,
        {})
    })->
    ADD_WINDOWS(
    "2", {
        WN_WINDOW(++id_win, 1, 1, 60, 20, "1", true, 3, true,
        {
            WN_LABEL(4999, 2, 3, 5, 1, "name: "), WN_TEXT(++i, 8, 3, 25, 1, ""),
            WN_LABEL(++i, 2, 5, 5, 1, "name: "), WN_TEXT(++i, 8, 5, 25, 1, ""),
            WN_LABEL(++i, 2, 7, 5, 1, "name: "), WN_TEXT(++i, 8, 7, 25, 1, ""),
            WN_CHECKBOX(5000, 2, 9, 12, 1, "DDD", true),
            WN_CHECKBOX(5001, 2, 10, 12, 1, "AAA", false),
            WN_CHECKBOX(5002, 2, 11, 12, 1, "GGG", false),
            WN_BUTTON(5003, 2, 13, 12, 1, "BUTTON 1", &action_btn),
            WN_BUTTON(5004, 2, 14, 12, 1, "BUTTON 2", &action_btn),
        }),
        WN_WINDOW(++id_win, 0, 22, WN_RATIO(100, 150), WN_RATIO(56), "2", true, 5, true,
        {}),
        WN_WINDOW(++id_win, WN_RATIO(50) - 40, 5, 20, 11, "3", true, 6, false,
        {}),
        WN_WINDOW(++id_win, 92, 1, 20, 11, "4", false, 4, true,
        {}),
        WN_WINDOW(++id_win, WN_RATIO(50) + 4, 1, WN_RATIO(20), WN_RATIO(30), "5", false, 8, true,
        {}),
        WN_WINDOW(++id_win, WN_ALIGN_LEFT, 25, WN_RATIO(25), WN_RATIO(25, 40), "LEFT", true, 6, true,
        {}),
        WN_WINDOW(++id_win, WN_ALIGN_CENTER, 25, WN_RATIO(25), WN_RATIO(25, 40), "CENTER", true, 6, true,
        {}),
        WN_WINDOW(++id_win, WN_ALIGN_RIGHT, 25, WN_RATIO(25), WN_RATIO(25, 40), "RIGHT", true, 6, true,
        {}),
        WN_WINDOW(++id_win, WN_ALIGN_CENTER, WN_ALIGN_BOTTOM + 1, WN_RATIO(20), WN_RATIO(20, 40), "x", true, 1, true,
        {}),
        WN_WINDOW(++id_win, WN_ALIGN_LEFT, WN_ALIGN_BOTTOM + 1, WN_RATIO(50) - 12, WN_RATIO(20, 40), "y", true, 1, true,
        {}),
        WN_WINDOW(++id_win, WN_ALIGN_RIGHT + 1, WN_ALIGN_BOTTOM + 1, WN_RATIO(50) - 12, WN_RATIO(20, 40), "z", true, 1, true,
        {}),
        WN_WINDOW(++id_win, WN_RATIO(100) / 2, WN_RATIO(50) + 3, 7, 2, "DEMO", false, 10, true,
        {}),

    })->
    ADD_WINDOWS(
    "3", {
        WN_WINDOW(++id_win, WN_RATIO(0), WN_RATIO(0), WN_RATIO(50), WN_RATIO(50), "q 111", true, 4, true,
        {}),
        WN_WINDOW(++id_win, WN_RATIO(0), WN_RATIO(50), WN_RATIO(50), WN_RATIO(50), "q 222", true, 6, true,
        {}),
        WN_WINDOW(++id_win, WN_RATIO(50), WN_RATIO(0), WN_RATIO(50), WN_RATIO(50), "q 333", true, 8, true,
        {

            WN_BUTTON(++i, 2, 5, 12, 1, "BUTTON", &action_button),
            WN_BUTTON(++i, 2, 6, 12, 1, "BUTTON", &action_button),
            WN_BUTTON(++i, 2, 7, 12, 1, "BUTTON", &action_button)
        }),
        WN_WINDOW(++id_win, WN_RATIO(50), WN_RATIO(50), WN_RATIO(50), WN_RATIO(50), "q 444", true, 10, true,
        {}),
        WN_WINDOW(++id_win, 10, WN_ALIGN_TOP, WN_RATIO(20), WN_RATIO(10), "TOP", true, 2, true,
        {}),
        WN_WINDOW(++id_win, 10, WN_ALIGN_CENTER, WN_RATIO(20), WN_RATIO(10), "CENTER", true, 2, true,
        {}),
        WN_WINDOW(++id_win, 10, WN_ALIGN_BOTTOM, WN_RATIO(20), WN_RATIO(10), "BOTTOM", true, 2, true,
        {})
    })->
    ADD_WINDOWS(
    "4", {
        WN_WINDOW(++id_win, WN_ALIGN_CENTER, WN_ALIGN_TOP, WN_RATIO(50), WN_RATIO(50), "aaa", true, 7, true,
        {}),
        WN_WINDOW(++id_win, WN_ALIGN_CENTER + 5, WN_ALIGN_TOP + 2, WN_RATIO(40), WN_RATIO(40), "bbb", true, 1, true,
        {}),
        WN_WINDOW(++id_win, WN_ALIGN_CENTER + 10, WN_ALIGN_TOP + 4, WN_RATIO(25), WN_RATIO(30), "ccc", true, 2, true,
        {})
    })->
    ADD_WINDOWS(
    "5", {
        WN_WINDOW(++id_win, WN_RATIO(50), 5, WN_RATIO(50), 5, "xxx", true, 7, true,
        {}),
        WN_WINDOW(++id_win, 58, 15, WN_RATIO(50), 5, "yyy", true, 7, true,
        {}),
        WN_WINDOW(++id_win, WN_ALIGN_RIGHT, 25, WN_RATIO(50), 5, "zzz", true, 7, true,
        {}),
        WN_WINDOW(++id_win, WN_ALIGN_LEFT, WN_ALIGN_BOTTOM, WN_RATIO(50) + 20, 5, "Test Text", true, 4, true,
        {
            WN_LABEL(++i, 2, 3, 5, 1, "1: "),
            WN_TEXT(++i, 6, 3, WN_RATIO(55), 1, "test")
        })

    })->
    ADD_WINDOWS(
    "6", {
        WN_WINDOW(++id_win, 3, 3, WN_RATIO(95), WN_RATIO(30), "ciao", true, 1, true,
        {

            WN_LABEL(77777, WN_ALIGN_CENTER, WN_RATIO(50),     3, 1, "XXX"),
            WN_LABEL(88888, WN_ALIGN_CENTER, WN_RATIO(50) + 1, 3, 1, "XXX"),

        }),
        WN_WINDOW(++id_win, WN_ALIGN_CENTER, WN_RATIO(30) + 8, WN_RATIO(30), WN_RATIO(30), "TEST", true, 7, true,
        {})
    });

    set_colors(COLOR_WHITE_ON_BLUE);
    add_action('1', "111", &action1);
    add_action('2', "222", &action2);
    add_action('3', "333", &action3);
    add_action('4', "444", &action4);
    add_action('5', "555", &action5);
    add_action('6', "666", &action6);
    add_action('7', "777", &action7);
    add_action('8', "888", &action8);
    add_action('9', "999", &action9);
    add_action('A', "a", &action1);
    add_action('B', "b", &action1);
    add_action('C', "c", &action1);
    add_action('D', "d", &action1);
    add_action('E', "e", &action1);
    add_action('F', "f", &action1);
    add_action('G', "g", &action1);
    add_action('H', "h", &action1);
    add_action('I', "i", &action1);
    add_action('L', "l", &action1);
    add_action('M', "m", &action1);

    load_main_ui_config_name("1");
    load_main_ui_config_data(conf);

    wn::CheckBox *ck = static_cast<wn::CheckBox*> (wn::get_component(5000));
    if (ck) {
        ck->set_responsive(false);
        ck->set_responsive_color(4);
    }

    wn::Button *bt = wn::get_casted_component<wn::Button>(5003);
    if (bt) {
        bt->set_responsive(false);
        bt->set_responsive_color(4);
    }

    wn::Label *lb = wn::get_casted_component<wn::Label>(4999);
    if (lb) {
        lb->set_color(6);
    }

    std::vector<Component*> *vc = get_components_by_type("1", {UI_TYPE::LABEL_TYPE});
    __wn_dd("get_components_by_type - vc->size: ", (int)vc->size());

    wn::TextField *tf = wn::get_casted_component<wn::TextField>(77889);
    if (tf) {
        tf->set_text("xxx");
    }

    wn::Window *win = static_cast<wn::Window*> (get_component(888));

    run_app();

    return 0;
}

