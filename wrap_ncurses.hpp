/*******************************************************************************
 * __        ______      _    ____  _   _  ____ _   _ ____  ____  _____ ____
 * \ \      / /  _ \    / \  |  _ \| \ | |/ ___| | | |  _ \/ ___|| ____/ ___|
 *  \ \ /\ / /| |_) |  / _ \ | |_) |  \| | |   | | | | |_) \___ \|  _| \___ \
 *   \ V  V / |  _ <  / ___ \|  __/| |\  | |___| |_| |  _ < ___) | |___ ___) |
 *    \_/\_/  |_| \_\/_/   \_\_|___|_| \_|\____|\___/|_| \_\____/|_____|____/
 *                            |_____|
 ******************************************************************************/

/*******************************************************************************
 *                                                                             *
 *  The MIT License (MIT)                                                      *
 *                                                                             *
 *  Copyright © 2021 <Riccata2010>                                             *
 *                                                                             *
 *  Permission is hereby granted, free of charge, to any person obtaining a    *
 *  copy of this software and associated documentation files (the “Software”), *
 *  to deal in the Software without restriction, including without limitation  *
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,   *
 *  and/or sell copies of the Software, and to permit persons to whom the      *
 *  Software is furnished to do so, subject to the following conditions:       *
 *                                                                             *
 *  The above copyright notice and this permission notice shall be included    *
 *  in all copies or substantial portions of the Software.                     *
 *                                                                             *
 *  THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS    *
 *  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,*
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    *
 *  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER *
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    *
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        *
 *  DEALINGS IN THE SOFTWARE.                                                  *
 *                                                                             *
 ******************************************************************************/

/*******************************************************************************
 *   Author: Riccata2010 (https://github.com/Riccata2010)                      *
 ******************************************************************************/

// $Id: wrap_ncurses.hpp,v 1.00 2021/20/06 18:00:00 Exp $
// $CH-20:06:21:   Modifica per gestione percentuali.
// $CH-24:06:21:   Inizio inserimento gestione componenti text.
// $CH-25:06:21:   Modifica per focus su componente text.
// $CH-01:07:21:   Implemementato spostamento cursore nelle text.
// $CH-02:07:21:   Iniziate le checkbox.
// $CH-08:07:21:   Finita funzione per ricavare i componenti su base id.
// $CH-08:07:21:   Modifica per non sensibili.
// $CH-21:07:21:   Iniziato commenti codice.
// $CH-18:09:21:   Controllo allineamento Label (usare num. corrente di char).
// $CH-21:09:21:   Inserimento mutex per aggiornamento gui.
// $CH-22:09:21:   Aggiunta funz. per sapere se e' show la popup.
// $CH-25:09:21:   Aggiunta funz. cursor 0 e nessuna echo dei caratteri.
// $CH-05:10:21:   Inizio aggiornamento Window per rimozione fields.
// $CH-05:11:21:   Modifica per aggiornamento dalla window.
// $CH-05:11:21:   Aggiunto flag per sapere se run_app e' attivo.
// $CH-13:11:21:   Modifica per funzioni static.
// $CH-05:12:21:   Controllo formattazione.

#ifndef WRAP_NCURSES_H
#define WRAP_NCURSES_H

//****************************************************************************//
//****************************************************************************//
//****************************************************************************//

#include <ncurses.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <fstream>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <atomic>
#include <memory>
#include <thread>
#include <mutex>

//****************************************************************************//
//****************************************************************************//
//****************************************************************************//

#define WN_ALIGN_CENTER                  WN_ALIGN_CENTER_DEF()
#define WN_ALIGN_LEFT                    WN_ALIGN_LEFT_DEF()
#define WN_ALIGN_RIGHT                   WN_ALIGN_RIGHT_DEF()
#define WN_ALIGN_TOP                     WN_ALIGN_TOP_DEF()
#define WN_ALIGN_BOTTOM                  WN_ALIGN_BOTTOM_DEF()

//****************************************************************************//
//****************************************************************************//
//****************************************************************************//

#define LOG_ON_FILE
#define SDEF_ID_POP                     -10000

#ifndef MAX_PRINTED_ACTION
#define MAX_PRINTED_ACTION              9
#endif

#ifndef MAX_HIGHLIGHT_ACTION
#define MAX_HIGHLIGHT_ACTION            14
#endif

#ifndef MIN_HIGHLIGHT_ACTION
#define MIN_HIGHLIGHT_ACTION            8
#endif

#define COLOR_WHITE_ON_BLUE             1
#define COLOR_BLACK_ON_CYAN             2
#define COLOR_WHITE_ON_BLACK            3
#define COLOR_YELLOW_ON_BLACK           4
#define COLOR_YELLOW_ON_BLUE            5
#define COLOR_CYAN_ON_MAGENTA           6
#define COLOR_WHITE_ON_MAGENTA          7
#define COLOR_WHITE_ON_RED              8
#define COLOR_WHITE_ON_GREEN            9
#define COLOR_BLACK_ON_GREEN            10
#define COLOR_BLACK_ON_BLUE             11
#define COLOR_RED_ON_BLUE               12
#define COLOR_CYAN_ON_BLUE              13
#define COLOR_MAGENTA_ON_BLUE           14

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

#define ERR_INIT_MAIN_WINDOW            -100
#define ERR_INIT_MAIN_WINDOW_LOG        "ERROR: Wrong initialising ncurses."
#define ERR_UI_CFG_NOT_FOUND            -200
#define ERR_UI_CFG_NOT_FOUND_LOG        "ERROR: UI Configuration not found."
#define ERR_NAME_CFG_NOT_FOUND          -300
#define ERR_NAME_CFG_NOT_FOUND_LOG      "ERROR: Name Configuration not found."

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

#ifndef MIN_WIDTH_SIZE_FRAME
#define MIN_WIDTH_SIZE_FRAME            12
#endif

#ifndef MIN_HEIGHT_SIZE_FRAME
#define MIN_HEIGHT_SIZE_FRAME           12
#endif

#ifndef NEXT_ACTION_KEY_CODE
#define NEXT_ACTION_KEY_CODE            62
#endif

#ifndef BACK_ACTION_KEY_CODE
#define BACK_ACTION_KEY_CODE            60
#endif

#ifndef RESIZE_CODE
#define RESIZE_CODE                     410
#endif

#ifndef TAB_KEY_CODE
#define TAB_KEY_CODE                    9
#endif

#ifndef CANC_KEY_CODE
#define CANC_KEY_CODE                   24
#endif

#ifndef CANC_EX_KEY_CODE
#define CANC_EX_KEY_CODE                330
#endif

#ifndef DEL_KEY_CODE
#define DEL_KEY_CODE                    127
#endif

#ifndef BS_KEY_CODE
#define BS_KEY_CODE                     8
#endif

#ifndef BS_EX_KEY_CODE
#define BS_EX_KEY_CODE                  263
#endif

#ifndef BOX_DIALOG_POPUP
#define BOX_DIALOG_POPUP                0        // Box Dialog
#endif

#ifndef ENTER_KEY_CODE
#define ENTER_KEY_CODE                  13       // Enter
#endif

#ifndef ENTER_EX_KEY_CODE
#define ENTER_EX_KEY_CODE               10       // Line Feed
#endif

#ifndef ENTER_TEXT_LABEL
#define ENTER_TEXT_LABEL                "Ok"     // Button ok
#endif

#ifndef ESC_KEY_CODE
#define ESC_KEY_CODE                    27       // Esc
#endif

#ifndef CANCEL_TEXT_LABEL
#define CANCEL_TEXT_LABEL               "Cancel"  // Button Cancel 
#endif

#ifndef MIN_CHAR_ACP
#define MIN_CHAR_ACP                    32        // ASCII
#endif

#ifndef MAX_CHAR_ACP
#define MAX_CHAR_ACP                    126       // ASCII
#endif

#ifndef CURSOR_LIMIT_COLORS
#define CURSOR_LIMIT_COLORS             0         // Color limit cursor
#endif

//****************************************************************************//
//****************************************************************************//
//****************************************************************************//

typedef long unsigned int ulong_t;
typedef int geometry_t;

//****************************************************************************//
//****************************************************************************//
//****************************************************************************//

namespace wn {
//----------------------------------------------------------------------------//
enum ACTION_TYPE {
    UPDATE,
    USER,
    NEXT,
    BACK,
    KLEFT,
    KRIGHT,
    FOCUS,
    BS,
    CANC,
    ENTER,
    ESC
};
//----------------------------------------------------------------------------//
enum ALIGN_TYPE {
    UNDEFINED,
    LEFT,
    CENTER,
    RIGHT,
    TOP,
    BOTTOM
};
//----------------------------------------------------------------------------//
class Ratio {
public:
    geometry_t value        = 0;
    geometry_t percentage   = 0;
    geometry_t max          = 0;
    bool ratio              = false;
    ALIGN_TYPE align        = ALIGN_TYPE::UNDEFINED;
    short operation         = 0;

    /**
     * Questo costrutore viene invocato con la creazione di solo un intero
     * interpretato come un valore fisso e non una percentuale.
     * @param value
     */
    Ratio(geometry_t value) : value(value) {
    }

    /**
     * Con questo costruttore si calcolano le percentuali.
     * @param percentage
     * @param max
     * @param ratio
     * @param align
     */
    Ratio(geometry_t percentage,
          geometry_t max,
          bool ratio,
          ALIGN_TYPE align) :
        percentage(percentage),
        max(max),
        ratio(ratio),
        align(align) {
    }

    inline Ratio operator+(int v) {
        value = v;
        operation = 1;
        return *this;
    }

    inline Ratio operator-(int v) {
        value = v;
        operation = 2;
        return *this;
    }

    inline Ratio operator/(int v) {
        value = v;
        operation = 3;
        return *this;
    }

    inline Ratio operator*(int v) {
        value = v;
        operation = 4;
        return *this;
    }

};
//----------------------------------------------------------------------------//
typedef void(*__fp_key_action_t)(void);
typedef void(*__fp_btn_key_action_t)(int, std::string);
//----------------------------------------------------------------------------//
struct __data_key_action {
    char key;
    char *label;
    __fp_key_action_t action;
};
//----------------------------------------------------------------------------//
struct __data_pop_key_action {
    char key;
    char *label;
    __fp_btn_key_action_t action;
};
//----------------------------------------------------------------------------//
static std::ofstream        __log_file;
static std::stack<int>      __action_stack;
static int                  __current_key;
static ACTION_TYPE          __current_action = ACTION_TYPE::UPDATE;
//----------------------------------------------------------------------------//
static int                  __main_window_x                  = -1;
static int                  __main_window_y                  = -1;
static int                  __main_colors                    = -1;
//----------------------------------------------------------------------------//
static int                  __action_paging                  = 0;
static int                  __action_last_index              = 0;
static int                  __action_printed                 = 0;
static int                  __action_next                    = 0;
//----------------------------------------------------------------------------//
static std::atomic<bool>    __popup_showed(false);
static std::atomic<bool>    __run_app_activated(false);
//----------------------------------------------------------------------------//
static bool                 __popup_first_time               = true;
static bool                 __popup_readjust                 = true;
static int                  __popup_width_percentage         = -1;
static int                  __popup_height_percentage        = -1;
static int                  __popup_width_val                = -1;
static int                  __popup_height_val               = -1;
static int                  __popup_colors                   = -1;
static int                  __popup_buttons_text_length      = 0;
//----------------------------------------------------------------------------//
static std::string          __popup_msg_text_row1;
static std::string          __popup_msg_text_row2;
static std::string          __popup_msg_text_row3;
static wn::ALIGN_TYPE       __popup_align_text_row1;
static wn::ALIGN_TYPE       __popup_align_text_row2;
static wn::ALIGN_TYPE       __popup_align_text_row3;
//----------------------------------------------------------------------------//
static std::list<char>      __popup_buttons_key;
//----------------------------------------------------------------------------//
static char                 *__main_title;
static char                 *__status_message;
//----------------------------------------------------------------------------//
static std::vector<char>                     __key_actions;
static std::map<char, __data_key_action>     __map_actions;
static std::map<char, __data_pop_key_action> __map_popup_actions;
//----------------------------------------------------------------------------//
static WINDOW       *__popup_dialog       = nullptr;
static WINDOW       *__center_window      = nullptr;
static WINDOW       *__main_window        = nullptr;
//----------------------------------------------------------------------------//
static bool go_next = false;
static bool go_back = false;
//----------------------------------------------------------------------------//
static std::string __current_name_group;
static std::mutex  __g_mutex;
//----------------------------------------------------------------------------//
};

