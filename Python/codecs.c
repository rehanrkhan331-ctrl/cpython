import turtle
import math
import time

# ---------------------- FULL-SCREEN SETUP ----------------------
screen = turtle.Screen()
screen.bgcolor("#000000")  # Black background for contrast
screen.setup(width=1.0, height=1.0)  # Full screen
screen.tracer(0)  # Smooth animation
screen.title("Dynamic Heart Animation")

# Get screen dimensions
WIDTH = screen.window_width()
HEIGHT = screen.window_height()

# Heart pen setup
heart = turtle.Turtle()
heart.hideturtle()
heart.penup()
heart.speed(0)

# Animation config
MIN_SCALE = 0.3  # Smallest heart size
MAX_SCALE = 0.8  # Largest heart size
PULSE_SPEED = 0.02  # Faster = quicker pulses
COLOR_SHIFT_SPEED = 0.05  # Faster = quicker color changes

# ---------------------- HEART DRAWING FUNCTION ----------------------
def draw_heart(scale):
    # Calculate heart size based on screen and scale
    size = min(WIDTH, HEIGHT) * scale * 0.2
    
    # Move to center
    heart.goto(0, -size * 0.3)
    
    # Clear previous heart
    heart.clear()
    
    # Calculate RGB color shift (rainbow effect)
    red = (math.sin(time.time() * COLOR_SHIFT_SPEED) + 1) / 2
    green = (math.sin(time.time() * COLOR_SHIFT_SPEED + 2) + 1) / 2
    blue = (math.sin(time.time() * COLOR_SHIFT_SPEED + 4) + 1) / 2
    heart.color((red, green, blue))
    
    # Draw filled heart
    heart.begin_fill()
    heart.left(50)
    heart.forward(size)
    heart.circle(size * 0.4, 200)
    heart.right(140)
    heart.circle(size * 0.4, 200)
    heart.forward(size)
    heart.end_fill()

# ---------------------- DYNAMIC ANIMATION LOOP ----------------------
def animate():
    # Calculate pulsing scale (smooth sine wave transition)
    current_scale = MIN_SCALE + (MAX_SCALE - MIN_SCALE) * (math.sin(time.time() * PULSE_SPEED) + 1) / 2
    
    # Draw and update
    draw_heart(current_scale)
    screen.update()
    screen.ontimer(animate, 10)  # Repeat every 10ms

# ---------------------- START ANIMATION ----------------------
animate()

# Keep running
try:
    screen.exitonclick()
except:
    turtle.done()
    
