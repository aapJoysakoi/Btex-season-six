import glfw
from OpenGL.GL import *
import numpy as np

coordinates = []

def key_callback(window, key, scancode, action, mods):
    if key == glfw.KEY_ESCAPE and action == glfw.PRESS:
        glfw.set_window_should_close(window, True)

def cursor_position_callback(window, xpos, ypos):
    if glfw.get_mouse_button(window, glfw.MOUSE_BUTTON_LEFT) == glfw.PRESS:
        x, y = glfw.get_cursor_pos(window)
        coordinates.append((x, y))

def main():
    if not glfw.init():
        print("Failed to initialize GLFW")
        return -1

    window = glfw.create_window(800, 600, "OpenGL Plotter", None, None)
    if not window:
        glfw.terminate()
        print("Failed to create GLFW window")
        return -1

    glfw.make_context_current(window)
    glfw.set_key_callback(window, key_callback)
    glfw.set_cursor_pos_callback(window, cursor_position_callback)

    while not glfw.window_should_close(window):
        glClear(GL_COLOR_BUFFER_BIT)

        # Plot entered coordinates
        glBegin(GL_POINTS)
        glColor3f(1.0, 0.0, 0.0) # Red color
        for coord in coordinates:
            glVertex2f(coord[0] / 400.0 - 1.0, -(coord[1] / 300.0 - 1.0)) # Normalize coordinates
        glEnd()

        glfw.swap_buffers(window)
        glfw.poll_events()

    glfw.terminate()
    return 0

if __name__ == "__main__":
    main()
