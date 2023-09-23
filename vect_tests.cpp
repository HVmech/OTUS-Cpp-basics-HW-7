#include "vect.h"

#include <gtest/gtest.h>

// No size c-tor test
TEST(vect_int_constructors, vect_int_0_size_returns_0)
{
    vect<int> arr1;

    const size_t expectedZeroSize = 0;
    EXPECT_EQ(arr1.size(), expectedZeroSize);
}

// Specified size c-tor test
TEST(vect_int_constructors, vect_int_10_size_returns_0)
{
    const size_t size = 10;
    vect<int> arr(size);

    const size_t expectedZeroSize = 0;
    EXPECT_EQ(arr.size(), expectedZeroSize);
}

// List conversive c-tor test
TEST(vect_int_constructors, vect_int_initializer_list_0_to_9_size_returns_10_elements_checks_return_true)
{
    vect<int> arr {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    const size_t expectedSize = 10;
    ASSERT_EQ(arr.size(), expectedSize);

    for(int i = 0; i < expectedSize; ++i)
    {
        ASSERT_TRUE(arr[i] == i);
    }
}

struct vect_int_methods :
    public testing::Test
{
    vect<int> arr;

    void fill(int uppLimit)
    {
        for(int i = 0; i < uppLimit; ++i)
        {
            arr.push_back(i);
        }
    }
};

TEST_F(vect_int_methods, push_back_0_1_2_size_returns_3_elements_compare_return_true)
{
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);

    const size_t expectedSize = 3;
    ASSERT_EQ(arr.size(), expectedSize);

    for(int i = 0; i < expectedSize; ++i)
    {
        ASSERT_TRUE(arr[i] == i);
    }
}

TEST_F(vect_int_methods, push_front_2_1_0_size_returns_3_elements_compare_return_true)
{
    arr.push_front(2);
    arr.push_front(1);
    arr.push_front(0);

    const size_t expectedSize = 3;
    ASSERT_EQ(arr.size(), expectedSize);

    for(int i = 0; i < expectedSize; ++i)
    {
        ASSERT_TRUE(arr[i] == i);
    }
}

TEST_F(vect_int_methods, fill_vect_int_0_to_4_compare_vect_int_0_to_4_returns_true)
{
    const int size = 5;
    fill(size);

    vect<int> arr2 {0, 1, 2, 3, 4};

    ASSERT_EQ(arr.size(), arr2.size());

    EXPECT_TRUE(arr == arr2);
}

TEST_F(vect_int_methods, fill_vect_int_0_to_5_compare_vect_int_0_to_4_returns_false)
{
    const int size = 6;
    fill(size);

    vect<int> arr2 {0, 1, 2, 3, 4};

    ASSERT_NE(arr.size(), arr2.size());

    EXPECT_FALSE(arr == arr2);
}

TEST_F(vect_int_methods, fill_vect_int_0_to_9_erase_10_5_1_compare_vect_int_1_2_3_5_6_7_8_returns_true)
{
    const int size = 10;
    fill(size);

	arr.erase(10);
	arr.erase(5);
	arr.erase(1);

    vect<int> expectedArr {1, 2, 3, 5, 6, 7, 8};

    EXPECT_TRUE(arr == expectedArr);
}

TEST_F(vect_int_methods, fill_vect_int_0_to_9_insert_20_to_6_compare_vect_int_0_1_2_3_4_20_5_6_7_8_9_returns_true)
{
    const size_t size = 10;
    fill(size);

    const int elem = 20;
    const size_t pos = 6;
	arr.insert(elem, pos);

    vect<int> expectedArr {0, 1, 2, 3, 4, 20, 5, 6, 7, 8, 9};

    EXPECT_TRUE(arr == expectedArr);
}

TEST_F(vect_int_methods, fill_vect_int_0_to_4_at_4_5_6_return_4_0_0)
{
    const int size = 5;
    fill(size);

    EXPECT_EQ(arr.at(4), 4);
    EXPECT_EQ(arr.at(5), 0);
    EXPECT_EQ(arr.at(6), 0);
}

TEST_F(vect_int_methods, fill_vect_int_0_to_4_clear_size_returns_0)
{
    const int size = 5;
    fill(size);

	arr.clear();

    const size_t expectedZeroSize = 0;
    EXPECT_EQ(arr.size(), expectedZeroSize);
}

TEST_F(vect_int_methods, fill_vect_int_0_to_4_begin_returns_0)
{
    const int size = 5;
    fill(size);

    const int expectedResult = 0;
    EXPECT_TRUE(*arr.begin() == expectedResult);
}

TEST_F(vect_int_methods, fill_vect_int_0_to_4_for_begin_to_end_assign_5_for_all_element_check_returns_5)
{
    const int size = 5;
    fill(size);

    const int expectedResult = 5;
    for(auto it = arr.begin(); it != arr.end(); ++it)
    {
        *it = expectedResult;
    }

    for(size_t i = 0; i < size; ++i)
    {
        ASSERT_TRUE(arr[i] == expectedResult);
    }
}

struct vect_int_copy :
    public testing::Test
{
    vect<int> arr {0, 1, 2, 3, 4};
};

TEST_F(vect_int_copy, vect_int_0_to_4_new_vect_int_copy_is_equal)
{
    vect<int> newArr {arr};

    EXPECT_TRUE(arr == newArr);
}

TEST_F(vect_int_copy, vect_int_0_to_4_assignment_copy_to_vect_int_0_to_9_is_equal)
{
    vect<int> arr2 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    arr2 = arr;

    EXPECT_TRUE(arr == arr2);
}

TEST_F(vect_int_copy, vect_int_0_to_4_assignment_copy_to_vect_int_0_to_3_is_equal)
{
    vect<int> arr2 {0, 1, 2, 3};

    arr2 = arr;

    EXPECT_TRUE(arr == arr2);
}

TEST_F(vect_int_copy, vect_int_0_to_4_assignment_copy_to_vect_int_0_is_equal)
{
    vect<int> arr2;

    arr2 = arr;

    EXPECT_TRUE(arr == arr2);
}

struct vect_int_move :
    public testing::Test
{
    vect<int> arr {0, 1, 2, 3, 4};
};

TEST_F(vect_int_move, new_vect_int_from_moved_vect_int_0_to_9_is_equal)
{
    vect<int> tempArr {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vect<int> arr2 (std::move(tempArr));

    ASSERT_EQ(tempArr.size(), 0);

    vect<int> expectedArr {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    EXPECT_TRUE(arr2 == expectedArr);
}

TEST_F(vect_int_move, vect_int_0_to_4_copy_of_moved_vect_int_0_to_9_is_equal)
{
    vect<int> tempArr {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    arr = std::move(tempArr);

    ASSERT_EQ(tempArr.size(), 0);

    vect<int> expectedArr {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    EXPECT_TRUE(arr == expectedArr);
}

int destructorCount_v = 0;

struct test_int_v
{
    test_int_v()
    {
        value = 0;
    }

    test_int_v(int val)
    {
        value = val;
    }

    friend bool operator== (const test_int_v& val1, const test_int_v& val2)
    {
        return val1.value == val2.value;
    }

    friend bool operator!= (const test_int_v& val1, const test_int_v& val2)
    {
        return val1.value != val2.value;
    }

    ~test_int_v()
    {
        ++destructorCount_v;
    }

    int value;
};

TEST(vect_test_int_v_destructor, vect_test_int_v_0_to_9_destructor_count_is_10)
{
    {
        vect<test_int_v> arr {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        destructorCount_v = 0;
    }

    const int expectedResult = 10;
    EXPECT_EQ(destructorCount_v, expectedResult);
}
