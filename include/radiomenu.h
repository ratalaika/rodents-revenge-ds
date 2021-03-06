#ifndef _radiomenu_h
#define _radiomenu_h

#include "canvas.h"
#include "font.h"
#include "menu.h"

const s8 RADIOBUTTON_NONE_SELECTED = -1;

const u8 RADIOMENU_BUTTON_WIDTHS = SCREEN_WIDTH - 64;
const u8 RADIOMENU_BUTTON_HEIGHTS = 24;

class RadioMenu : public Menu {
	public:
		// Constructors
		RadioMenu(Canvas *the_canvas, Font *the_font, Color background);
		~RadioMenu();

		// Accessors
		void set_selected_button(s8 new_selected_button);
		void set_selected_value(s32 value);

		// Methods
		void add_back_button(const char *button_text);
		void add_radio_button(const char *button_text, s32 value);
		s32 select();

	private:
		s8 selected_button;
		s8 back_button;

		s32 values[MAX_BUTTONS];
};

#endif

