import sys
inchar = list(sys.argv[-1])
max_input = 16

stack=['$']
state = 0

print("({}, {}, {})".format(state,''.join(inchar),''.join(stack)))
for i in range(0, max_input+1) :
    if state == 0:
        if not inchar:
            break
        if inchar[0] == 'a':
            del inchar[0]
            state += 1
            stack.append('a')
            stack.reverse()
            print("({}, {}, {})".format(state,''.join(inchar),''.join(stack)))
            stack.reverse()
        else:
            break
    elif state == 1:
        if not inchar:
            break
        if inchar[0] == 'a':
            del inchar[0]
            stack.append('a')
            stack.reverse()
            print("({}, {}, {})".format(state,''.join(inchar),''.join(stack)))
            stack.reverse()
        elif inchar[0] == 'b':
            del inchar[0]
            state += 1
            if 'a' in stack:
                stack.remove('a')
                stack.reverse()
                print("({}, {}, {})".format(state,''.join(inchar),''.join(stack)))
                stack.reverse()
            else:
                break
        else:
            break
    elif state == 2:
        if not inchar:
            if stack[-1] =='$':
                state += 1
                stack.reverse()
                print("({}, {}, {})".format(state,''.join(inchar),''.join(stack)))
                stack.reverse()
                break
        elif stack[-1] == '$':
            state += 1
            stack.reverse()
            print("({}, {}, {})".format(state,''.join(inchar),''.join(stack)))
            stack.reverse()
            break
        elif inchar[0] == 'b':
            if 'a' in stack:
                del inchar[0]
                stack.remove('a')
                stack.reverse()
                print("({}, {}, {})".format(state,''.join(inchar),''.join(stack)))
                stack.reverse()
    else:
        break

if state == 3 and not inchar:
    print("Accepted")
elif state == 0 and not inchar:
    print("Accepted")
else:
    print("Rejected")