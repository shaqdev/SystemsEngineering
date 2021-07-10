#!/usr/bin/env python3

def sum_int(n):
  res = 0
  for i in range(n):
    res += i
  return res

if __name__ == "__main__":
  import pdb; pdb.set_trace()
  n = int(input())
  res = sum_int(n)
  print("Sum of first %d integers is %d"%(n, res))