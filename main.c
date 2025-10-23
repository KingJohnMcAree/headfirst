#include <X11/Xlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    Display* dpy = XOpenDisplay(NULL);
    if (!dpy) { fprintf(stderr, "Cannot open X display\n"); return 1; }

    int scr = DefaultScreen(dpy);
    Window win = XCreateSimpleWindow(
        dpy, RootWindow(dpy, scr),
        100, 100, 800, 600, 1,
        BlackPixel(dpy, scr), WhitePixel(dpy, scr)
    );
    XStoreName(dpy, win, "John McAree");
    XMapWindow(dpy, win);
    XFlush(dpy);

    sleep(3);  // keep the window visible briefly

    XDestroyWindow(dpy, win);
    XCloseDisplay(dpy);
    return 0;
}

