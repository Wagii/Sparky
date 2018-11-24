#include "window.h"
#include <iostream>

namespace sparky {
	namespace graphics {
		void windowResize(GLFWwindow *window, int width, int height);

		Window::Window(const char *name, int width, int height) {
			this->_name = name;
			this->_width = width;
			this->_height = height;
			if (!init())
				glfwTerminate();
		}

		Window::~Window() {
			glfwTerminate();
		}

		bool Window::init() {
			if (!glfwInit()) {
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}

			this->_window = glfwCreateWindow(this->_width, this->_height, this->_name, NULL, NULL);
			if (!this->_name) {
				glfwTerminate();
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(this->_window);
			glfwSetWindowSizeCallback(this->_window, windowResize);
			return true;
		}

		void Window::update()  {
			glfwPollEvents();
			glfwSwapBuffers(this->_window);
		}

		bool Window::closed() const {
			return glfwWindowShouldClose(this->_window) == 1;
		}

		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void windowResize(GLFWwindow *window, int width, int height) {
			glViewport(0, 0, width, height);
		}
	}
}