#include <iostream>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>
#include "TextReaderTest.h"

namespace Mitrais
{
namespace test
{
	int main()
	{
		using namespace CppUnit;

		CppUnit::TextUi::TestRunner runner;
		runner.addTest(new TextReaderTest());
		runner.run();

		return 0;
	}
}
}
