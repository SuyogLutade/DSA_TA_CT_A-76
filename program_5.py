def isValid(expression):
    stack = []
    opening = "({["
    closing = ")}]"
    
    for ch in expression:
        if ch in opening:
            stack.append(ch)
        elif ch in closing:
            pos = closing.index(ch)
            if len(stack) > 0 and opening[pos] == stack[-1]:
                stack.pop()
            else:
                return False
    
    return len(stack) == 0


# Driver code
expr = input("Enter expression: ")
if isValid(expr):
    print("Parentheses are Matched ")
else:
    print("Parentheses are NOT Matched ")