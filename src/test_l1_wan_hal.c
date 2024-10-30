/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:*
 * Copyright 2024 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file test_l1_wan_hal.c
 * @page wan_hal Level 1 Tests
 *
 * ## Module's Role
 * This module includes Level 1 functional tests (success and failure scenarios).
 * This is to ensure that the wan_hal APIs meet the requirements across all vendors.
 *
 * **Pre-Conditions:**  None@n
 * **Dependencies:** None@n
 *
 * Ref to API Definition specification documentation : [wan-hal_halSpec.md](../../docs/pages/wan-hal_halSpec.md)
 */

#include <ut.h>
#include <ut_log.h>
#include "wan_hal.h"
#include <ut_kvp_profile.h>

static int gTestGroup = 1;
static int gTestID = 1;
#define MAX_STRING_LENGTH 250
WAN_QOS_QUEUE queue;
/**
 * @brief This test is to verify the initialization of the WAN HAL module
 *
 * In this test, the WAN HAL module is initialized and the return value is checked to ensure successful initialization@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 001@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the WAN HAL initialization function | No input data required for this function | The return value should be RETURN_OK, indicating successful initialization | Should be successful |
 */
int fetch_queue_data()
{
    char retrievedString[MAX_STRING_LENGTH];
    queue.InstanceNumber = UT_KVP_PROFILE_GET_UINT32("wan.config.queue.InstanceNumber");

    UT_KVP_PROFILE_GET_STRING("wan.config.queue.Alias", retrievedString);
    strncpy(queue.Alias, retrievedString, sizeof(queue.Alias));

    queue.queueKey = UT_KVP_PROFILE_GET_UINT32("wan.config.queue.queueKey");
    queue.queueEnable = UT_KVP_PROFILE_GET_BOOL("wan.config.queue.queueEnable");

    UT_KVP_PROFILE_GET_STRING("wan.config.queue.queueStatus", retrievedString);
    strncpy(queue.queueStatus, retrievedString, sizeof(queue.queueStatus));

    UT_KVP_PROFILE_GET_STRING("wan.config.queue.queueInterface", retrievedString);
    strncpy(queue.queueInterface, retrievedString, sizeof(queue.queueInterface));

    queue.queueWeight = UT_KVP_PROFILE_GET_UINT32("wan.config.queue.queueWeight");
    queue.queuePrecedence = UT_KVP_PROFILE_GET_UINT32("wan.config.queue.queuePrecedence");
    queue.REDThreshold = UT_KVP_PROFILE_GET_UINT32("wan.config.queue.REDThreshold");

    UT_KVP_PROFILE_GET_STRING("wan.config.queue.dropAlgorithm", retrievedString);
    strncpy(queue.dropAlgorithm, retrievedString, sizeof(queue.dropAlgorithm));

    UT_KVP_PROFILE_GET_STRING("wan.config.queue.schedulerAlgorithm", retrievedString);
    strncpy(queue.schedulerAlgorithm, retrievedString, sizeof(queue.schedulerAlgorithm));

    queue.shapingRate = UT_KVP_PROFILE_GET_UINT32("wan.config.queue.shapingRate");
    queue.shapingBurstSize = UT_KVP_PROFILE_GET_UINT32("wan.config.queue.shapingBurstSize");
    queue.MinBitRate = UT_KVP_PROFILE_GET_UINT32("wan.config.queue.MinBitRate");

    UT_KVP_PROFILE_GET_STRING("wan.config.queue.QueueName", retrievedString);
    strncpy(queue.QueueName, retrievedString, sizeof(queue.QueueName));

    queue.DslLatency = UT_KVP_PROFILE_GET_UINT32("wan.config.queue.DslLatency");
    queue.PtmPriority = UT_KVP_PROFILE_GET_UINT32("wan.config.queue.PtmPriority");
    queue.QueueId = UT_KVP_PROFILE_GET_UINT32("wan.config.queue.QueueId");

    queue.LowClassMaxThreshold = UT_KVP_PROFILE_GET_UINT32("wan.config.queue.LowClassMaxThreshold");
    queue.LowClassMinThreshold = UT_KVP_PROFILE_GET_UINT32("wan.config.queue.LowClassMinThreshold");
    queue.HighClassMinThreshold = UT_KVP_PROFILE_GET_UINT32("wan.config.queue.HighClassMinThreshold");
    queue.HighClassMaxThreshold = UT_KVP_PROFILE_GET_UINT32("wan.config.queue.HighClassMaxThreshold");

    UT_KVP_PROFILE_GET_STRING("wan.config.queue.L2DeviceType", retrievedString);
    strncpy(queue.L2DeviceType, retrievedString, sizeof(queue.L2DeviceType));

    return 0;
}

