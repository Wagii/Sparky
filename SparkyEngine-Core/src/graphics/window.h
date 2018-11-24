#pragma once

#include <GLFW/glfw3.h>

namespace sparky {
	namespace graphics {
		class Window
		{
		private:
			GLFWwindow* _window;
			int _width, _height;
			bool _closed;
			const char *_name;

		public:
			Window(const char* name, int width, int height);
			~Window();
			void update();
			void clear() const;
			bool closed() const;
			
			inline int getWidth() const { return _width; }
			inline int getHeight() const { return _height; }

		private:
			bool init();
		};
	}
}