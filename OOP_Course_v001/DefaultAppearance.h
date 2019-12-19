#pragma once
#include "Appearance.h"

namespace ATable {
	class DefaultAppearance : public Appearance {
	public:
		DefaultAppearance() {
			this->left_top_corner = 218;
			this->right_top_corner = 191;
			this->left_bottom_corner = 192;
			this->right_bottom_corner = 217;
			this->top_separator = 194;
			this->bottom_separator = 193;
			this->left_separator = 195;
			this->right_separator = 180;
			this->center_separator = 197;
			this->vertical_line = 179;
			this->horizontal_line = 196;
		}
	};
}
