// starT.cpp   A demonstration of ASCII Art printing T characters

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starT(int width, int height);
void runTests(void);

// Write starT per specifictions in the lab writeup

string starT(int width, int height)
{ string result = "";
  if ((width < 3) || (height < 2))
    return result;

  if(width % 2 == 0)
    return result;
 
  for(int c = 1; c <= width; c++)
  { result += "*";}
  result += "\n";
  
  int centre = width / 2 + 1;

  for (int r = 2; r <= height; r++)
  {for(int c = 1; c <= width; c++)
    {
      if(c == centre)
        result += "*";
      else
 result += " ";}
    result += "\n";}return result;}




// Test-Driven Development; check expected results against actual

void runTests(void)
{

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they
  // automatically get concatenated into a single string literal

  string starT34Expected =
      "***\n"
      " * \n"
      " * \n"
      " * \n";

  assertEquals(starT34Expected, starT(3, 4), "starT(3,4)");

  string starT53Expected =
      "*****\n"
      "  *  \n"
      "  *  \n";

  assertEquals(starT53Expected, starT(5, 3), "starT(5,3)");

  string starT72Expected =
      "*******\n"
      "   *   \n";

  assertEquals(starT72Expected, starT(7, 2), "starT(7,2)");

  assertEquals("", starT(1, 2), "starT(1,2)");
  assertEquals("", starT(5, 1), "starT(5,1)");
  assertEquals("", starT(4, 2), "starT(4,2)");
  assertEquals("", starT(6, 2), "starT(6,2)");
}

// Test harness

void assertEquals(string expected, string actual, string message = "")
{
  if (expected == actual)
  {
    cout << "PASSED: " << message << endl;
    ;
  }
  else
  {
    cout << "   FAILED: " << message << endl
         << "   Expected:[\n"
         << expected << "] actual = [\n"
         << actual << "]\n"
         << endl;
  }
}



int main(int argc, char *argv[])
{

  if (argc != 3)
  {
    cerr << "Usage: " << argv[0] << " width height" << endl;
    exit(1);
  }

  int width = stoi(argv[1]);
  int height = stoi(argv[2]);
  // If the program is executed with parameters -1 -1 unit test
  // the starL() function using our automated test framework
  if (width == -1 && height == -1)
  {
    runTests();
    exit(0);
  }
  cout << starT(width, height);
  return 0;
}
