#include <iostream>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xfixes.h>

#include <chrono>
#include <thread>

Display* display = nullptr;

void hideCursor(){
	XFixesHideCursor(display, DefaultRootWindow(display));
	XFlush(display);
	std::cout << "Hide cursor" << std::endl;
}

void showCursor(){
	XFixesShowCursor(display, DefaultRootWindow(display));
	XFlush(display);
	std::cout << "Show cursor" << std::endl;
}

static void on_exit_hook(void) {

	showCursor();

	if (display != NULL)
		XCloseDisplay(display);
}


int main(int argc, const char** argv) {
	//

	atexit(on_exit_hook);

	display = XOpenDisplay(nullptr);


	hideCursor();

	std::string str;
	while(std::cin>>str){
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}