//****************************************************************************//
//****************************************************************************//
//****************************************************************************//

/**
 * DEBUG
 */
inline void __wn_dd(const std::string &log, const std::string &msg) {
#ifdef LOG_ON_FILE
    wn::__log_file << log << msg << std::endl;
    wn::__log_file.flush();
#endif
}

/**
 * DEBUG
 */
inline void __wn_dd(const std::string &log, int n) {
#ifdef LOG_ON_FILE
    wn::__log_file << log << n << std::endl;
    wn::__log_file.flush();
#endif
}

/**
 * DEBUG
 */
inline void __wn_dd(const std::string &log1, int n1, const std::string &log2, int n2) {
#ifdef LOG_ON_FILE
    wn::__log_file << log1 << n1 << log2 << n2 << std::endl;
    wn::__log_file.flush();
#endif
}

/**
 * DEBUG
 */
inline void __wn_dd(const std::string &log, unsigned int n) {
#ifdef LOG_ON_FILE
    wn::__log_file << log << n << std::endl;
    wn::__log_file.flush();
#endif
}

/**
 * DEBUG
 */
inline void __wn_dd(const std::string &log, bool val) {
#ifdef LOG_ON_FILE
    wn::__log_file << log << val << std::endl;
    wn::__log_file.flush();
#endif
}

/**
 * DEBUG
 */
inline void __wn_dd(const std::string &log) {
#ifdef LOG_ON_FILE
    wn::__log_file << log << std::endl;
    wn::__log_file.flush();
#endif
}

/**
 * Range accepted char value.
 */
inline bool __wn_is_accepted_ascii_char(int ch) {
    return ch >= MIN_CHAR_ACP && ch <= MAX_CHAR_ACP;
}

/**
 * Read text value from screen.
 * @param win
 * @param x
 * @param y
 * @param length
 * @return
 */
inline std::string __wn_read_from_scrn(WINDOW *win, int x, int y, ulong_t length) {

    std::string result = "";
    chtype raw[length + 1] {0};

    if (mvwinchnstr(win, y, x, raw, length) != ERR) {
        for (unsigned int i = 0; i < length; ++i) {
            char ch = raw[i] & A_CHARTEXT;
            result += ch;
        }
    }
    return result;
}

/**
 * Return true if a map contains key value.
 * @param map
 * @param key
 * @return
 */
template<class K, class V>
inline bool __wn_map_contains(std::map<K, V> &map, const K &key) {
    typename std::map<K, V>::iterator it = map.find(key);
    return it != map.end();
}

/**
 * Return true if an std::initializer_list<T> contains one value equal of find.
 * @param types
 * @param find
 * @return
 */
template<class T>
inline bool __wn_initializer_list_contains(std::initializer_list<T> &types, const T &find) {
    for (auto &item : types) {
        if (item == find)
            return true;
    }
    return false;
}

/**
 * Return an integer used for positioning component on the screen.
 */
inline int __wn_compute_alignement(
    int w_frame,
    int width,
    wn::ALIGN_TYPE align_type,
    int padding) {

    int align = 0;

    switch (align_type) {
    case wn::ALIGN_TYPE::TOP:
    case wn::ALIGN_TYPE::LEFT:
    {
        align = padding;
        break;
    }
    case wn::ALIGN_TYPE::BOTTOM:
    case wn::ALIGN_TYPE::RIGHT:
    {
        align = w_frame - padding * 2 > width ?
                ((w_frame - 1) - width) - padding : padding;
        break;
    }
    default:
    {
        align = (((w_frame) / 2) - (width / 2));
    }
    }

    return align;
}

inline int __wn_compute_alignement(
    int w_frame,
    std::string label,
    wn::ALIGN_TYPE align_type,
    int padding) {
    return __wn_compute_alignement(w_frame,
                                   label.length(), align_type, padding);
}

inline int __wn_ratio(
    int orig,
    int total,
    int offset,
    const wn::Ratio &ratio) {

    //#ifdef LOG_ON_FILE
    //    std::stringstream ss;
    //    ss << "***************************" << std::endl;
    //    ss << "\t{Ratio}" << std::endl;
    //    ss << "\tvalue      :" << ratio.value << std::endl;
    //    ss << "\tpercentage :" << ratio.percentage << std::endl;
    //    ss << "\toperation  :" << ratio.operation << std::endl;
    //    ss << "\tmax        :" << ratio.max << std::endl;
    //    ss << "\talign      :" << ratio.align << std::endl;
    //    ss << "***************************" << std::endl;
    //    __wn_dd(ss.str());
    //#endif

    if (!ratio.ratio)
        return orig;

    int percentage = ratio.percentage;
    int max = ratio.max;

    if (ratio.align == wn::ALIGN_TYPE::UNDEFINED && percentage <= 0)
        return 0;

    switch (ratio.align) {
    case wn::ALIGN_TYPE::UNDEFINED:
    {
        orig = ((total - offset) * percentage) / 100;
        break;
    }
    default:
    {
        orig = __wn_compute_alignement(total, orig, ratio.align, offset);
    }
    }

    switch (ratio.operation) {
    case 1:
    {
        orig += ratio.value;
        break;
    }
    case 2:
    {
        orig -= ratio.value;
        break;
    }
    case 3:
    {
        orig /= ratio.value;
        break;
    }
    case 4:
    {
        orig *= ratio.value;
        break;
    }
    }

    return (max > 0 && orig > max) ? max : orig;
}

inline void __wn_format_geometry(
    int max_x,
    int max_y,
    const wn::Ratio &xr,
    const wn::Ratio &yr,
    const wn::Ratio &wr,
    const wn::Ratio &hr,
    int &x,
    int &y,
    int &w,
    int &h,
    int xw_offset,
    int yh_offset) {

    /**
     * NOTA: In base alla dimensione della finestra se e' stato impostato
     * un ratio si calcola la percentuale o posizione, altrimenti ritorna
     * il valore passato come primo parametro.
     *
     * Nel caso vi sia un allienamento ho bisogno prima della w o h, quindi
     * salto per ora x e y, calcolo w e h e poi base ai valori calcolo x e y
     * ma solo per allineamento.
     */

    if (xr.align == wn::ALIGN_TYPE::UNDEFINED) {
        x = __wn_ratio(x, max_x, xw_offset /*0*/, xr);
    }

    if (yr.align == wn::ALIGN_TYPE::UNDEFINED) {
        y = __wn_ratio(y, max_y, yh_offset /*2*/, yr);
    }

    w = __wn_ratio(w, max_x, xw_offset, wr);
    h = __wn_ratio(h, max_y, yh_offset, hr);

    if (xr.align != wn::ALIGN_TYPE::UNDEFINED) {
        x = __wn_ratio(w, max_x, xw_offset, xr);
    }

    if (yr.align != wn::ALIGN_TYPE::UNDEFINED) {
        y = __wn_ratio(h, max_y, yh_offset, yr);
    }
}

std::string __wn_format_button(char key, std::string &label) {

    std::string result = "";

    if (key == ENTER_KEY_CODE || key == ENTER_EX_KEY_CODE) {

        result.append("[").append(" ")
        .append("Enter (").append(label).append(") ]");

    } else if (key == ESC_KEY_CODE) {

        result.append("[").append(" ")
        .append("Esc (").append(label).append(") ]");

    } else if (key > 0) {

        result.append("[").append(" ")
        .append(std::string(1, key))
        .append(" (").append(label).append(") ]");

    } else {

        result.append("[").append(" (").append(label).append(") ]");
    }

    return result;
}

std::string __wn_format_button_label(char key, const char *label) {
    std::string s(label);
    return __wn_format_button(key, s);
}

void __wn_print_text_popup(int num_row,
                           std::string msg, wn::ALIGN_TYPE align_text, int pop_w) {

    if (msg.length() > pop_w - 10) {
        msg = msg.substr(0, pop_w - 10);
    }

    int align = __wn_compute_alignement(pop_w, msg.length(), align_text, 5);

    mvwprintw(wn::__popup_dialog, num_row, align, msg.c_str());
}

void __wn_set_msg_rows_popup(const char *message,
                             wn::ALIGN_TYPE align_text, std::string &r, wn::ALIGN_TYPE &a) {
    a = align_text;
    std::stringstream ss;
    ss << message;
    r = ss.str();
}

void __wn_put_action_popup_dialog(char key_val,
                                  const char **label_val, void (**pfun)(int, std::string)) {

    int label_length = strlen(*label_val);

    wn::__data_pop_key_action data = {
        .key = key_val,
        .label = new char[label_length + 12] {
            0
        },
        .action = *pfun
    };

    strcpy(data.label, __wn_format_button_label(data.key, *label_val).c_str());

    label_length = strlen(data.label);

    wn::__popup_buttons_text_length += label_length;
    wn::__map_popup_actions[key_val] = data;
    wn::__popup_buttons_key.push_back(key_val);
}

template<class L>
void __wn_str_token_exec(std::string text,
                         const std::string delim, bool add_delim, L func) {
    size_t index = 0, ldem = delim.length();
    std::string token = "";
    while ((index = text.find(delim)) != std::string::npos) {
        token = text.substr(0, index);
        func(add_delim ? delim + token : token);
        text.erase(0, index + ldem);
    }
    func(add_delim ? delim + text : text);
}

//****************************************************************************//
//****************************************************************************//
//****************************************************************************//

namespace wn {

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

enum UI_TYPE {
    COMPONENT_TYPE = 0,
    WINDOW_TYPE,
    BUTTON_TYPE,
    LABEL_TYPE,
    TEXT_TYPE,
    CHECKBOX_TYPE
};

//============================================================================//
//============================================================================//
//============================================================================//

class Textualizable {
public:
    virtual std::string to_string() = 0;
};

//============================================================================//
//============================================================================//
//============================================================================//

class Component : public Textualizable {
protected:

    int id                  = -1;
    geometry_t x            = -1;
    geometry_t y            = -1;
    geometry_t w            = -1;
    geometry_t h            = -1;
    geometry_t rx           = -1;
    geometry_t ry           = -1;
    geometry_t rw           = -1;
    geometry_t rh           = -1;
    char key                = 0;
    UI_TYPE type            = UI_TYPE::COMPONENT_TYPE;
    bool box_value          = false;
    bool visible            = true;
    int color               = -1;
    wn::Ratio x_ratio       = {0};
    wn::Ratio y_ratio       = {0};
    wn::Ratio w_ratio       = {0};
    wn::Ratio h_ratio       = {0};
    WINDOW *window          = nullptr;
    std::string text        = "";
    std::string label       = "";
    std::string properties  = "";
    bool ck_value           = false;
    bool responsive         = true;
    int responsive_color    = -1;
    void (*before)(int)     = nullptr;
    void (*after)(int)      = nullptr;

    Component() {
    }

