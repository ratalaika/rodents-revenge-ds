#ifndef _rrkeyboard_h
#define _rrkeyboard_h

#include "color.h"
#include "canvas.h"
#include "font.h"
#include "menu.h"

enum KeyboardStatus {
	KEYBOARD_OK,
	KEYBOARD_FILE_NOT_FOUND
};

struct KeyboardColors {
	Color line;
	Color key_background;
	Color text;
	Color background;
	Color highlight_key_background;
	Color highlight_text;
};

// This control character represents a new row of keys on the keyboard.
const char KEYBOARD_NEW_ROW = 5;

// This gets passed to the print_key() function.
const bool KEY_HIGHLIGHTED = true;
const bool KEY_UNHIGHLIGHTED = false;

class RRKeyboard {
	public:
		// Constructors
		RRKeyboard(const char *filename, Canvas *the_canvas, Font *the_font, u8 the_key_width, u8 space_bar_width);
		~RRKeyboard();

		// Returns key that is currently pressed, and highlights/unhighlights it
		char key_pressed(touchPosition stylus);

		// Load keyboard layout from file
		KeyboardStatus load_keyboard(const char *filename);

		// Screen output
		void print_key(char key, u16 x, u16 y, bool highlighted=false) const;
		void draw() const;

		// Accessors
		void set_colors(KeyboardColors new_colors) { colors = new_colors; }
		u8 get_status() const { return status; }
		void set_canvas(Canvas *new_canvas) { canvas = new_canvas; }
		void set_shift(bool new_shift) { shift = new_shift; }
		bool get_shift() const { return shift; }

	private:
		Canvas *canvas;
		Font *font;
		char keyboard[2][255];
		u8 key_width;
		KeyboardStatus status;
		u16 keyboard_x;
		u16 keyboard_y;
		u8 width_of_space_bar;
		char highlighted_key;
		KeyboardColors colors;
		bool shift;

		u32 calculate_keyboard_width();
		u32 calculate_keyboard_height();
};

#endif

