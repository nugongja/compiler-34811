#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


#define SYM_TABLE_SIZE 100
#define STR_POOL_SIZE 500
#define HASH_TABLE_SIZE 20
#define TRUE 1
#define FALSE 0


char separators[] = " ,;\t\n\r\n";
char str_pool[STR_POOL_SIZE];
int symbol_table[SYM_TABLE_SIZE][4];	// ID, Index, Length, Hash_idx
int sym_id = 0;		// symbol table에 저장된 요소의 개수


typedef struct HTentry* HTpointer;
typedef struct HTentry {
	int index;
	HTpointer next;
}HTentry;

HTpointer HT[HASH_TABLE_SIZE];


void printSymbolTable(void);
void insertSymbol(int index_start, int index_next);
int calc_key(char* str);
int divisionMethod(int key, int tableSize);
HTpointer lookup_hash_table(int id_index, int hscode);
void add_hash_table(int id_index, int hscode);
void printHashTable(void);



int main() {
	FILE* fp;
	int result;
	int c;
	int index_start = 0;
	int index_next = 0;
	int index = 0;
	bool first_char = TRUE; // 첫 글자인지 여부 확인

	result = fopen_s(&fp, "example.txt", "r");
	if (result != 0) {
		printf("파일을 열수 없습니다(%d)\n", result);
		return -1;
	}

	int err_flag = FALSE;
	do {
		c = fgetc(fp);

		if (index_next >= sizeof(str_pool) - 1) {
			printf("오류: 문자열 버퍼 크기 초과\n");
			break;
		}

		if ((strchr(separators, c) != NULL) || c == EOF) {  // 처리 불가능한 문자이거나, 마지막 문자일 경우
			if (index_next > index_start) {   // 빈 문자열 출력 방지
				str_pool[index_next++] = '\0'; // 현재 단어 끝내기

				if (err_flag != TRUE) {
					insertSymbol(index_start, index_next);

					index_start = index_next;  // 다음 단어의 시작 위치 저장
				}
				else {
					printf("Error - Invalid identifire (%s)\n", str_pool + index_start);
					index_next = index_start; // 에러 발생 시 현재 위치 초기화
					err_flag = FALSE;
				}
				first_char = TRUE;
			}
		}
		else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
			if (first_char) {
				first_char = FALSE;
			}
			str_pool[index_next++] = (char)c;
		}
		else if ((c >= '0' && c <= '9')) { // 숫자가 나왔을 때 or 허용되지 않는 문자
			str_pool[index_next++] = (char)c;
			if (first_char) {
				err_flag = TRUE;
				first_char = FALSE;
			}
		}
		else {
			// 영어, 숫자, 밑줄, 구분자를 제외한 다른 문자: 무조건 오류
			str_pool[index_next++] = (char)c;
			err_flag = TRUE;
			first_char = FALSE;
		}
	} while (c != EOF);

	printSymbolTable();
	printHashTable();

	fclose(fp);
	return 0;
}




// == symbol table function ==

// 심볼 테이블 출력 함수
void printSymbolTable() {
	int idx = 0;
	printf("\n-------------------- Symbol Table ----------------------\n");
	printf(" Name\t\t\tID\tIndex\tLength\tHashValue\n");
	printf("--------------------------------------------------------\n");
	for (int i = 0; i < sym_id; i++) {
		printf(" %-16s\t%d\t%d\t%d\t%d\n", str_pool+symbol_table[i][1], symbol_table[i][0], symbol_table[i][1], symbol_table[i][2], symbol_table[i][3]);
	}
	printf("--------------------------------------------------------\n\n");
}

// 심볼 테이블 insert
void insertSymbol(int index_start, int index_next) {
	char* new_str = str_pool + index_start;
	int new_len = index_next - index_start - 1;

	if (new_len > 15) {
		printf("Error - Identifier too long (%s)\n", new_str);
		return;
	}


	// 해시값 계산
	int key = calc_key(new_str);
	int hscode = divisionMethod(key, HASH_TABLE_SIZE);

	// 중복 여부 확인
	HTpointer htp = lookup_hash_table(index_start, hscode);
	if (htp != NULL) {
		printf("%s (Already exists)\n", new_str);
		return;
	} 
	else {
		printf("%s\n", str_pool + index_start);   // 정상적인 식별자 출력
	}

	// 중복이 아니면 심볼 테이블에 추가
	symbol_table[sym_id][0] = sym_id + 1;
	symbol_table[sym_id][1] = index_start;
	symbol_table[sym_id][2] = new_len;
	symbol_table[sym_id][3] = hscode;

	add_hash_table(index_start, hscode);  // 해시 테이블에는 string_pool index만 저장
	sym_id++;
}


// == hash table function ==

// 문자열 키 계산
int calc_key(char* str) {
	int length = strlen(str);
	int key = 0;

	for (int i = 0; i < length; i++) {
		key += (int)*(str + i);
	}

	return key;
}

// hash code 계산 (제산법)
int divisionMethod(int key, int tableSize) {
	return key % tableSize;
}

/* lookup_hash_table()
* hash bucket에 동일한 심벌이 존재하는지 찾는 함수(해시 테이블에 이미 존재하면 포인터 반환, 없으면 NULL 반환)
* 
* 입력:
* index - 현재 string pool 위치
* hscode - 현재 입력된 symbol의 hash code
*
* 출력:
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
	return NULL; // 항목을 찾지 못한 경우
}



/* add_hash_table()
* identifier의 hash code칸에 추가
* 
* 입력:
* index - 현재 string pool 위치
* hscode - 현재 입력된 symbol의 hash code
*
* 출력: 없음
*/
void add_hash_table(int index, int hscode) {
	// 새 항목 생성 및 초기화
	HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry));
	if (newEntry == NULL) {
		printf("메모리 할당 실패\n");
		exit(1);
	}

	newEntry->index = index;
	newEntry->next = NULL;

	// 연결리스트 뒤에서 추가
	if (HT[hscode] == NULL) {
		HT[hscode] = newEntry;        // 해시 슬롯이 비어있으면 첫 항목으로
	}
	else {
		newEntry->next = HT[hscode];
		HT[hscode] = newEntry;
		/* 끝까지 찾아서 마지막에 연결
		HTpointer curr = HT[hscode];      
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = newEntry;
		*/
	}
}


// 해시 테이블 내용을 출력하는 함수 추가
void printHashTable() {
	printf("\n---------- Hash Table ----------\n");
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		HTpointer curr = HT[i];
		if (curr == NULL) { // 해시 버킷의 비어 있는 부분은 출력하지 않음
			continue;
		}

		printf("[%d] -> ", i);
		while (curr != NULL) {
			printf("%s(String Start Index:%d) -> ", str_pool + curr->index, curr->index);
			curr = curr->next;
		}
		printf("NULL\n");
	}
	printf("--------------------------------\n\n");
}