    Component(UI_TYPE type) : type(type) {
    }

    Component(int id,
              geometry_t x,
              geometry_t y,
              geometry_t w,
              geometry_t h) :
        id(id),
        x(x),
        y(y),
        w(w),
        h(h) {
    }

    Component(int id,
              geometry_t x,
              geometry_t y,
              geometry_t w,
              geometry_t h,
              char key,
              const std::string &label,
              UI_TYPE type) :
        id(id),
        x(x),
        y(y),
        w(w),
        h(h),
        key(key),
        label(label),
        type(type) {
    }

    Component(int id,
              geometry_t x,
              geometry_t y,
              geometry_t w,
              geometry_t h,
              const std::string &label,
              bool box,
              int color,
              UI_TYPE type,
              bool visible) :
        id(id),
        x(x),
        y(y),
        w(w),
        h(h),
        label(label),
        box_value(box),
        color(color),
        type(type),
        visible(visible) {
    }

    Component(int id,
              geometry_t x,
              geometry_t y,
              geometry_t w,
              geometry_t h,
              char key,
              const std::string &text,
              const std::string &label,
              UI_TYPE type,
              bool visible) :
        id(id),
        x(x),
        y(y),
        w(w),
        h(h),
        key(key),
        text(text),
        label(label),
        type(type),
        visible(visible) {
    }

public:

    virtual ~Component() {

#ifdef LOG_ON_FILE
        wn::__log_file << "Distructor of Component - CALLED\n";
        wn::__log_file << this->to_string() << "\n";
        wn::__log_file.flush();
#endif

    }

    virtual void after_mod_listener(void (*f)(int)) {
        this->after = f;
    }

    virtual void before_mod_listener(void (*f)(int)) {
        this->before = f;
    }

    virtual void update_after_mod() {
        if (this->after) {
            after(this->get_id());
        }
    }

    virtual void update_before_mod() {
        if (this->before) {
            before(this->get_id());
        }
    }

    virtual bool print_component(bool focus) {
        return false;
    }

    virtual bool update_component(bool focus) {
        return false;
    }

    virtual bool update_component(ACTION_TYPE action, char typed, bool focus) {
        return false;
    }

    virtual void delete_window() {
        if (window) {
            delwin(window);
            window = nullptr;
        }
    }

    /**
     * Call this after each print_component to take effect.
     */
    virtual void repaint() {
        if (window) {
            refresh();
            wrefresh(window);
        }
    }

    virtual void focus_lost() {
    }

    virtual int set_focus_here() {
        return set_focus_here(rx, ry);
    }

    virtual int set_focus_here(int value_x, int value_y) {
        int result = wmove(window, value_y, value_x);
        refresh();
        wrefresh(window);
        return result;
    }

    virtual std::string empty_value() const {
        std::stringstream ss;
        for (int i = 0; i < this->rw; ++i) {
            ss << " ";
        }
        return ss.str();
    }

    virtual void set_WINDOW(WINDOW *&win) {
        this->window = win;
    }

    virtual WINDOW *get_WINDOW() const {
        return this->window;
    }

    virtual void set_responsive(bool v) {
        this->responsive = v;
    }

    virtual bool get_responsive() const {
        return this->responsive;
    }

    virtual void set_responsive_color(int c) {
        this->responsive_color = c;
    }

    virtual int get_responsive_color() const {
        return this->responsive_color;
    }

    virtual void set_ck_value(bool v) {
        this->ck_value = v;
    }

    virtual bool get_ck_value() const {
        return this->ck_value;
    }

    virtual void set_id(int id) {
        this->id = id;
    }

    virtual int get_id() const {
        return this->id;
    }

    virtual void set_x(geometry_t x) {
        this->x = x;
    }

    virtual geometry_t get_x() const {
        return this->x;
    }

    virtual void set_y(geometry_t y) {
        this->y = y;
    }

    virtual geometry_t get_y() const {
        return this->y;
    }

    virtual void set_w(geometry_t w) {
        this->w = w;
    }

    virtual geometry_t get_w() const {
        return this->w;
    }

    virtual void set_h(geometry_t h) {
        this->h = h;
    }

    virtual geometry_t get_h() const {
        return this->h;
    }

    virtual void set_key(char k) {
        this->key = k;
    }

    virtual char get_key() const {
        return this->key;
    }

    virtual void set_text(const std::string &t) {
        this->text = t;
    }

    virtual std::string get_text() const {
        return this->text;
    }

    virtual void set_label(const std::string &t) {
        this->label = t;
    }

    virtual std::string get_label() const {
        return this->label;
    }

    virtual void set_properties(const std::string &t) {
        this->properties = t;
    }

    virtual std::string get_properties() const {
        return this->properties;
    }
    virtual void set_type(UI_TYPE t) {
        this->type = t;
    }

    virtual UI_TYPE get_type() const {
        return this->type;
    }

    virtual void set_box(bool b) {
        this->box_value = b;
    }

    virtual bool get_box() const {
        return this->box_value;
    }

    virtual void set_color(int b) {
        this->color = b;
    }

    virtual int get_color() const {
        return this->color;
    }

    virtual void set_x_ratio(wn::Ratio value) {
        this->x_ratio = value;
    }

    virtual void set_y_ratio(wn::Ratio value) {
        this->y_ratio = value;
    }

    virtual void set_w_ratio(wn::Ratio value) {
        this->w_ratio = value;
    }

    virtual void set_h_ratio(wn::Ratio value) {
        this->h_ratio = value;
    }

    virtual wn::Ratio get_x_ratio() {
        return this->x_ratio;
    }

    virtual wn::Ratio get_y_ratio() {
        return this->y_ratio;
    }

    virtual wn::Ratio get_w_ratio() {
        return this->w_ratio;
    }

    virtual wn::Ratio get_h_ratio() {
        return this->h_ratio;
    }

    virtual void set_visible(bool b) {
        this->visible = b;
    }

    virtual bool get_visible() const {
        return this->visible;
    }

    virtual void set_rx(geometry_t rx) {
        this->rx = rx;
    }

    virtual geometry_t get_rx() const {
        return this->rx;
    }

    virtual void set_ry(geometry_t ry) {
        this->ry = ry;
    }

    virtual geometry_t get_ry() const {
        return this->ry;
    }

    virtual void set_rw(geometry_t rw) {
        this->rw = rw;
    }

    virtual geometry_t get_rw() const {
        return this->rw;
    }

    virtual void set_rh(geometry_t rh) {
        this->rh = rh;
    }

    virtual geometry_t get_rh() const {
        return this->rh;
    }

    virtual std::string to_string() {
        std::stringstream ss;
        ss << "Component( id: " << get_id()
           << ", x: "           << get_x()
           << ", y: "           << get_y()
           << ", w: "           << get_w()
           << ", h: "           << get_h()
           << ", type: "        << get_type()
           << ", key: "         << get_key()
           << ", color: "       << get_color()
           << ", box: "         << get_box()
           << ", rx: "          << get_rx()
           << ", ry: "          << get_ry()
           << ", rw: "          << get_rw()
           << ", rh: "          << get_rh()
           << ", text: "        << get_text()
           << ", label: "       << get_label()
           << ")";
        return ss.str();
    }

private:

};

//============================================================================//
//============================================================================//
//============================================================================//

class Field : public Component {
protected:
public:

    Field(int id,
          geometry_t x,
          geometry_t y,
          geometry_t w,
          geometry_t h) :
        Component(id, x, y, w, h) {
    }

    Field(int id,
          geometry_t x,
          geometry_t y,
          geometry_t w,
          geometry_t h,
          char key,
          const std::string &label,
          UI_TYPE type) :
        Component(id, x, y, w, h, key, label, type) {
    }

    ~Field() {
#ifdef LOG_ON_FILE
        wn::__log_file << "Distructor of Field - CALLED\n";
        wn::__log_file.flush();
#endif
    }

private:
};

//============================================================================//
//============================================================================//
//============================================================================//

class Label : public Field {
protected:
public:

    Label(int id,
          geometry_t x,
          geometry_t y,
          geometry_t w,
          geometry_t h) :
        Field(id, x, y, w, h) {
    }

    ~Label() {
#ifdef LOG_ON_FILE
        wn::__log_file << "Distructor of Label - CALLED\n";
        wn::__log_file.flush();
#endif
    }

    /**
     * Specializzo il disegno del componente su terminale.
     */
    bool print_component(bool focus) {

        if (this->window) {

            if (this->get_color() > -1) {
                wattron(this->window, COLOR_PAIR(this->get_color()));
            }

            mvwprintw(this->window, this->get_ry(), this->get_rx(), this->get_label().c_str());

            if (this->get_color() > -1) {
                wattroff(this->window, COLOR_PAIR(this->get_color()));
            }
        }

        return true;
    }

private:
};

//============================================================================//
//============================================================================//
//============================================================================//

class CheckBox : public Field {
protected:
public:

    CheckBox(int id,
             geometry_t x,
             geometry_t y,
             geometry_t w,
             geometry_t h) :
        Field(id, x, y, w, h) {
    }

    ~CheckBox() {
#ifdef LOG_ON_FILE
        wn::__log_file << "Distructor of CheckBox - CALLED\n";
        wn::__log_file.flush();
#endif
    }

    /**
     * Specializzo il disegno del componente su terminale.
     */
    bool print_component(bool focus) {

        bool result = false;

        if (this->window) {

            std::stringstream ss;

            ss << "[";
            ss << (this->get_ck_value() ? "x" : " ");
            ss << "]";
            ss << this->get_label();

            if (!this->get_responsive() && this->get_responsive_color() > -1) {
                wattron(this->window, COLOR_PAIR(this->get_responsive_color()));
            }

            mvwprintw(this->window, this->get_ry(), this->get_rx(), ss.str().c_str());

            if (!this->get_responsive() && this->get_responsive_color() > -1) {
                wattroff(this->window, COLOR_PAIR(this->get_responsive_color()));
            }

            if (focus) {
                result = (OK == set_focus_here());
            }
        }

        return result;
    }

    int set_focus_here() {
        return Component::set_focus_here(rx + 1, ry);
    }

    bool update_component(bool focus) {

        bool result = false;

        if (wn::__current_action == wn::ACTION_TYPE::ENTER) {

            if (this->get_responsive()) {

                this->update_before_mod();

                this->set_ck_value(!this->get_ck_value());

                this->update_after_mod();
            }

            result = print_component(focus);
        }

        return result;
    }

private:
};

//============================================================================//
//============================================================================//
//============================================================================//

class TextField : public Field {
protected:
public:

    TextField(int id,
              geometry_t x,
              geometry_t y,
              geometry_t w,
              geometry_t h) :
        Field(id, x, y, w, h) {
    }

    ~TextField() {
#ifdef LOG_ON_FILE
        wn::__log_file << "Distructor of TextField - CALLED\n";
        wn::__log_file.flush();
#endif
    }

