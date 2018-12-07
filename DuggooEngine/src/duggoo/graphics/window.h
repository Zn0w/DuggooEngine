#pragma once

#include <windows.h>

namespace Duggoo { namespace graphics {
		/*struct _WNDCLASS
		{
			UINT style;
			WNDPROC lpfnWndProc;
			int cbClsExtra;
			int cbWndExtra;
			HANDLE hInstance;
			HICON hIcon;
			HCURSOR hCursor;
			HBRUSH hbrBackground;
			LPCTSTR lpszMenuName;
			LPCTSTR lpszClassName;
		};*/

		class Window
		{
		
		private:
			WNDCLASS window_class = {}; // initilize every element of window class to zero

		public:
			Window(int w, int h, const char* t);

		};

} }