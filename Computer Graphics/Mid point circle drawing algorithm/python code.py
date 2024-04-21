import matplotlib.pyplot as plt

def draw_circle(xc, yc, r):
    x = r
    y = 0
    points = []

    # Initial decision parameter of region 1
    d = 1 - r

    # Plot the initial point
    points.extend([(xc + x, yc + y), (xc - x, yc + y), (xc + x, yc - y), (xc - x, yc - y),
                   (xc + y, yc + x), (xc - y, yc + x), (xc + y, yc - x), (xc - y, yc - x)])

    while x > y:
        y += 1

        # Mid-point is inside or on the perimeter
        if d <= 0:
            d = d + 2 * y + 1
        else:
            x -= 1
            d = d + 2 * (y - x) + 1

        # Plot the points in the other octants
        if x < y:
            break

        points.extend([(xc + x, yc + y), (xc - x, yc + y), (xc + x, yc - y), (xc - x, yc - y),
                       (xc + y, yc + x), (xc - y, yc + x), (xc + y, yc - x), (xc - y, yc - x)])

    return points

# Example usage:
xc, yc = 250, 250  # Center of the circle
r = 150  # Radius of the circle
points = draw_circle(xc, yc, r)

# Plotting
plt.figure()
x_values = [p[0] for p in points]
y_values = [p[1] for p in points]
plt.scatter(x_values, y_values, marker='.', color='black')
plt.title("Midpoint Circle Drawing Algorithm")
plt.xlabel("X")
plt.ylabel("Y")
plt.grid(True)
plt.gca().set_aspect('equal', adjustable='box')
plt.show()
