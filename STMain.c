#include "SymbolInfo.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


#define STR_LEN_SIZE 15
#define SYM_TABLE_SIZE 100
#define STR_POOL_SIZE 1000
#define HASH_TABLE_SIZE 100
#define TRUE 1
#define FALSE 0


char separators[] = " ,;\t\n\r\n";
char str_pool[STR_POOL_SIZE];																// 문자열 저장 배열
SymbolInfo symbol_table[SYM_TABLE_SIZE];														// ID, Index, Length, 
int sym_id = 0;																				// symbol table에 저장된 요소의 개수
int index_start = 0;
extern line_num;

																													

// 해시 테이블 정의
typedef struct HTentry* HTpointer;
typedef struct HTentry {
	int index;
	int id;
	HTpointer next;
}HTentry;
HTpointer HT[HASH_TABLE_SIZE];


// 함수 선언
int process_sym_table(char* identifier);
void update_sym_table(int sym_id, int lineno, const char* type, const char* kind);
void set_param_info(int sym_id, const char* param_str, int count);
void printSymbolTable(void);
int divisionMethod(char* str, int tableSize);
HTpointer lookup_hash_table(int id_index, int hscode);
void add_hash_table(int id, int id_index, int hscode);
void printHashTable(void);
void init_sym_table(void);
void init_hash_table(void);
extern void print_error(int error_num, char* identifier);




int process_sym_table(char* identifier) {

	/* string pool overflow (5) */
	if (index_start + strlen(identifier) + 1 >= STR_POOL_SIZE) {
		print_error(5, identifier);
	}

	strcpy_s(str_pool + index_start, STR_POOL_SIZE - index_start,identifier);


	/* long identifier (2) */
	if (strlen(identifier) > STR_LEN_SIZE) {
		print_error(2, identifier);
	}

	/* symbol table overflow (4) */
	if (sym_id >= SYM_TABLE_SIZE) {
		print_error(4, identifier);
	}


	SymbolInfo* sym = &symbol_table[sym_id];

	// 해시값 계산
	int hash_value = divisionMethod(str_pool + index_start, HASH_TABLE_SIZE);


	// 식별자 중복 여부 확인
	HTpointer htp = lookup_hash_table(index_start, hash_value);
	if (htp != NULL) {
		printf("%-7d %-15s %-15s", line_num, "TIDENT",identifier);
		printf(" (already exists) [ST-ID:%d|PoolIdx:%d|Len:%d|Hash:%d]\n", symbol_table[htp->id - 1].id, symbol_table[htp->id - 1].index, symbol_table[htp->id - 1].length, hash_value);

		return symbol_table[htp->id - 1].id;				// 중복된 심볼이므로 기존 ID 반환
	}
	else {
		// 중복이 아니면 심볼 테이블에 추가
		sym->id = sym_id + 1;
		sym->index = index_start;
		sym->length = (int)strlen(str_pool + index_start);
		sym->hash_code = hash_value;
		sym->lineno = line_num;														// 현재 라인 번호 저장
		add_hash_table(sym->id, index_start, hash_value);							// 해시 테이블에는 string_pool index만 저장
		sym_id++;
	}

	index_start += strlen(identifier);
	str_pool[index_start++] = '\0';

	return sym->id;														// 심볼 테이블에 저장된 ID 반환
}

/* update_sym_table()
* 심볼 테이블의 특정 심볼의 속성을 업데이트하는 함수
* 
* Args:
* sym_id - 업데이트할 심볼의 ID
* lineno - 심볼이 정의된 라인 번호
* type - 심볼의 타입 (int, float, char 등)
* kind - 심볼의 종류 (scalar, array, function 등)
*/
void update_sym_table(int sym_id, int lineno, const char* type, const char* kind) {
	if(symbol_table[sym_id - 1].lineno == NULL)
		symbol_table[sym_id - 1].lineno = lineno;										
	strcpy(symbol_table[sym_id - 1].type, type);
	strcpy(symbol_table[sym_id - 1].kind, kind);
}

/* set_param_info()
* 심볼이 함수인 경우, 함수의 파라미터 정보를 설정하는 함수
* 
* Args:	
* sym_id - 함수 심볼의 ID
* param_str - 파라미터 문자열 (예: "int a, float b")
* count - 파라미터 개수
*/
void set_param_info(int sym_id, const char* param_str, int count) {
	strcpy(symbol_table[sym_id - 1].params, param_str);	// 함수의 파라미터 설정
	symbol_table[sym_id - 1].params_count = count;		// 파라미터 개수 설정
}



