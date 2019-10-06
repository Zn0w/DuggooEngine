#include "input.h"


namespace dg { namespace input {

bool Input::isKeyPressed(int keycode)
{
	int state = glfwGetKey(window, keycode);
	return state == GLFW_PRESS;
}

bool Input::isKeyReleased(int keycode)
{
	int state = glfwGetKey(window, keycode);
	return state == GLFW_RELEASE;
}

// NOTE: possibly the return value of this function will be a vertex of x and y in the future
void Input::getMousePosition(int* x, int* y)
{
	// NOTE: workaround for converting double pointers to int pointers (temporary solution)
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	int sx, sy;
	sx = xpos;
	sy = ypos;

	*x = sx;
	*y = sy;
}

bool Input::isMouseButtonPressed(int mouseButtonCode)
{
	int state = glfwGetMouseButton(window, mouseButtonCode);
	return state == GLFW_PRESS;
}

} }