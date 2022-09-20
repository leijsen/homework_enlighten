s = input()
left = ['(', '[', '{']
right = [')', ']', '}']
stack = []
result = 1
for c in s:
    if c in left:
        if(c=='('):
            stack.append(')')
        elif(c=='['):
            stack.append(']')
        else:
            stack.append('}')
    elif c in right:
        if stack is None:
            result = 0
            break
        if c == stack[-1]:
            stack.pop()
        else:
            result = 0
if not stack and result == 1:
    print('1')
else:
    print('0')