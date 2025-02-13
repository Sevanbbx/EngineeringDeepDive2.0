class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __str__(self):
        return f'({self.x}, {self.y})'
    
    def lt_x(self, other):
        return self.x < other.x
    
    def lt_y(self, other):
        return self.y < other.y
    
    def distance(self, other):
        return ((other.x - self.x) ** 2 + (other.y - self.y) ** 2)


class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


class KDTree:
    def __init__(self):
        self.root = None

    def insert(self, point, current=None, level=0):
        if self.root == None:
            self.root = Node(point)
            return self.root.value
        if current == None:
           current = self.root
        if level % 2:
            if point.lt_y(current.value):
                if current.left == None:
                    current.left = Node(point)
                    return current.left.value
                else:
                    return self.insert(point, current.left, level + 1)
            else:
                if current.right == None:
                    current.right = Node(point)
                    return current.right.value
                else:
                    return self.insert(point, current.right, level + 1)
        else:
            if point.lt_x(current.value):
                if current.left == None:
                    current.left = Node(point)
                    return current.left.value
                else:
                    return self.insert(point, current.left, level + 1)
            else:
                if current.right == None:
                    current.right = Node(point)
                    return current.right.value
                else:
                    return self.insert(point, current.right, level + 1)

    def nn_search(self, point, current, nn, level=0):
        if current == None:
            current = self.root
        
        if current.value.distance(point) < nn.distance(point):
            nn = current.value
        
        # if level % 2:
        #     if point.lt_y(current.value):
        #         if current.left != None:
        #             nn = self.nn_search(point, current.left, nn, level + 1)
        #         if current.right != None 

    def print(self, current=None, indent=""):
        if current is None:
            current = self.root
        print(indent + str(current.value))
        indent += "    "
        if current.right is not None:
            self.print(current.right, indent)
        if current.left is not None:
            self.print(current.left, indent)


kd_tree = KDTree()
kd_tree.insert(Point(2, 3))
kd_tree.insert(Point(8, 7))
kd_tree.insert(Point(1, 9))
kd_tree.insert(Point(4, 8))
kd_tree.insert(Point(5, 1))
kd_tree.insert(Point(3, 2))
kd_tree.insert(Point(7, 4))
kd_tree.insert(Point(9, 6))


kd_tree.print()
