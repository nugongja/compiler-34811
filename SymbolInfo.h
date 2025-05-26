#pragma once

/*
식별자의 정보를 담은 구조체

id : 식별자의 symbol table에서의 ID
index; 식별자의 string pool에서의 시작 위치
length: 식별자의 길이
hash_code: 식별자의 해시값
lineno: 식별자가 선언된 라인 번호
type: 식별자의 자료형 (int, float, char 등)
kind: 식별자의 종류 (scalar, array, function 등)
params_count: 함수의 파라미터 개수 (함수인 경우에만 사용)
params: 함수의 파라미터 유형 (함수인 경우에만 사용, 최대 128개 파라미터 가정)
*/

typedef struct SymbolInfo {
    int id;
    int index;
    int length;
    int hash_code;
    int lineno;    
    char type[16];  
	char kind[16];  
	int params_count; 
	char params[128]; 
} SymbolInfo;
