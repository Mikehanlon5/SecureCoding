// Uncomment the next line to use precompiled headers
//#include "pch.h"
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
  ~Environment() override {}

  // Override this to define how to set up the environment.
  void SetUp() override
  {
    //  initialize random seed
    srand(time(nullptr));
  }

  // Override this to define how to tear down the environment.
  void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
  // create a smart point to hold our collection
  std::unique_ptr<std::vector<int>> collection;

  void SetUp() override
  { // create a new collection to be used in the test
    collection.reset( new std::vector<int>);
  }

  void TearDown() override
  { //  erase all elements in the collection, if any remain
    collection->clear();
    // free the pointer
    collection.reset(nullptr);
  }

  // helper function to add random values from 0 to 99 count times to the collection
  void add_entries(int count)
  {
    assert(count > 0);
    for (auto i = 0; i < count; ++i)
      collection->push_back(rand() % 100);
  }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
  // is the collection created
  ASSERT_TRUE(collection);

  // if empty, the size must be 0
  ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
  // is the collection empty?
  ASSERT_TRUE(collection->empty());

  // if empty, the size must be 0
  ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
TEST_F(CollectionTest, AlwaysFail)
{
  FAIL();
}

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
  // is the collection empty?
  // if empty, the size must be 0

  add_entries(1);

  // is the collection still empty?
  // if not empty, what must the size be?
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
  add_entries(5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
bool enough_space1(collection) {
  if (collection.max_size() >= 0) {
    if (collection.max_size() >= 1) {
      if (collection.max_size() >= 5) {
        if (collection.max_size() >= 10) {
          return true;
        }
      }
    }
  }
  else {
    return false;
  }
}
// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries
bool enough_space2(collection) {
  if (collection.max_size() - collection.size() >= 0) {
    if (collection.max_size() - collection.size() >= 1) {
      if (collection.max_size() - collection.size() >= 5) {
        if (collection.max_size() - collection.size() >= 10) {
          return true;
        }
      }
    }
  }
  else {
    return false;
  }
}
// TODO: Create a test to verify resizing increases the collection
bool test_resize1(collection) {
  int first_size = collection.max_size();
  collection.resize(collection.max_size() + 10)
  if (collection.max_size() > first_size) {
    return true;
  }
  else {
    return false;
  }
} 
// TODO: Create a test to verify resizing decreases the collection
bool test_resize2(collection) {
  int first_size = collection.max_size();
  collection.resize(collection.max_size() - 10);
  if (collection.max_size() < first_size) {
    return true;
  }
  else {
    return false;
  }
}

// TODO: Create a test to verify resizing decreases the collection to zero
bool test_resize3(collection) {
  collection.resize(0);
  if (collection.max_size() == 0) {
    return true;
  }
  else {
    return false;
  }
} 

// TODO: Create a test to verify clear erases the collection
bool test_clear(collection) {
  collection.clear();
  return collection.empty(); //should return true/false if collection is empty
}

// TODO: Create a test to verify erase(begin,end) erases the collection
bool test_erase(collection) {
  int start_size = collection.size();
  collection.erase(0, start_size);
  if (collection.size() == 0) { 
    return true;
  }
  else {
    return 0;
  }
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
bool test_reserve(collection) {
  int start_size = collection.size();
  collection.reserve(100);
  if (collection.size() == start_size) {
    return true;
  }
  else {
    return false;
  }
}

// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test
bool break_range(collection) {
  try {
    collection.at(-1);
  }
  catch (const std::out_of_range &e) {
    std::cout << "Error Occured: " << e.what() << std::endl;
    return true;
  }
  return false;
}

// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative

//Negative Test: After a clear it is a good test to see that there is no longer any element in the first index
bool check_front_empty(collection) {
  collection.clear();
  front = collection.front();
  if (front == null) {
    return true;
  }
  else {
    return false;
  }
}

//Check if push_back is actually increasing the size of vector
bool check_push_back(collection) {
  initial = collection.size();
  collection.push_back(1);
  if (collection.size() == initial + 1) {
    return true;
  }
  else {
    return false;
  }
}
