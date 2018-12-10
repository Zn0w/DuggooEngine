#pragma once

#include <windows.h>
#include <tchar.h>		// for _T macro

#include "window.h"

#include <stdio.h>

Duggoo::graphics::Window* window_data;

LRESULT CALLBACK MainWindowProc(
	HWND   window,
	UINT   message,
	WPARAM wParam,
	LPARAM lParam
)
{
	LRESULT result;
	
	switch (message)
	{
		case WM_SIZE :
		{
			OutputDebugStringA("WM_SIZE\n");
			printf("WM_SIZE\n");
		}break;

		case WM_DESTROY :
		{
			OutputDebugStringA("WM_DESTROY\n");
			printf("WM_DESTROY\n");
		}break;

		case WM_CLOSE :
		{

		}break;

		case WM_ACTIVATEAPP:
		{
			OutputDebugStringA("WM_ACTIVATEAPP\n");
			printf("WM_ACTIVATEAPP\n");
		}break;

		case WM_PAINT :
		{
			PAINTSTRUCT paint;
			HDC device_context = BeginPaint(window, &paint);
			static DWORD operation = WHITENESS;
			PatBlt(device_context, window_data->x, window_data->y, window_data->width, window_data->height, operation);
			
			if (operation == WHITENESS)
				operation = BLACKNESS;
			else
				operation = WHITENESS;

			EndPaint(window, &paint);
		}break;

		default:
		{
			OutputDebugStringA("default\n");
			printf("default\n");
			result = DefWindowProcA(window, message, wParam, lParam);
		}break;

	}

	return result;
}

int CALLBACK WinMain(
	HINSTANCE instance,
	HINSTANCE prev_instance,
	LPSTR     cmd,
	int       cmd_show
)
{
	// suffix A in WNDCLASS, RegisterClass() and CreateWindowExA - means to treat the const char* data as ansi code
	
	WNDCLASSA window_class = {}; // initilize every element of window class to zero
	window_class.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	window_class.lpfnWndProc = MainWindowProc;
	window_class.hInstance = instance;
	window_class.lpszClassName = "DuggooWindowClass";

	if (RegisterClassA(&window_class))
	{
		const char* title = window_data->title;
		
		HWND window_handle = CreateWindowExA(
			0,
			window_class.lpszClassName,
			title,
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			window_data->x,
			window_data->y,
			window_data->width,
			window_data->height,
			0,
			0,
			instance,
			0
		);

		if (window_handle)
		{
			MSG message;
			while (GetMessage(&message, 0, 0, 0))
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
		}
		else
		{
			// handle if fails
		}
	}
	else
	{
		// Handle if fails
	}
}

namespace Duggoo { namespace graphics {
	
	void initGraphics(Window* w)
	{
		window_data = w;
		WinMain(0, 0, 0, 0);
	}

} }