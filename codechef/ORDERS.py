import os, sys

def order(n, moves):
    orig_order = []
    ordered = range(1,n+1)
    for i in reversed(moves):
        val = ordered[len(ordered)-1] - i
        ordered.remove(val)
        print val
        orig_order.append(val) 

    orig_order.reverse()
    return orig_order

def main():
    l = [0,1,2,0,1]
    n = 5
    print order(n, l)

if __name__ == "__main__":
    main()
