
import numpy as np
def forward_kinematics(l1, l2, l3, t1, t2, t3):
    # Trigonometric functions of the joint angles
    c1, s1 = np.cos(t1), np.sin(t1)
    c2, s2 = np.cos(t2), np.sin(t2)
    c3, s3 = np.cos(t3), np.sin(t3)
    # Calculate intermediate variables
    c12 = c1 * c2 - s1 * s2
    s12 = s1 * c2 + c1 * s2
    c123 = c12 * c3 - s12 * s3
    s123 = s12 * c3 + c12 * s3
    # forward kinematics
    x = (l1 * c1) + (l2 * c12) + (l3 * c123)
    y = (l1 * s1) + (l2 * s12) + (l3 * s123)
    theta = t1 + t2 + t3
    return x, y, theta

l1, l2, l3 = 2.75, 5.5, 7.75 # link lengths
t1, t2, t3 = np.pi / 4, np.pi / 3, np.pi / 2  # joint angles
x, y, theta = forward_kinematics(l1, l2, l3, t1, t2, t3)

print("End-effector position: ({}, {})".format(x, y))
print("End-effector orientation: {} radians".format(theta))
