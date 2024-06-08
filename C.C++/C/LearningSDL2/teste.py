import numpy as np
import matplotlib.pyplot as plt

# Define the acceleration due to gravity
g = 9.81  # m/s^2

# Define functions to calculate position, velocity, and acceleration
def position(t, g):
    return 0.5 * g * t**2

def velocity(t, g):
    return g * t

def acceleration(t, g):
    return np.full_like(t, g)

# Generate an array of time values from 0 to 10 seconds
time_values = np.linspace(0, 10, 500)

# Calculate the corresponding position, velocity, and acceleration values
position_values = position(time_values, g)
velocity_values = velocity(time_values, g)
acceleration_values = acceleration(time_values, g)

# Plot the position, velocity, and acceleration over time
plt.figure(figsize=(12, 8))

# Position plot
plt.subplot(3, 1, 1)
plt.plot(time_values, position_values, label='Position (s = 0.5 * g * t^2)', color='b')
plt.xlabel('Time (seconds)')
plt.ylabel('Position (m)')
plt.title('Position of an Object in Free Fall Over Time')
plt.legend()
plt.grid(True)

# Velocity plot
plt.subplot(3, 1, 2)
plt.plot(time_values, velocity_values, label='Velocity (v = g * t)', color='g')
plt.xlabel('Time (seconds)')
plt.ylabel('Velocity (m/s)')
plt.title('Velocity of an Object in Free Fall Over Time')
plt.legend()
plt.grid(True)

# Acceleration plot
plt.subplot(3, 1, 3)
plt.plot(time_values, acceleration_values, label='Acceleration (a = g)', color='r')
plt.xlabel('Time (seconds)')
plt.ylabel('Acceleration (m/s^2)')
plt.title('Acceleration of an Object in Free Fall Over Time')
plt.legend()
plt.grid(True)

# Adjust layout to prevent overlap
plt.tight_layout()
plt.show()
