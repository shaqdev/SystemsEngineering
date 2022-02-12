void reverse(char src[], int beg, int end){
  char c;

  // Check if we reach end of recursion
  if (beg >= end)
    return;

  //swap src[beg] & src[end]
  c = src[beg];
  src[beg] = src[end];
  src[end] = c;

  // Increment/Decrement beg/end
  // Call reverse
  // Note: Always pre inc/dec the args if sending by values
  reverse(src, ++beg, --end);
}