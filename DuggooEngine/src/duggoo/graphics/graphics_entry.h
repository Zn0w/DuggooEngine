#pragma once

#include <windows.h>

// TODO : delete this line
#include <tchar.h>		// for _T macro

#include "window.h"

#include <stdio.h>

Duggoo::graphics::Window* window_data;

// TODO : temporary solution
static bool running;

// TODO	: make those variables local to the translation unit
static BITMAPINFO bitmap_info;
static void* bitmap_memory;		// the memory that is being drawn to from custom render
static HBITMAP bitmap_handle;
static HDC bitmap_device_context;

// A local function for handling WM_SIZE
static void resizeDIBSection(int width, int height)
{	
	// free the DIBSection after each creation
	if (bitmap_handle)
	{
		DeleteObject(bitmap_handle);
	}
	
	if (!bitmap_device_context)
	{
		bitmap_device_context = CreateCompatibleDC(0);		// if the function argument is NULL (0), the function creates a memory DC compatible withthe application's current screen.

	}

	bitmap_info.bmiHeader.biSize = sizeof(bitmap_info.bmiHeader);
	bitmap_info.bmiHeader.biWidth = width;
	bitmap_info.bmiHeader.biHeight = height;
	bitmap_info.bmiHeader.biPlanes = 1;				// This value must be set to 1 (says msdn)
	bitmap_info.bmiHeader.biBitCount = 32;			// 8 for red, 8 for green, 8 for blue and 8 for the future (need at leas 24)
	bitmap_info.bmiHeader.biCompression = BI_RGB;	// Uncompressed format
	bitmap_info.bmiHeader.biSizeImage = 0;			// this can be set to 0 for BI_RGB bitmaps
	bitmap_info.bmiHeader.biXPelsPerMeter = 0;
	bitmap_info.bmiHeader.biYPelsPerMeter = 0;
	bitmap_info.bmiHeader.biClrUsed = 0;			// Packed bitmaps require that the biClrUsed member must be either zero or the actual size of the color table.
	bitmap_info.bmiHeader.biClrImportant = 0;		// The number of color indexes that are required for displaying the bitmap.If this value is zero, all colors are required.
	
	bitmap_handle = CreateDIBSection(bitmap_device_context, &bitmap_info, DIB_RGB_COLORS, &bitmap_memory, 0, 0);
}

static void updateWindow(HDC device_context, int x, int y, int width, int height)
{
	StretchDIBits(
		device_context, 
		x, y, width, height, 
		x, y, width, height, 
		bitmap_memory, 
		&bitmap_info, 
		DIB_RGB_COLORS, 
		SRCCOPY
	);
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