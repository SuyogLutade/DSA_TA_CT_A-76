class TwoStacks:
    def __init__(self, size):
        self.size = size
        self.arr = [None] * size
        self.top1 = -1
        self.top2 = size

    def push1(self, x):
        if self.top1 + 1 == self.top2:
            print("Stack 1 Overflow!")
        else:
            self.top1 += 1
            self.arr[self.top1] = x
            print("Inserted in Stack 1")

    def push2(self, x):
        if self.top2 - 1 == self.top1:
            print("Stack 2 Overflow!")
        else:
            self.top2 -= 1
            self.arr[self.top2] = x
            print("Inserted in Stack 2")

    def pop1(self):
        if self.top1 == -1:
            print("Stack 1 Underflow!")
        else:
            print("Popped from Stack 1:", self.arr[self.top1])
            self.top1 -= 1

    def pop2(self):
        if self.top2 == self.size:
            print("Stack 2 Underflow!")
        else:
            print("Popped from Stack 2:", self.arr[self.top2])
            self.top2 += 1

# Driver code
ts = TwoStacks(10)

while True:
    print("\n Enter your choise: ")
    print("1. Push in Stack 1")
    print("2. Push in Stack 2")
    print("3. Pop from Stack 1")
    print("4. Pop from Stack 2")
    print("5. Exit")

    choice = int(input(": "))

    match choice:
        case 1:
            val = int(input("Enter value: "))
            ts.push1(val)

        case 2:
            val = int(input("Enter value: "))
            ts.push2(val)

        case 3:
            ts.pop1()

        case 4:
            ts.pop2()

        case 5:
            print("Exiting program!")
            break

        case _:
            print("Invalid Choice Try again.")
