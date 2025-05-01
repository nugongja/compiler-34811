#pragma once


typedef struct SymbolInfo {
    int id;
    int index;
    int length;
    int hash_code;
    int success;    // 1: 정상 처리됨, -1: 에러 발생
} SymbolInfo;
