import matplotlib.pyplot as plt

# Define the points to plot
# points = [0, 1, 2, 3, 4]


# Plot the points along the x-axis
def plot_points(points = [0, 1, 2, 3, 4]) -> None:
    plt.figure(figsize=(15, 5))  # Making the figure wider to better display the points
    plt.plot(range(len(points)), points, 'bo')  # 'bo' creates blue circles at each point
    plt.grid(True) # Add gridlines for both x and y axes
    plt.ylim(min(points), max(points)) # Set y-axis limits to the range of points
    # plt.yticks(range(len(points)))  # Show y-axis ticks for clarity
    # plt.yticks([]) # Hide y-axis ticks
    # Add vertical lines for each x position
    # for x in points:
    #     plt.axvline(x=x, color='gray', linestyle='--', linewidth=0.5)
    # Add a horizontal line at y=0
    # plt.axhline(y=0, color='grey', linestyle='-', linewidth=0.5)
    # plt.grid(axis='x') # Add gridlines along the x-axis
    plt.title("Points plotted along the X-axis")
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.show()
