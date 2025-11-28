#include <unity.h>
#include <string.h>
#include <stdlib.h>

void setUp(void) {
}

void tearDown(void) {
}

// CSV deserialize implementation for native testing (mimics firmware logic)
void deserialize_csv(const char* input, int16_t* data_array, uint16_t max_size) {
    char buffer[1024];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    
    char* p = strtok(buffer, ",");
    int i = 0;
    while (p && i < max_size) {
        data_array[i] = atoi(p);
        p = strtok(NULL, ",");
        i++;
    }
}

void test_deserialize_simple(void) {
    int16_t data[10] = {0};
    const char* input = "0,1,50,50,512,512,512,0,0,0";
    
    deserialize_csv(input, data, 10);
    
    TEST_ASSERT_EQUAL_INT16(0, data[0]);
    TEST_ASSERT_EQUAL_INT16(1, data[1]);
    TEST_ASSERT_EQUAL_INT16(50, data[2]);
    TEST_ASSERT_EQUAL_INT16(50, data[3]);
    TEST_ASSERT_EQUAL_INT16(512, data[4]);
    TEST_ASSERT_EQUAL_INT16(512, data[5]);
    TEST_ASSERT_EQUAL_INT16(512, data[6]);
    TEST_ASSERT_EQUAL_INT16(0, data[7]);
    TEST_ASSERT_EQUAL_INT16(0, data[8]);
    TEST_ASSERT_EQUAL_INT16(0, data[9]);
}

void test_deserialize_negative_values(void) {
    int16_t data[5] = {0};
    const char* input = "-10,0,100,-50,25";
    
    deserialize_csv(input, data, 5);
    
    TEST_ASSERT_EQUAL_INT16(-10, data[0]);
    TEST_ASSERT_EQUAL_INT16(0, data[1]);
    TEST_ASSERT_EQUAL_INT16(100, data[2]);
    TEST_ASSERT_EQUAL_INT16(-50, data[3]);
    TEST_ASSERT_EQUAL_INT16(25, data[4]);
}

void test_deserialize_partial(void) {
    int16_t data[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    const char* input = "10,20,30";
    
    deserialize_csv(input, data, 10);
    
    TEST_ASSERT_EQUAL_INT16(10, data[0]);
    TEST_ASSERT_EQUAL_INT16(20, data[1]);
    TEST_ASSERT_EQUAL_INT16(30, data[2]);
    TEST_ASSERT_EQUAL_INT16(-1, data[3]);
}

void test_deserialize_empty(void) {
    int16_t data[5] = {-1, -1, -1, -1, -1};
    const char* input = "";
    
    deserialize_csv(input, data, 5);
    
    TEST_ASSERT_EQUAL_INT16(-1, data[0]);
}

void test_deserialize_max_bounds(void) {
    int16_t data[3] = {0};
    const char* input = "1,2,3,4,5,6,7,8,9";
    
    deserialize_csv(input, data, 3);
    
    TEST_ASSERT_EQUAL_INT16(1, data[0]);
    TEST_ASSERT_EQUAL_INT16(2, data[1]);
    TEST_ASSERT_EQUAL_INT16(3, data[2]);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    
    RUN_TEST(test_deserialize_simple);
    RUN_TEST(test_deserialize_negative_values);
    RUN_TEST(test_deserialize_partial);
    RUN_TEST(test_deserialize_empty);
    RUN_TEST(test_deserialize_max_bounds);
    
    return UNITY_END();
}

