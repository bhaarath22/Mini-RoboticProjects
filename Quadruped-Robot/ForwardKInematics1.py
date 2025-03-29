import numpy as np

def fk3r(q1, q2, q3, l1, l2, l3):
    """
    Forward kinematics of a 3R robot with different link lengths

    :param q1: Joint angle 1
    :param q2: Joint angle 2
    :param q3: Joint angle 3
    :param l1: Link length 1
    :param l2: Link length 2
    :param l3: Link length 3
    :return: End-effector position (x, y)
    """

    # DH parameters
    d1 = 0
    d2 = 0
    d3 = 0
    a1 = l1
    a2 = l2
    a3 = l3

    # Homogeneous transformation matrices for each link
    T01 = np.array([
        [np.cos(q1), -np.sin(q1), 0, a1],
        [np.sin(q1), np.cos(q1), 0, 0],
        [0, 0, 1, d1],
        [0, 0, 0, 1]
    ])

    T12 = np.array([
        [np.cos(q2), -np.sin(q2), 0, a2*np.cos(q2)],
        [np.sin(q2), np.cos(q2), 0, a2*np.sin(q2)],
        [0, 0, 1, d2],
        [0, 0, 0, 1]
    ])

    T23 = np.array([
        [np.cos(q3), -np.sin(q3), 0, a3*np.cos(q3)],
        [np.sin(q3), np.cos(q3), 0, a3*np.sin(q3)],
        [0, 0, 1, d3],
        [0, 0, 0, 1]
    ])

    # End-effector position
    T03 = np.dot(T01, np.dot(T12, T23))
    x, y = T03[:2, 2]

    return x, y

if __name__ == '__main__':
    # Example use
    q1, q2, q3 = 0, np.pi/2, np.pi/2
    l1, l2, l3 = 27.5, 55, 77.5

    x, y = fk3r(q1, q2, q3, l1, l2, l3)

    print('End-effector position (x, y): {}'.format((x, y)))