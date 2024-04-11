#include "pch.h"
#include "CppUnitTest.h"
#include "../lab12.6/FileName.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCreateQueueFromFile)
		{
			std::string filename = "test_words.txt";
			std::ofstream outfile(filename);
			outfile << "apple" << std::endl;
			outfile << "banana" << std::endl;
			outfile << "orange" << std::endl;
			outfile.close();

			std::queue<std::string> resultQueue = createQueueFromFile(filename);

			Assert::AreEqual(3, static_cast<int>(resultQueue.size()));
			Assert::AreEqual(std::string("apple"), resultQueue.front());
			resultQueue.pop();
			Assert::AreEqual(std::string("banana"), resultQueue.front());
			resultQueue.pop();
			Assert::AreEqual(std::string("orange"), resultQueue.front());
		}
	};
}
