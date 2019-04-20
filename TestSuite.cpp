#include "TestSuite.h"
#include "LinkedListOfInts.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define TestSize 1000

void print(LinkedListOfInts list)
{
    
    vector<int> vec = list.toVector();
    cout << "List Length: " << list.size() << endl;
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void print(vector<int> vec)
{
    cout << "Vector Length: " << vec.size() << endl;
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

TestSuite::TestSuite()
{

}

void TestSuite::PrintTest(string message)
{
    cout.width(70   );
    cout << left << message;
}


void TestSuite::PrintPassFail(bool PassFail)
{
    if(PassFail)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    
}


void TestSuite::runTests()
{
    EmptyListIsCreatedConstructor();
    SizeOfEmptyListIsZero();
    SizeReturnsCorrectValueAfterOneAddFront();
    SizeReturnsCorrectValueAfterOneAddBack();
    SizeReturnsCorrectValueAfterMultipleAddFront();
    SizeReturnsCorrectValueAfterMultipleAddBack();
    SizeReturnsCorrectValueAfterAddsAndRemoveFront();
    SizeReturnsCorrectValueAfterAddsAndRemoveBack();
    SizeReturnsCorrectValue();
    SearchReturnsFalseOnEmptyList();
    SearchReturnsFalseWhenValueNotInList();
    SearchReturnsTrueWhenValueInLargeList();
    ToVectorReturnsEmptyVectorForEmptyList();
    ToVectorCreatesVectorWithContentsOfLargeList();
    AddBackHasSizeOfPreviousListPlusOne();
    AddBackAddsValueToTheBackOfList();
    AddFrontHasSizeOfPreviousListPlusOne();
    AddFrontAddsValueToTheFrontOfList();
    RemoveBackOnEmptyListReturnsFalse();
    RemoveBackRemovesBackElementOfList();
    RemoveFrontOnEmptyListReturnsTrue();
    RemoveFrontRemovesFrontElementOfList();
}


void TestSuite::EmptyListIsCreatedConstructor()
{
    PrintTest("Test 1: Consctructor creates empty list: ");

    LinkedListOfInts list;
    bool Passed = false;

    Passed = list.isEmpty();
    
    PrintPassFail(Passed);
}


void TestSuite::SizeOfEmptyListIsZero()
{
    PrintTest("Test 2: Size of empty list is zero: ");

    LinkedListOfInts list;
    bool Passed = false;

    Passed = list.size() == 0;

    PrintPassFail(Passed);
}


void TestSuite::SizeReturnsCorrectValueAfterOneAddFront()
{
    PrintTest("Test 3: Size returns correct value after 1 addFront: ");

    LinkedListOfInts list;
    bool Passed = false;

    list.addFront(1);
    Passed = list.size() == 1;

    PrintPassFail(Passed);
}


void TestSuite::SizeReturnsCorrectValueAfterOneAddBack()
{
    PrintTest("Test 4: Size returns correct value after 1 addBack: ");

    LinkedListOfInts list;
    bool Passed = false;

    list.addBack(1);
    Passed = list.size() == 1;

    PrintPassFail(Passed);
}


void TestSuite::SizeReturnsCorrectValueAfterMultipleAddFront()
{
    PrintTest("Test 5: Size returns correct value after multiple addFront: ");

    LinkedListOfInts list;
    bool Passed = false;

    for(int i = 0; i < TestSize; i++)
    {
        list.addFront(i);
    }
    Passed = list.size() == TestSize;

    PrintPassFail(Passed);
}


void TestSuite::SizeReturnsCorrectValueAfterMultipleAddBack()
{
    PrintTest("Test 6: Size returns correct value after multiple addBack: ");

    LinkedListOfInts list;
    bool Passed = false;

    for(int i = 0; i < TestSize; i++)
    {
        list.addBack(i);
    }
    Passed = list.size() == TestSize;

    PrintPassFail(Passed);
}


void TestSuite::SizeReturnsCorrectValueAfterAddsAndRemoveFront()
{
    PrintTest("Test 7: Size returns correct value after adds and removeFront: ");

    LinkedListOfInts list;
    bool Passed = false;

    for(int i = 0; i < TestSize; i++)
    {
        list.addFront(i);
        list.removeFront();
    }
    Passed = list.size() == 0;

    PrintPassFail(Passed);
}


void TestSuite::SizeReturnsCorrectValueAfterAddsAndRemoveBack()
{
    PrintTest("Test 8: Size returns correct value after adds and removeBack: ");

    LinkedListOfInts list;
    bool Passed = false;

    for(int i = 0; i < TestSize; i++)
    {
        list.addBack(i);
        list.removeBack();
    }
    Passed = list.size() == 0;

    PrintPassFail(Passed);
}


void TestSuite::SizeReturnsCorrectValue()
{
    PrintTest("Test 9: Size returns correct value: ");

    LinkedListOfInts list;
    bool Passed = false;

    for(int i = 0; i < TestSize; i++)
    {
        list.addBack(i);
    }
    Passed = list.size() == TestSize;

    PrintPassFail(Passed);
}


void TestSuite::SearchReturnsFalseOnEmptyList()
{
    PrintTest("Test 10: Search returns false on empty list: ");

    LinkedListOfInts list;
    bool Passed = false;

    Passed = list.search(20) == false;

    PrintPassFail(Passed);
}


void TestSuite::SearchReturnsFalseWhenValueNotInList()
{
    PrintTest("Test 11: Search returns false when value not in list: ");

    LinkedListOfInts list;
    bool Passed = false;

    for(int i = 0; i < TestSize; i++)
    {
        list.addBack(i);
    }
    Passed = list.search(TestSize) == false;

    PrintPassFail(Passed);
}


void TestSuite::SearchReturnsTrueWhenValueInLargeList()
{
    PrintTest("Test 12: Search returns true when value in large list: ");

    LinkedListOfInts list;
    bool Passed = false;

    for(int i = 0; i < TestSize; i++)
    {
        list.addBack(i);
    }
    bool isWithin = true;
    for(int i = 0; i < TestSize; i++)
    {
        if(!list.search(i))
        {
            isWithin = false;
        }
    }
    Passed = isWithin;

    PrintPassFail(Passed);
}


void TestSuite::ToVectorReturnsEmptyVectorForEmptyList()
{
    PrintTest("Test 13: ToVector returns empty vector for empty list: ");

    LinkedListOfInts list;
    bool Passed = false;

    vector<int> vec = list.toVector();
    Passed = vec.empty();

    PrintPassFail(Passed);
}


void TestSuite::ToVectorCreatesVectorWithContentsOfLargeList()
{
    PrintTest("Test 14: ToVector creates vector with contents of large list: ");

    LinkedListOfInts list;
    bool Passed = false;

    vector<int> key;
    for(int i = 0; i < TestSize; i++)
    {
        list.addFront(i);
        auto it = key.insert(key.begin(), i); 
    }
    vector<int> vec = list.toVector();
    bool isSame = true;
    for(int i = 0; i < TestSize; i++)
    {
        if(key[i] != vec[i])
        {
            isSame = false;
        }
    }
    Passed = isSame;
    PrintPassFail(Passed);
}


void TestSuite::AddBackHasSizeOfPreviousListPlusOne()
{
    PrintTest("Test 15: AddBack has size of previous list plus one: ");

    LinkedListOfInts list;
    bool Passed = false;

    for(int i = 0; i < TestSize; i++)
    {
        list.addFront(i);
    }
    int prevSize = list.size();
    list.addBack(TestSize);
    Passed = prevSize + 1 == list.size();

    PrintPassFail(Passed);
}


void TestSuite::AddBackAddsValueToTheBackOfList()
{
    PrintTest("Test 16: AddBack adds value to the back of list: ");

    LinkedListOfInts list;
    bool Passed = false;

    for(int i = 0; i < TestSize; i++)
    {
        list.addBack(i);
    }
    list.addBack(TestSize);
        vector<int> vec = list.toVector();
    Passed = vec[vec.size() - 1] == TestSize;

    PrintPassFail(Passed);
}


void TestSuite::AddFrontHasSizeOfPreviousListPlusOne()
{
    PrintTest("Test 17: AddFront has size of previous list plus one: ");

    LinkedListOfInts list;
    bool Passed = false;

    for(int i = 0; i < TestSize; i++)
    {
        list.addBack(i);
    }
    int prevSize = list.size();
    list.addFront(TestSize);
    Passed = prevSize + 1 == list.size();

    PrintPassFail(Passed);
}


void TestSuite::AddFrontAddsValueToTheFrontOfList()
{
    PrintTest("Test 18: AddFront adds value to the front of the list: ");

    LinkedListOfInts list;
    bool Passed = false;

    for(int i = 0; i < TestSize; i++)
    {
        list.addBack(i);
    }
    list.addFront(TestSize);
    vector<int> vec = list.toVector();
    Passed = vec[0] == TestSize;

    PrintPassFail(Passed);
}


void TestSuite::RemoveBackOnEmptyListReturnsFalse()
{
    PrintTest("Test 19: RemoveBack on empty list returns false: ");

    LinkedListOfInts list;
    bool Passed = false;

    Passed = !list.removeBack();

    PrintPassFail(Passed);
}


void TestSuite::RemoveBackRemovesBackElementOfList()
{
    PrintTest("Test 20: RemoveBack removes the back element of list: ");

    LinkedListOfInts list;
    bool Passed = false;

    for(int i = 0; i < TestSize; i++)
    {
        list.addFront(i);
    }
    vector<int> vec = list.toVector();
    int value = vec[vec.size() - 1];
    list.removeBack();
    Passed = !list.search(value);

    PrintPassFail(Passed);
}


void TestSuite::RemoveFrontOnEmptyListReturnsTrue()
{
    PrintTest("Test 21: RemoveFront on empty list returns true: ");

    LinkedListOfInts list;
    bool Passed = false;

    Passed = !list.removeFront();

    PrintPassFail(Passed);
}


void TestSuite::RemoveFrontRemovesFrontElementOfList()
{
    PrintTest("Test 22: RemoveFront removes front element of list: ");

    LinkedListOfInts list;
    bool Passed = false;

    for(int i = 0; i < TestSize; i++)
    {
        list.addBack(i);
    }
    vector<int> vec = list.toVector();
    int value = vec[0];
    list.removeFront();
    Passed = !list.search(value);

    PrintPassFail(Passed);
}

