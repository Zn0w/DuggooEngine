#pragma once

#include <windows.h>

#include "window.h"

#include <stdio.h>

Duggoo::graphics::Window* window;

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

		default:
		{
			OutputDebugStringA("default\n");
			printf("default\n");
			result = DefWindowProc(window, message, wParam, lParam);
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
	WNDCLASS window_class = {}; // initilize every element of window class to zero
	window_class.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	window_class.lpfnWndProc = MainWindowProc;
	window_class.hInstance = instance;
	window_class.lpszClassName = (LPCWSTR) "DuggooWindowClass";

	if (RegisterClass(&window_class))
	{
		HWND window_handle = CreateWindowEx(
			0, 
			window_class.lpszClassName, 
			(LPCWSTR) window->title,
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			window->x,
			window->y,
			window->width,
			window->height,
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
		window = w;
		WinMain(0, 0, 0, 0);
	}

} }