#pragma once

#include <windows.h>

// TODO : delete this line
#include <tchar.h>		// for _T macro

#include "window.h"

#include <stdio.h>

Duggoo::graphics::Window* window_data;

// TODO : temporary solution
static bool running;

// A local function for handling WM_SIZE
static void resizeDIBSection(int width, int height)
{
	CreateDIBSection();
}

static void updateWindow(HDC device_context, int x, int y, int width, int height)
{
	StretchDIBits(device_context, x, y, width, height, x, y, width, height, DIB_RGB_COLORS, );
}

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
			RECT client_rect;
			GetClientRect(window, &client_rect);

			int width = client_rect.right - client_rect.left;
			int height = client_rect.top - client_rect.bottom;

			resizeDIBSection(width, height);
		}break;

		case WM_DESTROY :
		{
			// TODO : handle error (recreate window on the go)
			running = false;
		}break;

		case WM_CLOSE :
		{
			// TODO : prompt user if they want to exit
			running = false;
			window_data->opened = false;
			printf("WM_CLOSE\n");
		}break;

		case WM_ACTIVATEAPP:
		{
			OutputDebugStringA("WM_ACTIVATEAPP\n");
			printf("WM_ACTIVATEAPP\n");
		}break;

		case WM_PAINT :
		{
			// TODO : handle event with event system and change window_data or use windows's default handling (with paint struct)
			PAINTSTRUCT paint;
			HDC device_context = BeginPaint(window, &paint);
			
			int x = paint.rcPaint.left;
			int y = paint.rcPaint.top;
			int width = paint.rcPaint.right - paint.rcPaint.left;
			int height = paint.rcPaint.bottom - paint.rcPaint.top;
			updateWindow(device_context, x, y, width, height);
			
			EndPaint(window, &paint);
		}break;

		default:
		{
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
		HWND window_handle = CreateWindowExA(
			0,
			window_class.lpszClassName,
			window_data->title,
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
			running = true;
			
			while (running)
			{
				MSG message;
				BOOL message_result = GetMessage(&message, 0, 0, 0);
				if (message_result > 0)
				{
					TranslateMessage(&message);
					DispatchMessageA(&message);
				}
				else
				{
					break;
				}
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
		window_data->opened = true;
		WinMain(0, 0, 0, 0);
	}

} }