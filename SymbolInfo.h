#pragma once

/*
식별자의 정보를 담은 구조체

id : 식별자의 symbol table에서의 ID
index; 식별자의 string pool에서의 시작 위치
length: 식별자의 길이
hash_code: 식별자의 해시값
suceess: 새로운 식별자로서 심볼 테이블에 저장되면 정상 처리(1), 그 외(-1)
*/
typedef struct SymbolInfo {
    int id;
    int index;
    int length;
    int hash_code;
    int success;    // 1: 정상 처리됨, -1: 에러 발생
} SymbolInfo;