void test_l1_wan_hal_positive1_Init(void)
{
    gTestID = 1;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = wan_hal_Init();
    UT_LOG_DEBUG("Invoking wan_hal_Init()");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is to verify the functionality of the wan_hal_SetWanmode API when WAN_MODE_DISABLED is passed as input.
 *
 * In this test, the wan_hal_SetWanmode API is invoked with WAN_MODE_DISABLED as input. The test verifies if the API is able to handle this input and return the expected output.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 002@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_SetWanmode API with WAN_MODE_DISABLED as input | mode = WAN_MODE_DISABLED | The API should return RETURN_OK | The API should handle this input and return the expected output |
 */

void test_l1_wan_hal_positive1_SetWanmode(void)
{
    gTestID = 2;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = wan_hal_SetWanmode(WAN_MODE_DISABLED);
    UT_LOG_DEBUG("Invoking wan_hal_SetWanmode with mode as WAN_MODE_DISABLED");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test verifies the functionality of the wan_hal_SetWanmode API when the mode is set to WAN_MODE_DSL_ONLY
 *
 * In this test, the wan_hal_SetWanmode API is invoked with the mode set to WAN_MODE_DSL_ONLY. The test verifies that the API returns the expected result.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 003@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_SetWanmode API with the mode set to WAN_MODE_DSL_ONLY | mode = WAN_MODE_DSL_ONLY | The API should return RETURN_OK | The test should pass |
 */

void test_l1_wan_hal_positive2_SetWanmode(void)
{
    gTestID = 3;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = wan_hal_SetWanmode(WAN_MODE_DSL_ONLY);
    UT_LOG_DEBUG("Invoking wan_hal_SetWanmode with mode as WAN_MODE_DSL_ONLY");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test checks if the WAN mode can be set correctly
 *
 * This test invokes the wan_hal_SetWanmode API with WAN_MODE_ETH_ONLY as the argument and checks if the return value is RETURN_OK.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 004@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_SetWanmode API with WAN_MODE_ETH_ONLY as argument | mode = WAN_MODE_ETH_ONLY | The return value should be RETURN_OK | The test should pass |
 */

void test_l1_wan_hal_positive3_SetWanmode(void)
{
    gTestID = 4;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int ret = wan_hal_SetWanmode(WAN_MODE_ETH_ONLY);
    UT_LOG_DEBUG("Invoking wan_hal_SetWanmode with mode as WAN_MODE_ETH_ONLY");
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is to verify the functionality of the wan_hal_SetWanmode API when the mode is set to WAN_MODE_AUTO
 *
 * In this test, the wan_hal_SetWanmode API is invoked with the mode set to WAN_MODE_AUTO. The test verifies if the API returns the expected return value.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 005@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_SetWanmode API with mode set to WAN_MODE_AUTO | mode = WAN_MODE_AUTO | The return value should be RETURN_OK | The test should pass |
 */

void test_l1_wan_hal_positive4_SetWanmode(void)
{
    gTestID = 5;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int ret = wan_hal_SetWanmode(WAN_MODE_AUTO);
    UT_LOG_DEBUG("Invoking wan_hal_SetWanmode with mode as WAN_MODE_AUTO");
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the negative scenario of the wan_hal_SetWanmode API
 *
 * In this test, the wan_hal_SetWanmode API is invoked with an invalid mode value to check if the API is handling the error scenario correctly.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 006@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_SetWanmode API with invalid mode value | mode = 0 | The return value should be RETURN_ERROR | The API should handle the error scenario correctly |
 */

void test_l1_wan_hal_negative1_SetWanmode(void)
{
    gTestID = 6;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int num_invalid_mode;
    int i = 0;
    num_invalid_mode = UT_KVP_PROFILE_GET_LIST_COUNT("wan/config/invalid_wanmode");
    int invalid_mode[num_invalid_mode];
    char mode[50];
    for (i = 0; i <= num_invalid_mode; i++)
    {
        sprintf(mode, "vlan/config/invalid_brName/%d", i); // Fetch from yaml file
        invalid_mode[i] = UT_KVP_PROFILE_GET_UINT32(mode);
        int ret = wan_hal_SetWanmode(invalid_mode[i]);
        UT_LOG_DEBUG("Invoking wan_hal_SetWanmode with mode as %d\n", invalid_mode);
        UT_ASSERT_EQUAL(ret, RETURN_ERROR);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is to verify the functionality of the wan_hal_SetWanConnectionEnable API when the input is positive.
 *
 * In this test, the wan_hal_SetWanConnectionEnable API is invoked with a positive input and the return value is checked against the expected return value.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 007@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_SetWanConnectionEnable API with a positive input | enable = 1 | The return value should be RETURN_OK | The test should pass |
 */

void test_l1_wan_hal_positive1_SetWanConnectionEnable(void)
{
    gTestID = 7;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    unsigned int enable = 1;
    int ret = wan_hal_SetWanConnectionEnable(enable);
    UT_LOG_DEBUG("Invoking wan_hal_SetWanConnectionEnable with enable = %u\n", enable);
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is to verify the functionality of the wan_hal_SetWanConnectionEnable API when the 'enable' parameter is set to 0.
 *
 * In this test, the wan_hal_SetWanConnectionEnable API is invoked with 'enable' parameter set to 0. The test verifies if the API returns the expected return value when invoked with these parameters.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 008@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_SetWanConnectionEnable API with 'enable' parameter set to 0 | enable = 0 | The API should return RETURN_OK | The test should pass |
 */

void test_l1_wan_hal_positive2_SetWanConnectionEnable(void)
{
    gTestID = 8;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    unsigned int enable = 0;
    int ret = wan_hal_SetWanConnectionEnable(enable);
    UT_LOG_DEBUG("Invoking wan_hal_SetWanConnectionEnable with enable = %u\n", enable);
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_SetWanConnectionEnable API when provided with invalid input.
 *
 * In this test, the wan_hal_SetWanConnectionEnable API is invoked with an invalid 'enable' value to check if the API returns the expected error code.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 009@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_SetWanConnectionEnable API with invalid 'enable' value | enable = 2 | The API should return an error code | The test should pass if the API returns the expected error code |
 */

void test_l1_wan_hal_negative1_SetWanConnectionEnable(void)
{
    gTestID = 9;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int enable[] = {2, -1};
    int i = 0;
    for (i = 0; i < 2; i++)
    {
        int ret = wan_hal_SetWanConnectionEnable(enable[i]);
        UT_LOG_DEBUG("Invoking wan_hal_SetWanConnectionEnable with enable = %d\n", enable[i]);
        UT_ASSERT_EQUAL(ret, RETURN_ERROR);
    }
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test verifies the functionality of the wan_hal_SetSelfHealConfig API when invoked with valid parameters.
 *
 * This test is designed to validate the positive scenario of the wan_hal_SetSelfHealConfig API. The API is invoked with a valid pointer and rebootStatus set to 0. The test verifies that the API returns the expected return value.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 010@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_SetSelfHealConfig with valid pointer and rebootStatus set to 0 | config = {0}, rebootStatus = 0 | The return value should be RETURN_OK | The test should pass |
 */

void test_l1_wan_hal_positive1_SetSelfHealConfig(void)
{
    gTestID = 10;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    SELFHEAL_CONFIG config = {0};
    int ret = wan_hal_SetSelfHealConfig(&config);

    UT_LOG_DEBUG("Invoking wan_hal_SetSelfHealConfig with valid pointer and rebootStatus set to 0");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test verifies the functionality of the wan_hal_SetSelfHealConfig API when provided with valid input
 *
 * In this test, the wan_hal_SetSelfHealConfig API is invoked with a valid pointer and rebootStatus set to 1. The test verifies that the API returns the expected result when provided with valid input.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 011@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_SetSelfHealConfig with valid pointer and rebootStatus set to 1 | config = {1} | The return value should be RETURN_OK | The test should pass |
 */

void test_l1_wan_hal_positive2_SetSelfHealConfig(void)
{
    gTestID = 11;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    SELFHEAL_CONFIG config = {1};
    int ret = wan_hal_SetSelfHealConfig(&config);

    UT_LOG_DEBUG("Invoking wan_hal_SetSelfHealConfig with valid pointer and rebootStatus set to 1");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_SetSelfHealConfig API when passed a NULL pointer
 *
 * In this test, the wan_hal_SetSelfHealConfig API is invoked with a NULL pointer. The objective is to ensure that the API handles such erroneous input gracefully and returns an error code.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 012@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_SetSelfHealConfig API with NULL pointer | NULL | The API should return an error code | The API should handle erroneous input gracefully |
 */

void test_l1_wan_hal_negative1_SetSelfHealConfig(void)
{
    gTestID = 12;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = wan_hal_SetSelfHealConfig(NULL);

    UT_LOG_DEBUG("Invoking wan_hal_SetSelfHealConfig with NULL pointer");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the behavior of the wan_hal_SetSelfHealConfig API when provided with invalid input.
 *
 * In this test, the wan_hal_SetSelfHealConfig API is invoked with a SELFHEAL_CONFIG structure where the rebootStatus is set to a value other than 0 or 1. The API is expected to return an error in this scenario.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 013@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_SetSelfHealConfig with a SELFHEAL_CONFIG structure where the rebootStatus is set to a value other than 0 or 1 | rebootStatus = 2 | The API should return an error | The API is expected to validate the input and return an error for invalid values |
 */

void test_l1_wan_hal_negative2_SetSelfHealConfig(void)
{
    gTestID = 13;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    SELFHEAL_CONFIG config = {2};
    int ret = wan_hal_SetSelfHealConfig(&config);

    UT_LOG_DEBUG("Invoking wan_hal_SetSelfHealConfig with rebootStatus set to a value other than 0 or 1");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test verifies the function wan_hal_GetWanOEUpstreamCurrRate
 *
 * This test case is designed to verify if the function wan_hal_GetWanOEUpstreamCurrRate is able to successfully retrieve the current upstream rate of the WAN interface.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 014@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the function wan_hal_GetWanOEUpstreamCurrRate with a valid pointer | value = uninitialized unsigned int variable | The function should return RETURN_OK | The function should successfully retrieve the current upstream rate |
 */
void test_l1_wan_hal_positive1_GetWanOEUpstreamCurrRate(void)
{
    gTestID = 14;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned int value;
    int ret = wan_hal_GetWanOEUpstreamCurrRate(&value);

    UT_LOG_DEBUG("Invoking wan_hal_GetWanOEUpstreamCurrRate with valid pointer");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_GetWanOEUpstreamCurrRate API when invoked with NULL pointer.
 *
 * In this test, the wan_hal_GetWanOEUpstreamCurrRate API is invoked with NULL pointer to check if the API handles the error condition gracefully and returns the appropriate error code.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 015@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_GetWanOEUpstreamCurrRate API with NULL pointer | NULL | The API should return RETURN_ERROR | The API should handle the error condition gracefully |
 */

void test_l1_wan_hal_negative1_GetWanOEUpstreamCurrRate(void)
{
    gTestID = 15;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = wan_hal_GetWanOEUpstreamCurrRate(NULL);

    UT_LOG_DEBUG("Invoking wan_hal_GetWanOEUpstreamCurrRate with NULL pointer");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test verifies the function wan_hal_GetWanOEDownstreamCurrRate
 *
 * This test checks if the function wan_hal_GetWanOEDownstreamCurrRate returns the correct downstream current rate when invoked with a valid pointer.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 016@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_GetWanOEDownstreamCurrRate with valid pointer | pointer to unsigned int value | The function should return RETURN_OK | Should be successful |
 */

void test_l1_wan_hal_positive1_GetWanOEDownstreamCurrRate(void)
{
    gTestID = 16;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned int value;
    int ret = wan_hal_GetWanOEDownstreamCurrRate(&value);

    UT_LOG_DEBUG("Invoking wan_hal_GetWanOEDownstreamCurrRate with valid pointer");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the negative scenario of the function wan_hal_GetWanOEDownstreamCurrRate
 *
 * In this test, we are testing the behavior of the function wan_hal_GetWanOEDownstreamCurrRate when it is invoked with NULL pointer as input. This is to ensure that the function handles invalid inputs gracefully.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 017@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the function wan_hal_GetWanOEDownstreamCurrRate with NULL pointer as input | input = NULL | The function should return RETURN_ERROR | The function should handle invalid inputs gracefully |
 */

void test_l1_wan_hal_negative1_GetWanOEDownstreamCurrRate(void)
{
    gTestID = 17;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = wan_hal_GetWanOEDownstreamCurrRate(NULL);

    UT_LOG_DEBUG("Invoking wan_hal_GetWanOEDownstreamCurrRate with NULL pointer");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test verifies the function wan_hal_SetQoSConfiguration for positive scenario
 *
 * This test case is designed to verify the correct functionality of the wan_hal_SetQoSConfiguration API when invoked with valid parameters. The API is expected to return a success status when the queue is initialized with valid values and the function is called with valid baseifname and wanifname.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 018@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Initialize queue with valid values | queue = valid values | Queue should be initialized successfully | Should be successful |
 * | 02 | Invoke wan_hal_SetQoSConfiguration with valid pQueue, QueueNumberOfEntries = 1, valid baseifname and wanifname | pQueue = &queue, QueueNumberOfEntries = 1, baseifname = "erouter0", wanifname = "erouter0" | The function should return RETURN_OK | Should be successful |
 */

void test_l1_wan_hal_positive1_SetQoSConfiguration(void)
{
    gTestID = 18;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int status = wan_hal_SetQoSConfiguration(&queue, 1, "erouter0", "erouter0");

    UT_LOG_DEBUG("Invoking wan_hal_SetQoSConfiguration with valid pQueue, QueueNumberOfEntries = 1, valid baseifname and wanifname\n");
    UT_ASSERT_EQUAL(status, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_SetQoSConfiguration function when provided with invalid parameters.
 *
 * In this test, the wan_hal_SetQoSConfiguration function is invoked with a NULL pointer for the pQueue parameter, and valid values for the other parameters. The test is designed to ensure that the function handles this scenario correctly and returns an error.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 019@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_SetQoSConfiguration with pQueue = NULL, QueueNumberOfEntries = 1, valid baseifname and wanifname | pQueue = NULL, QueueNumberOfEntries = 1, baseifname = "erouter0", wanifname = "erouter0" | The function should return an error | The function should handle invalid parameters gracefully |
 */

void test_l1_wan_hal_negative1_SetQoSConfiguration(void)
{
    gTestID = 19;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int status = wan_hal_SetQoSConfiguration(NULL, 1, "erouter0", "erouter0");

    UT_LOG_DEBUG("Invoking wan_hal_SetQoSConfiguration with pQueue = NULL, QueueNumberOfEntries = 1, valid baseifname and wanifname\n");
    UT_ASSERT_EQUAL(status, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the function wan_hal_SetQoSConfiguration
 *
 * In this test, the function wan_hal_SetQoSConfiguration is invoked with valid parameters but with QueueNumberOfEntries set to 0. The function is expected to return an error in this scenario.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 020@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_SetQoSConfiguration with valid parameters but with QueueNumberOfEntries set to 0 | pQueue = valid, QueueNumberOfEntries = 0, baseifname = "erouter0", wanifname = "erouter0" | The function should return an error | The function is expected to handle this scenario gracefully and return an error |
 */

void test_l1_wan_hal_negative2_SetQoSConfiguration(void)
{
    gTestID = 20;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int status = wan_hal_SetQoSConfiguration(&queue, 0, "erouter0", "erouter0");

    UT_LOG_DEBUG("Invoking wan_hal_SetQoSConfiguration with valid pQueue, QueueNumberOfEntries = 0, valid baseifname and wanifname\n");
    UT_ASSERT_EQUAL(status, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the function wan_hal_SetQoSConfiguration
 *
 * In this test, the function wan_hal_SetQoSConfiguration is invoked with valid queue, QueueNumberOfEntries set to 1, baseifname set to NULL and a valid wanifname. The test is designed to verify the robustness of the function when it is invoked with a NULL baseifname.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 021@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_SetQoSConfiguration with valid queue, QueueNumberOfEntries set to 1, baseifname set to NULL and a valid wanifname | queue = valid, QueueNumberOfEntries = 1, baseifname = NULL, wanifname = "erouter0" | The function should return RETURN_ERROR | The function is expected to handle NULL baseifname gracefully |
 */

void test_l1_wan_hal_negative3_SetQoSConfiguration(void)
{
    gTestID = 21;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int status = wan_hal_SetQoSConfiguration(&queue, 1, NULL, "erouter0");

    UT_LOG_DEBUG("Invoking wan_hal_SetQoSConfiguration with valid pQueue, QueueNumberOfEntries = 1, baseifname = NULL and valid wanifname\n");
    UT_ASSERT_EQUAL(status, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the function wan_hal_SetQoSConfiguration
 *
 * In this test, the function wan_hal_SetQoSConfiguration is invoked with valid queue, QueueNumberOfEntries set to 1, valid baseifname and wanifname set to NULL. The test is designed to verify the robustness of the function when it is invoked with NULL wanifname.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 022@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_SetQoSConfiguration with valid queue, QueueNumberOfEntries set to 1, valid baseifname and wanifname set to NULL | queue = valid, QueueNumberOfEntries = 1, baseifname = "erouter0", wanifname = NULL | The function should return RETURN_ERROR | The function is expected to handle NULL wanifname gracefully |
 */

void test_l1_wan_hal_negative4_SetQoSConfiguration(void)
{
    gTestID = 22;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int status = wan_hal_SetQoSConfiguration(&queue, 1, "erouter0", NULL);

    UT_LOG_DEBUG("Invoking wan_hal_SetQoSConfiguration with valid pQueue, QueueNumberOfEntries = 1, valid baseifname and wanifname = NULL\n");
    UT_ASSERT_EQUAL(status, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the function wan_hal_SetQoSConfiguration
 *
 * In this test, the function wan_hal_SetQoSConfiguration is invoked with valid parameters but expecting a negative scenario. The objective is to ensure the function handles error conditions correctly.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 023@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_SetQoSConfiguration with valid parameters but expecting a negative scenario | pQueue = valid, QueueNumberOfEntries = 1, baseifname = "", wanifname = "erouter0" | The function should return RETURN_ERROR | The function should handle error conditions correctly |
 */

void test_l1_wan_hal_negative5_SetQoSConfiguration(void)
{
    gTestID = 23;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    // Initialize queue with valid values
    int status = wan_hal_SetQoSConfiguration(&queue, 1, "", "erouter0");

    UT_LOG_DEBUG("Invoking wan_hal_SetQoSConfiguration with valid pQueue, QueueNumberOfEntries = 1, baseifname = "
                 " and valid wanifname\n");
    UT_ASSERT_EQUAL(status, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the function wan_hal_SetQoSConfiguration
 *
 * In this test, the function wan_hal_SetQoSConfiguration is invoked with valid parameters but expecting a negative scenario. The objective is to ensure the function handles error conditions correctly.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 024@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_SetQoSConfiguration with valid parameters but expecting a negative scenario | pQueue = valid, QueueNumberOfEntries = 1, baseifname = "erouter0", wanifname = "" | The function should return RETURN_ERROR | The function should handle error conditions correctly |
 */

void test_l1_wan_hal_negative6_SetQoSConfiguration(void)
{
    gTestID = 24;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int status = wan_hal_SetQoSConfiguration(&queue, 1, "erouter0", "");

    UT_LOG_DEBUG("Invoking wan_hal_SetQoSConfiguration with valid pQueue, QueueNumberOfEntries = 1, valid baseifname and wanifname = "
                 "\n");
    UT_ASSERT_EQUAL(status, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test verifies the functionality of the wan_hal_ConfigureIpv4 API with valid parameters
 *
 * In this test, the wan_hal_ConfigureIpv4 API is invoked with a valid WAN_IPV4_CFG structure. The test verifies that the API returns the expected result when invoked with valid parameters.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 025@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_ConfigureIpv4 with valid parameters | ifname = "erouter0", subnetmask = "255.255.255.0", ipaddress = "192.168.0.1", dnsservers = "8.8.8.8\n8.8.4.4", defaultgateway = "192.168.0.254" | The return value should be RETURN_OK | The test should pass |
 */

void test_l1_wan_hal_positive1_ConfigureIpv4(void)
{
    gTestID = 25;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV4_CFG cfg = {
        .ifname = "erouter0",
        .subnetmask = "255.255.255.0",
        .ipaddress = "192.168.0.1",
        .dnsservers = "8.8.8.8\n8.8.4.4",
        .defaultgateway = "192.168.0.254"};

    int ret = wan_hal_ConfigureIpv4(&cfg);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_ConfigureIpv4 function when passed a NULL parameter
 *
 * In this test, the wan_hal_ConfigureIpv4 function is invoked with a NULL parameter. The objective is to ensure that the function handles this scenario correctly and returns an error.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 026@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_ConfigureIpv4 with NULL parameter | NULL | The function should return an error | The function should handle NULL parameter correctly |
 */

void test_l1_wan_hal_negative1_ConfigureIpv4(void)
{
    gTestID = 26;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    UT_LOG_DEBUG("Invoking wan_hal_ConfigureIpv4 with NULL parameter");
    int ret = wan_hal_ConfigureIpv4(NULL);
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the behavior of the wan_hal_ConfigureIpv4 API when invoked with an empty interface name.
 *
 * This test case is designed to validate the negative scenario where the wan_hal_ConfigureIpv4 API is invoked with an empty interface name. The API is expected to return an error in this case.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 027@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_ConfigureIpv4 API with an empty interface name | ifname = "", subnetmask = "255.255.255.0", ipaddress = "192.168.0.1", dnsservers = "8.8.8.8\n8.8.4.4", defaultgateway = "192.168.0.254" | The API should return an error | The API is expected to handle this scenario gracefully and return an error |
 */

void test_l1_wan_hal_negative2_ConfigureIpv4(void)
{
    gTestID = 27;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV4_CFG cfg = {
        .ifname = "",
        .subnetmask = "255.255.255.0",
        .ipaddress = "192.168.0.1",
        .dnsservers = "8.8.8.8\n8.8.4.4",
        .defaultgateway = "192.168.0.254"};

    int ret = wan_hal_ConfigureIpv4(&cfg);
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is to verify the functionality of the wan_hal_UnConfigureIpv4 API when invoked with valid parameters.
 *
 * In this test, the wan_hal_UnConfigureIpv4 API is invoked with a valid WAN_IPV4_CFG structure. The objective is to ensure that the API behaves as expected when invoked with valid parameters.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 028@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_UnConfigureIpv4 API with a valid WAN_IPV4_CFG structure | cfg = {"erouter0", "255.255.255.0", "192.168.0.1", "8.8.8.8\n8.8.4.4", "192.168.0.254"} | The return value should be RETURN_OK | The test should pass if the API behaves as expected with valid parameters |
 */
void test_l1_wan_hal_positive1_UnConfigureIpv4(void)
{
    gTestID = 28;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV4_CFG cfg = {
        .ifname = "erouter0",
        .subnetmask = "255.255.255.0",
        .ipaddress = "192.168.0.1",
        .dnsservers = "8.8.8.8\n8.8.4.4",
        .defaultgateway = "192.168.0.254"};

    int ret = wan_hal_UnConfigureIpv4(&cfg);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the positive scenario of the function wan_hal_UnConfigureIpv4
 *
 * In this test, we are testing the scenario where the function wan_hal_UnConfigureIpv4 is invoked with a WAN_IPV4_CFG structure having only ifname field filled. The function is expected to return RETURN_OK in this case.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 029@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the function wan_hal_UnConfigureIpv4 with a WAN_IPV4_CFG structure having only ifname field filled | ifname = "erouter0", remaining fields are empty | The function should return RETURN_OK | The function is expected to handle this scenario successfully |
 */

void test_l1_wan_hal_positive2_UnConfigureIpv4(void)
{
    gTestID = 29;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV4_CFG cfg = {"erouter0", "", "", "", ""};
    int ret = wan_hal_UnConfigureIpv4(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_UnConfigureIpv4 with WAN_IPV4_CFG structure having only ifname field filled");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_UnConfigureIpv4 function when passed a NULL pointer
 *
 * This test is important to ensure that the function can handle incorrect or unexpected input and return the appropriate error code. This is a basic level test.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 030@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_UnConfigureIpv4 with NULL pointer | NULL | RETURN_ERROR | Should return error |
 */

void test_l1_wan_hal_negative1_UnConfigureIpv4(void)
{
    gTestID = 30;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = wan_hal_UnConfigureIpv4(NULL);

    UT_LOG_DEBUG("Invoking wan_hal_UnConfigureIpv4 with NULL pointer");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_UnConfigureIpv4 API when provided with invalid input.
 *
 * In this test, the wan_hal_UnConfigureIpv4 API is invoked with an invalid interface name. The objective is to ensure that the API handles erroneous input gracefully and returns the appropriate error code.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 031@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_UnConfigureIpv4 API with an invalid interface name | ifname = "invalid_ifname", netmask = "255.255.255.0", gateway = "192.168.0.1", dns = "8.8.8.8\n8.8.4.4", bcast = "192.168.0.254" | The API should return an error code | The API should handle erroneous input gracefully |
 */

void test_l1_wan_hal_negative2_UnConfigureIpv4(void)
{
    gTestID = 31;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV4_CFG cfg = {
        .ifname = "123@abc",
        .subnetmask = "255.255.255.0",
        .ipaddress = "192.168.0.1",
        .dnsservers = "8.8.8.8\n8.8.4.4",
        .defaultgateway = "192.168.0.254"};

    int ret = wan_hal_UnConfigureIpv4(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_UnConfigureIpv4 with invalid ifname field");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the wan_hal_UnConfigureIpv4 API when invoked with an empty ifname field.
 *
 * In this test, the wan_hal_UnConfigureIpv4 API is invoked with an empty ifname field in the WAN_IPV4_CFG structure. The API is expected to return an error in this scenario.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 032@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_UnConfigureIpv4 API with an empty ifname field in the WAN_IPV4_CFG structure | ifname = "", netmask = "255.255.255.0", gateway = "192.168.0.1", dns = "8.8.8.8\n8.8.4.4", bcast = "192.168.0.254" | The API should return an error | The test is expected to fail because the ifname field is empty |
 */

void test_l1_wan_hal_negative3_UnConfigureIpv4(void)
{
    gTestID = 32;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV4_CFG cfg = {"", "255.255.255.0", "192.168.0.1", "8.8.8.8\n8.8.4.4", "192.168.0.254"};
    int ret = wan_hal_UnConfigureIpv4(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_UnConfigureIpv4 with empty ifname field");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_UnConfigureIpv4 API when invoked with invalid parameters.
 *
 * In this test, the wan_hal_UnConfigureIpv4 API is invoked with a configuration structure filled with invalid values. The objective is to ensure that the API handles erroneous input gracefully and returns the appropriate error code.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 033@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_UnConfigureIpv4 with invalid parameters | cfg = {"erouter0", "invalid_subnetmask", "invalid_ipaddress", "invalid_dnsservers", "invalid_defaultgateway"} | The return value should be RETURN_ERROR | The API should handle invalid input gracefully and return an error code |
 */

void test_l1_wan_hal_negative4_UnConfigureIpv4(void)
{
    gTestID = 33;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV4_CFG cfg = {"erouter0", "222@2", "222@2", "222@2", "222@2"};

    int ret = wan_hal_UnConfigureIpv4(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_UnConfigureIpv4 with invalid fields");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test verifies the functionality of the wan_hal_ConfigureIpv6 API with valid parameters
 *
 * In this test, the wan_hal_ConfigureIpv6 API is invoked with a valid WAN_IPV6_CFG structure. The test verifies that the API returns the expected result when invoked with valid parameters.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 034@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_ConfigureIpv6 API with a valid WAN_IPV6_CFG structure | cfg = {"erouter0", "2001:db8::1", "2001:db8::2\n2001:db8::3", 3600, 7200} | The API should return RETURN_OK | The test should pass |
 */

void test_l1_wan_hal_positive1_ConfigureIpv6(void)
{
    gTestID = 34;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"erouter0", "2001:db8::1", "2001:db8::2\n2001:db8::3", 3600, 7200}; // values from profile
    int ret = wan_hal_ConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_ConfigureIpv6 with valid parameters\n");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the wan_hal_ConfigureIpv6 API when invoked with a non-existent interface.
 *
 * In this test, the wan_hal_ConfigureIpv6 API is invoked with a non-existent interface. The objective is to ensure that the API handles this error condition correctly and returns an appropriate error code.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 035@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_ConfigureIpv6 API with a non-existent interface | cfg = {"nonexistent", "2001:db8::1", "2001:db8::2\n2001:db8::3", 3600, 7200} | The API should return an error code | The test should be successful |
 */

void test_l1_wan_hal_negative1_ConfigureIpv6(void)
{
    gTestID = 35;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"123@abc", "2001:db8::1", "2001:db8::2\n2001:db8::3", 3600, 7200};
    int ret = wan_hal_ConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_ConfigureIpv6 with non-existent interface\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the behavior of the wan_hal_ConfigureIpv6 API when provided with an invalid IPv6 address.
 *
 * In this test, the wan_hal_ConfigureIpv6 API is invoked with an invalid IPv6 address to ensure that the API correctly handles this erroneous input and returns the expected error code.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 036@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_ConfigureIpv6 API with an invalid IPv6 address | cfg = {"erouter0", "invalid", "2001:db8::2\n2001:db8::3", 3600, 7200} | The API should return an error code | The test should be successful |
 */

void test_l1_wan_hal_negative2_ConfigureIpv6(void)
{
    gTestID = 36;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"erouter0", "10.0.30@21", "2001:db8::2\n2001:db8::3", 3600, 7200};
    int ret = wan_hal_ConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_ConfigureIpv6 with invalid IPv6 address\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the behavior of the wan_hal_ConfigureIpv6 API when provided with an invalid DNS server address.
 *
 * In this test, the wan_hal_ConfigureIpv6 API is invoked with a configuration where the DNS server address is invalid. The objective is to ensure that the API handles this erroneous input gracefully and returns an error code.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 037@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_ConfigureIpv6 with invalid DNS server address | cfg = {"erouter0", "2001:db8::1", "invalid\n2001:db8::3", 3600, 7200} | The return value should be RETURN_ERROR | The API should handle the erroneous input gracefully and return an error code |
 */

void test_l1_wan_hal_negative3_ConfigureIpv6(void)
{
    gTestID = 37;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"erouter0", "2001:db8::1", "123@abc\n2001:db8::3", 3600, 7200};
    int ret = wan_hal_ConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_ConfigureIpv6 with invalid DNS server address\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_ConfigureIpv6 function when passed a NULL parameter
 *
 * In this test, the wan_hal_ConfigureIpv6 function is invoked with a NULL parameter. The objective is to ensure that the function handles this edge case correctly and returns an error.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 038@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_ConfigureIpv6 with NULL parameter | parameter = NULL | The function should return an error | The function should handle this edge case correctly |
 */

void test_l1_wan_hal_negative4_ConfigureIpv6(void)
{
    gTestID = 38;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = wan_hal_ConfigureIpv6(NULL);

    UT_LOG_DEBUG("Invoking wan_hal_ConfigureIpv6 with NULL parameter\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the wan_hal_ConfigureIpv6 API when invoked with an empty interface name.
 *
 * In this test, the wan_hal_ConfigureIpv6 API is invoked with an empty interface name. The API is expected to return an error in this scenario.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 039@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_ConfigureIpv6 API with an empty interface name | interface name = "", ipv6_addr = "2001:db8::1", ipv6_prefix = "2001:db8::2\n2001:db8::3", ipv6_lease_time = 3600, ipv6_renew_time = 7200 | The API should return an error | The API is expected to handle the scenario gracefully and return an error |
 */

void test_l1_wan_hal_negative5_ConfigureIpv6(void)
{
    gTestID = 39;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"", "2001:db8::1", "2001:db8::2\n2001:db8::3", 3600, 7200};
    int ret = wan_hal_ConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_ConfigureIpv6 with empty interface name\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the behavior of the wan_hal_ConfigureIpv6 API when invoked with an empty DNS servers list.
 *
 * In this test, the wan_hal_ConfigureIpv6 API is invoked with a configuration where the DNS servers list is empty. The objective is to ensure that the API returns an error in such a scenario.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 040@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_ConfigureIpv6 with a configuration where the DNS servers list is empty | cfg = {"erouter0", "2001:db8::1", "", 3600, 7200} | The API should return an error | The API is expected to handle this scenario gracefully and return an error |
 */

void test_l1_wan_hal_negative6_ConfigureIpv6(void)
{
    gTestID = 40;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"erouter0", "2001:db8::1", "", 3600, 7200};
    int ret = wan_hal_ConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_ConfigureIpv6 with empty DNS servers list\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the behavior of the wan_hal_ConfigureIpv6 API when invoked with negative preferredlifetime.
 *
 * In this test, the wan_hal_ConfigureIpv6 API is invoked with a negative preferredlifetime value to ensure that the API handles such erroneous input correctly.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 041@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_ConfigureIpv6 with negative preferredlifetime | interface = "erouter0", ipv6_addr = "2001:db8::1", ipv6_prefix = "2001:db8::2\n2001:db8::3", preferred_lifetime = -3600, valid_lifetime = 7200 | The return value should be RETURN_ERROR | The API should handle erroneous input correctly |
 */

void test_l1_wan_hal_negative7_ConfigureIpv6(void)
{
    gTestID = 41;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"erouter0", "2001:db8::1", "2001:db8::2\n2001:db8::3", -3600, 7200};
    int ret = wan_hal_ConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_ConfigureIpv6 with negative preferredlifetime\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the behavior of the wan_hal_ConfigureIpv6 API when invoked with negative validlifetime.
 *
 * In this test, the wan_hal_ConfigureIpv6 API is invoked with a negative validlifetime to ensure that the API handles this scenario correctly and returns an error.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 042@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_ConfigureIpv6 API with negative validlifetime | cfg = {"erouter0", "2001:db8::1", "2001:db8::2\n2001:db8::3", 3600, -7200} | The API should return an error | The API should handle this scenario correctly and return an error |
 */

void test_l1_wan_hal_negative8_ConfigureIpv6(void)
{
    gTestID = 42;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"erouter0", "2001:db8::1", "2001:db8::2\n2001:db8::3", 3600, -7200};
    int ret = wan_hal_ConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_ConfigureIpv6 with negative validlifetime\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is to verify the functionality of the wan_hal_UnConfigureIpv6 API when invoked with valid parameters.
 *
 * This test case is designed to test the positive scenario of the wan_hal_UnConfigureIpv6 API. The API is invoked with a valid WAN_IPV6_CFG structure and the return value is checked to be RETURN_OK.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 043@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_UnConfigureIpv6 API with a valid WAN_IPV6_CFG structure | cfg = {"erouter0", "2001:db8::1", "2001:db8::2\n2001:db8::3", 3600, 7200} | The return value should be RETURN_OK | The test should pass |
 */

void test_l1_wan_hal_positive1_UnConfigureIpv6(void)
{
    gTestID = 43;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"erouter0", "2001:db8::1", "2001:db8::2\n2001:db8::3", 3600, 7200};
    int ret = wan_hal_UnConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_UnConfigureIpv6 with valid pWanIpv6Cfg");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_UnConfigureIpv6 function when passed a NULL argument.
 *
 * This test is important to ensure that the function can handle incorrect or unexpected input gracefully and return an appropriate error code. This is a basic level test.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 044@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_UnConfigureIpv6 with NULL argument | pWanIpv6Cfg = NULL | The function should return an error code | The function should handle the NULL input gracefully |
 */

void test_l1_wan_hal_negative1_UnConfigureIpv6(void)
{
    gTestID = 44;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = wan_hal_UnConfigureIpv6(NULL);

    UT_LOG_DEBUG("Invoking wan_hal_UnConfigureIpv6 with NULL pWanIpv6Cfg");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the negative scenario of the wan_hal_UnConfigureIpv6 API when invoked with an empty interface name.
 *
 * In this test, the wan_hal_UnConfigureIpv6 API is invoked with an empty interface name. The API is expected to return an error in this scenario. This test is important to ensure that the API handles invalid inputs gracefully.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 045@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_UnConfigureIpv6 API with empty interface name | ifname = "", ipv6_addr = "2001:db8::1", ipv6_prefix = "2001:db8::2\n2001:db8::3", valid_lifetime = 3600, preferred_lifetime = 7200 | The API should return an error | The API should handle invalid inputs gracefully |
 */

void test_l1_wan_hal_negative2_UnConfigureIpv6(void)
{
    gTestID = 45;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"", "2001:db8::1", "2001:db8::2\n2001:db8::3", 3600, 7200};
    int ret = wan_hal_UnConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_UnConfigureIpv6 with empty ifname");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the negative scenario of the wan_hal_UnConfigureIpv6 API when invoked with empty ipaddress
 *
 * In this test, the wan_hal_UnConfigureIpv6 API is invoked with an empty ipaddress to check if the API is able to handle this negative scenario and return an error as expected.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 046@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_UnConfigureIpv6 API with empty ipaddress | cfg = {"erouter0", "", "2001:db8::2\n2001:db8::3", 3600, 7200} | The API should return an error | The API should be able to handle this negative scenario and return an error as expected |
 */

void test_l1_wan_hal_negative3_UnConfigureIpv6(void)
{
    gTestID = 46;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"erouter0", "", "2001:db8::2\n2001:db8::3", 3600, 7200};
    int ret = wan_hal_UnConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_UnConfigureIpv6 with empty ipaddress");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_UnConfigureIpv6 function when invoked with empty dnsservers.
 *
 * In this test, we are checking if the wan_hal_UnConfigureIpv6 function returns an error when invoked with empty dnsservers. This is important to ensure that the function handles invalid input correctly.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 047@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_UnConfigureIpv6 with empty dnsservers | cfg = {"erouter0", "2001:db8::1", "", 3600, 7200} | The function should return an error | The function should handle invalid input correctly |
 */

void test_l1_wan_hal_negative4_UnConfigureIpv6(void)
{
    gTestID = 47;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"erouter0", "2001:db8::1", "", 3600, 7200};
    int ret = wan_hal_UnConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_UnConfigureIpv6 with empty dnsservers");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_UnConfigureIpv6 API when invoked with negative preferredlifetime.
 *
 * In this test, the wan_hal_UnConfigureIpv6 API is invoked with a negative preferredlifetime to ensure that the API handles this edge case correctly.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 048@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_UnConfigureIpv6 with negative preferredlifetime | cfg = {"erouter0", "2001:db8::1", "2001:db8::2\n2001:db8::3", -1, 7200} | The return value should be RETURN_ERROR | The API should handle this edge case correctly |
 */

void test_l1_wan_hal_negative5_UnConfigureIpv6(void)
{
    gTestID = 48;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"erouter0", "2001:db8::1", "2001:db8::2\n2001:db8::3", -1, 7200};
    int ret = wan_hal_UnConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_UnConfigureIpv6 with negative preferredlifetime");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_UnConfigureIpv6 function when invoked with negative validlifetime.
 *
 * In this test, the wan_hal_UnConfigureIpv6 function is invoked with a negative validlifetime to test its robustness and error handling capabilities.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 049@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_UnConfigureIpv6 with negative validlifetime | cfg = {"erouter0", "2001:db8::1", "2001:db8::2\n2001:db8::3", 3600, -1} | The function should return an error | The function should handle the negative validlifetime gracefully |
 */

void test_l1_wan_hal_negative6_UnConfigureIpv6(void)
{
    gTestID = 49;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"erouter0", "2001:db8::1", "2001:db8::2\n2001:db8::3", 3600, -1};
    int ret = wan_hal_UnConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_UnConfigureIpv6 with negative validlifetime");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_UnConfigureIpv6 function when provided with an invalid IP address format.
 *
 * In this test, the wan_hal_UnConfigureIpv6 function is invoked with an invalid IP address format to check if the function can handle such erroneous inputs and return the appropriate error code.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 050@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_UnConfigureIpv6 function with an invalid IP address format | cfg = {"erouter0", "2001:db8::1g", "2001:db8::2\n2001:db8::3", 3600, 7200} | The function should return an error code indicating that the IP address format is invalid | The function should be able to handle erroneous inputs and return the appropriate error code |
 */

void test_l1_wan_hal_negative7_UnConfigureIpv6(void)
{
    gTestID = 50;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"erouter0", "2001:db8::1@", "2001:db8::2\n2001:db8::3", 3600, 7200};
    int ret = wan_hal_UnConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_UnConfigureIpv6 with invalid ipaddress format");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the wan_hal_UnConfigureIpv6 API when invoked with invalid dnsservers format.
 *
 * In this test, the wan_hal_UnConfigureIpv6 API is invoked with an invalid dnsservers format in the WAN_IPV6_CFG structure. The API is expected to return an error.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 051@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_UnConfigureIpv6 API with invalid dnsservers format in the WAN_IPV6_CFG structure | cfg = {"erouter0", "2001:db8::1", "2001:db8::22001:db8::3", 3600, 7200} | The API should return an error | The test is expected to fail |
 */

void test_l1_wan_hal_negative8_UnConfigureIpv6(void)
{
    gTestID = 51;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"erouter0", "2001:db8::1", "2001:db8::22001:db8::3", 3600, 7200};
    int ret = wan_hal_UnConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_UnConfigureIpv6 with invalid dnsservers format");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is to verify the functionality of the wan_hal_UnConfigureIpv6 API when invoked with zero preferredlifetime and validlifetime.
 *
 * This test case is designed to test the positive scenario of the wan_hal_UnConfigureIpv6 API. The API is invoked with a valid WAN_IPV6_CFG structure where preferredlifetime and validlifetime are set to zero. The test verifies if the API is able to handle this scenario and returns the expected result.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 052@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the wan_hal_UnConfigureIpv6 API with a valid WAN_IPV6_CFG structure where preferredlifetime and validlifetime are set to zero | cfg = {"erouter0", "2001:db8::1", "2001:db8::2\n2001:db8::3", 0, 0} | The API should return RETURN_OK | The test should pass |
 */

void test_l1_wan_hal_positive2_UnConfigureIpv6(void)
{
    gTestID = 52;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    WAN_IPV6_CFG cfg = {"erouter0", "2001:db8::1", "2001:db8::2\n2001:db8::3", 0, 0};
    int ret = wan_hal_UnConfigureIpv6(&cfg);

    UT_LOG_DEBUG("Invoking wan_hal_UnConfigureIpv6 with zero preferredlifetime and validlifetime");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test verifies the functionality of the wan_hal_EnableMapt API when invoked with valid parameters
 *
 * In this test, the wan_hal_EnableMapt API is invoked with a valid WAN_MAPT_CFG structure. The test verifies that the API returns the expected return code when invoked with valid parameters.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 053@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_EnableMapt API with valid parameters | maptCfg = {"erouter0", "2000::", "1.0.0.0", "2000::", psidOffset, ratio, "2001:0db8:85a3::/64"} | The return value should be RETURN_OK | The test should pass |
 */

void test_l1_wan_hal_positive1_EnableMapt(void)
{
    gTestID = 53;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    unsigned int ratio;
    unsigned int psidOffset;
    psidOffset = UT_KVP_PROFILE_GET_UINT32("wan.config.psidOffset");
    ratio = UT_KVP_PROFILE_GET_UINT32("wan.config.ratio");

    WAN_MAPT_CFG maptCfg = {"erouter0", "2000::", "1.0.0.0", "2000::", psidOffset, ratio, "2001:0db8:85a3::/64"}; // vendor specific ratio second last and psid offset
    int ret = wan_hal_EnableMapt(&maptCfg);

    UT_LOG_DEBUG("Invoking wan_hal_EnableMapt with valid parameters\n");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the negative scenario of the wan_hal_EnableMapt API when invoked with NULL parameter
 *
 * In this test, the wan_hal_EnableMapt API is invoked with NULL parameter. The API is expected to return an error. This test is important to ensure that the API handles invalid inputs gracefully.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 054@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_EnableMapt API with NULL parameter | NULL | API should return an error | Should be successful |
 */

void test_l1_wan_hal_negative1_EnableMapt(void)
{
    gTestID = 54;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = wan_hal_EnableMapt(NULL);

    UT_LOG_DEBUG("Invoking wan_hal_EnableMapt with NULL parameter\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the negative scenario of enabling MAPT in L1 WAN HAL
 *
 * In this test, the function wan_hal_EnableMapt is invoked with an empty interface name to check if the function handles the error correctly.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 055@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_EnableMapt with empty ifName | ifName = "", ipv6Prefix = "2000::", ipv4Addr = "1.0.0.0", ipv6Addr = "2000::", psidOffset, ratio, maptIPv6Prefix = "2001:0db8:85a3::/64" | The return value should be RETURN_ERROR | The function should handle the error correctly |
 */

void test_l1_wan_hal_negative2_EnableMapt(void)
{
    gTestID = 55;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned int ratio;
    unsigned int psidOffset;
    psidOffset = UT_KVP_PROFILE_GET_UINT32("wan.config.psidOffset");
    ratio = UT_KVP_PROFILE_GET_UINT32("wan.config.ratio");

    WAN_MAPT_CFG maptCfg = {"", "2000::", "1.0.0.0", "2000::", psidOffset, ratio, "2001:0db8:85a3::/64"};
    int ret = wan_hal_EnableMapt(&maptCfg);

    UT_LOG_DEBUG("Invoking wan_hal_EnableMapt with empty ifName\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the function wan_hal_EnableMapt
 *
 * In this test, the function wan_hal_EnableMapt is invoked with an invalid brIPv6Prefix to ensure that the function handles error conditions correctly.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 056@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the function wan_hal_EnableMapt with invalid brIPv6Prefix | brIPv6Prefix = "4000::", brIPv4Addr = "1.0.0.0", brIPv6Addr = "2000::", psidOffset, ratio, maptIPv6Prefix = "2001:0db8:85a3::/64" | The return value should be RETURN_ERROR | The function should handle the error condition correctly |
 */

void test_l1_wan_hal_negative3_EnableMapt(void)
{
    gTestID = 56;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned int ratio;
    unsigned int psidOffset;
    psidOffset = UT_KVP_PROFILE_GET_UINT32("wan.config.psidOffset");
    ratio = UT_KVP_PROFILE_GET_UINT32("wan.config.ratio");

    WAN_MAPT_CFG maptCfg = {"erouter0", "4000::", "1.0.0.0", "2000::", psidOffset, ratio, "2001:0db8:85a3::/64"};
    int ret = wan_hal_EnableMapt(&maptCfg);

    UT_LOG_DEBUG("Invoking wan_hal_EnableMapt with invalid brIPv6Prefix\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_EnableMapt function when provided with invalid ruleIPv4Prefix.
 *
 * In this test, the wan_hal_EnableMapt function is invoked with an invalid ruleIPv4Prefix to ensure that the function handles the error correctly.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 057@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_EnableMapt with invalid ruleIPv4Prefix | maptCfg = {"erouter0", "2000::", "0.0.0.0", "2000::", psidOffset, ratio, "2001:0db8:85a3::/64"} | The return value should be RETURN_ERROR | The function should handle the error correctly |
 */

void test_l1_wan_hal_negative4_EnableMapt(void)
{
    gTestID = 57;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    unsigned int ratio;
    unsigned int psidOffset;
    psidOffset = UT_KVP_PROFILE_GET_UINT32("wan.config.psidOffset");
    ratio = UT_KVP_PROFILE_GET_UINT32("wan.config.ratio");

    WAN_MAPT_CFG maptCfg = {"erouter0", "2000::", "0.0.0.0", "2000::", psidOffset, ratio, "2001:0db8:85a3::/64"};
    int ret = wan_hal_EnableMapt(&maptCfg);

    UT_LOG_DEBUG("Invoking wan_hal_EnableMapt with invalid ruleIPv4Prefix\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the function wan_hal_EnableMapt
 *
 * In this test, the function wan_hal_EnableMapt is invoked with an invalid ruleIPv6Prefix to ensure that the function handles error conditions correctly.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 058@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the function wan_hal_EnableMapt with invalid ruleIPv6Prefix | maptCfg = {"erouter0", "2000::", "1.0.0.0", "4000::", psidOffset, ratio, "2001:0db8:85a3::/64"} | The function should return RETURN_ERROR | The function should handle the error condition correctly |
 */

void test_l1_wan_hal_negative5_EnableMapt(void)
{
    gTestID = 58;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned int ratio;
    unsigned int psidOffset;
    psidOffset = UT_KVP_PROFILE_GET_UINT32("wan.config.psidOffset");
    ratio = UT_KVP_PROFILE_GET_UINT32("wan.config.ratio");

    WAN_MAPT_CFG maptCfg = {"erouter0", "2000::", "1.0.0.0", "4000::", psidOffset, ratio, "2001:0db8:85a3::/64"};
    int ret = wan_hal_EnableMapt(&maptCfg);

    UT_LOG_DEBUG("Invoking wan_hal_EnableMapt with invalid ruleIPv6Prefix\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the wan_hal_EnableMapt API when invoked with invalid psidOffset.
 *
 * In this test, the wan_hal_EnableMapt API is invoked with an invalid psidOffset in the MAPT configuration. The API is expected to return an error.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 059@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_EnableMapt API with invalid psidOffset in the MAPT configuration | maptCfg = {"erouter0", "2000::", "1.0.0.0", "2000::", psidOffset, ratio, "2001:0db8:85a3::/64"} | The API should return an error | The test is expected to fail |
 */

void test_l1_wan_hal_negative6_EnableMapt(void)
{
    gTestID = 59;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned int ratio;
    unsigned int psidOffset = 16;
    ratio = UT_KVP_PROFILE_GET_UINT32("wan.config.ratio");

    WAN_MAPT_CFG maptCfg = {"erouter0", "2000::", "1.0.0.0", "2000::", psidOffset, ratio, "2001:0db8:85a3::/64"};
    int ret = wan_hal_EnableMapt(&maptCfg);

    UT_LOG_DEBUG("Invoking wan_hal_EnableMapt with invalid psidOffset\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the wan_hal_EnableMapt API when invoked with invalid ratio.
 *
 * In this test, the wan_hal_EnableMapt API is invoked with an invalid ratio in the MAPT configuration. The API is expected to return an error.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 060@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_EnableMapt API with invalid ratio in the MAPT configuration | maptCfg = {"erouter0", "2000::", "1.0.0.0", "2000::", 0, 65537, "2001:0db8:85a3::/64"} | The API should return an error | The test is expected to be successful |
 */

void test_l1_wan_hal_negative7_EnableMapt(void)
{
    gTestID = 60;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    unsigned int ratio = 65537;
    unsigned int psidOffset;
    psidOffset = UT_KVP_PROFILE_GET_UINT32("wan.config.psidOffset");

    WAN_MAPT_CFG maptCfg = {"erouter0", "2000::", "1.0.0.0", "2000::", psidOffset, ratio, "2001:0db8:85a3::/64"};
    int ret = wan_hal_EnableMapt(&maptCfg);

    UT_LOG_DEBUG("Invoking wan_hal_EnableMapt with invalid ratio\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the function wan_hal_EnableMapt
 *
 * In this test, the function wan_hal_EnableMapt is invoked with invalid pdIPv6Prefix to ensure that the function handles error conditions correctly.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 061@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the function wan_hal_EnableMapt with invalid pdIPv6Prefix | maptCfg = {"erouter0", "2000::", "1.0.0.0", "2000::", 0, 1, "4000::"} | The return value should be RETURN_ERROR | The function should handle the error condition correctly |
 */

void test_l1_wan_hal_negative8_EnableMapt(void)
{
    gTestID = 61;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned int ratio;
    unsigned int psidOffset;
    psidOffset = UT_KVP_PROFILE_GET_UINT32("wan.config.psidOffset");
    ratio = UT_KVP_PROFILE_GET_UINT32("wan.config.ratio");

    WAN_MAPT_CFG maptCfg = {"erouter0", "2000::", "1.0.0.0", "2000::", psidOffset, ratio, "4000::"};
    int ret = wan_hal_EnableMapt(&maptCfg);

    UT_LOG_DEBUG("Invoking wan_hal_EnableMapt with invalid pdIPv6Prefix\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is to verify the functionality of the wan_hal_DisableMapt API when invoked with a valid interface name
 *
 * In this test, the wan_hal_DisableMapt API is invoked with a valid interface name and the return value is checked to be RETURN_OK. This is to ensure that the API is able to correctly disable MAP-T on the given interface.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 062@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_DisableMapt API with valid interface name | ifName = erouter0 | The return value should be RETURN_OK | The test should pass |
 */

void test_l1_wan_hal_positive1_DisableMapt(void)
{
    gTestID = 62;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    const char *ifName = "erouter0";
    int ret = wan_hal_DisableMapt(ifName);

    UT_LOG_DEBUG("Invoking wan_hal_DisableMapt with valid interface name: %s\n", ifName);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_DisableMapt function when provided with an invalid interface name.
 *
 * In this test, the wan_hal_DisableMapt function is invoked with an invalid interface name to ensure that the function handles such scenarios correctly and returns the appropriate error code.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 063@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_DisableMapt with invalid interface name | ifName = invalidInterface | The function should return RETURN_ERROR | The function should handle invalid inputs gracefully |
 */

void test_l1_wan_hal_negative1_DisableMapt(void)
{
    gTestID = 63;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    const char *ifName = "123@abc";
    int ret = wan_hal_DisableMapt(ifName);

    UT_LOG_DEBUG("Invoking wan_hal_DisableMapt with invalid interface name: %s\n", ifName);
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_DisableMapt function when passed a NULL interface name
 *
 * In this test, the wan_hal_DisableMapt function is invoked with a NULL interface name. The objective is to ensure that the function handles this edge case correctly and returns an error.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 064@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_DisableMapt with NULL interface name | ifName = NULL | The function should return an error | The function should handle this edge case correctly |
 */

void test_l1_wan_hal_negative2_DisableMapt(void)
{
    gTestID = 64;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    const char *ifName = NULL;
    int ret = wan_hal_DisableMapt(ifName);

    UT_LOG_DEBUG("Invoking wan_hal_DisableMapt with NULL interface name\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_DisableMapt function when provided with an empty interface name.
 *
 * In this test, the wan_hal_DisableMapt function is invoked with an empty string as the interface name. The objective is to ensure that the function handles this edge case correctly and returns an error.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 065@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_DisableMapt with empty interface name | ifName = "" | The function should return an error | The function should handle this edge case correctly |
 */

void test_l1_wan_hal_negative3_DisableMapt(void)
{
    gTestID = 65;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    const char *ifName = "";
    int ret = wan_hal_DisableMapt(ifName);

    UT_LOG_DEBUG("Invoking wan_hal_DisableMapt with empty interface name\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is to verify the functionality of enabling WAN OEM mode
 *
 * This test case is designed to test the positive scenario of enabling the WAN OEM mode. The function wan_hal_enableWanOEMode is invoked with enable set to 1 and the return value is checked to be RETURN_OK.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 066@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke the function wan_hal_enableWanOEMode with enable set to 1 | enable = 1 | The return value should be RETURN_OK | Should be successful |
 */

void test_l1_wan_hal_positive1_enableWanOEMode(void)
{
    gTestID = 66;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int ret = wan_hal_enableWanOEMode(1);
    UT_LOG_DEBUG("Invoking wan_hal_enableWanOEMode with enable set to 1");
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test checks if the WAN OEM mode can be enabled successfully
 *
 * This test invokes the wan_hal_enableWanOEMode API with enable set to 0 and checks if the return value is RETURN_OK@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 067@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_enableWanOEMode API with enable set to 0 | enable = 0 | The return value should be RETURN_OK | Should be successful |
 */

void test_l1_wan_hal_positive2_enableWanOEMode(void)
{
    gTestID = 67;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int ret = wan_hal_enableWanOEMode(0);
    UT_LOG_DEBUG("Invoking wan_hal_enableWanOEMode with enable set to 0");
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the wan_hal_enableWanOEMode API
 *
 * This test case is designed to test the wan_hal_enableWanOEMode API when it is invoked with an invalid input. The API is expected to return an error in this scenario.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 068@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_enableWanOEMode API with invalid input | enable = 2 | The API should return an error | The API is expected to handle invalid inputs gracefully |
 */

void test_l1_wan_hal_negative1_enableWanOEMode(void)
{
    gTestID = 68;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int ret = wan_hal_enableWanOEMode(2);
    UT_LOG_DEBUG("Invoking wan_hal_enableWanOEMode with enable set to a value other than 0 or 1");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the positive scenario of the function wan_hal_getAuthInfo
 *
 * In this test, we are testing the wan_hal_getAuthInfo function with a valid buffer of size 256 bytes to ensure that it returns the expected output when provided with valid input.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 069@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_getAuthInfo with valid buffer of size 256 bytes | authInfo = valid buffer of size 256 bytes | The return value should be RETURN_OK | Should be successful |
 */

void test_l1_wan_hal_positive1_getAuthInfo(void)
{
    gTestID = 69;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char authInfo[256];
    int ret = wan_hal_getAuthInfo(authInfo);

    UT_LOG_DEBUG("Invoking wan_hal_getAuthInfo with valid buffer of size 256 bytes");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the positive scenario of the wan_hal_getAuthInfo API
 *
 * In this test, we are testing the wan_hal_getAuthInfo API with a valid buffer of size 16384 bytes. The objective is to ensure that the API is able to handle and return the correct authentication information when provided with valid input.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 070@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_getAuthInfo with valid buffer of size 16384 bytes | authInfo = valid buffer of size 16384 bytes | The return value should be RETURN_OK | The test should pass successfully |
 */

void test_l1_wan_hal_positive2_getAuthInfo(void)
{
    gTestID = 70;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char authInfo[16384];
    int ret = wan_hal_getAuthInfo(authInfo);

    UT_LOG_DEBUG("Invoking wan_hal_getAuthInfo with valid buffer of size 16384 bytes");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to check the behavior of the wan_hal_getAuthInfo API when invoked with NULL buffer
 *
 * This test invokes the wan_hal_getAuthInfo API with NULL buffer and expects it to return an error. This is to ensure that the API handles invalid input parameters gracefully.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 071@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_getAuthInfo API with NULL buffer | buffer = NULL | The API should return an error | The API should handle invalid input parameters gracefully |
 */

void test_l1_wan_hal_negative1_getAuthInfo(void)
{
    gTestID = 71;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = wan_hal_getAuthInfo(NULL);

    UT_LOG_DEBUG("Invoking wan_hal_getAuthInfo with NULL buffer");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the negative scenario of the wan_hal_getAuthInfo API when invoked with a valid buffer of size less than 256 bytes.
 *
 * In this test, the wan_hal_getAuthInfo API is invoked with a valid buffer of size less than 256 bytes. The API is expected to return an error. This test is important to ensure that the API handles invalid input parameters correctly.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 072@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_getAuthInfo API with a valid buffer of size less than 256 bytes | authInfo = valid buffer of size less than 256 bytes | The API should return an error | The API should handle invalid input parameters correctly |
 */

void test_l1_wan_hal_negative2_getAuthInfo(void)
{
    gTestID = 72;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char authInfo[255];
    int ret = wan_hal_getAuthInfo(authInfo);

    UT_LOG_DEBUG("Invoking wan_hal_getAuthInfo with valid buffer of size less than 256 bytes");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
 * @brief This test is designed to verify the behavior of the wan_hal_getAuthInfo API when invoked with a valid buffer of size more than 16384 bytes.
 *
 * In this test, the wan_hal_getAuthInfo API is invoked with a valid buffer of size more than 16384 bytes. The objective is to ensure that the API returns an error in such a scenario, as it is expected to handle buffers of size up to 16384 bytes only.@n
 *
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 073@n
 * **Priority:** High@n
 * @n
 * **Pre-Conditions:** None@n
 * **Dependencies:** None@n
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 * @n
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data |Expected Result |Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke wan_hal_getAuthInfo with a valid buffer of size more than 16384 bytes | authInfo[16385] | The API should return an error | The API is expected to handle buffers of size up to 16384 bytes only |
 */

void test_l1_wan_hal_negative3_getAuthInfo(void)
{
    gTestID = 73;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char authInfo[16385];
    int ret = wan_hal_getAuthInfo(authInfo);

    UT_LOG_DEBUG("Invoking wan_hal_getAuthInfo with valid buffer of size more than 16384 bytes");
    UT_ASSERT_EQUAL(ret, RETURN_ERROR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

static UT_test_suite_t *pSuite = NULL;

/**
 * @brief Register the main tests for this module
 *
 * @return int - 0 on success, otherwise failure
 */

int test_wan_hal_l1_register(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L1 wan_hal]", fetch_queue_data, NULL);
    if (pSuite == NULL)
    {
        return -1;
    }

    // Add tests to the suite

    UT_add_test(pSuite, "l1_wan_hal_positive1_Init", test_l1_wan_hal_positive1_Init);
    UT_add_test(pSuite, "l1_wan_hal_positive1_SetWanmode", test_l1_wan_hal_positive1_SetWanmode);
    UT_add_test(pSuite, "l1_wan_hal_positive2_SetWanmode", test_l1_wan_hal_positive2_SetWanmode);
    UT_add_test(pSuite, "l1_wan_hal_positive3_SetWanmode", test_l1_wan_hal_positive3_SetWanmode);
    UT_add_test(pSuite, "l1_wan_hal_positive4_SetWanmode", test_l1_wan_hal_positive4_SetWanmode);
    UT_add_test(pSuite, "l1_wan_hal_negative1_SetWanmode", test_l1_wan_hal_negative1_SetWanmode);
    UT_add_test(pSuite, "l1_wan_hal_positive1_SetWanConnectionEnable", test_l1_wan_hal_positive1_SetWanConnectionEnable);
    UT_add_test(pSuite, "l1_wan_hal_positive2_SetWanConnectionEnable", test_l1_wan_hal_positive2_SetWanConnectionEnable);
    UT_add_test(pSuite, "l1_wan_hal_negative1_SetWanConnectionEnable", test_l1_wan_hal_negative1_SetWanConnectionEnable);
    UT_add_test(pSuite, "l1_wan_hal_positive1_SetSelfHealConfig", test_l1_wan_hal_positive1_SetSelfHealConfig);
    UT_add_test(pSuite, "l1_wan_hal_positive2_SetSelfHealConfig", test_l1_wan_hal_positive2_SetSelfHealConfig);
    UT_add_test(pSuite, "l1_wan_hal_negative1_SetSelfHealConfig", test_l1_wan_hal_negative1_SetSelfHealConfig);
    UT_add_test(pSuite, "l1_wan_hal_negative2_SetSelfHealConfig", test_l1_wan_hal_negative2_SetSelfHealConfig);
    UT_add_test(pSuite, "l1_wan_hal_positive1_GetWanOEUpstreamCurrRate", test_l1_wan_hal_positive1_GetWanOEUpstreamCurrRate);
    UT_add_test(pSuite, "l1_wan_hal_negative1_GetWanOEUpstreamCurrRate", test_l1_wan_hal_negative1_GetWanOEUpstreamCurrRate);
    UT_add_test(pSuite, "l1_wan_hal_positive1_GetWanOEDownstreamCurrRate", test_l1_wan_hal_positive1_GetWanOEDownstreamCurrRate);
    UT_add_test(pSuite, "l1_wan_hal_negative1_GetWanOEDownstreamCurrRate", test_l1_wan_hal_negative1_GetWanOEDownstreamCurrRate);
    UT_add_test(pSuite, "l1_wan_hal_positive1_SetQoSConfiguration", test_l1_wan_hal_positive1_SetQoSConfiguration);
    UT_add_test(pSuite, "l1_wan_hal_negative1_SetQoSConfiguration", test_l1_wan_hal_negative1_SetQoSConfiguration);
    UT_add_test(pSuite, "l1_wan_hal_negative2_SetQoSConfiguration", test_l1_wan_hal_negative2_SetQoSConfiguration);
    UT_add_test(pSuite, "l1_wan_hal_negative3_SetQoSConfiguration", test_l1_wan_hal_negative3_SetQoSConfiguration);
    UT_add_test(pSuite, "l1_wan_hal_negative4_SetQoSConfiguration", test_l1_wan_hal_negative4_SetQoSConfiguration);
    UT_add_test(pSuite, "l1_wan_hal_negative5_SetQoSConfiguration", test_l1_wan_hal_negative5_SetQoSConfiguration);
    UT_add_test(pSuite, "l1_wan_hal_negative6_SetQoSConfiguration", test_l1_wan_hal_negative6_SetQoSConfiguration);
    UT_add_test(pSuite, "l1_wan_hal_positive1_ConfigureIpv4", test_l1_wan_hal_positive1_ConfigureIpv4);
    UT_add_test(pSuite, "l1_wan_hal_negative1_ConfigureIpv4", test_l1_wan_hal_negative1_ConfigureIpv4);
    UT_add_test(pSuite, "l1_wan_hal_negative2_ConfigureIpv4", test_l1_wan_hal_negative2_ConfigureIpv4);
    UT_add_test(pSuite, "l1_wan_hal_positive1_UnConfigureIpv4", test_l1_wan_hal_positive1_UnConfigureIpv4);
    UT_add_test(pSuite, "l1_wan_hal_positive2_UnConfigureIpv4", test_l1_wan_hal_positive2_UnConfigureIpv4);
    UT_add_test(pSuite, "l1_wan_hal_negative1_UnConfigureIpv4", test_l1_wan_hal_negative1_UnConfigureIpv4);
    UT_add_test(pSuite, "l1_wan_hal_negative2_UnConfigureIpv4", test_l1_wan_hal_negative2_UnConfigureIpv4);
    UT_add_test(pSuite, "l1_wan_hal_negative3_UnConfigureIpv4", test_l1_wan_hal_negative3_UnConfigureIpv4);
    UT_add_test(pSuite, "l1_wan_hal_negative4_UnConfigureIpv4", test_l1_wan_hal_negative4_UnConfigureIpv4);
    UT_add_test(pSuite, "l1_wan_hal_positive1_ConfigureIpv6", test_l1_wan_hal_positive1_ConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative1_ConfigureIpv6", test_l1_wan_hal_negative1_ConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative2_ConfigureIpv6", test_l1_wan_hal_negative2_ConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative3_ConfigureIpv6", test_l1_wan_hal_negative3_ConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative4_ConfigureIpv6", test_l1_wan_hal_negative4_ConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative5_ConfigureIpv6", test_l1_wan_hal_negative5_ConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative6_ConfigureIpv6", test_l1_wan_hal_negative6_ConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative7_ConfigureIpv6", test_l1_wan_hal_negative7_ConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative8_ConfigureIpv6", test_l1_wan_hal_negative8_ConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_positive1_UnConfigureIpv6", test_l1_wan_hal_positive1_UnConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative1_UnConfigureIpv6", test_l1_wan_hal_negative1_UnConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative2_UnConfigureIpv6", test_l1_wan_hal_negative2_UnConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative3_UnConfigureIpv6", test_l1_wan_hal_negative3_UnConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative4_UnConfigureIpv6", test_l1_wan_hal_negative4_UnConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative5_UnConfigureIpv6", test_l1_wan_hal_negative5_UnConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative6_UnConfigureIpv6", test_l1_wan_hal_negative6_UnConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative7_UnConfigureIpv6", test_l1_wan_hal_negative7_UnConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_negative8_UnConfigureIpv6", test_l1_wan_hal_negative8_UnConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_positive2_UnConfigureIpv6", test_l1_wan_hal_positive2_UnConfigureIpv6);
    UT_add_test(pSuite, "l1_wan_hal_positive1_EnableMapt", test_l1_wan_hal_positive1_EnableMapt);
    UT_add_test(pSuite, "l1_wan_hal_negative1_EnableMapt", test_l1_wan_hal_negative1_EnableMapt);
    UT_add_test(pSuite, "l1_wan_hal_negative2_EnableMapt", test_l1_wan_hal_negative2_EnableMapt);
    UT_add_test(pSuite, "l1_wan_hal_negative3_EnableMapt", test_l1_wan_hal_negative3_EnableMapt);
    UT_add_test(pSuite, "l1_wan_hal_negative4_EnableMapt", test_l1_wan_hal_negative4_EnableMapt);
    UT_add_test(pSuite, "l1_wan_hal_negative5_EnableMapt", test_l1_wan_hal_negative5_EnableMapt);
    UT_add_test(pSuite, "l1_wan_hal_negative6_EnableMapt", test_l1_wan_hal_negative6_EnableMapt);
    UT_add_test(pSuite, "l1_wan_hal_negative7_EnableMapt", test_l1_wan_hal_negative7_EnableMapt);
    UT_add_test(pSuite, "l1_wan_hal_negative8_EnableMapt", test_l1_wan_hal_negative8_EnableMapt);
    UT_add_test(pSuite, "l1_wan_hal_positive1_DisableMapt", test_l1_wan_hal_positive1_DisableMapt);
    UT_add_test(pSuite, "l1_wan_hal_negative1_DisableMapt", test_l1_wan_hal_negative1_DisableMapt);
    UT_add_test(pSuite, "l1_wan_hal_negative2_DisableMapt", test_l1_wan_hal_negative2_DisableMapt);
    UT_add_test(pSuite, "l1_wan_hal_negative3_DisableMapt", test_l1_wan_hal_negative3_DisableMapt);
    UT_add_test(pSuite, "l1_wan_hal_positive1_enableWanOEMode", test_l1_wan_hal_positive1_enableWanOEMode);
    UT_add_test(pSuite, "l1_wan_hal_positive2_enableWanOEMode", test_l1_wan_hal_positive2_enableWanOEMode);
    UT_add_test(pSuite, "l1_wan_hal_negative1_enableWanOEMode", test_l1_wan_hal_negative1_enableWanOEMode);
    UT_add_test(pSuite, "l1_wan_hal_positive1_getAuthInfo", test_l1_wan_hal_positive1_getAuthInfo);
    UT_add_test(pSuite, "l1_wan_hal_positive2_getAuthInfo", test_l1_wan_hal_positive2_getAuthInfo);
    UT_add_test(pSuite, "l1_wan_hal_negative1_getAuthInfo", test_l1_wan_hal_negative1_getAuthInfo);
    UT_add_test(pSuite, "l1_wan_hal_negative2_getAuthInfo", test_l1_wan_hal_negative2_getAuthInfo);
    UT_add_test(pSuite, "l1_wan_hal_negative3_getAuthInfo", test_l1_wan_hal_negative3_getAuthInfo);

    return 0;
}