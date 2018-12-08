#pragma once

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

		struct Window
		{
			int x, y, width, height;
			const char* title;
			// Dynamic array of entities, etc ...
		};

} }