    /**
     * Specializzo il disegno del componente su terminale.
     */
    bool print_component(bool focus) {

        int result = false;

        //__wn_dd(" ");
        //__wn_dd(" - cursor: ", cursor);
        //__wn_dd(" - rw    : ", rw);

        if (this->window) {

            wattron(this->window, (color > -1) ? COLOR_PAIR(color) : A_REVERSE);

            int len = 0;

            std::string vs = this->text;

            len = vs.length();

            // Il testo e' piu' piccolo della largheza del campo
            if (len < rw) {

                __wn_dd("[TextField]: testo piu' piccolo.");

                std::stringstream ss;
                ss << vs;

                for (int i = len; i < rw; ++i) {
                    ss << " ";
                }

                vs = ss.str();

                if (cursor > rw - 1)
                    cursor = rw - 1;

                if (cursor > len)
                    cursor = len;

                if (index > len)
                    index = len;

                if (cursor < 0)
                    cursor = 0;

                if (index < 0)
                    index = 0;

                index = cursor;

                // Devo impostare gli indici per il substr perche'
                // potrebbe al giro successivo superare il bordo destro
                l = 0;
                r = rw;

                //__wn_dd("< CASO TESTO PIU PICCOLO DI RW >");

                if (first_time) {
                    first_time = false;
                }

                mvwprintw(this->window, this->get_ry(), this->get_rx(),
                          empty_value().c_str());
                mvwprintw(this->window, this->get_ry(), this->get_rx(),
                          vs.c_str());

            } else {

                /* Altrimenti se troppo lungo lo scrivo    */
                /* a partire dal primo carattere possibile */
                /* fino al fondo.                          */

                __wn_dd("[TextField]: testo piu' grande.");

                if (first_time) {

                    l = 0;
                    r = rw;

                    vs = vs.substr(l, r);

                    mvwprintw(this->window, this->get_ry(), this->get_rx(),
                              empty_value().c_str());
                    mvwprintw(this->window, this->get_ry(), this->get_rx(),
                              vs.c_str());

                    first_time = false;

                } else {

                    if (cursor >= rw - 1) {

                        __wn_dd("[TextField]: < LIMITE DESTRO SUPERATO OPPURE UGUALE >");

                        if (cursor > rw -1) {
                            cursor = rw - 1;
                        }

                        if (index > len - 1) {
                            index = len - 1;
                        }

                        // Con il + 1 sposto il testo di una cella in piu'
                        // per creare uno spazio bianco in piu'
                        l = (index - (rw - 1)); // + 1; // per spazio in piu'
                        r = rw; // Numero di caratteri massimi

                        // Se ho creato uno spazio bianco in piu' devo anche
                        // incrementare l'index di + 1
                        // index++;

                        //__wn_dd(" - l : ", l);
                        //__wn_dd(" - r : ", r);

                        vs = vs.substr(l, r);

                        //__wn_dd(" - vs: ", vs);

                        mvwprintw(this->window, this->get_ry(), this->get_rx(),
                                  empty_value().c_str());
                        mvwprintw(this->window, this->get_ry(), this->get_rx(),
                                  vs.c_str());

                    } else if (cursor < 0) {

                        __wn_dd("[TextField]: < LIMITE SINISTRO SUPERATO >");

                        cursor = 0;

                        if (index < 0) {
                            index = 0;
                        }

                        l = index;
                        r = rw;

                        //__wn_dd(" - l : ", l);
                        //__wn_dd(" - r : ", r);

                        vs = vs.substr(l, r);

                        //__wn_dd(" - vs: ", vs);

                        mvwprintw(this->window, this->get_ry(), this->get_rx(),
                                  empty_value().c_str());
                        mvwprintw(this->window, this->get_ry(), this->get_rx(),
                                  vs.c_str());

                    } else {

                        __wn_dd("[TextField]: < CASO GENERICO >");

                        //__wn_dd(" - l : ", l);
                        //__wn_dd(" - r : ", r);

                        while (l >= vs.length())
                            l--;

                        vs = vs.substr(l, r);

                        //__wn_dd(" - vs: ", vs);

                        mvwprintw(this->window, this->get_ry(), this->get_rx(),
                                  empty_value().c_str());
                        mvwprintw(this->window, this->get_ry(), this->get_rx(),
                                  vs.c_str());
                    }
                }
            }

            //__wn_dd(" + cursor : ", cursor);
            //__wn_dd(" + index  : ", index);

            wattroff(this->window, (color > -1) ? COLOR_PAIR(color) : A_REVERSE);

            if (focus) {
                result = (OK == set_focus_here());
            } else {
                result = true;
            }
        }

        return result;
    }

    int set_focus_here() {
        return set_focus_here(rx + cursor, ry);
    }

    int set_focus_here(int value_x, int value_y) {

        int result = wmove(window, value_y, value_x);

        if (CURSOR_LIMIT_COLORS) {

            /**
             * Imposta un colore differente per il cursore se e' sui bordi.
             */
            if (cursor == 0 || cursor == rw - 1) {
                printf("\e]12;%s\a", "red");
            } else {
                printf("\e]12;%s\a", "blue");
            }

            fflush(stdout);
        }

        refresh();
        wrefresh(window);

        return result;
    }

    bool update_component(bool focus) {

        bool result = false;

        std::string str = this->get_text();

        __wn_dd("------------------------------------------------------------");
        __wn_dd("------------------------------------------------------------");
        __wn_dd(" - TYPE (before) - str length : ", (int)str.length());
        __wn_dd(" - TYPE (before) - index      : ", index);
        __wn_dd(" - TYPE (before) - cursor     : ", cursor);

        if (wn::__current_action == wn::ACTION_TYPE::USER &&
                __wn_is_accepted_ascii_char(wn::__current_key)) {

            //__wn_dd("<insert text>");

            if (this->get_responsive()) {

                this->update_before_mod();

                // Per versione con spazio in piu' al limite
                //if (index == str.length()) {
                //    str += wn::__current_key;
                //} else {

                str.insert(index, std::string(1, wn::__current_key));

                //}

                this->set_text(str);

                this->update_after_mod();
            }

            index++;

            cursor++;

            result = this->print_component(focus);

        } else if (wn::__current_action == wn::ACTION_TYPE::KLEFT) {

            //__wn_dd("<kleft>");

            index--;

            cursor--;

            result = this->print_component(focus);

        } else if (wn::__current_action == wn::ACTION_TYPE::KRIGHT) {

            //__wn_dd("<kright>");

            if (index < str.length()) {

                index++;

                if (cursor < rw && cursor < str.length()) {
                    cursor++;
                }
            }

            result = this->print_component(focus);

        } else if (wn::__current_action == wn::ACTION_TYPE::CANC) {

            //__wn_dd("<canc>");

            if (this->get_responsive()) {

                this->update_before_mod();

                str.erase(index, 1);

                this->set_text(str);

                this->update_after_mod();
            }

            result = this->print_component(focus);

        } else if (wn::__current_action == wn::ACTION_TYPE::BS) {

            //__wn_dd("<bs>");

            if (index - 1 >= 0) {

                index--;

                if (cursor - 1 >= 0)
                    cursor--;

                if (this->get_responsive()) {

                    this->update_before_mod();

                    str.erase(index, 1);

                    this->set_text(str);

                    this->update_after_mod();
                }
            }

            result = this->print_component(focus);
        }

        __wn_dd(" - TYPE (after) - str length : ", (int)str.length());
        __wn_dd(" - TYPE (after) - index      : ", index);
        __wn_dd(" - TYPE (after) - cursor     : ", cursor);
        __wn_dd("------------------------------------------------------------");
        __wn_dd("------------------------------------------------------------");

        return result;
    }

private:
    unsigned int l = 0;
    unsigned int r = 0;
    int index = 0;
    int cursor = 0;
    bool first_time = true;
};

//============================================================================//
//============================================================================//
//============================================================================//

class Button : public Field {
protected:
public:

    Button(int id,
           geometry_t x,
           geometry_t y,
           geometry_t w,
           geometry_t h,
           char key,
           const std::string &label,
           void(*action)(int, std::string)) :
        Field(id, x, y, w, h, key, label, UI_TYPE::BUTTON_TYPE) {

        this->action = action;

        /**
         * Gestione comune per disegno bottoni.
         */
        button_text =
            __wn_format_button_label(this->get_key(),
                                     this->get_label().c_str());
    }

    ~Button() {
#ifdef LOG_ON_FILE
        wn::__log_file << "Distructor of Button - CALLED\n";
        wn::__log_file.flush();
#endif
    }

    /**
     * Specializzo il disegno del componente su terminale.
     */
    bool print_component(bool focus) {

        __wn_dd("BUTTON - print_component     : ", focus);
        __wn_dd("BUTTON - get_responsive      : ", this->get_responsive());
        __wn_dd("BUTTON - get_responsive_color: ", this->get_responsive_color());

        if (this->window) {

            if (focus) {
                wattron(this->window, A_REVERSE);
            }

            if (!this->get_responsive() && this->get_responsive_color() > -1) {
                wattron(this->window, COLOR_PAIR(this->get_responsive_color()));
            }

            mvwprintw(this->window, this->get_ry(), this->get_rx(), button_text.c_str());

            if (!this->get_responsive() && this->get_responsive_color() > -1) {
                wattroff(this->window, COLOR_PAIR(this->get_responsive_color()));
            }

            if (focus) {
                wattroff(this->window, A_REVERSE);
            }
        }

        return true;
    }

    void focus_lost() {
        print_component(false);
        wrefresh(window);
    }

    int set_focus_here() {

        print_component(true);
        int vx = key > 0 ? rx + 2 : rx;

        int ris = Component::set_focus_here(vx, ry);
        return ris;
    }

    bool update_component(bool focus) {

        if (wn::__current_action == wn::ACTION_TYPE::ENTER ||
                wn::__current_key == this->get_key()) {

            action_on_button();

        } else if (wn::__current_action == wn::ACTION_TYPE::ESC &&
                   wn::__current_key == ESC_KEY_CODE &&
                   this->get_key() == wn::__current_key) {

            action_on_button();
        }

        return print_component(focus);
    }

private:

    void action_on_button() {

        if (this->get_responsive()) {

            this->update_before_mod();

            this->action(this->get_id(), this->get_label());

            this->update_after_mod();
        }
    }

    std::string button_text = "";
    __fp_btn_key_action_t action;
};

//============================================================================//
//============================================================================//
//============================================================================//

class FOCUS {
private:

    int index = -1;
    std::vector<std::shared_ptr<Component>> list;

public:

    static FOCUS& get_instance() {
        static FOCUS instance;
        return instance;
    }

    void add(std::shared_ptr<Component> item) {
        list.push_back(std::move(item));
    }

    int size() {
        return list.size();
    }

    void clear() {
        list.clear();
    }

    void reset_index() {
        index = -1;
    }

    void next() {

        if (list.size() > 0) {

            //__wn_dd("FOCUS NEXT - index:", index);

            if (index >= 0) {
                list.at(index).get()->focus_lost();
            }

            index = ++index % list.size();
        }
    }

    bool exists_next_focus_component() {
        return !list.empty() && index > -1 && index < list.size();
    }

    std::shared_ptr<Component> get_focused_component() {
        return list.at(index);
    }

    bool focus_on_component() {

        bool focused = false;

        if (index < 0 && list.size() > 0) {
            next();
        }

        if (exists_next_focus_component()) {

            curs_set(1);

            focused = (OK == list.at(index).get()->set_focus_here());
        }

        return focused;
    }

    template<class L>
    void for_each(L func) {
        int size = list.size();
        for (int i = 0; i < size; ++i) {
            auto item = list.at(i);
            func(*item.get(), i == index);
        }
    }

private:

    FOCUS() {
    }
    FOCUS(FOCUS const&);
    void operator=(FOCUS const&);

};

//============================================================================//
//============================================================================//
//============================================================================//

typedef   std::shared_ptr<wn::Field>                shafield_t   ;
typedef   std::shared_ptr<std::vector<shafield_t>>  shavecfield_t;

//============================================================================//
//============================================================================//
//============================================================================//

class Window : public Component {
protected:
public:

    Window(int id,
           geometry_t x,
           geometry_t y,
           geometry_t w,
           geometry_t h,
           const std::string &label,
           bool box,
           int color,
           bool visible,
           std::initializer_list<shafield_t> list) :
        Component(id, x, y, w, h, label, box, color, UI_TYPE::WINDOW_TYPE, visible) {

        insert_all(list);
    }

