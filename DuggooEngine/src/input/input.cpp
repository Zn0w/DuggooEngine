#include "input.h"


namespace dg { namespace input {

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //if (key == GLFW_KEY_E && action == GLFW_PRESS)
      //  activate_airship();
}

void Input::setWindow(GLFWwindow* handle)
{
	window = handle;

	glfwSetKeyCallback(window, key_callback);
}

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

struct Key
{
	int keycode;
	bool active;
};

bool Input::isKeyTyped(int keycode)
{
	static Key last_key;
	if (!isKeyPressed(keycode) && last_key.keycode == keycode && last_key.active)
	{
		last_key.active = false;
		last_key.keycode = keycode;

		return true;
	}
	else
	{
		last_key.active = isKeyPressed(keycode);
		last_key.keycode = keycode;

		return false;
	}
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