/* printSymbolTable()
* 심볼 테이블 출력 함수
*
* 입력: 없음
*
* 반환값: 없음
*/
void printSymbolTable() {
	printf("\n\nSymbol Table:\n");					
	printf("ID\tIndex\tLength\tSymbol\t\tAttributes\n");
	for (int i = 0; i < sym_id; i++) {
		SymbolInfo* sym = &symbol_table[i];
		printf("%-7d\t%-7d\t%-7d\t%-10s\t", sym->id, sym->index, sym->length, str_pool + sym->index);
		
		// 공통 속성 출력
		printf("line %d, %s %s", sym->lineno, sym->type, sym->kind);

		// 함수라면 파라미터 추가 출력
		if (strcmp(sym->kind, "function") == 0) {
			printf(", params: ");
			if (sym->params_count == 0) { printf("- None -"); }
			else{ printf("%s ", sym->params); }
		}

		printf("\n");
	}
	printf("\n");
}



/* divisionMethod()
* hash code 계산 (제산법)
*
* 입력:
* str - 식별자
* tableSize - 해시 테이블의 사이즈
* 
* 반환값: 식별자의 해시 테이블 인덱스 값
*/
int divisionMethod(char* str, int tableSize) {
	int length = strlen(str);
	int key = 0;

	for (int i = 0; i < length; i++) {
		key += (int)*(str + i);
	}

	return key % tableSize;
}



/* lookup_hash_table()
* hash bucket에 동일한 심벌이 존재하는지 찾는 함수(해시 테이블에 이미 존재하면 포인터 반환, 없으면 NULL 반환)
* 
* 입력:
* index - 현재 string pool 위치
* hscode - 현재 입력된 symbol의 hash code
*
* 반환값:
* HTpointer - 찾고자 하는 symbol이 이미 존재할 경우 해당 symbol이 저장된 HTpointer 반환
*             없을 경우는 NULL 반환
*/
HTpointer lookup_hash_table(int index, int hscode) {										
	char* str = str_pool + index;
	int str_len = strlen(str);
	
	HTpointer entry = HT[hscode];

	while (entry != NULL) {
		int existing_idx = entry->index;
		int existing_len = 0;

		
		while (str_pool[existing_idx + existing_len] != '\0') existing_len++;

		if (existing_len == str_len &&
			strncmp(str_pool + existing_idx, str_pool + index, str_len) == 0) {
			return entry;
		}
		

		entry = entry->next;
	}
	return NULL;																			// 항목을 찾지 못한 경우 NULL 반환
}



/* add_hash_table()
* identifier의 hash code칸에 추가
* 
* 입력:
* index - 현재 string pool 위치
* hscode - 현재 입력된 symbol의 hash code
*
* 반환값: 없음
*/
void add_hash_table(int id, int index, int hscode) {
	// 새 항목 생성 및 초기화
	HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry));
	if (newEntry == NULL) {
		print_error(6, "hashtableoverflow");
		return;
	}

	newEntry->index = index;
	newEntry->id = id;
	newEntry->next = NULL;


	// 연결리스트 앞에서 추가
	if (HT[hscode] == NULL) {
		HT[hscode] = newEntry;																// 해시 슬롯이 비어있으면 첫 항목으로
	}
	else {
		newEntry->next = HT[hscode];
		HT[hscode] = newEntry;
	}
}



/* add_hash_table()
* 해시 테이블 내용을 출력하는 함수
*
* 입력: 없음
*
* 반환값: 없음
*/
void printHashTable() {
	printf("\n\nHash Table:\n");
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		HTpointer curr = HT[i];
		if (curr == NULL) {																	// 해시 버킷의 비어 있는 부분은 출력하지 않음
			continue;
		}

		printf("[%d]: ", i);
		while (curr != NULL) {
			printf("%d -> ", curr->id);
			curr = curr->next;
		}
		printf("NULL\n");
	}
	printf("\n");
}





/* 테이블 초기화 */
void init_sym_table() {
	int i;
	for (i = 0; i < SYM_TABLE_SIZE; i++) {
		symbol_table[i].id = -1;
		symbol_table[i].index = -1;
		symbol_table[i].length = -1;
		symbol_table[i].hash_code = -1;
		symbol_table[i].lineno = -1;
		symbol_table[i].type[0] = '\0';  // 자료형 초기화
		symbol_table[i].kind[0] = '\0';  // 종류 초기화
		symbol_table[i].params_count = 0; // 함수의 파라미터 개수 초기화
		symbol_table[i].params[0] = '\0'; // 함수의 파라미터 유형 초기화
	}
}

void init_hash_table() {
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		HT[i] = NULL;
	}
}