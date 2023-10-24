// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool do_even_more_custom_application_logic()
{
  // TODO: Throw any standard exceptionr
  std::cout << "Running Even More Custom Application Logic." << std::endl;
  try {
    throw 505;
  }
  catch (const std::exception &e) {
    std::cout << "Standard exception: " << std::endl;
    std::cout << e.what() << std::endl;
  }
  return true;
}
void do_custom_application_logic()
{
  // TODO: Wrap the call to do_even_more_custom_application_logic()
  //  with an exception handler that catches std::exception, displays
  //  a message and the exception.what(), then continues processing
  std::cout << "Running Custom Application Logic." << std::endl;
  //try do_even_more_custom_application_logic()
  try {
    if(do_even_more_custom_application_logic())
    {
      std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
    } 
  }

  catch (...) {
    std::cout << "Error: Exception in do_even_more_custom_application_logic(): integer error" << std::endl;
  }

  // TODO: Throw a custom exception derived from std::exception
  //  and catch it explictly in main

  std::cout << "Leaving Custom Application Logic." << std::endl;

}

//Custom exception extending std::exception to catch division by 0
class DivisionByZero : public std::exception {
  public:
  char * what () {
    return "Division by Zero";
  }
};

float divide(float num, float den)
{
  // TODO: Throw an exception to deal with divide by zero errors using
  //  a standard C++ defined exception
  if (den == 0) {
    throw DivisionByZero();
  }
  return (num / den);
}

void do_division() noexcept
{
  //  TODO: create an exception handler to capture ONLY the exception thrown
  //  by divide.

  float numerator = 10.0f;
  float denominator = 0;
  auto result = 0;
  try {
    result = divide(numerator, denominator);
  }
  catch (DivisionByZero dbz) {
    std::cout << "Math Error: " << std::endl;
    std::cout << dbz.what() << std::endl;
  }
  std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
}

int main()
{
  std::cout << "Exceptions Tests!" << std::endl;
  try {
  // TODO: Create exception handlers that catch (in this order):
  //  your custom exception
  //  std::exception
  //  uncaught exception 
  //  that wraps the whole main function, and displays a message to the console.
    do_division();
    do_custom_application_logic();
  }
  catch (...) {
    std::cout << "Exception Occured during Testing" << std::endl;
  }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
