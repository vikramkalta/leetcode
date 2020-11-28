int factorial(int num)
{
  int iteration, factorial = 1;
  for (iteration = 1; iteration <= num; iteration++)
    factorial = factorial * iteration;

  return factorial;
}