#include <iostream>
#include <vector>

using namespace std;

class TestSuite
{
    public:
        TestSuite();

        void runTests();
    
    private:
        void PrintTest(string);
        void PrintPassFail(bool);

        void EmptyListIsCreatedConstructor();
        void SizeOfEmptyListIsZero();
        void SizeReturnsCorrectValueAfterOneAddFront();
        void SizeReturnsCorrectValueAfterOneAddBack();
        void SizeReturnsCorrectValueAfterMultipleAddFront();
        void SizeReturnsCorrectValueAfterMultipleAddBack();
        void SizeReturnsCorrectValueAfterAddsAndRemoveFront();
        void SizeReturnsCorrectValueAfterAddsAndRemoveBack();
        void SizeReturnsCorrectValue();
        void SearchReturnsFalseOnEmptyList();
        void SearchReturnsFalseWhenValueNotInList();
        void SearchReturnsTrueWhenValueInLargeList();
        void ToVectorReturnsEmptyVectorForEmptyList();
        void ToVectorCreatesVectorWithContentsOfLargeList();
        void AddBackHasSizeOfPreviousListPlusOne();
        void AddBackAddsValueToTheBackOfList();
        void AddFrontHasSizeOfPreviousListPlusOne();
        void AddFrontAddsValueToTheFrontOfList();
        void RemoveBackOnEmptyListReturnsFalse();
        void RemoveBackRemovesBackElementOfList();
        void RemoveFrontOnEmptyListReturnsTrue();
        void RemoveFrontRemovesFrontElementOfList();
};