    ~Window() {

#ifdef LOG_ON_FILE
        wn::__log_file << "Distructor of Window - CALLED\n";
        wn::__log_file.flush();
#endif

    }

    void insert_item(const shafield_t &item) {
        if (fields) {
            fields.get()->push_back(item);
        }
    }

    void insert_all(std::initializer_list<shafield_t> f) {

        if (fields) {
            fields.get()->clear();
        }

        fields = std::make_shared<std::vector<shafield_t>> ();

        for (auto &item : f) {
            insert_item(item);
        }
    }

    shavecfield_t &get_items() {
        return fields;
    }

    void remove_all_items() {
        if (fields) {
            fields.get()->clear();
        }
    }

    bool remove_item(const int id_to_remove) {

        bool removed = false;

        if (fields) {
            for (unsigned int i = 0; i < fields->size(); ++i) {

                if (id_to_remove == fields->at(i).get()->get_id()) {
                    fields->erase(fields->begin() + i);
                    removed = true;
                    break;
                }
            }
        }
        return removed;
    }

    void print_components() {
        this->print_components(this->get_rw(), this->get_rw(), this->get_WINDOW());
    }

    /**
     * Draw all sub-components.
     *
     * @param win_w
     * @param win_h
     * @param wcurrent
     */
    void print_components(int win_w, int win_h, WINDOW *wcurrent) {

        shavecfield_t svf            = this->get_items();
        std::vector<shafield_t> *vf  = svf.get();

        if (vf && !vf->empty()) {

            int ix = 0, iy = 0, iw = 0, ih = 0;

            int j = 0;

            int size = vf->size();

            for (; j < size; ++j) {

                shafield_t shf   = vf->at(j);
                wn::Field *field = shf.get();

                ix = field->get_x();
                iy = field->get_y();
                iw = field->get_w();
                ih = field->get_h();

                int before_ix = ix,
                    before_iy = iy,
                    before_iw = iw,
                    before_ih = ih;

                __wn_format_geometry(
                    win_w,
                    win_h,
                    field->get_x_ratio(),
                    field->get_y_ratio(),
                    field->get_w_ratio(),
                    field->get_h_ratio(),
                    ix,
                    iy,
                    iw,
                    ih,
                    0,
                    2);

                __wn_dd("------------------------------------------------------------");
                __wn_dd("{Window.print_components} - FIELD - id :", field->get_id());
                __wn_dd("{Window.print_components} - FIELD - ix :", ix, " (before):", before_ix);
                __wn_dd("{Window.print_components} - FIELD - iy :", iy, " (before):", before_iy);
                __wn_dd("{Window.print_components} - FIELD - iw :", iw, " (before):", before_iw);
                __wn_dd("{Window.print_components} - FIELD - ih :", ih, " (before):", before_ih);
                __wn_dd("------------------------------------------------------------");

                field->set_rx(ix);
                field->set_ry(iy);
                field->set_rw(iw);
                field->set_rh(ih);

                field->set_WINDOW(wcurrent);

                switch (field->get_type()) {

                case wn::UI_TYPE::BUTTON_TYPE:
                case wn::UI_TYPE::CHECKBOX_TYPE:
                case wn::UI_TYPE::TEXT_TYPE:
                {
                    field->print_component(false);

                    wn::FOCUS::get_instance().add(shf);

                    break;
                }
                case wn::UI_TYPE::LABEL_TYPE:
                {
                    field->print_component(false);
                    break;
                }
                }
            }

        } else {
            __wn_dd("<no fields>");
        }
    }

    /**
     * Calling the refresh function on the windows requires to redesign all
     * sub components.
     */
    void repaint() {

        if (fields) {
            print_components(this->get_rw(), this->get_rh(), this->get_WINDOW());
            refresh();
        }

        WINDOW *wcurrent = this->get_WINDOW();

        if (this->get_box()) {
            box(wcurrent, 0, 0);
        }

        if (this->get_label().length() > 0) {

            if (this->get_box()) {
                mvwaddch(wcurrent, 0, 2, ACS_RTEE);
                waddch(wcurrent, ' ');
            }

            waddstr(wcurrent, this->get_label().c_str());

            if (this->get_box()) {
                waddch(wcurrent, ' ');
                waddch(wcurrent, ACS_LTEE);
            }
        }

        if (this->get_color() > -1) {
            wbkgd(wcurrent, A_NORMAL | COLOR_PAIR(this->get_color()));
        }

        wrefresh(wcurrent);
    }

private:
    shavecfield_t fields;
};

//============================================================================//
//============================================================================//
//============================================================================//

typedef   std::shared_ptr<wn::Window>              shawin_t   ;
typedef   std::shared_ptr<std::vector<shawin_t>>   shavecwin_t;
typedef   std::map<std::string, shavecwin_t>       mapshavec_t;

//============================================================================//
//============================================================================//
//============================================================================//

class Container {
public:

    Container(std::string name) : name(name) {
        windows.clear();
    }

    ~Container() {

#ifdef LOG_ON_FILE
        wn::__log_file << "Distructor of Container - CALLED\n";
        wn::__log_file.flush();
#endif
        windows.clear();
    }

    std::string get_name() {
        return this->name;
    }

    Container *ADD_WINDOWS(std::string key, std::initializer_list<shawin_t> wins) {

        shavecwin_t vec = NULL;

        if (!__wn_map_contains(windows, key)) {

            vec = std::make_shared<std::vector < shawin_t >> ();
            windows.insert({key, vec});
        } else {
            vec = windows[key];
        }

        for (auto item : wins) {
            vec.get()->push_back(item);
        }

        return this;
    }

    shavecwin_t &get_list_windows(const std::string &key) {

        if (!__wn_map_contains(windows, key)) {
            fprintf(stderr, ERR_NAME_CFG_NOT_FOUND_LOG "\n");
            exit(EXIT_FAILURE);
        }

        return windows[key];
    }

    Component *get_component(int id) {

        __wn_dd("Looking for component with id: ", id);

        for(std::map<std::string, shavecwin_t>::iterator it = windows.begin();
                it != windows.end(); ++it) {

            //__wn_dd("map key: ", it->first);

            shavecwin_t sv = it->second;
            std::vector<shawin_t> *vw = sv.get();

            for (unsigned int i = 0; i < vw->size(); ++i) {

                //__wn_dd("window: ", vw->at(i).get()->to_string());

                if (id == vw->at(i).get()->get_id()) {
                    return vw->at(i).get();
                }

                shavecfield_t vf = vw->at(i).get()->get_items();

                for (unsigned int j = 0; j < vf->size(); ++j) {

                    //__wn_dd("field: ", vf->at(j).get()->to_string());

                    if (id == vf->at(j).get()->get_id()) {
                        return vf->at(j).get();
                    }
                }
            }
        }

        __wn_dd("key value: ", id);
        __wn_dd("NOT FOUND!");

        return nullptr;
    }

    std::vector<Component*> *get_components_by_type(const char *name,
            std::initializer_list<UI_TYPE> types) {

        __wn_dd("get_components_by_type: ", name);

        auto *result = new std::vector<Component*>();

        shavecwin_t wins = get_list_windows(name);

        std::vector<shawin_t> *vw = wins.get();

        for (unsigned int i = 0; i < vw->size(); ++i) {

            if (__wn_initializer_list_contains(types, vw->at(i).get()->get_type())) {
                result->push_back(vw->at(i).get());
            }

            shavecfield_t vf = vw->at(i).get()->get_items();

            for (unsigned int j = 0; j < vf->size(); ++j) {

                if (__wn_initializer_list_contains(types, vf->at(j).get()->get_type())) {
                    result->push_back(vf->at(j).get());
                }
            }
        }

        return result;
    }

private:
    std::string name = "undefined";
    mapshavec_t windows;
};

//============================================================================//
//============================================================================//
//============================================================================//

Container *global_container;

//============================================================================//
//============================================================================//
//============================================================================//

void init_main_window(bool default_exit_on_err, const char *title);
int get_max_x();
int get_max_y();
void repaint_ui();
void update_ui();
bool readmax_xy();
void init_pair_color(int num, int fore, int bkg);
void init_default_pair_color();
void set_colors(int colors);
void add_action(char key, const char *text_label, void (*pfun)());
void remove_action(char key);
void next_action_paging();
void back_action_paging();
void print_status_msg(const char *message);
void print_status_msg_num(const char *message, const int value);
void create_popup_dialog_panel(int width_perc, int height_perc, int color_id);
void write_msg_row1_popup_dialog_panel(const char *message, wn::ALIGN_TYPE align_text);
void write_msg_row2_popup_dialog_panel(const char *message, wn::ALIGN_TYPE align_text);
void write_msg_row3_popup_dialog_panel(const char *message, wn::ALIGN_TYPE align_text);
void add_button_popup_dialog_panel(char key, const char *label, void (*pf)(int, std::string));
void add_button_ok_popup_dialog_panel(void (*pf)(int, std::string));
void add_button_cancel_popup_dialog_panel(void (*pf)(int, std::string));
void init_popup_dialog_panel();
void show_popup_dialog_panel();
void hide_popup_dialog_panel();
bool is_popup_dialog_panel_showed();
bool is_run_app_activated();
bool request_next_focus();
void load_main_ui_config_name(const char *name);
void load_main_ui_config_data(wn::Container *&config);
void update_status_message();
void print_center();
void print_action_bar();
void print_popup();
void run_app();
void quit_app();
void set_popup_readjust(bool value);
bool is_popup_readjust();
void print_center();
bool update_current_focused_component();
void cursor_zero_no_echo();
Component *get_component(int id);
std::vector<Component*> *get_components_by_type(const char *name, std::initializer_list<UI_TYPE> types);
template<class T> T *get_casted_component(int id);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

};

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

inline wn::Ratio WN_RATIO(geometry_t percentage) {
    return wn::Ratio(percentage, 0, true, wn::ALIGN_TYPE::UNDEFINED);
}

inline wn::Ratio WN_RATIO(geometry_t percentage, geometry_t max) {
    return wn::Ratio(percentage, max, true, wn::ALIGN_TYPE::UNDEFINED);
}

inline wn::Ratio WN_ALIGN_CENTER_DEF() {
    return wn::Ratio(0, 0, true, wn::ALIGN_TYPE::CENTER);
}

inline wn::Ratio WN_ALIGN_LEFT_DEF() {
    return wn::Ratio(0, 0, true, wn::ALIGN_TYPE::LEFT);
}

inline wn::Ratio WN_ALIGN_RIGHT_DEF() {
    return wn::Ratio(0, 0, true, wn::ALIGN_TYPE::RIGHT);
}

inline wn::Ratio WN_ALIGN_TOP_DEF() {
    return wn::Ratio(0, 0, true, wn::ALIGN_TYPE::TOP);
}

inline wn::Ratio WN_ALIGN_BOTTOM_DEF() {
    return wn::Ratio(0, 0, true, wn::ALIGN_TYPE::BOTTOM);
}

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

template<class F = wn::Field, class B = wn::Button>
inline std::shared_ptr<F> WN_BUTTON(
    int id,
    wn::Ratio x,
    wn::Ratio y,
    wn::Ratio w,
    wn::Ratio h,
    char key,
    const std::string &label,
    void(*action)(int, std::string)) {
    return std::make_shared<B>(B(id,
                                 x.value,
                                 y.value,
                                 w.value,
                                 h.value,
                                 key,
                                 label,
                                 action));
}

template<class F = wn::Field, class B = wn::Button>
inline std::shared_ptr<F> WN_BUTTON(
    int id,
    wn::Ratio x,
    wn::Ratio y,
    wn::Ratio w,
    wn::Ratio h,
    const std::string &label,
    void(*action)(int, std::string)) {
    return WN_BUTTON(id, x, y, w, h, 0, label, action);
}

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

