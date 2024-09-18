#include <gtest/gtest.h>
#include <MoarPtr/moar_ptr.h>

TEST(MoarPtrTest, ExternPtrTest)
{
	int test_int = 0;
	moar::extern_ptr<int> test_int_ptr;
	test_int_ptr.reset(&test_int);
	*test_int_ptr.get() = 10;

	EXPECT_EQ(test_int, 10);
}

int add(const int a, const int b)
{
	return a + b;
}
TEST(MoarPtrTest, FunctionPtrTest)
{
	moar::function_ptr<int(int, int)> add_ptr;
	add_ptr.reset(add);
	int result = add_ptr(2, 3);
	EXPECT_EQ(result, 5);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}