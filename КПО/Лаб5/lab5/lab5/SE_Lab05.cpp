#include "Dictionary.h"
#if defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_GETENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) + defined(TEST_DICTIONARY) > 1
#error "Должен быть установлен только один макрос из списка TEST_CREATE_01, TEST_CREATE_02, TEST_ADDENTRY_03, TEST_ADDENTRY_04, TEST_GETENTRY_05, TEST_GETENTRY_06, TEST_UPDENTRY_07, TEST_UPDENTRY_08, TEST_DICTIONARY"
#endif