template<class F = wn::Field, class T = wn::TextField>
inline std::shared_ptr<F> WN_TEXT(
    int id,
    wn::Ratio x,
    wn::Ratio y,
    wn::Ratio w,
    wn::Ratio h,
    const std::string &text,
    int color) {

    std::shared_ptr<F> field =
        std::make_shared<T>(T(id, x.value, y.value, w.value, h.value));

    field.get()->set_type(wn::UI_TYPE::TEXT_TYPE);
    field.get()->set_text(text);
    field.get()->set_color(color);

    if (x.ratio)
        field.get()->set_x_ratio(x);
    if (y.ratio)
        field.get()->set_y_ratio(y);
    if (w.ratio)
        field.get()->set_w_ratio(w);
    if (h.ratio)
        field.get()->set_h_ratio(h);

    return field;
}

template<class F = wn::Field>
inline std::shared_ptr<F> WN_TEXT(
    int id,
    wn::Ratio x,
    wn::Ratio y,
    wn::Ratio w,
    wn::Ratio h,
    const std::string &text) {

    return WN_TEXT(id, x, y, w, h, text, -1);
}

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

template<class F = wn::Field, class L = wn::Label>
inline std::shared_ptr<F> WN_LABEL(
    int id,
    wn::Ratio x,
    wn::Ratio y,
    wn::Ratio w,
    wn::Ratio h,
    const std::string &text) {

    std::shared_ptr<F> field =
        std::make_shared<L>(L(id, x.value, y.value, w.value, h.value));

    field.get()->set_type(wn::UI_TYPE::LABEL_TYPE);
    field.get()->set_label(text);

    if (x.ratio)
        field.get()->set_x_ratio(x);
    if (y.ratio)
        field.get()->set_y_ratio(y);
    if (w.ratio)
        field.get()->set_w_ratio(w);
    if (h.ratio)
        field.get()->set_h_ratio(h);

    return field;
}

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

template<class F = wn::Field, class CK = wn::CheckBox>
inline std::shared_ptr<F> WN_CHECKBOX(
    int id,
    wn::Ratio x,
    wn::Ratio y,
    wn::Ratio w,
    wn::Ratio h,
    const std::string &text,
    bool value) {

    std::shared_ptr<F> field =
        std::make_shared<CK>(CK(id, x.value, y.value, w.value, h.value));

    field.get()->set_type(wn::UI_TYPE::CHECKBOX_TYPE);
    field.get()->set_label(text);
    field.get()->set_ck_value(value);

    if (x.ratio)
        field.get()->set_x_ratio(x);
    if (y.ratio)
        field.get()->set_y_ratio(y);
    if (w.ratio)
        field.get()->set_w_ratio(w);
    if (h.ratio)
        field.get()->set_h_ratio(h);

    return field;
}

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

template<class W = wn::Window>
inline std::shared_ptr<W> WN_WINDOW(
    int id,
    wn::Ratio x,
    wn::Ratio y,
    wn::Ratio w,
    wn::Ratio h,
    const std::string &label,
    bool box,
    int bg,
    bool visible,
    std::initializer_list<wn::shafield_t> list) {

    std::shared_ptr<W> win =
        std::make_shared<W>(W(id,
                              x.value,
                              y.value,
                              w.value,
                              h.value,
                              label,
                              box,
                              bg,
                              visible,
                              list));

    if (x.ratio)
        win.get()->set_x_ratio(x);
    if (y.ratio)
        win.get()->set_y_ratio(y);
    if (w.ratio)
        win.get()->set_w_ratio(w);
    if (h.ratio)
        win.get()->set_h_ratio(h);

    return win;
}

template<class C = wn::Container>
inline wn::Container *WN_CONTAINER(const std::string name) {
    return new wn::Container(name);
}

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

void wn::init_main_window(bool default_exit_on_err, const char *title) {

#ifdef LOG_ON_FILE
    wn::__log_file.open("out.log", std::ios_base::app);
    wn::__log_file << "NEW MAIN WIN - CALLED\n";
    wn::__log_file.flush();
#endif

    if ((wn::__main_window = initscr()) == NULL && default_exit_on_err) {
        fprintf(stderr, ERR_INIT_MAIN_WINDOW_LOG "\n");
        exit(EXIT_FAILURE);
    }

    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();

    wn::init_default_pair_color();

    wn::__main_title = new char[strlen(title) + 1] {
        0
    };
    strcpy(wn::__main_title, title);

    getmaxyx(wn::__main_window, wn::__main_window_y, wn::__main_window_x);
}

int wn::get_max_x() {
    return wn::__main_window_x;
}

int wn::get_max_y() {
    return wn::__main_window_y;
}

/**
 * Aggiungo voci label per action bar per rispettare l'ordine di inserimento
 * uso un vettore di chiavi.
 * @param key
 * @param text_label
 * @param pfun
 */
void wn::add_action(char key, const char *text_label, void (*pfun)()) {

    wn::__data_key_action data = {
        .key = key,
        .label = new char[strlen(text_label) + 1] {
            0
        },
        .action = pfun
    };
    strcpy(data.label, text_label);

    wn::__map_actions[key] = data;
    wn::__key_actions.push_back(key);
}

void wn::remove_action(char key) {

    // Rimuovo dalla mappa delle azioni
    auto it = wn::__map_actions.find(key);
    if (it != wn::__map_actions.end()) {
        wn::__map_actions.erase(key);
    }

    // Rimuovo anche dal vettore di chiavi
    auto vit = std::find(wn::__key_actions.begin(), wn::__key_actions.end(), key);
    if (vit != wn::__key_actions.end()) {
        wn::__key_actions.erase(vit);
    }
}

void wn::set_popup_readjust(bool value) {
    wn::__popup_readjust = value;
}

bool wn::is_popup_readjust() {
    return wn::__popup_readjust;
}

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

void wn::print_popup() {

    if (wn::__popup_showed.load()) {

        wn::__popup_first_time = wn::__popup_dialog == nullptr;

        if (wn::__popup_width_percentage > 0 && wn::__popup_height_percentage > 0 && wn::__popup_colors > 0) {

            curs_set(0);
            wn::FOCUS::get_instance().clear();

            // NOTA: si gestisce anche il fatto che la popup non possa ridimensionarsi
            int pop_w = wn::__popup_width_val > 0 && !is_popup_readjust() ?
                        wn::__popup_width_val : (wn::__main_window_x * wn::__popup_width_percentage) / 100;

            int pop_h = wn::__popup_height_val > 0 && !is_popup_readjust() ?
                        wn::__popup_height_val : (wn::__main_window_y * wn::__popup_height_percentage) / 100;

            wn::__popup_width_val = pop_w;
            wn::__popup_height_val = pop_h;

            int pop_x = (wn::__main_window_x - pop_w) / 2;
            int pop_y = (wn::__main_window_y - pop_h) / 2;

            // Creo la POPUP DIALOG
            wn::__popup_dialog = newwin(pop_h, pop_w, pop_y, pop_x);

            if (BOX_DIALOG_POPUP)
                box(wn::__popup_dialog, 0, 0);

            wbkgd(wn::__popup_dialog, A_NORMAL | COLOR_PAIR(wn::__popup_colors));

            int i;

            if (pop_w < wn::__main_window_x - 3 && pop_h < wn::__main_window_y - 3) {

                // Attivo l'attributo grafico
                attron(COLOR_PAIR(3));

                for (i = (pop_x + 2); i < (pop_x + pop_w + 1); i++) {
                    move((pop_y + pop_h), i);
                    addch(' ');
                }

                for (i = (pop_y + 1); i < (pop_y + pop_h + 1); i++) {

                    move(i, (pop_x + pop_w));
                    addch(' ');
                    move(i, (pop_x + pop_w + 1));
                    addch(' ');
                }

                // Spegno l'attributo grafico
                attroff(COLOR_PAIR(3));
            }

            // WRITE POPUP MSG
            int row_index = 1;

            if (wn::__popup_msg_text_row1.length() > 0) {
                __wn_print_text_popup(++row_index, wn::__popup_msg_text_row1, wn::__popup_align_text_row1, pop_w);
            }

            if (wn::__popup_msg_text_row2.length() > 0) {
                __wn_print_text_popup(++row_index, wn::__popup_msg_text_row2, wn::__popup_align_text_row2, pop_w);
            }

            if (wn::__popup_msg_text_row3.length() > 0) {
                __wn_print_text_popup(++row_index, wn::__popup_msg_text_row3, wn::__popup_align_text_row3, pop_w);
            }

            // POPUP BUTTONS
            if (wn::__popup_buttons_key.size() > 0) {

                int id = SDEF_ID_POP;
                int y_btn = pop_h - 3;

                int all_label_length = wn::__popup_buttons_text_length + wn::__popup_buttons_key.size();

                if (pop_w > all_label_length) {

                    int x_btn = __wn_compute_alignement(pop_w, all_label_length, wn::ALIGN_TYPE::CENTER, 10);

                    std::list<char>::iterator it = wn::__popup_buttons_key.begin();

                    for (; it != wn::__popup_buttons_key.end(); ++it, --id) {

                        wn::__data_pop_key_action data = wn::__map_popup_actions[*it];

                        int w = strlen(data.label);

                        std::shared_ptr<wn::Component> btn = WN_BUTTON(id, x_btn, y_btn, w, 1, data.key, data.label, data.action);
                        wn::FOCUS::get_instance().add(btn);
                        x_btn += w + 1;
                    }

                    if (wn::__popup_first_time) {
                        wn::FOCUS::get_instance().next();
                    }

                    wn::FOCUS::get_instance().for_each([&](wn::Component &item, bool focus) {

                        if (item.get_label().length() > 0) {

                            if (focus) {
                                wattron(wn::__popup_dialog, A_REVERSE);
                            }

                            mvwprintw(wn::__popup_dialog, item.get_y(), item.get_x(), item.get_label().c_str());

                            if (focus) {
                                wattroff(wn::__popup_dialog, A_REVERSE);
                            }
                        }
                    });
                } else {

                    mvwprintw(wn::__popup_dialog, y_btn,
                              __wn_compute_alignement(pop_w, 5, wn::ALIGN_TYPE::CENTER, 10), "[...]");
                }
            }
            wrefresh(wn::__popup_dialog);

        }
    } // FINE: POPUP DIALOG
}

//****************************************************************************//
//****************************************************************************//
//             _       _                 _   _                 _
//  _ __  _ __(_)_ __ | |_     __ _  ___| |_(_) ___  _ __     | |__   __ _ _ __
// | '_ \| '__| | '_ \| __|   / _` |/ __| __| |/ _ \| '_ \    | '_ \ / _` | '__|
// | |_) | |  | | | | | |_   | (_| | (__| |_| | (_) | | | |   | |_) | (_| | |
// | .__/|_|  |_|_| |_|\__|___\__,_|\___|\__|_|\___/|_| |_|___|_.__/ \__,_|_|
// |_|                   |_____|                         |_____|
//
//****************************************************************************//
//****************************************************************************//

void wn::print_action_bar() {

    __wn_dd("{print_action_bar}");

    if (wn::__map_actions.size() > 0) {

        // Cancello l'ultima riga
        move(wn::__main_window_y - 1, 0);
        clrtoeol();

        //int index_key = 0;
        int start_x = 1;
        int total_actions = wn::__map_actions.size();
        int every_each = 0;

        every_each = (wn::__main_window_x < 20) ? MIN_HIGHLIGHT_ACTION : MAX_HIGHLIGHT_ACTION;

        /* Creo un array con le chiavi della mappa, uso questo per ricavare */
        /* gli elemenenti dalla mappa action.                               */
        //char keys[total_actions];
        //std::map<char, wn::__data_key_action>::iterator it = wn::__map_actions.begin();
        //for (; it != wn::__map_actions.end(); ++it) {
        //    keys[index_key++] = it->second.key;
        //}

        if (wn::__action_paging <= 0) {

            //__wn_dd("{print_action_bar}: paging <= 0");

            while (!wn::__action_stack.empty()) {
                wn::__action_stack.pop();
            }

            wn::__action_last_index = 0;
            wn::__action_stack.push(0);

        } else {

            //__wn_dd("{print_action_bar}: paging > 0");

            /* NOTA: se al primo giro wn::__action_next e' -1 vuol dire che si */
            /*       deve ridisegnare la gui ma NON e' stato premuto alcun     */
            /*       bottone per mandare avanti o indietro l'action bar.       */
            if (wn::__action_next == -1) {
                if (!wn::__action_stack.empty()) {
                    wn::__action_last_index = wn::__action_stack.top();
                }
            } else if (wn::__action_next == 1) {
                wn::__action_last_index++;
                wn::__action_stack.push(wn::__action_last_index);
            } else if (wn::__action_next == 0) {
                if (!wn::__action_stack.empty()) {
                    wn::__action_stack.pop();
                    if (!wn::__action_stack.empty()) {
                        wn::__action_last_index = wn::__action_stack.top();
                    }
                }
            }
            wn::__action_next = -1;
        }

        // INIZIO DISEGNO ACTION BAR
        bool stop_print = false;
        wn::__action_printed = 0;

        for (; wn::__action_last_index < total_actions; ++wn::__action_last_index) {

            //__wn_dd("{print_action_bar} - __action_last_index: ", __action_last_index);

            // Per rispettare l'ordine di inserimento uso il vettore
            wn::__data_key_action current_action = wn::__map_actions[wn::__key_actions[wn::__action_last_index]];

            char *klb = new char[2] {
                0
            };

            sprintf(klb, "%c", current_action.key);
            mvwprintw(wn::__main_window, wn::__main_window_y - 1, start_x, klb);

            start_x++;
            attron(A_REVERSE);
            char *lbl = new char[every_each] {
                0
            };

            snprintf(lbl, sizeof (char) * every_each, "%s", current_action.label);
            int blank_size = every_each - strlen(current_action.label);

            for (int i = 0; i < blank_size - 1; ++i) {
                strcat(lbl, " ");
            }

            mvwprintw(wn::__main_window, wn::__main_window_y - 1, start_x, lbl);
            attroff(A_REVERSE);

            wn::__action_printed++;

            if (wn::__action_printed == MAX_PRINTED_ACTION ||
                    (start_x + (every_each * 2) - 1) > wn::__main_window_x) {

                stop_print = true;
            }

            start_x += every_each;

            delete [] klb;
            delete [] lbl;

            if (stop_print) {
                break;
            }
        }

        //__wn_dd("{print_action_bar} - stop_print: ", stop_print);

        attron(COLOR_PAIR(COLOR_BLACK_ON_CYAN));
        mvwprintw(wn::__main_window, wn::__main_window_y - 1, wn::__main_window_x - 2, "--");
        attroff(COLOR_PAIR(COLOR_BLACK_ON_CYAN));

        wn::go_next = false;
        wn::go_back = false;

        if (wn::__action_paging > 0) {
            attron(COLOR_PAIR(COLOR_BLACK_ON_CYAN));
            mvwprintw(wn::__main_window, wn::__main_window_y - 1, wn::__main_window_x - 2, "<");
            attroff(COLOR_PAIR(COLOR_BLACK_ON_CYAN));
            wn::go_back = true;
        }

        if (stop_print) {
            if (wn::__action_last_index + 1 < total_actions) {
                attron(COLOR_PAIR(COLOR_BLACK_ON_CYAN));
                mvwprintw(wn::__main_window, wn::__main_window_y - 1, wn::__main_window_x - 1, ">");
                attroff(COLOR_PAIR(COLOR_BLACK_ON_CYAN));
                wn::go_next = true;
            }
        }

    } // FINE: ACTION BAR
}

void wn::update_status_message() {

    __wn_dd("{update_status_message}");

    // Cancello la penultima riga
    move(wn::__main_window_y - 2, 0);
    clrtoeol();

    if (wn::__status_message) {

        std::stringstream ss;
        ss << wn::__status_message;
        std::string msg = ss.str();

        if (msg.length() > wn::__main_window_x - 1) {
            msg = msg.substr(0, wn::__main_window_x - 1);
        }

        mvaddstr(wn::__main_window_y - 2, 0, msg.c_str());
    }
}

//****************************************************************************//
//****************************************************************************//
//             _       _                     _
//  _ __  _ __(_)_ __ | |_     ___ ___ _ __ | |_ ___ _ __
// | '_ \| '__| | '_ \| __|   / __/ _ \ '_ \| __/ _ \ '__|
// | |_) | |  | | | | | |_   | (_|  __/ | | | ||  __/ |
// | .__/|_|  |_|_| |_|\__|___\___\___|_| |_|\__\___|_|
// |_|                   |_____|
//
//****************************************************************************//
//****************************************************************************//

void wn::print_center() {

    __wn_dd("{print_center}");

    if (!wn::global_container) {
        fprintf(stderr, ERR_UI_CFG_NOT_FOUND_LOG "\n");
        exit(EXIT_FAILURE);
    }

    if (wn::__center_window) {
        delwin(wn::__center_window);
    }

    // Creo il pannello centrale
    wn::__center_window = newwin(wn::__main_window_y - 2, wn::__main_window_x, 0, 0);
    keypad(wn::__center_window, TRUE);

    wbkgd(wn::__center_window, A_NORMAL | COLOR_PAIR(wn::__main_colors));

    /**
     * Se il titolo non e' stringa vuota allora bordo e label
     */
    if (wn::__main_title && strlen(wn::__main_title) > 0) {

        box(wn::__center_window, 0, 0);

        mvwaddch(wn::__center_window, 0, 2, ACS_RTEE);
        waddch(wn::__center_window, ' ');
        waddstr(wn::__center_window, wn::__main_title);
        waddch(wn::__center_window, ' ');
        waddch(wn::__center_window, ACS_LTEE);
    }

    wrefresh(wn::__center_window);

    wn::shavecwin_t shared_windows =
        wn::global_container->get_list_windows(wn::__current_name_group);

    std::vector<wn::shawin_t> *windows = shared_windows.get();

    int size = windows->size();

    for (int i = 0; i < size; ++i) {

        wn::shawin_t swin = windows->at(i);
        wn::Window *win   = swin.get();

        if (win->get_WINDOW()) {
            win->delete_window();
        }

        /**
         * Inizio calcolo per posizionamento window.
         */
        int win_x = 0, win_y = 0, win_w = 0, win_h = 0;

        // Inizialmente uso i valori settati statici se vi sono, 0 altrimenti.
        win_x = win->get_x();
        win_y = win->get_y();
        win_w = win->get_w();
        win_h = win->get_h();

        __wn_format_geometry(
            wn::__main_window_x,
            wn::__main_window_y,
            win->get_x_ratio(),
            win->get_y_ratio(),
            win->get_w_ratio(),
            win->get_h_ratio(),
            win_x,
            win_y,
            win_w,
            win_h,
            0,
            2);

        __wn_dd("------------------------------------------------------------");
        __wn_dd("WINDOW - id        :", win->get_id());
        __wn_dd("WINDOW - get_label :", win->get_label());
        __wn_dd("WINDOW - win_x     :", win_x);
        __wn_dd("WINDOW - win_y     :", win_y);
        __wn_dd("WINDOW - win_w     :", win_w);
        __wn_dd("WINDOW - win_h     :", win_h);
        __wn_dd("------------------------------------------------------------");

        win->set_rx(win_x);
        win->set_ry(win_y);
        win->set_rw(win_w);
        win->set_rh(win_h);

        WINDOW *wcurrent = newwin(win_h, win_w, win_y, win_x);
        win->set_WINDOW(wcurrent);

        keypad(wcurrent, TRUE);

        if (win->get_visible()) {

            /* NOTA: per creare i sotto componenti uso la window */
            win->repaint();
        }
    }

    /* Se non ci sono elementi focusabili disabilito il cursore */
    if (wn::FOCUS::get_instance().size() == 0) {
        curs_set(0);
    }
}

/**
 * Return true if update x and y max window value.
 * @return
 */
bool wn::readmax_xy() {

    __wn_dd("{readmax_xy}");

    getmaxyx(wn::__main_window, wn::__main_window_y, wn::__main_window_x);

    __wn_dd("DIMENSION - wn::__main_window_y: ", wn::__main_window_y);
    __wn_dd("DIMENSION - wn::__main_window_x: ", wn::__main_window_x);

    return (wn::__main_window_x > MIN_WIDTH_SIZE_FRAME &&
            wn::__main_window_y > MIN_HEIGHT_SIZE_FRAME);
}

/**
 * Force redraw all frame.
 * Note: refresh need call print_component before for take an effect.
 */
void wn::repaint_ui() {

    std::lock_guard<std::mutex> guard(__g_mutex);

    __wn_dd("{repaint_ui}");

    if (readmax_xy()) {
        refresh();
        print_center();
        update_status_message();
        print_action_bar();
    }
}

bool wn::update_current_focused_component() {

    bool result = false;

    if (wn::FOCUS::get_instance().exists_next_focus_component()) {

        std::shared_ptr<Component> sc =
            wn::FOCUS::get_instance().get_focused_component();

        wn::Component *field = sc.get();

        result = field->update_component(true);

    } else {

        __wn_dd("FOCUS: no next component.");
    }

    return result;
}

void wn::cursor_zero_no_echo() {
    curs_set(0);
    noecho();
}

/**
 * Return a pointer of type wn::Component by the id configuration value.
 * @param id
 * @return
 */
wn::Component *wn::get_component(int id) {

    if (!wn::global_container) {
        fprintf(stderr, ERR_UI_CFG_NOT_FOUND_LOG "\n");
        exit(EXIT_FAILURE);
    }

    return wn::global_container->get_component(id);
}

/**
 * Return a pointer of std::vector<wn::Component*> with all object by types of
 * data configuration name.
 * @param name
 * @param types
 * @return
 */
std::vector<wn::Component*> *wn::get_components_by_type(const char *name,
        std::initializer_list<UI_TYPE> types) {

    if (!wn::global_container) {
        fprintf(stderr, ERR_UI_CFG_NOT_FOUND_LOG "\n");
        exit(EXIT_FAILURE);
    }

    return wn::global_container->get_components_by_type(name, types);
}

/**
 * Same as 'wn::get_component(id)' but cast the result by type.
 * @param id
 * @return
 */
template<class T>
T *wn::get_casted_component(int id) {

    T *result = nullptr;
    wn::Component *comp = wn::get_component(id);

    if (comp) {
        result = static_cast<T*> (comp);
    }

    return result;
}

//****************************************************************************//
//****************************************************************************//
//                  _       _                _
//  _   _ _ __   __| | __ _| |_ ___    _   _(_)
// | | | | '_ \ / _` |/ _` | __/ _ \  | | | | |
// | |_| | |_) | (_| | (_| | ||  __/  | |_| | |
//  \__,_| .__/ \__,_|\__,_|\__\___|___\__,_|_|
//       |_|                      |_____|
//
//****************************************************************************//
//****************************************************************************//

void wn::update_ui() {

    std::lock_guard<std::mutex> guard(__g_mutex);

    if (wn::__main_window) {

        if (readmax_xy()) {

            print_popup();

            if (!wn::__popup_showed.load()) {

                wn::FOCUS::get_instance().clear();

                switch (wn::__current_action) {
                case wn::ACTION_TYPE::UPDATE:
                case wn::ACTION_TYPE::FOCUS:
                case wn::ACTION_TYPE::USER:
                {

                    refresh();

                    update_status_message();

                    print_action_bar();

                    print_center();

                    break;
                }
                case wn::ACTION_TYPE::BACK:
                case wn::ACTION_TYPE::NEXT:
                {
                    print_action_bar();
                    break;
                }
                default: {
                }
                }

                wn::FOCUS::get_instance().focus_on_component();
            }
        }
    }
}

//****************************************************************************//
//****************************************************************************//

void wn::next_action_paging() {
    if (!wn::__popup_showed.load()) {
        if (wn::go_next) {
            wn::__action_next = 1;
            wn::__action_paging++;
        }
    }
}

//****************************************************************************//
//****************************************************************************//

void wn::back_action_paging() {
    if (!wn::__popup_showed.load()) {
        if (wn::go_back) {
            wn::__action_next = 0;
            if (wn::__action_paging > 0) {
                wn::__action_paging--;
            }
        }
    }
}

//****************************************************************************//
//****************************************************************************//

bool wn::request_next_focus() {

    bool result = false;

    wn::FOCUS::get_instance().next();

    if(!wn::__popup_showed.load()) {
        result = wn::FOCUS::get_instance().focus_on_component();
    }

    return result;
}

//****************************************************************************//
//****************************************************************************//

void wn::print_status_msg(const char *message) {

    wn::__status_message = new char[strlen(message) + 1] {
        0
    };
    strcpy(wn::__status_message, message);
}

//****************************************************************************//
//****************************************************************************//

void wn::print_status_msg_num(const char *message, const int value) {

    wn::__status_message = new char[strlen(message) + 5] {
        0
    };
    sprintf(wn::__status_message, "%s%d", message, value);
}

//****************************************************************************//
//****************************************************************************//

void wn::init_pair_color(int num, int fore, int bkg) {

    init_pair(num, fore, bkg);
}

//****************************************************************************//
//****************************************************************************//

void wn::init_default_pair_color() {

    init_pair_color (COLOR_WHITE_ON_BLUE,    COLOR_WHITE,    COLOR_BLUE);
    init_pair_color (COLOR_BLACK_ON_CYAN,    COLOR_BLACK,    COLOR_CYAN);
    init_pair_color (COLOR_WHITE_ON_BLACK,   COLOR_WHITE,    COLOR_BLACK);
    init_pair_color (COLOR_YELLOW_ON_BLACK,  COLOR_YELLOW,   COLOR_BLACK);
    init_pair_color (COLOR_YELLOW_ON_BLUE,   COLOR_YELLOW,   COLOR_BLUE);
    init_pair_color (COLOR_CYAN_ON_MAGENTA,  COLOR_CYAN,     COLOR_MAGENTA);
    init_pair_color (COLOR_WHITE_ON_MAGENTA, COLOR_WHITE,    COLOR_MAGENTA);
    init_pair_color (COLOR_WHITE_ON_RED,     COLOR_WHITE,    COLOR_RED);
    init_pair_color (COLOR_WHITE_ON_GREEN,   COLOR_WHITE,    COLOR_GREEN);
    init_pair_color (COLOR_BLACK_ON_GREEN,   COLOR_BLACK,    COLOR_GREEN);
    init_pair_color (COLOR_BLACK_ON_BLUE,    COLOR_BLACK,    COLOR_BLUE);
    init_pair_color (COLOR_RED_ON_BLUE,      COLOR_RED,      COLOR_BLUE);
    init_pair_color (COLOR_CYAN_ON_BLUE,     COLOR_CYAN,     COLOR_BLUE);
    init_pair_color (COLOR_MAGENTA_ON_BLUE,  COLOR_MAGENTA,  COLOR_BLUE);
}

//****************************************************************************//
//****************************************************************************//

void wn::set_colors(int colors) {
    wn::__main_colors = colors;
}

//****************************************************************************//
//****************************************************************************//

void wn::create_popup_dialog_panel(int width_perc, int height_perc, int color_id) {

    __wn_dd("{create_popup_dialog_panel}");

    wn::__popup_width_percentage = width_perc;
    wn::__popup_height_percentage = height_perc;
    wn::__popup_colors = color_id;
}

//****************************************************************************//
//****************************************************************************//

void wn::write_msg_row1_popup_dialog_panel(const char *message,
        wn::ALIGN_TYPE align_text = wn::ALIGN_TYPE::CENTER) {
    __wn_set_msg_rows_popup(message, align_text,
                            wn::__popup_msg_text_row1, wn::__popup_align_text_row1);
}

//****************************************************************************//
//****************************************************************************//

void wn::write_msg_row2_popup_dialog_panel(const char *message,
        wn::ALIGN_TYPE align_text = wn::ALIGN_TYPE::CENTER) {
    __wn_set_msg_rows_popup(message, align_text,
                            wn::__popup_msg_text_row2, wn::__popup_align_text_row2);
}

//****************************************************************************//
//****************************************************************************//

void wn::write_msg_row3_popup_dialog_panel(const char *message,
        wn::ALIGN_TYPE align_text = wn::ALIGN_TYPE::CENTER) {
    __wn_set_msg_rows_popup(message, align_text,
                            wn::__popup_msg_text_row3, wn::__popup_align_text_row3);
}

//****************************************************************************//
//****************************************************************************//

void wn::add_button_popup_dialog_panel(char key_val, const char *label_val,
                                       void (*pf)(int, std::string)) {
    __wn_put_action_popup_dialog(key_val, &label_val, &pf);
}

//****************************************************************************//
//****************************************************************************//

void wn::add_button_ok_popup_dialog_panel(void (*pf)(int, std::string)) {
    add_button_popup_dialog_panel(ENTER_KEY_CODE, ENTER_TEXT_LABEL, pf);
}

//****************************************************************************//
//****************************************************************************//

void wn::add_button_cancel_popup_dialog_panel(void (*pf)(int, std::string)) {
    add_button_popup_dialog_panel(ESC_KEY_CODE, CANCEL_TEXT_LABEL, pf);
}

//****************************************************************************//
//****************************************************************************//

void wn::show_popup_dialog_panel() {

    if (!wn::__popup_showed.load()) {

        __wn_dd("{show_popup_dialog_panel}");

        wn::__popup_showed = true;
    }
}

//****************************************************************************//
//****************************************************************************//

bool wn::is_popup_dialog_panel_showed() {
    return wn::__popup_showed.load();
}

bool wn::is_run_app_activated() {
    return wn::__run_app_activated.load();
}

//****************************************************************************//
//****************************************************************************//

void wn::hide_popup_dialog_panel() {
    wn::__popup_buttons_text_length = 0;
    wn::__popup_showed = false;
    wn::__popup_first_time = true;
    wn::__popup_dialog = nullptr;
    wn::FOCUS::get_instance().reset_index();
}

//****************************************************************************//
//****************************************************************************//

void wn::init_popup_dialog_panel() {

    hide_popup_dialog_panel();

    wn::__map_popup_actions.clear();
    wn::__popup_buttons_key.clear();
    wn::__popup_msg_text_row1 = "";
    wn::__popup_msg_text_row2 = "";
    wn::__popup_msg_text_row3 = "";
}

//****************************************************************************//
//****************************************************************************//

void wn::load_main_ui_config_name(const char *name) {

    std::stringstream ss;
    ss << name;
    wn::__current_name_group = ss.str();
    wn::FOCUS::get_instance().reset_index();
}

//****************************************************************************//
//****************************************************************************//

void wn::load_main_ui_config_data(wn::Container *&config) {
    wn::global_container = config;
}

//****************************************************************************//
//****************************************************************************//

void wn::run_app() {

    if (!wn::__main_window)
        return;

    update_ui();

    wn::__run_app_activated = true;

    while (wn::__run_app_activated.load()) {

        bool need_update = true;

        wn::__current_key = 0;

        timeout(-1);

        wn::__current_key = getch();

        //__wn_dd(" ");
        //__wn_dd("########################################");
        //__wn_dd("#");
        //__wn_dd("# wn::__current_key: ", wn::__current_key);
        //__wn_dd("#");
        //__wn_dd("########################################");
        //__wn_dd(" ");

        switch (wn::__current_key) {

        // ------------------------------------------------------------------ //
        // ------------------------------------------------------------------ //
        // ------------------------------------------------------------------ //

        case KEY_LEFT:
        {
            __wn_dd("<KEY_LEFT>");
            wn::__current_action = wn::ACTION_TYPE::KLEFT;
            need_update = !wn::update_current_focused_component();
            break;
        }
        case KEY_RIGHT:
        {
            __wn_dd("<KEY_RIGHT>");
            wn::__current_action = wn::ACTION_TYPE::KRIGHT;
            need_update = !wn::update_current_focused_component();
            break;
        }
        case RESIZE_CODE:
        {
            __wn_dd("<RESIZE>");
            wn::__current_action = wn::ACTION_TYPE::UPDATE;
            repaint_ui();
            break;
        }
        case TAB_KEY_CODE:
        {
            __wn_dd("<TAB>");
            wn::__current_action = wn::ACTION_TYPE::FOCUS;
            need_update = !request_next_focus();
            break;
        }
        case NEXT_ACTION_KEY_CODE:
        {
            __wn_dd("<NEXT_ACTION>");
            curs_set(0);
            wn::__current_action = wn::ACTION_TYPE::NEXT;
            next_action_paging();
            break;
        }
        case BACK_ACTION_KEY_CODE:
        {
            __wn_dd("<BACK_ACTION>");
            curs_set(0);
            wn::__current_action = wn::ACTION_TYPE::BACK;
            back_action_paging();
            break;
        }
        case BS_KEY_CODE:
        case BS_EX_KEY_CODE:
        {
            __wn_dd("<BS>");
            wn::__current_action = wn::ACTION_TYPE::BS;
            need_update = !wn::update_current_focused_component();
            break;
        }
        case CANC_KEY_CODE:
        case CANC_EX_KEY_CODE:
        {
            __wn_dd("<CANC>");
            wn::__current_action = wn::ACTION_TYPE::CANC;
            need_update = !wn::update_current_focused_component();
            break;
        }
        case ENTER_KEY_CODE:
        case ENTER_EX_KEY_CODE:
        {
            __wn_dd("<ENTER>");
            wn::__current_action = wn::ACTION_TYPE::ENTER;
            need_update = !wn::update_current_focused_component();
            break;
        }
        case ESC_KEY_CODE:
        {
            __wn_dd("<ESC>");
            wn::__current_action = wn::ACTION_TYPE::ESC;
            need_update = !wn::update_current_focused_component();
            break;
        }
        default:
        {
            __wn_dd("<USER>");

            wn::__current_action = wn::ACTION_TYPE::USER;

            if (__wn_map_contains(wn::__map_actions, (char) wn::__current_key)) {

                wn::__map_actions[(char) wn::__current_key].action();

            } else {

                need_update = !wn::update_current_focused_component();
            }

            break;
        }

            // ------------------------------------------------------------------ //
            // ------------------------------------------------------------------ //
            // ------------------------------------------------------------------ //

        }

        __wn_dd("need_update: ", need_update);
        if (need_update) {
            update_ui();
        }
    }

    wn::__run_app_activated = false;

    delwin(wn::__main_window);
    endwin();
    refresh();
}

void wn::quit_app() {

    wn::__run_app_activated = false;

    if (wn::__main_window)
        delwin(wn::__main_window);

    endwin();
    refresh();
}

#endif /* WRAP_NCURSES_H */

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////